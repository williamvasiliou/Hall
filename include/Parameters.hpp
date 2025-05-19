#ifndef PARAMETERS_H
#define PARAMETERS_H

#include <iostream>
#include "Options.hpp"

class Parameters {
	public:
		static const Parameters *is(double bottom, double mutate, double top, size_t trade, size_t train);
		static const Parameters *is(const Options& options);

		const double bottom;
		const double mutate;
		const double top;
		const size_t trade;
		const size_t train;

		static inline constexpr double BOTTOM = 0.0;
		static inline constexpr double MUTATE = 0.0;
		static inline constexpr double TOP = 0.0;
		static inline const size_t TRADE = 1000;
		static inline const size_t TRAIN = 100;

		friend std::ostream& operator<<(std::ostream& out, const Parameters& parameters);

		~Parameters();

	private:
		explicit Parameters(double bottom, double mutate, double top, size_t trade, size_t train);
};

#endif // PARAMETERS_H
