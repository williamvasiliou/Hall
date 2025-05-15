#include "Weights.hpp"

Weights::Weights(size_t population, double *weight, const Parameters& parameters) :
	population(population),
	weights(2 * population * Items::trades),
	weight(weight),
	fitness(new double[population]),
	parameters(parameters)
{}

void Weights::fill() noexcept {
	double sum = this->fitness[0];
	for (size_t i = 1; i < this->population; ++i) {
		sum += this->fitness[i];
		this->fitness[i] = sum;
	}

	for (size_t i = 0; i < this->population; ++i) {
		this->fitness[i] /= sum;
	}
}

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

void Weights::fill(double *child, const double *weights) noexcept {
	const double value = dis(gen);
	const double amount = dis(gen);
	bool index = false;
	bool next = false;
	size_t i = 0;
	size_t j = 0;

	for (size_t k = 0; k < this->population; ++k) {
		const double fitness = this->fitness[k];

		if (!index && value < fitness) {
			i = k;
			index = true;
		}

		if (!next && amount < fitness) {
			j = k;
			next = true;
		}

		if (index && next) {
			break;
		}
	}

	const double *first = weights + i * Items::trades;
	const double *second = weights + j * Items::trades;
	for (size_t k = 0; k < Items::trades; ++k) {
		if (dis(gen) < 0.5) {
			child[k] = first[k];
		} else {
			child[k] = second[k];
		}

		if (dis(gen) < this->parameters.mutate) {
			child[k] += dis(gen);
		}

		if (child[k] < 0.0) {
			child[k] = 0.0;
		} else if (child[k] > 1.0) {
			child[k] = 1.0;
		}
	}

	for (size_t k = 0; k < Items::size; ++k) {
		double sum = 0.0;
		const size_t next = Items::item[k].next;
		for (size_t index = Items::item[k].index; index < next; ++index) {
			sum += child[Items::trade[index]];
		}

		if (sum > 1.0) {
			for (size_t index = Items::item[k].index; index < next; ++index) {
				child[Items::trade[index]] /= sum;
			}
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
	delete[] this->fitness;
}
