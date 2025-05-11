#ifndef CONFIG_H
#define CONFIG_H

#include <fstream>
#include "Inventory.hpp"
#include "JSON.hpp"
#include "Parameters.hpp"
#include <string>
#include <vector>
#include "Weights.hpp"

namespace Config {
	class Weights {
		public:
			static const Weights *is(const JSON::Array *array) {
				if (array && array->size() == Items::trades) {
					double *weights = new double[Items::trades];
					if (Weights::get(array->array, weights)) {
						return new Weights(weights);
					}
					delete[] weights;
				}

				return (Weights *) nullptr;
			}

			static inline const Weights *fill() {
				double *weights = new double[Items::trades];
				::Weights::fill(weights);
				return new Weights(weights);
			}

			const double *weights;

			~Weights() {
				delete[] this->weights;
			}

		private:
			explicit Weights(const double *weights) :
				weights(weights)
			{}

			static inline bool get(const std::vector<JSON::Any *>& array, double *weights) noexcept {
				size_t items = 0;
				for (const auto& item : array) {
					const JSON::Number *value = JSON::Number::is(item);
					if (value) {
						weights[items] = value->number;
						++items;
					}
				}

				if (items == Items::trades) {
					for (size_t i = 0; i < Items::trades; ++i) {
						const double value = weights[i];
						if (value < 0.0 || value > 1.0) {
							return false;
						}
					}

					for (size_t i = 0; i < Items::size; ++i) {
						size_t index = Items::item[i].index;
						const size_t next = Items::item[i].next;

						double sum = 0.0;
						while (index < next) {
							sum += weights[Items::trade[index]];
							++index;
						}

						if (sum > 1.0) {
							return false;
						}
					}

					return true;
				}

				return false;
			}
	};

	class Population {
		public:
			static const Population *is(size_t size, const JSON::Array *array) {
				if (size > 0) {
					std::vector<const Weights *> *vector = new std::vector<const Weights *>();
					if (Population::get(array, *vector, size)) {
						return new Population(vector);
					}

					for (const auto& weights : *vector) {
						delete weights;
					}
					delete vector;
				}

				return (Population *) nullptr;
			}

			static const Population *fill() {
				std::vector<const Weights *> *vector = new std::vector<const Weights *>();

				size_t items = 0;
				while (items < Population::SIZE) {
					vector->push_back(Weights::fill());
					++items;
				}

				return new Population(vector);
			}

			static inline const size_t SIZE = 100;
			const std::vector<const Weights *> *population;

			inline size_t size() const noexcept {
				return this->population->size();
			}

			::Weights *weights() const noexcept {
				const auto& population = *this->population;
				const size_t size = population.size();

				if (size > 0) {
					double *weights = new double[2 * size * Items::trades];

					size_t i = 0;
					for (size_t j = 0; j < size; ++j) {
						for (size_t k = 0; k < Items::trades; ++k) {
							weights[i] = population[j]->weights[k];
							++i;
						}
					}

					return new ::Weights(size, weights);
				}

				return (::Weights *) nullptr;
			}

			~Population() {
				for (const auto& weights : *this->population) {
					delete weights;
				}
				delete this->population;
			}

		private:
			explicit Population(const std::vector<const Weights *> *population) :
				population(population)
			{}

			static inline bool get(const std::vector<JSON::Any *>& array, std::vector<const Weights *>& weights, size_t size) noexcept {
				size_t items = 0;

				for (const auto& item : array) {
					if (items < size) {
						const Weights *value = Weights::is(JSON::Array::is(item));
						if (value) {
							weights.push_back(value);
							++items;
						}
					} else {
						break;
					}
				}

				while (items < size) {
					weights.push_back(Weights::fill());
					++items;
				}

				return true;
			}

			static inline bool get(const JSON::Array *array, std::vector<const Weights *>& weights, size_t size) noexcept {
				if (array) {
					return Population::get(array->array, weights, size);
				} else {
					size_t items = 0;
					while (items < size) {
						weights.push_back(Weights::fill());
						++items;
					}

					return true;
				}
			}
	};

	static inline size_t number(const double *number, size_t size) {
		if (number) {
			const double value = *number;

			if (value < 0.0) {
				return size;
			} else {
				return (size_t) value;
			}
		}

		return size;
	}

