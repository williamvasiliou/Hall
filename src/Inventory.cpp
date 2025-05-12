#include "Inventory.hpp"

Inventory *Inventory::is(double *items, double *rate) {
	if (!items) {
		items = new double[Items::size] {};
	}

	if (!rate) {
		rate = new double[Items::size] {};
		for (size_t i = 0; i < Items::size; ++i) {
			rate[i] = Items::item[i].rate;
		}
	}

	return new Inventory(items, rate);
}

Inventory::Inventory(const double *items, const double *rate) :
	items(items),
	rate(rate),
	in{},
	out{}
{
	this->restore();
}

double Inventory::get(size_t i) const {
	return i < Items::size ? this->in[i] : 0.0;
}

void Inventory::set(size_t i, double amount) {
	if (i < Items::size) {
		this->in[i] = amount;
		this->out[i] = amount;
	}
}

void Inventory::add(size_t i, double amount) {
	this->out[i] += amount;
}

void Inventory::remove(size_t i, double amount) {
	this->out[i] -= amount;
}

void Inventory::commit() {
	for (size_t i = 0; i < Items::size; ++i) {
		this->out[i] += this->rate[i];
		this->in[i] = this->out[i];
	}
}

void Inventory::restore() {
	for (size_t i = 0; i < Items::size; ++i) {
		this->in[i] = this->items[i];
		this->out[i] = this->items[i];
	}
}

std::ostream& operator<<(std::ostream& out, const Inventory& inventory) {
	out << "\t\"items\": {" << std::endl;
	bool rest = false;
	for (size_t i = 0; i < Items::size; ++i) {
		const double quantity = inventory.in[i];
		if (quantity > 0.0) {
			if (rest) {
				std::cout << "," << std::endl;
			}

			std::cout << "\t\t\"" << Items::item[i].name << "\": " << quantity;
			rest = true;
		}
	}
	if (rest) {
		out << std::endl;
	}
	out << "\t}," << std::endl;

	out << "\t\"rate\": {" << std::endl;
	rest = false;
	for (size_t i = 0; i < Items::size; ++i) {
		const double rate = inventory.rate[i];
		if (rate > 0.0) {
			if (rest) {
				std::cout << "," << std::endl;
			}

			std::cout << "\t\t\"" << Items::item[i].name << "\": " << rate;
			rest = true;
		}
	}
	if (rest) {
		out << std::endl;
	}
	out << "\t}";
	return out;
}

Inventory::~Inventory() {
	delete[] this->items;
	delete[] this->rate;
}
