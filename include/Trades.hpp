#ifndef TRADES_H
#define TRADES_H

#include <filesystem>
#include <fstream>
#include <iostream>
#include "JSON.hpp"
#include <map>
#include <set>
#include <string>
#include <vector>

namespace Trades {
	typedef struct {
		std::map<std::string, double> in;
		std::map<std::string, double> out;
	} AbstractTrade;

	typedef struct {
		const std::string name;
		std::vector<AbstractTrade> trades;
	} File;

	template <typename T>
	class Array {
		public:
			static const Array *is(const JSON::Object *object, const std::string& name) {
				if (object) {
					const JSON::Array *array = object->get<JSON::Array>(name);
					if (array) {
						const size_t size = array->size();
						std::vector<const T *> *vector = new std::vector<const T *>();
						if (array->get<T, JSON::Object>(*vector) == size) {
							return new Array(vector);
						}

						for (const auto& item : *vector) {
							delete item;
						}
						delete vector;
					}
				}

				return (Array *) nullptr;
			}

			const std::vector<const T *> *array;

			inline const T *operator[](size_t i) const noexcept {
				if (i < this->array->size()) {
					return (*this->array)[i];
				} else {
					return (T *) nullptr;
				}
			}

			inline size_t size() const noexcept {
				return this->array->size();
			}

			~Array() {
				for (const auto& item : *this->array) {
					delete item;
				}
				delete this->array;
			}

		private:
			explicit Array(const std::vector<const T *> *array) :
				array(array)
			{}
	};

	class Item {
		public:
			static const Item *is(const JSON::Object *object) {
				if (object) {
					const std::string *item = object->get<std::string, JSON::String, &JSON::String::string>("item");
					const double *quantity = object->get<double, JSON::Number, &JSON::Number::number>("quantity");
					if (item && quantity) {
						return new Item(item, quantity);
					}
				}

				return (Item *) nullptr;
			}

			const std::string *item;
			const double *quantity;

			~Item() {}

		private:
			explicit Item(const std::string *item, const double *quantity) :
				item(item),
				quantity(quantity)
			{}
	};

	class Trade {
		public:
			static const Trade *is(const JSON::Object *object) {
				if (object) {
					const Array<Item> *wants = Array<Item>::is(object, "wants");
					const Array<Item> *gives = Array<Item>::is(object, "gives");
					if (wants && gives) {
						return new Trade(wants, gives);
					} else {
						if (wants) {
							delete wants;
						}

						if (gives) {
							delete gives;
						}
					}
				}

				return (Trade *) nullptr;
			}

			const Array<Item> *wants;
			const Array<Item> *gives;

			template <auto AbstractTrade:: *data, const Array<Item> *Trade:: *items>
			inline void push(AbstractTrade& trade) const noexcept {
				auto& out = trade.*data;

				const Array<Item>& array = *(this->*items);
				const size_t size = array.size();
				for (size_t i = 0; i < size; ++i) {
					const Item *item = array[i];
					out[*item->item] += *item->quantity;
				}
			}

			template <typename T>
			inline size_t push(T& trades) const noexcept {
				return trades.push(*this);
			}

			~Trade() {
				delete this->wants;
				delete this->gives;
			}

		private:
			explicit Trade(const Array<Item> *wants, const Array<Item> *gives) :
				wants(wants),
				gives(gives)
			{}
	};

	class Group {
		public:
			static Group *is(const JSON::Object *object) {
				if (object) {
					const Array<Trade> *trades = Array<Trade>::is(object, "trades");
					if (trades) {
						return new Group(trades);
					}
				}

				return (Group *) nullptr;
			}

			const Array<Trade> *trades;

			template <typename T>
			inline size_t push(T& trades) const noexcept {
				return trades.template push<Trade, Group, &Group::trades>(*this);
			}

			~Group() {
				delete this->trades;
			}

		private:
			explicit Group(const Array<Trade> *trades) :
				trades(trades)
			{}
	};

	class Tier {
		public:
			static const Tier *is(const JSON::Object *object) {
				if (object) {
					const Array<Group> *groups = Array<Group>::is(object, "groups");
					if (groups) {
						return new Tier(groups);
					}
				}

				return (Tier *) nullptr;
			}

			const Array<Group> *groups;

			template <typename T>
			inline size_t push(T& trades) const noexcept {
				return trades.template push<Group, Tier, &Tier::groups>(*this);
			}

			~Tier() {
				delete this->groups;
			}

		private:
			explicit Tier(const Array<Group> *groups) :
				groups(groups)
			{}
	};

	class Villager {
		public:
			static const Villager *is(const JSON::Object *object) {
				if (object) {
					const Array<Tier> *tiers = Array<Tier>::is(object, "tiers");
					if (tiers) {
						return new Villager(tiers);
					}
				}

				return (Villager *) nullptr;
			}

			const Array<Tier> *tiers;

			template <typename T>
			inline size_t push(T& trades) const noexcept {
				return trades.template push<Tier, Villager, &Villager::tiers>(*this);
			}

			~Villager() {
				delete this->tiers;
			}

		private:
			explicit Villager(const Array<Tier> *tiers) :
				tiers(tiers)
			{}
	};

	class Trades {
		public:
			explicit Trades() :
				trades((std::vector<AbstractTrade> *) nullptr),
				files()
			{}

			inline size_t push(const AbstractTrade& trade) noexcept {
				if (this->trades && trade.in.size() > 0 && trade.out.size() > 0) {
					this->trades->push_back(trade);
					return 1;
				}

				return 0;
			}

			inline size_t push(const Trade& trade) noexcept {
				AbstractTrade items;
				trade.push<&AbstractTrade::in, &Trade::wants>(items);
				trade.push<&AbstractTrade::out, &Trade::gives>(items);
				return this->push(items);
			}

			template <typename T, typename U, const Array<T> *U:: *data>
			inline size_t push(const U& object) noexcept {
				size_t items = 0;

				const Array<T>& array = *(object.*data);
				const size_t size = array.size();
				for (size_t i = 0; i < size; ++i) {
					items += array[i]->push(*this);
				}

				return items;
			}

			~Trades() {}

		private:
			std::vector<AbstractTrade> *trades;
			std::vector<File> files;
	};
} // namespace Trades

#endif // TRADES_H
