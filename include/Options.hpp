#ifndef OPTIONS_H
#define OPTIONS_H

#include <iostream>
#include <set>
#include <string>
#include "Trade.hpp"

template <typename T>
class Option {
	public:
		inline operator bool() const noexcept {
			return this->is;
		}

		inline const T& operator()(const T& value) const noexcept {
			if (this->is) {
				return this->value;
			}

			return value;
		}

		inline void operator=(const T& value) noexcept {
			this->value = value;
			this->is = true;
		}

		inline void operator=(const char *value) noexcept;

	private:
		explicit Option(const T& value);

		T value;
		bool is;

		~Option();

		friend class Options;
};

template <>
inline void Option<double>::operator=(const char *value) noexcept {
	this->value = std::strtod(value, (char **) nullptr);
	this->is = true;
}

template <>
inline void Option<size_t>::operator=(const char *value) noexcept {
	this->value = std::strtoul(value, (char **) nullptr, 10);
	this->is = true;
}

namespace Trade {
	static inline std::ostream& print(std::ostream& out, size_t trade) noexcept {
		out << "{" << std::endl;

		out << "\t\"in\": {" << std::endl;
		size_t index = Trade::in::index[trade];
		size_t next = Trade::in::next[trade];
		out << "\t\t\"" << Items::item[Trade::in::item[index]].name << "\": " << Trade::in::quantity[index];
		while (++index < next) {
			out << "," << std::endl << "\t\t\"" << Items::item[Trade::in::item[index]].name << "\": " << Trade::in::quantity[index];
		}
		out << std::endl << "\t}," << std::endl;

		out << "\t\"out\": {" << std::endl;
		index = Trade::out::index[trade];
		next = Trade::out::next[trade];
		out << "\t\t\"" << Items::item[Trade::out::item[index]].name << "\": " << Trade::out::quantity[index];
		while (++index < next) {
			out << "," << std::endl << "\t\t\"" << Items::item[Trade::out::item[index]].name << "\": " << Trade::out::quantity[index];
		}
		out << std::endl << "\t}" << std::endl;

		out << "}" << std::endl;
		return out;
	}

	static inline std::ostream& print(std::ostream& out) noexcept {
		for (size_t i = 0; i < trades; ++i) {
			print(out, i);
		}

		return out;
	}
} // namespace Trade

class Options {
	public:
		static inline std::ostream& items(std::ostream& out) noexcept {
			for (size_t i = 0; i < Items::size; ++i) {
				out << Items::item[i].name << std::endl;
			}
			return out;
		}

		static inline std::ostream& usage(std::ostream& out) noexcept {
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

		static const Options *parse(std::set<std::string>& directories, std::string& file, bool& verbose, int argc, char **argv);

		Option<double> bottom;
		Option<std::string> find;
		Option<double> mutate;
		Option<double> top;
		Option<size_t> trade;
		Option<size_t> train;

		~Options();

	private:
		explicit Options();
};

#endif // OPTIONS_H
