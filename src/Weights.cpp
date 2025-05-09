#include "Weights.hpp"

Weights::Weights(size_t population, double *weight) :
	population(population),
	weights(2 * population * Items::trades),
	weight(weight)
{}

void Weights::fill(double *weights) noexcept {
	for (size_t i = 0; i < Items::size; ++i) {
		const size_t index = Items::item[i].index;
		const size_t next = Items::item[i].next;

		double sum = 0.0;
		for (size_t j = index; j < next; ++j) {
			const double weight = dis(gen);

			weights[Items::trade[j]] = weight;
			sum += weight;
		}

		if (sum > Weights::UNIT) {
			sum = dis(gen) / sum;
		} else {
			sum = dis(gen);
		}

		for (size_t j = index; j < next; ++j) {
			weights[Items::trade[j]] *= sum;
		}
	}
}

Weights::~Weights() {
	delete[] this->weight;
}
