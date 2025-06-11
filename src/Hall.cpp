#include <algorithm>
#include "Config.hpp"
#include "Path.hpp"
#include "Trades.hpp"

namespace Items {
	static inline ssize_t find(const std::string& name) {
		ssize_t first = 0;
		ssize_t second = Items::size - 1;
		while (first < second) {
			const ssize_t index = first / 2 + second / 2;
			const std::string& value = Items::item[index].name;
			if (value < name) {
				first = index + 1;
			} else if (value > name) {
				second = index - 1;
			} else {
				return index;
			}
		}

		if (first == second && Items::item[first].name == name) {
			return first;
		}

		return -1;
	}
} // namespace Items

namespace Trade {
	static inline constexpr double UNIT = 1e-6;
	static inline void on(Inventory& inventory, const double *weight, size_t trade) noexcept {
		size_t index = Trade::in::index[trade];
		size_t next = Trade::in::next[trade];
		double amount = (inventory[Trade::in::item[index]] * weight[index]) / Trade::in::quantity[index];
		while (++index < next) {
			if (amount < Trade::UNIT) {
				inventory.trade(trade, 0.0);
				return;
			}
			const double value = (inventory[Trade::in::item[index]] * weight[index]) / Trade::in::quantity[index];
			if (value < amount) {
				amount = value;
			}
		}

		if (amount >= Trade::UNIT) {
			index = Trade::in::index[trade];
			inventory.remove(Trade::in::item[index], Trade::in::quantity[index] * amount);
			while (++index < next) {
				inventory.remove(Trade::in::item[index], Trade::in::quantity[index] * amount);
			}

			index = Trade::out::index[trade];
			next = Trade::out::next[trade];
			inventory.add(Trade::out::item[index], Trade::out::quantity[index] * amount);
			while (++index < next) {
				inventory.add(Trade::out::item[index], Trade::out::quantity[index] * amount);
			}

			inventory.trade(trade, amount);
		} else {
			inventory.trade(trade, 0.0);
		}
	}

	static inline void on(Inventory& inventory, const double *weight) noexcept {
		for (size_t i = 0; i < trades; ++i) {
			on(inventory, weight, i);
		}
	}
} // namespace Trade

static inline const size_t SIZE = 11;
template <double *(Weights:: *first)(size_t i) noexcept, const double *(Weights:: *second)() const noexcept, size_t *amount>
inline void fill(size_t bottom, size_t top, Weights& weights, bool verbose) noexcept {
	if (verbose) {
		double sum = weights.fitness[0];
		double min = sum;
		double max = sum;
		for (size_t i = 1; i < weights.population; ++i) {
			const double value = weights.fitness[i];
			sum += value;

			if (value < min) {
				min = value;
			}

			if (value > max) {
				max = value;
			}
		}

		std::ostringstream out;
		out << "\t" << min;
		while (out.str().size() < SIZE) {
			out << " ";
		}

		out << "\t" << (sum / weights.population);
		while (out.str().size() < 2 * SIZE) {
			out << " ";
		}

		out << "\t" << max;
		std::cout << out.str() << std::endl;
	}

	size_t i = 0;
	while (i < bottom) {
		Weights::fill((weights.*first)(i));
		++i;
	}

	std::vector<std::pair<size_t, double>> vector;
	size_t j = 0;
	while (j < weights.population) {
		vector.push_back({j, weights.fitness[j]});
		++j;
	}
	std::sort(vector.begin(), vector.end(), [](auto& index, auto& next) {
		return index.second > next.second;
	});
	weights.fill();

	if (amount) {
		*amount = vector[0].first;
	}

	j = 0;
	while (i < top) {
		weights.fill((weights.*first)(i), (weights.*second)(), vector[j].first);
		++i;
		++j;
	}

	while (i < weights.population) {
		weights.fill((weights.*first)(i), (weights.*second)());
		++i;
	}
}

template <const double *(Weights:: *first)(size_t i) const noexcept>
inline void trade(Inventory& inventory, const Parameters& parameters, Weights& weights, size_t population) noexcept {
	for (size_t i = 0; i < population; inventory.restore(++i)) {
		const double *weight = (weights.*first)(i);
		for (size_t j = 0; j < parameters.trade; ++j) {
			Trade::on(inventory, weight);
			inventory.commit();
		}

		weights.fitness[i] = inventory.fitness();
	}

	const double *weight = (weights.*first)(population);
	for (size_t i = 0; i < parameters.trade; ++i) {
		Trade::on(inventory, weight);
		inventory.commit();
	}

	weights.fitness[population] = inventory.fitness();
	inventory.restore(0);
}

