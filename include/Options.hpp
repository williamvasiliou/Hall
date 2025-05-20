#ifndef OPTIONS_H
#define OPTIONS_H

#include <array>
#include <iostream>
#include <set>
#include <string>

class Options {
	public:
		double bottom;
		double mutate;
		double top;
		size_t trade;
		size_t train;

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

		static inline const size_t BOTTOM = 0;
		static inline const size_t MUTATE = 1;
		static inline const size_t TOP = 2;
		static inline const size_t TRADE = 3;
		static inline const size_t TRAIN = 4;

		static inline const size_t SIZE = 5;
		std::array<bool, SIZE> is;

		~Options();

	private:
		explicit Options();
};

#endif // OPTIONS_H
