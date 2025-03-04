#include "Inventory.hpp"

Inventory::Inventory() :
	in{},
	out{}
{}

double Inventory::get(size_t i) const {
	return i < size ? this->in[i] : 0.0;
}

void Inventory::set(size_t i, double amount) {
	if (i < size) {
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
	for (size_t i = 0; i < size; ++i) {
		this->out[i] += Items::item[i].rate;
		this->in[i] = this->out[i];
	}
}

std::ostream& operator<<(std::ostream& out, const Inventory& inventory) {
	out << "Inventory:" << std::endl;

	for (size_t i = 0; i < size; ++i) {
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

Inventory::~Inventory() {}
