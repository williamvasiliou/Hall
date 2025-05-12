#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream>
#include "Items.hpp"

class Inventory {
	public:
		static Inventory *is(double *items, double *rate);

		double get(size_t i) const;
		void set(size_t i, double amount);

		void add(size_t i, double amount);
		void remove(size_t i, double amount);

		void commit();
		void restore();

		inline double fitness() const noexcept {
			return this->in[Items::minecraft::emerald];
		}

		inline double operator[](size_t i) const noexcept {
			return this->in[i];
		}
		friend std::ostream& operator<<(std::ostream& out, const Inventory& inventory);

		~Inventory();

	private:
		explicit Inventory(const double *items, const double *rate);

		const double *items;
		const double *rate;

		double in[Items::size];
		double out[Items::size];
};

#endif // INVENTORY_H
