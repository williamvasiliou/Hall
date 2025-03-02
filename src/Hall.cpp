#include "Trade.hpp"
#include <iostream>
#include <vector>

bool good(const Inventory& inventory, const std::vector<Trade>& trades) {
	if (size <= 0) {
		return false;
	}

	std::string previous = Items::item[0].name;
	for (size_t i = 1; i < size; ++i) {
		if (Items::item[i].name <= previous) {
			return false;
		}

		previous = Items::item[i].name;
	}

	for (size_t i = 0; i < size; ++i) {
		if (Items::item[i].rate < 0.0 || inventory.get(i) < 0.0) {
			return false;
		}
	}

	double weights[size] {};

	for (auto& trade : trades) {
		auto& in = trade.getIn();
		auto& out = trade.getOut();
		bool keys[size] {};

		if (in.size() <= 0 || out.size() <= 0) {
			return false;
		}

		for (auto&& [key, value] : in) {
			if (value.amount < 1.0 || value.weight < 0.0 || value.weight > 1.0 || key >= size || keys[key]) {
				return false;
			}

			weights[key] += value.weight;
			keys[key] = true;
		}

		for (auto&& [key, value] : out) {
			if (value < 1.0 || key >= size || keys[key]) {
				return false;
			}

			keys[key] = true;
		}
	}

	for (auto weight : weights) {
		if (weight < 0.0 || weight > 1.0) {
			return false;
		}
	}

	return true;
}

int main(int argc, char *argv[]) {
	Inventory inventory;
	std::vector<Trade> trades(24);

	trades[0].setIn(6, {3.0, 0.0});
	trades[0].setOut(18, 1.0);

	trades[1].setIn(6, {5.0, 0.0});
	trades[1].setOut(24, 1.0);

	trades[2].setIn(17, {4.0, 0.0});
	trades[2].setOut(6, 1.0);

	trades[3].setIn(13, {8.0, 0.0});
	trades[3].setOut(6, 2.0);

	trades[4].setIn(6, {3.0, 0.0});
	trades[4].setOut(1, 1.0);

	trades[5].setIn(6, {3.0, 0.0});
	trades[5].setOut(4, 1.0);

	trades[6].setIn(6, {3.0, 0.0});
	trades[6].setOut(7, 1.0);

	trades[7].setIn(6, {3.0, 0.0});
	trades[7].setOut(10, 1.0);

	trades[8].setIn(6, {3.0, 0.0});
	trades[8].setOut(21, 1.0);

	trades[9].setIn(6, {3.0, 0.0});
	trades[9].setOut(3, 1.0);

	trades[10].setIn(6, {3.0, 0.0});
	trades[10].setOut(9, 1.0);

	trades[11].setIn(6, {3.0, 0.0});
	trades[11].setOut(12, 1.0);

	trades[12].setIn(6, {3.0, 0.0});
	trades[12].setOut(23, 1.0);

	trades[13].setIn(6, {5.0, 0.0});
	trades[13].setOut(2, 1.0);

	trades[14].setIn(6, {5.0, 0.0});
	trades[14].setOut(5, 1.0);

	trades[15].setIn(6, {5.0, 0.0});
	trades[15].setOut(8, 1.0);

	trades[16].setIn(6, {5.0, 0.0});
	trades[16].setOut(11, 1.0);

	trades[17].setIn(6, {5.0, 0.0});
	trades[17].setOut(22, 1.0);

	trades[18].setIn(6, {6.0, 0.0});
	trades[18].setOut(14, 1.0);

	trades[19].setIn(6, {8.0, 0.0});
	trades[19].setOut(19, 1.0);

	trades[20].setIn(16, {1.0, 0.0});
	trades[20].setOut(6, 4.0);

	trades[21].setIn(20, {1.0, 0.0});
	trades[21].setOut(6, 5.0);

	trades[22].setIn(0, {1.0, 0.0});
	trades[22].setOut(6, 5.0);

	trades[23].setIn(15, {1.0, 0.0});
	trades[23].setOut(6, 5.0);

	if (good(inventory, trades)) {
		for (auto& trade : trades) {
			trade.on(inventory);
		}

		inventory.commit();
	}

	return 0;
}
