#ifndef TRADE_H
#define TRADE_H

#include "Inventory.hpp"
#include "TradeRow.hpp"
#include <unordered_map>

class Trade {
	public:
		Trade();

		const std::unordered_map<size_t, TradeRow>& getIn() const;
		void setIn(size_t i, const TradeRow& row);
		void setWeight(size_t i, double weight);

		const std::unordered_map<size_t, double>& getOut() const;
		void setOut(size_t i, double amount);

		void on(Inventory& inventory) const;

		friend std::ostream& operator<<(std::ostream& out, const Trade& trade);

		~Trade();

	private:
		std::unordered_map<size_t, TradeRow> in;
		std::unordered_map<size_t, double> out;
};

#endif // TRADE_H
