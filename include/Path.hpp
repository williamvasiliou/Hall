#ifndef PATH_H
#define PATH_H

#include <array>
#include <map>
#include <set>
#include "Trade.hpp"
#include <vector>

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

	static inline double fitness(const double *inventory) noexcept {
		return inventory[Items::minecraft::emerald];
	}

	static std::pair<std::vector<size_t>, double> *find(const double *inventory, std::array<bool, Trade::trades>& array) {
		double amount = fitness(inventory);
		if (amount > 0.0) {
			return new std::pair<std::vector<size_t>, double>(std::vector<size_t>(), amount);
		}

		amount = 0.0;
		std::pair<std::vector<size_t>, double> *max = (std::pair<std::vector<size_t>, double> *) nullptr;
		for (size_t i = 0; i < Trade::trades; ++i) {
			if (!array[i] && good(inventory, &amount, i)) {
				const double *next = on(inventory, amount, i);
				if (good(inventory, next)) {
					array[i] = true;
					std::pair<std::vector<size_t>, double> *pair = find(next, array);
					array[i] = false;
					delete[] next;

					pair->first.push_back(i);
					if (max) {
						if (pair->second > max->second || (
							pair->second == max->second &&
							pair->first.size() < max->first.size()
						)) {
							delete max;
							max = pair;
						} else {
							delete pair;
						}
					} else {
						max = pair;
					}
				} else {
					delete[] next;
				}
			}
		}

		if (max) {
			return max;
		} else {
			return new std::pair<std::vector<size_t>, double>(std::vector<size_t>(), 0.0);
		}
	}

	static inline bool find(const std::set<size_t>& wants, const std::set<size_t>& items, size_t item) noexcept {
		if (wants.find(item) != wants.end()) {
			return true;
		}

		if (items.find(item) != items.end()) {
			return true;
		}

		return false;
	}

	static void find(const std::set<size_t>& wants, std::set<size_t>& items, std::map<size_t, std::set<size_t>>& weights, std::set<size_t>& weight, size_t item) {
		items.insert(item);

		const size_t index = Items::sum::index[item];
		const size_t next = Items::sum::next[item];
		std::set<size_t> in;
		std::set<size_t> out;

		for (size_t i = index; i < next; ++i) {
			const double value = Items::sum::quantity[i];

			if (value > 0.0) {
				in.insert(Items::sum::item[i]);
			} else if (value < 0.0) {
				out.insert(Items::sum::item[i]);
			}
		}

		for (const auto& trade : out) {
			if (weight.find(trade) != weight.end()) {
				continue;
			}

			bool out = false;
			const size_t index = Trade::sum::index[trade];
			const size_t next = Trade::sum::next[trade];
			for (size_t i = index; i < next; ++i) {
				const size_t first = Trade::sum::item[i];
				if (first == item) {
					continue;
				}

				if (find(wants, items, first)) {
					const double second = Trade::sum::quantity[i];
					if (second > 0.0) {
						out = true;
					} else if (second < 0.0 && (
						weights.find(trade) == weights.end() ||
						weights[trade].find(first) == weights[trade].end()
					)) {
						out = false;
						break;
					}
				}
			}

			if (out) {
				weights[trade].insert(item);
			} else {
				weight.insert(trade);
			}
		}

		for (const auto& trade : in) {
			if (weight.find(trade) != weight.end()) {
				continue;
			}

			const size_t index = Trade::in::index[trade];
			const size_t next = Trade::in::next[trade];
			for (size_t i = index; i < next; ++i) {
				const size_t item = Trade::in::item[i];
				weights[trade].insert(item);

				if (items.find(item) == items.end()) {
					find(wants, items, weights, weight, item);
				}
			}
		}
	}

	static void find(const std::set<size_t>& wants, std::set<size_t>& items, std::map<size_t, std::set<size_t>>& weights, std::set<size_t>& weight) {
		std::set<size_t> in;

		for (const auto& item : wants) {
			const size_t index = Items::sum::index[item];
			const size_t next = Items::sum::next[item];

			for (size_t i = index; i < next; ++i) {
				const double value = Items::sum::quantity[i];

				if (value > 0.0) {
					in.insert(Items::sum::item[i]);
				} else if (value < 0.0) {
					weight.insert(Items::sum::item[i]);
				}
			}
		}

		for (const auto& trade : in) {
			if (weight.find(trade) != weight.end()) {
				continue;
			}

			const size_t index = Trade::in::index[trade];
			const size_t next = Trade::in::next[trade];
			for (size_t i = index; i < next; ++i) {
				const size_t item = Trade::in::item[i];
				weights[trade].insert(item);

				if (items.find(item) == items.end()) {
					find(wants, items, weights, weight, item);
				}
			}
		}
	}
} // namespace Path

#endif // PATH_H