	static inline double number(const double *number, double size) {
		if (number) {
			return *number;
		}

		return size;
	}

	static inline bool parse(Inventory **inventory, const Parameters **parameters, ::Weights **weights, const std::string& source) {
		bool config = false;

		if (inventory && parameters && weights) {
			JSON::Any *value = JSON::parse(source);
			if (value) {
				const JSON::Object *object = JSON::Object::is(value);
				if (object) {
					if (*inventory) {
						delete *inventory;
					}

					const JSON::Object *items = object->get<JSON::Object>("items");
					double *quantity = new double[Items::size] {};
					if (items) {
						for (size_t i = 0; i < Items::size; ++i) {
							const std::string& name = Items::item[i].name;
							const JSON::Number *value = items->get<JSON::Number>(name);
							if (value && value->number > 0.0) {
								quantity[i] = value->number;
							}
						}
					}

					const JSON::Object *rate = object->get<JSON::Object>("rate");
					double *rates = new double[Items::size] {};
					if (rate) {
						for (size_t i = 0; i < Items::size; ++i) {
							const std::string& name = Items::item[i].name;
							const JSON::Number *value = rate->get<JSON::Number>(name);
							if (value && value->number > 0.0) {
								rates[i] = value->number;
							} else {
								rates[i] = Items::item[i].rate;
							}
						}
					} else {
						for (size_t i = 0; i < Items::size; ++i) {
							rates[i] = Items::item[i].rate;
						}
					}
					*inventory = Inventory::is(quantity, rates);

					if (*parameters) {
						delete *parameters;
					}
					*parameters = Parameters::is(number(object->get<double, JSON::Number, &JSON::Number::number>("bottom"), Parameters::BOTTOM), number(object->get<double, JSON::Number, &JSON::Number::number>("mutate"), Parameters::MUTATE), number(object->get<double, JSON::Number, &JSON::Number::number>("top"), Parameters::TOP), number(object->get<double, JSON::Number, &JSON::Number::number>("trade"), Parameters::TRADE), number(object->get<double, JSON::Number, &JSON::Number::number>("train"), Parameters::TRAIN));

					if (*weights) {
						delete *weights;
					}

					const Population *population = Population::is(number(object->get<double, JSON::Number, &JSON::Number::number>("population"), Population::SIZE), object->get<JSON::Array>("weights"));
					if (population) {
						*weights = population->weights();

						delete population;
					} else {
						const Population *population = Population::fill();
						*weights = population->weights();
						delete population;
					}

					config = true;
				}

				delete value;
			}

			if (!config) {
				if (*inventory) {
					delete *inventory;
				}
				*inventory = Inventory::is((double *) nullptr, (double *) nullptr);

				if (*parameters) {
					delete *parameters;
				}
				*parameters = Parameters::is(Parameters::BOTTOM, Parameters::MUTATE, Parameters::TOP, Parameters::TRADE, Parameters::TRAIN);

				if (*weights) {
					delete *weights;
				}
				const Population *population = Population::fill();
				*weights = population->weights();
				delete population;

				config = true;
			}
		}

		return config;
	}

	static inline const size_t MAX_LENGTH = 65536;
	static bool file(Inventory **inventory, const Parameters **parameters, ::Weights **weights, const std::string& source) {
		bool config = false;

		std::ifstream is(source, std::ifstream::binary);
		if (is) {
			is.seekg(0, is.end);
			const size_t length = is.tellg();
			is.seekg(0, is.beg);

			if (length <= MAX_LENGTH) {
				char *buffer = new char[length];
				is.read(buffer, length);
				config = parse(inventory, parameters, weights, std::string(buffer, length));
				delete[] buffer;
			}

			is.close();
		}

		return config;
	}

	static inline std::ostream& print(std::ostream& out, const Inventory& inventory, const Parameters& parameters, const ::Weights& weights) noexcept {
		out << "{" << std::endl;
		out << inventory << "," << std::endl;
		out << parameters << "," << std::endl;
		out << weights << std::endl;
		out << "}" << std::endl;

		return out;
	}
} // namespace Config

#endif // CONFIG_H
