#ifndef ITEMS_H
#define ITEMS_H

#include <algorithm>
#include <cstddef>
#include <iterator>
#include <string>

namespace Items {
	static const size_t size = 25;

	typedef struct {
		const std::string name;
		const double rate;
	} Item;

	static const Item item[size] {
		{"axolotl_bucket", 0.0},
		{"brain_coral", 0.0},
		{"brain_coral_block", 0.0},
		{"brain_coral_fan", 0.0},
		{"bubble_coral", 0.0},
		{"bubble_coral_block", 0.0},
		{"emerald", 0.0},
		{"fire_coral", 0.0},
		{"fire_coral_block", 0.0},
		{"fire_coral_fan", 0.0},
		{"horn_coral", 0.0},
		{"horn_coral_block", 0.0},
		{"horn_coral_fan", 0.0},
		{"kelp", 0.0},
		{"nautilus_shell", 0.0},
		{"pufferfish_bucket", 0.0},
		{"scute", 0.0},
		{"seagrass", 0.0},
		{"sea_pickle", 0.0},
		{"sponge", 0.0},
		{"tropical_fish_bucket", 0.0},
		{"tube_coral", 0.0},
		{"tube_coral_block", 0.0},
		{"tube_coran_fan", 0.0},
		{"water_bucket", 0.0},
	};

	template <typename T>
	void remove_copy_if(size_t i, T& result) {
		if (i < size) {
			const std::string& name = item[i].name;

			std::remove_copy_if(name.begin(), name.end(), std::back_inserter(result), [](char c){ return c == '_'; });
		}
	}
}

#endif // ITEMS_H
