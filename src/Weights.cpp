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

std::ostream& operator<<(std::ostream& out, const Weights& weights) {
	out << "\t\"population\": " << weights.population << "," << std::endl;
	out << "\t\"weights\": [" << std::endl;

	size_t i = 0;
	for (size_t j = 0; j < weights.population; ++j) {
		if (j > 0) {
			out << "," << std::endl;
		}

		out << "\t\t[";
		for (size_t k = 0; k < Items::trades; ++k) {
			if (k > 0) {
				out << ", ";
			}

			out << weights.weight[i];
			++i;
		}
		out << "]";
	}

	out << std::endl << "\t]";
	return out;
}

Weights::~Weights() {
	delete[] this->weight;
}
