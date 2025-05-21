#include "Parameters.hpp"

const Parameters *Parameters::is(double bottom, double mutate, double top, size_t trade, size_t train) {
	if (bottom < 0.0) {
		bottom = 0.0;
	} else if (bottom > 1.0) {
		bottom = 1.0;
	}

	if (top < 0.0) {
		top = 0.0;
	} else if (top > 1.0) {
		top = 1.0;
	}

	const double sum = bottom + top;
	if (sum > 1.0) {
		bottom /= sum;
		top /= sum;
	}

	if (mutate < 0.0) {
		mutate = 0.0;
	} else if (mutate > 1.0) {
		mutate = 1.0;
	}

	if (trade == 0) {
		trade = Parameters::TRADE;
	}

	if (train == 0) {
		train = Parameters::TRAIN;
	}

	return new Parameters(bottom, mutate, top, trade, train);
}

const Parameters *Parameters::is(const Options& options) {
	return Parameters::is(
		options.get<double, Options::BOTTOM>(Parameters::BOTTOM),
		options.get<double, Options::MUTATE>(Parameters::MUTATE),
		options.get<double, Options::TOP>(Parameters::TOP),
		options.get<size_t, Options::TRADE>(Parameters::TRADE),
		options.get<size_t, Options::TRAIN>(Parameters::TRAIN)
	);
}

Parameters::Parameters(double bottom, double mutate, double top, size_t trade, size_t train) :
	bottom(bottom),
	mutate(mutate),
	top(top),
	trade(trade),
	train(train)
{}

std::ostream& operator<<(std::ostream& out, const Parameters& parameters) {
	out << "\t\"bottom\": " << parameters.bottom << "," << std::endl;
	out << "\t\"mutate\": " << parameters.mutate << "," << std::endl;
	out << "\t\"top\": " << parameters.top << "," << std::endl;
	out << "\t\"trade\": " << parameters.trade << "," << std::endl;
	out << "\t\"train\": " << parameters.train;

	return out;
}

Parameters::~Parameters() {}
