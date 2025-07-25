#include "Options.hpp"

template <typename T>
Option<T>::Option(const T& value) :
	value(value),
	is(false)
{}

template <typename T>
Option<T>::~Option() {}

Options::Options() :
	bottom(0.0),
	find(""),
	mutate(0.0),
	rfind(""),
	top(0.0),
	trade(0),
	train(0)
{}

const Options *Options::parse(std::set<std::string>& directories, std::string& file, bool& verbose, int argc, char **argv) {
	Options *options = new Options();

	for (int i = 1; i < argc; ++i) {
		const std::string string(argv[i]);
		const size_t size = string.size();
		if (size > 0 && string[0] == '-') {
			if (size > 1 && string[1] == '-') {
				if (string == "--bottom") {
					if (++i < argc) {
						options->bottom = argv[i];
					}
				} else if (string.substr(0, 9) == "--bottom=") {
					options->bottom = argv[i] + 9;
				} else if (string == "--directory") {
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
				} else if (string == "--find") {
					if (++i < argc) {
						options->find = std::string(argv[i]);
					}
				} else if (string.substr(0, 7) == "--find=") {
					options->find = string.substr(7);
				} else if (string == "--help") {
					Options::usage(std::cout);
					delete options;
					exit(EXIT_SUCCESS);
				} else if (string == "--items") {
					Options::items(std::cout);
					delete options;
					exit(EXIT_SUCCESS);
				} else if (string == "--mutate") {
					if (++i < argc) {
						options->mutate = argv[i];
					}
				} else if (string.substr(0, 9) == "--mutate=") {
					options->mutate = argv[i] + 9;
				} else if (string == "--rfind") {
					if (++i < argc) {
						options->rfind = std::string(argv[i]);
					}
				} else if (string.substr(0, 8) == "--rfind=") {
					options->rfind = string.substr(8);
				} else if (string == "--top") {
					if (++i < argc) {
						options->top = argv[i];
					}
				} else if (string.substr(0, 6) == "--top=") {
					options->top = argv[i] + 6;
				} else if (string == "--trade") {
					if (++i < argc) {
						options->trade = argv[i];
					}
				} else if (string.substr(0, 8) == "--trade=") {
					options->trade = argv[i] + 8;
				} else if (string == "--trades") {
					Trade::print(std::cout);
					delete options;
					exit(EXIT_SUCCESS);
				} else if (string == "--train") {
					if (++i < argc) {
						options->train = argv[i];
					}
				} else if (string.substr(0, 8) == "--train=") {
					options->train = argv[i] + 8;
				} else if (string == "--verbose") {
					verbose = true;
				} else {
					std::cerr << "error: unrecognized command-line option: `" << string << "'" << std::endl;
					delete options;
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
							Options::usage(std::cout);
							delete options;
							exit(EXIT_SUCCESS);
							break;
						case 'i':
							Options::items(std::cout);
							delete options;
							exit(EXIT_SUCCESS);
							break;
						case 't':
							Trade::print(std::cout);
							delete options;
							exit(EXIT_SUCCESS);
							break;
						case 'v':
							verbose = true;
							break;
						default:
							std::cerr << "error: unrecognized command-line option: `-" << string[j] << "'" << std::endl;
							delete options;
							exit(EXIT_FAILURE);
					}
				}
			}
		} else {
			file = string;
		}
	}

	return options;
}

Options::~Options() {}
