#ifndef INVENTORY_H
#define INVENTORY_H

#include "Items.hpp"
using Items::size;

class Inventory {
	public:
		Inventory();

		double get(size_t i) const;
		void set(size_t i, double amount);

		void add(size_t i, double amount);
		void remove(size_t i, double amount);

		void commit();

		~Inventory();

	private:
		double in[size];
		double out[size];
};

#endif // INVENTORY_H
