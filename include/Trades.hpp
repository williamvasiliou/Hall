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
					return Array<T>::is(object->get<JSON::Array>(name));
				}

				return (Array *) nullptr;
			}

			static inline const Array *is(const JSON::Array *array) {
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
						const double *count = object->get<double, JSON::Number, &JSON::Number::number>("count");
						const double *quantity = object->get<double, JSON::Number, &JSON::Number::number>("quantity");
						return Item::is(item, count, quantity);
					}

					const std::string *tag = object->get<std::string, JSON::String, &JSON::String::string>("tag");
					if (tag) {
						return new Item(tag, &Item::fallback);
					}
				}

				return (Item *) nullptr;
			}

			static const Item *is(const JSON::Object *object, const std::string *string) {
				if (object) {
					if (string) {
						return (Item *) nullptr;
					} else {
						return Item::is(object);
					}
				} else if (string) {
					return new Item(string, &Item::fallback);
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

			static inline const Item *is(const std::string *item, const double *count, const double *quantity) {
				if (count) {
					if (quantity) {
						return (Item *) nullptr;
					} else {
						return new Item(item, count);
					}
				} else if (quantity) {
					return new Item(item, quantity);
				}

				return new Item(item, &Item::fallback);
			}
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
			static inline const Villager *is(const JSON::Object *object) {
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

	template <size_t wants, size_t gives>
	class Items {
		public:
			static const Items *is(const JSON::Object *object, const std::vector<std::string>& first, const std::vector<std::string>& second) {
				if (object && first.size() == wants && second.size() == gives) {
					std::vector<const Item *> *in = new std::vector<const Item *>();
					std::vector<const Item *> *out = new std::vector<const Item *>();
					for (const auto& name : first) {
						const Item *item = Item::is(object->get<JSON::Object>(name), object->get<std::string, JSON::String, &JSON::String::string>(name));
						if (item) {
							in->push_back(item);
						}
					}

					for (const auto& name : second) {
						const Item *item = Item::is(object->get<JSON::Object>(name), object->get<std::string, JSON::String, &JSON::String::string>(name));
						if (item) {
							out->push_back(item);
						}
					}

					if (in->size() == wants && out->size() == gives) {
						return new Items(in, out);
					}

					for (const auto& item : *in) {
						delete item;
					}
					delete in;

					for (const auto& item : *out) {
						delete item;
					}
					delete out;
				}

				return (Items *) nullptr;
			}

			const std::vector<const Item *> *in;
			const std::vector<const Item *> *out;

			template <typename T>
			inline size_t push(T& trades) const noexcept {
				AbstractTrade trade;

				for (const auto& item : *this->in) {
					trade.in[*item->item] += *item->quantity;
				}

				for (const auto& item : *this->out) {
					trade.out[*item->item] += *item->quantity;
				}

				return trades.push(trade);
			}

			~Items() {
				for (const auto& item : *this->in) {
					delete item;
				}
				delete this->in;

				for (const auto& item : *this->out) {
					delete item;
				}
				delete this->out;
			}

		private:
			explicit Items(const std::vector<const Item *> *in, const std::vector<const Item *> *out) :
				in(in),
				out(out)
			{}
	};

	class Container {
		public:
			static const Container *is(const JSON::Object *object) {
				const Items<2, 1> *items = Items<2, 1>::is(object, Container::first, Container::second);
				if (items) {
					return new Container(items);
				}

				return (Container *) nullptr;
			}

			const Items<2, 1> *items;

			template <typename T>
			inline size_t push(T& trades) const noexcept {
				return this->items->push(trades);
			}

			~Container() {
				delete this->items;
			}
		private:
			explicit Container(const Items<2, 1> *items) :
				items(items)
			{}

			static inline const std::vector<std::string> first{"input", "reagent"};
			static inline const std::vector<std::string> second{"output"};
	};

	class Mix {
		public:
			static const Mix *is(const JSON::Object *object) {
				const Items<2, 1> *items = Items<2, 1>::is(object, Mix::first, Mix::second);
				if (items) {
					return new Mix(items);
				}

				return (Mix *) nullptr;
			}

			const Items<2, 1> *items;

			template <typename T>
			inline size_t push(T& trades) const noexcept {
				return this->items->push(trades);
			}

			~Mix() {
				delete this->items;
			}
		private:
			explicit Mix(const Items<2, 1> *items) :
				items(items)
			{}

			static inline const std::vector<std::string> first{"input", "reagent"};
			static inline const std::vector<std::string> second{"output"};
	};

	class Key {
		public:
			static const Key *is(const JSON::Object *object) {
				if (object) {
					size_t size = 0;
					std::map<const char, const Item *> *items = new std::map<const char, const Item *>();
					for (const std::pair<const std::string, JSON::Any *>& pair : object->object) {
						++size;
						if (pair.first.size() == 1) {
							const Item *item = Item::is(JSON::Object::is(pair.second));
							if (item) {
								items->insert(std::pair<const char, const Item *>(pair.first[0], item));
							}
						}
					}

					if (size > 0) {
						if (items->size() == size) {
							return new Key(items);
						}

						for (const std::pair<const char, const Item *>& pair : *items) {
							delete pair.second;
						}
					}
					delete items;
				}

				return (Key *) nullptr;
			}

			const std::map<const char, const Item *> *items;

			~Key() {
				for (const std::pair<const char, const Item *>& pair : *this->items) {
					delete pair.second;
				}
				delete this->items;
			}

		private:
			explicit Key(const std::map<const char, const Item *> *items) :
				items(items)
			{}
	};

	class Result {
		public:
			static const Result *is(const JSON::Array *array, const JSON::Object *object) {
				if (array) {
					if (object) {
						return (Result *) nullptr;
					} else if (array->size() > 0) {
						const Array<Item> *items = Array<Item>::is(array);
						if (items) {
							return new Result(items);
						}
					}
				} else if (object) {
					const Item *item = Item::is(object);
					if (item) {
						return new Result(Array<Item>::is(item));
					}
				}

				return (Result *) nullptr;
			}

			const Array<Item> *items;

			inline void push(AbstractTrade& trade) const noexcept {
				const auto& items = *this->items;
				const size_t size = items.size();
				for (size_t i = 0; i < size; ++i) {
					const Item *item = items[i];
					trade.out[*item->item] += *item->quantity;
				}
			}

			~Result() {
				delete this->items;
			}

		private:
			explicit Result(const Array<Item> *items) :
				items(items)
			{}
	};

	class Shaped {
		public:
			static const Shaped *is(const JSON::Object *object) {
				if (object) {
					const JSON::Array *pattern = object->get<JSON::Array>("pattern");
					const Key *key = Key::is(object->get<JSON::Object>("key"));
					const Result *result = Result::is(object->get<JSON::Array>("result"), object->get<JSON::Object>("result"));
					if (pattern && key && result) {
						const size_t size = pattern->size();
						if (size > 0) {
							std::vector<const std::string *> *vector = new std::vector<const std::string *>();
							if (pattern->get<std::string, JSON::String, &JSON::String::string>(*vector) == size) {
								return new Shaped(vector, key, result);
							}
							delete vector;
						}
						delete key;
						delete result;
					} else {
						if (key) {
							delete key;
						}

						if (result) {
							delete result;
						}
					}
				}

				return (Shaped *) nullptr;
			}

			const std::vector<const std::string *> *pattern;
			const Key *key;
			const Result *result;

			template <typename T>
			inline size_t push(T& trades) const noexcept {
				const auto& pattern = *this->pattern;
				const auto& key = *this->key->items;
				AbstractTrade trade;

				for (const std::string *row : pattern) {
					for (const char c : *row) {
						const auto& pair = key.find(c);
						if (pair != key.end()) {
							const Item *item = pair->second;
							trade.in[*item->item] += *item->quantity;
						}
					}
				}

				result->push(trade);
				return trades.push(trade);
			}

			~Shaped() {
				delete this->pattern;
				delete this->key;
				delete this->result;
			}

		private:
			explicit Shaped(const std::vector<const std::string *> *pattern, const Key *key, const Result *result) :
				pattern(pattern),
				key(key),
				result(result)
			{}
	};

	class Shapeless {
		public:
			static const Shapeless *is(const JSON::Object *object) {
				const Array<Item> *ingredients = Array<Item>::is(object, "ingredients");
				if (ingredients) {
					const Result *result = Result::is(object->get<JSON::Array>("result"), object->get<JSON::Object>("result"));
					if (result) {
						return new Shapeless(ingredients, result);
					}
					delete ingredients;
				}

				return (Shapeless *) nullptr;
			}

			const Array<Item> *ingredients;
			const Result *result;

			template <typename T>
			inline size_t push(T& trades) const noexcept {
				AbstractTrade trade;

				const auto& ingredients = *this->ingredients;
				const size_t size = ingredients.size();
				for (size_t i = 0; i < size; ++i) {
					const Item *item = ingredients[i];
					trade.in[*item->item] += *item->quantity;
				}

				result->push(trade);
				return trades.push(trade);
			}

			~Shapeless() {
				delete this->ingredients;
				delete this->result;
			}

		private:
			explicit Shapeless(const Array<Item> *ingredients, const Result *result) :
				ingredients(ingredients),
				result(result)
			{}
	};

	class Transform {
		public:
			static const Transform *is(const JSON::Object *object) {
				const Items<2, 1> *items = Items<2, 1>::is(object, Transform::first, Transform::second);
				if (items) {
					return new Transform(items);
				}

				return (Transform *) nullptr;
			}

			const Items<2, 1> *items;

			template <typename T>
			inline size_t push(T& trades) const noexcept {
				return this->items->push(trades);
			}

			~Transform() {
				delete this->items;
			}
		private:
			explicit Transform(const Items<2, 1> *items) :
				items(items)
			{}

			static inline const std::vector<std::string> first{"base", "addition"};
			static inline const std::vector<std::string> second{"result"};
	};

	class Trim {
		public:
			static const Trim *is(const JSON::Object *object) {
				const Items<3, 1> *items = Items<3, 1>::is(object, Trim::first, Trim::second);
				if (items) {
					return new Trim(items);
				}

				return (Trim *) nullptr;
			}

			const Items<3, 1> *items;

			template <typename T>
			inline size_t push(T& trades) const noexcept {
				return this->items->push(trades);
			}

			~Trim() {
				delete this->items;
			}
		private:
			explicit Trim(const Items<3, 1> *items) :
				items(items)
			{}

			static inline const std::vector<std::string> first{"base", "addition", "template"};
			static inline const std::vector<std::string> second{"base"};
	};

	template <typename T, typename U>
	class Recipe {
		public:
			static inline const Recipe *is(const JSON::Object *object, const std::string& name, const std::string& key) {
				if (object) {
					const T *first = T::is(object->get<JSON::Object>(name));
					const U *second = U::is(object->get<JSON::Object>(key));
					if (first) {
						if (second) {
							delete first;
							delete second;
						} else {
							return new Recipe(first);
						}
					} else if (second) {
						return new Recipe(second);
					}
				}

				return (Recipe *) nullptr;
			}

			const T *first;
			const U *second;

			template <typename V>
			inline size_t push(V& trades) const noexcept {
				if (this->first) {
					return this->first->push(trades);
				} else {
					return this->second->push(trades);
				}
			}

			~Recipe() {
				if (this->first) {
					delete this->first;
				} else {
					delete this->second;
				}
			}

		private:
			explicit Recipe(const T *first) :
				first(first),
				second((U *) nullptr)
			{}

			explicit Recipe(const U *second) :
				first((T *) nullptr),
				second(second)
			{}
	};

	class Brewing {
		public:
			static inline const Brewing *is(const JSON::Object *object) {
				const Recipe<Container, Mix> *recipe = Recipe<Container, Mix>::is(object, "minecraft:recipe_brewing_container", "minecraft:recipe_brewing_mix");
				if (recipe) {
					return new Brewing(recipe);
				}

				return (Brewing *) nullptr;
			}

			const Recipe<Container, Mix> *recipe;

			template <typename T>
			inline size_t push(T& trades) const noexcept {
				return this->recipe->push(trades);
			}

			~Brewing() {
				delete this->recipe;
			}

		private:
			explicit Brewing(const Recipe<Container, Mix> *recipe) :
				recipe(recipe)
			{}
	};

	class Crafting {
		public:
			static inline const Crafting *is(const JSON::Object *object) {
				const Recipe<Shaped, Shapeless> *recipe = Recipe<Shaped, Shapeless>::is(object, "minecraft:recipe_shaped", "minecraft:recipe_shapeless");
				if (recipe) {
					return new Crafting(recipe);
				}

				return (Crafting *) nullptr;
			}

			const Recipe<Shaped, Shapeless> *recipe;

			template <typename T>
			inline size_t push(T& trades) const noexcept {
				return this->recipe->push(trades);
			}

			~Crafting() {
				delete this->recipe;
			}

		private:
			explicit Crafting(const Recipe<Shaped, Shapeless> *recipe) :
				recipe(recipe)
			{}
	};

	class Furnace {
		public:
			static inline const Furnace *is(const JSON::Object *object) {
				if (object) {
					const Items<1, 1> *items = Items<1, 1>::is(object->get<JSON::Object>("minecraft:recipe_furnace"), Furnace::first, Furnace::second);
					if (items) {
						return new Furnace(items);
					}
				}

				return (Furnace *) nullptr;
			}

			const Items<1, 1> *items;

			template <typename T>
			inline size_t push(T& trades) const noexcept {
				return this->items->push(trades);
			}

			~Furnace() {
				delete this->items;
			}

		private:
			explicit Furnace(const Items<1, 1> *items) :
				items(items)
			{}

			static inline const std::vector<std::string> first{"input"};
			static inline const std::vector<std::string> second{"output"};
	};

	class Smithing {
		public:
			static inline const Smithing *is(const JSON::Object *object) {
				const Recipe<Transform, Trim> *recipe = Recipe<Transform, Trim>::is(object, "minecraft:recipe_smithing_transform", "minecraft:recipe_smithing_trim");
				if (recipe) {
					return new Smithing(recipe);
				}

				return (Smithing *) nullptr;
			}

			const Recipe<Transform, Trim> *recipe;

			template <typename T>
			inline size_t push(T& trades) const noexcept {
				return this->recipe->push(trades);
			}

			~Smithing() {
				delete this->recipe;
			}

		private:
			explicit Smithing(const Recipe<Transform, Trim> *recipe) :
				recipe(recipe)
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
