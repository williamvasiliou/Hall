#ifndef WEIGHTS_H
#define WEIGHTS_H

#include <iostream>
#include "Items.hpp"
#include <random>

namespace Config {
	class Population;
} // namespace Config

static std::random_device rd;
static std::mt19937 gen(rd());
static std::uniform_real_distribution<> dis(0.0, 1.0);

class Weights {
	public:
		const size_t population;
		const size_t weights;

		double *weight;
		double *fitness;

		inline const double *first() const noexcept {
			return this->weight;
		}

		inline const double *second() const noexcept {
			return this->weight + this->population * Items::trades;
		}

		inline const double *first(size_t i) const noexcept {
			return this->weight + i * Items::trades;
		}

		inline const double *second(size_t i) const noexcept {
			return this->first(this->population + i);
		}

		inline double *first(size_t i) noexcept {
			return this->weight + i * Items::trades;
		}

		inline double *second(size_t i) noexcept {
			return this->first(this->population + i);
		}

		static inline constexpr double UNIT = 1e-6;
		void fill() noexcept;
		static void fill(double *weights) noexcept;
		void fill(double *child, const double *weights) noexcept;

		friend std::ostream& operator<<(std::ostream& out, const Weights& weights);

		~Weights();

	private:
		explicit Weights(size_t population, double *weight);

		friend class Config::Population;
};

#endif // WEIGHTS_H
