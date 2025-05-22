#ifndef OPTIONS_H
#define OPTIONS_H

#include <array>
#include <iostream>
#include <set>
#include <string>

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

class Options {
	public:
		Option<double> bottom;
		Option<double> mutate;
		Option<double> top;
		Option<size_t> trade;
		Option<size_t> train;

		~Options();

	private:
		explicit Options();
};

#endif // OPTIONS_H
