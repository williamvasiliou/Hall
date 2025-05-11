#include "Config.hpp"
#include "Trade.hpp"

inline void train(Inventory& inventory, const Parameters& parameters, Weights& weights) noexcept {
	for (size_t i = 0; i < weights.population; ++i) {
		inventory.restore();
		const double *weight = weights.first(i);
		for (size_t j = 0; j < parameters.trade; ++j) {
			Trade::on(inventory, weight);
			inventory.commit();
		}

		std::cout << std::endl << inventory << std::endl;
	}
}

int main() {
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
