#ifndef OPTIONS_H
#define OPTIONS_H

#include <array>
#include <iostream>
#include <set>
#include <string>

class Options {
	public:
		static inline const size_t BOTTOM = 0;
		static inline const size_t MUTATE = 1;
		static inline const size_t TOP = 2;
		static inline const size_t TRADE = 3;
		static inline const size_t TRAIN = 4;

		template <typename T, size_t index>
		inline const T& get(const T& value) const noexcept;

		template <typename T, size_t index>
		inline void set(const T& value) noexcept;

		~Options();

	private:
		explicit Options();

		double bottom;
		double mutate;
		double top;
		size_t trade;
		size_t train;

		static inline const size_t SIZE = 5;
		std::array<bool, SIZE> is;

		template <typename T, size_t index, const T Options:: *data>
		inline const T& get(const T& value) const noexcept {
			if (this->is[index]) {
				return this->*data;
			}

			return value;
		}

		template <typename T, size_t index, T Options:: *data>
		inline void set(const T& value) noexcept {
			this->*data = value;
			this->is[index] = true;
		}
};

template <>
inline const double& Options::get<double, Options::BOTTOM>(const double& value) const noexcept {
	return this->get<double, Options::BOTTOM, &Options::bottom>(value);
}

template <>
inline const double& Options::get<double, Options::MUTATE>(const double& value) const noexcept {
	return this->get<double, Options::MUTATE, &Options::mutate>(value);
}

template <>
inline const double& Options::get<double, Options::TOP>(const double& value) const noexcept {
	return this->get<double, Options::TOP, &Options::top>(value);
}

template <>
inline const size_t& Options::get<size_t, Options::TRADE>(const size_t& value) const noexcept {
	return this->get<size_t, Options::TRADE, &Options::trade>(value);
}

template <>
inline const size_t& Options::get<size_t, Options::TRAIN>(const size_t& value) const noexcept {
	return this->get<size_t, Options::TRAIN, &Options::train>(value);
}

template <>
inline void Options::set<double, Options::BOTTOM>(const double& value) noexcept {
	return this->set<double, Options::BOTTOM, &Options::bottom>(value);
}

template <>
inline void Options::set<double, Options::MUTATE>(const double& value) noexcept {
	return this->set<double, Options::MUTATE, &Options::mutate>(value);
}

template <>
inline void Options::set<double, Options::TOP>(const double& value) noexcept {
	return this->set<double, Options::TOP, &Options::top>(value);
}

template <>
inline void Options::set<size_t, Options::TRADE>(const size_t& value) noexcept {
	return this->set<size_t, Options::TRADE, &Options::trade>(value);
}

template <>
inline void Options::set<size_t, Options::TRAIN>(const size_t& value) noexcept {
	return this->set<size_t, Options::TRAIN, &Options::train>(value);
}

#endif // OPTIONS_H
