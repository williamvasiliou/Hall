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

void Weights::fill(double *child, const std::map<size_t, std::set<size_t>>& weights) noexcept {
	std::map<size_t, size_t> size;
	std::array<double, Items::size> items;

	for (const auto& pair : weights) {
		for (const auto& item : pair.second) {
			++size[item];
		}
	}

	for (const auto& pair : size) {
		items[pair.first] = dis(gen) / pair.second;
	}

	for (size_t i = 0; i < Trade::trades; ++i) {
		size_t index = Trade::in::index[i];
		const size_t next = Trade::in::next[i];
		child[index] = items[Trade::in::item[index]];
		while (++index < next) {
			child[index] = items[Trade::in::item[index]];
		}
	}
}

void Weights::fill(double *child, const double *weights) const noexcept {
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
	}

	for (size_t k = 0; k < Items::size; ++k) {
		double sum = 0.0;

		const size_t index = Items::item[k].index;
		const size_t next = Items::item[k].next;
		for (size_t l = index; l < next; ++l) {
			sum += child[Items::trade[l]];
		}

		if (sum > 1.0) {
			double value = 0.0;
			for (size_t l = index; l < next; ++l) {
				value += first[Items::trade[l]] + second[Items::trade[l]];
			}

			sum = value / (2.0 * sum);
			for (size_t l = index; l < next; ++l) {
				child[Items::trade[l]] *= sum;
			}
		}

		this->mutate(child, index, next);
	}
}

void Weights::fill(double *child, const double *weights, size_t i) const noexcept {
	const double *weight = weights + i * Items::trades;
	for (size_t j = 0; j < Items::trades; ++j) {
		child[j] = weight[j];
	}
}

inline void Weights::mutate(double *child, size_t index, size_t next) const noexcept {
	for (size_t i = index; i < next; ++i) {
		if (dis(gen) < this->parameters.mutate) {
			const double weight = child[Items::trade[i]];

			double sum = 1.0;
			for (size_t j = index; j < next; ++j) {
				sum -= child[Items::trade[j]];
			}

			if (weight + sum > Weights::UNIT) {
				if (dis(gen) < sum / (weight + sum)) {
					child[Items::trade[i]] += sum * dis(gen) * dis(gen) * dis(gen);
				} else {
					child[Items::trade[i]] -= weight * dis(gen) * dis(gen) * dis(gen);
				}
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
