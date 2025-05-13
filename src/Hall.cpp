#include "Config.hpp"
#include "Trade.hpp"
#include "Trades.hpp"

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

inline std::ostream& items(std::ostream& out) noexcept {
	for (size_t i = 0; i < Items::size; ++i) {
		out << Items::item[i].name << std::endl;
	}
	return out;
}

inline std::ostream& usage(std::ostream& out) noexcept {
	out << "Usage: Hall [OPTION...] [FILE]..." << std::endl;
	out << "Options:" << std::endl;
	out << "  -d, --directory=DIRECTORY  update items and trades from" << std::endl;
	out << "                               a directory; this option may" << std::endl;
	out << "                               be specified more than once" << std::endl;
	out << "  -f, --file=CONFIG          use CONFIG instead of config.json" << std::endl;
	out << "  -h, --help                 display this help and exit" << std::endl;
	out << "  -i, --items                display items and exit" << std::endl;
	out << "  -t, --trades               display trades and exit" << std::endl;
	out << "  -v, --verbose              be verbose" << std::endl;
	return out;
}

inline bool train(const std::string& file, bool verbose) noexcept {
	Inventory *inventory = (Inventory *) nullptr;
	const Parameters *parameters = (Parameters *) nullptr;
	Weights *weights = (Weights *) nullptr;
	if (Config::file(&inventory, &parameters, &weights, file)) {
		if (verbose) {
			Config::print(std::cout, *inventory, *parameters, *weights);
		}
		train(*inventory, *parameters, *weights);

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

int main(int argc, char *argv[]) {
	std::set<std::string> directories;
	std::string file = "config.json";
	bool verbose = false;
	for (int i = 1; i < argc; ++i) {
		const std::string string(argv[i]);
		const size_t size = string.size();
		if (size > 0 && string[0] == '-') {
			if (size > 1 && string[1] == '-') {
				if (string == "--directory") {
					if (++i < argc) {
						directories.insert(std::string(argv[i]));
					}
				} else if (string.substr(0, 12) == "--directory=") {
					directories.insert(string.substr(12));
				} else if (string == "--file") {
					if (++i < argc) {
						file = std::string(argv[i]);
					}
				} else if (string.substr(0, 7) == "--file=") {
					file = string.substr(7);
				} else if (string == "--help") {
					usage(std::cout);
					exit(EXIT_SUCCESS);
				} else if (string == "--items") {
					items(std::cout);
					exit(EXIT_SUCCESS);
				} else if (string == "--trades") {
					Trade::print(std::cout);
					exit(EXIT_SUCCESS);
				} else if (string == "--verbose") {
					verbose = true;
				} else {
					std::cerr << "error: unrecognized command-line option: `" << string << "'" << std::endl;
					exit(EXIT_FAILURE);
				}
			} else {
				for (size_t j = 1; j < size; ++j) {
					switch (string[j]) {
						case 'd':
							if (j == size - 1) {
								if (++i < argc) {
									directories.insert(std::string(argv[i]));
								}
							} else {
								directories.insert(std::string(argv[i] + j + 1));
							}
							j = size;
							break;
						case 'f':
							if (j == size - 1) {
								if (++i < argc) {
									file = std::string(argv[i]);
								}
							} else {
								file = std::string(argv[i] + j + 1);
							}
							j = size;
							break;
						case 'h':
							usage(std::cout);
							exit(EXIT_SUCCESS);
							break;
						case 'i':
							items(std::cout);
							exit(EXIT_SUCCESS);
							break;
						case 't':
							Trade::print(std::cout);
							exit(EXIT_SUCCESS);
							break;
						case 'v':
							verbose = true;
							break;
						default:
							std::cerr << "error: unrecognized command-line option: `-" << string[j] << "'" << std::endl;
							exit(EXIT_FAILURE);
					}
				}
			}
		} else {
			file = string;
		}
	}

	if (directories.size() > 0) {
		Trades::Trades trades;
		for (const std::string& directory : directories) {
			trades.directory(directory);
		}
		Trades::Commit commit(trades);

		std::ofstream Items("./include/Items.hpp");
		commit.Items(Items);
		Items.close();

		std::ofstream Trade("./include/Trade.hpp");
		commit.Trade(Trade);
		Trade.close();

		std::ofstream Document("./docs/README.md");
		commit.Document(Document);
		Document.close();
	} else if (file.size() > 0) {
		if (train(file, verbose)) {
			exit(EXIT_SUCCESS);
		} else {
			exit(EXIT_FAILURE);
		}
	} else {
		exit(EXIT_FAILURE);
	}
}
