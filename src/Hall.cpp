#include "Config.hpp"
#include "Trade.hpp"

template <double *(Weights:: *first)(size_t i) noexcept, const double *(Weights:: *second)() const noexcept>
inline void fill(size_t bottom, size_t top, Weights& weights) noexcept {
	weights.fill();

	size_t i = 0;
	while (i < bottom) {
		Weights::fill((weights.*first)(i));
		++i;
	}

	while (i < top) {
		weights.fill((weights.*first)(i), (weights.*second)());
		++i;
	}

	while (i < weights.population) {
		weights.fill((weights.*first)(i), (weights.*second)());
		++i;
	}
}

template <const double *(Weights:: *first)(size_t i) const noexcept>
inline void trade(Inventory& inventory, const Parameters& parameters, Weights& weights) noexcept {
	for (size_t i = 0; i < weights.population; ++i) {
		const double *weight = (weights.*first)(i);
		for (size_t j = 0; j < parameters.trade; ++j) {
			Trade::on(inventory, weight);
			inventory.commit();
		}

		weights.fitness[i] = inventory.fitness();
		inventory.restore();
	}
}

inline void train(Inventory& inventory, const Parameters& parameters, Weights& weights) noexcept {
	const size_t bottom = (size_t) (parameters.bottom * (double) weights.population);
	const size_t top = bottom + (size_t) (parameters.top * (double) weights.population);
	for (size_t i = 0; i < parameters.train; ++i) {
		trade<&Weights::first>(inventory, parameters, weights);
		fill<&Weights::second, &Weights::first>(bottom, top, weights);

		trade<&Weights::second>(inventory, parameters, weights);
		fill<&Weights::first, &Weights::second>(bottom, top, weights);
	}
}

int main(int argc, char *argv[]) {
	Inventory *inventory = (Inventory *) nullptr;
	const Parameters *parameters = (Parameters *) nullptr;
	Weights *weights = (Weights *) nullptr;
	if (Config::file(&inventory, &parameters, &weights, "config.json")) {
		Trade::print(Config::print(std::cout, *inventory, *parameters, *weights));
		train(*inventory, *parameters, *weights);

		delete inventory;
		delete parameters;
		delete weights;
		exit(EXIT_SUCCESS);
	} else {
		if (inventory) {
			delete inventory;
		}

		if (parameters) {
			delete parameters;
		}

		if (weights) {
			delete weights;
		}

		exit(EXIT_FAILURE);
	}
}
