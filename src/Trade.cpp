#include "Trade.hpp"

Trade::Trade() {}

const std::unordered_map<size_t, TradeRow>& Trade::getIn() const {
	return this->in;
}

void Trade::setIn(size_t i, const TradeRow& row) {
	this->in[i] = row;
}

const std::unordered_map<size_t, double>& Trade::getOut() const {
	return this->out;
}

void Trade::setOut(size_t i, double amount) {
	this->out[i] = amount;
}

void Trade::on(Inventory& inventory) const {
	double min = -1.0;

	for (auto&& [key, value] : this->in) {
		const double amount = inventory.get(key) * value.weight;

		if (amount > 0.0001) {
			const double factor = amount / value.amount;

			if (min < 0.0 || factor < min) {
				min = factor;
			}
		} else {
			return;
		}
	}

	if (min > 0.0001) {
		for (auto&& [key, value] : this->in) {
			inventory.remove(key, value.amount * min);
		}

		for(auto&& [key, value] : this->out) {
			inventory.add(key, value * min);
		}
	}
}

Trade::~Trade() {}
