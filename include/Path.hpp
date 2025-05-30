#ifndef PATH_H
#define PATH_H

#include "Trade.hpp"

namespace Path {
	static inline constexpr double UNIT = 1e-6;
	static bool good(const double *inventory, double *value, size_t trade) {
		size_t index = Trade::in::index[trade];
		const size_t next = Trade::in::next[trade];
		double amount = inventory[Trade::in::item[index]] / Trade::in::quantity[index];
		while (++index < next) {
			if (amount < Path::UNIT) {
				return false;
			}
			const double value = inventory[Trade::in::item[index]] / Trade::in::quantity[index];
			if (value < amount) {
				amount = value;
			}
		}

		if (amount >= Path::UNIT) {
			*value = amount;
			return true;
		}

		return false;
	}

	static bool good(const double *inventory, const double *next) {
		for (size_t i = 0; i < Items::size; ++i) {
			const double value = inventory[i] - next[i];
			if (value < 0.0) {
				if (-value >= Path::UNIT) {
					return true;
				}
			} else if (value >= Path::UNIT) {
				return true;
			}
		}

		return false;
	}

	static const double *on(const double *inventory, double amount, size_t trade) {
		double *items = new double[Items::size];
		for (size_t i = 0; i < Items::size; ++i) {
			items[i] = inventory[i];
		}

		size_t index = Trade::in::index[trade];
		size_t next = Trade::in::next[trade];
		items[Trade::in::item[index]] -= amount * Trade::in::quantity[index];
		while (++index < next) {
			items[Trade::in::item[index]] -= amount * Trade::in::quantity[index];
		}

		index = Trade::out::index[trade];
		next = Trade::out::next[trade];
		items[Trade::out::item[index]] += amount * Trade::out::quantity[index];
		while (++index < next) {
			items[Trade::out::item[index]] += amount * Trade::out::quantity[index];
		}

		return items;
	}
} // namespace Path

#endif // PATH_H