inline void train(Inventory& inventory, const Parameters& parameters, Weights& weights, bool verbose) noexcept {
	inventory.population<Trade::trades>(weights.population);

	const size_t bottom = (size_t) (parameters.bottom * (double) weights.population);
	const size_t top = bottom + (size_t) (parameters.top * (double) weights.population);
	const size_t population = weights.population - 1;
	for (size_t i = 1; i < parameters.train; ++i) {
		trade<&Weights::first>(inventory, parameters, weights, population);
		fill<&Weights::second, &Weights::first, (size_t *) nullptr>(bottom, top, weights, verbose);

		trade<&Weights::second>(inventory, parameters, weights, population);
		fill<&Weights::first, &Weights::second, (size_t *) nullptr>(bottom, top, weights, verbose);
	}

	trade<&Weights::first>(inventory, parameters, weights, population);
	fill<&Weights::second, &Weights::first, (size_t *) nullptr>(bottom, top, weights, verbose);

	static size_t amount = 0;
	trade<&Weights::second>(inventory, parameters, weights, population);
	fill<&Weights::first, &Weights::second, &amount>(bottom, top, weights, verbose);
	std::vector<std::pair<size_t, double>>& vector = inventory.checkout(amount);
	std::sort(vector.begin(), vector.end(), [](auto& index, auto& next) {
		return index.second > next.second;
	});

	for (size_t i = 0; i < Trade::trades; ++i) {
		std::cout << vector[i].first << ": " << vector[i].second << std::endl;
		Trade::print(std::cout, vector[i].first);
	}
}

inline bool train(const std::string& file, const Options& options, bool verbose) noexcept {
	Inventory *inventory = (Inventory *) nullptr;
	const Parameters *parameters = (Parameters *) nullptr;
	Weights *weights = (Weights *) nullptr;
	if (Config::file(&inventory, &parameters, &weights, file, options, verbose)) {
		if (verbose) {
			Config::print(std::cout, *inventory, *parameters, *weights);
		}

		if (options.find) {
			const Inventory& in = *inventory;
			double *items = new double[Items::size];
			for (size_t i = 0; i < Items::size; ++i) {
				items[i] = in[i];
			}

			std::array<bool, Trade::trades> array;
			std::pair<std::vector<size_t>, double> *pair = Path::find(items, array);
			if (pair) {
				const size_t size = pair->first.size();
				std::cout << size << ": " << pair->second << std::endl;

				for (size_t i = 0; i < size; ++i) {
					std::cout << pair->first[i] << std::endl;
					Trade::print(std::cout, pair->first[i]);
				}
				delete pair;
			}

			delete[] items;
		} else {
			train(*inventory, *parameters, *weights, verbose);
		}

		delete inventory;
		delete parameters;
		delete weights;
		return true;
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

		return false;
	}
}

inline bool good(const std::set<std::string>& directories, const std::string& file, const Options& options, const bool& verbose) {
	if (directories.size() > 0) {
		Trades::Trades trades(verbose);
		for (const std::string& directory : directories) {
			trades.directory(directory);
		}
		Trades::Commit commit(trades);

		std::ofstream Items("include/Items.hpp");
		commit.Items(Items);
		Items.close();

		std::ofstream Trade("include/Trade.hpp");
		commit.Trade(Trade);
		Trade.close();

		std::ofstream Document("docs/README.md");
		commit.Document(Document);
		Document.close();

		return true;
	} else if (options.rfind) {
		std::set<size_t> wants;
		std::set<size_t> items;
		std::map<size_t, std::set<size_t>> weights;
		std::set<size_t> weight;

		const ssize_t item = Items::find(options.rfind(""));
		if (item >= 0) {
			wants.insert((size_t) item);
		}

		Path::find(wants, items, weights, weight);
		for (const auto& pair : weights) {
			std::cout << pair.first << std::endl;
			Trade::print(std::cout, pair.first);
		}

		return true;
	} else if (file.size() > 0) {
		return train(file, options, verbose);
	} else {
		return false;
	}
}

int main(int argc, char *argv[]) {
	std::set<std::string> directories;
	std::string file = "config.json";
	bool verbose = false;
	const Options *options = Options::parse(directories, file, verbose, argc, argv);

	if (options && good(directories, file, *options, verbose)) {
		delete options;
		exit(EXIT_SUCCESS);
	} else {
		if (options) {
			delete options;
		}

		exit(EXIT_FAILURE);
	}
}
