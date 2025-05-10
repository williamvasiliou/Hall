#include "Inventory.hpp"

Inventory *Inventory::is(const double *items) {
	if (!items) {
		items = new double[Items::size] {};
	}

	return new Inventory(items);
}

Inventory::Inventory(const double *items) :
	items(items),
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
		this->out[i] += Items::item[i].rate;
		this->in[i] = this->out[i];
	}
}

void Inventory::restore() {
	for (size_t i = 0; i < Items::size; ++i) {
		this->in[i] = this->items[i];
		this->out[i] = this->items[i];
	}
}

double Inventory::operator[](size_t i) const noexcept {
	return this->in[i];
}

std::ostream& operator<<(std::ostream& out, const Inventory& inventory) {
	out << "Inventory:" << std::endl;

	for (size_t i = 0; i < Items::size; ++i) {
		const Items::Item item = Items::item[i];
		const double inventoryIn = inventory.in[i];
		const double inventoryOut = inventory.out[i];

		out << "\t" << item.name << ": " << inventoryIn;

		if (inventoryIn != inventoryOut) {
			out << " to " << inventoryOut;
		}

		if (item.rate > 0.0) {
			out << " (" << item.rate << "/T)" << std::endl;
		} else {
			out << std::endl;
		}
	}

	return out;
}

Inventory::~Inventory() {
	delete[] this->items;
}
