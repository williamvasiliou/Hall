#ifndef TRADE_ROW_H
#define TRADE_ROW_H

class TradeRow {
	public:
		explicit TradeRow();
		TradeRow(double amount, double weight);

		double amount;
		double weight;

		~TradeRow();
};

#endif // TRADE_ROW_H
