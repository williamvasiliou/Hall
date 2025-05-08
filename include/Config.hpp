#ifndef CONFIG_H
#define CONFIG_H

#include <fstream>
#include "Inventory.hpp"
#include "JSON.hpp"
#include <string>
#include <vector>

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
			static const Population *is(const JSON::Array *array) {
				if (array) {
					const size_t size = array->size();
					std::vector<const Weights *> *vector = new std::vector<const Weights *>();
					if (array->get<Weights, JSON::Array>(*vector) == size) {
						return new Population(vector);
					}

					for (const auto& weights : *vector) {
						delete weights;
					}
					delete vector;
				}

				return (Population *) nullptr;
			}

			const std::vector<const Weights *> *population;

			inline size_t size() const noexcept {
				return this->population->size();
			}

			double *weights() const noexcept {
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

					return weights;
				}

				return (double *) nullptr;
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
	};

	class Config {
		public:
			static const Config *is(const JSON::Object *object) {
				if (object) {
					const Population *population = Population::is(object->get<JSON::Array>("population"));
					if (population) {
						return new Config(population);
					}
				}

				return (Config *) nullptr;
			}

			const Population *population;

			~Config() {
				delete this->population;
			}

		private:
			explicit Config(const Population *population) :
				population(population)
			{}

			static inline const Config *parse(const std::string& source) {
				const Config *config = (Config *) nullptr;

				JSON::Any *value = JSON::parse(source);
				if (value) {
					config = Config::is(JSON::Object::is(value));
					delete value;
				}

				return config;
			}

			friend const Config *file(const std::string& source);
	};

	static inline const size_t MAX_LENGTH = 65536;
	const Config *file(const std::string& source) {
		const Config *config = (Config *) nullptr;

		std::ifstream is(source, std::ifstream::binary);
		if (is) {
			is.seekg(0, is.end);
			const size_t length = is.tellg();
			is.seekg(0, is.beg);

			if (length <= MAX_LENGTH) {
				char *buffer = new char[length];
				is.read(buffer, length);
				config = Config::parse(std::string(buffer, length));
				delete[] buffer;
			}

			is.close();
		}

		return config;
	}
} // namespace Config

#endif // CONFIG_H
