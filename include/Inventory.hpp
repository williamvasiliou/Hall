#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream>
#include "Items.hpp"
#include <vector>

class Inventory {
	public:
		static Inventory *is(double *items, double *rate);

		double get(size_t i) const;
		void set(size_t i, double amount);

		void add(size_t i, double amount);
		void remove(size_t i, double amount);

		void commit();
		void restore();
		void restore(size_t index);

		template <size_t trades>
		inline void population(size_t population) {
			if (this->weight) {
				delete this->weight;
			}
			this->weight = new std::vector<std::vector<std::pair<size_t, double>>>();

			for (size_t i = 0; i < population; ++i) {
				std::vector<std::pair<size_t, double>> vector;
				for (size_t j = 0; j < trades; ++j) {
					vector.push_back({j, 0.0});
				}
				this->weight->push_back(vector);
			}
		}
		void trade(size_t trade, double amount);

		inline const std::vector<std::pair<size_t, double>>& checkout() const noexcept {
			return (*this->weight)[this->index];
		}

		inline std::vector<std::pair<size_t, double>>& checkout() noexcept {
			return (*this->weight)[this->index];
		}

		inline const std::vector<std::pair<size_t, double>>& checkout(size_t index) const noexcept {
			return (*this->weight)[index];
		}

		inline std::vector<std::pair<size_t, double>>& checkout(size_t index) noexcept {
			return (*this->weight)[index];
		}

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

		std::vector<std::vector<std::pair<size_t, double>>> *weight;
		size_t index;
};

#endif // INVENTORY_H
