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

			static inline const Array *is(const T *item) {
				std::vector<const T *> *vector = new std::vector<const T *>();
				if (item) {
					vector->push_back(item);
				}
				return new Array(vector);
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
					if (item) {
						const double *quantity = object->get<double, JSON::Number, &JSON::Number::number>("quantity");
						if (quantity) {
							return new Item(item, quantity);
						}

						return new Item(item, &Item::fallback);
					}
				}

				return (Item *) nullptr;
			}

			const std::string *item;
			const double *quantity;

			~Item() {}

		private:
			static constexpr double fallback = 1.0;

			explicit Item(const std::string *item, const double *quantity) :
				item(item),
				quantity(quantity)
			{}
	};

	class Choice {
		public:
			static const Choice *is(const JSON::Object *object) {
				const Item *item = Item::is(object);
				if (item) {
					const JSON::Array *array = object->get<JSON::Array>("choice");
					if (array) {
						delete item;
					} else {
						return new Choice(Array<Item>::is(item));
					}
				} else {
					const Array<Item> *choice = Array<Item>::is(object, "choice");
					if (choice) {
						if (choice->size() > 0) {
							return new Choice(choice);
						}
						delete choice;
					}
				}

				return (Choice *) nullptr;
			}

			const Array<Item> *choice;

			inline const Item *get(size_t i) const noexcept {
				return (*this->choice)[i];
			}

			inline size_t size() const noexcept {
				return this->choice->size();
			}

			~Choice() {
				delete this->choice;
			}

		private:
			explicit Choice(const Array<Item> *choice) :
				choice(choice)
			{}
	};

	class Trade {
		public:
			static const Trade *is(const JSON::Object *object) {
				const Array<Choice> *wants = Array<Choice>::is(object, "wants");
				const Array<Choice> *gives = Array<Choice>::is(object, "gives");
				if (wants && gives && wants->size() > 0 && gives->size() > 0) {
					return new Trade(wants, gives);
				} else {
					if (wants) {
						delete wants;
					}

					if (gives) {
						delete gives;
					}
				}

				return (Trade *) nullptr;
			}

			const Array<Choice> *wants;
			const Array<Choice> *gives;

			template <typename T>
			inline size_t push(T& trades) const noexcept {
				const size_t wants = this->wants->size();
				const size_t gives = this->gives->size();
				std::vector<size_t> index;
				std::vector<size_t> size;
				size_t items = 0;

				const Array<Choice>& in = *this->wants;
				for (size_t i = 0; i < wants; ++i) {
					index.push_back(0);
					size.push_back(in[i]->size());
				}

				const Array<Choice>& out = *this->gives;
				for (size_t i = 0; i < gives; ++i) {
					index.push_back(0);
					size.push_back(out[i]->size());
				}

				while (index[0] < size[0]) {
					AbstractTrade trade;

					size_t i = 0;
					for (size_t j = 0; j < wants; ++j) {
						const Item *item = in[j]->get(index[i]);
						trade.in[*item->item] += *item->quantity;
						++i;
					}

					for (size_t j = 0; j < gives; ++j) {
						const Item *item = out[j]->get(index[i]);
						trade.out[*item->item] += *item->quantity;
						++i;
					}
					--i;

					++index[i];
					while (i > 0) {
						if (index[i] >= size[i]) {
							index[i] = 0;
							++index[i - 1];
						} else {
							break;
						}

						--i;
					}

					items += trades.push(trade);
				}

				return items;
			}

			~Trade() {
				delete this->wants;
				delete this->gives;
			}

		private:
			explicit Trade(const Array<Choice> *wants, const Array<Choice> *gives) :
				wants(wants),
				gives(gives)
			{}
	};

	class Group {
		public:
			static Group *is(const JSON::Object *object) {
				const Array<Trade> *trades = Array<Trade>::is(object, "trades");
				if (trades) {
					if (trades->size() > 0) {
						return new Group(trades);
					}
					delete trades;
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
				const Array<Group> *groups = Array<Group>::is(object, "groups");
				if (groups) {
					if (groups->size() > 0) {
						return new Tier(groups);
					}
					delete groups;
				} else {
					const Group *group = Group::is(object);
					if (group) {
						return new Tier(Array<Group>::is(group));
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
				const Array<Tier> *tiers = Array<Tier>::is(object, "tiers");
				if (tiers) {
					if (tiers->size() > 0) {
						return new Villager(tiers);
					}
					delete tiers;
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
