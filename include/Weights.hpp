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

		inline const double *first(size_t i) const noexcept {
			return this->weight + i * Items::trades;
		}

		inline const double *second(size_t i) const noexcept {
			return this->first(this->population + i);
		}

		static inline constexpr double UNIT = 1e-6;
		static void fill(double *weight) noexcept;

		friend std::ostream& operator<<(std::ostream& out, const Weights& weights);

		~Weights();

	private:
		explicit Weights(size_t population, double *weight);

		friend class Config::Population;
};

#endif // WEIGHTS_H
