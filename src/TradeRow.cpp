#include "TradeRow.hpp"

TradeRow::TradeRow() :
	amount(0.0),
	weight(0.0)
{}

TradeRow::TradeRow(double amount, double weight) :
	amount(amount),
	weight(weight)
{}

TradeRow::~TradeRow() {}
