#include "Trade.hpp"
#include <iostream>
#include <random>
#include <vector>

static const size_t population = 100;
static const size_t weights = population * Items::trades;

static double weight[weights] {};

static std::random_device rd;
static std::mt19937 gen(rd());
static std::uniform_real_distribution<> dis(0.0, 1.0);

bool good(const Inventory& inventory, const std::vector<Trade>& trades) {
	if (size <= 0) {
		return false;
	}

	std::string previous = Items::item[0].name;

	for (size_t i = 1; i < size; ++i) {
		const std::string& next = Items::item[i].name;

		if (next <= previous) {
			return false;
		}

		previous = next;
	}

	for (size_t i = 0; i < size; ++i) {
		if (Items::item[i].rate < 0.0 || inventory.get(i) < 0.0) {
			return false;
		}
	}

	double weights[size] {};

	for (auto& trade : trades) {
		auto& in = trade.getIn();
		auto& out = trade.getOut();
		std::vector<bool> keys(size, false);

		if (in.size() <= 0 || out.size() <= 0) {
			return false;
		}

		for (auto&& [key, value] : in) {
			if (value.amount < 1.0 || value.weight < 0.0 || value.weight > 1.0 || key >= size || keys[key]) {
				return false;
			}

			weights[key] += value.weight;
			keys[key] = true;
		}

		for (auto&& [key, value] : out) {
			if (value < 1.0 || key >= size || (
				key != Items::minecraft::arrow &&
				key != Items::minecraft::bolt_armor_trim_smithing_template &&
				key != Items::minecraft::book &&
				key != Items::minecraft::bucket &&
				key != Items::minecraft::carpet &&
				key != Items::minecraft::coast_armor_trim_smithing_template &&
				key != Items::minecraft::dune_armor_trim_smithing_template &&
				key != Items::minecraft::dye &&
				key != Items::minecraft::emptymap &&
				key != Items::minecraft::eye_armor_trim_smithing_template &&
				key != Items::minecraft::flow_armor_trim_smithing_template &&
				key != Items::minecraft::grindstone &&
				key != Items::minecraft::host_armor_trim_smithing_template &&
				key != Items::minecraft::netherite_upgrade_smithing_template &&
				key != Items::minecraft::potion_type &&
				key != Items::minecraft::purpur_block &&
				key != Items::minecraft::quartz_block &&
				key != Items::minecraft::raiser_armor_trim_smithing_template &&
				key != Items::minecraft::rib_armor_trim_smithing_template &&
				key != Items::minecraft::sentry_armor_trim_smithing_template &&
				key != Items::minecraft::shaper_armor_trim_smithing_template &&
				key != Items::minecraft::silence_armor_trim_smithing_template &&
				key != Items::minecraft::snout_armor_trim_smithing_template &&
				key != Items::minecraft::spire_armor_trim_smithing_template &&
				key != Items::minecraft::string &&
				key != Items::minecraft::tide_armor_trim_smithing_template &&
				key != Items::minecraft::vex_armor_trim_smithing_template &&
				key != Items::minecraft::ward_armor_trim_smithing_template &&
				key != Items::minecraft::wayfinder_armor_trim_smithing_template &&
				key != Items::minecraft::wild_armor_trim_smithing_template &&
				keys[key]
			)) {
				return false;
			}

			keys[key] = true;
		}
	}

	for (auto weight : weights) {
		if (weight < 0.0 || weight > 1.0) {
			return false;
		}
	}

	return true;
}

void setWeights(double *weights) {
	for (size_t i = 0; i < size; ++i) {
		const size_t index = Items::item[i].index;
		const size_t size = Items::item[i].size;
		const size_t end = index + size;

		if (size > 0 && end <= Items::trades) {
			double sum = 0.0;

			for (size_t j = index; j < end; ++j) {
				const double weight = dis(gen);

				weights[j] = weight;
				sum += weight;
			}

			if (sum > 0.001) {
				sum = dis(gen) / sum;

				for (size_t j = index; j < end; ++j) {
					weights[j] *= sum;
				}
			} else {
				sum = dis(gen);

				for (size_t j = index; j < end; ++j) {
					weights[j] *= sum;
				}
			}
		}
	}
}

void setWeights(std::vector<Trade>& trades, double *weights) {
	for (size_t i = 0; i < size; ++i) {
		const size_t index = Items::item[i].index;
		const size_t size = Items::item[i].size;
		const size_t end = index + size;

		if (size > 0 && end <= Items::trades) {
			for (size_t j = index; j < end; ++j) {
				trades[Items::trade[j]].setWeight(i, weights[j]);
			}
		}
	}
}

int main() {
	Inventory inventory;
	std::vector<Trade> trades(1895);

	// mojang/bedrock-samples-main/behavior_pack/trading/economy_trades/armorer_trades.json
	trades[0].setIn(Items::minecraft::coal, {15.0, 0.0});
	trades[0].setOut(Items::minecraft::emerald, 1.0);
	trades[1].setIn(Items::minecraft::emerald, {7.0, 0.0});
	trades[1].setOut(Items::minecraft::iron_leggings, 1.0);
	trades[2].setIn(Items::minecraft::emerald, {4.0, 0.0});
	trades[2].setOut(Items::minecraft::iron_boots, 1.0);
	trades[3].setIn(Items::minecraft::emerald, {5.0, 0.0});
	trades[3].setOut(Items::minecraft::iron_helmet, 1.0);
	trades[4].setIn(Items::minecraft::emerald, {9.0, 0.0});
	trades[4].setOut(Items::minecraft::iron_chestplate, 1.0);
	trades[5].setIn(Items::minecraft::iron_ingot, {4.0, 0.0});
	trades[5].setOut(Items::minecraft::emerald, 1.0);
	trades[6].setIn(Items::minecraft::emerald, {36.0, 0.0});
	trades[6].setOut(Items::minecraft::bell, 1.0);
	trades[7].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[7].setOut(Items::minecraft::chainmail_boots, 1.0);
	trades[8].setIn(Items::minecraft::emerald, {3.0, 0.0});
	trades[8].setOut(Items::minecraft::chainmail_leggings, 1.0);
	trades[9].setIn(Items::minecraft::bucket, {1.0, 0.0});
	trades[9].setOut(Items::minecraft::emerald, 1.0);
	trades[10].setIn(Items::minecraft::diamond, {1.0, 0.0});
	trades[10].setOut(Items::minecraft::emerald, 1.0);
	trades[11].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[11].setOut(Items::minecraft::chainmail_helmet, 1.0);
	trades[12].setIn(Items::minecraft::emerald, {4.0, 0.0});
	trades[12].setOut(Items::minecraft::chainmail_chestplate, 1.0);
	trades[13].setIn(Items::minecraft::emerald, {5.0, 0.0});
	trades[13].setOut(Items::minecraft::shield, 1.0);
	trades[14].setIn(Items::minecraft::emerald, {14.0, 0.0});
	trades[14].setOut(Items::minecraft::diamond_leggings, 1.0);
	trades[15].setIn(Items::minecraft::emerald, {8.0, 0.0});
	trades[15].setOut(Items::minecraft::diamond_boots, 1.0);
	trades[16].setIn(Items::minecraft::emerald, {8.0, 0.0});
	trades[16].setOut(Items::minecraft::diamond_helmet, 1.0);
	trades[17].setIn(Items::minecraft::emerald, {16.0, 0.0});
	trades[17].setOut(Items::minecraft::diamond_chestplate, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/trading/economy_trades/butcher_trades.json
	trades[18].setIn(Items::minecraft::chicken, {14.0, 0.0});
	trades[18].setOut(Items::minecraft::emerald, 1.0);
	trades[19].setIn(Items::minecraft::rabbit, {4.0, 0.0});
	trades[19].setOut(Items::minecraft::emerald, 1.0);
	trades[20].setIn(Items::minecraft::porkchop, {7.0, 0.0});
	trades[20].setOut(Items::minecraft::emerald, 1.0);
	trades[21].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[21].setOut(Items::minecraft::rabbit_stew, 1.0);
	trades[22].setIn(Items::minecraft::coal, {15.0, 0.0});
	trades[22].setOut(Items::minecraft::emerald, 1.0);
	trades[23].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[23].setOut(Items::minecraft::cooked_chicken, 8.0);
	trades[24].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[24].setOut(Items::minecraft::cooked_porkchop, 5.0);
	trades[25].setIn(Items::minecraft::beef, {10.0, 0.0});
	trades[25].setOut(Items::minecraft::emerald, 1.0);
	trades[26].setIn(Items::minecraft::muttonraw, {7.0, 0.0});
	trades[26].setOut(Items::minecraft::emerald, 1.0);
	trades[27].setIn(Items::minecraft::dried_kelp_block, {10.0, 0.0});
	trades[27].setOut(Items::minecraft::emerald, 1.0);
	trades[28].setIn(Items::minecraft::sweet_berries, {10.0, 0.0});
	trades[28].setOut(Items::minecraft::emerald, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/trading/economy_trades/cartographer_trades.json
	trades[29].setIn(Items::minecraft::paper, {24.0, 0.0});
	trades[29].setOut(Items::minecraft::emerald, 1.0);
	trades[30].setIn(Items::minecraft::emerald, {7.0, 0.0});
	trades[30].setOut(Items::minecraft::emptymap, 1.0);
	trades[31].setIn(Items::minecraft::glass_pane, {11.0, 0.0});
	trades[31].setOut(Items::minecraft::emerald, 1.0);
	trades[32].setIn(Items::minecraft::emerald, {13.0, 0.0});
	trades[32].setIn(Items::minecraft::compass, {1.0, 0.0});
	trades[32].setOut(Items::minecraft::map, 1.0);
	trades[33].setIn(Items::minecraft::compass, {1.0, 0.0});
	trades[33].setOut(Items::minecraft::emerald, 1.0);
	trades[34].setIn(Items::minecraft::emerald, {14.0, 0.0});
	trades[34].setIn(Items::minecraft::compass, {1.0, 0.0});
	trades[34].setOut(Items::minecraft::map, 1.0);
	trades[35].setIn(Items::minecraft::emerald, {12.0, 0.0});
	trades[35].setIn(Items::minecraft::compass, {1.0, 0.0});
	trades[35].setOut(Items::minecraft::map, 1.0);
	trades[36].setIn(Items::minecraft::emerald, {7.0, 0.0});
	trades[36].setOut(Items::minecraft::frame, 1.0);
	trades[37].setIn(Items::minecraft::emerald, {3.0, 0.0});
	trades[37].setOut(Items::minecraft::banner, 1.0);
	trades[38].setIn(Items::minecraft::emerald, {8.0, 0.0});
	trades[38].setOut(Items::minecraft::banner_pattern, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/trading/economy_trades/cleric_trades.json
	trades[39].setIn(Items::minecraft::rotten_flesh, {32.0, 0.0});
	trades[39].setOut(Items::minecraft::emerald, 1.0);
	trades[40].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[40].setOut(Items::minecraft::redstone, 2.0);
	trades[41].setIn(Items::minecraft::gold_ingot, {3.0, 0.0});
	trades[41].setOut(Items::minecraft::emerald, 1.0);
	trades[42].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[42].setOut(Items::minecraft::dye, 1.0);
	trades[43].setIn(Items::minecraft::rabbit_foot, {2.0, 0.0});
	trades[43].setOut(Items::minecraft::emerald, 1.0);
	trades[44].setIn(Items::minecraft::emerald, {4.0, 0.0});
	trades[44].setOut(Items::minecraft::glowstone, 1.0);
	trades[45].setIn(Items::minecraft::turtle_shell_piece, {4.0, 0.0});
	trades[45].setOut(Items::minecraft::emerald, 1.0);
	trades[46].setIn(Items::minecraft::glass_bottle, {9.0, 0.0});
	trades[46].setOut(Items::minecraft::emerald, 1.0);
	trades[47].setIn(Items::minecraft::emerald, {5.0, 0.0});
	trades[47].setOut(Items::minecraft::ender_pearl, 1.0);
	trades[48].setIn(Items::minecraft::nether_wart, {22.0, 0.0});
	trades[48].setOut(Items::minecraft::emerald, 1.0);
	trades[49].setIn(Items::minecraft::emerald, {3.0, 0.0});
	trades[49].setOut(Items::minecraft::experience_bottle, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/trading/economy_trades/farmer_trades.json
	trades[50].setIn(Items::minecraft::wheat, {20.0, 0.0});
	trades[50].setOut(Items::minecraft::emerald, 1.0);
	trades[51].setIn(Items::minecraft::potato, {26.0, 0.0});
	trades[51].setOut(Items::minecraft::emerald, 1.0);
	trades[52].setIn(Items::minecraft::beetroot, {15.0, 0.0});
	trades[52].setOut(Items::minecraft::emerald, 1.0);
	trades[53].setIn(Items::minecraft::carrot, {22.0, 0.0});
	trades[53].setOut(Items::minecraft::emerald, 1.0);
	trades[54].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[54].setOut(Items::minecraft::bread, 6.0);
	trades[55].setIn(Items::minecraft::pumpkin, {6.0, 0.0});
	trades[55].setOut(Items::minecraft::emerald, 1.0);
	trades[56].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[56].setOut(Items::minecraft::pumpkin_pie, 4.0);
	trades[57].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[57].setOut(Items::minecraft::apple, 4.0);
	trades[58].setIn(Items::minecraft::melon_block, {4.0, 0.0});
	trades[58].setOut(Items::minecraft::emerald, 1.0);
	trades[59].setIn(Items::minecraft::emerald, {3.0, 0.0});
	trades[59].setOut(Items::minecraft::cookie, 18.0);
	trades[60].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[60].setOut(Items::minecraft::suspicious_stew, 1.0);
	trades[61].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[61].setOut(Items::minecraft::cake, 1.0);
	trades[62].setIn(Items::minecraft::emerald, {3.0, 0.0});
	trades[62].setOut(Items::minecraft::golden_carrot, 3.0);
	trades[63].setIn(Items::minecraft::emerald, {4.0, 0.0});
	trades[63].setOut(Items::minecraft::speckled_melon, 3.0);

	// mojang/bedrock-samples-main/behavior_pack/trading/economy_trades/fisherman_trades.json
	trades[64].setIn(Items::minecraft::string, {20.0, 0.0});
	trades[64].setOut(Items::minecraft::emerald, 1.0);
	trades[65].setIn(Items::minecraft::coal, {10.0, 0.0});
	trades[65].setOut(Items::minecraft::emerald, 1.0);
	trades[66].setIn(Items::minecraft::emerald, {3.0, 0.0});
	trades[66].setOut(Items::minecraft::bucket, 1.0);
	trades[67].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[67].setIn(Items::minecraft::fish, {6.0, 0.0});
	trades[67].setOut(Items::minecraft::cooked_fish, 6.0);
	trades[68].setIn(Items::minecraft::fish, {15.0, 0.0});
	trades[68].setOut(Items::minecraft::emerald, 1.0);
	trades[69].setIn(Items::minecraft::emerald, {2.0, 0.0});
	trades[69].setOut(Items::minecraft::campfire, 1.0);
	trades[70].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[70].setIn(Items::minecraft::salmon, {6.0, 0.0});
	trades[70].setOut(Items::minecraft::cooked_salmon, 6.0);
	trades[71].setIn(Items::minecraft::salmon, {13.0, 0.0});
	trades[71].setOut(Items::minecraft::emerald, 1.0);
	trades[72].setIn(Items::minecraft::emerald, {3.0, 0.0});
	trades[72].setOut(Items::minecraft::fishing_rod, 1.0);
	trades[73].setIn(Items::minecraft::clownfish, {6.0, 0.0});
	trades[73].setOut(Items::minecraft::emerald, 1.0);
	trades[74].setIn(Items::minecraft::pufferfish, {4.0, 0.0});
	trades[74].setOut(Items::minecraft::emerald, 1.0);
	trades[75].setIn(Items::minecraft::oak_boat, {1.0, 0.0});
	trades[75].setOut(Items::minecraft::emerald, 1.0);
	trades[76].setIn(Items::minecraft::spruce_boat, {1.0, 0.0});
	trades[76].setOut(Items::minecraft::emerald, 1.0);
	trades[77].setIn(Items::minecraft::jungle_boat, {1.0, 0.0});
	trades[77].setOut(Items::minecraft::emerald, 1.0);
	trades[78].setIn(Items::minecraft::acacia_boat, {1.0, 0.0});
	trades[78].setOut(Items::minecraft::emerald, 1.0);
	trades[79].setIn(Items::minecraft::dark_oak_boat, {1.0, 0.0});
	trades[79].setOut(Items::minecraft::emerald, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/trading/economy_trades/fletcher_trades.json
	trades[80].setIn(Items::minecraft::stick, {32.0, 0.0});
	trades[80].setOut(Items::minecraft::emerald, 1.0);
	trades[81].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[81].setOut(Items::minecraft::arrow, 16.0);
	trades[82].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[82].setIn(Items::minecraft::gravel, {10.0, 0.0});
	trades[82].setOut(Items::minecraft::flint, 10.0);
	trades[83].setIn(Items::minecraft::flint, {26.0, 0.0});
	trades[83].setOut(Items::minecraft::emerald, 1.0);
	trades[84].setIn(Items::minecraft::emerald, {2.0, 0.0});
	trades[84].setOut(Items::minecraft::bow, 1.0);
	trades[85].setIn(Items::minecraft::string, {14.0, 0.0});
	trades[85].setOut(Items::minecraft::emerald, 1.0);
	trades[86].setIn(Items::minecraft::emerald, {3.0, 0.0});
	trades[86].setOut(Items::minecraft::crossbow, 1.0);
	trades[87].setIn(Items::minecraft::feather, {24.0, 0.0});
	trades[87].setOut(Items::minecraft::emerald, 1.0);
	trades[88].setIn(Items::minecraft::emerald, {2.0, 0.0});
	trades[88].setOut(Items::minecraft::bow, 1.0);
	trades[89].setIn(Items::minecraft::tripwire_hook, {8.0, 0.0});
	trades[89].setOut(Items::minecraft::emerald, 1.0);
	trades[90].setIn(Items::minecraft::emerald, {3.0, 0.0});
	trades[90].setOut(Items::minecraft::crossbow, 1.0);
	trades[91].setIn(Items::minecraft::emerald, {2.0, 0.0});
	trades[91].setIn(Items::minecraft::arrow, {5.0, 0.0});
	trades[91].setOut(Items::minecraft::arrow, 5.0);
	trades[92].setIn(Items::minecraft::emerald, {2.0, 0.0});
	trades[92].setIn(Items::minecraft::arrow, {5.0, 0.0});
	trades[92].setOut(Items::minecraft::arrow, 5.0);
	trades[93].setIn(Items::minecraft::emerald, {2.0, 0.0});
	trades[93].setIn(Items::minecraft::arrow, {5.0, 0.0});
	trades[93].setOut(Items::minecraft::arrow, 5.0);
	trades[94].setIn(Items::minecraft::emerald, {2.0, 0.0});
	trades[94].setIn(Items::minecraft::arrow, {5.0, 0.0});
	trades[94].setOut(Items::minecraft::arrow, 5.0);
	trades[95].setIn(Items::minecraft::emerald, {2.0, 0.0});
	trades[95].setIn(Items::minecraft::arrow, {5.0, 0.0});
	trades[95].setOut(Items::minecraft::arrow, 5.0);
	trades[96].setIn(Items::minecraft::emerald, {2.0, 0.0});
	trades[96].setIn(Items::minecraft::arrow, {5.0, 0.0});
	trades[96].setOut(Items::minecraft::arrow, 5.0);
	trades[97].setIn(Items::minecraft::emerald, {2.0, 0.0});
	trades[97].setIn(Items::minecraft::arrow, {5.0, 0.0});
	trades[97].setOut(Items::minecraft::arrow, 5.0);
	trades[98].setIn(Items::minecraft::emerald, {2.0, 0.0});
	trades[98].setIn(Items::minecraft::arrow, {5.0, 0.0});
	trades[98].setOut(Items::minecraft::arrow, 5.0);
	trades[99].setIn(Items::minecraft::emerald, {2.0, 0.0});
	trades[99].setIn(Items::minecraft::arrow, {5.0, 0.0});
	trades[99].setOut(Items::minecraft::arrow, 5.0);
	trades[100].setIn(Items::minecraft::emerald, {2.0, 0.0});
	trades[100].setIn(Items::minecraft::arrow, {5.0, 0.0});
	trades[100].setOut(Items::minecraft::arrow, 5.0);
	trades[101].setIn(Items::minecraft::emerald, {2.0, 0.0});
	trades[101].setIn(Items::minecraft::arrow, {5.0, 0.0});
	trades[101].setOut(Items::minecraft::arrow, 5.0);
	trades[102].setIn(Items::minecraft::emerald, {2.0, 0.0});
	trades[102].setIn(Items::minecraft::arrow, {5.0, 0.0});
	trades[102].setOut(Items::minecraft::arrow, 5.0);
	trades[103].setIn(Items::minecraft::emerald, {2.0, 0.0});
	trades[103].setIn(Items::minecraft::arrow, {5.0, 0.0});
	trades[103].setOut(Items::minecraft::arrow, 5.0);
	trades[104].setIn(Items::minecraft::emerald, {2.0, 0.0});
	trades[104].setIn(Items::minecraft::arrow, {5.0, 0.0});
	trades[104].setOut(Items::minecraft::arrow, 5.0);
	trades[105].setIn(Items::minecraft::emerald, {2.0, 0.0});
	trades[105].setIn(Items::minecraft::arrow, {5.0, 0.0});
	trades[105].setOut(Items::minecraft::arrow, 5.0);

	// mojang/bedrock-samples-main/behavior_pack/trading/economy_trades/leather_worker_trades.json
	trades[106].setIn(Items::minecraft::leather, {6.0, 0.0});
	trades[106].setOut(Items::minecraft::emerald, 1.0);
	trades[107].setIn(Items::minecraft::emerald, {3.0, 0.0});
	trades[107].setOut(Items::minecraft::leather_leggings, 1.0);
	trades[108].setIn(Items::minecraft::emerald, {7.0, 0.0});
	trades[108].setOut(Items::minecraft::leather_chestplate, 1.0);
	trades[109].setIn(Items::minecraft::flint, {26.0, 0.0});
	trades[109].setOut(Items::minecraft::emerald, 1.0);
	trades[110].setIn(Items::minecraft::emerald, {5.0, 0.0});
	trades[110].setOut(Items::minecraft::leather_helmet, 1.0);
	trades[111].setIn(Items::minecraft::emerald, {4.0, 0.0});
	trades[111].setOut(Items::minecraft::leather_boots, 1.0);
	trades[112].setIn(Items::minecraft::rabbit_hide, {9.0, 0.0});
	trades[112].setOut(Items::minecraft::emerald, 1.0);
	trades[113].setIn(Items::minecraft::emerald, {7.0, 0.0});
	trades[113].setOut(Items::minecraft::leather_chestplate, 1.0);
	trades[114].setIn(Items::minecraft::turtle_shell_piece, {4.0, 0.0});
	trades[114].setOut(Items::minecraft::emerald, 1.0);
	trades[115].setIn(Items::minecraft::emerald, {6.0, 0.0});
	trades[115].setOut(Items::minecraft::horsearmorleather, 1.0);
	trades[116].setIn(Items::minecraft::emerald, {5.0, 0.0});
	trades[116].setOut(Items::minecraft::leather_helmet, 1.0);
	trades[117].setIn(Items::minecraft::emerald, {6.0, 0.0});
	trades[117].setOut(Items::minecraft::saddle, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/trading/economy_trades/librarian_trades.json
	trades[118].setIn(Items::minecraft::paper, {24.0, 0.0});
	trades[118].setOut(Items::minecraft::emerald, 1.0);
	trades[119].setIn(Items::minecraft::emerald, {9.0, 0.0});
	trades[119].setOut(Items::minecraft::bookshelf, 1.0);
	trades[120].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[120].setIn(Items::minecraft::book, {1.0, 0.0});
	trades[120].setOut(Items::minecraft::book, 1.0);
	trades[121].setIn(Items::minecraft::book, {4.0, 0.0});
	trades[121].setOut(Items::minecraft::emerald, 1.0);
	trades[122].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[122].setOut(Items::minecraft::lantern, 1.0);
	trades[123].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[123].setIn(Items::minecraft::book, {1.0, 0.0});
	trades[123].setOut(Items::minecraft::book, 1.0);
	trades[124].setIn(Items::minecraft::dye, {5.0, 0.0});
	trades[124].setOut(Items::minecraft::emerald, 1.0);
	trades[125].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[125].setOut(Items::minecraft::glass, 4.0);
	trades[126].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[126].setIn(Items::minecraft::book, {1.0, 0.0});
	trades[126].setOut(Items::minecraft::book, 1.0);
	trades[127].setIn(Items::minecraft::writable_book, {2.0, 0.0});
	trades[127].setOut(Items::minecraft::emerald, 1.0);
	trades[128].setIn(Items::minecraft::emerald, {4.0, 0.0});
	trades[128].setOut(Items::minecraft::compass, 1.0);
	trades[129].setIn(Items::minecraft::emerald, {5.0, 0.0});
	trades[129].setOut(Items::minecraft::clock, 1.0);
	trades[130].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[130].setIn(Items::minecraft::book, {1.0, 0.0});
	trades[130].setOut(Items::minecraft::book, 1.0);
	trades[131].setIn(Items::minecraft::emerald, {20.0, 0.0});
	trades[131].setOut(Items::minecraft::nametag, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/trading/economy_trades/shepherd_trades.json
	trades[132].setIn(Items::minecraft::white_wool, {18.0, 0.0});
	trades[132].setOut(Items::minecraft::emerald, 1.0);
	trades[133].setIn(Items::minecraft::gray_wool, {18.0, 0.0});
	trades[133].setOut(Items::minecraft::emerald, 1.0);
	trades[134].setIn(Items::minecraft::brown_wool, {18.0, 0.0});
	trades[134].setOut(Items::minecraft::emerald, 1.0);
	trades[135].setIn(Items::minecraft::black_wool, {18.0, 0.0});
	trades[135].setOut(Items::minecraft::emerald, 1.0);
	trades[136].setIn(Items::minecraft::emerald, {2.0, 0.0});
	trades[136].setOut(Items::minecraft::shears, 1.0);
	trades[137].setIn(Items::minecraft::black_dye, {12.0, 0.0});
	trades[137].setOut(Items::minecraft::emerald, 1.0);
	trades[138].setIn(Items::minecraft::gray_dye, {12.0, 0.0});
	trades[138].setOut(Items::minecraft::emerald, 1.0);
	trades[139].setIn(Items::minecraft::lime_dye, {12.0, 0.0});
	trades[139].setOut(Items::minecraft::emerald, 1.0);
	trades[140].setIn(Items::minecraft::light_blue_dye, {12.0, 0.0});
	trades[140].setOut(Items::minecraft::emerald, 1.0);
	trades[141].setIn(Items::minecraft::white_dye, {12.0, 0.0});
	trades[141].setOut(Items::minecraft::emerald, 1.0);
	trades[142].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[142].setOut(Items::minecraft::white_wool, 1.0);
	trades[143].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[143].setOut(Items::minecraft::orange_wool, 1.0);
	trades[144].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[144].setOut(Items::minecraft::magenta_wool, 1.0);
	trades[145].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[145].setOut(Items::minecraft::light_blue_wool, 1.0);
	trades[146].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[146].setOut(Items::minecraft::yellow_wool, 1.0);
	trades[147].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[147].setOut(Items::minecraft::lime_wool, 1.0);
	trades[148].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[148].setOut(Items::minecraft::pink_wool, 1.0);
	trades[149].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[149].setOut(Items::minecraft::gray_wool, 1.0);
	trades[150].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[150].setOut(Items::minecraft::light_gray_wool, 1.0);
	trades[151].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[151].setOut(Items::minecraft::cyan_wool, 1.0);
	trades[152].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[152].setOut(Items::minecraft::purple_wool, 1.0);
	trades[153].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[153].setOut(Items::minecraft::blue_wool, 1.0);
	trades[154].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[154].setOut(Items::minecraft::brown_wool, 1.0);
	trades[155].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[155].setOut(Items::minecraft::green_wool, 1.0);
	trades[156].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[156].setOut(Items::minecraft::red_wool, 1.0);
	trades[157].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[157].setOut(Items::minecraft::black_wool, 1.0);
	trades[158].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[158].setOut(Items::minecraft::white_carpet, 4.0);
	trades[159].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[159].setOut(Items::minecraft::orange_carpet, 4.0);
	trades[160].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[160].setOut(Items::minecraft::magenta_carpet, 4.0);
	trades[161].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[161].setOut(Items::minecraft::light_blue_carpet, 4.0);
	trades[162].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[162].setOut(Items::minecraft::yellow_carpet, 4.0);
	trades[163].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[163].setOut(Items::minecraft::lime_carpet, 4.0);
	trades[164].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[164].setOut(Items::minecraft::pink_carpet, 4.0);
	trades[165].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[165].setOut(Items::minecraft::gray_carpet, 4.0);
	trades[166].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[166].setOut(Items::minecraft::light_gray_carpet, 4.0);
	trades[167].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[167].setOut(Items::minecraft::cyan_carpet, 4.0);
	trades[168].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[168].setOut(Items::minecraft::purple_carpet, 4.0);
	trades[169].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[169].setOut(Items::minecraft::blue_carpet, 4.0);
	trades[170].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[170].setOut(Items::minecraft::brown_carpet, 4.0);
	trades[171].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[171].setOut(Items::minecraft::green_carpet, 4.0);
	trades[172].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[172].setOut(Items::minecraft::red_carpet, 4.0);
	trades[173].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[173].setOut(Items::minecraft::black_carpet, 4.0);
	trades[174].setIn(Items::minecraft::red_dye, {12.0, 0.0});
	trades[174].setOut(Items::minecraft::emerald, 1.0);
	trades[175].setIn(Items::minecraft::light_gray_dye, {12.0, 0.0});
	trades[175].setOut(Items::minecraft::emerald, 1.0);
	trades[176].setIn(Items::minecraft::pink_dye, {12.0, 0.0});
	trades[176].setOut(Items::minecraft::emerald, 1.0);
	trades[177].setIn(Items::minecraft::yellow_dye, {12.0, 0.0});
	trades[177].setOut(Items::minecraft::emerald, 1.0);
	trades[178].setIn(Items::minecraft::orange_dye, {12.0, 0.0});
	trades[178].setOut(Items::minecraft::emerald, 1.0);
	trades[179].setIn(Items::minecraft::emerald, {3.0, 0.0});
	trades[179].setOut(Items::minecraft::bed, 1.0);
	trades[180].setIn(Items::minecraft::green_dye, {12.0, 0.0});
	trades[180].setOut(Items::minecraft::emerald, 1.0);
	trades[181].setIn(Items::minecraft::brown_dye, {12.0, 0.0});
	trades[181].setOut(Items::minecraft::emerald, 1.0);
	trades[182].setIn(Items::minecraft::blue_dye, {12.0, 0.0});
	trades[182].setOut(Items::minecraft::emerald, 1.0);
	trades[183].setIn(Items::minecraft::purple_dye, {12.0, 0.0});
	trades[183].setOut(Items::minecraft::emerald, 1.0);
	trades[184].setIn(Items::minecraft::cyan_dye, {12.0, 0.0});
	trades[184].setOut(Items::minecraft::emerald, 1.0);
	trades[185].setIn(Items::minecraft::magenta_dye, {12.0, 0.0});
	trades[185].setOut(Items::minecraft::emerald, 1.0);
	trades[186].setIn(Items::minecraft::emerald, {3.0, 0.0});
	trades[186].setOut(Items::minecraft::banner, 1.0);
	trades[187].setIn(Items::minecraft::emerald, {2.0, 0.0});
	trades[187].setOut(Items::minecraft::painting, 3.0);

	// mojang/bedrock-samples-main/behavior_pack/trading/economy_trades/stone_mason_trades.json
	trades[188].setIn(Items::minecraft::clay_ball, {10.0, 0.0});
	trades[188].setOut(Items::minecraft::emerald, 1.0);
	trades[189].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[189].setOut(Items::minecraft::brick, 10.0);
	trades[190].setIn(Items::minecraft::stone, {20.0, 0.0});
	trades[190].setOut(Items::minecraft::emerald, 1.0);
	trades[191].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[191].setOut(Items::minecraft::chiseled_stone_bricks, 4.0);
	trades[192].setIn(Items::minecraft::granite, {16.0, 0.0});
	trades[192].setOut(Items::minecraft::emerald, 1.0);
	trades[193].setIn(Items::minecraft::diorite, {16.0, 0.0});
	trades[193].setOut(Items::minecraft::emerald, 1.0);
	trades[194].setIn(Items::minecraft::andesite, {16.0, 0.0});
	trades[194].setOut(Items::minecraft::emerald, 1.0);
	trades[195].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[195].setOut(Items::minecraft::polished_granite, 4.0);
	trades[196].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[196].setOut(Items::minecraft::polished_diorite, 4.0);
	trades[197].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[197].setOut(Items::minecraft::polished_andesite, 4.0);
	trades[198].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[198].setOut(Items::minecraft::dripstone_block, 4.0);
	trades[199].setIn(Items::minecraft::quartz, {12.0, 0.0});
	trades[199].setOut(Items::minecraft::emerald, 1.0);
	trades[200].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[200].setOut(Items::minecraft::white_terracotta, 1.0);
	trades[201].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[201].setOut(Items::minecraft::orange_terracotta, 1.0);
	trades[202].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[202].setOut(Items::minecraft::magenta_terracotta, 1.0);
	trades[203].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[203].setOut(Items::minecraft::light_blue_terracotta, 1.0);
	trades[204].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[204].setOut(Items::minecraft::yellow_terracotta, 1.0);
	trades[205].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[205].setOut(Items::minecraft::lime_terracotta, 1.0);
	trades[206].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[206].setOut(Items::minecraft::pink_terracotta, 1.0);
	trades[207].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[207].setOut(Items::minecraft::gray_terracotta, 1.0);
	trades[208].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[208].setOut(Items::minecraft::light_gray_terracotta, 1.0);
	trades[209].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[209].setOut(Items::minecraft::cyan_terracotta, 1.0);
	trades[210].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[210].setOut(Items::minecraft::purple_terracotta, 1.0);
	trades[211].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[211].setOut(Items::minecraft::blue_terracotta, 1.0);
	trades[212].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[212].setOut(Items::minecraft::brown_terracotta, 1.0);
	trades[213].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[213].setOut(Items::minecraft::green_terracotta, 1.0);
	trades[214].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[214].setOut(Items::minecraft::red_terracotta, 1.0);
	trades[215].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[215].setOut(Items::minecraft::black_terracotta, 1.0);
	trades[216].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[216].setOut(Items::minecraft::black_glazed_terracotta, 1.0);
	trades[217].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[217].setOut(Items::minecraft::blue_glazed_terracotta, 1.0);
	trades[218].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[218].setOut(Items::minecraft::brown_glazed_terracotta, 1.0);
	trades[219].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[219].setOut(Items::minecraft::cyan_glazed_terracotta, 1.0);
	trades[220].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[220].setOut(Items::minecraft::gray_glazed_terracotta, 1.0);
	trades[221].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[221].setOut(Items::minecraft::green_glazed_terracotta, 1.0);
	trades[222].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[222].setOut(Items::minecraft::light_blue_glazed_terracotta, 1.0);
	trades[223].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[223].setOut(Items::minecraft::lime_glazed_terracotta, 1.0);
	trades[224].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[224].setOut(Items::minecraft::magenta_glazed_terracotta, 1.0);
	trades[225].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[225].setOut(Items::minecraft::orange_glazed_terracotta, 1.0);
	trades[226].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[226].setOut(Items::minecraft::pink_glazed_terracotta, 1.0);
	trades[227].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[227].setOut(Items::minecraft::purple_glazed_terracotta, 1.0);
	trades[228].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[228].setOut(Items::minecraft::red_glazed_terracotta, 1.0);
	trades[229].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[229].setOut(Items::minecraft::silver_glazed_terracotta, 1.0);
	trades[230].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[230].setOut(Items::minecraft::white_glazed_terracotta, 1.0);
	trades[231].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[231].setOut(Items::minecraft::yellow_glazed_terracotta, 1.0);
	trades[232].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[232].setOut(Items::minecraft::quartz_block, 1.0);
	trades[233].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[233].setOut(Items::minecraft::quartz_pillar, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/trading/economy_trades/tool_smith_trades.json
	trades[234].setIn(Items::minecraft::coal, {15.0, 0.0});
	trades[234].setOut(Items::minecraft::emerald, 1.0);
	trades[235].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[235].setOut(Items::minecraft::stone_axe, 1.0);
	trades[236].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[236].setOut(Items::minecraft::stone_shovel, 1.0);
	trades[237].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[237].setOut(Items::minecraft::stone_pickaxe, 1.0);
	trades[238].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[238].setOut(Items::minecraft::stone_hoe, 1.0);
	trades[239].setIn(Items::minecraft::iron_ingot, {4.0, 0.0});
	trades[239].setOut(Items::minecraft::emerald, 1.0);
	trades[240].setIn(Items::minecraft::emerald, {36.0, 0.0});
	trades[240].setOut(Items::minecraft::bell, 1.0);
	trades[241].setIn(Items::minecraft::flint, {30.0, 0.0});
	trades[241].setOut(Items::minecraft::emerald, 1.0);
	trades[242].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[242].setOut(Items::minecraft::iron_axe, 1.0);
	trades[243].setIn(Items::minecraft::emerald, {2.0, 0.0});
	trades[243].setOut(Items::minecraft::iron_shovel, 1.0);
	trades[244].setIn(Items::minecraft::emerald, {3.0, 0.0});
	trades[244].setOut(Items::minecraft::iron_pickaxe, 1.0);
	trades[245].setIn(Items::minecraft::emerald, {4.0, 0.0});
	trades[245].setOut(Items::minecraft::diamond_hoe, 1.0);
	trades[246].setIn(Items::minecraft::diamond, {1.0, 0.0});
	trades[246].setOut(Items::minecraft::emerald, 1.0);
	trades[247].setIn(Items::minecraft::emerald, {12.0, 0.0});
	trades[247].setOut(Items::minecraft::diamond_axe, 1.0);
	trades[248].setIn(Items::minecraft::emerald, {5.0, 0.0});
	trades[248].setOut(Items::minecraft::diamond_shovel, 1.0);
	trades[249].setIn(Items::minecraft::emerald, {13.0, 0.0});
	trades[249].setOut(Items::minecraft::diamond_pickaxe, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/trading/economy_trades/wandering_trader_trades.json
	trades[250].setIn(Items::minecraft::emerald, {2.0, 0.0});
	trades[250].setOut(Items::minecraft::sea_pickle, 1.0);
	trades[251].setIn(Items::minecraft::emerald, {4.0, 0.0});
	trades[251].setOut(Items::minecraft::slime_ball, 1.0);
	trades[252].setIn(Items::minecraft::emerald, {2.0, 0.0});
	trades[252].setOut(Items::minecraft::glowstone, 1.0);
	trades[253].setIn(Items::minecraft::emerald, {5.0, 0.0});
	trades[253].setOut(Items::minecraft::nautilus_shell, 1.0);
	trades[254].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[254].setOut(Items::minecraft::fern, 1.0);
	trades[255].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[255].setOut(Items::minecraft::reeds, 1.0);
	trades[256].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[256].setOut(Items::minecraft::pumpkin, 1.0);
	trades[257].setIn(Items::minecraft::emerald, {3.0, 0.0});
	trades[257].setOut(Items::minecraft::kelp, 1.0);
	trades[258].setIn(Items::minecraft::emerald, {3.0, 0.0});
	trades[258].setOut(Items::minecraft::cactus, 1.0);
	trades[259].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[259].setOut(Items::minecraft::dandelion, 1.0);
	trades[260].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[260].setOut(Items::minecraft::poppy, 1.0);
	trades[261].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[261].setOut(Items::minecraft::blue_orchid, 1.0);
	trades[262].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[262].setOut(Items::minecraft::allium, 1.0);
	trades[263].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[263].setOut(Items::minecraft::azure_bluet, 1.0);
	trades[264].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[264].setOut(Items::minecraft::red_tulip, 1.0);
	trades[265].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[265].setOut(Items::minecraft::orange_tulip, 1.0);
	trades[266].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[266].setOut(Items::minecraft::white_tulip, 1.0);
	trades[267].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[267].setOut(Items::minecraft::pink_tulip, 1.0);
	trades[268].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[268].setOut(Items::minecraft::oxeye_daisy, 1.0);
	trades[269].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[269].setOut(Items::minecraft::cornflower, 1.0);
	trades[270].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[270].setOut(Items::minecraft::lily_of_the_valley, 1.0);
	trades[271].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[271].setOut(Items::minecraft::open_eyeblossom, 1.0);
	trades[272].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[272].setOut(Items::minecraft::wheat_seeds, 1.0);
	trades[273].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[273].setOut(Items::minecraft::beetroot_seeds, 1.0);
	trades[274].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[274].setOut(Items::minecraft::pumpkin_seeds, 1.0);
	trades[275].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[275].setOut(Items::minecraft::melon_seeds, 1.0);
	trades[276].setIn(Items::minecraft::emerald, {5.0, 0.0});
	trades[276].setOut(Items::minecraft::oak_sapling, 1.0);
	trades[277].setIn(Items::minecraft::emerald, {5.0, 0.0});
	trades[277].setOut(Items::minecraft::spruce_sapling, 1.0);
	trades[278].setIn(Items::minecraft::emerald, {5.0, 0.0});
	trades[278].setOut(Items::minecraft::birch_sapling, 1.0);
	trades[279].setIn(Items::minecraft::emerald, {5.0, 0.0});
	trades[279].setOut(Items::minecraft::jungle_sapling, 1.0);
	trades[280].setIn(Items::minecraft::emerald, {5.0, 0.0});
	trades[280].setOut(Items::minecraft::acacia_sapling, 1.0);
	trades[281].setIn(Items::minecraft::emerald, {5.0, 0.0});
	trades[281].setOut(Items::minecraft::dark_oak_sapling, 1.0);
	trades[282].setIn(Items::minecraft::emerald, {5.0, 0.0});
	trades[282].setOut(Items::minecraft::cherry_sapling, 1.0);
	trades[283].setIn(Items::minecraft::emerald, {5.0, 0.0});
	trades[283].setOut(Items::minecraft::mangrove_propagule, 1.0);
	trades[284].setIn(Items::minecraft::emerald, {5.0, 0.0});
	trades[284].setOut(Items::minecraft::pale_oak_sapling, 1.0);
	trades[285].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[285].setOut(Items::minecraft::red_dye, 3.0);
	trades[286].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[286].setOut(Items::minecraft::white_dye, 3.0);
	trades[287].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[287].setOut(Items::minecraft::blue_dye, 3.0);
	trades[288].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[288].setOut(Items::minecraft::pink_dye, 3.0);
	trades[289].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[289].setOut(Items::minecraft::black_dye, 3.0);
	trades[290].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[290].setOut(Items::minecraft::green_dye, 3.0);
	trades[291].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[291].setOut(Items::minecraft::light_gray_dye, 3.0);
	trades[292].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[292].setOut(Items::minecraft::magenta_dye, 3.0);
	trades[293].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[293].setOut(Items::minecraft::yellow_dye, 3.0);
	trades[294].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[294].setOut(Items::minecraft::gray_dye, 3.0);
	trades[295].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[295].setOut(Items::minecraft::purple_dye, 3.0);
	trades[296].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[296].setOut(Items::minecraft::light_blue_dye, 3.0);
	trades[297].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[297].setOut(Items::minecraft::lime_dye, 3.0);
	trades[298].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[298].setOut(Items::minecraft::orange_dye, 3.0);
	trades[299].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[299].setOut(Items::minecraft::brown_dye, 3.0);
	trades[300].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[300].setOut(Items::minecraft::cyan_dye, 3.0);
	trades[301].setIn(Items::minecraft::emerald, {3.0, 0.0});
	trades[301].setOut(Items::minecraft::tube_coral_block, 1.0);
	trades[302].setIn(Items::minecraft::emerald, {3.0, 0.0});
	trades[302].setOut(Items::minecraft::brain_coral_block, 1.0);
	trades[303].setIn(Items::minecraft::emerald, {3.0, 0.0});
	trades[303].setOut(Items::minecraft::bubble_coral_block, 1.0);
	trades[304].setIn(Items::minecraft::emerald, {3.0, 0.0});
	trades[304].setOut(Items::minecraft::fire_coral_block, 1.0);
	trades[305].setIn(Items::minecraft::emerald, {3.0, 0.0});
	trades[305].setOut(Items::minecraft::horn_coral_block, 1.0);
	trades[306].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[306].setOut(Items::minecraft::vine, 1.0);
	trades[307].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[307].setOut(Items::minecraft::pale_hanging_moss, 1.0);
	trades[308].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[308].setOut(Items::minecraft::brown_mushroom, 1.0);
	trades[309].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[309].setOut(Items::minecraft::red_mushroom, 1.0);
	trades[310].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[310].setOut(Items::minecraft::waterlily, 2.0);
	trades[311].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[311].setOut(Items::minecraft::small_dripleaf_block, 2.0);
	trades[312].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[312].setOut(Items::minecraft::sand, 8.0);
	trades[313].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[313].setOut(Items::minecraft::red_sand, 4.0);
	trades[314].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[314].setOut(Items::minecraft::pointed_dripstone, 2.0);
	trades[315].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[315].setOut(Items::minecraft::dirt_with_roots, 2.0);
	trades[316].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[316].setOut(Items::minecraft::moss_block, 2.0);
	trades[317].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[317].setOut(Items::minecraft::pale_moss_block, 2.0);
	trades[318].setIn(Items::minecraft::emerald, {5.0, 0.0});
	trades[318].setOut(Items::minecraft::bucket, 1.0);
	trades[319].setIn(Items::minecraft::emerald, {5.0, 0.0});
	trades[319].setOut(Items::minecraft::bucket, 1.0);
	trades[320].setIn(Items::minecraft::emerald, {3.0, 0.0});
	trades[320].setOut(Items::minecraft::packed_ice, 1.0);
	trades[321].setIn(Items::minecraft::emerald, {6.0, 0.0});
	trades[321].setOut(Items::minecraft::blue_ice, 1.0);
	trades[322].setIn(Items::minecraft::emerald, {1.0, 0.0});
	trades[322].setOut(Items::minecraft::gunpowder, 1.0);
	trades[323].setIn(Items::minecraft::emerald, {3.0, 0.0});
	trades[323].setOut(Items::minecraft::podzol, 3.0);

	// mojang/bedrock-samples-main/behavior_pack/trading/economy_trades/weapon_smith_trades.json
	trades[324].setIn(Items::minecraft::coal, {15.0, 0.0});
	trades[324].setOut(Items::minecraft::emerald, 1.0);
	trades[325].setIn(Items::minecraft::emerald, {3.0, 0.0});
	trades[325].setOut(Items::minecraft::iron_axe, 1.0);
	trades[326].setIn(Items::minecraft::emerald, {2.0, 0.0});
	trades[326].setOut(Items::minecraft::iron_sword, 1.0);
	trades[327].setIn(Items::minecraft::iron_ingot, {4.0, 0.0});
	trades[327].setOut(Items::minecraft::emerald, 1.0);
	trades[328].setIn(Items::minecraft::emerald, {36.0, 0.0});
	trades[328].setOut(Items::minecraft::bell, 1.0);
	trades[329].setIn(Items::minecraft::flint, {24.0, 0.0});
	trades[329].setOut(Items::minecraft::emerald, 1.0);
	trades[330].setIn(Items::minecraft::diamond, {1.0, 0.0});
	trades[330].setOut(Items::minecraft::emerald, 1.0);
	trades[331].setIn(Items::minecraft::emerald, {12.0, 0.0});
	trades[331].setOut(Items::minecraft::diamond_axe, 1.0);
	trades[332].setIn(Items::minecraft::emerald, {8.0, 0.0});
	trades[332].setOut(Items::minecraft::diamond_sword, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/acacia_boat.json
	trades[333].setIn(Items::minecraft::acacia_planks, {5.0, 0.0});
	trades[333].setOut(Items::minecraft::acacia_boat, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/acacia_chest_boat.json
	trades[334].setIn(Items::minecraft::chest, {1.0, 0.0});
	trades[334].setIn(Items::minecraft::boat, {1.0, 0.0});
	trades[334].setOut(Items::minecraft::chest_boat, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/acacia_door.json
	trades[335].setIn(Items::minecraft::acacia_planks, {6.0, 0.0});
	trades[335].setOut(Items::minecraft::acacia_door, 3.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/acacia_fence_gate.json
	trades[336].setIn(Items::minecraft::stick, {4.0, 0.0});
	trades[336].setIn(Items::minecraft::acacia_planks, {2.0, 0.0});
	trades[336].setOut(Items::minecraft::acacia_fence_gate, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/acacia_fence.json
	trades[337].setIn(Items::minecraft::stick, {2.0, 0.0});
	trades[337].setIn(Items::minecraft::acacia_planks, {4.0, 0.0});
	trades[337].setOut(Items::minecraft::acacia_fence, 3.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/acacia_hanging_sign.json
	trades[338].setIn(Items::minecraft::stripped_acacia_log, {6.0, 0.0});
	trades[338].setIn(Items::minecraft::chain, {2.0, 0.0});
	trades[338].setOut(Items::minecraft::acacia_hanging_sign, 6.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/acacia_planks_from_stripped.json
	trades[339].setIn(Items::minecraft::stripped_acacia_log, {1.0, 0.0});
	trades[339].setOut(Items::minecraft::acacia_planks, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/acacia_planks_from_stripped_wood.json
	trades[340].setIn(Items::minecraft::stripped_acacia_wood, {1.0, 0.0});
	trades[340].setOut(Items::minecraft::acacia_planks, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/acacia_planks_from_wood.json
	trades[341].setIn(Items::minecraft::acacia_wood, {1.0, 0.0});
	trades[341].setOut(Items::minecraft::acacia_planks, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/acacia_planks.json
	trades[342].setIn(Items::minecraft::acacia_log, {1.0, 0.0});
	trades[342].setOut(Items::minecraft::acacia_planks, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/acacia_stairs.json
	trades[343].setIn(Items::minecraft::acacia_planks, {6.0, 0.0});
	trades[343].setOut(Items::minecraft::acacia_stairs, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/acacia_wooden_slab.json
	trades[344].setIn(Items::minecraft::acacia_planks, {3.0, 0.0});
	trades[344].setOut(Items::minecraft::acacia_slab, 6.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/acacia_wood.json
	trades[345].setIn(Items::minecraft::acacia_log, {4.0, 0.0});
	trades[345].setOut(Items::minecraft::acacia_wood, 3.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/acacia_wood_stripped.json
	trades[346].setIn(Items::minecraft::stripped_acacia_log, {4.0, 0.0});
	trades[346].setOut(Items::minecraft::stripped_acacia_wood, 3.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/activator_rail.json
	trades[347].setIn(Items::minecraft::redstone_torch, {1.0, 0.0});
	trades[347].setIn(Items::minecraft::stick, {2.0, 0.0});
	trades[347].setIn(Items::minecraft::iron_ingot, {6.0, 0.0});
	trades[347].setOut(Items::minecraft::activator_rail, 6.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/amethyst_block.json
	trades[348].setIn(Items::minecraft::amethyst_shard, {4.0, 0.0});
	trades[348].setOut(Items::minecraft::amethyst_block, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/andesite.json
	trades[349].setIn(Items::minecraft::diorite, {1.0, 0.0});
	trades[349].setIn(Items::minecraft::cobblestone, {1.0, 0.0});
	trades[349].setOut(Items::minecraft::andesite, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/andesite_stairs.json
	trades[350].setIn(Items::minecraft::andesite, {6.0, 0.0});
	trades[350].setOut(Items::minecraft::andesite_stairs, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/andesite_wall.json
	trades[351].setIn(Items::minecraft::andesite, {6.0, 0.0});
	trades[351].setOut(Items::minecraft::andesite_wall, 6.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/anvil.json
	trades[352].setIn(Items::minecraft::iron_block, {3.0, 0.0});
	trades[352].setIn(Items::minecraft::iron_ingot, {4.0, 0.0});
	trades[352].setOut(Items::minecraft::anvil, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/armor_stand.json
	trades[353].setIn(Items::minecraft::stick, {6.0, 0.0});
	trades[353].setIn(Items::minecraft::smooth_stone_slab, {1.0, 0.0});
	trades[353].setOut(Items::minecraft::armor_stand, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/arrow.json
	trades[354].setIn(Items::minecraft::stick, {1.0, 0.0});
	trades[354].setIn(Items::minecraft::flint, {1.0, 0.0});
	trades[354].setIn(Items::minecraft::feather, {1.0, 0.0});
	trades[354].setOut(Items::minecraft::arrow, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/bamboo_block.json
	trades[355].setIn(Items::minecraft::bamboo, {9.0, 0.0});
	trades[355].setOut(Items::minecraft::bamboo_block, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/bamboo_button.json
	trades[356].setIn(Items::minecraft::bamboo_planks, {1.0, 0.0});
	trades[356].setOut(Items::minecraft::bamboo_button, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/bamboo_chest_raft.json
	trades[357].setIn(Items::minecraft::chest, {1.0, 0.0});
	trades[357].setIn(Items::minecraft::boat, {1.0, 0.0});
	trades[357].setOut(Items::minecraft::chest_boat, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/bamboo_door.json
	trades[358].setIn(Items::minecraft::bamboo_planks, {6.0, 0.0});
	trades[358].setOut(Items::minecraft::bamboo_door, 3.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/bamboo_fence_gate.json
	trades[359].setIn(Items::minecraft::stick, {4.0, 0.0});
	trades[359].setIn(Items::minecraft::bamboo_planks, {2.0, 0.0});
	trades[359].setOut(Items::minecraft::bamboo_fence_gate, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/bamboo_fence.json
	trades[360].setIn(Items::minecraft::stick, {2.0, 0.0});
	trades[360].setIn(Items::minecraft::bamboo_planks, {4.0, 0.0});
	trades[360].setOut(Items::minecraft::bamboo_fence, 3.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/bamboo_hanging_sign.json
	trades[361].setIn(Items::minecraft::stripped_bamboo_block, {6.0, 0.0});
	trades[361].setIn(Items::minecraft::chain, {2.0, 0.0});
	trades[361].setOut(Items::minecraft::bamboo_hanging_sign, 6.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/bamboo_mosaic.json
	trades[362].setIn(Items::minecraft::bamboo_slab, {2.0, 0.0});
	trades[362].setOut(Items::minecraft::bamboo_mosaic, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/bamboo_mosaic_slab.json
	trades[363].setIn(Items::minecraft::bamboo_mosaic, {3.0, 0.0});
	trades[363].setOut(Items::minecraft::bamboo_mosaic_slab, 6.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/bamboo_mosiac_stairs.json
	trades[364].setIn(Items::minecraft::bamboo_mosaic, {6.0, 0.0});
	trades[364].setOut(Items::minecraft::bamboo_mosaic_stairs, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/bamboo_planks_from_stripped.json
	trades[365].setIn(Items::minecraft::stripped_bamboo_block, {1.0, 0.0});
	trades[365].setOut(Items::minecraft::bamboo_planks, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/bamboo_planks.json
	trades[366].setIn(Items::minecraft::bamboo_block, {1.0, 0.0});
	trades[366].setOut(Items::minecraft::bamboo_planks, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/bamboo_pressure_plate.json
	trades[367].setIn(Items::minecraft::bamboo_planks, {2.0, 0.0});
	trades[367].setOut(Items::minecraft::bamboo_pressure_plate, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/bamboo_raft.json
	trades[368].setIn(Items::minecraft::bamboo_planks, {5.0, 0.0});
	trades[368].setOut(Items::minecraft::bamboo_raft, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/bamboo_sign.json
	trades[369].setIn(Items::minecraft::bamboo_planks, {6.0, 0.0});
	trades[369].setIn(Items::minecraft::stick, {1.0, 0.0});
	trades[369].setOut(Items::minecraft::bamboo_sign, 3.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/bamboo_slab.json
	trades[370].setIn(Items::minecraft::bamboo_planks, {3.0, 0.0});
	trades[370].setOut(Items::minecraft::bamboo_slab, 6.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/bamboo_stairs.json
	trades[371].setIn(Items::minecraft::bamboo_planks, {6.0, 0.0});
	trades[371].setOut(Items::minecraft::bamboo_stairs, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/bamboo_trapdoor.json
	trades[372].setIn(Items::minecraft::bamboo_planks, {6.0, 0.0});
	trades[372].setOut(Items::minecraft::bamboo_trapdoor, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/banner_pattern_bricks.json
	trades[373].setIn(Items::minecraft::paper, {1.0, 0.0});
	trades[373].setIn(Items::minecraft::brick_block, {1.0, 0.0});
	trades[373].setOut(Items::minecraft::banner_pattern, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/banner_pattern_creeper.json
	trades[374].setIn(Items::minecraft::paper, {1.0, 0.0});
	trades[374].setIn(Items::minecraft::skull, {1.0, 0.0});
	trades[374].setOut(Items::minecraft::banner_pattern, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/banner_pattern_flower.json
	trades[375].setIn(Items::minecraft::paper, {1.0, 0.0});
	trades[375].setIn(Items::minecraft::oxeye_daisy, {1.0, 0.0});
	trades[375].setOut(Items::minecraft::banner_pattern, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/banner_pattern_skull.json
	trades[376].setIn(Items::minecraft::paper, {1.0, 0.0});
	trades[376].setIn(Items::minecraft::skull, {1.0, 0.0});
	trades[376].setOut(Items::minecraft::banner_pattern, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/banner_pattern_thing.json
	trades[377].setIn(Items::minecraft::paper, {1.0, 0.0});
	trades[377].setIn(Items::minecraft::appleenchanted, {1.0, 0.0});
	trades[377].setOut(Items::minecraft::banner_pattern, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/banner_pattern_vines.json
	trades[378].setIn(Items::minecraft::paper, {1.0, 0.0});
	trades[378].setIn(Items::minecraft::vine, {1.0, 0.0});
	trades[378].setOut(Items::minecraft::banner_pattern, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/barrel_deprecated.json
	trades[379].setIn(Items::minecraft::stick, {6.0, 0.0});
	trades[379].setIn(Items::minecraft::wooden_slabs, {2.0, 0.0});
	trades[379].setOut(Items::minecraft::barrel, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/barrel_from_crimson_slab_deprecated.json
	trades[380].setIn(Items::minecraft::stick, {6.0, 0.0});
	trades[380].setIn(Items::minecraft::crimson_slab, {2.0, 0.0});
	trades[380].setOut(Items::minecraft::barrel, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/barrel_from_crimson_slab.json
	trades[381].setIn(Items::minecraft::stick, {6.0, 0.0});
	trades[381].setIn(Items::minecraft::crimson_slab, {2.0, 0.0});
	trades[381].setOut(Items::minecraft::barrel, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/barrel_from_mangrove_slab_deprecated.json
	trades[382].setIn(Items::minecraft::stick, {6.0, 0.0});
	trades[382].setIn(Items::minecraft::mangrove_slab, {2.0, 0.0});
	trades[382].setOut(Items::minecraft::barrel, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/barrel_from_mangrove_slab.json
	trades[383].setIn(Items::minecraft::stick, {6.0, 0.0});
	trades[383].setIn(Items::minecraft::mangrove_slab, {2.0, 0.0});
	trades[383].setOut(Items::minecraft::barrel, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/barrel_from_warped_slab_deprecated.json
	trades[384].setIn(Items::minecraft::stick, {6.0, 0.0});
	trades[384].setIn(Items::minecraft::warped_slab, {2.0, 0.0});
	trades[384].setOut(Items::minecraft::barrel, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/barrel_from_warped_slab.json
	trades[385].setIn(Items::minecraft::stick, {6.0, 0.0});
	trades[385].setIn(Items::minecraft::warped_slab, {2.0, 0.0});
	trades[385].setOut(Items::minecraft::barrel, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/barrel.json
	trades[386].setIn(Items::minecraft::planks, {6.0, 0.0});
	trades[386].setIn(Items::minecraft::wooden_slabs, {2.0, 0.0});
	trades[386].setOut(Items::minecraft::barrel, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/barrel_with_tag_deprecated.json
	trades[387].setIn(Items::minecraft::stick, {6.0, 0.0});
	trades[387].setIn(Items::minecraft::wooden_slabs, {2.0, 0.0});
	trades[387].setOut(Items::minecraft::barrel, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/basic_map_to_enhanced.json
	trades[388].setIn(Items::minecraft::emptymap, {1.0, 0.0});
	trades[388].setIn(Items::minecraft::compass, {1.0, 0.0});
	trades[388].setOut(Items::minecraft::emptymap, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/beacon.json
	trades[389].setIn(Items::minecraft::netherstar, {1.0, 0.0});
	trades[389].setIn(Items::minecraft::glass, {5.0, 0.0});
	trades[389].setIn(Items::minecraft::obsidian, {3.0, 0.0});
	trades[389].setOut(Items::minecraft::beacon, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/beehive_from_crimson_planks.json
	trades[390].setIn(Items::minecraft::crimson_planks, {6.0, 0.0});
	trades[390].setIn(Items::minecraft::honeycomb, {3.0, 0.0});
	trades[390].setOut(Items::minecraft::beehive, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/beehive_from_mangrove_planks.json
	trades[391].setIn(Items::minecraft::mangrove_planks, {6.0, 0.0});
	trades[391].setIn(Items::minecraft::honeycomb, {3.0, 0.0});
	trades[391].setOut(Items::minecraft::beehive, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/beehive_from_warped_planks.json
	trades[392].setIn(Items::minecraft::warped_planks, {6.0, 0.0});
	trades[392].setIn(Items::minecraft::honeycomb, {3.0, 0.0});
	trades[392].setOut(Items::minecraft::beehive, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/beehive.json
	trades[393].setIn(Items::minecraft::planks, {6.0, 0.0});
	trades[393].setIn(Items::minecraft::honeycomb, {3.0, 0.0});
	trades[393].setOut(Items::minecraft::beehive, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/beetroot_soup.json
	trades[394].setIn(Items::minecraft::bowl, {1.0, 0.0});
	trades[394].setIn(Items::minecraft::beetroot, {6.0, 0.0});
	trades[394].setOut(Items::minecraft::beetroot_soup, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/birch_boat.json
	trades[395].setIn(Items::minecraft::birch_planks, {5.0, 0.0});
	trades[395].setOut(Items::minecraft::birch_boat, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/birch_chest_boat.json
	trades[396].setIn(Items::minecraft::chest, {1.0, 0.0});
	trades[396].setIn(Items::minecraft::boat, {1.0, 0.0});
	trades[396].setOut(Items::minecraft::chest_boat, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/birch_door.json
	trades[397].setIn(Items::minecraft::birch_planks, {6.0, 0.0});
	trades[397].setOut(Items::minecraft::birch_door, 3.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/birch_fence_gate.json
	trades[398].setIn(Items::minecraft::stick, {4.0, 0.0});
	trades[398].setIn(Items::minecraft::birch_planks, {2.0, 0.0});
	trades[398].setOut(Items::minecraft::birch_fence_gate, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/birch_fence.json
	trades[399].setIn(Items::minecraft::stick, {2.0, 0.0});
	trades[399].setIn(Items::minecraft::birch_planks, {4.0, 0.0});
	trades[399].setOut(Items::minecraft::birch_fence, 3.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/birch_hanging_sign.json
	trades[400].setIn(Items::minecraft::stripped_birch_log, {6.0, 0.0});
	trades[400].setIn(Items::minecraft::chain, {2.0, 0.0});
	trades[400].setOut(Items::minecraft::birch_hanging_sign, 6.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/birch_planks_from_stripped.json
	trades[401].setIn(Items::minecraft::stripped_birch_log, {1.0, 0.0});
	trades[401].setOut(Items::minecraft::birch_planks, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/birch_planks_from_stripped_wood.json
	trades[402].setIn(Items::minecraft::stripped_birch_wood, {1.0, 0.0});
	trades[402].setOut(Items::minecraft::birch_planks, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/birch_planks_from_wood.json
	trades[403].setIn(Items::minecraft::birch_wood, {1.0, 0.0});
	trades[403].setOut(Items::minecraft::birch_planks, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/birch_planks.json
	trades[404].setIn(Items::minecraft::birch_log, {1.0, 0.0});
	trades[404].setOut(Items::minecraft::birch_planks, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/birch_stairs.json
	trades[405].setIn(Items::minecraft::birch_planks, {6.0, 0.0});
	trades[405].setOut(Items::minecraft::birch_stairs, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/birch_wooden_slab.json
	trades[406].setIn(Items::minecraft::birch_planks, {3.0, 0.0});
	trades[406].setOut(Items::minecraft::birch_slab, 6.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/birch_wood.json
	trades[407].setIn(Items::minecraft::birch_log, {4.0, 0.0});
	trades[407].setOut(Items::minecraft::birch_wood, 3.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/birch_wood_stripped.json
	trades[408].setIn(Items::minecraft::stripped_birch_log, {4.0, 0.0});
	trades[408].setOut(Items::minecraft::stripped_birch_wood, 3.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/black_banner.json
	trades[409].setIn(Items::minecraft::black_wool, {6.0, 0.0});
	trades[409].setIn(Items::minecraft::stick, {1.0, 0.0});
	trades[409].setOut(Items::minecraft::banner, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/black_candle_from_ink_sac.json
	trades[410].setIn(Items::minecraft::candle, {1.0, 0.0});
	trades[410].setIn(Items::minecraft::dye, {1.0, 0.0});
	trades[410].setOut(Items::minecraft::black_candle, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/black_candle.json
	trades[411].setIn(Items::minecraft::candle, {1.0, 0.0});
	trades[411].setIn(Items::minecraft::dye, {1.0, 0.0});
	trades[411].setOut(Items::minecraft::black_candle, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/black_carpet_from_white.json
	trades[412].setIn(Items::minecraft::white_carpet, {8.0, 0.0});
	trades[412].setIn(Items::minecraft::black_dye, {1.0, 0.0});
	trades[412].setOut(Items::minecraft::black_carpet, 8.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/black_carpet.json
	trades[413].setIn(Items::minecraft::black_wool, {2.0, 0.0});
	trades[413].setOut(Items::minecraft::black_carpet, 3.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/black_concrete_powder_from_ink_sac.json
	trades[414].setIn(Items::minecraft::ink_sac, {1.0, 0.0});
	trades[414].setIn(Items::minecraft::sand, {4.0, 0.0});
	trades[414].setIn(Items::minecraft::gravel, {4.0, 0.0});
	trades[414].setOut(Items::minecraft::black_concrete_powder, 8.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/black_concrete_powder.json
	trades[415].setIn(Items::minecraft::black_dye, {1.0, 0.0});
	trades[415].setIn(Items::minecraft::sand, {4.0, 0.0});
	trades[415].setIn(Items::minecraft::gravel, {4.0, 0.0});
	trades[415].setOut(Items::minecraft::black_concrete_powder, 8.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/black_dye_from_ink_sac.json
	trades[416].setIn(Items::minecraft::dye, {1.0, 0.0});
	trades[416].setOut(Items::minecraft::dye, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/black_dye_from_wither_rose.json
	trades[417].setIn(Items::minecraft::wither_rose, {1.0, 0.0});
	trades[417].setOut(Items::minecraft::dye, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/black_stained_glass_from_ink_sac.json
	trades[418].setIn(Items::minecraft::glass, {8.0, 0.0});
	trades[418].setIn(Items::minecraft::ink_sac, {1.0, 0.0});
	trades[418].setOut(Items::minecraft::black_stained_glass, 8.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/black_stained_glass.json
	trades[419].setIn(Items::minecraft::glass, {8.0, 0.0});
	trades[419].setIn(Items::minecraft::black_dye, {1.0, 0.0});
	trades[419].setOut(Items::minecraft::black_stained_glass, 8.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/black_stained_glass_pane_from_pane.json
	trades[420].setIn(Items::minecraft::glass_pane, {8.0, 0.0});
	trades[420].setIn(Items::minecraft::black_dye, {1.0, 0.0});
	trades[420].setOut(Items::minecraft::black_stained_glass_pane, 8.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/black_stained_glass_pane.json
	trades[421].setIn(Items::minecraft::black_stained_glass, {6.0, 0.0});
	trades[421].setOut(Items::minecraft::black_stained_glass_pane, 16.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/black_stained_hardened_clay_from_ink_sac.json
	trades[422].setIn(Items::minecraft::hardened_clay, {8.0, 0.0});
	trades[422].setIn(Items::minecraft::ink_sac, {1.0, 0.0});
	trades[422].setOut(Items::minecraft::black_terracotta, 8.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/black_stained_hardened_clay.json
	trades[423].setIn(Items::minecraft::hardened_clay, {8.0, 0.0});
	trades[423].setIn(Items::minecraft::black_dye, {1.0, 0.0});
	trades[423].setOut(Items::minecraft::black_terracotta, 8.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/blackstone_slab.json
	trades[424].setIn(Items::minecraft::blackstone, {3.0, 0.0});
	trades[424].setOut(Items::minecraft::blackstone_slab, 6.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/blackstone_stairs.json
	trades[425].setIn(Items::minecraft::blackstone, {6.0, 0.0});
	trades[425].setOut(Items::minecraft::blackstone_stairs, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/blackstone_wall.json
	trades[426].setIn(Items::minecraft::blackstone, {6.0, 0.0});
	trades[426].setOut(Items::minecraft::blackstone_wall, 6.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/blast_furnace.json
	trades[427].setIn(Items::minecraft::smooth_stone, {3.0, 0.0});
	trades[427].setIn(Items::minecraft::iron_ingot, {5.0, 0.0});
	trades[427].setIn(Items::minecraft::furnace, {1.0, 0.0});
	trades[427].setOut(Items::minecraft::blast_furnace, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/blaze_powder.json
	trades[428].setIn(Items::minecraft::blaze_rod, {1.0, 0.0});
	trades[428].setOut(Items::minecraft::blaze_powder, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/blue_banner.json
	trades[429].setIn(Items::minecraft::blue_wool, {6.0, 0.0});
	trades[429].setIn(Items::minecraft::stick, {1.0, 0.0});
	trades[429].setOut(Items::minecraft::banner, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/blue_candle_from_lapis_lazuli.json
	trades[430].setIn(Items::minecraft::candle, {1.0, 0.0});
	trades[430].setIn(Items::minecraft::dye, {1.0, 0.0});
	trades[430].setOut(Items::minecraft::blue_candle, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/blue_candle.json
	trades[431].setIn(Items::minecraft::candle, {1.0, 0.0});
	trades[431].setIn(Items::minecraft::dye, {1.0, 0.0});
	trades[431].setOut(Items::minecraft::blue_candle, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/blue_carpet_from_white.json
	trades[432].setIn(Items::minecraft::white_carpet, {8.0, 0.0});
	trades[432].setIn(Items::minecraft::blue_dye, {1.0, 0.0});
	trades[432].setOut(Items::minecraft::blue_carpet, 8.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/blue_carpet.json
	trades[433].setIn(Items::minecraft::blue_wool, {2.0, 0.0});
	trades[433].setOut(Items::minecraft::blue_carpet, 3.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/blue_concrete_powder_from_lapis_lazuli.json
	trades[434].setIn(Items::minecraft::lapis_lazuli, {1.0, 0.0});
	trades[434].setIn(Items::minecraft::sand, {4.0, 0.0});
	trades[434].setIn(Items::minecraft::gravel, {4.0, 0.0});
	trades[434].setOut(Items::minecraft::blue_concrete_powder, 8.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/blue_concrete_powder.json
	trades[435].setIn(Items::minecraft::blue_dye, {1.0, 0.0});
	trades[435].setIn(Items::minecraft::sand, {4.0, 0.0});
	trades[435].setIn(Items::minecraft::gravel, {4.0, 0.0});
	trades[435].setOut(Items::minecraft::blue_concrete_powder, 8.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/blue_dye_from_cornflower.json
	trades[436].setIn(Items::minecraft::cornflower, {1.0, 0.0});
	trades[436].setOut(Items::minecraft::dye, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/blue_dye_from_lapis_lazuli.json
	trades[437].setIn(Items::minecraft::dye, {1.0, 0.0});
	trades[437].setOut(Items::minecraft::dye, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/blue_ice.json
	trades[438].setIn(Items::minecraft::packed_ice, {9.0, 0.0});
	trades[438].setOut(Items::minecraft::blue_ice, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/blue_stained_glass_from_lapis_lazuli.json
	trades[439].setIn(Items::minecraft::glass, {8.0, 0.0});
	trades[439].setIn(Items::minecraft::lapis_lazuli, {1.0, 0.0});
	trades[439].setOut(Items::minecraft::blue_stained_glass, 8.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/blue_stained_glass.json
	trades[440].setIn(Items::minecraft::glass, {8.0, 0.0});
	trades[440].setIn(Items::minecraft::blue_dye, {1.0, 0.0});
	trades[440].setOut(Items::minecraft::blue_stained_glass, 8.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/blue_stained_glass_pane_from_pane.json
	trades[441].setIn(Items::minecraft::glass_pane, {8.0, 0.0});
	trades[441].setIn(Items::minecraft::blue_dye, {1.0, 0.0});
	trades[441].setOut(Items::minecraft::blue_stained_glass_pane, 8.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/blue_stained_glass_pane.json
	trades[442].setIn(Items::minecraft::blue_stained_glass, {6.0, 0.0});
	trades[442].setOut(Items::minecraft::blue_stained_glass_pane, 16.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/blue_stained_hardened_clay_from_lapis_lazuli.json
	trades[443].setIn(Items::minecraft::hardened_clay, {8.0, 0.0});
	trades[443].setIn(Items::minecraft::lapis_lazuli, {1.0, 0.0});
	trades[443].setOut(Items::minecraft::blue_terracotta, 8.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/blue_stained_hardened_clay.json
	trades[444].setIn(Items::minecraft::hardened_clay, {8.0, 0.0});
	trades[444].setIn(Items::minecraft::blue_dye, {1.0, 0.0});
	trades[444].setOut(Items::minecraft::blue_terracotta, 8.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/boat.json
	trades[445].setIn(Items::minecraft::oak_planks, {5.0, 0.0});
	trades[445].setOut(Items::minecraft::oak_boat, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/bolt_armor_trim_smithing_template_duplicate.json
	trades[446].setIn(Items::minecraft::bolt_armor_trim_smithing_template, {1.0, 0.0});
	trades[446].setIn(Items::minecraft::diamond, {7.0, 0.0});
	trades[446].setIn(Items::minecraft::copper_block, {1.0, 0.0});
	trades[446].setOut(Items::minecraft::bolt_armor_trim_smithing_template, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/bolt_armor_trim_smithing_template_duplicate_waxed.json
	trades[447].setIn(Items::minecraft::bolt_armor_trim_smithing_template, {1.0, 0.0});
	trades[447].setIn(Items::minecraft::diamond, {7.0, 0.0});
	trades[447].setIn(Items::minecraft::waxed_copper, {1.0, 0.0});
	trades[447].setOut(Items::minecraft::bolt_armor_trim_smithing_template, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/bone_block.json
	trades[448].setIn(Items::minecraft::dye, {9.0, 0.0});
	trades[448].setOut(Items::minecraft::bone_block, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/bone_meal_from_block.json
	trades[449].setIn(Items::minecraft::bone_block, {1.0, 0.0});
	trades[449].setOut(Items::minecraft::dye, 9.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/bone_meal_from_bone.json
	trades[450].setIn(Items::minecraft::bone, {1.0, 0.0});
	trades[450].setOut(Items::minecraft::dye, 3.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/book.json
	trades[451].setIn(Items::minecraft::paper, {3.0, 0.0});
	trades[451].setIn(Items::minecraft::leather, {1.0, 0.0});
	trades[451].setOut(Items::minecraft::book, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/bookshelf_from_crimson_planks.json
	trades[452].setIn(Items::minecraft::crimson_planks, {6.0, 0.0});
	trades[452].setIn(Items::minecraft::book, {3.0, 0.0});
	trades[452].setOut(Items::minecraft::bookshelf, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/bookshelf_from_mangrove_planks.json
	trades[453].setIn(Items::minecraft::mangrove_planks, {6.0, 0.0});
	trades[453].setIn(Items::minecraft::book, {3.0, 0.0});
	trades[453].setOut(Items::minecraft::bookshelf, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/bookshelf_from_warped_planks.json
	trades[454].setIn(Items::minecraft::warped_planks, {6.0, 0.0});
	trades[454].setIn(Items::minecraft::book, {3.0, 0.0});
	trades[454].setOut(Items::minecraft::bookshelf, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/bookshelf.json
	trades[455].setIn(Items::minecraft::planks, {6.0, 0.0});
	trades[455].setIn(Items::minecraft::book, {3.0, 0.0});
	trades[455].setOut(Items::minecraft::bookshelf, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/bow.json
	trades[456].setIn(Items::minecraft::stick, {3.0, 0.0});
	trades[456].setIn(Items::minecraft::string, {3.0, 0.0});
	trades[456].setOut(Items::minecraft::bow, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/bowl_from_crimson_planks.json
	trades[457].setIn(Items::minecraft::crimson_planks, {3.0, 0.0});
	trades[457].setOut(Items::minecraft::bowl, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/bowl_from_mangrove_planks.json
	trades[458].setIn(Items::minecraft::mangrove_planks, {3.0, 0.0});
	trades[458].setOut(Items::minecraft::bowl, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/bowl_from_warped_planks.json
	trades[459].setIn(Items::minecraft::warped_planks, {3.0, 0.0});
	trades[459].setOut(Items::minecraft::bowl, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/bowl.json
	trades[460].setIn(Items::minecraft::planks, {3.0, 0.0});
	trades[460].setOut(Items::minecraft::bowl, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/bread.json
	trades[461].setIn(Items::minecraft::wheat, {3.0, 0.0});
	trades[461].setOut(Items::minecraft::bread, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/brew_awkward_blaze_powder.json
	trades[462].setIn(Items::minecraft::potion_type, {1.0, 0.0});
	trades[462].setIn(Items::minecraft::blaze_powder, {1.0, 0.0});
	trades[462].setOut(Items::minecraft::potion_type, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/brew_awkward_breeze_rod.json
	trades[463].setIn(Items::minecraft::potion_type, {1.0, 0.0});
	trades[463].setIn(Items::minecraft::breeze_rod, {1.0, 0.0});
	trades[463].setOut(Items::minecraft::potion_type, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/brew_awkward_fermented_spider_eye.json
	trades[464].setIn(Items::minecraft::potion_type, {1.0, 0.0});
	trades[464].setIn(Items::minecraft::fermented_spider_eye, {1.0, 0.0});
	trades[464].setOut(Items::minecraft::potion_type, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/brew_awkward_ghast_tear.json
	trades[465].setIn(Items::minecraft::potion_type, {1.0, 0.0});
	trades[465].setIn(Items::minecraft::ghast_tear, {1.0, 0.0});
	trades[465].setOut(Items::minecraft::potion_type, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/brew_awkward_golden_carrot.json
	trades[466].setIn(Items::minecraft::potion_type, {1.0, 0.0});
	trades[466].setIn(Items::minecraft::golden_carrot, {1.0, 0.0});
	trades[466].setOut(Items::minecraft::potion_type, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/brew_awkward_magma_cream.json
	trades[467].setIn(Items::minecraft::potion_type, {1.0, 0.0});
	trades[467].setIn(Items::minecraft::magma_cream, {1.0, 0.0});
	trades[467].setOut(Items::minecraft::potion_type, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/brew_awkward_phantom_membrane.json
	trades[468].setIn(Items::minecraft::potion_type, {1.0, 0.0});
	trades[468].setIn(Items::minecraft::phantom_membrane, {1.0, 0.0});
	trades[468].setOut(Items::minecraft::potion_type, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/brew_awkward_puffer_fish.json
	trades[469].setIn(Items::minecraft::potion_type, {1.0, 0.0});
	trades[469].setIn(Items::minecraft::pufferfish, {1.0, 0.0});
	trades[469].setOut(Items::minecraft::potion_type, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/brew_awkward_rabbit_foot.json
	trades[470].setIn(Items::minecraft::potion_type, {1.0, 0.0});
	trades[470].setIn(Items::minecraft::rabbit_foot, {1.0, 0.0});
	trades[470].setOut(Items::minecraft::potion_type, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/brew_awkward_slime_block.json
	trades[471].setIn(Items::minecraft::potion_type, {1.0, 0.0});
	trades[471].setIn(Items::minecraft::slime, {1.0, 0.0});
	trades[471].setOut(Items::minecraft::potion_type, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/brew_awkward_speckled_melon.json
	trades[472].setIn(Items::minecraft::potion_type, {1.0, 0.0});
	trades[472].setIn(Items::minecraft::speckled_melon, {1.0, 0.0});
	trades[472].setOut(Items::minecraft::potion_type, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/brew_awkward_spider_eye.json
	trades[473].setIn(Items::minecraft::potion_type, {1.0, 0.0});
	trades[473].setIn(Items::minecraft::spider_eye, {1.0, 0.0});
	trades[473].setOut(Items::minecraft::potion_type, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/brew_awkward_stone.json
	trades[474].setIn(Items::minecraft::potion_type, {1.0, 0.0});
	trades[474].setIn(Items::minecraft::stone, {1.0, 0.0});
	trades[474].setOut(Items::minecraft::potion_type, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/brew_awkward_sugar.json
	trades[475].setIn(Items::minecraft::potion_type, {1.0, 0.0});
	trades[475].setIn(Items::minecraft::sugar, {1.0, 0.0});
	trades[475].setOut(Items::minecraft::potion_type, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/brew_awkward_turtle_helmet.json
	trades[476].setIn(Items::minecraft::potion_type, {1.0, 0.0});
	trades[476].setIn(Items::minecraft::turtle_helmet, {1.0, 0.0});
	trades[476].setOut(Items::minecraft::potion_type, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/brew_awkward_web.json
	trades[477].setIn(Items::minecraft::potion_type, {1.0, 0.0});
	trades[477].setIn(Items::minecraft::web, {1.0, 0.0});
	trades[477].setOut(Items::minecraft::potion_type, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/brew_fireresistance_redstone.json
	trades[478].setIn(Items::minecraft::potion_type, {1.0, 0.0});
	trades[478].setIn(Items::minecraft::redstone, {1.0, 0.0});
	trades[478].setOut(Items::minecraft::potion_type, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/brew_harming_glowstone_dust.json
	trades[479].setIn(Items::minecraft::potion_type, {1.0, 0.0});
	trades[479].setIn(Items::minecraft::glowstone_dust, {1.0, 0.0});
	trades[479].setOut(Items::minecraft::potion_type, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/brew_healing_fermented_spider_eye.json
	trades[480].setIn(Items::minecraft::potion_type, {1.0, 0.0});
	trades[480].setIn(Items::minecraft::fermented_spider_eye, {1.0, 0.0});
	trades[480].setOut(Items::minecraft::potion_type, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/brew_healing_glowstone_dust.json
	trades[481].setIn(Items::minecraft::potion_type, {1.0, 0.0});
	trades[481].setIn(Items::minecraft::glowstone_dust, {1.0, 0.0});
	trades[481].setOut(Items::minecraft::potion_type, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/brewing_stand_from_blackstone.json
	trades[482].setIn(Items::minecraft::blaze_rod, {1.0, 0.0});
	trades[482].setIn(Items::minecraft::blackstone, {3.0, 0.0});
	trades[482].setOut(Items::minecraft::brewing_stand, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/brewing_stand_from_cobbled_deepslate.json
	trades[483].setIn(Items::minecraft::blaze_rod, {1.0, 0.0});
	trades[483].setIn(Items::minecraft::cobbled_deepslate, {3.0, 0.0});
	trades[483].setOut(Items::minecraft::brewing_stand, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/brewing_stand.json
	trades[484].setIn(Items::minecraft::blaze_rod, {1.0, 0.0});
	trades[484].setIn(Items::minecraft::stone_crafting_materials, {3.0, 0.0});
	trades[484].setOut(Items::minecraft::brewing_stand, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/brew_invisibility_red_stone.json
	trades[485].setIn(Items::minecraft::potion_type, {1.0, 0.0});
	trades[485].setIn(Items::minecraft::redstone, {1.0, 0.0});
	trades[485].setOut(Items::minecraft::potion_type, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/brew_leaping_fermented_spider_eye.json
	trades[486].setIn(Items::minecraft::potion_type, {1.0, 0.0});
	trades[486].setIn(Items::minecraft::fermented_spider_eye, {1.0, 0.0});
	trades[486].setOut(Items::minecraft::potion_type, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/brew_leaping_glow_stone.json
	trades[487].setIn(Items::minecraft::potion_type, {1.0, 0.0});
	trades[487].setIn(Items::minecraft::glowstone_dust, {1.0, 0.0});
	trades[487].setOut(Items::minecraft::potion_type, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/brew_leaping_red_stone.json
	trades[488].setIn(Items::minecraft::potion_type, {1.0, 0.0});
	trades[488].setIn(Items::minecraft::redstone, {1.0, 0.0});
	trades[488].setOut(Items::minecraft::potion_type, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/brew_long_leaping_fermented_spider_eye.json
	trades[489].setIn(Items::minecraft::potion_type, {1.0, 0.0});
	trades[489].setIn(Items::minecraft::fermented_spider_eye, {1.0, 0.0});
	trades[489].setOut(Items::minecraft::potion_type, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/brew_long_mundane_fermented_spider_eye.json
	trades[490].setIn(Items::minecraft::potion_type, {1.0, 0.0});
	trades[490].setIn(Items::minecraft::fermented_spider_eye, {1.0, 0.0});
	trades[490].setOut(Items::minecraft::potion_type, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/brew_longnightvision_fermented_spider_eye.json
	trades[491].setIn(Items::minecraft::potion_type, {1.0, 0.0});
	trades[491].setIn(Items::minecraft::fermented_spider_eye, {1.0, 0.0});
	trades[491].setOut(Items::minecraft::potion_type, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/brew_long_poison_fermented_spider_eye.json
	trades[492].setIn(Items::minecraft::potion_type, {1.0, 0.0});
	trades[492].setIn(Items::minecraft::fermented_spider_eye, {1.0, 0.0});
	trades[492].setOut(Items::minecraft::potion_type, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/brew_long_strength_fermented_spider_eye.json
	trades[493].setIn(Items::minecraft::potion_type, {1.0, 0.0});
	trades[493].setIn(Items::minecraft::fermented_spider_eye, {1.0, 0.0});
	trades[493].setOut(Items::minecraft::potion_type, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/brew_longswiftness_fermented_spider_eye.json
	trades[494].setIn(Items::minecraft::potion_type, {1.0, 0.0});
	trades[494].setIn(Items::minecraft::fermented_spider_eye, {1.0, 0.0});
	trades[494].setOut(Items::minecraft::potion_type, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/brew_mundane_fermented_spider_eye.json
	trades[495].setIn(Items::minecraft::potion_type, {1.0, 0.0});
	trades[495].setIn(Items::minecraft::fermented_spider_eye, {1.0, 0.0});
	trades[495].setOut(Items::minecraft::potion_type, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/brew_nightvision_fermented_spider_eye.json
	trades[496].setIn(Items::minecraft::potion_type, {1.0, 0.0});
	trades[496].setIn(Items::minecraft::fermented_spider_eye, {1.0, 0.0});
	trades[496].setOut(Items::minecraft::potion_type, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/brew_nightvision_redstone.json
	trades[497].setIn(Items::minecraft::potion_type, {1.0, 0.0});
	trades[497].setIn(Items::minecraft::redstone, {1.0, 0.0});
	trades[497].setOut(Items::minecraft::potion_type, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/brew_poison_fermented_spider_eye.json
	trades[498].setIn(Items::minecraft::potion_type, {1.0, 0.0});
	trades[498].setIn(Items::minecraft::fermented_spider_eye, {1.0, 0.0});
	trades[498].setOut(Items::minecraft::potion_type, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/brew_poison_glowstone_dust.json
	trades[499].setIn(Items::minecraft::potion_type, {1.0, 0.0});
	trades[499].setIn(Items::minecraft::glowstone_dust, {1.0, 0.0});
	trades[499].setOut(Items::minecraft::potion_type, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/brew_poison_redstone.json
	trades[500].setIn(Items::minecraft::potion_type, {1.0, 0.0});
	trades[500].setIn(Items::minecraft::redstone, {1.0, 0.0});
	trades[500].setOut(Items::minecraft::potion_type, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/brew_potion_sulphur.json
	trades[501].setIn(Items::minecraft::potion, {1.0, 0.0});
	trades[501].setIn(Items::minecraft::gunpowder, {1.0, 0.0});
	trades[501].setOut(Items::minecraft::splash_potion, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/brew_regeneration_glowstone_dust.json
	trades[502].setIn(Items::minecraft::potion_type, {1.0, 0.0});
	trades[502].setIn(Items::minecraft::glowstone_dust, {1.0, 0.0});
	trades[502].setOut(Items::minecraft::potion_type, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/brew_regeneration_redstone.json
	trades[503].setIn(Items::minecraft::potion_type, {1.0, 0.0});
	trades[503].setIn(Items::minecraft::redstone, {1.0, 0.0});
	trades[503].setOut(Items::minecraft::potion_type, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/brew_slow_falling_redstone.json
	trades[504].setIn(Items::minecraft::potion_type, {1.0, 0.0});
	trades[504].setIn(Items::minecraft::redstone, {1.0, 0.0});
	trades[504].setOut(Items::minecraft::potion_type, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/brew_slowness_glowstone_dust.json
	trades[505].setIn(Items::minecraft::potion_type, {1.0, 0.0});
	trades[505].setIn(Items::minecraft::glowstone_dust, {1.0, 0.0});
	trades[505].setOut(Items::minecraft::potion_type, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/brew_slowness_redstone.json
	trades[506].setIn(Items::minecraft::potion_type, {1.0, 0.0});
	trades[506].setIn(Items::minecraft::redstone, {1.0, 0.0});
	trades[506].setOut(Items::minecraft::potion_type, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/brew_splash_potion_dragon_breath.json
	trades[507].setIn(Items::minecraft::splash_potion, {1.0, 0.0});
	trades[507].setIn(Items::minecraft::dragon_breath, {1.0, 0.0});
	trades[507].setOut(Items::minecraft::lingering_potion, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/brew_strength_fermented_spider_eye.json
	trades[508].setIn(Items::minecraft::potion_type, {1.0, 0.0});
	trades[508].setIn(Items::minecraft::fermented_spider_eye, {1.0, 0.0});
	trades[508].setOut(Items::minecraft::potion_type, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/brew_strength_glowstone_dust.json
	trades[509].setIn(Items::minecraft::potion_type, {1.0, 0.0});
	trades[509].setIn(Items::minecraft::glowstone_dust, {1.0, 0.0});
	trades[509].setOut(Items::minecraft::potion_type, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/brew_strength_redstone.json
	trades[510].setIn(Items::minecraft::potion_type, {1.0, 0.0});
	trades[510].setIn(Items::minecraft::redstone, {1.0, 0.0});
	trades[510].setOut(Items::minecraft::potion_type, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/brew_strong_healing_fermented_spider_eye.json
	trades[511].setIn(Items::minecraft::potion_type, {1.0, 0.0});
	trades[511].setIn(Items::minecraft::fermented_spider_eye, {1.0, 0.0});
	trades[511].setOut(Items::minecraft::potion_type, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/brew_strong_poison_fermented_spider_eye.json
	trades[512].setIn(Items::minecraft::potion_type, {1.0, 0.0});
	trades[512].setIn(Items::minecraft::fermented_spider_eye, {1.0, 0.0});
	trades[512].setOut(Items::minecraft::potion_type, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/brew_strong_strength_fermented_spider_eye.json
	trades[513].setIn(Items::minecraft::potion_type, {1.0, 0.0});
	trades[513].setIn(Items::minecraft::fermented_spider_eye, {1.0, 0.0});
	trades[513].setOut(Items::minecraft::potion_type, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/brew_swiftness_fermented_spider_eye.json
	trades[514].setIn(Items::minecraft::potion_type, {1.0, 0.0});
	trades[514].setIn(Items::minecraft::fermented_spider_eye, {1.0, 0.0});
	trades[514].setOut(Items::minecraft::potion_type, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/brew_swiftness_glowstone_dust.json
	trades[515].setIn(Items::minecraft::potion_type, {1.0, 0.0});
	trades[515].setIn(Items::minecraft::glowstone_dust, {1.0, 0.0});
	trades[515].setOut(Items::minecraft::potion_type, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/brew_swiftness_redstone.json
	trades[516].setIn(Items::minecraft::potion_type, {1.0, 0.0});
	trades[516].setIn(Items::minecraft::redstone, {1.0, 0.0});
	trades[516].setOut(Items::minecraft::potion_type, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/brew_thick_fermented_spider_eye.json
	trades[517].setIn(Items::minecraft::potion_type, {1.0, 0.0});
	trades[517].setIn(Items::minecraft::fermented_spider_eye, {1.0, 0.0});
	trades[517].setOut(Items::minecraft::potion_type, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/brew_turtle_master_glowstone_dust.json
	trades[518].setIn(Items::minecraft::potion_type, {1.0, 0.0});
	trades[518].setIn(Items::minecraft::glowstone_dust, {1.0, 0.0});
	trades[518].setOut(Items::minecraft::potion_type, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/brew_turtle_master_redstone.json
	trades[519].setIn(Items::minecraft::potion_type, {1.0, 0.0});
	trades[519].setIn(Items::minecraft::redstone, {1.0, 0.0});
	trades[519].setOut(Items::minecraft::potion_type, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/brew_water_blaze_powder.json
	trades[520].setIn(Items::minecraft::potion_type, {1.0, 0.0});
	trades[520].setIn(Items::minecraft::blaze_powder, {1.0, 0.0});
	trades[520].setOut(Items::minecraft::potion_type, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/brew_water_breathing_redstone.json
	trades[521].setIn(Items::minecraft::potion_type, {1.0, 0.0});
	trades[521].setIn(Items::minecraft::redstone, {1.0, 0.0});
	trades[521].setOut(Items::minecraft::potion_type, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/brew_water_breeze_rod.json
	trades[522].setIn(Items::minecraft::potion_type, {1.0, 0.0});
	trades[522].setIn(Items::minecraft::breeze_rod, {1.0, 0.0});
	trades[522].setOut(Items::minecraft::potion_type, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/brew_water_fermented_spider_eye.json
	trades[523].setIn(Items::minecraft::potion_type, {1.0, 0.0});
	trades[523].setIn(Items::minecraft::fermented_spider_eye, {1.0, 0.0});
	trades[523].setOut(Items::minecraft::potion_type, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/brew_water_ghast_tear.json
	trades[524].setIn(Items::minecraft::potion_type, {1.0, 0.0});
	trades[524].setIn(Items::minecraft::ghast_tear, {1.0, 0.0});
	trades[524].setOut(Items::minecraft::potion_type, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/brew_water_glow_stone.json
	trades[525].setIn(Items::minecraft::potion_type, {1.0, 0.0});
	trades[525].setIn(Items::minecraft::glowstone_dust, {1.0, 0.0});
	trades[525].setOut(Items::minecraft::potion_type, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/brew_water_magma_cream.json
	trades[526].setIn(Items::minecraft::potion_type, {1.0, 0.0});
	trades[526].setIn(Items::minecraft::magma_cream, {1.0, 0.0});
	trades[526].setOut(Items::minecraft::potion_type, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/brew_water_nether_wart.json
	trades[527].setIn(Items::minecraft::potion_type, {1.0, 0.0});
	trades[527].setIn(Items::minecraft::nether_wart, {1.0, 0.0});
	trades[527].setOut(Items::minecraft::potion_type, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/brew_water_rabbit_foot.json
	trades[528].setIn(Items::minecraft::potion_type, {1.0, 0.0});
	trades[528].setIn(Items::minecraft::rabbit_foot, {1.0, 0.0});
	trades[528].setOut(Items::minecraft::potion_type, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/brew_water_red_stone.json
	trades[529].setIn(Items::minecraft::potion_type, {1.0, 0.0});
	trades[529].setIn(Items::minecraft::redstone, {1.0, 0.0});
	trades[529].setOut(Items::minecraft::potion_type, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/brew_water_slime_block.json
	trades[530].setIn(Items::minecraft::potion_type, {1.0, 0.0});
	trades[530].setIn(Items::minecraft::slime, {1.0, 0.0});
	trades[530].setOut(Items::minecraft::potion_type, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/brew_water_speckled_melon.json
	trades[531].setIn(Items::minecraft::potion_type, {1.0, 0.0});
	trades[531].setIn(Items::minecraft::speckled_melon, {1.0, 0.0});
	trades[531].setOut(Items::minecraft::potion_type, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/brew_water_spider_eye.json
	trades[532].setIn(Items::minecraft::potion_type, {1.0, 0.0});
	trades[532].setIn(Items::minecraft::spider_eye, {1.0, 0.0});
	trades[532].setOut(Items::minecraft::potion_type, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/brew_water_stone.json
	trades[533].setIn(Items::minecraft::potion_type, {1.0, 0.0});
	trades[533].setIn(Items::minecraft::stone, {1.0, 0.0});
	trades[533].setOut(Items::minecraft::potion_type, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/brew_water_sugar.json
	trades[534].setIn(Items::minecraft::potion_type, {1.0, 0.0});
	trades[534].setIn(Items::minecraft::sugar, {1.0, 0.0});
	trades[534].setOut(Items::minecraft::potion_type, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/brew_water_web.json
	trades[535].setIn(Items::minecraft::potion_type, {1.0, 0.0});
	trades[535].setIn(Items::minecraft::web, {1.0, 0.0});
	trades[535].setOut(Items::minecraft::potion_type, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/brew_weakness_redstone.json
	trades[536].setIn(Items::minecraft::potion_type, {1.0, 0.0});
	trades[536].setIn(Items::minecraft::redstone, {1.0, 0.0});
	trades[536].setOut(Items::minecraft::potion_type, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/brick_block.json
	trades[537].setIn(Items::minecraft::brick, {4.0, 0.0});
	trades[537].setOut(Items::minecraft::brick_block, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/brick_stairs.json
	trades[538].setIn(Items::minecraft::brick_block, {6.0, 0.0});
	trades[538].setOut(Items::minecraft::brick_stairs, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/brick_wall.json
	trades[539].setIn(Items::minecraft::brick_block, {6.0, 0.0});
	trades[539].setOut(Items::minecraft::brick_wall, 6.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/brown_banner.json
	trades[540].setIn(Items::minecraft::brown_wool, {6.0, 0.0});
	trades[540].setIn(Items::minecraft::stick, {1.0, 0.0});
	trades[540].setOut(Items::minecraft::banner, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/brown_candle_from_cocoa_beans.json
	trades[541].setIn(Items::minecraft::candle, {1.0, 0.0});
	trades[541].setIn(Items::minecraft::dye, {1.0, 0.0});
	trades[541].setOut(Items::minecraft::brown_candle, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/brown_candle.json
	trades[542].setIn(Items::minecraft::candle, {1.0, 0.0});
	trades[542].setIn(Items::minecraft::dye, {1.0, 0.0});
	trades[542].setOut(Items::minecraft::brown_candle, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/brown_carpet_from_white.json
	trades[543].setIn(Items::minecraft::white_carpet, {8.0, 0.0});
	trades[543].setIn(Items::minecraft::brown_dye, {1.0, 0.0});
	trades[543].setOut(Items::minecraft::brown_carpet, 8.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/brown_carpet.json
	trades[544].setIn(Items::minecraft::brown_wool, {2.0, 0.0});
	trades[544].setOut(Items::minecraft::brown_carpet, 3.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/brown_concrete_powder_from_cocoa_beans.json
	trades[545].setIn(Items::minecraft::cocoa_beans, {1.0, 0.0});
	trades[545].setIn(Items::minecraft::sand, {4.0, 0.0});
	trades[545].setIn(Items::minecraft::gravel, {4.0, 0.0});
	trades[545].setOut(Items::minecraft::brown_concrete_powder, 8.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/brown_concrete_powder.json
	trades[546].setIn(Items::minecraft::brown_dye, {1.0, 0.0});
	trades[546].setIn(Items::minecraft::sand, {4.0, 0.0});
	trades[546].setIn(Items::minecraft::gravel, {4.0, 0.0});
	trades[546].setOut(Items::minecraft::brown_concrete_powder, 8.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/brown_dye_from_cocoa_beans.json
	trades[547].setIn(Items::minecraft::dye, {1.0, 0.0});
	trades[547].setOut(Items::minecraft::dye, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/brown_stained_glass_from_cocoa_beans.json
	trades[548].setIn(Items::minecraft::glass, {8.0, 0.0});
	trades[548].setIn(Items::minecraft::cocoa_beans, {1.0, 0.0});
	trades[548].setOut(Items::minecraft::brown_stained_glass, 8.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/brown_stained_glass.json
	trades[549].setIn(Items::minecraft::glass, {8.0, 0.0});
	trades[549].setIn(Items::minecraft::brown_dye, {1.0, 0.0});
	trades[549].setOut(Items::minecraft::brown_stained_glass, 8.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/brown_stained_glass_pane_from_pane.json
	trades[550].setIn(Items::minecraft::glass_pane, {8.0, 0.0});
	trades[550].setIn(Items::minecraft::brown_dye, {1.0, 0.0});
	trades[550].setOut(Items::minecraft::brown_stained_glass_pane, 8.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/brown_stained_glass_pane.json
	trades[551].setIn(Items::minecraft::brown_stained_glass, {6.0, 0.0});
	trades[551].setOut(Items::minecraft::brown_stained_glass_pane, 16.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/brown_stained_hardened_clay_from_cocoa_beans.json
	trades[552].setIn(Items::minecraft::hardened_clay, {8.0, 0.0});
	trades[552].setIn(Items::minecraft::cocoa_beans, {1.0, 0.0});
	trades[552].setOut(Items::minecraft::brown_terracotta, 8.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/brown_stained_hardened_clay.json
	trades[553].setIn(Items::minecraft::hardened_clay, {8.0, 0.0});
	trades[553].setIn(Items::minecraft::brown_dye, {1.0, 0.0});
	trades[553].setOut(Items::minecraft::brown_terracotta, 8.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/brush.json
	trades[554].setIn(Items::minecraft::feather, {1.0, 0.0});
	trades[554].setIn(Items::minecraft::copper_ingot, {1.0, 0.0});
	trades[554].setIn(Items::minecraft::stick, {1.0, 0.0});
	trades[554].setOut(Items::minecraft::brush, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/bucket.json
	trades[555].setIn(Items::minecraft::iron_ingot, {3.0, 0.0});
	trades[555].setOut(Items::minecraft::bucket, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/bundle.json
	trades[556].setIn(Items::minecraft::string, {1.0, 0.0});
	trades[556].setIn(Items::minecraft::leather, {1.0, 0.0});
	trades[556].setOut(Items::minecraft::bundle, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/cake.json
	trades[557].setIn(Items::minecraft::bucket, {3.0, 0.0});
	trades[557].setIn(Items::minecraft::sugar, {2.0, 0.0});
	trades[557].setIn(Items::minecraft::wheat, {3.0, 0.0});
	trades[557].setIn(Items::minecraft::egg, {1.0, 0.0});
	trades[557].setOut(Items::minecraft::cake, 1.0);
	trades[557].setOut(Items::minecraft::bucket, 3.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/calibrated_sculk_sensor.json
	trades[558].setIn(Items::minecraft::amethyst_shard, {3.0, 0.0});
	trades[558].setIn(Items::minecraft::sculk_sensor, {1.0, 0.0});
	trades[558].setOut(Items::minecraft::calibrated_sculk_sensor, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/campfire_charcoal.json
	trades[559].setIn(Items::minecraft::stick, {3.0, 0.0});
	trades[559].setIn(Items::minecraft::log, {3.0, 0.0});
	trades[559].setIn(Items::minecraft::charcoal, {1.0, 0.0});
	trades[559].setOut(Items::minecraft::campfire, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/campfire_from_charcoal_log2.json
	trades[560].setIn(Items::minecraft::stick, {3.0, 0.0});
	trades[560].setIn(Items::minecraft::log2, {3.0, 0.0});
	trades[560].setIn(Items::minecraft::charcoal, {1.0, 0.0});
	trades[560].setOut(Items::minecraft::campfire, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/campfire_from_charcoal_mangrove_log.json
	trades[561].setIn(Items::minecraft::stick, {3.0, 0.0});
	trades[561].setIn(Items::minecraft::charcoal, {1.0, 0.0});
	trades[561].setIn(Items::minecraft::mangrove_log, {3.0, 0.0});
	trades[561].setOut(Items::minecraft::campfire, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/campfire_from_charcoal_mangrove_wood.json
	trades[562].setIn(Items::minecraft::stick, {3.0, 0.0});
	trades[562].setIn(Items::minecraft::charcoal, {1.0, 0.0});
	trades[562].setIn(Items::minecraft::mangrove_wood, {3.0, 0.0});
	trades[562].setOut(Items::minecraft::campfire, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/campfire_from_charcoal_stripped_acacia_log.json
	trades[563].setIn(Items::minecraft::stick, {3.0, 0.0});
	trades[563].setIn(Items::minecraft::stripped_acacia_log, {3.0, 0.0});
	trades[563].setIn(Items::minecraft::charcoal, {1.0, 0.0});
	trades[563].setOut(Items::minecraft::campfire, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/campfire_from_charcoal_stripped_birch_log.json
	trades[564].setIn(Items::minecraft::stick, {3.0, 0.0});
	trades[564].setIn(Items::minecraft::stripped_birch_log, {3.0, 0.0});
	trades[564].setIn(Items::minecraft::charcoal, {1.0, 0.0});
	trades[564].setOut(Items::minecraft::campfire, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/campfire_from_charcoal_stripped_dark_oak_log.json
	trades[565].setIn(Items::minecraft::stick, {3.0, 0.0});
	trades[565].setIn(Items::minecraft::stripped_dark_oak_log, {3.0, 0.0});
	trades[565].setIn(Items::minecraft::charcoal, {1.0, 0.0});
	trades[565].setOut(Items::minecraft::campfire, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/campfire_from_charcoal_stripped_jungle_log.json
	trades[566].setIn(Items::minecraft::stick, {3.0, 0.0});
	trades[566].setIn(Items::minecraft::stripped_jungle_log, {3.0, 0.0});
	trades[566].setIn(Items::minecraft::charcoal, {1.0, 0.0});
	trades[566].setOut(Items::minecraft::campfire, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/campfire_from_charcoal_stripped_mangrove_log.json
	trades[567].setIn(Items::minecraft::stick, {3.0, 0.0});
	trades[567].setIn(Items::minecraft::stripped_mangrove_log, {3.0, 0.0});
	trades[567].setIn(Items::minecraft::charcoal, {1.0, 0.0});
	trades[567].setOut(Items::minecraft::campfire, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/campfire_from_charcoal_stripped_mangrove_wood.json
	trades[568].setIn(Items::minecraft::stick, {3.0, 0.0});
	trades[568].setIn(Items::minecraft::charcoal, {1.0, 0.0});
	trades[568].setIn(Items::minecraft::stripped_mangrove_wood, {3.0, 0.0});
	trades[568].setOut(Items::minecraft::campfire, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/campfire_from_charcoal_stripped_oak_log.json
	trades[569].setIn(Items::minecraft::stick, {3.0, 0.0});
	trades[569].setIn(Items::minecraft::stripped_oak_log, {3.0, 0.0});
	trades[569].setIn(Items::minecraft::charcoal, {1.0, 0.0});
	trades[569].setOut(Items::minecraft::campfire, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/campfire_from_charcoal_stripped_spruce_log.json
	trades[570].setIn(Items::minecraft::stick, {3.0, 0.0});
	trades[570].setIn(Items::minecraft::stripped_spruce_log, {3.0, 0.0});
	trades[570].setIn(Items::minecraft::charcoal, {1.0, 0.0});
	trades[570].setOut(Items::minecraft::campfire, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/campfire_from_charcoal_wood.json
	trades[571].setIn(Items::minecraft::stick, {3.0, 0.0});
	trades[571].setIn(Items::minecraft::wood, {3.0, 0.0});
	trades[571].setIn(Items::minecraft::charcoal, {1.0, 0.0});
	trades[571].setOut(Items::minecraft::campfire, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/campfire_from_crimson_stem.json
	trades[572].setIn(Items::minecraft::stick, {3.0, 0.0});
	trades[572].setIn(Items::minecraft::coal, {1.0, 0.0});
	trades[572].setIn(Items::minecraft::crimson_stem, {3.0, 0.0});
	trades[572].setOut(Items::minecraft::campfire, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/campfire_from_log2.json
	trades[573].setIn(Items::minecraft::stick, {3.0, 0.0});
	trades[573].setIn(Items::minecraft::log2, {3.0, 0.0});
	trades[573].setIn(Items::minecraft::coal, {1.0, 0.0});
	trades[573].setOut(Items::minecraft::campfire, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/campfire_from_mangrove_log.json
	trades[574].setIn(Items::minecraft::stick, {3.0, 0.0});
	trades[574].setIn(Items::minecraft::coal, {1.0, 0.0});
	trades[574].setIn(Items::minecraft::mangrove_log, {3.0, 0.0});
	trades[574].setOut(Items::minecraft::campfire, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/campfire_from_mangrove_wood.json
	trades[575].setIn(Items::minecraft::stick, {3.0, 0.0});
	trades[575].setIn(Items::minecraft::mangrove_wood, {3.0, 0.0});
	trades[575].setIn(Items::minecraft::coal, {1.0, 0.0});
	trades[575].setOut(Items::minecraft::campfire, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/campfire_from_stripped_acacia_log.json
	trades[576].setIn(Items::minecraft::stick, {3.0, 0.0});
	trades[576].setIn(Items::minecraft::stripped_acacia_log, {3.0, 0.0});
	trades[576].setIn(Items::minecraft::coal, {1.0, 0.0});
	trades[576].setOut(Items::minecraft::campfire, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/campfire_from_stripped_birch_log.json
	trades[577].setIn(Items::minecraft::stick, {3.0, 0.0});
	trades[577].setIn(Items::minecraft::stripped_birch_log, {3.0, 0.0});
	trades[577].setIn(Items::minecraft::coal, {1.0, 0.0});
	trades[577].setOut(Items::minecraft::campfire, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/campfire_from_stripped_crimson_stem.json
	trades[578].setIn(Items::minecraft::stick, {3.0, 0.0});
	trades[578].setIn(Items::minecraft::coal, {1.0, 0.0});
	trades[578].setIn(Items::minecraft::stripped_crimson_stem, {3.0, 0.0});
	trades[578].setOut(Items::minecraft::campfire, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/campfire_from_stripped_dark_oak_log.json
	trades[579].setIn(Items::minecraft::stick, {3.0, 0.0});
	trades[579].setIn(Items::minecraft::stripped_dark_oak_log, {3.0, 0.0});
	trades[579].setIn(Items::minecraft::coal, {1.0, 0.0});
	trades[579].setOut(Items::minecraft::campfire, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/campfire_from_stripped_jungle_log.json
	trades[580].setIn(Items::minecraft::stick, {3.0, 0.0});
	trades[580].setIn(Items::minecraft::stripped_jungle_log, {3.0, 0.0});
	trades[580].setIn(Items::minecraft::coal, {1.0, 0.0});
	trades[580].setOut(Items::minecraft::campfire, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/campfire_from_stripped_mangrove_log.json
	trades[581].setIn(Items::minecraft::stick, {3.0, 0.0});
	trades[581].setIn(Items::minecraft::stripped_mangrove_log, {3.0, 0.0});
	trades[581].setIn(Items::minecraft::coal, {1.0, 0.0});
	trades[581].setOut(Items::minecraft::campfire, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/campfire_from_stripped_mangrove_wood.json
	trades[582].setIn(Items::minecraft::stick, {3.0, 0.0});
	trades[582].setIn(Items::minecraft::coal, {1.0, 0.0});
	trades[582].setIn(Items::minecraft::stripped_mangrove_wood, {3.0, 0.0});
	trades[582].setOut(Items::minecraft::campfire, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/campfire_from_stripped_oak_log.json
	trades[583].setIn(Items::minecraft::stick, {3.0, 0.0});
	trades[583].setIn(Items::minecraft::stripped_oak_log, {3.0, 0.0});
	trades[583].setIn(Items::minecraft::coal, {1.0, 0.0});
	trades[583].setOut(Items::minecraft::campfire, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/campfire_from_stripped_spruce_log.json
	trades[584].setIn(Items::minecraft::stick, {3.0, 0.0});
	trades[584].setIn(Items::minecraft::stripped_spruce_log, {3.0, 0.0});
	trades[584].setIn(Items::minecraft::coal, {1.0, 0.0});
	trades[584].setOut(Items::minecraft::campfire, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/campfire_from_stripped_warped_stem.json
	trades[585].setIn(Items::minecraft::stick, {3.0, 0.0});
	trades[585].setIn(Items::minecraft::coal, {1.0, 0.0});
	trades[585].setIn(Items::minecraft::stripped_warped_stem, {3.0, 0.0});
	trades[585].setOut(Items::minecraft::campfire, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/campfire_from_warped_stem.json
	trades[586].setIn(Items::minecraft::stick, {3.0, 0.0});
	trades[586].setIn(Items::minecraft::coal, {1.0, 0.0});
	trades[586].setIn(Items::minecraft::warped_stem, {3.0, 0.0});
	trades[586].setOut(Items::minecraft::campfire, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/campfire_from_wood.json
	trades[587].setIn(Items::minecraft::stick, {3.0, 0.0});
	trades[587].setIn(Items::minecraft::wood, {3.0, 0.0});
	trades[587].setIn(Items::minecraft::coal, {1.0, 0.0});
	trades[587].setOut(Items::minecraft::campfire, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/campfire.json
	trades[588].setIn(Items::minecraft::stick, {3.0, 0.0});
	trades[588].setIn(Items::minecraft::logs, {3.0, 0.0});
	trades[588].setIn(Items::minecraft::coals, {1.0, 0.0});
	trades[588].setOut(Items::minecraft::campfire, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/candle.json
	trades[589].setIn(Items::minecraft::honeycomb, {1.0, 0.0});
	trades[589].setIn(Items::minecraft::string, {1.0, 0.0});
	trades[589].setOut(Items::minecraft::candle, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/carrot_on_a_stick.json
	trades[590].setIn(Items::minecraft::fishing_rod, {1.0, 0.0});
	trades[590].setIn(Items::minecraft::carrot, {1.0, 0.0});
	trades[590].setOut(Items::minecraft::carrotonastick, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/cartography_table_from_crimson_planks.json
	trades[591].setIn(Items::minecraft::paper, {2.0, 0.0});
	trades[591].setIn(Items::minecraft::crimson_planks, {4.0, 0.0});
	trades[591].setOut(Items::minecraft::cartography_table, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/cartography_table_from_mangrove_planks.json
	trades[592].setIn(Items::minecraft::paper, {2.0, 0.0});
	trades[592].setIn(Items::minecraft::mangrove_planks, {4.0, 0.0});
	trades[592].setOut(Items::minecraft::cartography_table, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/cartography_table_from_warped_planks.json
	trades[593].setIn(Items::minecraft::paper, {2.0, 0.0});
	trades[593].setIn(Items::minecraft::warped_planks, {4.0, 0.0});
	trades[593].setOut(Items::minecraft::cartography_table, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/cartography_table.json
	trades[594].setIn(Items::minecraft::paper, {2.0, 0.0});
	trades[594].setIn(Items::minecraft::planks, {4.0, 0.0});
	trades[594].setOut(Items::minecraft::cartography_table, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/cartography_table_locator_map.json
	trades[595].setIn(Items::minecraft::paper, {1.0, 0.0});
	trades[595].setIn(Items::minecraft::compass, {1.0, 0.0});
	trades[595].setOut(Items::minecraft::emptymap, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/cartography_table_map.json
	trades[596].setIn(Items::minecraft::paper, {1.0, 0.0});
	trades[596].setOut(Items::minecraft::emptymap, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/cauldron.json
	trades[597].setIn(Items::minecraft::iron_ingot, {7.0, 0.0});
	trades[597].setOut(Items::minecraft::cauldron, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/chain.json
	trades[598].setIn(Items::minecraft::iron_nugget, {2.0, 0.0});
	trades[598].setIn(Items::minecraft::iron_ingot, {1.0, 0.0});
	trades[598].setOut(Items::minecraft::chain, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/cherry_boat.json
	trades[599].setIn(Items::minecraft::cherry_planks, {5.0, 0.0});
	trades[599].setOut(Items::minecraft::cherry_boat, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/cherry_button.json
	trades[600].setIn(Items::minecraft::cherry_planks, {1.0, 0.0});
	trades[600].setOut(Items::minecraft::cherry_button, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/cherry_chest_boat.json
	trades[601].setIn(Items::minecraft::chest, {1.0, 0.0});
	trades[601].setIn(Items::minecraft::cherry_boat, {1.0, 0.0});
	trades[601].setOut(Items::minecraft::cherry_chest_boat, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/cherry_door.json
	trades[602].setIn(Items::minecraft::cherry_planks, {6.0, 0.0});
	trades[602].setOut(Items::minecraft::cherry_door, 3.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/cherry_fence_gate.json
	trades[603].setIn(Items::minecraft::stick, {4.0, 0.0});
	trades[603].setIn(Items::minecraft::cherry_planks, {2.0, 0.0});
	trades[603].setOut(Items::minecraft::cherry_fence_gate, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/cherry_fence.json
	trades[604].setIn(Items::minecraft::stick, {2.0, 0.0});
	trades[604].setIn(Items::minecraft::cherry_planks, {4.0, 0.0});
	trades[604].setOut(Items::minecraft::cherry_fence, 3.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/cherry_hanging_sign.json
	trades[605].setIn(Items::minecraft::stripped_cherry_log, {6.0, 0.0});
	trades[605].setIn(Items::minecraft::chain, {2.0, 0.0});
	trades[605].setOut(Items::minecraft::cherry_hanging_sign, 6.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/cherry_planks_from_log.json
	trades[606].setIn(Items::minecraft::cherry_log, {1.0, 0.0});
	trades[606].setOut(Items::minecraft::cherry_planks, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/cherry_planks_from_stripped_log.json
	trades[607].setIn(Items::minecraft::stripped_cherry_log, {1.0, 0.0});
	trades[607].setOut(Items::minecraft::cherry_planks, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/cherry_planks_from_stripped_wood.json
	trades[608].setIn(Items::minecraft::stripped_cherry_wood, {1.0, 0.0});
	trades[608].setOut(Items::minecraft::cherry_planks, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/cherry_planks_from_wood.json
	trades[609].setIn(Items::minecraft::cherry_wood, {1.0, 0.0});
	trades[609].setOut(Items::minecraft::cherry_planks, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/cherry_pressure_plate.json
	trades[610].setIn(Items::minecraft::cherry_planks, {2.0, 0.0});
	trades[610].setOut(Items::minecraft::cherry_pressure_plate, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/cherry_sign.json
	trades[611].setIn(Items::minecraft::cherry_planks, {6.0, 0.0});
	trades[611].setIn(Items::minecraft::stick, {1.0, 0.0});
	trades[611].setOut(Items::minecraft::cherry_sign, 3.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/cherry_slab.json
	trades[612].setIn(Items::minecraft::cherry_planks, {3.0, 0.0});
	trades[612].setOut(Items::minecraft::cherry_slab, 6.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/cherry_stairs.json
	trades[613].setIn(Items::minecraft::cherry_planks, {6.0, 0.0});
	trades[613].setOut(Items::minecraft::cherry_stairs, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/cherry_stripped_wood_from_stripped_log.json
	trades[614].setIn(Items::minecraft::stripped_cherry_log, {4.0, 0.0});
	trades[614].setOut(Items::minecraft::stripped_cherry_wood, 3.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/cherry_trapdoor.json
	trades[615].setIn(Items::minecraft::cherry_planks, {6.0, 0.0});
	trades[615].setOut(Items::minecraft::cherry_trapdoor, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/cherry_wood_from_log.json
	trades[616].setIn(Items::minecraft::cherry_log, {4.0, 0.0});
	trades[616].setOut(Items::minecraft::cherry_wood, 3.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/chest_boat.json
	trades[617].setIn(Items::minecraft::chest, {1.0, 0.0});
	trades[617].setIn(Items::minecraft::boat, {1.0, 0.0});
	trades[617].setOut(Items::minecraft::chest_boat, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/chest_from_crimson_planks.json
	trades[618].setIn(Items::minecraft::crimson_planks, {8.0, 0.0});
	trades[618].setOut(Items::minecraft::chest, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/chest_from_mangrove_planks.json
	trades[619].setIn(Items::minecraft::mangrove_planks, {8.0, 0.0});
	trades[619].setOut(Items::minecraft::chest, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/chest_from_warped_planks.json
	trades[620].setIn(Items::minecraft::warped_planks, {8.0, 0.0});
	trades[620].setOut(Items::minecraft::chest, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/chest.json
	trades[621].setIn(Items::minecraft::planks, {8.0, 0.0});
	trades[621].setOut(Items::minecraft::chest, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/chest_minecart.json
	trades[622].setIn(Items::minecraft::chest, {1.0, 0.0});
	trades[622].setIn(Items::minecraft::minecart, {1.0, 0.0});
	trades[622].setOut(Items::minecraft::chest_minecart, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/chiseled_bookshelf.json
	trades[623].setIn(Items::minecraft::planks, {6.0, 0.0});
	trades[623].setIn(Items::minecraft::wooden_slabs, {3.0, 0.0});
	trades[623].setOut(Items::minecraft::chiseled_bookshelf, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/chiseled_deepslate_from_cobbled_deepslate_stonecutting.json
	trades[624].setIn(Items::minecraft::cobbled_deepslate, {1.0, 0.0});
	trades[624].setOut(Items::minecraft::chiseled_deepslate, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/chiseled_deepslate.json
	trades[625].setIn(Items::minecraft::cobbled_deepslate_slab, {2.0, 0.0});
	trades[625].setOut(Items::minecraft::chiseled_deepslate, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/chiseled_nether_bricks.json
	trades[626].setIn(Items::minecraft::nether_brick_slab, {2.0, 0.0});
	trades[626].setOut(Items::minecraft::chiseled_nether_bricks, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/chiseled_polished_blackstone.json
	trades[627].setIn(Items::minecraft::polished_blackstone_slab, {2.0, 0.0});
	trades[627].setOut(Items::minecraft::chiseled_polished_blackstone, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/chiseled_resin_bricks_from_slabs.json
	trades[628].setIn(Items::minecraft::resin_brick_slab, {2.0, 0.0});
	trades[628].setOut(Items::minecraft::chiseled_resin_bricks, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/chiseled_tuff_bricks.json
	trades[629].setIn(Items::minecraft::tuff_brick_slab, {2.0, 0.0});
	trades[629].setOut(Items::minecraft::chiseled_tuff_bricks, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/chiseled_tuff.json
	trades[630].setIn(Items::minecraft::tuff_slab, {2.0, 0.0});
	trades[630].setOut(Items::minecraft::chiseled_tuff, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/clay.json
	trades[631].setIn(Items::minecraft::clay_ball, {4.0, 0.0});
	trades[631].setOut(Items::minecraft::clay, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/clock.json
	trades[632].setIn(Items::minecraft::gold_ingot, {4.0, 0.0});
	trades[632].setIn(Items::minecraft::redstone, {1.0, 0.0});
	trades[632].setOut(Items::minecraft::clock, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/coal_block.json
	trades[633].setIn(Items::minecraft::coal, {9.0, 0.0});
	trades[633].setOut(Items::minecraft::coal_block, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/coal.json
	trades[634].setIn(Items::minecraft::coal_block, {1.0, 0.0});
	trades[634].setOut(Items::minecraft::coal, 9.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/coarse_dirt.json
	trades[635].setIn(Items::minecraft::dirt, {2.0, 0.0});
	trades[635].setIn(Items::minecraft::gravel, {2.0, 0.0});
	trades[635].setOut(Items::minecraft::coarse_dirt, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/coast_armor_trim_smithing_template_duplicate.json
	trades[636].setIn(Items::minecraft::coast_armor_trim_smithing_template, {1.0, 0.0});
	trades[636].setIn(Items::minecraft::diamond, {7.0, 0.0});
	trades[636].setIn(Items::minecraft::cobblestone, {1.0, 0.0});
	trades[636].setOut(Items::minecraft::coast_armor_trim_smithing_template, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/cobbled_deepslate_slab_from_cobbled_deepslate_stonecutting.json
	trades[637].setIn(Items::minecraft::cobbled_deepslate, {1.0, 0.0});
	trades[637].setOut(Items::minecraft::cobbled_deepslate_slab, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/cobbled_deepslate_slab.json
	trades[638].setIn(Items::minecraft::cobbled_deepslate, {3.0, 0.0});
	trades[638].setOut(Items::minecraft::cobbled_deepslate_slab, 6.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/cobbled_deepslate_stairs_from_cobbled_deepslate_cutting.json
	trades[639].setIn(Items::minecraft::cobbled_deepslate, {1.0, 0.0});
	trades[639].setOut(Items::minecraft::cobbled_deepslate_stairs, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/cobbled_deepslate_stairs.json
	trades[640].setIn(Items::minecraft::cobbled_deepslate, {6.0, 0.0});
	trades[640].setOut(Items::minecraft::cobbled_deepslate_stairs, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/cobbled_deepslate_wall_from_cobbled_deepslate_stonecutting.json
	trades[641].setIn(Items::minecraft::cobbled_deepslate, {1.0, 0.0});
	trades[641].setOut(Items::minecraft::cobbled_deepslate_wall, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/cobbled_deepslate_wall.json
	trades[642].setIn(Items::minecraft::cobbled_deepslate, {6.0, 0.0});
	trades[642].setOut(Items::minecraft::cobbled_deepslate_wall, 6.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/cobblestone_stairs.json
	trades[643].setIn(Items::minecraft::cobblestone, {6.0, 0.0});
	trades[643].setOut(Items::minecraft::stone_stairs, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/cobblestone_wall.json
	trades[644].setIn(Items::minecraft::cobblestone, {6.0, 0.0});
	trades[644].setOut(Items::minecraft::cobblestone_wall, 6.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/cobweb_to_string.json
	trades[645].setIn(Items::minecraft::web, {1.0, 0.0});
	trades[645].setOut(Items::minecraft::string, 9.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/comparator.json
	trades[646].setIn(Items::minecraft::redstone_torch, {3.0, 0.0});
	trades[646].setIn(Items::minecraft::quartz, {1.0, 0.0});
	trades[646].setIn(Items::minecraft::stone, {3.0, 0.0});
	trades[646].setOut(Items::minecraft::comparator, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/compass.json
	trades[647].setIn(Items::minecraft::iron_ingot, {4.0, 0.0});
	trades[647].setIn(Items::minecraft::redstone, {1.0, 0.0});
	trades[647].setOut(Items::minecraft::compass, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/composter_from_crimson_slab.json
	trades[648].setIn(Items::minecraft::crimson_slab, {7.0, 0.0});
	trades[648].setOut(Items::minecraft::composter, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/composter_from_mangrove_slab.json
	trades[649].setIn(Items::minecraft::mangrove_slab, {7.0, 0.0});
	trades[649].setOut(Items::minecraft::composter, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/composter_from_warped_slab.json
	trades[650].setIn(Items::minecraft::warped_slab, {7.0, 0.0});
	trades[650].setOut(Items::minecraft::composter, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/composter.json
	trades[651].setIn(Items::minecraft::wooden_slabs, {7.0, 0.0});
	trades[651].setOut(Items::minecraft::composter, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/conduit.json
	trades[652].setIn(Items::minecraft::nautilus_shell, {8.0, 0.0});
	trades[652].setIn(Items::minecraft::heart_of_the_sea, {1.0, 0.0});
	trades[652].setOut(Items::minecraft::conduit, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/cookie.json
	trades[653].setIn(Items::minecraft::wheat, {2.0, 0.0});
	trades[653].setIn(Items::minecraft::dye, {1.0, 0.0});
	trades[653].setOut(Items::minecraft::cookie, 8.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/copper_block_from_ingots.json
	trades[654].setIn(Items::minecraft::copper_ingot, {9.0, 0.0});
	trades[654].setOut(Items::minecraft::copper_block, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/cracked_deepslate_bricks_furnace.json
	trades[655].setIn(Items::minecraft::deepslate_bricks, {1.0, 0.0});
	trades[655].setOut(Items::minecraft::cracked_deepslate_bricks, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/cracked_deepslate_tiles_furnace.json
	trades[656].setIn(Items::minecraft::deepslate_tiles, {1.0, 0.0});
	trades[656].setOut(Items::minecraft::cracked_deepslate_tiles, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/crafter.json
	trades[657].setIn(Items::minecraft::redstone, {2.0, 0.0});
	trades[657].setIn(Items::minecraft::iron_ingot, {5.0, 0.0});
	trades[657].setIn(Items::minecraft::dropper, {1.0, 0.0});
	trades[657].setIn(Items::minecraft::crafting_table, {1.0, 0.0});
	trades[657].setOut(Items::minecraft::crafter, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/crafting_table_chiseled_copper.json
	trades[658].setIn(Items::minecraft::cut_copper_slab, {2.0, 0.0});
	trades[658].setOut(Items::minecraft::chiseled_copper, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/crafting_table_copper_bulb.json
	trades[659].setIn(Items::minecraft::redstone, {1.0, 0.0});
	trades[659].setIn(Items::minecraft::copper_block, {3.0, 0.0});
	trades[659].setIn(Items::minecraft::blaze_rod, {1.0, 0.0});
	trades[659].setOut(Items::minecraft::copper_bulb, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/crafting_table_copper_door.json
	trades[660].setIn(Items::minecraft::copper_ingot, {6.0, 0.0});
	trades[660].setOut(Items::minecraft::copper_door, 3.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/crafting_table_copper_grate.json
	trades[661].setIn(Items::minecraft::copper_block, {4.0, 0.0});
	trades[661].setOut(Items::minecraft::copper_grate, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/crafting_table_copper_trapdoor.json
	trades[662].setIn(Items::minecraft::copper_ingot, {6.0, 0.0});
	trades[662].setOut(Items::minecraft::copper_trapdoor, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/crafting_table_cut_copper.json
	trades[663].setIn(Items::minecraft::copper_block, {4.0, 0.0});
	trades[663].setOut(Items::minecraft::cut_copper, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/crafting_table_cut_copper_slab.json
	trades[664].setIn(Items::minecraft::cut_copper, {3.0, 0.0});
	trades[664].setOut(Items::minecraft::cut_copper_slab, 6.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/crafting_table_cut_copper_stairs.json
	trades[665].setIn(Items::minecraft::cut_copper, {6.0, 0.0});
	trades[665].setOut(Items::minecraft::cut_copper_stairs, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/crafting_table_default.json
	trades[666].setIn(Items::minecraft::oak_planks, {4.0, 0.0});
	trades[666].setOut(Items::minecraft::crafting_table, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/crafting_table_exposed_chiseled_copper.json
	trades[667].setIn(Items::minecraft::exposed_cut_copper_slab, {2.0, 0.0});
	trades[667].setOut(Items::minecraft::exposed_chiseled_copper, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/crafting_table_exposed_copper_bulb.json
	trades[668].setIn(Items::minecraft::redstone, {1.0, 0.0});
	trades[668].setIn(Items::minecraft::exposed_copper, {3.0, 0.0});
	trades[668].setIn(Items::minecraft::blaze_rod, {1.0, 0.0});
	trades[668].setOut(Items::minecraft::exposed_copper_bulb, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/crafting_table_exposed_copper_grate.json
	trades[669].setIn(Items::minecraft::exposed_copper, {4.0, 0.0});
	trades[669].setOut(Items::minecraft::exposed_copper_grate, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/crafting_table_exposed_cut_copper.json
	trades[670].setIn(Items::minecraft::exposed_copper, {4.0, 0.0});
	trades[670].setOut(Items::minecraft::exposed_cut_copper, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/crafting_table_exposed_cut_copper_slab.json
	trades[671].setIn(Items::minecraft::exposed_cut_copper, {3.0, 0.0});
	trades[671].setOut(Items::minecraft::exposed_cut_copper_slab, 6.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/crafting_table_exposed_cut_copper_stairs.json
	trades[672].setIn(Items::minecraft::exposed_cut_copper, {6.0, 0.0});
	trades[672].setOut(Items::minecraft::exposed_cut_copper_stairs, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/crafting_table_from_crimson_planks.json
	trades[673].setIn(Items::minecraft::crimson_planks, {4.0, 0.0});
	trades[673].setOut(Items::minecraft::crafting_table, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/crafting_table_from_mangrove_planks.json
	trades[674].setIn(Items::minecraft::mangrove_planks, {4.0, 0.0});
	trades[674].setOut(Items::minecraft::crafting_table, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/crafting_table_from_warped_planks.json
	trades[675].setIn(Items::minecraft::warped_planks, {4.0, 0.0});
	trades[675].setOut(Items::minecraft::crafting_table, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/crafting_table.json
	trades[676].setIn(Items::minecraft::planks, {4.0, 0.0});
	trades[676].setOut(Items::minecraft::crafting_table, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/crafting_table_oxidized_chiseled_copper.json
	trades[677].setIn(Items::minecraft::oxidized_cut_copper_slab, {2.0, 0.0});
	trades[677].setOut(Items::minecraft::oxidized_chiseled_copper, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/crafting_table_oxidized_copper_bulb.json
	trades[678].setIn(Items::minecraft::redstone, {1.0, 0.0});
	trades[678].setIn(Items::minecraft::oxidized_copper, {3.0, 0.0});
	trades[678].setIn(Items::minecraft::blaze_rod, {1.0, 0.0});
	trades[678].setOut(Items::minecraft::oxidized_copper_bulb, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/crafting_table_oxidized_copper_grate.json
	trades[679].setIn(Items::minecraft::oxidized_copper, {4.0, 0.0});
	trades[679].setOut(Items::minecraft::oxidized_copper_grate, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/crafting_table_oxidized_cut_copper.json
	trades[680].setIn(Items::minecraft::oxidized_copper, {4.0, 0.0});
	trades[680].setOut(Items::minecraft::oxidized_cut_copper, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/crafting_table_oxidized_cut_copper_slab.json
	trades[681].setIn(Items::minecraft::oxidized_cut_copper, {3.0, 0.0});
	trades[681].setOut(Items::minecraft::oxidized_cut_copper_slab, 6.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/crafting_table_oxidized_cut_copper_stairs.json
	trades[682].setIn(Items::minecraft::oxidized_cut_copper, {6.0, 0.0});
	trades[682].setOut(Items::minecraft::oxidized_cut_copper_stairs, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/crafting_table_waxed_chiseled_copper.json
	trades[683].setIn(Items::minecraft::waxed_cut_copper_slab, {2.0, 0.0});
	trades[683].setOut(Items::minecraft::waxed_chiseled_copper, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/crafting_table_waxed_copper_bulb.json
	trades[684].setIn(Items::minecraft::redstone, {1.0, 0.0});
	trades[684].setIn(Items::minecraft::waxed_copper, {3.0, 0.0});
	trades[684].setIn(Items::minecraft::blaze_rod, {1.0, 0.0});
	trades[684].setOut(Items::minecraft::waxed_copper_bulb, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/crafting_table_waxed_copper_door.json
	trades[685].setIn(Items::minecraft::waxed_copper, {6.0, 0.0});
	trades[685].setOut(Items::minecraft::waxed_copper_door, 3.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/crafting_table_waxed_copper_grate.json
	trades[686].setIn(Items::minecraft::waxed_copper, {4.0, 0.0});
	trades[686].setOut(Items::minecraft::waxed_copper_grate, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/crafting_table_waxed_cut_copper.json
	trades[687].setIn(Items::minecraft::waxed_copper, {4.0, 0.0});
	trades[687].setOut(Items::minecraft::waxed_cut_copper, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/crafting_table_waxed_cut_copper_slab.json
	trades[688].setIn(Items::minecraft::waxed_cut_copper, {3.0, 0.0});
	trades[688].setOut(Items::minecraft::waxed_cut_copper_slab, 6.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/crafting_table_waxed_cut_copper_stairs.json
	trades[689].setIn(Items::minecraft::waxed_cut_copper, {6.0, 0.0});
	trades[689].setOut(Items::minecraft::waxed_cut_copper_stairs, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/crafting_table_waxed_exposed_chiseled_copper.json
	trades[690].setIn(Items::minecraft::waxed_exposed_cut_copper_slab, {2.0, 0.0});
	trades[690].setOut(Items::minecraft::waxed_exposed_chiseled_copper, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/crafting_table_waxed_exposed_copper_bulb.json
	trades[691].setIn(Items::minecraft::redstone, {1.0, 0.0});
	trades[691].setIn(Items::minecraft::waxed_exposed_copper, {3.0, 0.0});
	trades[691].setIn(Items::minecraft::blaze_rod, {1.0, 0.0});
	trades[691].setOut(Items::minecraft::waxed_exposed_copper_bulb, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/crafting_table_waxed_exposed_copper_grate.json
	trades[692].setIn(Items::minecraft::waxed_exposed_copper, {4.0, 0.0});
	trades[692].setOut(Items::minecraft::waxed_exposed_copper_grate, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/crafting_table_waxed_exposed_cut_copper.json
	trades[693].setIn(Items::minecraft::waxed_exposed_copper, {4.0, 0.0});
	trades[693].setOut(Items::minecraft::waxed_exposed_cut_copper, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/crafting_table_waxed_exposed_cut_copper_slab.json
	trades[694].setIn(Items::minecraft::waxed_exposed_cut_copper, {3.0, 0.0});
	trades[694].setOut(Items::minecraft::waxed_exposed_cut_copper_slab, 6.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/crafting_table_waxed_exposed_cut_copper_stairs.json
	trades[695].setIn(Items::minecraft::waxed_exposed_cut_copper, {6.0, 0.0});
	trades[695].setOut(Items::minecraft::waxed_exposed_cut_copper_stairs, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/crafting_table_waxed_oxidized_chiseled_copper.json
	trades[696].setIn(Items::minecraft::waxed_oxidized_cut_copper_slab, {2.0, 0.0});
	trades[696].setOut(Items::minecraft::waxed_oxidized_chiseled_copper, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/crafting_table_waxed_oxidized_copper_bulb.json
	trades[697].setIn(Items::minecraft::redstone, {1.0, 0.0});
	trades[697].setIn(Items::minecraft::waxed_oxidized_copper, {3.0, 0.0});
	trades[697].setIn(Items::minecraft::blaze_rod, {1.0, 0.0});
	trades[697].setOut(Items::minecraft::waxed_oxidized_copper_bulb, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/crafting_table_waxed_oxidized_copper_grate.json
	trades[698].setIn(Items::minecraft::waxed_oxidized_copper, {4.0, 0.0});
	trades[698].setOut(Items::minecraft::waxed_oxidized_copper_grate, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/crafting_table_waxed_oxidized_cut_copper.json
	trades[699].setIn(Items::minecraft::waxed_oxidized_copper, {4.0, 0.0});
	trades[699].setOut(Items::minecraft::waxed_oxidized_cut_copper, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/crafting_table_waxed_oxidized_cut_copper_slab.json
	trades[700].setIn(Items::minecraft::waxed_oxidized_cut_copper, {3.0, 0.0});
	trades[700].setOut(Items::minecraft::waxed_oxidized_cut_copper_slab, 6.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/crafting_table_waxed_oxidized_cut_copper_stairs.json
	trades[701].setIn(Items::minecraft::waxed_oxidized_cut_copper, {6.0, 0.0});
	trades[701].setOut(Items::minecraft::waxed_oxidized_cut_copper_stairs, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/crafting_table_waxed_weathered_chiseled_copper.json
	trades[702].setIn(Items::minecraft::waxed_weathered_cut_copper_slab, {2.0, 0.0});
	trades[702].setOut(Items::minecraft::waxed_weathered_chiseled_copper, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/crafting_table_waxed_weathered_copper_bulb.json
	trades[703].setIn(Items::minecraft::redstone, {1.0, 0.0});
	trades[703].setIn(Items::minecraft::waxed_weathered_copper, {3.0, 0.0});
	trades[703].setIn(Items::minecraft::blaze_rod, {1.0, 0.0});
	trades[703].setOut(Items::minecraft::waxed_weathered_copper_bulb, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/crafting_table_waxed_weathered_copper_grate.json
	trades[704].setIn(Items::minecraft::waxed_weathered_copper, {4.0, 0.0});
	trades[704].setOut(Items::minecraft::waxed_weathered_copper_grate, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/crafting_table_waxed_weathered_cut_copper.json
	trades[705].setIn(Items::minecraft::waxed_weathered_copper, {4.0, 0.0});
	trades[705].setOut(Items::minecraft::waxed_weathered_cut_copper, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/crafting_table_waxed_weathered_cut_copper_slab.json
	trades[706].setIn(Items::minecraft::waxed_weathered_cut_copper, {3.0, 0.0});
	trades[706].setOut(Items::minecraft::waxed_weathered_cut_copper_slab, 6.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/crafting_table_waxed_weathered_cut_copper_stairs.json
	trades[707].setIn(Items::minecraft::waxed_weathered_cut_copper, {6.0, 0.0});
	trades[707].setOut(Items::minecraft::waxed_weathered_cut_copper_stairs, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/crafting_table_weathered_chiseled_copper.json
	trades[708].setIn(Items::minecraft::weathered_cut_copper_slab, {2.0, 0.0});
	trades[708].setOut(Items::minecraft::weathered_chiseled_copper, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/crafting_table_weathered_copper_bulb.json
	trades[709].setIn(Items::minecraft::redstone, {1.0, 0.0});
	trades[709].setIn(Items::minecraft::weathered_copper, {3.0, 0.0});
	trades[709].setIn(Items::minecraft::blaze_rod, {1.0, 0.0});
	trades[709].setOut(Items::minecraft::weathered_copper_bulb, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/crafting_table_weathered_copper_grate.json
	trades[710].setIn(Items::minecraft::weathered_copper, {4.0, 0.0});
	trades[710].setOut(Items::minecraft::weathered_copper_grate, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/crafting_table_weathered_cut_copper.json
	trades[711].setIn(Items::minecraft::weathered_copper, {4.0, 0.0});
	trades[711].setOut(Items::minecraft::weathered_cut_copper, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/crafting_table_weathered_cut_copper_slab.json
	trades[712].setIn(Items::minecraft::weathered_cut_copper, {3.0, 0.0});
	trades[712].setOut(Items::minecraft::weathered_cut_copper_slab, 6.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/crafting_table_weathered_cut_copper_stairs.json
	trades[713].setIn(Items::minecraft::weathered_cut_copper, {6.0, 0.0});
	trades[713].setOut(Items::minecraft::weathered_cut_copper_stairs, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/creaking_heart.json
	trades[714].setIn(Items::minecraft::pale_oak_log, {2.0, 0.0});
	trades[714].setIn(Items::minecraft::resin_block, {1.0, 0.0});
	trades[714].setOut(Items::minecraft::creaking_heart, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/crimson_button.json
	trades[715].setIn(Items::minecraft::crimson_planks, {1.0, 0.0});
	trades[715].setOut(Items::minecraft::crimson_button, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/crimson_door.json
	trades[716].setIn(Items::minecraft::crimson_planks, {6.0, 0.0});
	trades[716].setOut(Items::minecraft::crimson_door, 3.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/crimson_fence_gate.json
	trades[717].setIn(Items::minecraft::stick, {4.0, 0.0});
	trades[717].setIn(Items::minecraft::crimson_planks, {2.0, 0.0});
	trades[717].setOut(Items::minecraft::crimson_fence_gate, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/crimson_fence.json
	trades[718].setIn(Items::minecraft::stick, {2.0, 0.0});
	trades[718].setIn(Items::minecraft::crimson_planks, {4.0, 0.0});
	trades[718].setOut(Items::minecraft::crimson_fence, 3.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/crimson_hanging_sign.json
	trades[719].setIn(Items::minecraft::stripped_crimson_stem, {6.0, 0.0});
	trades[719].setIn(Items::minecraft::chain, {2.0, 0.0});
	trades[719].setOut(Items::minecraft::crimson_hanging_sign, 6.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/crimson_hyphae.json
	trades[720].setIn(Items::minecraft::crimson_stem, {4.0, 0.0});
	trades[720].setOut(Items::minecraft::crimson_hyphae, 3.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/crimson_hyphae_stripped.json
	trades[721].setIn(Items::minecraft::stripped_crimson_stem, {4.0, 0.0});
	trades[721].setOut(Items::minecraft::stripped_crimson_hyphae, 3.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/crimson_planks_from_crimson_hyphae.json
	trades[722].setIn(Items::minecraft::crimson_hyphae, {1.0, 0.0});
	trades[722].setOut(Items::minecraft::crimson_planks, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/crimson_planks_from_stripped_crimson_hyphae.json
	trades[723].setIn(Items::minecraft::stripped_crimson_hyphae, {1.0, 0.0});
	trades[723].setOut(Items::minecraft::crimson_planks, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/crimson_planks_from_stripped_log.json
	trades[724].setIn(Items::minecraft::stripped_crimson_stem, {1.0, 0.0});
	trades[724].setOut(Items::minecraft::crimson_planks, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/crimson_planks.json
	trades[725].setIn(Items::minecraft::crimson_stem, {1.0, 0.0});
	trades[725].setOut(Items::minecraft::crimson_planks, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/crimson_pressure_plate.json
	trades[726].setIn(Items::minecraft::crimson_planks, {2.0, 0.0});
	trades[726].setOut(Items::minecraft::crimson_pressure_plate, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/crimson_sign.json
	trades[727].setIn(Items::minecraft::crimson_planks, {6.0, 0.0});
	trades[727].setIn(Items::minecraft::stick, {1.0, 0.0});
	trades[727].setOut(Items::minecraft::crimson_sign, 3.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/crimson_slab.json
	trades[728].setIn(Items::minecraft::crimson_planks, {3.0, 0.0});
	trades[728].setOut(Items::minecraft::crimson_slab, 6.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/crimson_stairs.json
	trades[729].setIn(Items::minecraft::crimson_planks, {6.0, 0.0});
	trades[729].setOut(Items::minecraft::crimson_stairs, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/crimson_trapdoor.json
	trades[730].setIn(Items::minecraft::crimson_planks, {6.0, 0.0});
	trades[730].setOut(Items::minecraft::crimson_trapdoor, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/crossbow.json
	trades[731].setIn(Items::minecraft::stick, {3.0, 0.0});
	trades[731].setIn(Items::minecraft::string, {2.0, 0.0});
	trades[731].setIn(Items::minecraft::iron_ingot, {1.0, 0.0});
	trades[731].setIn(Items::minecraft::tripwire_hook, {1.0, 0.0});
	trades[731].setOut(Items::minecraft::crossbow, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/cyan_banner.json
	trades[732].setIn(Items::minecraft::cyan_wool, {6.0, 0.0});
	trades[732].setIn(Items::minecraft::stick, {1.0, 0.0});
	trades[732].setOut(Items::minecraft::banner, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/cyan_candle.json
	trades[733].setIn(Items::minecraft::candle, {1.0, 0.0});
	trades[733].setIn(Items::minecraft::dye, {1.0, 0.0});
	trades[733].setOut(Items::minecraft::cyan_candle, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/cyan_carpet_from_white.json
	trades[734].setIn(Items::minecraft::white_carpet, {8.0, 0.0});
	trades[734].setIn(Items::minecraft::cyan_dye, {1.0, 0.0});
	trades[734].setOut(Items::minecraft::cyan_carpet, 8.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/cyan_carpet.json
	trades[735].setIn(Items::minecraft::cyan_wool, {2.0, 0.0});
	trades[735].setOut(Items::minecraft::cyan_carpet, 3.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/cyan_concrete_powder.json
	trades[736].setIn(Items::minecraft::cyan_dye, {1.0, 0.0});
	trades[736].setIn(Items::minecraft::sand, {4.0, 0.0});
	trades[736].setIn(Items::minecraft::gravel, {4.0, 0.0});
	trades[736].setOut(Items::minecraft::cyan_concrete_powder, 8.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/cyan_dye_from_lapis_lazuli.json
	trades[737].setIn(Items::minecraft::dye, {2.0, 0.0});
	trades[737].setOut(Items::minecraft::dye, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/cyan_dye_from_pitcher_plant.json
	trades[738].setIn(Items::minecraft::pitcher_plant, {1.0, 0.0});
	trades[738].setOut(Items::minecraft::cyan_dye, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/cyan_dye.json
	trades[739].setIn(Items::minecraft::dye, {2.0, 0.0});
	trades[739].setOut(Items::minecraft::dye, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/cyan_stained_glass.json
	trades[740].setIn(Items::minecraft::glass, {8.0, 0.0});
	trades[740].setIn(Items::minecraft::cyan_dye, {1.0, 0.0});
	trades[740].setOut(Items::minecraft::cyan_stained_glass, 8.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/cyan_stained_glass_pane_from_pane.json
	trades[741].setIn(Items::minecraft::glass_pane, {8.0, 0.0});
	trades[741].setIn(Items::minecraft::cyan_dye, {1.0, 0.0});
	trades[741].setOut(Items::minecraft::cyan_stained_glass_pane, 8.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/cyan_stained_glass_pane.json
	trades[742].setIn(Items::minecraft::cyan_stained_glass, {6.0, 0.0});
	trades[742].setOut(Items::minecraft::cyan_stained_glass_pane, 16.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/cyan_stained_hardened_clay.json
	trades[743].setIn(Items::minecraft::hardened_clay, {8.0, 0.0});
	trades[743].setIn(Items::minecraft::cyan_dye, {1.0, 0.0});
	trades[743].setOut(Items::minecraft::cyan_terracotta, 8.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/dark_oak_boat.json
	trades[744].setIn(Items::minecraft::dark_oak_planks, {5.0, 0.0});
	trades[744].setOut(Items::minecraft::dark_oak_boat, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/dark_oak_chest_boat.json
	trades[745].setIn(Items::minecraft::chest, {1.0, 0.0});
	trades[745].setIn(Items::minecraft::boat, {1.0, 0.0});
	trades[745].setOut(Items::minecraft::chest_boat, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/dark_oak_door.json
	trades[746].setIn(Items::minecraft::dark_oak_planks, {6.0, 0.0});
	trades[746].setOut(Items::minecraft::dark_oak_door, 3.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/dark_oak_fence_gate.json
	trades[747].setIn(Items::minecraft::stick, {4.0, 0.0});
	trades[747].setIn(Items::minecraft::dark_oak_planks, {2.0, 0.0});
	trades[747].setOut(Items::minecraft::dark_oak_fence_gate, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/dark_oak_fence.json
	trades[748].setIn(Items::minecraft::stick, {2.0, 0.0});
	trades[748].setIn(Items::minecraft::dark_oak_planks, {4.0, 0.0});
	trades[748].setOut(Items::minecraft::dark_oak_fence, 3.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/dark_oak_hanging_sign.json
	trades[749].setIn(Items::minecraft::stripped_dark_oak_log, {6.0, 0.0});
	trades[749].setIn(Items::minecraft::chain, {2.0, 0.0});
	trades[749].setOut(Items::minecraft::dark_oak_hanging_sign, 6.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/dark_oak_planks_from_stripped.json
	trades[750].setIn(Items::minecraft::stripped_dark_oak_log, {1.0, 0.0});
	trades[750].setOut(Items::minecraft::dark_oak_planks, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/dark_oak_planks_from_stripped_wood.json
	trades[751].setIn(Items::minecraft::stripped_dark_oak_wood, {1.0, 0.0});
	trades[751].setOut(Items::minecraft::dark_oak_planks, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/dark_oak_planks_from_wood.json
	trades[752].setIn(Items::minecraft::dark_oak_wood, {1.0, 0.0});
	trades[752].setOut(Items::minecraft::dark_oak_planks, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/dark_oak_planks.json
	trades[753].setIn(Items::minecraft::dark_oak_log, {1.0, 0.0});
	trades[753].setOut(Items::minecraft::dark_oak_planks, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/dark_oak_stairs.json
	trades[754].setIn(Items::minecraft::dark_oak_planks, {6.0, 0.0});
	trades[754].setOut(Items::minecraft::dark_oak_stairs, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/dark_oak_wooden_slab.json
	trades[755].setIn(Items::minecraft::dark_oak_planks, {3.0, 0.0});
	trades[755].setOut(Items::minecraft::dark_oak_slab, 6.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/dark_oak_wood.json
	trades[756].setIn(Items::minecraft::dark_oak_log, {4.0, 0.0});
	trades[756].setOut(Items::minecraft::dark_oak_wood, 3.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/dark_oak_wood_stripped.json
	trades[757].setIn(Items::minecraft::stripped_dark_oak_log, {4.0, 0.0});
	trades[757].setOut(Items::minecraft::stripped_dark_oak_wood, 3.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/dark_prismarine_from_ink_sac.json
	trades[758].setIn(Items::minecraft::prismarine_shard, {8.0, 0.0});
	trades[758].setIn(Items::minecraft::ink_sac, {1.0, 0.0});
	trades[758].setOut(Items::minecraft::dark_prismarine, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/dark_prismarine.json
	trades[759].setIn(Items::minecraft::prismarine_shard, {8.0, 0.0});
	trades[759].setIn(Items::minecraft::black_dye, {1.0, 0.0});
	trades[759].setOut(Items::minecraft::dark_prismarine, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/daylight_detector_from_crimson_slab.json
	trades[760].setIn(Items::minecraft::glass, {3.0, 0.0});
	trades[760].setIn(Items::minecraft::quartz, {3.0, 0.0});
	trades[760].setIn(Items::minecraft::crimson_slab, {3.0, 0.0});
	trades[760].setOut(Items::minecraft::daylight_detector, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/daylight_detector_from_mangrove_slab.json
	trades[761].setIn(Items::minecraft::glass, {3.0, 0.0});
	trades[761].setIn(Items::minecraft::quartz, {3.0, 0.0});
	trades[761].setIn(Items::minecraft::mangrove_slab, {3.0, 0.0});
	trades[761].setOut(Items::minecraft::daylight_detector, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/daylight_detector_from_warped_slab.json
	trades[762].setIn(Items::minecraft::glass, {3.0, 0.0});
	trades[762].setIn(Items::minecraft::quartz, {3.0, 0.0});
	trades[762].setIn(Items::minecraft::warped_slab, {3.0, 0.0});
	trades[762].setOut(Items::minecraft::daylight_detector, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/daylight_detector.json
	trades[763].setIn(Items::minecraft::glass, {3.0, 0.0});
	trades[763].setIn(Items::minecraft::quartz, {3.0, 0.0});
	trades[763].setIn(Items::minecraft::wooden_slabs, {3.0, 0.0});
	trades[763].setOut(Items::minecraft::daylight_detector, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/deepslate_bricks_from_cobbled_deepslate_stonecutting.json
	trades[764].setIn(Items::minecraft::cobbled_deepslate, {1.0, 0.0});
	trades[764].setOut(Items::minecraft::deepslate_bricks, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/deepslate_bricks_from_polished_deepslate_stonecutting.json
	trades[765].setIn(Items::minecraft::polished_deepslate, {1.0, 0.0});
	trades[765].setOut(Items::minecraft::deepslate_bricks, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/deepslate_bricks.json
	trades[766].setIn(Items::minecraft::polished_deepslate, {4.0, 0.0});
	trades[766].setOut(Items::minecraft::deepslate_bricks, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/deepslate_brick_slab_from_cobbled_deepslate_stonecutting.json
	trades[767].setIn(Items::minecraft::cobbled_deepslate, {1.0, 0.0});
	trades[767].setOut(Items::minecraft::deepslate_brick_slab, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/deepslate_brick_slab_from_deepslate_bricks_stonecutting.json
	trades[768].setIn(Items::minecraft::deepslate_bricks, {1.0, 0.0});
	trades[768].setOut(Items::minecraft::deepslate_brick_slab, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/deepslate_brick_slab_from_polished_deepslate_stonecutting.json
	trades[769].setIn(Items::minecraft::polished_deepslate, {1.0, 0.0});
	trades[769].setOut(Items::minecraft::deepslate_brick_slab, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/deepslate_brick_slab.json
	trades[770].setIn(Items::minecraft::deepslate_bricks, {3.0, 0.0});
	trades[770].setOut(Items::minecraft::deepslate_brick_slab, 6.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/deepslate_brick_stairs_from_cobbled_deepslate_stonecutting.json
	trades[771].setIn(Items::minecraft::cobbled_deepslate, {1.0, 0.0});
	trades[771].setOut(Items::minecraft::deepslate_brick_stairs, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/deepslate_brick_stairs_from_deepslate_bricks_stonecutting.json
	trades[772].setIn(Items::minecraft::deepslate_bricks, {1.0, 0.0});
	trades[772].setOut(Items::minecraft::deepslate_brick_stairs, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/deepslate_brick_stairs_from_polished_deepslate_stonecut.json
	trades[773].setIn(Items::minecraft::polished_deepslate, {1.0, 0.0});
	trades[773].setOut(Items::minecraft::deepslate_brick_stairs, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/deepslate_brick_stairs.json
	trades[774].setIn(Items::minecraft::deepslate_bricks, {6.0, 0.0});
	trades[774].setOut(Items::minecraft::deepslate_brick_stairs, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/deepslate_brick_wall_from_cobbled_deepslate_stonecutting.json
	trades[775].setIn(Items::minecraft::cobbled_deepslate, {1.0, 0.0});
	trades[775].setOut(Items::minecraft::deepslate_brick_wall, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/deepslate_brick_wall_from_deepslate_bricks_stonecutting.json
	trades[776].setIn(Items::minecraft::deepslate_bricks, {1.0, 0.0});
	trades[776].setOut(Items::minecraft::deepslate_brick_wall, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/deepslate_brick_wall_from_polished_deepslate_stonecutting.json
	trades[777].setIn(Items::minecraft::polished_deepslate, {1.0, 0.0});
	trades[777].setOut(Items::minecraft::deepslate_brick_wall, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/deepslate_brick_wall.json
	trades[778].setIn(Items::minecraft::deepslate_bricks, {6.0, 0.0});
	trades[778].setOut(Items::minecraft::deepslate_brick_wall, 6.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/deepslate_furnace.json
	trades[779].setIn(Items::minecraft::cobbled_deepslate, {1.0, 0.0});
	trades[779].setOut(Items::minecraft::deepslate, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/deepslate_tiles_from_cobbled_deepslate_stonecutting.json
	trades[780].setIn(Items::minecraft::cobbled_deepslate, {1.0, 0.0});
	trades[780].setOut(Items::minecraft::deepslate_tiles, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/deepslate_tiles_from_deepslate_bricks_stonecutting.json
	trades[781].setIn(Items::minecraft::deepslate_bricks, {1.0, 0.0});
	trades[781].setOut(Items::minecraft::deepslate_tiles, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/deepslate_tiles_from_polished_deepslate_stonecutting.json
	trades[782].setIn(Items::minecraft::polished_deepslate, {1.0, 0.0});
	trades[782].setOut(Items::minecraft::deepslate_tiles, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/deepslate_tiles.json
	trades[783].setIn(Items::minecraft::deepslate_bricks, {4.0, 0.0});
	trades[783].setOut(Items::minecraft::deepslate_tiles, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/deepslate_tile_slab_from_cobbled_deepslate_stonecutting.json
	trades[784].setIn(Items::minecraft::cobbled_deepslate, {1.0, 0.0});
	trades[784].setOut(Items::minecraft::deepslate_tile_slab, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/deepslate_tile_slab_from_deepslate_bricks_stonecutting.json
	trades[785].setIn(Items::minecraft::deepslate_bricks, {1.0, 0.0});
	trades[785].setOut(Items::minecraft::deepslate_tile_slab, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/deepslate_tile_slab_from_deepslate_tiles_stonecutting.json
	trades[786].setIn(Items::minecraft::deepslate_tiles, {1.0, 0.0});
	trades[786].setOut(Items::minecraft::deepslate_tile_slab, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/deepslate_tile_slab_from_polished_deepslate_stonecutting.json
	trades[787].setIn(Items::minecraft::polished_deepslate, {1.0, 0.0});
	trades[787].setOut(Items::minecraft::deepslate_tile_slab, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/deepslate_tile_slab.json
	trades[788].setIn(Items::minecraft::deepslate_tiles, {3.0, 0.0});
	trades[788].setOut(Items::minecraft::deepslate_tile_slab, 6.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/deepslate_tile_stairs_from_cobbled_deepslate_stonecutting.json
	trades[789].setIn(Items::minecraft::cobbled_deepslate, {1.0, 0.0});
	trades[789].setOut(Items::minecraft::deepslate_tile_stairs, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/deepslate_tile_stairs_from_deepslate_bricks_stonecutting.json
	trades[790].setIn(Items::minecraft::deepslate_bricks, {1.0, 0.0});
	trades[790].setOut(Items::minecraft::deepslate_tile_stairs, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/deepslate_tile_stairs_from_deepslate_tiles_stonecutting.json
	trades[791].setIn(Items::minecraft::deepslate_tiles, {1.0, 0.0});
	trades[791].setOut(Items::minecraft::deepslate_tile_stairs, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/deepslate_tile_stairs_from_polished_deepslate_stonecutting.json
	trades[792].setIn(Items::minecraft::polished_deepslate, {1.0, 0.0});
	trades[792].setOut(Items::minecraft::deepslate_tile_stairs, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/deepslate_tile_stairs.json
	trades[793].setIn(Items::minecraft::deepslate_tiles, {6.0, 0.0});
	trades[793].setOut(Items::minecraft::deepslate_tile_stairs, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/deepslate_tile_wall_from_cobbled_deepslate_stonecutting.json
	trades[794].setIn(Items::minecraft::cobbled_deepslate, {1.0, 0.0});
	trades[794].setOut(Items::minecraft::deepslate_tile_wall, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/deepslate_tile_wall_from_deepslate_bricks_stonecutting.json
	trades[795].setIn(Items::minecraft::deepslate_bricks, {1.0, 0.0});
	trades[795].setOut(Items::minecraft::deepslate_tile_wall, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/deepslate_tile_wall_from_deepslate_tiles_stonecutting.json
	trades[796].setIn(Items::minecraft::deepslate_tiles, {1.0, 0.0});
	trades[796].setOut(Items::minecraft::deepslate_tile_wall, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/deepslate_tile_wall_from_polished_deepslate_stonecutting.json
	trades[797].setIn(Items::minecraft::polished_deepslate, {1.0, 0.0});
	trades[797].setOut(Items::minecraft::deepslate_tile_wall, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/deepslate_tile_wall.json
	trades[798].setIn(Items::minecraft::deepslate_tiles, {6.0, 0.0});
	trades[798].setOut(Items::minecraft::deepslate_tile_wall, 6.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/deprecated_cobweb_to_string.json
	trades[799].setIn(Items::minecraft::string, {1.0, 0.0});
	trades[799].setOut(Items::minecraft::string, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/detector_rail.json
	trades[800].setIn(Items::minecraft::redstone, {1.0, 0.0});
	trades[800].setIn(Items::minecraft::stone_pressure_plate, {1.0, 0.0});
	trades[800].setIn(Items::minecraft::iron_ingot, {6.0, 0.0});
	trades[800].setOut(Items::minecraft::detector_rail, 6.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/diamond_axe.json
	trades[801].setIn(Items::minecraft::stick, {2.0, 0.0});
	trades[801].setIn(Items::minecraft::diamond, {3.0, 0.0});
	trades[801].setOut(Items::minecraft::diamond_axe, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/diamond_block.json
	trades[802].setIn(Items::minecraft::diamond, {9.0, 0.0});
	trades[802].setOut(Items::minecraft::diamond_block, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/diamond_boots.json
	trades[803].setIn(Items::minecraft::diamond, {4.0, 0.0});
	trades[803].setOut(Items::minecraft::diamond_boots, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/diamond_chestplate.json
	trades[804].setIn(Items::minecraft::diamond, {8.0, 0.0});
	trades[804].setOut(Items::minecraft::diamond_chestplate, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/diamond_helmet.json
	trades[805].setIn(Items::minecraft::diamond, {5.0, 0.0});
	trades[805].setOut(Items::minecraft::diamond_helmet, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/diamond_hoe.json
	trades[806].setIn(Items::minecraft::stick, {2.0, 0.0});
	trades[806].setIn(Items::minecraft::diamond, {2.0, 0.0});
	trades[806].setOut(Items::minecraft::diamond_hoe, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/diamond.json
	trades[807].setIn(Items::minecraft::diamond_block, {1.0, 0.0});
	trades[807].setOut(Items::minecraft::diamond, 9.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/diamond_leggings.json
	trades[808].setIn(Items::minecraft::diamond, {7.0, 0.0});
	trades[808].setOut(Items::minecraft::diamond_leggings, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/diamond_pickaxe.json
	trades[809].setIn(Items::minecraft::stick, {2.0, 0.0});
	trades[809].setIn(Items::minecraft::diamond, {3.0, 0.0});
	trades[809].setOut(Items::minecraft::diamond_pickaxe, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/diamond_shovel.json
	trades[810].setIn(Items::minecraft::stick, {2.0, 0.0});
	trades[810].setIn(Items::minecraft::diamond, {1.0, 0.0});
	trades[810].setOut(Items::minecraft::diamond_shovel, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/diamond_sword.json
	trades[811].setIn(Items::minecraft::stick, {1.0, 0.0});
	trades[811].setIn(Items::minecraft::diamond, {2.0, 0.0});
	trades[811].setOut(Items::minecraft::diamond_sword, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/diorite.json
	trades[812].setIn(Items::minecraft::quartz, {2.0, 0.0});
	trades[812].setIn(Items::minecraft::cobblestone, {2.0, 0.0});
	trades[812].setOut(Items::minecraft::diorite, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/diorite_stairs.json
	trades[813].setIn(Items::minecraft::diorite, {6.0, 0.0});
	trades[813].setOut(Items::minecraft::diorite_stairs, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/diorite_wall.json
	trades[814].setIn(Items::minecraft::diorite, {6.0, 0.0});
	trades[814].setOut(Items::minecraft::diorite_wall, 6.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/dispenser.json
	trades[815].setIn(Items::minecraft::redstone, {1.0, 0.0});
	trades[815].setIn(Items::minecraft::cobblestone, {7.0, 0.0});
	trades[815].setIn(Items::minecraft::bow, {1.0, 0.0});
	trades[815].setOut(Items::minecraft::dispenser, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/dried_kelp_block.json
	trades[816].setIn(Items::minecraft::dried_kelp, {9.0, 0.0});
	trades[816].setOut(Items::minecraft::dried_kelp_block, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/dried_kelp.json
	trades[817].setIn(Items::minecraft::dried_kelp_block, {1.0, 0.0});
	trades[817].setOut(Items::minecraft::dried_kelp, 9.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/dripstone_block_from_pointed_dripstone.json
	trades[818].setIn(Items::minecraft::pointed_dripstone, {4.0, 0.0});
	trades[818].setOut(Items::minecraft::dripstone_block, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/dripstone_block.json
	trades[819].setIn(Items::minecraft::pointed_dripstone, {4.0, 0.0});
	trades[819].setOut(Items::minecraft::dripstone_block, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/dropper.json
	trades[820].setIn(Items::minecraft::redstone, {1.0, 0.0});
	trades[820].setIn(Items::minecraft::cobblestone, {7.0, 0.0});
	trades[820].setOut(Items::minecraft::dropper, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/dune_armor_trim_smithing_template_duplicate.json
	trades[821].setIn(Items::minecraft::dune_armor_trim_smithing_template, {1.0, 0.0});
	trades[821].setIn(Items::minecraft::diamond, {7.0, 0.0});
	trades[821].setIn(Items::minecraft::sandstone, {1.0, 0.0});
	trades[821].setOut(Items::minecraft::dune_armor_trim_smithing_template, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/emerald_block.json
	trades[822].setIn(Items::minecraft::emerald, {9.0, 0.0});
	trades[822].setOut(Items::minecraft::emerald_block, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/emerald.json
	trades[823].setIn(Items::minecraft::emerald_block, {1.0, 0.0});
	trades[823].setOut(Items::minecraft::emerald, 9.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/empty_map_to_enhanced.json
	trades[824].setIn(Items::minecraft::emptymap, {1.0, 0.0});
	trades[824].setIn(Items::minecraft::compass, {1.0, 0.0});
	trades[824].setOut(Items::minecraft::emptymap, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/enchanting_table.json
	trades[825].setIn(Items::minecraft::book, {1.0, 0.0});
	trades[825].setIn(Items::minecraft::obsidian, {4.0, 0.0});
	trades[825].setIn(Items::minecraft::diamond, {2.0, 0.0});
	trades[825].setOut(Items::minecraft::enchanting_table, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/end_bricks.json
	trades[826].setIn(Items::minecraft::end_stone, {4.0, 0.0});
	trades[826].setOut(Items::minecraft::end_bricks, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/end_brick_stairs.json
	trades[827].setIn(Items::minecraft::end_bricks, {6.0, 0.0});
	trades[827].setOut(Items::minecraft::end_brick_stairs, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/end_brick_wall.json
	trades[828].setIn(Items::minecraft::end_bricks, {6.0, 0.0});
	trades[828].setOut(Items::minecraft::end_stone_brick_wall, 6.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/end_crystal.json
	trades[829].setIn(Items::minecraft::ghast_tear, {1.0, 0.0});
	trades[829].setIn(Items::minecraft::ender_eye, {1.0, 0.0});
	trades[829].setIn(Items::minecraft::glass, {7.0, 0.0});
	trades[829].setOut(Items::minecraft::end_crystal, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/ender_chest.json
	trades[830].setIn(Items::minecraft::obsidian, {8.0, 0.0});
	trades[830].setIn(Items::minecraft::ender_eye, {1.0, 0.0});
	trades[830].setOut(Items::minecraft::ender_chest, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/ender_eye.json
	trades[831].setIn(Items::minecraft::ender_pearl, {1.0, 0.0});
	trades[831].setIn(Items::minecraft::blaze_powder, {1.0, 0.0});
	trades[831].setOut(Items::minecraft::ender_eye, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/end_rod.json
	trades[832].setIn(Items::minecraft::chorus_fruit_popped, {1.0, 0.0});
	trades[832].setIn(Items::minecraft::blaze_rod, {1.0, 0.0});
	trades[832].setOut(Items::minecraft::end_rod, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/eye_armor_trim_smithing_template_duplicate.json
	trades[833].setIn(Items::minecraft::eye_armor_trim_smithing_template, {1.0, 0.0});
	trades[833].setIn(Items::minecraft::diamond, {7.0, 0.0});
	trades[833].setIn(Items::minecraft::end_stone, {1.0, 0.0});
	trades[833].setOut(Items::minecraft::eye_armor_trim_smithing_template, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/fence_gate.json
	trades[834].setIn(Items::minecraft::stick, {4.0, 0.0});
	trades[834].setIn(Items::minecraft::oak_planks, {2.0, 0.0});
	trades[834].setOut(Items::minecraft::fence_gate, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/fence.json
	trades[835].setIn(Items::minecraft::stick, {2.0, 0.0});
	trades[835].setIn(Items::minecraft::oak_planks, {4.0, 0.0});
	trades[835].setOut(Items::minecraft::oak_fence, 3.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/fermented_spider_eye.json
	trades[836].setIn(Items::minecraft::spider_eye, {1.0, 0.0});
	trades[836].setIn(Items::minecraft::brown_mushroom, {1.0, 0.0});
	trades[836].setIn(Items::minecraft::sugar, {1.0, 0.0});
	trades[836].setOut(Items::minecraft::fermented_spider_eye, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/fire_charge_charcoal.json
	trades[837].setIn(Items::minecraft::blaze_powder, {1.0, 0.0});
	trades[837].setIn(Items::minecraft::charcoal, {1.0, 0.0});
	trades[837].setIn(Items::minecraft::gunpowder, {1.0, 0.0});
	trades[837].setOut(Items::minecraft::fire_charge, 3.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/fire_charge_coal.json
	trades[838].setIn(Items::minecraft::blaze_powder, {1.0, 0.0});
	trades[838].setIn(Items::minecraft::coal, {1.0, 0.0});
	trades[838].setIn(Items::minecraft::gunpowder, {1.0, 0.0});
	trades[838].setOut(Items::minecraft::fire_charge, 3.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/fire_charge.json
	trades[839].setIn(Items::minecraft::blaze_powder, {1.0, 0.0});
	trades[839].setIn(Items::minecraft::coals, {1.0, 0.0});
	trades[839].setIn(Items::minecraft::gunpowder, {1.0, 0.0});
	trades[839].setOut(Items::minecraft::fire_charge, 3.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/fishing_rod.json
	trades[840].setIn(Items::minecraft::stick, {3.0, 0.0});
	trades[840].setIn(Items::minecraft::string, {2.0, 0.0});
	trades[840].setOut(Items::minecraft::fishing_rod, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/fletching_table_from_crimson_planks.json
	trades[841].setIn(Items::minecraft::flint, {2.0, 0.0});
	trades[841].setIn(Items::minecraft::crimson_planks, {4.0, 0.0});
	trades[841].setOut(Items::minecraft::fletching_table, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/fletching_table_from_mangrove_planks.json
	trades[842].setIn(Items::minecraft::flint, {2.0, 0.0});
	trades[842].setIn(Items::minecraft::mangrove_planks, {4.0, 0.0});
	trades[842].setOut(Items::minecraft::fletching_table, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/fletching_table_from_warped_planks.json
	trades[843].setIn(Items::minecraft::flint, {2.0, 0.0});
	trades[843].setIn(Items::minecraft::warped_planks, {4.0, 0.0});
	trades[843].setOut(Items::minecraft::fletching_table, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/fletching_table.json
	trades[844].setIn(Items::minecraft::flint, {2.0, 0.0});
	trades[844].setIn(Items::minecraft::planks, {4.0, 0.0});
	trades[844].setOut(Items::minecraft::fletching_table, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/flint_and_steel.json
	trades[845].setIn(Items::minecraft::iron_ingot, {1.0, 0.0});
	trades[845].setIn(Items::minecraft::flint, {1.0, 0.0});
	trades[845].setOut(Items::minecraft::flint_and_steel, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/flow_armor_trim_smithing_template_duplicate.json
	trades[846].setIn(Items::minecraft::flow_armor_trim_smithing_template, {1.0, 0.0});
	trades[846].setIn(Items::minecraft::diamond, {7.0, 0.0});
	trades[846].setIn(Items::minecraft::breeze_rod, {1.0, 0.0});
	trades[846].setOut(Items::minecraft::flow_armor_trim_smithing_template, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/flower_pot.json
	trades[847].setIn(Items::minecraft::brick, {3.0, 0.0});
	trades[847].setOut(Items::minecraft::flower_pot, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_acacia_wood.json
	trades[848].setIn(Items::minecraft::wood, {1.0, 0.0});
	trades[848].setOut(Items::minecraft::coal, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_ancient_debris.json
	trades[849].setIn(Items::minecraft::ancient_debris, {1.0, 0.0});
	trades[849].setOut(Items::minecraft::netherite_scrap, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_beef.json
	trades[850].setIn(Items::minecraft::beef, {1.0, 0.0});
	trades[850].setOut(Items::minecraft::cooked_beef, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_birch_wood.json
	trades[851].setIn(Items::minecraft::wood, {1.0, 0.0});
	trades[851].setOut(Items::minecraft::coal, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_cactus.json
	trades[852].setIn(Items::minecraft::cactus, {1.0, 0.0});
	trades[852].setOut(Items::minecraft::dye, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_chainmail_boots.json
	trades[853].setIn(Items::minecraft::chainmail_boots, {1.0, 0.0});
	trades[853].setOut(Items::minecraft::iron_nugget, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_chainmail_chestplate.json
	trades[854].setIn(Items::minecraft::chainmail_chestplate, {1.0, 0.0});
	trades[854].setOut(Items::minecraft::iron_nugget, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_chainmail_helmet.json
	trades[855].setIn(Items::minecraft::chainmail_helmet, {1.0, 0.0});
	trades[855].setOut(Items::minecraft::iron_nugget, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_chainmail_leggings.json
	trades[856].setIn(Items::minecraft::chainmail_leggings, {1.0, 0.0});
	trades[856].setOut(Items::minecraft::iron_nugget, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_chicken.json
	trades[857].setIn(Items::minecraft::chicken, {1.0, 0.0});
	trades[857].setOut(Items::minecraft::cooked_chicken, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_chorus_fruit.json
	trades[858].setIn(Items::minecraft::chorus_fruit, {1.0, 0.0});
	trades[858].setOut(Items::minecraft::chorus_fruit_popped, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_clay_ball.json
	trades[859].setIn(Items::minecraft::clay_ball, {1.0, 0.0});
	trades[859].setOut(Items::minecraft::brick, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_clay.json
	trades[860].setIn(Items::minecraft::clay, {1.0, 0.0});
	trades[860].setOut(Items::minecraft::hardened_clay, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_coal_ore.json
	trades[861].setIn(Items::minecraft::coal_ore, {1.0, 0.0});
	trades[861].setOut(Items::minecraft::coal, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_cobblestone.json
	trades[862].setIn(Items::minecraft::cobblestone, {1.0, 0.0});
	trades[862].setOut(Items::minecraft::stone, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_copper.json
	trades[863].setIn(Items::minecraft::raw_copper, {1.0, 0.0});
	trades[863].setOut(Items::minecraft::copper_ingot, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_copper_ore.json
	trades[864].setIn(Items::minecraft::copper_ore, {1.0, 0.0});
	trades[864].setOut(Items::minecraft::copper_ingot, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_cracked_nether_bricks.json
	trades[865].setIn(Items::minecraft::nether_brick, {1.0, 0.0});
	trades[865].setOut(Items::minecraft::cracked_nether_bricks, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_cracked_polished_blackstone_bricks.json
	trades[866].setIn(Items::minecraft::polished_blackstone_bricks, {1.0, 0.0});
	trades[866].setOut(Items::minecraft::cracked_polished_blackstone_bricks, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_dark_oak_wood.json
	trades[867].setIn(Items::minecraft::wood, {1.0, 0.0});
	trades[867].setOut(Items::minecraft::coal, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_deepslate_coal_ore.json
	trades[868].setIn(Items::minecraft::deepslate_coal_ore, {1.0, 0.0});
	trades[868].setOut(Items::minecraft::coal, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_deepslate_copper_ore.json
	trades[869].setIn(Items::minecraft::deepslate_copper_ore, {1.0, 0.0});
	trades[869].setOut(Items::minecraft::copper_ingot, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_deepslate_diamond_ore.json
	trades[870].setIn(Items::minecraft::deepslate_diamond_ore, {1.0, 0.0});
	trades[870].setOut(Items::minecraft::diamond, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_deepslate_emerald_ore.json
	trades[871].setIn(Items::minecraft::deepslate_emerald_ore, {1.0, 0.0});
	trades[871].setOut(Items::minecraft::emerald, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_deepslate_gold_ore.json
	trades[872].setIn(Items::minecraft::deepslate_gold_ore, {1.0, 0.0});
	trades[872].setOut(Items::minecraft::gold_ingot, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_deepslate_iron_ore.json
	trades[873].setIn(Items::minecraft::deepslate_iron_ore, {1.0, 0.0});
	trades[873].setOut(Items::minecraft::iron_ingot, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_deepslate_lapis_ore.json
	trades[874].setIn(Items::minecraft::deepslate_lapis_ore, {1.0, 0.0});
	trades[874].setOut(Items::minecraft::dye, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_deepslate_redstone_ore.json
	trades[875].setIn(Items::minecraft::deepslate_redstone_ore, {1.0, 0.0});
	trades[875].setOut(Items::minecraft::redstone, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_diamond_ore.json
	trades[876].setIn(Items::minecraft::diamond_ore, {1.0, 0.0});
	trades[876].setOut(Items::minecraft::diamond, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_emerald_ore.json
	trades[877].setIn(Items::minecraft::emerald_ore, {1.0, 0.0});
	trades[877].setOut(Items::minecraft::emerald, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_fish.json
	trades[878].setIn(Items::minecraft::fish, {1.0, 0.0});
	trades[878].setOut(Items::minecraft::cooked_fish, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_from_blackstone.json
	trades[879].setIn(Items::minecraft::blackstone, {8.0, 0.0});
	trades[879].setOut(Items::minecraft::furnace, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_from_cobbled_deepslate.json
	trades[880].setIn(Items::minecraft::cobbled_deepslate, {8.0, 0.0});
	trades[880].setOut(Items::minecraft::furnace, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_golden_axe.json
	trades[881].setIn(Items::minecraft::golden_axe, {1.0, 0.0});
	trades[881].setOut(Items::minecraft::gold_nugget, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_golden_boots.json
	trades[882].setIn(Items::minecraft::golden_boots, {1.0, 0.0});
	trades[882].setOut(Items::minecraft::gold_nugget, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_golden_chestplate.json
	trades[883].setIn(Items::minecraft::golden_chestplate, {1.0, 0.0});
	trades[883].setOut(Items::minecraft::gold_nugget, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_golden_helmet.json
	trades[884].setIn(Items::minecraft::golden_helmet, {1.0, 0.0});
	trades[884].setOut(Items::minecraft::gold_nugget, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_golden_hoe.json
	trades[885].setIn(Items::minecraft::golden_hoe, {1.0, 0.0});
	trades[885].setOut(Items::minecraft::gold_nugget, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_golden_leggings.json
	trades[886].setIn(Items::minecraft::golden_leggings, {1.0, 0.0});
	trades[886].setOut(Items::minecraft::gold_nugget, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_golden_pickaxe.json
	trades[887].setIn(Items::minecraft::golden_pickaxe, {1.0, 0.0});
	trades[887].setOut(Items::minecraft::gold_nugget, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_golden_shovel.json
	trades[888].setIn(Items::minecraft::golden_shovel, {1.0, 0.0});
	trades[888].setOut(Items::minecraft::gold_nugget, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_golden_sword.json
	trades[889].setIn(Items::minecraft::golden_sword, {1.0, 0.0});
	trades[889].setOut(Items::minecraft::gold_nugget, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_gold.json
	trades[890].setIn(Items::minecraft::raw_gold, {1.0, 0.0});
	trades[890].setOut(Items::minecraft::gold_ingot, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_gold_ore.json
	trades[891].setIn(Items::minecraft::gold_ore, {1.0, 0.0});
	trades[891].setOut(Items::minecraft::gold_ingot, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_horse_armor_gold.json
	trades[892].setIn(Items::minecraft::horsearmorgold, {1.0, 0.0});
	trades[892].setOut(Items::minecraft::gold_nugget, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_horse_armor_iron.json
	trades[893].setIn(Items::minecraft::horsearmoriron, {1.0, 0.0});
	trades[893].setOut(Items::minecraft::iron_nugget, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_iron_axe.json
	trades[894].setIn(Items::minecraft::iron_axe, {1.0, 0.0});
	trades[894].setOut(Items::minecraft::iron_nugget, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_iron_boots.json
	trades[895].setIn(Items::minecraft::iron_boots, {1.0, 0.0});
	trades[895].setOut(Items::minecraft::iron_nugget, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_iron_chestplate.json
	trades[896].setIn(Items::minecraft::iron_chestplate, {1.0, 0.0});
	trades[896].setOut(Items::minecraft::iron_nugget, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_iron_helmet.json
	trades[897].setIn(Items::minecraft::iron_helmet, {1.0, 0.0});
	trades[897].setOut(Items::minecraft::iron_nugget, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_iron_hoe.json
	trades[898].setIn(Items::minecraft::iron_hoe, {1.0, 0.0});
	trades[898].setOut(Items::minecraft::iron_nugget, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_iron.json
	trades[899].setIn(Items::minecraft::raw_iron, {1.0, 0.0});
	trades[899].setOut(Items::minecraft::iron_ingot, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_iron_leggings.json
	trades[900].setIn(Items::minecraft::iron_leggings, {1.0, 0.0});
	trades[900].setOut(Items::minecraft::iron_nugget, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_iron_ore.json
	trades[901].setIn(Items::minecraft::iron_ore, {1.0, 0.0});
	trades[901].setOut(Items::minecraft::iron_ingot, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_iron_pickaxe.json
	trades[902].setIn(Items::minecraft::iron_pickaxe, {1.0, 0.0});
	trades[902].setOut(Items::minecraft::iron_nugget, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_iron_shovel.json
	trades[903].setIn(Items::minecraft::iron_shovel, {1.0, 0.0});
	trades[903].setOut(Items::minecraft::iron_nugget, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_iron_sword.json
	trades[904].setIn(Items::minecraft::iron_sword, {1.0, 0.0});
	trades[904].setOut(Items::minecraft::iron_nugget, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace.json
	trades[905].setIn(Items::minecraft::stone_crafting_materials, {8.0, 0.0});
	trades[905].setOut(Items::minecraft::furnace, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_jungle_wood.json
	trades[906].setIn(Items::minecraft::wood, {1.0, 0.0});
	trades[906].setOut(Items::minecraft::coal, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_kelp.json
	trades[907].setIn(Items::minecraft::kelp, {1.0, 0.0});
	trades[907].setOut(Items::minecraft::dried_kelp, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_lapis_ore.json
	trades[908].setIn(Items::minecraft::lapis_ore, {1.0, 0.0});
	trades[908].setOut(Items::minecraft::dye, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_log2_acacia.json
	trades[909].setIn(Items::minecraft::log2, {1.0, 0.0});
	trades[909].setOut(Items::minecraft::coal, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_log2_dark_oak.json
	trades[910].setIn(Items::minecraft::log2, {1.0, 0.0});
	trades[910].setOut(Items::minecraft::coal, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_log_birch.json
	trades[911].setIn(Items::minecraft::log, {1.0, 0.0});
	trades[911].setOut(Items::minecraft::coal, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_log.json
	trades[912].setIn(Items::minecraft::logs_that_burn, {1.0, 0.0});
	trades[912].setOut(Items::minecraft::coal, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_log_jungle.json
	trades[913].setIn(Items::minecraft::log, {1.0, 0.0});
	trades[913].setOut(Items::minecraft::coal, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_log_mangrove.json
	trades[914].setIn(Items::minecraft::mangrove_log, {1.0, 0.0});
	trades[914].setOut(Items::minecraft::coal, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_log_oak.json
	trades[915].setIn(Items::minecraft::log, {1.0, 0.0});
	trades[915].setOut(Items::minecraft::coal, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_log_spruce.json
	trades[916].setIn(Items::minecraft::log, {1.0, 0.0});
	trades[916].setOut(Items::minecraft::coal, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_mangrove_wood.json
	trades[917].setIn(Items::minecraft::mangrove_wood, {1.0, 0.0});
	trades[917].setOut(Items::minecraft::coal, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_mutton_raw.json
	trades[918].setIn(Items::minecraft::muttonRaw, {1.0, 0.0});
	trades[918].setOut(Items::minecraft::muttonCooked, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_nether_gold_ore.json
	trades[919].setIn(Items::minecraft::nether_gold_ore, {1.0, 0.0});
	trades[919].setOut(Items::minecraft::gold_ingot, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_netherrack.json
	trades[920].setIn(Items::minecraft::netherrack, {1.0, 0.0});
	trades[920].setOut(Items::minecraft::netherbrick, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_oak_wood.json
	trades[921].setIn(Items::minecraft::wood, {1.0, 0.0});
	trades[921].setOut(Items::minecraft::coal, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_porkchop.json
	trades[922].setIn(Items::minecraft::porkchop, {1.0, 0.0});
	trades[922].setOut(Items::minecraft::cooked_porkchop, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_potato.json
	trades[923].setIn(Items::minecraft::potato, {1.0, 0.0});
	trades[923].setOut(Items::minecraft::baked_potato, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_quartz_block.json
	trades[924].setIn(Items::minecraft::quartz_block, {1.0, 0.0});
	trades[924].setOut(Items::minecraft::smooth_quartz, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_quartz_ore.json
	trades[925].setIn(Items::minecraft::quartz_ore, {1.0, 0.0});
	trades[925].setOut(Items::minecraft::quartz, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_rabbit.json
	trades[926].setIn(Items::minecraft::rabbit, {1.0, 0.0});
	trades[926].setOut(Items::minecraft::cooked_rabbit, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_red_sand.json
	trades[927].setIn(Items::minecraft::red_sand, {1.0, 0.0});
	trades[927].setOut(Items::minecraft::glass, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_red_sandstone.json
	trades[928].setIn(Items::minecraft::red_sandstone, {1.0, 0.0});
	trades[928].setOut(Items::minecraft::smooth_red_sandstone, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_redstone_ore.json
	trades[929].setIn(Items::minecraft::redstone_ore, {1.0, 0.0});
	trades[929].setOut(Items::minecraft::redstone, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_resin_brick.json
	trades[930].setIn(Items::minecraft::resin_clump, {1.0, 0.0});
	trades[930].setOut(Items::minecraft::resin_brick, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_salmon.json
	trades[931].setIn(Items::minecraft::salmon, {1.0, 0.0});
	trades[931].setOut(Items::minecraft::cooked_salmon, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_sand.json
	trades[932].setIn(Items::minecraft::sand, {1.0, 0.0});
	trades[932].setOut(Items::minecraft::glass, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_sandstone.json
	trades[933].setIn(Items::minecraft::sandstone, {1.0, 0.0});
	trades[933].setOut(Items::minecraft::smooth_sandstone, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_sea_pickle.json
	trades[934].setIn(Items::minecraft::sea_pickle, {1.0, 0.0});
	trades[934].setOut(Items::minecraft::dye, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_smooth_basalt.json
	trades[935].setIn(Items::minecraft::basalt, {1.0, 0.0});
	trades[935].setOut(Items::minecraft::smooth_basalt, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_sponge.json
	trades[936].setIn(Items::minecraft::wet_sponge, {1.0, 0.0});
	trades[936].setOut(Items::minecraft::sponge, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_spruce_wood.json
	trades[937].setIn(Items::minecraft::wood, {1.0, 0.0});
	trades[937].setOut(Items::minecraft::coal, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_stained_hardened_clay0.json
	trades[938].setIn(Items::minecraft::white_terracotta, {1.0, 0.0});
	trades[938].setOut(Items::minecraft::white_glazed_terracotta, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_stained_hardened_clay10.json
	trades[939].setIn(Items::minecraft::purple_terracotta, {1.0, 0.0});
	trades[939].setOut(Items::minecraft::purple_glazed_terracotta, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_stained_hardened_clay11.json
	trades[940].setIn(Items::minecraft::blue_terracotta, {1.0, 0.0});
	trades[940].setOut(Items::minecraft::blue_glazed_terracotta, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_stained_hardened_clay12.json
	trades[941].setIn(Items::minecraft::brown_terracotta, {1.0, 0.0});
	trades[941].setOut(Items::minecraft::brown_glazed_terracotta, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_stained_hardened_clay13.json
	trades[942].setIn(Items::minecraft::green_terracotta, {1.0, 0.0});
	trades[942].setOut(Items::minecraft::green_glazed_terracotta, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_stained_hardened_clay14.json
	trades[943].setIn(Items::minecraft::red_terracotta, {1.0, 0.0});
	trades[943].setOut(Items::minecraft::red_glazed_terracotta, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_stained_hardened_clay15.json
	trades[944].setIn(Items::minecraft::black_terracotta, {1.0, 0.0});
	trades[944].setOut(Items::minecraft::black_glazed_terracotta, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_stained_hardened_clay1.json
	trades[945].setIn(Items::minecraft::orange_terracotta, {1.0, 0.0});
	trades[945].setOut(Items::minecraft::orange_glazed_terracotta, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_stained_hardened_clay2.json
	trades[946].setIn(Items::minecraft::magenta_terracotta, {1.0, 0.0});
	trades[946].setOut(Items::minecraft::magenta_glazed_terracotta, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_stained_hardened_clay3.json
	trades[947].setIn(Items::minecraft::light_blue_terracotta, {1.0, 0.0});
	trades[947].setOut(Items::minecraft::light_blue_glazed_terracotta, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_stained_hardened_clay4.json
	trades[948].setIn(Items::minecraft::yellow_terracotta, {1.0, 0.0});
	trades[948].setOut(Items::minecraft::yellow_glazed_terracotta, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_stained_hardened_clay5.json
	trades[949].setIn(Items::minecraft::lime_terracotta, {1.0, 0.0});
	trades[949].setOut(Items::minecraft::lime_glazed_terracotta, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_stained_hardened_clay6.json
	trades[950].setIn(Items::minecraft::pink_terracotta, {1.0, 0.0});
	trades[950].setOut(Items::minecraft::pink_glazed_terracotta, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_stained_hardened_clay7.json
	trades[951].setIn(Items::minecraft::gray_terracotta, {1.0, 0.0});
	trades[951].setOut(Items::minecraft::gray_glazed_terracotta, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_stained_hardened_clay8.json
	trades[952].setIn(Items::minecraft::light_gray_terracotta, {1.0, 0.0});
	trades[952].setOut(Items::minecraft::silver_glazed_terracotta, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_stained_hardened_clay9.json
	trades[953].setIn(Items::minecraft::cyan_terracotta, {1.0, 0.0});
	trades[953].setOut(Items::minecraft::cyan_glazed_terracotta, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_stone_brick.json
	trades[954].setIn(Items::minecraft::stone_bricks, {1.0, 0.0});
	trades[954].setOut(Items::minecraft::cracked_stone_bricks, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_stone.json
	trades[955].setIn(Items::minecraft::stone, {1.0, 0.0});
	trades[955].setOut(Items::minecraft::smooth_stone, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_stripped_acacia_log.json
	trades[956].setIn(Items::minecraft::stripped_acacia_log, {1.0, 0.0});
	trades[956].setOut(Items::minecraft::coal, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_stripped_acacia_wood.json
	trades[957].setIn(Items::minecraft::wood, {1.0, 0.0});
	trades[957].setOut(Items::minecraft::coal, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_stripped_birch_log.json
	trades[958].setIn(Items::minecraft::stripped_birch_log, {1.0, 0.0});
	trades[958].setOut(Items::minecraft::coal, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_stripped_birch_wood.json
	trades[959].setIn(Items::minecraft::wood, {1.0, 0.0});
	trades[959].setOut(Items::minecraft::coal, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_stripped_dark_oak_log.json
	trades[960].setIn(Items::minecraft::stripped_dark_oak_log, {1.0, 0.0});
	trades[960].setOut(Items::minecraft::coal, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_stripped_dark_oak_wood.json
	trades[961].setIn(Items::minecraft::wood, {1.0, 0.0});
	trades[961].setOut(Items::minecraft::coal, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_stripped_jungle_log.json
	trades[962].setIn(Items::minecraft::stripped_jungle_log, {1.0, 0.0});
	trades[962].setOut(Items::minecraft::coal, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_stripped_jungle_wood.json
	trades[963].setIn(Items::minecraft::wood, {1.0, 0.0});
	trades[963].setOut(Items::minecraft::coal, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_stripped_mangrove_log.json
	trades[964].setIn(Items::minecraft::stripped_mangrove_log, {1.0, 0.0});
	trades[964].setOut(Items::minecraft::coal, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_stripped_mangrove_wood.json
	trades[965].setIn(Items::minecraft::stripped_mangrove_wood, {1.0, 0.0});
	trades[965].setOut(Items::minecraft::coal, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_stripped_oak_log.json
	trades[966].setIn(Items::minecraft::stripped_oak_log, {1.0, 0.0});
	trades[966].setOut(Items::minecraft::coal, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_stripped_oak_wood.json
	trades[967].setIn(Items::minecraft::wood, {1.0, 0.0});
	trades[967].setOut(Items::minecraft::coal, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_stripped_spruce_log.json
	trades[968].setIn(Items::minecraft::stripped_spruce_log, {1.0, 0.0});
	trades[968].setOut(Items::minecraft::coal, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/furnace_stripped_spruce_wood.json
	trades[969].setIn(Items::minecraft::wood, {1.0, 0.0});
	trades[969].setOut(Items::minecraft::coal, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/glass_bottle.json
	trades[970].setIn(Items::minecraft::glass, {3.0, 0.0});
	trades[970].setOut(Items::minecraft::glass_bottle, 3.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/glass_pane.json
	trades[971].setIn(Items::minecraft::glass, {6.0, 0.0});
	trades[971].setOut(Items::minecraft::glass_pane, 16.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/glow_item_frame.json
	trades[972].setIn(Items::minecraft::frame, {1.0, 0.0});
	trades[972].setIn(Items::minecraft::glow_ink_sac, {1.0, 0.0});
	trades[972].setOut(Items::minecraft::glow_frame, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/glowstone.json
	trades[973].setIn(Items::minecraft::glowstone_dust, {4.0, 0.0});
	trades[973].setOut(Items::minecraft::glowstone, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/gold_block.json
	trades[974].setIn(Items::minecraft::gold_ingot, {9.0, 0.0});
	trades[974].setOut(Items::minecraft::gold_block, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/golden_apple.json
	trades[975].setIn(Items::minecraft::gold_ingot, {8.0, 0.0});
	trades[975].setIn(Items::minecraft::apple, {1.0, 0.0});
	trades[975].setOut(Items::minecraft::golden_apple, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/golden_axe.json
	trades[976].setIn(Items::minecraft::stick, {2.0, 0.0});
	trades[976].setIn(Items::minecraft::gold_ingot, {3.0, 0.0});
	trades[976].setOut(Items::minecraft::golden_axe, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/golden_boots.json
	trades[977].setIn(Items::minecraft::gold_ingot, {4.0, 0.0});
	trades[977].setOut(Items::minecraft::golden_boots, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/golden_carrot.json
	trades[978].setIn(Items::minecraft::gold_nugget, {8.0, 0.0});
	trades[978].setIn(Items::minecraft::carrot, {1.0, 0.0});
	trades[978].setOut(Items::minecraft::golden_carrot, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/golden_chestplate.json
	trades[979].setIn(Items::minecraft::gold_ingot, {8.0, 0.0});
	trades[979].setOut(Items::minecraft::golden_chestplate, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/golden_helmet.json
	trades[980].setIn(Items::minecraft::gold_ingot, {5.0, 0.0});
	trades[980].setOut(Items::minecraft::golden_helmet, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/golden_hoe.json
	trades[981].setIn(Items::minecraft::stick, {2.0, 0.0});
	trades[981].setIn(Items::minecraft::gold_ingot, {2.0, 0.0});
	trades[981].setOut(Items::minecraft::golden_hoe, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/golden_leggings.json
	trades[982].setIn(Items::minecraft::gold_ingot, {7.0, 0.0});
	trades[982].setOut(Items::minecraft::golden_leggings, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/golden_pickaxe.json
	trades[983].setIn(Items::minecraft::stick, {2.0, 0.0});
	trades[983].setIn(Items::minecraft::gold_ingot, {3.0, 0.0});
	trades[983].setOut(Items::minecraft::golden_pickaxe, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/golden_rail.json
	trades[984].setIn(Items::minecraft::redstone, {1.0, 0.0});
	trades[984].setIn(Items::minecraft::stick, {1.0, 0.0});
	trades[984].setIn(Items::minecraft::gold_ingot, {6.0, 0.0});
	trades[984].setOut(Items::minecraft::golden_rail, 6.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/golden_shovel.json
	trades[985].setIn(Items::minecraft::stick, {2.0, 0.0});
	trades[985].setIn(Items::minecraft::gold_ingot, {1.0, 0.0});
	trades[985].setOut(Items::minecraft::golden_shovel, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/golden_sword.json
	trades[986].setIn(Items::minecraft::stick, {1.0, 0.0});
	trades[986].setIn(Items::minecraft::gold_ingot, {2.0, 0.0});
	trades[986].setOut(Items::minecraft::golden_sword, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/gold_ingot_from_block.json
	trades[987].setIn(Items::minecraft::gold_block, {1.0, 0.0});
	trades[987].setOut(Items::minecraft::gold_ingot, 9.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/gold_ingot_from_nuggets.json
	trades[988].setIn(Items::minecraft::gold_nugget, {9.0, 0.0});
	trades[988].setOut(Items::minecraft::gold_ingot, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/gold_nugget.json
	trades[989].setIn(Items::minecraft::gold_ingot, {1.0, 0.0});
	trades[989].setOut(Items::minecraft::gold_nugget, 9.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/granite.json
	trades[990].setIn(Items::minecraft::diorite, {1.0, 0.0});
	trades[990].setIn(Items::minecraft::quartz, {1.0, 0.0});
	trades[990].setOut(Items::minecraft::granite, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/granite_stairs.json
	trades[991].setIn(Items::minecraft::granite, {6.0, 0.0});
	trades[991].setOut(Items::minecraft::granite_stairs, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/granite_wall.json
	trades[992].setIn(Items::minecraft::granite, {6.0, 0.0});
	trades[992].setOut(Items::minecraft::granite_wall, 6.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/gray_banner.json
	trades[993].setIn(Items::minecraft::gray_wool, {6.0, 0.0});
	trades[993].setIn(Items::minecraft::stick, {1.0, 0.0});
	trades[993].setOut(Items::minecraft::banner, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/gray_candle.json
	trades[994].setIn(Items::minecraft::candle, {1.0, 0.0});
	trades[994].setIn(Items::minecraft::dye, {1.0, 0.0});
	trades[994].setOut(Items::minecraft::gray_candle, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/gray_carpet_from_white.json
	trades[995].setIn(Items::minecraft::white_carpet, {8.0, 0.0});
	trades[995].setIn(Items::minecraft::gray_dye, {1.0, 0.0});
	trades[995].setOut(Items::minecraft::gray_carpet, 8.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/gray_carpet.json
	trades[996].setIn(Items::minecraft::gray_wool, {2.0, 0.0});
	trades[996].setOut(Items::minecraft::gray_carpet, 3.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/gray_concrete_powder.json
	trades[997].setIn(Items::minecraft::gray_dye, {1.0, 0.0});
	trades[997].setIn(Items::minecraft::sand, {4.0, 0.0});
	trades[997].setIn(Items::minecraft::gravel, {4.0, 0.0});
	trades[997].setOut(Items::minecraft::gray_concrete_powder, 8.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/gray_dye_from_black_bonemeal.json
	trades[998].setIn(Items::minecraft::dye, {2.0, 0.0});
	trades[998].setOut(Items::minecraft::dye, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/gray_dye_from_closed_eyeblossom.json
	trades[999].setIn(Items::minecraft::closed_eyeblossom, {1.0, 0.0});
	trades[999].setOut(Items::minecraft::gray_dye, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/gray_dye_from_ink_bonemeal.json
	trades[1000].setIn(Items::minecraft::dye, {2.0, 0.0});
	trades[1000].setOut(Items::minecraft::dye, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/gray_dye_from_ink_white.json
	trades[1001].setIn(Items::minecraft::dye, {2.0, 0.0});
	trades[1001].setOut(Items::minecraft::dye, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/gray_dye.json
	trades[1002].setIn(Items::minecraft::dye, {2.0, 0.0});
	trades[1002].setOut(Items::minecraft::dye, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/gray_stained_glass.json
	trades[1003].setIn(Items::minecraft::glass, {8.0, 0.0});
	trades[1003].setIn(Items::minecraft::gray_dye, {1.0, 0.0});
	trades[1003].setOut(Items::minecraft::gray_stained_glass, 8.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/gray_stained_glass_pane_from_pane.json
	trades[1004].setIn(Items::minecraft::glass_pane, {8.0, 0.0});
	trades[1004].setIn(Items::minecraft::gray_dye, {1.0, 0.0});
	trades[1004].setOut(Items::minecraft::gray_stained_glass_pane, 8.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/gray_stained_glass_pane.json
	trades[1005].setIn(Items::minecraft::gray_stained_glass, {6.0, 0.0});
	trades[1005].setOut(Items::minecraft::gray_stained_glass_pane, 16.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/gray_stained_hardened_clay.json
	trades[1006].setIn(Items::minecraft::hardened_clay, {8.0, 0.0});
	trades[1006].setIn(Items::minecraft::gray_dye, {1.0, 0.0});
	trades[1006].setOut(Items::minecraft::gray_terracotta, 8.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/green_banner.json
	trades[1007].setIn(Items::minecraft::green_wool, {6.0, 0.0});
	trades[1007].setIn(Items::minecraft::stick, {1.0, 0.0});
	trades[1007].setOut(Items::minecraft::banner, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/green_candle.json
	trades[1008].setIn(Items::minecraft::candle, {1.0, 0.0});
	trades[1008].setIn(Items::minecraft::dye, {1.0, 0.0});
	trades[1008].setOut(Items::minecraft::green_candle, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/green_carpet_from_white.json
	trades[1009].setIn(Items::minecraft::white_carpet, {8.0, 0.0});
	trades[1009].setIn(Items::minecraft::green_dye, {1.0, 0.0});
	trades[1009].setOut(Items::minecraft::green_carpet, 8.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/green_carpet.json
	trades[1010].setIn(Items::minecraft::green_wool, {2.0, 0.0});
	trades[1010].setOut(Items::minecraft::green_carpet, 3.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/green_concrete_powder.json
	trades[1011].setIn(Items::minecraft::green_dye, {1.0, 0.0});
	trades[1011].setIn(Items::minecraft::sand, {4.0, 0.0});
	trades[1011].setIn(Items::minecraft::gravel, {4.0, 0.0});
	trades[1011].setOut(Items::minecraft::green_concrete_powder, 8.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/green_stained_glass.json
	trades[1012].setIn(Items::minecraft::glass, {8.0, 0.0});
	trades[1012].setIn(Items::minecraft::green_dye, {1.0, 0.0});
	trades[1012].setOut(Items::minecraft::green_stained_glass, 8.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/green_stained_glass_pane_from_pane.json
	trades[1013].setIn(Items::minecraft::glass_pane, {8.0, 0.0});
	trades[1013].setIn(Items::minecraft::green_dye, {1.0, 0.0});
	trades[1013].setOut(Items::minecraft::green_stained_glass_pane, 8.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/green_stained_glass_pane.json
	trades[1014].setIn(Items::minecraft::green_stained_glass, {6.0, 0.0});
	trades[1014].setOut(Items::minecraft::green_stained_glass_pane, 16.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/green_stained_hardened_clay.json
	trades[1015].setIn(Items::minecraft::hardened_clay, {8.0, 0.0});
	trades[1015].setIn(Items::minecraft::green_dye, {1.0, 0.0});
	trades[1015].setOut(Items::minecraft::green_terracotta, 8.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/grindstone_from_crimson_planks2.json
	trades[1016].setIn(Items::minecraft::grindstone, {1.0, 0.0});
	trades[1016].setOut(Items::minecraft::grindstone, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/grindstone_from_crimson_planks3.json
	trades[1017].setIn(Items::minecraft::grindstone, {1.0, 0.0});
	trades[1017].setOut(Items::minecraft::grindstone, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/grindstone_from_crimson_planks4.json
	trades[1018].setIn(Items::minecraft::grindstone, {1.0, 0.0});
	trades[1018].setOut(Items::minecraft::grindstone, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/grindstone_from_crimson_planks.json
	trades[1019].setIn(Items::minecraft::stick, {2.0, 0.0});
	trades[1019].setIn(Items::minecraft::crimson_planks, {2.0, 0.0});
	trades[1019].setIn(Items::minecraft::normal_stone_slab, {1.0, 0.0});
	trades[1019].setOut(Items::minecraft::grindstone, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/grindstone_from_mangrove_planks2.json
	trades[1020].setIn(Items::minecraft::grindstone, {1.0, 0.0});
	trades[1020].setOut(Items::minecraft::grindstone, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/grindstone_from_mangrove_planks3.json
	trades[1021].setIn(Items::minecraft::grindstone, {1.0, 0.0});
	trades[1021].setOut(Items::minecraft::grindstone, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/grindstone_from_mangrove_planks4.json
	trades[1022].setIn(Items::minecraft::grindstone, {1.0, 0.0});
	trades[1022].setOut(Items::minecraft::grindstone, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/grindstone_from_mangrove_planks.json
	trades[1023].setIn(Items::minecraft::stick, {2.0, 0.0});
	trades[1023].setIn(Items::minecraft::mangrove_planks, {2.0, 0.0});
	trades[1023].setIn(Items::minecraft::normal_stone_slab, {1.0, 0.0});
	trades[1023].setOut(Items::minecraft::grindstone, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/grindstone_from_warped_planks2.json
	trades[1024].setIn(Items::minecraft::grindstone, {1.0, 0.0});
	trades[1024].setOut(Items::minecraft::grindstone, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/grindstone_from_warped_planks3.json
	trades[1025].setIn(Items::minecraft::grindstone, {1.0, 0.0});
	trades[1025].setOut(Items::minecraft::grindstone, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/grindstone_from_warped_planks4.json
	trades[1026].setIn(Items::minecraft::grindstone, {1.0, 0.0});
	trades[1026].setOut(Items::minecraft::grindstone, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/grindstone_from_warped_planks.json
	trades[1027].setIn(Items::minecraft::stick, {2.0, 0.0});
	trades[1027].setIn(Items::minecraft::warped_planks, {2.0, 0.0});
	trades[1027].setIn(Items::minecraft::normal_stone_slab, {1.0, 0.0});
	trades[1027].setOut(Items::minecraft::grindstone, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/grindstone.json
	trades[1028].setIn(Items::minecraft::stick, {2.0, 0.0});
	trades[1028].setIn(Items::minecraft::planks, {2.0, 0.0});
	trades[1028].setIn(Items::minecraft::normal_stone_slab, {1.0, 0.0});
	trades[1028].setOut(Items::minecraft::grindstone, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/hay_block.json
	trades[1029].setIn(Items::minecraft::wheat, {9.0, 0.0});
	trades[1029].setOut(Items::minecraft::hay_block, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/heavy_weighted_pressure_plate.json
	trades[1030].setIn(Items::minecraft::iron_ingot, {2.0, 0.0});
	trades[1030].setOut(Items::minecraft::heavy_weighted_pressure_plate, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/honey_block.json
	trades[1031].setIn(Items::minecraft::honey_bottle, {4.0, 0.0});
	trades[1031].setOut(Items::minecraft::honey_block, 1.0);
	trades[1031].setOut(Items::minecraft::glass_bottle, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/honey_bottle.json
	trades[1032].setIn(Items::minecraft::honey_block, {1.0, 0.0});
	trades[1032].setIn(Items::minecraft::glass_bottle, {4.0, 0.0});
	trades[1032].setOut(Items::minecraft::honey_bottle, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/honey_bottle_to_sugar.json
	trades[1033].setIn(Items::minecraft::honey_bottle, {1.0, 0.0});
	trades[1033].setOut(Items::minecraft::sugar, 3.0);
	trades[1033].setOut(Items::minecraft::glass_bottle, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/honeycomb_block.json
	trades[1034].setIn(Items::minecraft::honeycomb, {4.0, 0.0});
	trades[1034].setOut(Items::minecraft::honeycomb_block, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/hopper.json
	trades[1035].setIn(Items::minecraft::chest, {1.0, 0.0});
	trades[1035].setIn(Items::minecraft::iron_ingot, {5.0, 0.0});
	trades[1035].setOut(Items::minecraft::hopper, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/hopper_minecart.json
	trades[1036].setIn(Items::minecraft::hopper, {1.0, 0.0});
	trades[1036].setIn(Items::minecraft::minecart, {1.0, 0.0});
	trades[1036].setOut(Items::minecraft::hopper_minecart, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/host_armor_trim_smithing_template_duplicate.json
	trades[1037].setIn(Items::minecraft::host_armor_trim_smithing_template, {1.0, 0.0});
	trades[1037].setIn(Items::minecraft::diamond, {7.0, 0.0});
	trades[1037].setIn(Items::minecraft::hardened_clay, {1.0, 0.0});
	trades[1037].setOut(Items::minecraft::host_armor_trim_smithing_template, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/ingots_from_copper.json
	trades[1038].setIn(Items::minecraft::copper_block, {1.0, 0.0});
	trades[1038].setOut(Items::minecraft::copper_ingot, 9.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/ingots_from_waxed_copper.json
	trades[1039].setIn(Items::minecraft::waxed_copper, {1.0, 0.0});
	trades[1039].setOut(Items::minecraft::copper_ingot, 9.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/iron_axe.json
	trades[1040].setIn(Items::minecraft::stick, {2.0, 0.0});
	trades[1040].setIn(Items::minecraft::iron_ingot, {3.0, 0.0});
	trades[1040].setOut(Items::minecraft::iron_axe, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/iron_bars.json
	trades[1041].setIn(Items::minecraft::iron_ingot, {6.0, 0.0});
	trades[1041].setOut(Items::minecraft::iron_bars, 16.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/iron_block.json
	trades[1042].setIn(Items::minecraft::iron_ingot, {9.0, 0.0});
	trades[1042].setOut(Items::minecraft::iron_block, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/iron_boots.json
	trades[1043].setIn(Items::minecraft::iron_ingot, {4.0, 0.0});
	trades[1043].setOut(Items::minecraft::iron_boots, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/iron_chestplate.json
	trades[1044].setIn(Items::minecraft::iron_ingot, {8.0, 0.0});
	trades[1044].setOut(Items::minecraft::iron_chestplate, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/iron_door.json
	trades[1045].setIn(Items::minecraft::iron_ingot, {6.0, 0.0});
	trades[1045].setOut(Items::minecraft::iron_door, 3.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/iron_helmet.json
	trades[1046].setIn(Items::minecraft::iron_ingot, {5.0, 0.0});
	trades[1046].setOut(Items::minecraft::iron_helmet, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/iron_hoe.json
	trades[1047].setIn(Items::minecraft::stick, {2.0, 0.0});
	trades[1047].setIn(Items::minecraft::iron_ingot, {2.0, 0.0});
	trades[1047].setOut(Items::minecraft::iron_hoe, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/iron_ingot_from_block.json
	trades[1048].setIn(Items::minecraft::iron_block, {1.0, 0.0});
	trades[1048].setOut(Items::minecraft::iron_ingot, 9.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/iron_ingot_from_nuggets.json
	trades[1049].setIn(Items::minecraft::iron_nugget, {9.0, 0.0});
	trades[1049].setOut(Items::minecraft::iron_ingot, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/iron_leggings.json
	trades[1050].setIn(Items::minecraft::iron_ingot, {7.0, 0.0});
	trades[1050].setOut(Items::minecraft::iron_leggings, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/iron_nugget.json
	trades[1051].setIn(Items::minecraft::iron_ingot, {1.0, 0.0});
	trades[1051].setOut(Items::minecraft::iron_nugget, 9.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/iron_pickaxe.json
	trades[1052].setIn(Items::minecraft::stick, {2.0, 0.0});
	trades[1052].setIn(Items::minecraft::iron_ingot, {3.0, 0.0});
	trades[1052].setOut(Items::minecraft::iron_pickaxe, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/iron_shovel.json
	trades[1053].setIn(Items::minecraft::stick, {2.0, 0.0});
	trades[1053].setIn(Items::minecraft::iron_ingot, {1.0, 0.0});
	trades[1053].setOut(Items::minecraft::iron_shovel, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/iron_sword.json
	trades[1054].setIn(Items::minecraft::stick, {1.0, 0.0});
	trades[1054].setIn(Items::minecraft::iron_ingot, {2.0, 0.0});
	trades[1054].setOut(Items::minecraft::iron_sword, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/iron_trapdoor.json
	trades[1055].setIn(Items::minecraft::iron_ingot, {4.0, 0.0});
	trades[1055].setOut(Items::minecraft::iron_trapdoor, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/item_frame.json
	trades[1056].setIn(Items::minecraft::stick, {8.0, 0.0});
	trades[1056].setIn(Items::minecraft::leather, {1.0, 0.0});
	trades[1056].setOut(Items::minecraft::frame, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/jukebox_from_crimson_planks.json
	trades[1057].setIn(Items::minecraft::crimson_planks, {8.0, 0.0});
	trades[1057].setIn(Items::minecraft::diamond, {1.0, 0.0});
	trades[1057].setOut(Items::minecraft::jukebox, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/jukebox_from_mangrove_planks.json
	trades[1058].setIn(Items::minecraft::mangrove_planks, {8.0, 0.0});
	trades[1058].setIn(Items::minecraft::diamond, {1.0, 0.0});
	trades[1058].setOut(Items::minecraft::jukebox, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/jukebox_from_warped_planks.json
	trades[1059].setIn(Items::minecraft::warped_planks, {8.0, 0.0});
	trades[1059].setIn(Items::minecraft::diamond, {1.0, 0.0});
	trades[1059].setOut(Items::minecraft::jukebox, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/jukebox.json
	trades[1060].setIn(Items::minecraft::planks, {8.0, 0.0});
	trades[1060].setIn(Items::minecraft::diamond, {1.0, 0.0});
	trades[1060].setOut(Items::minecraft::jukebox, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/jungle_boat.json
	trades[1061].setIn(Items::minecraft::jungle_planks, {5.0, 0.0});
	trades[1061].setOut(Items::minecraft::jungle_boat, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/jungle_chest_boat.json
	trades[1062].setIn(Items::minecraft::chest, {1.0, 0.0});
	trades[1062].setIn(Items::minecraft::boat, {1.0, 0.0});
	trades[1062].setOut(Items::minecraft::chest_boat, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/jungle_door.json
	trades[1063].setIn(Items::minecraft::jungle_planks, {6.0, 0.0});
	trades[1063].setOut(Items::minecraft::jungle_door, 3.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/jungle_fence_gate.json
	trades[1064].setIn(Items::minecraft::stick, {4.0, 0.0});
	trades[1064].setIn(Items::minecraft::jungle_planks, {2.0, 0.0});
	trades[1064].setOut(Items::minecraft::jungle_fence_gate, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/jungle_fence.json
	trades[1065].setIn(Items::minecraft::stick, {2.0, 0.0});
	trades[1065].setIn(Items::minecraft::jungle_planks, {4.0, 0.0});
	trades[1065].setOut(Items::minecraft::jungle_fence, 3.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/jungle_hanging_sign.json
	trades[1066].setIn(Items::minecraft::stripped_jungle_log, {6.0, 0.0});
	trades[1066].setIn(Items::minecraft::chain, {2.0, 0.0});
	trades[1066].setOut(Items::minecraft::jungle_hanging_sign, 6.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/jungle_planks_from_stripped.json
	trades[1067].setIn(Items::minecraft::stripped_jungle_log, {1.0, 0.0});
	trades[1067].setOut(Items::minecraft::jungle_planks, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/jungle_planks_from_stripped_wood.json
	trades[1068].setIn(Items::minecraft::stripped_jungle_wood, {1.0, 0.0});
	trades[1068].setOut(Items::minecraft::jungle_planks, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/jungle_planks_from_wood.json
	trades[1069].setIn(Items::minecraft::jungle_wood, {1.0, 0.0});
	trades[1069].setOut(Items::minecraft::jungle_planks, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/jungle_planks.json
	trades[1070].setIn(Items::minecraft::jungle_log, {1.0, 0.0});
	trades[1070].setOut(Items::minecraft::jungle_planks, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/jungle_stairs.json
	trades[1071].setIn(Items::minecraft::jungle_planks, {6.0, 0.0});
	trades[1071].setOut(Items::minecraft::jungle_stairs, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/jungle_wooden_slab.json
	trades[1072].setIn(Items::minecraft::jungle_planks, {3.0, 0.0});
	trades[1072].setOut(Items::minecraft::jungle_slab, 6.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/jungle_wood.json
	trades[1073].setIn(Items::minecraft::jungle_log, {4.0, 0.0});
	trades[1073].setOut(Items::minecraft::jungle_wood, 3.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/jungle_wood_stripped.json
	trades[1074].setIn(Items::minecraft::stripped_jungle_log, {4.0, 0.0});
	trades[1074].setOut(Items::minecraft::stripped_jungle_wood, 3.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/ladder.json
	trades[1075].setIn(Items::minecraft::stick, {7.0, 0.0});
	trades[1075].setOut(Items::minecraft::ladder, 3.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/lantern.json
	trades[1076].setIn(Items::minecraft::iron_nugget, {8.0, 0.0});
	trades[1076].setIn(Items::minecraft::torch, {1.0, 0.0});
	trades[1076].setOut(Items::minecraft::lantern, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/lapis_block.json
	trades[1077].setIn(Items::minecraft::dye, {9.0, 0.0});
	trades[1077].setOut(Items::minecraft::lapis_block, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/lapis_lazuli.json
	trades[1078].setIn(Items::minecraft::lapis_block, {1.0, 0.0});
	trades[1078].setOut(Items::minecraft::dye, 9.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/lead.json
	trades[1079].setIn(Items::minecraft::string, {4.0, 0.0});
	trades[1079].setIn(Items::minecraft::slime_ball, {1.0, 0.0});
	trades[1079].setOut(Items::minecraft::lead, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/leather_boots.json
	trades[1080].setIn(Items::minecraft::leather, {4.0, 0.0});
	trades[1080].setOut(Items::minecraft::leather_boots, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/leather_chestplate.json
	trades[1081].setIn(Items::minecraft::leather, {8.0, 0.0});
	trades[1081].setOut(Items::minecraft::leather_chestplate, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/leather_helmet.json
	trades[1082].setIn(Items::minecraft::leather, {5.0, 0.0});
	trades[1082].setOut(Items::minecraft::leather_helmet, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/leather_horse_armor.json
	trades[1083].setIn(Items::minecraft::leather, {7.0, 0.0});
	trades[1083].setOut(Items::minecraft::horsearmorleather, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/leather.json
	trades[1084].setIn(Items::minecraft::rabbit_hide, {4.0, 0.0});
	trades[1084].setOut(Items::minecraft::leather, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/leather_leggings.json
	trades[1085].setIn(Items::minecraft::leather, {7.0, 0.0});
	trades[1085].setOut(Items::minecraft::leather_leggings, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/lectern_from_crimson_slab.json
	trades[1086].setIn(Items::minecraft::crimson_slab, {4.0, 0.0});
	trades[1086].setIn(Items::minecraft::bookshelf, {1.0, 0.0});
	trades[1086].setOut(Items::minecraft::lectern, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/lectern_from_mangrove_slab.json
	trades[1087].setIn(Items::minecraft::mangrove_slab, {4.0, 0.0});
	trades[1087].setIn(Items::minecraft::bookshelf, {1.0, 0.0});
	trades[1087].setOut(Items::minecraft::lectern, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/lectern_from_warped_slab.json
	trades[1088].setIn(Items::minecraft::warped_slab, {4.0, 0.0});
	trades[1088].setIn(Items::minecraft::bookshelf, {1.0, 0.0});
	trades[1088].setOut(Items::minecraft::lectern, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/lectern.json
	trades[1089].setIn(Items::minecraft::wooden_slabs, {4.0, 0.0});
	trades[1089].setIn(Items::minecraft::bookshelf, {1.0, 0.0});
	trades[1089].setOut(Items::minecraft::lectern, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/lever.json
	trades[1090].setIn(Items::minecraft::cobblestone, {1.0, 0.0});
	trades[1090].setIn(Items::minecraft::stick, {1.0, 0.0});
	trades[1090].setOut(Items::minecraft::lever, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/light_blue_banner.json
	trades[1091].setIn(Items::minecraft::light_blue_wool, {6.0, 0.0});
	trades[1091].setIn(Items::minecraft::stick, {1.0, 0.0});
	trades[1091].setOut(Items::minecraft::banner, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/light_blue_candle.json
	trades[1092].setIn(Items::minecraft::candle, {1.0, 0.0});
	trades[1092].setIn(Items::minecraft::dye, {1.0, 0.0});
	trades[1092].setOut(Items::minecraft::light_blue_candle, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/light_blue_carpet_from_white.json
	trades[1093].setIn(Items::minecraft::white_carpet, {8.0, 0.0});
	trades[1093].setIn(Items::minecraft::light_blue_dye, {1.0, 0.0});
	trades[1093].setOut(Items::minecraft::light_blue_carpet, 8.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/light_blue_carpet.json
	trades[1094].setIn(Items::minecraft::light_blue_wool, {2.0, 0.0});
	trades[1094].setOut(Items::minecraft::light_blue_carpet, 3.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/light_blue_concrete_powder.json
	trades[1095].setIn(Items::minecraft::light_blue_dye, {1.0, 0.0});
	trades[1095].setIn(Items::minecraft::sand, {4.0, 0.0});
	trades[1095].setIn(Items::minecraft::gravel, {4.0, 0.0});
	trades[1095].setOut(Items::minecraft::light_blue_concrete_powder, 8.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/light_blue_dye_from_blue_bonemeal.json
	trades[1096].setIn(Items::minecraft::dye, {2.0, 0.0});
	trades[1096].setOut(Items::minecraft::dye, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/light_blue_dye_from_blue_orchid.json
	trades[1097].setIn(Items::minecraft::blue_orchid, {1.0, 0.0});
	trades[1097].setOut(Items::minecraft::dye, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/light_blue_dye_from_lapis_bonemeal.json
	trades[1098].setIn(Items::minecraft::dye, {2.0, 0.0});
	trades[1098].setOut(Items::minecraft::dye, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/light_blue_dye_from_lapis_white.json
	trades[1099].setIn(Items::minecraft::dye, {2.0, 0.0});
	trades[1099].setOut(Items::minecraft::dye, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/light_blue_dye.json
	trades[1100].setIn(Items::minecraft::dye, {2.0, 0.0});
	trades[1100].setOut(Items::minecraft::dye, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/light_blue_stained_glass.json
	trades[1101].setIn(Items::minecraft::glass, {8.0, 0.0});
	trades[1101].setIn(Items::minecraft::light_blue_dye, {1.0, 0.0});
	trades[1101].setOut(Items::minecraft::light_blue_stained_glass, 8.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/light_blue_stained_glass_pane_from_pane.json
	trades[1102].setIn(Items::minecraft::glass_pane, {8.0, 0.0});
	trades[1102].setIn(Items::minecraft::light_blue_dye, {1.0, 0.0});
	trades[1102].setOut(Items::minecraft::light_blue_stained_glass_pane, 8.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/light_blue_stained_glass_pane.json
	trades[1103].setIn(Items::minecraft::light_blue_stained_glass, {6.0, 0.0});
	trades[1103].setOut(Items::minecraft::light_blue_stained_glass_pane, 16.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/light_blue_stained_hardened_clay.json
	trades[1104].setIn(Items::minecraft::hardened_clay, {8.0, 0.0});
	trades[1104].setIn(Items::minecraft::light_blue_dye, {1.0, 0.0});
	trades[1104].setOut(Items::minecraft::light_blue_terracotta, 8.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/light_gray_banner.json
	trades[1105].setIn(Items::minecraft::light_gray_wool, {6.0, 0.0});
	trades[1105].setIn(Items::minecraft::stick, {1.0, 0.0});
	trades[1105].setOut(Items::minecraft::banner, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/light_gray_candle.json
	trades[1106].setIn(Items::minecraft::candle, {1.0, 0.0});
	trades[1106].setIn(Items::minecraft::dye, {1.0, 0.0});
	trades[1106].setOut(Items::minecraft::light_gray_candle, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/light_gray__carpet_from_white.json
	trades[1107].setIn(Items::minecraft::carpet, {8.0, 0.0});
	trades[1107].setIn(Items::minecraft::dye, {1.0, 0.0});
	trades[1107].setOut(Items::minecraft::carpet, 8.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/light_gray_carpet_from_white.json
	trades[1108].setIn(Items::minecraft::white_carpet, {8.0, 0.0});
	trades[1108].setIn(Items::minecraft::light_gray_dye, {1.0, 0.0});
	trades[1108].setOut(Items::minecraft::light_gray_carpet, 8.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/light_gray_carpet.json
	trades[1109].setIn(Items::minecraft::light_gray_wool, {2.0, 0.0});
	trades[1109].setOut(Items::minecraft::light_gray_carpet, 3.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/light_gray_concrete_powder.json
	trades[1110].setIn(Items::minecraft::light_gray_dye, {1.0, 0.0});
	trades[1110].setIn(Items::minecraft::sand, {4.0, 0.0});
	trades[1110].setIn(Items::minecraft::gravel, {4.0, 0.0});
	trades[1110].setOut(Items::minecraft::light_gray_concrete_powder, 8.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/light_gray_dye_from_azure_bluet.json
	trades[1111].setIn(Items::minecraft::azure_bluet, {1.0, 0.0});
	trades[1111].setOut(Items::minecraft::dye, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/light_gray_dye_from_black_bonemeal.json
	trades[1112].setIn(Items::minecraft::dye, {3.0, 0.0});
	trades[1112].setOut(Items::minecraft::dye, 3.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/light_gray_dye_from_gray_bonemeal.json
	trades[1113].setIn(Items::minecraft::dye, {2.0, 0.0});
	trades[1113].setOut(Items::minecraft::dye, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/light_gray_dye_from_gray_white.json
	trades[1114].setIn(Items::minecraft::dye, {2.0, 0.0});
	trades[1114].setOut(Items::minecraft::dye, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/light_gray_dye_from_ink_bonemeal.json
	trades[1115].setIn(Items::minecraft::dye, {3.0, 0.0});
	trades[1115].setOut(Items::minecraft::dye, 3.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/light_gray_dye_from_ink_white.json
	trades[1116].setIn(Items::minecraft::dye, {3.0, 0.0});
	trades[1116].setOut(Items::minecraft::dye, 3.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/light_gray_dye_from_oxeye_daisy.json
	trades[1117].setIn(Items::minecraft::oxeye_daisy, {1.0, 0.0});
	trades[1117].setOut(Items::minecraft::dye, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/light_gray_dye_from_white_tulip.json
	trades[1118].setIn(Items::minecraft::white_tulip, {1.0, 0.0});
	trades[1118].setOut(Items::minecraft::dye, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/light_gray_dye.json
	trades[1119].setIn(Items::minecraft::dye, {3.0, 0.0});
	trades[1119].setOut(Items::minecraft::dye, 3.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/light_gray_stained_glass.json
	trades[1120].setIn(Items::minecraft::glass, {8.0, 0.0});
	trades[1120].setIn(Items::minecraft::light_gray_dye, {1.0, 0.0});
	trades[1120].setOut(Items::minecraft::light_gray_stained_glass, 8.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/light_gray_stained_glass_pane_from_pane.json
	trades[1121].setIn(Items::minecraft::glass_pane, {8.0, 0.0});
	trades[1121].setIn(Items::minecraft::light_gray_dye, {1.0, 0.0});
	trades[1121].setOut(Items::minecraft::light_gray_stained_glass_pane, 8.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/light_gray_stained_glass_pane.json
	trades[1122].setIn(Items::minecraft::light_gray_stained_glass, {6.0, 0.0});
	trades[1122].setOut(Items::minecraft::light_gray_stained_glass_pane, 16.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/light_gray_stained_hardened_clay.json
	trades[1123].setIn(Items::minecraft::hardened_clay, {8.0, 0.0});
	trades[1123].setIn(Items::minecraft::light_gray_dye, {1.0, 0.0});
	trades[1123].setOut(Items::minecraft::light_gray_terracotta, 8.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/lightning_rod.json
	trades[1124].setIn(Items::minecraft::copper_ingot, {3.0, 0.0});
	trades[1124].setOut(Items::minecraft::lightning_rod, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/light_weighted_pressure_plate.json
	trades[1125].setIn(Items::minecraft::gold_ingot, {2.0, 0.0});
	trades[1125].setOut(Items::minecraft::light_weighted_pressure_plate, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/lime_banner.json
	trades[1126].setIn(Items::minecraft::lime_wool, {6.0, 0.0});
	trades[1126].setIn(Items::minecraft::stick, {1.0, 0.0});
	trades[1126].setOut(Items::minecraft::banner, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/lime_candle.json
	trades[1127].setIn(Items::minecraft::candle, {1.0, 0.0});
	trades[1127].setIn(Items::minecraft::dye, {1.0, 0.0});
	trades[1127].setOut(Items::minecraft::lime_candle, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/lime__carpet_from_white.json
	trades[1128].setIn(Items::minecraft::carpet, {8.0, 0.0});
	trades[1128].setIn(Items::minecraft::dye, {1.0, 0.0});
	trades[1128].setOut(Items::minecraft::carpet, 8.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/lime_carpet_from_white.json
	trades[1129].setIn(Items::minecraft::white_carpet, {8.0, 0.0});
	trades[1129].setIn(Items::minecraft::lime_dye, {1.0, 0.0});
	trades[1129].setOut(Items::minecraft::lime_carpet, 8.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/lime_carpet.json
	trades[1130].setIn(Items::minecraft::lime_wool, {2.0, 0.0});
	trades[1130].setOut(Items::minecraft::lime_carpet, 3.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/lime_concrete_powder.json
	trades[1131].setIn(Items::minecraft::lime_dye, {1.0, 0.0});
	trades[1131].setIn(Items::minecraft::sand, {4.0, 0.0});
	trades[1131].setIn(Items::minecraft::gravel, {4.0, 0.0});
	trades[1131].setOut(Items::minecraft::lime_concrete_powder, 8.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/lime_dye_from_bonemeal.json
	trades[1132].setIn(Items::minecraft::dye, {2.0, 0.0});
	trades[1132].setOut(Items::minecraft::dye, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/lime_dye.json
	trades[1133].setIn(Items::minecraft::dye, {2.0, 0.0});
	trades[1133].setOut(Items::minecraft::dye, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/lime_stained_glass.json
	trades[1134].setIn(Items::minecraft::glass, {8.0, 0.0});
	trades[1134].setIn(Items::minecraft::lime_dye, {1.0, 0.0});
	trades[1134].setOut(Items::minecraft::lime_stained_glass, 8.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/lime_stained_glass_pane_from_pane.json
	trades[1135].setIn(Items::minecraft::glass_pane, {8.0, 0.0});
	trades[1135].setIn(Items::minecraft::lime_dye, {1.0, 0.0});
	trades[1135].setOut(Items::minecraft::lime_stained_glass_pane, 8.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/lime_stained_glass_pane.json
	trades[1136].setIn(Items::minecraft::lime_stained_glass, {6.0, 0.0});
	trades[1136].setOut(Items::minecraft::lime_stained_glass_pane, 16.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/lime_stained_hardened_clay.json
	trades[1137].setIn(Items::minecraft::hardened_clay, {8.0, 0.0});
	trades[1137].setIn(Items::minecraft::lime_dye, {1.0, 0.0});
	trades[1137].setOut(Items::minecraft::lime_terracotta, 8.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/lit_pumpkin.json
	trades[1138].setIn(Items::minecraft::carved_pumpkin, {1.0, 0.0});
	trades[1138].setIn(Items::minecraft::torch, {1.0, 0.0});
	trades[1138].setOut(Items::minecraft::lit_pumpkin, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/locator_map.json
	trades[1139].setIn(Items::minecraft::paper, {8.0, 0.0});
	trades[1139].setIn(Items::minecraft::compass, {1.0, 0.0});
	trades[1139].setOut(Items::minecraft::emptymap, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/lodestone.json
	trades[1140].setIn(Items::minecraft::chiseled_stone_bricks, {8.0, 0.0});
	trades[1140].setIn(Items::minecraft::netherite_ingot, {1.0, 0.0});
	trades[1140].setOut(Items::minecraft::lodestone, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/loom_from_crimson_planks.json
	trades[1141].setIn(Items::minecraft::string, {2.0, 0.0});
	trades[1141].setIn(Items::minecraft::crimson_planks, {2.0, 0.0});
	trades[1141].setOut(Items::minecraft::loom, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/loom_from_mangrove_planks.json
	trades[1142].setIn(Items::minecraft::string, {2.0, 0.0});
	trades[1142].setIn(Items::minecraft::mangrove_planks, {2.0, 0.0});
	trades[1142].setOut(Items::minecraft::loom, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/loom_from_warped_planks.json
	trades[1143].setIn(Items::minecraft::string, {2.0, 0.0});
	trades[1143].setIn(Items::minecraft::warped_planks, {2.0, 0.0});
	trades[1143].setOut(Items::minecraft::loom, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/loom.json
	trades[1144].setIn(Items::minecraft::string, {2.0, 0.0});
	trades[1144].setIn(Items::minecraft::planks, {2.0, 0.0});
	trades[1144].setOut(Items::minecraft::loom, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/mace.json
	trades[1145].setIn(Items::minecraft::breeze_rod, {1.0, 0.0});
	trades[1145].setIn(Items::minecraft::heavy_core, {1.0, 0.0});
	trades[1145].setOut(Items::minecraft::mace, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/magenta_banner.json
	trades[1146].setIn(Items::minecraft::magenta_wool, {6.0, 0.0});
	trades[1146].setIn(Items::minecraft::stick, {1.0, 0.0});
	trades[1146].setOut(Items::minecraft::banner, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/magenta_candle.json
	trades[1147].setIn(Items::minecraft::candle, {1.0, 0.0});
	trades[1147].setIn(Items::minecraft::dye, {1.0, 0.0});
	trades[1147].setOut(Items::minecraft::magenta_candle, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/magenta_carpet_from_white.json
	trades[1148].setIn(Items::minecraft::white_carpet, {8.0, 0.0});
	trades[1148].setIn(Items::minecraft::magenta_dye, {1.0, 0.0});
	trades[1148].setOut(Items::minecraft::magenta_carpet, 8.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/magenta_carpet.json
	trades[1149].setIn(Items::minecraft::magenta_wool, {2.0, 0.0});
	trades[1149].setOut(Items::minecraft::magenta_carpet, 3.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/magenta_concrete_powder.json
	trades[1150].setIn(Items::minecraft::magenta_dye, {1.0, 0.0});
	trades[1150].setIn(Items::minecraft::sand, {4.0, 0.0});
	trades[1150].setIn(Items::minecraft::gravel, {4.0, 0.0});
	trades[1150].setOut(Items::minecraft::magenta_concrete_powder, 8.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/magenta_dye_from_allium.json
	trades[1151].setIn(Items::minecraft::allium, {1.0, 0.0});
	trades[1151].setOut(Items::minecraft::dye, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/magenta_dye_from_blue_ink_bonemeal.json
	trades[1152].setIn(Items::minecraft::dye, {4.0, 0.0});
	trades[1152].setOut(Items::minecraft::dye, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/magenta_dye_from_blue_ink_white.json
	trades[1153].setIn(Items::minecraft::dye, {4.0, 0.0});
	trades[1153].setOut(Items::minecraft::dye, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/magenta_dye_from_lapis_ink_bonemeal.json
	trades[1154].setIn(Items::minecraft::dye, {4.0, 0.0});
	trades[1154].setOut(Items::minecraft::dye, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/magenta_dye_from_lapis_ink_white.json
	trades[1155].setIn(Items::minecraft::dye, {4.0, 0.0});
	trades[1155].setOut(Items::minecraft::dye, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/magenta_dye_from_lapis_red_pink.json
	trades[1156].setIn(Items::minecraft::dye, {3.0, 0.0});
	trades[1156].setOut(Items::minecraft::dye, 3.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/magenta_dye_from_lilac.json
	trades[1157].setIn(Items::minecraft::lilac, {1.0, 0.0});
	trades[1157].setOut(Items::minecraft::magenta_dye, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/magenta_dye_from_purple_and_pink.json
	trades[1158].setIn(Items::minecraft::dye, {2.0, 0.0});
	trades[1158].setOut(Items::minecraft::dye, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/magenta_dye.json
	trades[1159].setIn(Items::minecraft::dye, {3.0, 0.0});
	trades[1159].setOut(Items::minecraft::dye, 3.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/magenta_stained_glass.json
	trades[1160].setIn(Items::minecraft::glass, {8.0, 0.0});
	trades[1160].setIn(Items::minecraft::magenta_dye, {1.0, 0.0});
	trades[1160].setOut(Items::minecraft::magenta_stained_glass, 8.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/magenta_stained_glass_pane_from_pane.json
	trades[1161].setIn(Items::minecraft::glass_pane, {8.0, 0.0});
	trades[1161].setIn(Items::minecraft::magenta_dye, {1.0, 0.0});
	trades[1161].setOut(Items::minecraft::magenta_stained_glass_pane, 8.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/magenta_stained_glass_pane.json
	trades[1162].setIn(Items::minecraft::magenta_stained_glass, {6.0, 0.0});
	trades[1162].setOut(Items::minecraft::magenta_stained_glass_pane, 16.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/magenta_stained_hardened_clay.json
	trades[1163].setIn(Items::minecraft::hardened_clay, {8.0, 0.0});
	trades[1163].setIn(Items::minecraft::magenta_dye, {1.0, 0.0});
	trades[1163].setOut(Items::minecraft::magenta_terracotta, 8.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/magma_cream.json
	trades[1164].setIn(Items::minecraft::blaze_powder, {1.0, 0.0});
	trades[1164].setIn(Items::minecraft::slime_ball, {1.0, 0.0});
	trades[1164].setOut(Items::minecraft::magma_cream, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/magma.json
	trades[1165].setIn(Items::minecraft::magma_cream, {4.0, 0.0});
	trades[1165].setOut(Items::minecraft::magma, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/mangrove_boat.json
	trades[1166].setIn(Items::minecraft::mangrove_planks, {5.0, 0.0});
	trades[1166].setOut(Items::minecraft::mangrove_boat, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/mangrove_button.json
	trades[1167].setIn(Items::minecraft::mangrove_planks, {1.0, 0.0});
	trades[1167].setOut(Items::minecraft::mangrove_button, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/mangrove_chest_boat.json
	trades[1168].setIn(Items::minecraft::chest, {1.0, 0.0});
	trades[1168].setIn(Items::minecraft::boat, {1.0, 0.0});
	trades[1168].setOut(Items::minecraft::chest_boat, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/mangrove_door.json
	trades[1169].setIn(Items::minecraft::mangrove_planks, {6.0, 0.0});
	trades[1169].setOut(Items::minecraft::mangrove_door, 3.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/mangrove_fence_gate.json
	trades[1170].setIn(Items::minecraft::stick, {4.0, 0.0});
	trades[1170].setIn(Items::minecraft::mangrove_planks, {2.0, 0.0});
	trades[1170].setOut(Items::minecraft::mangrove_fence_gate, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/mangrove_fence.json
	trades[1171].setIn(Items::minecraft::stick, {2.0, 0.0});
	trades[1171].setIn(Items::minecraft::mangrove_planks, {4.0, 0.0});
	trades[1171].setOut(Items::minecraft::mangrove_fence, 3.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/mangrove_hanging_sign.json
	trades[1172].setIn(Items::minecraft::stripped_mangrove_log, {6.0, 0.0});
	trades[1172].setIn(Items::minecraft::chain, {2.0, 0.0});
	trades[1172].setOut(Items::minecraft::mangrove_hanging_sign, 6.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/mangrove_planks_from_stripped_log.json
	trades[1173].setIn(Items::minecraft::stripped_mangrove_log, {1.0, 0.0});
	trades[1173].setOut(Items::minecraft::mangrove_planks, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/mangrove_planks_from_stripped_wood.json
	trades[1174].setIn(Items::minecraft::stripped_mangrove_wood, {1.0, 0.0});
	trades[1174].setOut(Items::minecraft::mangrove_planks, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/mangrove_planks_from_wood.json
	trades[1175].setIn(Items::minecraft::mangrove_wood, {1.0, 0.0});
	trades[1175].setOut(Items::minecraft::mangrove_planks, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/mangrove_planks.json
	trades[1176].setIn(Items::minecraft::mangrove_log, {1.0, 0.0});
	trades[1176].setOut(Items::minecraft::mangrove_planks, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/mangrove_pressure_plate.json
	trades[1177].setIn(Items::minecraft::mangrove_planks, {2.0, 0.0});
	trades[1177].setOut(Items::minecraft::mangrove_pressure_plate, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/mangrove_sign.json
	trades[1178].setIn(Items::minecraft::mangrove_planks, {6.0, 0.0});
	trades[1178].setIn(Items::minecraft::stick, {1.0, 0.0});
	trades[1178].setOut(Items::minecraft::mangrove_sign, 3.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/mangrove_slab.json
	trades[1179].setIn(Items::minecraft::mangrove_planks, {3.0, 0.0});
	trades[1179].setOut(Items::minecraft::mangrove_slab, 6.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/mangrove_stairs.json
	trades[1180].setIn(Items::minecraft::mangrove_planks, {6.0, 0.0});
	trades[1180].setOut(Items::minecraft::mangrove_stairs, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/mangrove_trapdoor.json
	trades[1181].setIn(Items::minecraft::mangrove_planks, {6.0, 0.0});
	trades[1181].setOut(Items::minecraft::mangrove_trapdoor, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/mangrove_wood.json
	trades[1182].setIn(Items::minecraft::mangrove_log, {4.0, 0.0});
	trades[1182].setOut(Items::minecraft::mangrove_wood, 3.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/mangrove_wood_stripped.json
	trades[1183].setIn(Items::minecraft::stripped_mangrove_log, {4.0, 0.0});
	trades[1183].setOut(Items::minecraft::stripped_mangrove_wood, 3.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/map.json
	trades[1184].setIn(Items::minecraft::paper, {9.0, 0.0});
	trades[1184].setOut(Items::minecraft::emptymap, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/melon_block.json
	trades[1185].setIn(Items::minecraft::melon, {9.0, 0.0});
	trades[1185].setOut(Items::minecraft::melon_block, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/melon_seeds.json
	trades[1186].setIn(Items::minecraft::melon, {1.0, 0.0});
	trades[1186].setOut(Items::minecraft::melon_seeds, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/minecart.json
	trades[1187].setIn(Items::minecraft::iron_ingot, {5.0, 0.0});
	trades[1187].setOut(Items::minecraft::minecart, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/moss_carpet.json
	trades[1188].setIn(Items::minecraft::moss_block, {2.0, 0.0});
	trades[1188].setOut(Items::minecraft::moss_carpet, 3.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/mossy_cobblestone_from_moss.json
	trades[1189].setIn(Items::minecraft::cobblestone, {1.0, 0.0});
	trades[1189].setIn(Items::minecraft::moss_block, {1.0, 0.0});
	trades[1189].setOut(Items::minecraft::mossy_cobblestone, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/mossy_cobblestone.json
	trades[1190].setIn(Items::minecraft::cobblestone, {1.0, 0.0});
	trades[1190].setIn(Items::minecraft::vine, {1.0, 0.0});
	trades[1190].setOut(Items::minecraft::mossy_cobblestone, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/mossy_cobblestone_stairs.json
	trades[1191].setIn(Items::minecraft::mossy_cobblestone, {6.0, 0.0});
	trades[1191].setOut(Items::minecraft::mossy_cobblestone_stairs, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/mossy_cobblestone_wall.json
	trades[1192].setIn(Items::minecraft::mossy_cobblestone, {6.0, 0.0});
	trades[1192].setOut(Items::minecraft::mossy_cobblestone_wall, 6.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/mossy_stonebrick_from_moss.json
	trades[1193].setIn(Items::minecraft::stone_bricks, {1.0, 0.0});
	trades[1193].setIn(Items::minecraft::moss_block, {1.0, 0.0});
	trades[1193].setOut(Items::minecraft::mossy_stone_bricks, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/mossy_stonebrick.json
	trades[1194].setIn(Items::minecraft::stone_bricks, {1.0, 0.0});
	trades[1194].setIn(Items::minecraft::vine, {1.0, 0.0});
	trades[1194].setOut(Items::minecraft::mossy_stone_bricks, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/mossy_stone_brick_stairs.json
	trades[1195].setIn(Items::minecraft::mossy_stone_bricks, {6.0, 0.0});
	trades[1195].setOut(Items::minecraft::mossy_stone_brick_stairs, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/mossy_stone_brick_wall.json
	trades[1196].setIn(Items::minecraft::mossy_stone_bricks, {6.0, 0.0});
	trades[1196].setOut(Items::minecraft::mossy_stone_brick_wall, 6.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/mud_bricks.json
	trades[1197].setIn(Items::minecraft::packed_mud, {4.0, 0.0});
	trades[1197].setOut(Items::minecraft::mud_bricks, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/mud_brick_slab.json
	trades[1198].setIn(Items::minecraft::mud_bricks, {3.0, 0.0});
	trades[1198].setOut(Items::minecraft::mud_brick_slab, 6.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/mud_brick_stairs.json
	trades[1199].setIn(Items::minecraft::mud_bricks, {6.0, 0.0});
	trades[1199].setOut(Items::minecraft::mud_brick_stairs, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/mud_brick_wall.json
	trades[1200].setIn(Items::minecraft::mud_bricks, {6.0, 0.0});
	trades[1200].setOut(Items::minecraft::mud_brick_wall, 6.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/muddy_mangrove_roots.json
	trades[1201].setIn(Items::minecraft::mangrove_roots, {1.0, 0.0});
	trades[1201].setIn(Items::minecraft::mud, {1.0, 0.0});
	trades[1201].setOut(Items::minecraft::muddy_mangrove_roots, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/mushroom_stew.json
	trades[1202].setIn(Items::minecraft::brown_mushroom, {1.0, 0.0});
	trades[1202].setIn(Items::minecraft::red_mushroom, {1.0, 0.0});
	trades[1202].setIn(Items::minecraft::bowl, {1.0, 0.0});
	trades[1202].setOut(Items::minecraft::mushroom_stew, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/nether_brick_fence.json
	trades[1203].setIn(Items::minecraft::netherbrick, {2.0, 0.0});
	trades[1203].setIn(Items::minecraft::nether_brick, {4.0, 0.0});
	trades[1203].setOut(Items::minecraft::nether_brick_fence, 6.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/nether_brick.json
	trades[1204].setIn(Items::minecraft::netherbrick, {4.0, 0.0});
	trades[1204].setOut(Items::minecraft::nether_brick, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/nether_brick_stairs.json
	trades[1205].setIn(Items::minecraft::nether_brick, {6.0, 0.0});
	trades[1205].setOut(Items::minecraft::nether_brick_stairs, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/nether_brick_wall.json
	trades[1206].setIn(Items::minecraft::nether_brick, {6.0, 0.0});
	trades[1206].setOut(Items::minecraft::nether_brick_wall, 6.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/netherite_block.json
	trades[1207].setIn(Items::minecraft::netherite_ingot, {9.0, 0.0});
	trades[1207].setOut(Items::minecraft::netherite_block, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/netherite_ingot_from_block.json
	trades[1208].setIn(Items::minecraft::netherite_block, {1.0, 0.0});
	trades[1208].setOut(Items::minecraft::netherite_ingot, 9.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/netherite_ingot.json
	trades[1209].setIn(Items::minecraft::netherite_scrap, {4.0, 0.0});
	trades[1209].setIn(Items::minecraft::gold_ingot, {4.0, 0.0});
	trades[1209].setOut(Items::minecraft::netherite_ingot, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/netherite_upgrade_smithing_template_duplicate.json
	trades[1210].setIn(Items::minecraft::netherite_upgrade_smithing_template, {1.0, 0.0});
	trades[1210].setIn(Items::minecraft::diamond, {7.0, 0.0});
	trades[1210].setIn(Items::minecraft::netherrack, {1.0, 0.0});
	trades[1210].setOut(Items::minecraft::netherite_upgrade_smithing_template, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/nether_wart_block.json
	trades[1211].setIn(Items::minecraft::nether_wart, {9.0, 0.0});
	trades[1211].setOut(Items::minecraft::nether_wart_block, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/noteblock_from_crimson_planks.json
	trades[1212].setIn(Items::minecraft::crimson_planks, {8.0, 0.0});
	trades[1212].setIn(Items::minecraft::redstone, {1.0, 0.0});
	trades[1212].setOut(Items::minecraft::noteblock, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/noteblock_from_mangrove_planks.json
	trades[1213].setIn(Items::minecraft::mangrove_planks, {8.0, 0.0});
	trades[1213].setIn(Items::minecraft::redstone, {1.0, 0.0});
	trades[1213].setOut(Items::minecraft::noteblock, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/noteblock_from_warped_planks.json
	trades[1214].setIn(Items::minecraft::warped_planks, {8.0, 0.0});
	trades[1214].setIn(Items::minecraft::redstone, {1.0, 0.0});
	trades[1214].setOut(Items::minecraft::noteblock, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/noteblock.json
	trades[1215].setIn(Items::minecraft::planks, {8.0, 0.0});
	trades[1215].setIn(Items::minecraft::redstone, {1.0, 0.0});
	trades[1215].setOut(Items::minecraft::noteblock, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/oak_fence.json
	trades[1216].setIn(Items::minecraft::stick, {2.0, 0.0});
	trades[1216].setIn(Items::minecraft::oak_planks, {4.0, 0.0});
	trades[1216].setOut(Items::minecraft::oak_fence, 3.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/oak_hanging_sign.json
	trades[1217].setIn(Items::minecraft::stripped_oak_log, {6.0, 0.0});
	trades[1217].setIn(Items::minecraft::chain, {2.0, 0.0});
	trades[1217].setOut(Items::minecraft::oak_hanging_sign, 6.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/oak_planks_from_stripped.json
	trades[1218].setIn(Items::minecraft::stripped_oak_log, {1.0, 0.0});
	trades[1218].setOut(Items::minecraft::oak_planks, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/oak_planks_from_stripped_wood.json
	trades[1219].setIn(Items::minecraft::stripped_oak_wood, {1.0, 0.0});
	trades[1219].setOut(Items::minecraft::oak_planks, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/oak_planks_from_wood.json
	trades[1220].setIn(Items::minecraft::oak_wood, {1.0, 0.0});
	trades[1220].setOut(Items::minecraft::oak_planks, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/oak_planks.json
	trades[1221].setIn(Items::minecraft::oak_log, {1.0, 0.0});
	trades[1221].setOut(Items::minecraft::oak_planks, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/oak_stairs.json
	trades[1222].setIn(Items::minecraft::oak_planks, {6.0, 0.0});
	trades[1222].setOut(Items::minecraft::oak_stairs, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/oak_wooden_slab.json
	trades[1223].setIn(Items::minecraft::oak_planks, {3.0, 0.0});
	trades[1223].setOut(Items::minecraft::oak_slab, 6.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/oak_wood.json
	trades[1224].setIn(Items::minecraft::oak_log, {4.0, 0.0});
	trades[1224].setOut(Items::minecraft::oak_wood, 3.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/oak_wood_stripped.json
	trades[1225].setIn(Items::minecraft::stripped_oak_log, {4.0, 0.0});
	trades[1225].setOut(Items::minecraft::stripped_oak_wood, 3.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/observer.json
	trades[1226].setIn(Items::minecraft::quartz, {1.0, 0.0});
	trades[1226].setIn(Items::minecraft::redstone, {2.0, 0.0});
	trades[1226].setIn(Items::minecraft::cobblestone, {6.0, 0.0});
	trades[1226].setOut(Items::minecraft::observer, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/orange_banner.json
	trades[1227].setIn(Items::minecraft::orange_wool, {6.0, 0.0});
	trades[1227].setIn(Items::minecraft::stick, {1.0, 0.0});
	trades[1227].setOut(Items::minecraft::banner, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/orange_candle.json
	trades[1228].setIn(Items::minecraft::candle, {1.0, 0.0});
	trades[1228].setIn(Items::minecraft::dye, {1.0, 0.0});
	trades[1228].setOut(Items::minecraft::orange_candle, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/orange_carpet_from_white.json
	trades[1229].setIn(Items::minecraft::white_carpet, {8.0, 0.0});
	trades[1229].setIn(Items::minecraft::orange_dye, {1.0, 0.0});
	trades[1229].setOut(Items::minecraft::orange_carpet, 8.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/orange_carpet.json
	trades[1230].setIn(Items::minecraft::orange_wool, {2.0, 0.0});
	trades[1230].setOut(Items::minecraft::orange_carpet, 3.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/orange_concrete_powder.json
	trades[1231].setIn(Items::minecraft::orange_dye, {1.0, 0.0});
	trades[1231].setIn(Items::minecraft::sand, {4.0, 0.0});
	trades[1231].setIn(Items::minecraft::gravel, {4.0, 0.0});
	trades[1231].setOut(Items::minecraft::orange_concrete_powder, 8.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/orange_dye_from_open_eyeblossom.json
	trades[1232].setIn(Items::minecraft::open_eyeblossom, {1.0, 0.0});
	trades[1232].setOut(Items::minecraft::orange_dye, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/orange_dye_from_orange_tulip.json
	trades[1233].setIn(Items::minecraft::orange_tulip, {1.0, 0.0});
	trades[1233].setOut(Items::minecraft::dye, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/orange_dye_from_red_yellow.json
	trades[1234].setIn(Items::minecraft::dye, {2.0, 0.0});
	trades[1234].setOut(Items::minecraft::dye, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/orange_dye_from_torchflower.json
	trades[1235].setIn(Items::minecraft::torchflower, {1.0, 0.0});
	trades[1235].setOut(Items::minecraft::dye, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/orange_stained_glass.json
	trades[1236].setIn(Items::minecraft::glass, {8.0, 0.0});
	trades[1236].setIn(Items::minecraft::orange_dye, {1.0, 0.0});
	trades[1236].setOut(Items::minecraft::orange_stained_glass, 8.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/orange_stained_glass_pane_from_pane.json
	trades[1237].setIn(Items::minecraft::glass_pane, {8.0, 0.0});
	trades[1237].setIn(Items::minecraft::orange_dye, {1.0, 0.0});
	trades[1237].setOut(Items::minecraft::orange_stained_glass_pane, 8.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/orange_stained_glass_pane.json
	trades[1238].setIn(Items::minecraft::orange_stained_glass, {6.0, 0.0});
	trades[1238].setOut(Items::minecraft::orange_stained_glass_pane, 16.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/orange_stained_hardened_clay.json
	trades[1239].setIn(Items::minecraft::hardened_clay, {8.0, 0.0});
	trades[1239].setIn(Items::minecraft::orange_dye, {1.0, 0.0});
	trades[1239].setOut(Items::minecraft::orange_terracotta, 8.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/packed_ice.json
	trades[1240].setIn(Items::minecraft::ice, {9.0, 0.0});
	trades[1240].setOut(Items::minecraft::packed_ice, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/packed_mud.json
	trades[1241].setIn(Items::minecraft::mud, {1.0, 0.0});
	trades[1241].setIn(Items::minecraft::wheat, {1.0, 0.0});
	trades[1241].setOut(Items::minecraft::packed_mud, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/painting.json
	trades[1242].setIn(Items::minecraft::stick, {8.0, 0.0});
	trades[1242].setIn(Items::minecraft::wool, {1.0, 0.0});
	trades[1242].setOut(Items::minecraft::painting, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/pale_moss_carpet.json
	trades[1243].setIn(Items::minecraft::pale_moss_block, {2.0, 0.0});
	trades[1243].setOut(Items::minecraft::pale_moss_carpet, 3.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/pale_oak_boat.json
	trades[1244].setIn(Items::minecraft::pale_oak_planks, {5.0, 0.0});
	trades[1244].setOut(Items::minecraft::pale_oak_boat, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/pale_oak_button.json
	trades[1245].setIn(Items::minecraft::pale_oak_planks, {1.0, 0.0});
	trades[1245].setOut(Items::minecraft::pale_oak_button, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/pale_oak_chest_boat.json
	trades[1246].setIn(Items::minecraft::chest, {1.0, 0.0});
	trades[1246].setIn(Items::minecraft::pale_oak_boat, {1.0, 0.0});
	trades[1246].setOut(Items::minecraft::pale_oak_chest_boat, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/pale_oak_door.json
	trades[1247].setIn(Items::minecraft::pale_oak_planks, {6.0, 0.0});
	trades[1247].setOut(Items::minecraft::pale_oak_door, 3.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/pale_oak_fence_gate.json
	trades[1248].setIn(Items::minecraft::stick, {4.0, 0.0});
	trades[1248].setIn(Items::minecraft::pale_oak_planks, {2.0, 0.0});
	trades[1248].setOut(Items::minecraft::pale_oak_fence_gate, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/pale_oak_fence.json
	trades[1249].setIn(Items::minecraft::stick, {2.0, 0.0});
	trades[1249].setIn(Items::minecraft::pale_oak_planks, {4.0, 0.0});
	trades[1249].setOut(Items::minecraft::pale_oak_fence, 3.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/pale_oak_hanging_sign.json
	trades[1250].setIn(Items::minecraft::stripped_pale_oak_log, {6.0, 0.0});
	trades[1250].setIn(Items::minecraft::chain, {2.0, 0.0});
	trades[1250].setOut(Items::minecraft::pale_oak_hanging_sign, 6.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/pale_oak_planks_from_log.json
	trades[1251].setIn(Items::minecraft::pale_oak_log, {1.0, 0.0});
	trades[1251].setOut(Items::minecraft::pale_oak_planks, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/pale_oak_planks_from_stripped_log.json
	trades[1252].setIn(Items::minecraft::stripped_pale_oak_log, {1.0, 0.0});
	trades[1252].setOut(Items::minecraft::pale_oak_planks, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/pale_oak_planks_from_stripped_wood.json
	trades[1253].setIn(Items::minecraft::stripped_pale_oak_wood, {1.0, 0.0});
	trades[1253].setOut(Items::minecraft::pale_oak_planks, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/pale_oak_planks_from_wood.json
	trades[1254].setIn(Items::minecraft::pale_oak_wood, {1.0, 0.0});
	trades[1254].setOut(Items::minecraft::pale_oak_planks, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/pale_oak_pressure_plate.json
	trades[1255].setIn(Items::minecraft::pale_oak_planks, {2.0, 0.0});
	trades[1255].setOut(Items::minecraft::pale_oak_pressure_plate, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/pale_oak_sign.json
	trades[1256].setIn(Items::minecraft::pale_oak_planks, {6.0, 0.0});
	trades[1256].setIn(Items::minecraft::stick, {1.0, 0.0});
	trades[1256].setOut(Items::minecraft::pale_oak_sign, 3.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/pale_oak_slab.json
	trades[1257].setIn(Items::minecraft::pale_oak_planks, {3.0, 0.0});
	trades[1257].setOut(Items::minecraft::pale_oak_slab, 6.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/pale_oak_stairs.json
	trades[1258].setIn(Items::minecraft::pale_oak_planks, {6.0, 0.0});
	trades[1258].setOut(Items::minecraft::pale_oak_stairs, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/pale_oak_stripped_wood_from_stripped_log.json
	trades[1259].setIn(Items::minecraft::stripped_pale_oak_log, {4.0, 0.0});
	trades[1259].setOut(Items::minecraft::stripped_pale_oak_wood, 3.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/pale_oak_trapdoor.json
	trades[1260].setIn(Items::minecraft::pale_oak_planks, {6.0, 0.0});
	trades[1260].setOut(Items::minecraft::pale_oak_trapdoor, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/pale_oak_wood_from_log.json
	trades[1261].setIn(Items::minecraft::pale_oak_log, {4.0, 0.0});
	trades[1261].setOut(Items::minecraft::pale_oak_wood, 3.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/paper.json
	trades[1262].setIn(Items::minecraft::reeds, {3.0, 0.0});
	trades[1262].setOut(Items::minecraft::paper, 3.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/pillar_quartz_block.json
	trades[1263].setIn(Items::minecraft::quartz_block, {2.0, 0.0});
	trades[1263].setOut(Items::minecraft::quartz_block, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/pink_banner.json
	trades[1264].setIn(Items::minecraft::pink_wool, {6.0, 0.0});
	trades[1264].setIn(Items::minecraft::stick, {1.0, 0.0});
	trades[1264].setOut(Items::minecraft::banner, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/pink_candle.json
	trades[1265].setIn(Items::minecraft::candle, {1.0, 0.0});
	trades[1265].setIn(Items::minecraft::dye, {1.0, 0.0});
	trades[1265].setOut(Items::minecraft::pink_candle, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/pink_carpet_from_white.json
	trades[1266].setIn(Items::minecraft::white_carpet, {8.0, 0.0});
	trades[1266].setIn(Items::minecraft::pink_dye, {1.0, 0.0});
	trades[1266].setOut(Items::minecraft::pink_carpet, 8.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/pink_carpet.json
	trades[1267].setIn(Items::minecraft::pink_wool, {2.0, 0.0});
	trades[1267].setOut(Items::minecraft::pink_carpet, 3.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/pink_concrete_powder.json
	trades[1268].setIn(Items::minecraft::pink_dye, {1.0, 0.0});
	trades[1268].setIn(Items::minecraft::sand, {4.0, 0.0});
	trades[1268].setIn(Items::minecraft::gravel, {4.0, 0.0});
	trades[1268].setOut(Items::minecraft::pink_concrete_powder, 8.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/pink_dye_from_peony.json
	trades[1269].setIn(Items::minecraft::peony, {1.0, 0.0});
	trades[1269].setOut(Items::minecraft::pink_dye, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/pink_dye_from_pink_petals.json
	trades[1270].setIn(Items::minecraft::pink_petals, {1.0, 0.0});
	trades[1270].setOut(Items::minecraft::pink_dye, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/pink_dye_from_pink_tulip.json
	trades[1271].setIn(Items::minecraft::pink_tulip, {1.0, 0.0});
	trades[1271].setOut(Items::minecraft::dye, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/pink_dye_from_red_bonemeal.json
	trades[1272].setIn(Items::minecraft::dye, {2.0, 0.0});
	trades[1272].setOut(Items::minecraft::dye, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/pink_dye.json
	trades[1273].setIn(Items::minecraft::dye, {2.0, 0.0});
	trades[1273].setOut(Items::minecraft::dye, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/pink_stained_glass.json
	trades[1274].setIn(Items::minecraft::glass, {8.0, 0.0});
	trades[1274].setIn(Items::minecraft::pink_dye, {1.0, 0.0});
	trades[1274].setOut(Items::minecraft::pink_stained_glass, 8.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/pink_stained_glass_pane_from_pane.json
	trades[1275].setIn(Items::minecraft::glass_pane, {8.0, 0.0});
	trades[1275].setIn(Items::minecraft::pink_dye, {1.0, 0.0});
	trades[1275].setOut(Items::minecraft::pink_stained_glass_pane, 8.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/pink_stained_glass_pane.json
	trades[1276].setIn(Items::minecraft::pink_stained_glass, {6.0, 0.0});
	trades[1276].setOut(Items::minecraft::pink_stained_glass_pane, 16.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/pink_stained_hardened_clay.json
	trades[1277].setIn(Items::minecraft::hardened_clay, {8.0, 0.0});
	trades[1277].setIn(Items::minecraft::pink_dye, {1.0, 0.0});
	trades[1277].setOut(Items::minecraft::pink_terracotta, 8.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/piston_from_crimson_planks.json
	trades[1278].setIn(Items::minecraft::crimson_planks, {3.0, 0.0});
	trades[1278].setIn(Items::minecraft::cobblestone, {4.0, 0.0});
	trades[1278].setIn(Items::minecraft::iron_ingot, {1.0, 0.0});
	trades[1278].setIn(Items::minecraft::redstone, {1.0, 0.0});
	trades[1278].setOut(Items::minecraft::piston, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/piston_from_mangrove_planks.json
	trades[1279].setIn(Items::minecraft::mangrove_planks, {3.0, 0.0});
	trades[1279].setIn(Items::minecraft::cobblestone, {4.0, 0.0});
	trades[1279].setIn(Items::minecraft::iron_ingot, {1.0, 0.0});
	trades[1279].setIn(Items::minecraft::redstone, {1.0, 0.0});
	trades[1279].setOut(Items::minecraft::piston, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/piston_from_warped_planks.json
	trades[1280].setIn(Items::minecraft::warped_planks, {3.0, 0.0});
	trades[1280].setIn(Items::minecraft::cobblestone, {4.0, 0.0});
	trades[1280].setIn(Items::minecraft::iron_ingot, {1.0, 0.0});
	trades[1280].setIn(Items::minecraft::redstone, {1.0, 0.0});
	trades[1280].setOut(Items::minecraft::piston, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/piston.json
	trades[1281].setIn(Items::minecraft::planks, {3.0, 0.0});
	trades[1281].setIn(Items::minecraft::cobblestone, {4.0, 0.0});
	trades[1281].setIn(Items::minecraft::iron_ingot, {1.0, 0.0});
	trades[1281].setIn(Items::minecraft::redstone, {1.0, 0.0});
	trades[1281].setOut(Items::minecraft::piston, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/polished_andesite.json
	trades[1282].setIn(Items::minecraft::andesite, {4.0, 0.0});
	trades[1282].setOut(Items::minecraft::polished_andesite, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/polished_andesite_stairs.json
	trades[1283].setIn(Items::minecraft::polished_andesite, {6.0, 0.0});
	trades[1283].setOut(Items::minecraft::polished_andesite_stairs, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/polished_basalt.json
	trades[1284].setIn(Items::minecraft::basalt, {4.0, 0.0});
	trades[1284].setOut(Items::minecraft::polished_basalt, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/polished_blackstone_bricks.json
	trades[1285].setIn(Items::minecraft::polished_blackstone, {4.0, 0.0});
	trades[1285].setOut(Items::minecraft::polished_blackstone_bricks, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/polished_blackstone_brick_slab.json
	trades[1286].setIn(Items::minecraft::polished_blackstone_bricks, {3.0, 0.0});
	trades[1286].setOut(Items::minecraft::polished_blackstone_brick_slab, 6.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/polished_blackstone_brick_stairs.json
	trades[1287].setIn(Items::minecraft::polished_blackstone_bricks, {6.0, 0.0});
	trades[1287].setOut(Items::minecraft::polished_blackstone_brick_stairs, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/polished_blackstone_brick_wall.json
	trades[1288].setIn(Items::minecraft::polished_blackstone_bricks, {6.0, 0.0});
	trades[1288].setOut(Items::minecraft::polished_blackstone_brick_wall, 6.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/polished_blackstone_button.json
	trades[1289].setIn(Items::minecraft::polished_blackstone, {1.0, 0.0});
	trades[1289].setOut(Items::minecraft::polished_blackstone_button, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/polished_blackstone.json
	trades[1290].setIn(Items::minecraft::blackstone, {4.0, 0.0});
	trades[1290].setOut(Items::minecraft::polished_blackstone, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/polished_blackstone_pressure_plate.json
	trades[1291].setIn(Items::minecraft::polished_blackstone, {2.0, 0.0});
	trades[1291].setOut(Items::minecraft::polished_blackstone_pressure_plate, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/polished_blackstone_slab.json
	trades[1292].setIn(Items::minecraft::polished_blackstone, {3.0, 0.0});
	trades[1292].setOut(Items::minecraft::polished_blackstone_slab, 6.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/polished_blackstone_stairs.json
	trades[1293].setIn(Items::minecraft::polished_blackstone, {6.0, 0.0});
	trades[1293].setOut(Items::minecraft::polished_blackstone_stairs, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/polished_blackstone_wall.json
	trades[1294].setIn(Items::minecraft::polished_blackstone, {6.0, 0.0});
	trades[1294].setOut(Items::minecraft::polished_blackstone_wall, 6.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/polished_deepslate_from_cobbled_deepslate_stonecutting.json
	trades[1295].setIn(Items::minecraft::cobbled_deepslate, {1.0, 0.0});
	trades[1295].setOut(Items::minecraft::polished_deepslate, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/polished_deepslate.json
	trades[1296].setIn(Items::minecraft::cobbled_deepslate, {4.0, 0.0});
	trades[1296].setOut(Items::minecraft::polished_deepslate, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/polished_deepslate_slab_from_cobbled_deepslate_stonecut.json
	trades[1297].setIn(Items::minecraft::cobbled_deepslate, {1.0, 0.0});
	trades[1297].setOut(Items::minecraft::polished_deepslate_slab, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/polished_deepslate_slab_from_polished_deepslate_cutting.json
	trades[1298].setIn(Items::minecraft::polished_deepslate, {1.0, 0.0});
	trades[1298].setOut(Items::minecraft::polished_deepslate_slab, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/polished_deepslate_slab.json
	trades[1299].setIn(Items::minecraft::polished_deepslate, {3.0, 0.0});
	trades[1299].setOut(Items::minecraft::polished_deepslate_slab, 6.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/polished_deepslate_stairs_from_cobbled_deepslate_cutting.json
	trades[1300].setIn(Items::minecraft::cobbled_deepslate, {1.0, 0.0});
	trades[1300].setOut(Items::minecraft::polished_deepslate_stairs, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/polished_deepslate_stairs_from_polished_deepslate_cutting.json
	trades[1301].setIn(Items::minecraft::polished_deepslate, {1.0, 0.0});
	trades[1301].setOut(Items::minecraft::polished_deepslate_stairs, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/polished_deepslate_stairs.json
	trades[1302].setIn(Items::minecraft::polished_deepslate, {6.0, 0.0});
	trades[1302].setOut(Items::minecraft::polished_deepslate_stairs, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/polished_deepslate_wall_from_cobbled_deepslate_stonecut.json
	trades[1303].setIn(Items::minecraft::cobbled_deepslate, {1.0, 0.0});
	trades[1303].setOut(Items::minecraft::polished_deepslate_wall, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/polished_deepslate_wall_from_polished_deepslate_stonecut.json
	trades[1304].setIn(Items::minecraft::polished_deepslate, {1.0, 0.0});
	trades[1304].setOut(Items::minecraft::polished_deepslate_wall, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/polished_deepslate_wall.json
	trades[1305].setIn(Items::minecraft::polished_deepslate, {6.0, 0.0});
	trades[1305].setOut(Items::minecraft::polished_deepslate_wall, 6.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/polished_diorite.json
	trades[1306].setIn(Items::minecraft::diorite, {4.0, 0.0});
	trades[1306].setOut(Items::minecraft::polished_diorite, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/polished_diorite_stairs.json
	trades[1307].setIn(Items::minecraft::polished_diorite, {6.0, 0.0});
	trades[1307].setOut(Items::minecraft::polished_diorite_stairs, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/polished_granite.json
	trades[1308].setIn(Items::minecraft::granite, {4.0, 0.0});
	trades[1308].setOut(Items::minecraft::polished_granite, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/polished_granite_stairs.json
	trades[1309].setIn(Items::minecraft::polished_granite, {6.0, 0.0});
	trades[1309].setOut(Items::minecraft::polished_granite_stairs, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/polished_tuff.json
	trades[1310].setIn(Items::minecraft::tuff, {4.0, 0.0});
	trades[1310].setOut(Items::minecraft::polished_tuff, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/polished_tuff_slab.json
	trades[1311].setIn(Items::minecraft::polished_tuff, {3.0, 0.0});
	trades[1311].setOut(Items::minecraft::polished_tuff_slab, 6.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/polished_tuff_stairs.json
	trades[1312].setIn(Items::minecraft::polished_tuff, {6.0, 0.0});
	trades[1312].setOut(Items::minecraft::polished_tuff_stairs, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/polished_tuff_wall.json
	trades[1313].setIn(Items::minecraft::polished_tuff, {6.0, 0.0});
	trades[1313].setOut(Items::minecraft::polished_tuff_wall, 6.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/prismarine_bricks.json
	trades[1314].setIn(Items::minecraft::prismarine_shard, {9.0, 0.0});
	trades[1314].setOut(Items::minecraft::prismarine_bricks, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/prismarine.json
	trades[1315].setIn(Items::minecraft::prismarine_shard, {4.0, 0.0});
	trades[1315].setOut(Items::minecraft::prismarine, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/prismarine_stairs_bricks.json
	trades[1316].setIn(Items::minecraft::prismarine_bricks, {6.0, 0.0});
	trades[1316].setOut(Items::minecraft::prismarine_bricks_stairs, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/prismarine_stairs_dark.json
	trades[1317].setIn(Items::minecraft::dark_prismarine, {6.0, 0.0});
	trades[1317].setOut(Items::minecraft::dark_prismarine_stairs, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/prismarine_stairs.json
	trades[1318].setIn(Items::minecraft::prismarine, {6.0, 0.0});
	trades[1318].setOut(Items::minecraft::prismarine_stairs, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/prismarine_wall.json
	trades[1319].setIn(Items::minecraft::prismarine, {6.0, 0.0});
	trades[1319].setOut(Items::minecraft::prismarine_wall, 6.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/pumpkin_pie.json
	trades[1320].setIn(Items::minecraft::pumpkin, {1.0, 0.0});
	trades[1320].setIn(Items::minecraft::sugar, {1.0, 0.0});
	trades[1320].setIn(Items::minecraft::egg, {1.0, 0.0});
	trades[1320].setOut(Items::minecraft::pumpkin_pie, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/pumpkin_seeds.json
	trades[1321].setIn(Items::minecraft::pumpkin, {1.0, 0.0});
	trades[1321].setOut(Items::minecraft::pumpkin_seeds, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/purple_banner.json
	trades[1322].setIn(Items::minecraft::purple_wool, {6.0, 0.0});
	trades[1322].setIn(Items::minecraft::stick, {1.0, 0.0});
	trades[1322].setOut(Items::minecraft::banner, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/purple_candle.json
	trades[1323].setIn(Items::minecraft::candle, {1.0, 0.0});
	trades[1323].setIn(Items::minecraft::dye, {1.0, 0.0});
	trades[1323].setOut(Items::minecraft::purple_candle, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/purple_carpet_from_white.json
	trades[1324].setIn(Items::minecraft::white_carpet, {8.0, 0.0});
	trades[1324].setIn(Items::minecraft::purple_dye, {1.0, 0.0});
	trades[1324].setOut(Items::minecraft::purple_carpet, 8.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/purple_carpet.json
	trades[1325].setIn(Items::minecraft::purple_wool, {2.0, 0.0});
	trades[1325].setOut(Items::minecraft::purple_carpet, 3.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/purple_concrete_powder.json
	trades[1326].setIn(Items::minecraft::purple_dye, {1.0, 0.0});
	trades[1326].setIn(Items::minecraft::sand, {4.0, 0.0});
	trades[1326].setIn(Items::minecraft::gravel, {4.0, 0.0});
	trades[1326].setOut(Items::minecraft::purple_concrete_powder, 8.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/purple_dye_from_lapis_lazuli.json
	trades[1327].setIn(Items::minecraft::dye, {2.0, 0.0});
	trades[1327].setOut(Items::minecraft::dye, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/purple_dye.json
	trades[1328].setIn(Items::minecraft::dye, {2.0, 0.0});
	trades[1328].setOut(Items::minecraft::dye, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/purple_stained_glass.json
	trades[1329].setIn(Items::minecraft::glass, {8.0, 0.0});
	trades[1329].setIn(Items::minecraft::purple_dye, {1.0, 0.0});
	trades[1329].setOut(Items::minecraft::purple_stained_glass, 8.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/purple_stained_glass_pane_from_pane.json
	trades[1330].setIn(Items::minecraft::glass_pane, {8.0, 0.0});
	trades[1330].setIn(Items::minecraft::purple_dye, {1.0, 0.0});
	trades[1330].setOut(Items::minecraft::purple_stained_glass_pane, 8.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/purple_stained_glass_pane.json
	trades[1331].setIn(Items::minecraft::purple_stained_glass, {6.0, 0.0});
	trades[1331].setOut(Items::minecraft::purple_stained_glass_pane, 16.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/purple_stained_hardened_clay.json
	trades[1332].setIn(Items::minecraft::hardened_clay, {8.0, 0.0});
	trades[1332].setIn(Items::minecraft::purple_dye, {1.0, 0.0});
	trades[1332].setOut(Items::minecraft::purple_terracotta, 8.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/purpur_block.json
	trades[1333].setIn(Items::minecraft::chorus_fruit_popped, {4.0, 0.0});
	trades[1333].setOut(Items::minecraft::purpur_block, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/purpur_slab.json
	trades[1334].setIn(Items::minecraft::purpur_pillar, {3.0, 0.0});
	trades[1334].setOut(Items::minecraft::purpur_slab, 6.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/purpur_stairs.json
	trades[1335].setIn(Items::minecraft::purpur_block, {6.0, 0.0});
	trades[1335].setOut(Items::minecraft::purpur_stairs, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/quartz_block.json
	trades[1336].setIn(Items::minecraft::quartz, {4.0, 0.0});
	trades[1336].setOut(Items::minecraft::quartz_block, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/quartz_bricks.json
	trades[1337].setIn(Items::minecraft::quartz_block, {4.0, 0.0});
	trades[1337].setOut(Items::minecraft::quartz_bricks, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/quartz_pillar.json
	trades[1338].setIn(Items::minecraft::quartz_block, {2.0, 0.0});
	trades[1338].setOut(Items::minecraft::quartz_pillar, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/quartz_stairs.json
	trades[1339].setIn(Items::minecraft::quartz_block, {6.0, 0.0});
	trades[1339].setOut(Items::minecraft::quartz_stairs, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/rabbit_stew_from_brown_mushroom.json
	trades[1340].setIn(Items::minecraft::bowl, {1.0, 0.0});
	trades[1340].setIn(Items::minecraft::baked_potato, {1.0, 0.0});
	trades[1340].setIn(Items::minecraft::carrot, {1.0, 0.0});
	trades[1340].setIn(Items::minecraft::brown_mushroom, {1.0, 0.0});
	trades[1340].setIn(Items::minecraft::cooked_rabbit, {1.0, 0.0});
	trades[1340].setOut(Items::minecraft::rabbit_stew, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/rabbit_stew_from_red_mushroom.json
	trades[1341].setIn(Items::minecraft::bowl, {1.0, 0.0});
	trades[1341].setIn(Items::minecraft::baked_potato, {1.0, 0.0});
	trades[1341].setIn(Items::minecraft::carrot, {1.0, 0.0});
	trades[1341].setIn(Items::minecraft::red_mushroom, {1.0, 0.0});
	trades[1341].setIn(Items::minecraft::cooked_rabbit, {1.0, 0.0});
	trades[1341].setOut(Items::minecraft::rabbit_stew, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/rail.json
	trades[1342].setIn(Items::minecraft::stick, {1.0, 0.0});
	trades[1342].setIn(Items::minecraft::iron_ingot, {6.0, 0.0});
	trades[1342].setOut(Items::minecraft::rail, 16.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/raiser_armor_trim_smithing_template_duplicate.json
	trades[1343].setIn(Items::minecraft::raiser_armor_trim_smithing_template, {1.0, 0.0});
	trades[1343].setIn(Items::minecraft::diamond, {7.0, 0.0});
	trades[1343].setIn(Items::minecraft::hardened_clay, {1.0, 0.0});
	trades[1343].setOut(Items::minecraft::raiser_armor_trim_smithing_template, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/raw_copper_block.json
	trades[1344].setIn(Items::minecraft::raw_copper, {9.0, 0.0});
	trades[1344].setOut(Items::minecraft::raw_copper_block, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/raw_copper.json
	trades[1345].setIn(Items::minecraft::raw_copper_block, {1.0, 0.0});
	trades[1345].setOut(Items::minecraft::raw_copper, 9.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/raw_gold_block.json
	trades[1346].setIn(Items::minecraft::raw_gold, {9.0, 0.0});
	trades[1346].setOut(Items::minecraft::raw_gold_block, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/raw_gold.json
	trades[1347].setIn(Items::minecraft::raw_gold_block, {1.0, 0.0});
	trades[1347].setOut(Items::minecraft::raw_gold, 9.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/raw_iron_block.json
	trades[1348].setIn(Items::minecraft::raw_iron, {9.0, 0.0});
	trades[1348].setOut(Items::minecraft::raw_iron_block, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/raw_iron.json
	trades[1349].setIn(Items::minecraft::raw_iron_block, {1.0, 0.0});
	trades[1349].setOut(Items::minecraft::raw_iron, 9.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/record_5.json
	trades[1350].setIn(Items::minecraft::disc_fragment_5, {9.0, 0.0});
	trades[1350].setOut(Items::minecraft::record_5, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/recovery_compass_from_lodestone_compass.json
	trades[1351].setIn(Items::minecraft::echo_shard, {8.0, 0.0});
	trades[1351].setIn(Items::minecraft::lodestone_compass, {1.0, 0.0});
	trades[1351].setOut(Items::minecraft::recovery_compass, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/recovery_compass.json
	trades[1352].setIn(Items::minecraft::echo_shard, {8.0, 0.0});
	trades[1352].setIn(Items::minecraft::compass, {1.0, 0.0});
	trades[1352].setOut(Items::minecraft::recovery_compass, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/red_banner.json
	trades[1353].setIn(Items::minecraft::red_wool, {6.0, 0.0});
	trades[1353].setIn(Items::minecraft::stick, {1.0, 0.0});
	trades[1353].setOut(Items::minecraft::banner, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/red_candle.json
	trades[1354].setIn(Items::minecraft::candle, {1.0, 0.0});
	trades[1354].setIn(Items::minecraft::dye, {1.0, 0.0});
	trades[1354].setOut(Items::minecraft::red_candle, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/red_carpet_from_white.json
	trades[1355].setIn(Items::minecraft::white_carpet, {8.0, 0.0});
	trades[1355].setIn(Items::minecraft::red_dye, {1.0, 0.0});
	trades[1355].setOut(Items::minecraft::red_carpet, 8.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/red_carpet.json
	trades[1356].setIn(Items::minecraft::red_wool, {2.0, 0.0});
	trades[1356].setOut(Items::minecraft::red_carpet, 3.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/red_concrete_powder.json
	trades[1357].setIn(Items::minecraft::red_dye, {1.0, 0.0});
	trades[1357].setIn(Items::minecraft::sand, {4.0, 0.0});
	trades[1357].setIn(Items::minecraft::gravel, {4.0, 0.0});
	trades[1357].setOut(Items::minecraft::red_concrete_powder, 8.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/red_dye_from_beetroot.json
	trades[1358].setIn(Items::minecraft::beetroot, {1.0, 0.0});
	trades[1358].setOut(Items::minecraft::dye, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/red_dye_from_poppy.json
	trades[1359].setIn(Items::minecraft::poppy, {1.0, 0.0});
	trades[1359].setOut(Items::minecraft::dye, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/red_dye_from_rose_bush.json
	trades[1360].setIn(Items::minecraft::rose_bush, {1.0, 0.0});
	trades[1360].setOut(Items::minecraft::red_dye, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/red_dye_from_tulip.json
	trades[1361].setIn(Items::minecraft::red_tulip, {1.0, 0.0});
	trades[1361].setOut(Items::minecraft::dye, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/red_nether_brick.json
	trades[1362].setIn(Items::minecraft::nether_wart, {2.0, 0.0});
	trades[1362].setIn(Items::minecraft::netherbrick, {2.0, 0.0});
	trades[1362].setOut(Items::minecraft::red_nether_brick, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/red_nether_brick_stairs.json
	trades[1363].setIn(Items::minecraft::red_nether_brick, {6.0, 0.0});
	trades[1363].setOut(Items::minecraft::red_nether_brick_stairs, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/red_nether_brick_wall.json
	trades[1364].setIn(Items::minecraft::red_nether_brick, {6.0, 0.0});
	trades[1364].setOut(Items::minecraft::red_nether_brick_wall, 6.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/red_sandstone.json
	trades[1365].setIn(Items::minecraft::red_sand, {4.0, 0.0});
	trades[1365].setOut(Items::minecraft::red_sandstone, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/red_sandstone_stairs_from_chiseled.json
	trades[1366].setIn(Items::minecraft::chiseled_red_sandstone, {6.0, 0.0});
	trades[1366].setOut(Items::minecraft::red_sandstone_stairs, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/red_sandstone_stairs_from_cut.json
	trades[1367].setIn(Items::minecraft::cut_red_sandstone, {6.0, 0.0});
	trades[1367].setOut(Items::minecraft::red_sandstone_stairs, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/red_sandstone_stairs.json
	trades[1368].setIn(Items::minecraft::red_sandstone, {6.0, 0.0});
	trades[1368].setOut(Items::minecraft::red_sandstone_stairs, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/red_sandstone_wall.json
	trades[1369].setIn(Items::minecraft::red_sandstone, {6.0, 0.0});
	trades[1369].setOut(Items::minecraft::red_sandstone_wall, 6.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/red_stained_glass.json
	trades[1370].setIn(Items::minecraft::glass, {8.0, 0.0});
	trades[1370].setIn(Items::minecraft::red_dye, {1.0, 0.0});
	trades[1370].setOut(Items::minecraft::red_stained_glass, 8.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/red_stained_glass_pane_from_pane.json
	trades[1371].setIn(Items::minecraft::glass_pane, {8.0, 0.0});
	trades[1371].setIn(Items::minecraft::red_dye, {1.0, 0.0});
	trades[1371].setOut(Items::minecraft::red_stained_glass_pane, 8.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/red_stained_glass_pane.json
	trades[1372].setIn(Items::minecraft::red_stained_glass, {6.0, 0.0});
	trades[1372].setOut(Items::minecraft::red_stained_glass_pane, 16.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/red_stained_hardened_clay.json
	trades[1373].setIn(Items::minecraft::hardened_clay, {8.0, 0.0});
	trades[1373].setIn(Items::minecraft::red_dye, {1.0, 0.0});
	trades[1373].setOut(Items::minecraft::red_terracotta, 8.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/redstone_block.json
	trades[1374].setIn(Items::minecraft::redstone, {9.0, 0.0});
	trades[1374].setOut(Items::minecraft::redstone_block, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/redstone.json
	trades[1375].setIn(Items::minecraft::redstone_block, {1.0, 0.0});
	trades[1375].setOut(Items::minecraft::redstone, 9.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/redstone_lamp.json
	trades[1376].setIn(Items::minecraft::redstone, {4.0, 0.0});
	trades[1376].setIn(Items::minecraft::glowstone, {1.0, 0.0});
	trades[1376].setOut(Items::minecraft::redstone_lamp, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/redstone_torch.json
	trades[1377].setIn(Items::minecraft::stick, {1.0, 0.0});
	trades[1377].setIn(Items::minecraft::redstone, {1.0, 0.0});
	trades[1377].setOut(Items::minecraft::redstone_torch, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/repeater.json
	trades[1378].setIn(Items::minecraft::redstone_torch, {2.0, 0.0});
	trades[1378].setIn(Items::minecraft::redstone, {1.0, 0.0});
	trades[1378].setIn(Items::minecraft::stone, {3.0, 0.0});
	trades[1378].setOut(Items::minecraft::repeater, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/resin_block.json
	trades[1379].setIn(Items::minecraft::resin_clump, {9.0, 0.0});
	trades[1379].setOut(Items::minecraft::resin_block, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/resin_bricks.json
	trades[1380].setIn(Items::minecraft::resin_brick, {4.0, 0.0});
	trades[1380].setOut(Items::minecraft::resin_bricks, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/resin_brick_slab.json
	trades[1381].setIn(Items::minecraft::resin_bricks, {3.0, 0.0});
	trades[1381].setOut(Items::minecraft::resin_brick_slab, 6.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/resin_brick_stairs.json
	trades[1382].setIn(Items::minecraft::resin_bricks, {6.0, 0.0});
	trades[1382].setOut(Items::minecraft::resin_brick_stairs, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/resin_brick_wall.json
	trades[1383].setIn(Items::minecraft::resin_bricks, {6.0, 0.0});
	trades[1383].setOut(Items::minecraft::resin_brick_wall, 6.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/resin_clump_from_resin_block.json
	trades[1384].setIn(Items::minecraft::resin_block, {1.0, 0.0});
	trades[1384].setOut(Items::minecraft::resin_clump, 9.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/respawn_anchor.json
	trades[1385].setIn(Items::minecraft::crying_obsidian, {6.0, 0.0});
	trades[1385].setIn(Items::minecraft::glowstone, {3.0, 0.0});
	trades[1385].setOut(Items::minecraft::respawn_anchor, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/rib_armor_trim_smithing_template_duplicate.json
	trades[1386].setIn(Items::minecraft::rib_armor_trim_smithing_template, {1.0, 0.0});
	trades[1386].setIn(Items::minecraft::diamond, {7.0, 0.0});
	trades[1386].setIn(Items::minecraft::netherrack, {1.0, 0.0});
	trades[1386].setOut(Items::minecraft::rib_armor_trim_smithing_template, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/sandstone.json
	trades[1387].setIn(Items::minecraft::sand, {4.0, 0.0});
	trades[1387].setOut(Items::minecraft::sandstone, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/sandstone_stairs_from_chiseled.json
	trades[1388].setIn(Items::minecraft::chiseled_sandstone, {6.0, 0.0});
	trades[1388].setOut(Items::minecraft::sandstone_stairs, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/sandstone_stairs_from_cut.json
	trades[1389].setIn(Items::minecraft::cut_sandstone, {6.0, 0.0});
	trades[1389].setOut(Items::minecraft::sandstone_stairs, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/sandstone_stairs.json
	trades[1390].setIn(Items::minecraft::sandstone, {6.0, 0.0});
	trades[1390].setOut(Items::minecraft::sandstone_stairs, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/sandstone_wall.json
	trades[1391].setIn(Items::minecraft::sandstone, {6.0, 0.0});
	trades[1391].setOut(Items::minecraft::sandstone_wall, 6.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/scaffolding.json
	trades[1392].setIn(Items::minecraft::bamboo, {6.0, 0.0});
	trades[1392].setIn(Items::minecraft::string, {1.0, 0.0});
	trades[1392].setOut(Items::minecraft::scaffolding, 6.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/sealantern.json
	trades[1393].setIn(Items::minecraft::prismarine_shard, {4.0, 0.0});
	trades[1393].setIn(Items::minecraft::prismarine_crystals, {5.0, 0.0});
	trades[1393].setOut(Items::minecraft::sealantern, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/sentry_armor_trim_smithing_template_duplicate.json
	trades[1394].setIn(Items::minecraft::sentry_armor_trim_smithing_template, {1.0, 0.0});
	trades[1394].setIn(Items::minecraft::diamond, {7.0, 0.0});
	trades[1394].setIn(Items::minecraft::cobblestone, {1.0, 0.0});
	trades[1394].setOut(Items::minecraft::sentry_armor_trim_smithing_template, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/shaper_armor_trim_smithing_template_duplicate.json
	trades[1395].setIn(Items::minecraft::shaper_armor_trim_smithing_template, {1.0, 0.0});
	trades[1395].setIn(Items::minecraft::diamond, {7.0, 0.0});
	trades[1395].setIn(Items::minecraft::hardened_clay, {1.0, 0.0});
	trades[1395].setOut(Items::minecraft::shaper_armor_trim_smithing_template, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/shears.json
	trades[1396].setIn(Items::minecraft::iron_ingot, {2.0, 0.0});
	trades[1396].setOut(Items::minecraft::shears, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/shield_from_crimson_planks.json
	trades[1397].setIn(Items::minecraft::crimson_planks, {6.0, 0.0});
	trades[1397].setIn(Items::minecraft::iron_ingot, {1.0, 0.0});
	trades[1397].setOut(Items::minecraft::shield, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/shield_from_mangrove_planks.json
	trades[1398].setIn(Items::minecraft::mangrove_planks, {6.0, 0.0});
	trades[1398].setIn(Items::minecraft::iron_ingot, {1.0, 0.0});
	trades[1398].setOut(Items::minecraft::shield, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/shield_from_warped_planks.json
	trades[1399].setIn(Items::minecraft::warped_planks, {6.0, 0.0});
	trades[1399].setIn(Items::minecraft::iron_ingot, {1.0, 0.0});
	trades[1399].setOut(Items::minecraft::shield, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/shield.json
	trades[1400].setIn(Items::minecraft::planks, {6.0, 0.0});
	trades[1400].setIn(Items::minecraft::iron_ingot, {1.0, 0.0});
	trades[1400].setOut(Items::minecraft::shield, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/shulker_box.json
	trades[1401].setIn(Items::minecraft::chest, {1.0, 0.0});
	trades[1401].setIn(Items::minecraft::shulker_shell, {2.0, 0.0});
	trades[1401].setOut(Items::minecraft::undyed_shulker_box, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/sign_acacia.json
	trades[1402].setIn(Items::minecraft::acacia_planks, {6.0, 0.0});
	trades[1402].setIn(Items::minecraft::stick, {1.0, 0.0});
	trades[1402].setOut(Items::minecraft::acacia_sign, 3.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/sign_birch.json
	trades[1403].setIn(Items::minecraft::birch_planks, {6.0, 0.0});
	trades[1403].setIn(Items::minecraft::stick, {1.0, 0.0});
	trades[1403].setOut(Items::minecraft::birch_sign, 3.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/sign_darkoak.json
	trades[1404].setIn(Items::minecraft::dark_oak_planks, {6.0, 0.0});
	trades[1404].setIn(Items::minecraft::stick, {1.0, 0.0});
	trades[1404].setOut(Items::minecraft::darkoak_sign, 3.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/sign_jungle.json
	trades[1405].setIn(Items::minecraft::jungle_planks, {6.0, 0.0});
	trades[1405].setIn(Items::minecraft::stick, {1.0, 0.0});
	trades[1405].setOut(Items::minecraft::jungle_sign, 3.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/sign_oak.json
	trades[1406].setIn(Items::minecraft::oak_planks, {6.0, 0.0});
	trades[1406].setIn(Items::minecraft::stick, {1.0, 0.0});
	trades[1406].setOut(Items::minecraft::sign, 3.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/sign_spruce.json
	trades[1407].setIn(Items::minecraft::spruce_planks, {6.0, 0.0});
	trades[1407].setIn(Items::minecraft::stick, {1.0, 0.0});
	trades[1407].setOut(Items::minecraft::spruce_sign, 3.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/silence_armor_trim_smithing_template_duplicate.json
	trades[1408].setIn(Items::minecraft::silence_armor_trim_smithing_template, {1.0, 0.0});
	trades[1408].setIn(Items::minecraft::diamond, {7.0, 0.0});
	trades[1408].setIn(Items::minecraft::cobbled_deepslate, {1.0, 0.0});
	trades[1408].setOut(Items::minecraft::silence_armor_trim_smithing_template, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/slime_ball.json
	trades[1409].setIn(Items::minecraft::slime, {1.0, 0.0});
	trades[1409].setOut(Items::minecraft::slime_ball, 9.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/slime.json
	trades[1410].setIn(Items::minecraft::slime_ball, {9.0, 0.0});
	trades[1410].setOut(Items::minecraft::slime, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/smithing_armor_trim.json
	trades[1411].setIn(Items::minecraft::trimmable_armors, {1.0, 0.0});
	trades[1411].setIn(Items::minecraft::trim_materials, {1.0, 0.0});
	trades[1411].setOut(Items::minecraft::trim_templates, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/smithing_netherite_axe.json
	trades[1412].setIn(Items::minecraft::diamond_axe, {1.0, 0.0});
	trades[1412].setIn(Items::minecraft::netherite_ingot, {1.0, 0.0});
	trades[1412].setOut(Items::minecraft::netherite_axe, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/smithing_netherite_boots.json
	trades[1413].setIn(Items::minecraft::diamond_boots, {1.0, 0.0});
	trades[1413].setIn(Items::minecraft::netherite_ingot, {1.0, 0.0});
	trades[1413].setOut(Items::minecraft::netherite_boots, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/smithing_netherite_chestplate.json
	trades[1414].setIn(Items::minecraft::diamond_chestplate, {1.0, 0.0});
	trades[1414].setIn(Items::minecraft::netherite_ingot, {1.0, 0.0});
	trades[1414].setOut(Items::minecraft::netherite_chestplate, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/smithing_netherite_helmet.json
	trades[1415].setIn(Items::minecraft::diamond_helmet, {1.0, 0.0});
	trades[1415].setIn(Items::minecraft::netherite_ingot, {1.0, 0.0});
	trades[1415].setOut(Items::minecraft::netherite_helmet, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/smithing_netherite_hoe.json
	trades[1416].setIn(Items::minecraft::diamond_hoe, {1.0, 0.0});
	trades[1416].setIn(Items::minecraft::netherite_ingot, {1.0, 0.0});
	trades[1416].setOut(Items::minecraft::netherite_hoe, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/smithing_netherite_leggings.json
	trades[1417].setIn(Items::minecraft::diamond_leggings, {1.0, 0.0});
	trades[1417].setIn(Items::minecraft::netherite_ingot, {1.0, 0.0});
	trades[1417].setOut(Items::minecraft::netherite_leggings, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/smithing_netherite_pickaxe.json
	trades[1418].setIn(Items::minecraft::diamond_pickaxe, {1.0, 0.0});
	trades[1418].setIn(Items::minecraft::netherite_ingot, {1.0, 0.0});
	trades[1418].setOut(Items::minecraft::netherite_pickaxe, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/smithing_netherite_shovel.json
	trades[1419].setIn(Items::minecraft::diamond_shovel, {1.0, 0.0});
	trades[1419].setIn(Items::minecraft::netherite_ingot, {1.0, 0.0});
	trades[1419].setOut(Items::minecraft::netherite_shovel, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/smithing_netherite_sword.json
	trades[1420].setIn(Items::minecraft::diamond_sword, {1.0, 0.0});
	trades[1420].setIn(Items::minecraft::netherite_ingot, {1.0, 0.0});
	trades[1420].setOut(Items::minecraft::netherite_sword, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/smithing_table_from_crimson_planks.json
	trades[1421].setIn(Items::minecraft::iron_ingot, {2.0, 0.0});
	trades[1421].setIn(Items::minecraft::crimson_planks, {4.0, 0.0});
	trades[1421].setOut(Items::minecraft::smithing_table, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/smithing_table_from_mangrove_planks.json
	trades[1422].setIn(Items::minecraft::iron_ingot, {2.0, 0.0});
	trades[1422].setIn(Items::minecraft::mangrove_planks, {4.0, 0.0});
	trades[1422].setOut(Items::minecraft::smithing_table, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/smithing_table_from_warped_planks.json
	trades[1423].setIn(Items::minecraft::iron_ingot, {2.0, 0.0});
	trades[1423].setIn(Items::minecraft::warped_planks, {4.0, 0.0});
	trades[1423].setOut(Items::minecraft::smithing_table, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/smithing_table.json
	trades[1424].setIn(Items::minecraft::iron_ingot, {2.0, 0.0});
	trades[1424].setIn(Items::minecraft::planks, {4.0, 0.0});
	trades[1424].setOut(Items::minecraft::smithing_table, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/smoker_from_crimson_stem.json
	trades[1425].setIn(Items::minecraft::crimson_stem, {4.0, 0.0});
	trades[1425].setIn(Items::minecraft::furnace, {1.0, 0.0});
	trades[1425].setOut(Items::minecraft::smoker, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/smoker_from_log2.json
	trades[1426].setIn(Items::minecraft::furnace, {1.0, 0.0});
	trades[1426].setIn(Items::minecraft::log2, {4.0, 0.0});
	trades[1426].setOut(Items::minecraft::smoker, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/smoker_from_mangrove_log.json
	trades[1427].setIn(Items::minecraft::mangrove_log, {4.0, 0.0});
	trades[1427].setIn(Items::minecraft::furnace, {1.0, 0.0});
	trades[1427].setOut(Items::minecraft::smoker, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/smoker_from_mangrove_wood.json
	trades[1428].setIn(Items::minecraft::mangrove_wood, {4.0, 0.0});
	trades[1428].setIn(Items::minecraft::furnace, {1.0, 0.0});
	trades[1428].setOut(Items::minecraft::smoker, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/smoker_from_stripped_acacia.json
	trades[1429].setIn(Items::minecraft::furnace, {1.0, 0.0});
	trades[1429].setIn(Items::minecraft::stripped_acacia_log, {4.0, 0.0});
	trades[1429].setOut(Items::minecraft::smoker, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/smoker_from_stripped_birch.json
	trades[1430].setIn(Items::minecraft::furnace, {1.0, 0.0});
	trades[1430].setIn(Items::minecraft::stripped_birch_log, {4.0, 0.0});
	trades[1430].setOut(Items::minecraft::smoker, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/smoker_from_stripped_crimson_stem.json
	trades[1431].setIn(Items::minecraft::stripped_crimson_stem, {4.0, 0.0});
	trades[1431].setIn(Items::minecraft::furnace, {1.0, 0.0});
	trades[1431].setOut(Items::minecraft::smoker, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/smoker_from_stripped_dark_oak.json
	trades[1432].setIn(Items::minecraft::furnace, {1.0, 0.0});
	trades[1432].setIn(Items::minecraft::stripped_dark_oak_log, {4.0, 0.0});
	trades[1432].setOut(Items::minecraft::smoker, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/smoker_from_stripped_jungle.json
	trades[1433].setIn(Items::minecraft::furnace, {1.0, 0.0});
	trades[1433].setIn(Items::minecraft::stripped_jungle_log, {4.0, 0.0});
	trades[1433].setOut(Items::minecraft::smoker, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/smoker_from_stripped_mangrove_log.json
	trades[1434].setIn(Items::minecraft::furnace, {1.0, 0.0});
	trades[1434].setIn(Items::minecraft::stripped_mangrove_log, {4.0, 0.0});
	trades[1434].setOut(Items::minecraft::smoker, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/smoker_from_stripped_mangrove_wood.json
	trades[1435].setIn(Items::minecraft::stripped_mangrove_wood, {4.0, 0.0});
	trades[1435].setIn(Items::minecraft::furnace, {1.0, 0.0});
	trades[1435].setOut(Items::minecraft::smoker, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/smoker_from_stripped_oak.json
	trades[1436].setIn(Items::minecraft::furnace, {1.0, 0.0});
	trades[1436].setIn(Items::minecraft::stripped_oak_log, {4.0, 0.0});
	trades[1436].setOut(Items::minecraft::smoker, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/smoker_from_stripped_spruce.json
	trades[1437].setIn(Items::minecraft::furnace, {1.0, 0.0});
	trades[1437].setIn(Items::minecraft::stripped_spruce_log, {4.0, 0.0});
	trades[1437].setOut(Items::minecraft::smoker, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/smoker_from_stripped_warped_stem.json
	trades[1438].setIn(Items::minecraft::stripped_warped_stem, {4.0, 0.0});
	trades[1438].setIn(Items::minecraft::furnace, {1.0, 0.0});
	trades[1438].setOut(Items::minecraft::smoker, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/smoker_from_warped_stem.json
	trades[1439].setIn(Items::minecraft::warped_stem, {4.0, 0.0});
	trades[1439].setIn(Items::minecraft::furnace, {1.0, 0.0});
	trades[1439].setOut(Items::minecraft::smoker, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/smoker.json
	trades[1440].setIn(Items::minecraft::furnace, {1.0, 0.0});
	trades[1440].setIn(Items::minecraft::logs, {4.0, 0.0});
	trades[1440].setOut(Items::minecraft::smoker, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/smooth_quartz_stairs.json
	trades[1441].setIn(Items::minecraft::smooth_quartz, {6.0, 0.0});
	trades[1441].setOut(Items::minecraft::smooth_quartz_stairs, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/smooth_red_sandstone.json
	trades[1442].setIn(Items::minecraft::red_sandstone, {4.0, 0.0});
	trades[1442].setOut(Items::minecraft::cut_red_sandstone, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/smooth_red_sandstone_stairs.json
	trades[1443].setIn(Items::minecraft::smooth_red_sandstone, {6.0, 0.0});
	trades[1443].setOut(Items::minecraft::smooth_red_sandstone_stairs, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/smooth_sandstone.json
	trades[1444].setIn(Items::minecraft::sandstone, {4.0, 0.0});
	trades[1444].setOut(Items::minecraft::cut_sandstone, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/smooth_sandstone_stairs.json
	trades[1445].setIn(Items::minecraft::smooth_sandstone, {6.0, 0.0});
	trades[1445].setOut(Items::minecraft::smooth_sandstone_stairs, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/snout_armor_trim_smithing_template_duplicate.json
	trades[1446].setIn(Items::minecraft::snout_armor_trim_smithing_template, {1.0, 0.0});
	trades[1446].setIn(Items::minecraft::diamond, {7.0, 0.0});
	trades[1446].setIn(Items::minecraft::blackstone, {1.0, 0.0});
	trades[1446].setOut(Items::minecraft::snout_armor_trim_smithing_template, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/snow.json
	trades[1447].setIn(Items::minecraft::snowball, {4.0, 0.0});
	trades[1447].setOut(Items::minecraft::snow, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/snow_layer.json
	trades[1448].setIn(Items::minecraft::snow, {3.0, 0.0});
	trades[1448].setOut(Items::minecraft::snow_layer, 6.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/soul_campfire_from_crimson_stem2.json
	trades[1449].setIn(Items::minecraft::stick, {3.0, 0.0});
	trades[1449].setIn(Items::minecraft::soul_sand, {1.0, 0.0});
	trades[1449].setIn(Items::minecraft::crimson_stem, {3.0, 0.0});
	trades[1449].setOut(Items::minecraft::soul_campfire, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/soul_campfire_from_crimson_stem.json
	trades[1450].setIn(Items::minecraft::stick, {3.0, 0.0});
	trades[1450].setIn(Items::minecraft::soul_soil, {1.0, 0.0});
	trades[1450].setIn(Items::minecraft::crimson_stem, {3.0, 0.0});
	trades[1450].setOut(Items::minecraft::soul_campfire, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/soul_campfire_from_mangrove_log2.json
	trades[1451].setIn(Items::minecraft::stick, {3.0, 0.0});
	trades[1451].setIn(Items::minecraft::soul_sand, {1.0, 0.0});
	trades[1451].setIn(Items::minecraft::mangrove_log, {3.0, 0.0});
	trades[1451].setOut(Items::minecraft::soul_campfire, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/soul_campfire_from_mangrove_log.json
	trades[1452].setIn(Items::minecraft::stick, {3.0, 0.0});
	trades[1452].setIn(Items::minecraft::soul_soil, {1.0, 0.0});
	trades[1452].setIn(Items::minecraft::mangrove_log, {3.0, 0.0});
	trades[1452].setOut(Items::minecraft::soul_campfire, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/soul_campfire_from_mangrove_wood2.json
	trades[1453].setIn(Items::minecraft::stick, {3.0, 0.0});
	trades[1453].setIn(Items::minecraft::soul_sand, {1.0, 0.0});
	trades[1453].setIn(Items::minecraft::mangrove_wood, {3.0, 0.0});
	trades[1453].setOut(Items::minecraft::soul_campfire, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/soul_campfire_from_mangrove_wood.json
	trades[1454].setIn(Items::minecraft::stick, {3.0, 0.0});
	trades[1454].setIn(Items::minecraft::soul_soil, {1.0, 0.0});
	trades[1454].setIn(Items::minecraft::mangrove_wood, {3.0, 0.0});
	trades[1454].setOut(Items::minecraft::soul_campfire, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/soul_campfire_from_soul_sand_and_log2.json
	trades[1455].setIn(Items::minecraft::stick, {3.0, 0.0});
	trades[1455].setIn(Items::minecraft::soul_sand, {1.0, 0.0});
	trades[1455].setIn(Items::minecraft::log2, {3.0, 0.0});
	trades[1455].setOut(Items::minecraft::soul_campfire, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/soul_campfire_from_soul_sand_and_stripped_acacia_log.json
	trades[1456].setIn(Items::minecraft::stick, {3.0, 0.0});
	trades[1456].setIn(Items::minecraft::soul_sand, {1.0, 0.0});
	trades[1456].setIn(Items::minecraft::stripped_acacia_log, {3.0, 0.0});
	trades[1456].setOut(Items::minecraft::soul_campfire, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/soul_campfire_from_soul_sand_and_stripped_birch_log.json
	trades[1457].setIn(Items::minecraft::stick, {3.0, 0.0});
	trades[1457].setIn(Items::minecraft::soul_sand, {1.0, 0.0});
	trades[1457].setIn(Items::minecraft::stripped_birch_log, {3.0, 0.0});
	trades[1457].setOut(Items::minecraft::soul_campfire, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/soul_campfire_from_soul_sand_and_stripped_dark_oak_log.json
	trades[1458].setIn(Items::minecraft::stick, {3.0, 0.0});
	trades[1458].setIn(Items::minecraft::soul_sand, {1.0, 0.0});
	trades[1458].setIn(Items::minecraft::stripped_dark_oak_log, {3.0, 0.0});
	trades[1458].setOut(Items::minecraft::soul_campfire, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/soul_campfire_from_soul_sand_and_stripped_jungle_log.json
	trades[1459].setIn(Items::minecraft::stick, {3.0, 0.0});
	trades[1459].setIn(Items::minecraft::soul_sand, {1.0, 0.0});
	trades[1459].setIn(Items::minecraft::stripped_jungle_log, {3.0, 0.0});
	trades[1459].setOut(Items::minecraft::soul_campfire, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/soul_campfire_from_soul_sand_and_stripped_oak_log.json
	trades[1460].setIn(Items::minecraft::stick, {3.0, 0.0});
	trades[1460].setIn(Items::minecraft::soul_sand, {1.0, 0.0});
	trades[1460].setIn(Items::minecraft::stripped_oak_log, {3.0, 0.0});
	trades[1460].setOut(Items::minecraft::soul_campfire, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/soul_campfire_from_soul_sand_and_stripped_spruce_log.json
	trades[1461].setIn(Items::minecraft::stick, {3.0, 0.0});
	trades[1461].setIn(Items::minecraft::soul_sand, {1.0, 0.0});
	trades[1461].setIn(Items::minecraft::stripped_spruce_log, {3.0, 0.0});
	trades[1461].setOut(Items::minecraft::soul_campfire, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/soul_campfire_from_soul_sand_and_wood.json
	trades[1462].setIn(Items::minecraft::stick, {3.0, 0.0});
	trades[1462].setIn(Items::minecraft::soul_sand, {1.0, 0.0});
	trades[1462].setIn(Items::minecraft::wood, {3.0, 0.0});
	trades[1462].setOut(Items::minecraft::soul_campfire, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/soul_campfire_from_soul_sand.json
	trades[1463].setIn(Items::minecraft::stick, {3.0, 0.0});
	trades[1463].setIn(Items::minecraft::soul_sand, {1.0, 0.0});
	trades[1463].setIn(Items::minecraft::log, {3.0, 0.0});
	trades[1463].setOut(Items::minecraft::soul_campfire, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/soul_campfire_from_soul_soil_and_log2.json
	trades[1464].setIn(Items::minecraft::stick, {3.0, 0.0});
	trades[1464].setIn(Items::minecraft::soul_soil, {1.0, 0.0});
	trades[1464].setIn(Items::minecraft::log2, {3.0, 0.0});
	trades[1464].setOut(Items::minecraft::soul_campfire, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/soul_campfire_from_soul_soil_and_stripped_acacia_log.json
	trades[1465].setIn(Items::minecraft::stick, {3.0, 0.0});
	trades[1465].setIn(Items::minecraft::soul_soil, {1.0, 0.0});
	trades[1465].setIn(Items::minecraft::stripped_acacia_log, {3.0, 0.0});
	trades[1465].setOut(Items::minecraft::soul_campfire, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/soul_campfire_from_soul_soil_and_stripped_birch_log.json
	trades[1466].setIn(Items::minecraft::stick, {3.0, 0.0});
	trades[1466].setIn(Items::minecraft::soul_soil, {1.0, 0.0});
	trades[1466].setIn(Items::minecraft::stripped_birch_log, {3.0, 0.0});
	trades[1466].setOut(Items::minecraft::soul_campfire, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/soul_campfire_from_soul_soil_and_stripped_dark_oak_log.json
	trades[1467].setIn(Items::minecraft::stick, {3.0, 0.0});
	trades[1467].setIn(Items::minecraft::soul_soil, {1.0, 0.0});
	trades[1467].setIn(Items::minecraft::stripped_dark_oak_log, {3.0, 0.0});
	trades[1467].setOut(Items::minecraft::soul_campfire, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/soul_campfire_from_soul_soil_and_stripped_jungle_log.json
	trades[1468].setIn(Items::minecraft::stick, {3.0, 0.0});
	trades[1468].setIn(Items::minecraft::soul_soil, {1.0, 0.0});
	trades[1468].setIn(Items::minecraft::stripped_jungle_log, {3.0, 0.0});
	trades[1468].setOut(Items::minecraft::soul_campfire, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/soul_campfire_from_soul_soil_and_stripped_oak_log.json
	trades[1469].setIn(Items::minecraft::stick, {3.0, 0.0});
	trades[1469].setIn(Items::minecraft::soul_soil, {1.0, 0.0});
	trades[1469].setIn(Items::minecraft::stripped_oak_log, {3.0, 0.0});
	trades[1469].setOut(Items::minecraft::soul_campfire, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/soul_campfire_from_soul_soil_and_stripped_spruce_log.json
	trades[1470].setIn(Items::minecraft::stick, {3.0, 0.0});
	trades[1470].setIn(Items::minecraft::soul_soil, {1.0, 0.0});
	trades[1470].setIn(Items::minecraft::stripped_spruce_log, {3.0, 0.0});
	trades[1470].setOut(Items::minecraft::soul_campfire, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/soul_campfire_from_soul_soil_and_wood.json
	trades[1471].setIn(Items::minecraft::stick, {3.0, 0.0});
	trades[1471].setIn(Items::minecraft::soul_soil, {1.0, 0.0});
	trades[1471].setIn(Items::minecraft::wood, {3.0, 0.0});
	trades[1471].setOut(Items::minecraft::soul_campfire, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/soul_campfire_from_soul_soil.json
	trades[1472].setIn(Items::minecraft::stick, {3.0, 0.0});
	trades[1472].setIn(Items::minecraft::soul_soil, {1.0, 0.0});
	trades[1472].setIn(Items::minecraft::log, {3.0, 0.0});
	trades[1472].setOut(Items::minecraft::soul_campfire, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/soul_campfire_from_stripped_crimson_stem2.json
	trades[1473].setIn(Items::minecraft::stick, {3.0, 0.0});
	trades[1473].setIn(Items::minecraft::soul_sand, {1.0, 0.0});
	trades[1473].setIn(Items::minecraft::stripped_crimson_stem, {3.0, 0.0});
	trades[1473].setOut(Items::minecraft::soul_campfire, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/soul_campfire_from_stripped_crimson_stem.json
	trades[1474].setIn(Items::minecraft::stick, {3.0, 0.0});
	trades[1474].setIn(Items::minecraft::soul_soil, {1.0, 0.0});
	trades[1474].setIn(Items::minecraft::stripped_crimson_stem, {3.0, 0.0});
	trades[1474].setOut(Items::minecraft::soul_campfire, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/soul_campfire_from_stripped_mangrove_log2.json
	trades[1475].setIn(Items::minecraft::stick, {3.0, 0.0});
	trades[1475].setIn(Items::minecraft::soul_sand, {1.0, 0.0});
	trades[1475].setIn(Items::minecraft::stripped_mangrove_log, {3.0, 0.0});
	trades[1475].setOut(Items::minecraft::soul_campfire, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/soul_campfire_from_stripped_mangrove_log.json
	trades[1476].setIn(Items::minecraft::stick, {3.0, 0.0});
	trades[1476].setIn(Items::minecraft::soul_soil, {1.0, 0.0});
	trades[1476].setIn(Items::minecraft::stripped_mangrove_log, {3.0, 0.0});
	trades[1476].setOut(Items::minecraft::soul_campfire, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/soul_campfire_from_stripped_mangrove_wood2.json
	trades[1477].setIn(Items::minecraft::stick, {3.0, 0.0});
	trades[1477].setIn(Items::minecraft::soul_sand, {1.0, 0.0});
	trades[1477].setIn(Items::minecraft::stripped_mangrove_wood, {3.0, 0.0});
	trades[1477].setOut(Items::minecraft::soul_campfire, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/soul_campfire_from_stripped_mangrove_wood.json
	trades[1478].setIn(Items::minecraft::stick, {3.0, 0.0});
	trades[1478].setIn(Items::minecraft::soul_soil, {1.0, 0.0});
	trades[1478].setIn(Items::minecraft::stripped_mangrove_wood, {3.0, 0.0});
	trades[1478].setOut(Items::minecraft::soul_campfire, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/soul_campfire_from_stripped_warped_stem2.json
	trades[1479].setIn(Items::minecraft::stick, {3.0, 0.0});
	trades[1479].setIn(Items::minecraft::soul_sand, {1.0, 0.0});
	trades[1479].setIn(Items::minecraft::stripped_warped_stem, {3.0, 0.0});
	trades[1479].setOut(Items::minecraft::soul_campfire, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/soul_campfire_from_stripped_warped_stem.json
	trades[1480].setIn(Items::minecraft::stick, {3.0, 0.0});
	trades[1480].setIn(Items::minecraft::soul_soil, {1.0, 0.0});
	trades[1480].setIn(Items::minecraft::stripped_warped_stem, {3.0, 0.0});
	trades[1480].setOut(Items::minecraft::soul_campfire, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/soul_campfire_from_warped_stem2.json
	trades[1481].setIn(Items::minecraft::stick, {3.0, 0.0});
	trades[1481].setIn(Items::minecraft::soul_sand, {1.0, 0.0});
	trades[1481].setIn(Items::minecraft::warped_stem, {3.0, 0.0});
	trades[1481].setOut(Items::minecraft::soul_campfire, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/soul_campfire_from_warped_stem.json
	trades[1482].setIn(Items::minecraft::stick, {3.0, 0.0});
	trades[1482].setIn(Items::minecraft::soul_soil, {1.0, 0.0});
	trades[1482].setIn(Items::minecraft::warped_stem, {3.0, 0.0});
	trades[1482].setOut(Items::minecraft::soul_campfire, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/soul_campfire.json
	trades[1483].setIn(Items::minecraft::stick, {3.0, 0.0});
	trades[1483].setIn(Items::minecraft::soul_fire_base_blocks, {1.0, 0.0});
	trades[1483].setIn(Items::minecraft::logs, {3.0, 0.0});
	trades[1483].setOut(Items::minecraft::soul_campfire, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/soul_lantern.json
	trades[1484].setIn(Items::minecraft::soul_torch, {1.0, 0.0});
	trades[1484].setIn(Items::minecraft::iron_nugget, {8.0, 0.0});
	trades[1484].setOut(Items::minecraft::soul_lantern, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/soul_torch_from_soul_sand.json
	trades[1485].setIn(Items::minecraft::coal, {1.0, 0.0});
	trades[1485].setIn(Items::minecraft::stick, {1.0, 0.0});
	trades[1485].setIn(Items::minecraft::soul_sand, {1.0, 0.0});
	trades[1485].setOut(Items::minecraft::soul_torch, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/soul_torch_from_soul_soil.json
	trades[1486].setIn(Items::minecraft::coal, {1.0, 0.0});
	trades[1486].setIn(Items::minecraft::stick, {1.0, 0.0});
	trades[1486].setIn(Items::minecraft::soul_soil, {1.0, 0.0});
	trades[1486].setOut(Items::minecraft::soul_torch, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/soul_torch.json
	trades[1487].setIn(Items::minecraft::coals, {1.0, 0.0});
	trades[1487].setIn(Items::minecraft::stick, {1.0, 0.0});
	trades[1487].setIn(Items::minecraft::soul_fire_base_blocks, {1.0, 0.0});
	trades[1487].setOut(Items::minecraft::soul_torch, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/speckled_melon.json
	trades[1488].setIn(Items::minecraft::gold_nugget, {8.0, 0.0});
	trades[1488].setIn(Items::minecraft::melon, {1.0, 0.0});
	trades[1488].setOut(Items::minecraft::speckled_melon, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/spire_armor_trim_smithing_template_duplicate.json
	trades[1489].setIn(Items::minecraft::spire_armor_trim_smithing_template, {1.0, 0.0});
	trades[1489].setIn(Items::minecraft::diamond, {7.0, 0.0});
	trades[1489].setIn(Items::minecraft::purpur_block, {1.0, 0.0});
	trades[1489].setOut(Items::minecraft::spire_armor_trim_smithing_template, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/spruce_boat.json
	trades[1490].setIn(Items::minecraft::spruce_planks, {5.0, 0.0});
	trades[1490].setOut(Items::minecraft::spruce_boat, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/spruce_chest_boat.json
	trades[1491].setIn(Items::minecraft::chest, {1.0, 0.0});
	trades[1491].setIn(Items::minecraft::boat, {1.0, 0.0});
	trades[1491].setOut(Items::minecraft::chest_boat, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/spruce_door.json
	trades[1492].setIn(Items::minecraft::spruce_planks, {6.0, 0.0});
	trades[1492].setOut(Items::minecraft::spruce_door, 3.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/spruce_fence_gate.json
	trades[1493].setIn(Items::minecraft::stick, {4.0, 0.0});
	trades[1493].setIn(Items::minecraft::spruce_planks, {2.0, 0.0});
	trades[1493].setOut(Items::minecraft::spruce_fence_gate, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/spruce_fence.json
	trades[1494].setIn(Items::minecraft::stick, {2.0, 0.0});
	trades[1494].setIn(Items::minecraft::spruce_planks, {4.0, 0.0});
	trades[1494].setOut(Items::minecraft::spruce_fence, 3.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/spruce_hanging_sign.json
	trades[1495].setIn(Items::minecraft::stripped_spruce_log, {6.0, 0.0});
	trades[1495].setIn(Items::minecraft::chain, {2.0, 0.0});
	trades[1495].setOut(Items::minecraft::spruce_hanging_sign, 6.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/spruce_planks_from_stripped.json
	trades[1496].setIn(Items::minecraft::stripped_spruce_log, {1.0, 0.0});
	trades[1496].setOut(Items::minecraft::spruce_planks, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/spruce_planks_from_stripped_wood.json
	trades[1497].setIn(Items::minecraft::stripped_spruce_wood, {1.0, 0.0});
	trades[1497].setOut(Items::minecraft::spruce_planks, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/spruce_planks_from_wood.json
	trades[1498].setIn(Items::minecraft::spruce_wood, {1.0, 0.0});
	trades[1498].setOut(Items::minecraft::spruce_planks, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/spruce_planks.json
	trades[1499].setIn(Items::minecraft::spruce_log, {1.0, 0.0});
	trades[1499].setOut(Items::minecraft::spruce_planks, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/spruce_stairs.json
	trades[1500].setIn(Items::minecraft::spruce_planks, {6.0, 0.0});
	trades[1500].setOut(Items::minecraft::spruce_stairs, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/spruce_wooden_slab.json
	trades[1501].setIn(Items::minecraft::spruce_planks, {3.0, 0.0});
	trades[1501].setOut(Items::minecraft::spruce_slab, 6.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/spruce_wood.json
	trades[1502].setIn(Items::minecraft::spruce_log, {4.0, 0.0});
	trades[1502].setOut(Items::minecraft::spruce_wood, 3.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/spruce_wood_stripped.json
	trades[1503].setIn(Items::minecraft::stripped_spruce_log, {4.0, 0.0});
	trades[1503].setOut(Items::minecraft::stripped_spruce_wood, 3.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/spyglass.json
	trades[1504].setIn(Items::minecraft::amethyst_shard, {1.0, 0.0});
	trades[1504].setIn(Items::minecraft::copper_ingot, {2.0, 0.0});
	trades[1504].setOut(Items::minecraft::spyglass, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stick_from_crimson_planks.json
	trades[1505].setIn(Items::minecraft::crimson_planks, {2.0, 0.0});
	trades[1505].setOut(Items::minecraft::stick, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stick_from_mangrove_planks.json
	trades[1506].setIn(Items::minecraft::mangrove_planks, {2.0, 0.0});
	trades[1506].setOut(Items::minecraft::stick, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stick_from_warped_planks.json
	trades[1507].setIn(Items::minecraft::warped_planks, {2.0, 0.0});
	trades[1507].setOut(Items::minecraft::stick, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stick.json
	trades[1508].setIn(Items::minecraft::planks, {2.0, 0.0});
	trades[1508].setOut(Items::minecraft::stick, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/sticky_piston.json
	trades[1509].setIn(Items::minecraft::piston, {1.0, 0.0});
	trades[1509].setIn(Items::minecraft::slime_ball, {1.0, 0.0});
	trades[1509].setOut(Items::minecraft::sticky_piston, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stone_axe_from_blackstone.json
	trades[1510].setIn(Items::minecraft::stick, {2.0, 0.0});
	trades[1510].setIn(Items::minecraft::blackstone, {3.0, 0.0});
	trades[1510].setOut(Items::minecraft::stone_axe, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stone_axe_from_cobbled_deepslate.json
	trades[1511].setIn(Items::minecraft::stick, {2.0, 0.0});
	trades[1511].setIn(Items::minecraft::cobbled_deepslate, {3.0, 0.0});
	trades[1511].setOut(Items::minecraft::stone_axe, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stone_axe.json
	trades[1512].setIn(Items::minecraft::stick, {2.0, 0.0});
	trades[1512].setIn(Items::minecraft::stone_tool_materials, {3.0, 0.0});
	trades[1512].setOut(Items::minecraft::stone_axe, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonebrick.json
	trades[1513].setIn(Items::minecraft::stone, {4.0, 0.0});
	trades[1513].setOut(Items::minecraft::stone_bricks, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stone_brick_stairs.json
	trades[1514].setIn(Items::minecraft::stone_bricks, {6.0, 0.0});
	trades[1514].setOut(Items::minecraft::stone_brick_stairs, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stone_brick_wall.json
	trades[1515].setIn(Items::minecraft::stone_bricks, {6.0, 0.0});
	trades[1515].setOut(Items::minecraft::stone_brick_wall, 6.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stone_button.json
	trades[1516].setIn(Items::minecraft::stone, {1.0, 0.0});
	trades[1516].setOut(Items::minecraft::stone_button, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_andesite_slab.json
	trades[1517].setIn(Items::minecraft::andesite, {1.0, 0.0});
	trades[1517].setOut(Items::minecraft::andesite_slab, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_andesite_stairs.json
	trades[1518].setIn(Items::minecraft::andesite, {1.0, 0.0});
	trades[1518].setOut(Items::minecraft::andesite_stairs, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_andesite_wall.json
	trades[1519].setIn(Items::minecraft::andesite, {1.0, 0.0});
	trades[1519].setOut(Items::minecraft::andesite_wall, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_blackstone_slab_from_blackstone.json
	trades[1520].setIn(Items::minecraft::blackstone, {1.0, 0.0});
	trades[1520].setOut(Items::minecraft::blackstone_slab, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_blackstone_stairs_from_blackstone.json
	trades[1521].setIn(Items::minecraft::blackstone, {1.0, 0.0});
	trades[1521].setOut(Items::minecraft::blackstone_stairs, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_blackstone_wall_from_blackstone.json
	trades[1522].setIn(Items::minecraft::blackstone, {1.0, 0.0});
	trades[1522].setOut(Items::minecraft::blackstone_wall, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_bricks_from_polished_blackstone.json
	trades[1523].setIn(Items::minecraft::polished_blackstone, {1.0, 0.0});
	trades[1523].setOut(Items::minecraft::polished_blackstone_bricks, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_brick_slab_from_polished_blackstone.json
	trades[1524].setIn(Items::minecraft::polished_blackstone, {1.0, 0.0});
	trades[1524].setOut(Items::minecraft::polished_blackstone_brick_slab, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_brick_slab.json
	trades[1525].setIn(Items::minecraft::brick_block, {1.0, 0.0});
	trades[1525].setOut(Items::minecraft::brick_slab, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_brick_stairs_from_polished_blackstone.json
	trades[1526].setIn(Items::minecraft::polished_blackstone, {1.0, 0.0});
	trades[1526].setOut(Items::minecraft::polished_blackstone_brick_stairs, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_brick_stairs.json
	trades[1527].setIn(Items::minecraft::brick_block, {1.0, 0.0});
	trades[1527].setOut(Items::minecraft::brick_stairs, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_brick_wall_from_polished_blackstone.json
	trades[1528].setIn(Items::minecraft::polished_blackstone, {1.0, 0.0});
	trades[1528].setOut(Items::minecraft::polished_blackstone_brick_wall, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_brick_wall.json
	trades[1529].setIn(Items::minecraft::brick_block, {1.0, 0.0});
	trades[1529].setOut(Items::minecraft::brick_wall, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_chiseled_from_polished_blackstone.json
	trades[1530].setIn(Items::minecraft::polished_blackstone, {1.0, 0.0});
	trades[1530].setOut(Items::minecraft::chiseled_polished_blackstone, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_chiseled_nether_bricks_from_nether_brick.json
	trades[1531].setIn(Items::minecraft::nether_brick, {1.0, 0.0});
	trades[1531].setOut(Items::minecraft::chiseled_nether_bricks, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_chiseled_polished_from_blackstone.json
	trades[1532].setIn(Items::minecraft::blackstone, {1.0, 0.0});
	trades[1532].setOut(Items::minecraft::chiseled_polished_blackstone, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_cobblestone_slab.json
	trades[1533].setIn(Items::minecraft::cobblestone, {1.0, 0.0});
	trades[1533].setOut(Items::minecraft::cobblestone_slab, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_cobblestone_stairs.json
	trades[1534].setIn(Items::minecraft::cobblestone, {1.0, 0.0});
	trades[1534].setOut(Items::minecraft::stone_stairs, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_cobblestone_wall.json
	trades[1535].setIn(Items::minecraft::cobblestone, {1.0, 0.0});
	trades[1535].setOut(Items::minecraft::cobblestone_wall, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_copper_block_to_chiseled_copper.json
	trades[1536].setIn(Items::minecraft::copper_block, {1.0, 0.0});
	trades[1536].setOut(Items::minecraft::chiseled_copper, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_copper_block_to_copper_grate.json
	trades[1537].setIn(Items::minecraft::copper_block, {1.0, 0.0});
	trades[1537].setOut(Items::minecraft::copper_grate, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_copper_block_to_cut_copper.json
	trades[1538].setIn(Items::minecraft::copper_block, {1.0, 0.0});
	trades[1538].setOut(Items::minecraft::cut_copper, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_copper_block_to_cut_copper_slab.json
	trades[1539].setIn(Items::minecraft::copper_block, {1.0, 0.0});
	trades[1539].setOut(Items::minecraft::cut_copper_slab, 8.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_copper_block_to_cut_copper_stairs.json
	trades[1540].setIn(Items::minecraft::copper_block, {1.0, 0.0});
	trades[1540].setOut(Items::minecraft::cut_copper_stairs, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_cut_copper_to_chiseled_copper.json
	trades[1541].setIn(Items::minecraft::cut_copper, {1.0, 0.0});
	trades[1541].setOut(Items::minecraft::chiseled_copper, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_cut_copper_to_cut_copper_slab.json
	trades[1542].setIn(Items::minecraft::cut_copper, {1.0, 0.0});
	trades[1542].setOut(Items::minecraft::cut_copper_slab, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_cut_copper_to_cut_copper_stairs.json
	trades[1543].setIn(Items::minecraft::cut_copper, {1.0, 0.0});
	trades[1543].setOut(Items::minecraft::cut_copper_stairs, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_dark_prismarine_slab.json
	trades[1544].setIn(Items::minecraft::dark_prismarine, {1.0, 0.0});
	trades[1544].setOut(Items::minecraft::dark_prismarine_slab, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_dark_prismarine_stairs.json
	trades[1545].setIn(Items::minecraft::dark_prismarine, {1.0, 0.0});
	trades[1545].setOut(Items::minecraft::dark_prismarine_stairs, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_diorite_slab.json
	trades[1546].setIn(Items::minecraft::diorite, {1.0, 0.0});
	trades[1546].setOut(Items::minecraft::diorite_slab, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_diorite_stairs.json
	trades[1547].setIn(Items::minecraft::diorite, {1.0, 0.0});
	trades[1547].setOut(Items::minecraft::diorite_stairs, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_diorite_wall.json
	trades[1548].setIn(Items::minecraft::diorite, {1.0, 0.0});
	trades[1548].setOut(Items::minecraft::diorite_wall, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_endbricks.json
	trades[1549].setIn(Items::minecraft::end_stone, {1.0, 0.0});
	trades[1549].setOut(Items::minecraft::end_bricks, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_endbrick_slab2.json
	trades[1550].setIn(Items::minecraft::end_bricks, {1.0, 0.0});
	trades[1550].setOut(Items::minecraft::end_stone_brick_slab, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_endbrick_slab.json
	trades[1551].setIn(Items::minecraft::end_stone, {1.0, 0.0});
	trades[1551].setOut(Items::minecraft::end_stone_brick_slab, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_endbrick_stairs2.json
	trades[1552].setIn(Items::minecraft::end_bricks, {1.0, 0.0});
	trades[1552].setOut(Items::minecraft::end_brick_stairs, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_endbrick_stairs.json
	trades[1553].setIn(Items::minecraft::end_stone, {1.0, 0.0});
	trades[1553].setOut(Items::minecraft::end_brick_stairs, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_endbrick_wall2.json
	trades[1554].setIn(Items::minecraft::end_bricks, {1.0, 0.0});
	trades[1554].setOut(Items::minecraft::end_stone_brick_wall, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_endbrick_wall.json
	trades[1555].setIn(Items::minecraft::end_stone, {1.0, 0.0});
	trades[1555].setOut(Items::minecraft::end_stone_brick_wall, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_exp_cut_copper_to_exp_chiseled_copper.json
	trades[1556].setIn(Items::minecraft::exposed_cut_copper, {1.0, 0.0});
	trades[1556].setOut(Items::minecraft::exposed_chiseled_copper, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_exposed_copper_block_to_cut_copper.json
	trades[1557].setIn(Items::minecraft::exposed_copper, {1.0, 0.0});
	trades[1557].setOut(Items::minecraft::exposed_cut_copper, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_exposed_copper_block_to_cut_copper_slab.json
	trades[1558].setIn(Items::minecraft::exposed_copper, {1.0, 0.0});
	trades[1558].setOut(Items::minecraft::exposed_cut_copper_slab, 8.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_exposed_copper_block_to_cut_copper_stairs.json
	trades[1559].setIn(Items::minecraft::exposed_copper, {1.0, 0.0});
	trades[1559].setOut(Items::minecraft::exposed_cut_copper_stairs, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_exposed_copper_to_exposed_chiseled_copper.json
	trades[1560].setIn(Items::minecraft::exposed_copper, {1.0, 0.0});
	trades[1560].setOut(Items::minecraft::exposed_chiseled_copper, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_exposed_copper_to_exposed_copper_grate.json
	trades[1561].setIn(Items::minecraft::exposed_copper, {1.0, 0.0});
	trades[1561].setOut(Items::minecraft::exposed_copper_grate, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_exposed_cut_copper_to_cut_copper_slab.json
	trades[1562].setIn(Items::minecraft::exposed_cut_copper, {1.0, 0.0});
	trades[1562].setOut(Items::minecraft::exposed_cut_copper_slab, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_exposed_cut_copper_to_cut_copper_stairs.json
	trades[1563].setIn(Items::minecraft::exposed_cut_copper, {1.0, 0.0});
	trades[1563].setOut(Items::minecraft::exposed_cut_copper_stairs, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_granite_slab.json
	trades[1564].setIn(Items::minecraft::granite, {1.0, 0.0});
	trades[1564].setOut(Items::minecraft::granite_slab, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_granite_stairs.json
	trades[1565].setIn(Items::minecraft::granite, {1.0, 0.0});
	trades[1565].setOut(Items::minecraft::granite_stairs, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_granite_wall.json
	trades[1566].setIn(Items::minecraft::granite, {1.0, 0.0});
	trades[1566].setOut(Items::minecraft::granite_wall, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter.json
	trades[1567].setIn(Items::minecraft::stone, {3.0, 0.0});
	trades[1567].setIn(Items::minecraft::iron_ingot, {1.0, 0.0});
	trades[1567].setOut(Items::minecraft::stonecutter_block, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_mossy_cobblestone_slab.json
	trades[1568].setIn(Items::minecraft::mossy_cobblestone, {1.0, 0.0});
	trades[1568].setOut(Items::minecraft::mossy_cobblestone_slab, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_mossy_cobblestone_stairs.json
	trades[1569].setIn(Items::minecraft::mossy_cobblestone, {1.0, 0.0});
	trades[1569].setOut(Items::minecraft::mossy_cobblestone_stairs, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_mossy_cobblestone_wall.json
	trades[1570].setIn(Items::minecraft::mossy_cobblestone, {1.0, 0.0});
	trades[1570].setOut(Items::minecraft::mossy_cobblestone_wall, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_mossy_stonebrick_slab.json
	trades[1571].setIn(Items::minecraft::mossy_stone_bricks, {1.0, 0.0});
	trades[1571].setOut(Items::minecraft::mossy_stone_brick_slab, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_mossy_stonebrick_stairs.json
	trades[1572].setIn(Items::minecraft::mossy_stone_bricks, {1.0, 0.0});
	trades[1572].setOut(Items::minecraft::mossy_stone_brick_stairs, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_mossy_stonebrick_wall.json
	trades[1573].setIn(Items::minecraft::mossy_stone_bricks, {1.0, 0.0});
	trades[1573].setOut(Items::minecraft::mossy_stone_brick_wall, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_mud_brick_slab.json
	trades[1574].setIn(Items::minecraft::mud_bricks, {1.0, 0.0});
	trades[1574].setOut(Items::minecraft::mud_brick_slab, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_mud_brick_stairs.json
	trades[1575].setIn(Items::minecraft::mud_bricks, {1.0, 0.0});
	trades[1575].setOut(Items::minecraft::mud_brick_stairs, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_mud_brick_wall.json
	trades[1576].setIn(Items::minecraft::mud_bricks, {1.0, 0.0});
	trades[1576].setOut(Items::minecraft::mud_brick_wall, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_nether_brick_slab.json
	trades[1577].setIn(Items::minecraft::nether_brick, {1.0, 0.0});
	trades[1577].setOut(Items::minecraft::nether_brick_slab, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_nether_brick_stairs.json
	trades[1578].setIn(Items::minecraft::nether_brick, {1.0, 0.0});
	trades[1578].setOut(Items::minecraft::nether_brick_stairs, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_nether_brick_wall.json
	trades[1579].setIn(Items::minecraft::nether_brick, {1.0, 0.0});
	trades[1579].setOut(Items::minecraft::nether_brick_wall, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_oxi_cut_copper_to_oxi_chiseled_copper.json
	trades[1580].setIn(Items::minecraft::oxidized_cut_copper, {1.0, 0.0});
	trades[1580].setOut(Items::minecraft::oxidized_chiseled_copper, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_oxidized_copper_block_to_cut_copper.json
	trades[1581].setIn(Items::minecraft::oxidized_copper, {1.0, 0.0});
	trades[1581].setOut(Items::minecraft::oxidized_cut_copper, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_oxidized_copper_block_to_cut_copper_slab.json
	trades[1582].setIn(Items::minecraft::oxidized_copper, {1.0, 0.0});
	trades[1582].setOut(Items::minecraft::oxidized_cut_copper_slab, 8.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_oxidized_copper_block_to_cut_copper_stairs.json
	trades[1583].setIn(Items::minecraft::oxidized_copper, {1.0, 0.0});
	trades[1583].setOut(Items::minecraft::oxidized_cut_copper_stairs, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_oxidized_copper_to_oxidized_chiseled_copper.json
	trades[1584].setIn(Items::minecraft::oxidized_copper, {1.0, 0.0});
	trades[1584].setOut(Items::minecraft::oxidized_chiseled_copper, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_oxidized_copper_to_oxidized_copper_grate.json
	trades[1585].setIn(Items::minecraft::oxidized_copper, {1.0, 0.0});
	trades[1585].setOut(Items::minecraft::oxidized_copper_grate, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_oxidized_cut_copper_to_cut_copper_slab.json
	trades[1586].setIn(Items::minecraft::oxidized_cut_copper, {1.0, 0.0});
	trades[1586].setOut(Items::minecraft::oxidized_cut_copper_slab, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_oxidized_cut_copper_to_cut_copper_stairs.json
	trades[1587].setIn(Items::minecraft::oxidized_cut_copper, {1.0, 0.0});
	trades[1587].setOut(Items::minecraft::oxidized_cut_copper_stairs, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_polished_andesite.json
	trades[1588].setIn(Items::minecraft::andesite, {1.0, 0.0});
	trades[1588].setOut(Items::minecraft::polished_andesite, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_polished_andesite_slab2.json
	trades[1589].setIn(Items::minecraft::polished_andesite, {1.0, 0.0});
	trades[1589].setOut(Items::minecraft::polished_andesite_slab, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_polished_andesite_slab.json
	trades[1590].setIn(Items::minecraft::andesite, {1.0, 0.0});
	trades[1590].setOut(Items::minecraft::polished_andesite_slab, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_polished_andesite_stairs2.json
	trades[1591].setIn(Items::minecraft::polished_andesite, {1.0, 0.0});
	trades[1591].setOut(Items::minecraft::polished_andesite_stairs, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_polished_andesite_stairs.json
	trades[1592].setIn(Items::minecraft::andesite, {1.0, 0.0});
	trades[1592].setOut(Items::minecraft::polished_andesite_stairs, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_polished_basalt_from_basalt.json
	trades[1593].setIn(Items::minecraft::basalt, {1.0, 0.0});
	trades[1593].setOut(Items::minecraft::polished_basalt, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_polished_bricks_from_blackstone.json
	trades[1594].setIn(Items::minecraft::blackstone, {1.0, 0.0});
	trades[1594].setOut(Items::minecraft::polished_blackstone_bricks, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_polished_brick_slab_from_blackstone.json
	trades[1595].setIn(Items::minecraft::blackstone, {1.0, 0.0});
	trades[1595].setOut(Items::minecraft::polished_blackstone_brick_slab, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_polished_brick_stairs_from_blackstone.json
	trades[1596].setIn(Items::minecraft::blackstone, {1.0, 0.0});
	trades[1596].setOut(Items::minecraft::polished_blackstone_brick_stairs, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_polished_brick_wall_from_blackstone.json
	trades[1597].setIn(Items::minecraft::blackstone, {1.0, 0.0});
	trades[1597].setOut(Items::minecraft::polished_blackstone_brick_wall, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_polished_diorite.json
	trades[1598].setIn(Items::minecraft::diorite, {1.0, 0.0});
	trades[1598].setOut(Items::minecraft::polished_diorite, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_polished_diorite_slab2.json
	trades[1599].setIn(Items::minecraft::polished_diorite, {1.0, 0.0});
	trades[1599].setOut(Items::minecraft::polished_diorite_slab, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_polished_diorite_slab.json
	trades[1600].setIn(Items::minecraft::diorite, {1.0, 0.0});
	trades[1600].setOut(Items::minecraft::polished_diorite_slab, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_polished_diorite_stairs2.json
	trades[1601].setIn(Items::minecraft::polished_diorite, {1.0, 0.0});
	trades[1601].setOut(Items::minecraft::polished_diorite_stairs, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_polished_diorite_stairs.json
	trades[1602].setIn(Items::minecraft::diorite, {1.0, 0.0});
	trades[1602].setOut(Items::minecraft::polished_diorite_stairs, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_polished_from_blackstone.json
	trades[1603].setIn(Items::minecraft::blackstone, {1.0, 0.0});
	trades[1603].setOut(Items::minecraft::polished_blackstone, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_polished_granite.json
	trades[1604].setIn(Items::minecraft::granite, {1.0, 0.0});
	trades[1604].setOut(Items::minecraft::polished_granite, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_polished_granite_slab2.json
	trades[1605].setIn(Items::minecraft::polished_granite, {1.0, 0.0});
	trades[1605].setOut(Items::minecraft::polished_granite_slab, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_polished_granite_slab.json
	trades[1606].setIn(Items::minecraft::granite, {1.0, 0.0});
	trades[1606].setOut(Items::minecraft::polished_granite_slab, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_polished_granite_stairs2.json
	trades[1607].setIn(Items::minecraft::polished_granite, {1.0, 0.0});
	trades[1607].setOut(Items::minecraft::polished_granite_stairs, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_polished_granite_stairs.json
	trades[1608].setIn(Items::minecraft::granite, {1.0, 0.0});
	trades[1608].setOut(Items::minecraft::polished_granite_stairs, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_polished_slab_from_blackstone.json
	trades[1609].setIn(Items::minecraft::blackstone, {1.0, 0.0});
	trades[1609].setOut(Items::minecraft::polished_blackstone_slab, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_polished_stairs_from_blackstone.json
	trades[1610].setIn(Items::minecraft::blackstone, {1.0, 0.0});
	trades[1610].setOut(Items::minecraft::polished_blackstone_stairs, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_polished_tuff_to_chiseled_tuff_bricks.json
	trades[1611].setIn(Items::minecraft::polished_tuff, {1.0, 0.0});
	trades[1611].setOut(Items::minecraft::chiseled_tuff_bricks, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_polished_tuff_to_polished_tuff_slab.json
	trades[1612].setIn(Items::minecraft::polished_tuff, {1.0, 0.0});
	trades[1612].setOut(Items::minecraft::polished_tuff_slab, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_polished_tuff_to_polished_tuff_stairs.json
	trades[1613].setIn(Items::minecraft::polished_tuff, {1.0, 0.0});
	trades[1613].setOut(Items::minecraft::polished_tuff_stairs, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_polished_tuff_to_polished_tuff_wall.json
	trades[1614].setIn(Items::minecraft::polished_tuff, {1.0, 0.0});
	trades[1614].setOut(Items::minecraft::polished_tuff_wall, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_polished_tuff_to_tuff_bricks.json
	trades[1615].setIn(Items::minecraft::polished_tuff, {1.0, 0.0});
	trades[1615].setOut(Items::minecraft::tuff_bricks, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_polished_tuff_to_tuff_brick_slab.json
	trades[1616].setIn(Items::minecraft::polished_tuff, {1.0, 0.0});
	trades[1616].setOut(Items::minecraft::tuff_brick_slab, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_polished_tuff_to_tuff_brick_stairs.json
	trades[1617].setIn(Items::minecraft::polished_tuff, {1.0, 0.0});
	trades[1617].setOut(Items::minecraft::tuff_brick_stairs, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_polished_tuff_to_tuff_brick_wall.json
	trades[1618].setIn(Items::minecraft::polished_tuff, {1.0, 0.0});
	trades[1618].setOut(Items::minecraft::tuff_brick_wall, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_polished_wall_from_blackstone.json
	trades[1619].setIn(Items::minecraft::blackstone, {1.0, 0.0});
	trades[1619].setOut(Items::minecraft::polished_blackstone_wall, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_prismarine_brick_slab.json
	trades[1620].setIn(Items::minecraft::prismarine_bricks, {1.0, 0.0});
	trades[1620].setOut(Items::minecraft::prismarine_brick_slab, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_prismarine_brick_stairs.json
	trades[1621].setIn(Items::minecraft::prismarine_bricks, {1.0, 0.0});
	trades[1621].setOut(Items::minecraft::prismarine_bricks_stairs, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_prismarine_slab.json
	trades[1622].setIn(Items::minecraft::prismarine, {1.0, 0.0});
	trades[1622].setOut(Items::minecraft::prismarine_slab, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_prismarine_stairs.json
	trades[1623].setIn(Items::minecraft::prismarine, {1.0, 0.0});
	trades[1623].setOut(Items::minecraft::prismarine_stairs, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_prismarine_wall.json
	trades[1624].setIn(Items::minecraft::prismarine, {1.0, 0.0});
	trades[1624].setOut(Items::minecraft::prismarine_wall, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_purpur_lines.json
	trades[1625].setIn(Items::minecraft::purpur_block, {1.0, 0.0});
	trades[1625].setOut(Items::minecraft::purpur_block, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_purpur_pillar.json
	trades[1626].setIn(Items::minecraft::purpur_block, {1.0, 0.0});
	trades[1626].setOut(Items::minecraft::purpur_pillar, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_purpur_slab.json
	trades[1627].setIn(Items::minecraft::purpur_block, {1.0, 0.0});
	trades[1627].setOut(Items::minecraft::purpur_slab, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_purpur_stairs.json
	trades[1628].setIn(Items::minecraft::purpur_block, {1.0, 0.0});
	trades[1628].setOut(Items::minecraft::purpur_stairs, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_quartz_bricks_from_quartz_block.json
	trades[1629].setIn(Items::minecraft::quartz_block, {1.0, 0.0});
	trades[1629].setOut(Items::minecraft::quartz_bricks, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_quartz_chiseled.json
	trades[1630].setIn(Items::minecraft::quartz_block, {1.0, 0.0});
	trades[1630].setOut(Items::minecraft::chiseled_quartz_block, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_quartz_lines.json
	trades[1631].setIn(Items::minecraft::quartz_block, {1.0, 0.0});
	trades[1631].setOut(Items::minecraft::quartz_block, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_quartz_pillar.json
	trades[1632].setIn(Items::minecraft::quartz_block, {1.0, 0.0});
	trades[1632].setOut(Items::minecraft::quartz_pillar, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_quartz_slab.json
	trades[1633].setIn(Items::minecraft::quartz_block, {1.0, 0.0});
	trades[1633].setOut(Items::minecraft::quartz_slab, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_quartz_stairs.json
	trades[1634].setIn(Items::minecraft::quartz_block, {1.0, 0.0});
	trades[1634].setOut(Items::minecraft::quartz_stairs, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_red_nether_brick_slab.json
	trades[1635].setIn(Items::minecraft::red_nether_brick, {1.0, 0.0});
	trades[1635].setOut(Items::minecraft::red_nether_brick_slab, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_red_nether_brick_stairs.json
	trades[1636].setIn(Items::minecraft::red_nether_brick, {1.0, 0.0});
	trades[1636].setOut(Items::minecraft::red_nether_brick_stairs, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_red_nether_brick_wall.json
	trades[1637].setIn(Items::minecraft::red_nether_brick, {1.0, 0.0});
	trades[1637].setOut(Items::minecraft::red_nether_brick_wall, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_red_sandstone_cut.json
	trades[1638].setIn(Items::minecraft::red_sandstone, {1.0, 0.0});
	trades[1638].setOut(Items::minecraft::cut_red_sandstone, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_red_sandstone_heiroglyphs.json
	trades[1639].setIn(Items::minecraft::red_sandstone, {1.0, 0.0});
	trades[1639].setOut(Items::minecraft::chiseled_red_sandstone, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_red_sandstone_slab.json
	trades[1640].setIn(Items::minecraft::red_sandstone, {1.0, 0.0});
	trades[1640].setOut(Items::minecraft::red_sandstone_slab, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_red_sandstone_stairs.json
	trades[1641].setIn(Items::minecraft::red_sandstone, {1.0, 0.0});
	trades[1641].setOut(Items::minecraft::red_sandstone_stairs, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_red_sandstone_wall.json
	trades[1642].setIn(Items::minecraft::red_sandstone, {1.0, 0.0});
	trades[1642].setOut(Items::minecraft::red_sandstone_wall, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_resin_brick_chiseled.json
	trades[1643].setIn(Items::minecraft::resin_bricks, {1.0, 0.0});
	trades[1643].setOut(Items::minecraft::chiseled_resin_bricks, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_resin_brick_slab.json
	trades[1644].setIn(Items::minecraft::resin_bricks, {1.0, 0.0});
	trades[1644].setOut(Items::minecraft::resin_brick_slab, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_resin_brick_stairs.json
	trades[1645].setIn(Items::minecraft::resin_bricks, {1.0, 0.0});
	trades[1645].setOut(Items::minecraft::resin_brick_stairs, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_resin_brick_wall.json
	trades[1646].setIn(Items::minecraft::resin_bricks, {1.0, 0.0});
	trades[1646].setOut(Items::minecraft::resin_brick_wall, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_sandstone_cut.json
	trades[1647].setIn(Items::minecraft::sandstone, {1.0, 0.0});
	trades[1647].setOut(Items::minecraft::cut_sandstone, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_sandstone_heiroglyphs.json
	trades[1648].setIn(Items::minecraft::sandstone, {1.0, 0.0});
	trades[1648].setOut(Items::minecraft::chiseled_sandstone, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_sandstone_slab.json
	trades[1649].setIn(Items::minecraft::sandstone, {1.0, 0.0});
	trades[1649].setOut(Items::minecraft::sandstone_slab, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_sandstone_stairs.json
	trades[1650].setIn(Items::minecraft::sandstone, {1.0, 0.0});
	trades[1650].setOut(Items::minecraft::sandstone_stairs, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_sandstone_wall.json
	trades[1651].setIn(Items::minecraft::sandstone, {1.0, 0.0});
	trades[1651].setOut(Items::minecraft::sandstone_wall, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_slab_from_polished_blackstone_bricks.json
	trades[1652].setIn(Items::minecraft::polished_blackstone_bricks, {1.0, 0.0});
	trades[1652].setOut(Items::minecraft::polished_blackstone_brick_slab, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_slab_from_polished_blackstone.json
	trades[1653].setIn(Items::minecraft::polished_blackstone, {1.0, 0.0});
	trades[1653].setOut(Items::minecraft::polished_blackstone_slab, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_smooth_quartz_slab.json
	trades[1654].setIn(Items::minecraft::smooth_quartz, {1.0, 0.0});
	trades[1654].setOut(Items::minecraft::smooth_quartz_slab, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_smooth_quartz_stairs.json
	trades[1655].setIn(Items::minecraft::smooth_quartz, {1.0, 0.0});
	trades[1655].setOut(Items::minecraft::smooth_quartz_stairs, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_smooth_red_sandstone_slab.json
	trades[1656].setIn(Items::minecraft::smooth_red_sandstone, {1.0, 0.0});
	trades[1656].setOut(Items::minecraft::smooth_red_sandstone_slab, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_smooth_red_sandstone_stairs.json
	trades[1657].setIn(Items::minecraft::smooth_red_sandstone, {1.0, 0.0});
	trades[1657].setOut(Items::minecraft::smooth_red_sandstone_stairs, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_smooth_sandstone_slab.json
	trades[1658].setIn(Items::minecraft::smooth_sandstone, {1.0, 0.0});
	trades[1658].setOut(Items::minecraft::smooth_sandstone_slab, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_smooth_sandstone_stairs.json
	trades[1659].setIn(Items::minecraft::sandstone, {1.0, 0.0});
	trades[1659].setOut(Items::minecraft::smooth_sandstone_stairs, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_smooth_stone_slab.json
	trades[1660].setIn(Items::minecraft::smooth_stone, {1.0, 0.0});
	trades[1660].setOut(Items::minecraft::smooth_stone_slab, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_stairs_from_polished_blackstone_bricks.json
	trades[1661].setIn(Items::minecraft::polished_blackstone_bricks, {1.0, 0.0});
	trades[1661].setOut(Items::minecraft::polished_blackstone_brick_stairs, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_stairs_from_polished_blackstone.json
	trades[1662].setIn(Items::minecraft::polished_blackstone, {1.0, 0.0});
	trades[1662].setOut(Items::minecraft::polished_blackstone_stairs, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_stonebrick_chiseled2.json
	trades[1663].setIn(Items::minecraft::stone_bricks, {1.0, 0.0});
	trades[1663].setOut(Items::minecraft::chiseled_stone_bricks, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_stonebrick_chiseled.json
	trades[1664].setIn(Items::minecraft::stone, {1.0, 0.0});
	trades[1664].setOut(Items::minecraft::chiseled_stone_bricks, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_stonebrick.json
	trades[1665].setIn(Items::minecraft::stone, {1.0, 0.0});
	trades[1665].setOut(Items::minecraft::stone_bricks, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_stonebrick_slab2.json
	trades[1666].setIn(Items::minecraft::stone_bricks, {1.0, 0.0});
	trades[1666].setOut(Items::minecraft::stone_brick_slab, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_stonebrick_slab.json
	trades[1667].setIn(Items::minecraft::stone, {1.0, 0.0});
	trades[1667].setOut(Items::minecraft::stone_brick_slab, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_stonebrick_stairs2.json
	trades[1668].setIn(Items::minecraft::stone_bricks, {1.0, 0.0});
	trades[1668].setOut(Items::minecraft::stone_brick_stairs, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_stonebrick_stairs.json
	trades[1669].setIn(Items::minecraft::stone, {1.0, 0.0});
	trades[1669].setOut(Items::minecraft::stone_brick_stairs, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_stonebrick_wall2.json
	trades[1670].setIn(Items::minecraft::stone_bricks, {1.0, 0.0});
	trades[1670].setOut(Items::minecraft::stone_brick_wall, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_stonebrick_wall.json
	trades[1671].setIn(Items::minecraft::stone, {1.0, 0.0});
	trades[1671].setOut(Items::minecraft::stone_brick_wall, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_stone_slab.json
	trades[1672].setIn(Items::minecraft::stone, {1.0, 0.0});
	trades[1672].setOut(Items::minecraft::normal_stone_slab, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_stone_stairs.json
	trades[1673].setIn(Items::minecraft::stone, {1.0, 0.0});
	trades[1673].setOut(Items::minecraft::normal_stone_stairs, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_tuff_bricks_to_chiseled_tuff_bricks.json
	trades[1674].setIn(Items::minecraft::tuff_bricks, {1.0, 0.0});
	trades[1674].setOut(Items::minecraft::chiseled_tuff_bricks, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_tuff_bricks_to_tuff_brick_slab.json
	trades[1675].setIn(Items::minecraft::tuff_bricks, {1.0, 0.0});
	trades[1675].setOut(Items::minecraft::tuff_brick_slab, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_tuff_bricks_to_tuff_brick_stairs.json
	trades[1676].setIn(Items::minecraft::tuff_bricks, {1.0, 0.0});
	trades[1676].setOut(Items::minecraft::tuff_brick_stairs, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_tuff_bricks_to_tuff_brick_wall.json
	trades[1677].setIn(Items::minecraft::tuff_bricks, {1.0, 0.0});
	trades[1677].setOut(Items::minecraft::tuff_brick_wall, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_tuff_to_chiseled_tuff_bricks.json
	trades[1678].setIn(Items::minecraft::tuff, {1.0, 0.0});
	trades[1678].setOut(Items::minecraft::chiseled_tuff_bricks, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_tuff_to_chiseled_tuff.json
	trades[1679].setIn(Items::minecraft::tuff, {1.0, 0.0});
	trades[1679].setOut(Items::minecraft::chiseled_tuff, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_tuff_to_polished_tuff.json
	trades[1680].setIn(Items::minecraft::tuff, {1.0, 0.0});
	trades[1680].setOut(Items::minecraft::polished_tuff, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_tuff_to_polished_tuff_slab.json
	trades[1681].setIn(Items::minecraft::tuff, {1.0, 0.0});
	trades[1681].setOut(Items::minecraft::polished_tuff_slab, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_tuff_to_polished_tuff_stairs.json
	trades[1682].setIn(Items::minecraft::tuff, {1.0, 0.0});
	trades[1682].setOut(Items::minecraft::polished_tuff_stairs, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_tuff_to_polished_tuff_wall.json
	trades[1683].setIn(Items::minecraft::tuff, {1.0, 0.0});
	trades[1683].setOut(Items::minecraft::polished_tuff_wall, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_tuff_to_tuff_bricks.json
	trades[1684].setIn(Items::minecraft::tuff, {1.0, 0.0});
	trades[1684].setOut(Items::minecraft::tuff_bricks, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_tuff_to_tuff_brick_slab.json
	trades[1685].setIn(Items::minecraft::tuff, {1.0, 0.0});
	trades[1685].setOut(Items::minecraft::tuff_brick_slab, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_tuff_to_tuff_brick_stairs.json
	trades[1686].setIn(Items::minecraft::tuff, {1.0, 0.0});
	trades[1686].setOut(Items::minecraft::tuff_brick_stairs, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_tuff_to_tuff_brick_wall.json
	trades[1687].setIn(Items::minecraft::tuff, {1.0, 0.0});
	trades[1687].setOut(Items::minecraft::tuff_brick_wall, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_tuff_to_tuff_slab.json
	trades[1688].setIn(Items::minecraft::tuff, {1.0, 0.0});
	trades[1688].setOut(Items::minecraft::tuff_slab, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_tuff_to_tuff_stairs.json
	trades[1689].setIn(Items::minecraft::tuff, {1.0, 0.0});
	trades[1689].setOut(Items::minecraft::tuff_stairs, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_tuff_to_tuff_wall.json
	trades[1690].setIn(Items::minecraft::tuff, {1.0, 0.0});
	trades[1690].setOut(Items::minecraft::tuff_wall, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_wall_from_polished_blackstone_bricks.json
	trades[1691].setIn(Items::minecraft::polished_blackstone_bricks, {1.0, 0.0});
	trades[1691].setOut(Items::minecraft::polished_blackstone_brick_wall, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_wall_from_polished_blackstone.json
	trades[1692].setIn(Items::minecraft::polished_blackstone, {1.0, 0.0});
	trades[1692].setOut(Items::minecraft::polished_blackstone_wall, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_wax_cut_copper_to_wax_chiseled_copper.json
	trades[1693].setIn(Items::minecraft::waxed_cut_copper, {1.0, 0.0});
	trades[1693].setOut(Items::minecraft::waxed_chiseled_copper, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_wax_exp_cut_copper_to_wax_exp_chiseled_copper.json
	trades[1694].setIn(Items::minecraft::waxed_exposed_cut_copper, {1.0, 0.0});
	trades[1694].setOut(Items::minecraft::waxed_exposed_chiseled_copper, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_wax_oxi_cut_copper_to_wax_oxi_chiseled_copper.json
	trades[1695].setIn(Items::minecraft::waxed_oxidized_cut_copper, {1.0, 0.0});
	trades[1695].setOut(Items::minecraft::waxed_oxidized_chiseled_copper, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_wax_wea_cut_copper_to_wax_wea_chiseled_copper.json
	trades[1696].setIn(Items::minecraft::waxed_weathered_cut_copper, {1.0, 0.0});
	trades[1696].setOut(Items::minecraft::waxed_weathered_chiseled_copper, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_w_copper_block_to_cut_copper.json
	trades[1697].setIn(Items::minecraft::waxed_copper, {1.0, 0.0});
	trades[1697].setOut(Items::minecraft::waxed_cut_copper, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_w_copper_block_to_cut_copper_slab.json
	trades[1698].setIn(Items::minecraft::waxed_copper, {1.0, 0.0});
	trades[1698].setOut(Items::minecraft::waxed_cut_copper_slab, 8.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_w_copper_block_to_cut_copper_stairs.json
	trades[1699].setIn(Items::minecraft::waxed_copper, {1.0, 0.0});
	trades[1699].setOut(Items::minecraft::waxed_cut_copper_stairs, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_w_copper_to_w_chiseled_copper.json
	trades[1700].setIn(Items::minecraft::waxed_copper, {1.0, 0.0});
	trades[1700].setOut(Items::minecraft::waxed_chiseled_copper, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_w_copper_to_w_copper_grate.json
	trades[1701].setIn(Items::minecraft::waxed_copper, {1.0, 0.0});
	trades[1701].setOut(Items::minecraft::waxed_copper_grate, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_w_cut_copper_to_cut_copper_slab.json
	trades[1702].setIn(Items::minecraft::waxed_cut_copper, {1.0, 0.0});
	trades[1702].setOut(Items::minecraft::waxed_cut_copper_slab, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_w_cut_copper_to_cut_copper_stairs.json
	trades[1703].setIn(Items::minecraft::waxed_cut_copper, {1.0, 0.0});
	trades[1703].setOut(Items::minecraft::waxed_cut_copper_stairs, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_wea_cut_copper_to_wea_chiseled_copper.json
	trades[1704].setIn(Items::minecraft::weathered_cut_copper, {1.0, 0.0});
	trades[1704].setOut(Items::minecraft::weathered_chiseled_copper, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_weathered_copper_block_to_cut_copper.json
	trades[1705].setIn(Items::minecraft::weathered_copper, {1.0, 0.0});
	trades[1705].setOut(Items::minecraft::weathered_cut_copper, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_weathered_copper_block_to_cut_copper_slab.json
	trades[1706].setIn(Items::minecraft::weathered_copper, {1.0, 0.0});
	trades[1706].setOut(Items::minecraft::weathered_cut_copper_slab, 8.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_weathered_copper_block_to_cut_copper_stairs.json
	trades[1707].setIn(Items::minecraft::weathered_copper, {1.0, 0.0});
	trades[1707].setOut(Items::minecraft::weathered_cut_copper_stairs, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_weathered_copper_to_weathered_chiseled_copper.json
	trades[1708].setIn(Items::minecraft::weathered_copper, {1.0, 0.0});
	trades[1708].setOut(Items::minecraft::weathered_chiseled_copper, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_weathered_copper_to_weathered_copper_grate.json
	trades[1709].setIn(Items::minecraft::weathered_copper, {1.0, 0.0});
	trades[1709].setOut(Items::minecraft::weathered_copper_grate, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_weathered_cut_copper_to_cut_copper_slab.json
	trades[1710].setIn(Items::minecraft::weathered_cut_copper, {1.0, 0.0});
	trades[1710].setOut(Items::minecraft::weathered_cut_copper_slab, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_weathered_cut_copper_to_cut_copper_stairs.json
	trades[1711].setIn(Items::minecraft::weathered_cut_copper, {1.0, 0.0});
	trades[1711].setOut(Items::minecraft::weathered_cut_copper_stairs, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_w_exposed_copper_block_to_cut_copper.json
	trades[1712].setIn(Items::minecraft::waxed_exposed_copper, {1.0, 0.0});
	trades[1712].setOut(Items::minecraft::waxed_exposed_cut_copper, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_w_exposed_copper_block_to_cut_copper_slab.json
	trades[1713].setIn(Items::minecraft::waxed_exposed_copper, {1.0, 0.0});
	trades[1713].setOut(Items::minecraft::waxed_exposed_cut_copper_slab, 8.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_w_exposed_copper_block_to_cut_copper_stairs.json
	trades[1714].setIn(Items::minecraft::waxed_exposed_copper, {1.0, 0.0});
	trades[1714].setOut(Items::minecraft::waxed_exposed_cut_copper_stairs, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_w_exposed_copper_to_w_exposed_chiseled_copper.json
	trades[1715].setIn(Items::minecraft::waxed_exposed_copper, {1.0, 0.0});
	trades[1715].setOut(Items::minecraft::waxed_exposed_chiseled_copper, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_w_exposed_copper_to_w_exposed_copper_grate.json
	trades[1716].setIn(Items::minecraft::waxed_exposed_copper, {1.0, 0.0});
	trades[1716].setOut(Items::minecraft::waxed_exposed_copper_grate, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_w_exposed_cut_copper_to_cut_copper_slab.json
	trades[1717].setIn(Items::minecraft::waxed_exposed_cut_copper, {1.0, 0.0});
	trades[1717].setOut(Items::minecraft::waxed_exposed_cut_copper_slab, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_w_exposed_cut_copper_to_cut_copper_stairs.json
	trades[1718].setIn(Items::minecraft::waxed_exposed_cut_copper, {1.0, 0.0});
	trades[1718].setOut(Items::minecraft::waxed_exposed_cut_copper_stairs, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_w_oxidized_copper_2_w_oxidized_chiseled_copper.json
	trades[1719].setIn(Items::minecraft::waxed_oxidized_copper, {1.0, 0.0});
	trades[1719].setOut(Items::minecraft::waxed_oxidized_chiseled_copper, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_w_oxidized_copper_block_to_cut_copper.json
	trades[1720].setIn(Items::minecraft::waxed_oxidized_copper, {1.0, 0.0});
	trades[1720].setOut(Items::minecraft::waxed_oxidized_cut_copper, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_w_oxidized_copper_block_to_cut_copper_slab.json
	trades[1721].setIn(Items::minecraft::waxed_oxidized_copper, {1.0, 0.0});
	trades[1721].setOut(Items::minecraft::waxed_oxidized_cut_copper_slab, 8.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_w_oxidized_copper_block_to_cut_copper_stairs.json
	trades[1722].setIn(Items::minecraft::waxed_oxidized_copper, {1.0, 0.0});
	trades[1722].setOut(Items::minecraft::waxed_oxidized_cut_copper_stairs, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_w_oxidized_copper_to_w_oxidized_copper_grate.json
	trades[1723].setIn(Items::minecraft::waxed_oxidized_copper, {1.0, 0.0});
	trades[1723].setOut(Items::minecraft::waxed_oxidized_copper_grate, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_w_oxidized_cut_copper_to_cut_copper_slab.json
	trades[1724].setIn(Items::minecraft::waxed_oxidized_cut_copper, {1.0, 0.0});
	trades[1724].setOut(Items::minecraft::waxed_oxidized_cut_copper_slab, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_w_oxidized_cut_copper_to_cut_copper_stairs.json
	trades[1725].setIn(Items::minecraft::waxed_oxidized_cut_copper, {1.0, 0.0});
	trades[1725].setOut(Items::minecraft::waxed_oxidized_cut_copper_stairs, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_w_weatherd_copper_2_w_weatherd_chiseled_copper.json
	trades[1726].setIn(Items::minecraft::waxed_weathered_copper, {1.0, 0.0});
	trades[1726].setOut(Items::minecraft::waxed_weathered_chiseled_copper, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_w_weathered_copper_block_to_cut_copper.json
	trades[1727].setIn(Items::minecraft::waxed_weathered_copper, {1.0, 0.0});
	trades[1727].setOut(Items::minecraft::waxed_weathered_cut_copper, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_w_weathered_copper_block_to_cut_copper_slab.json
	trades[1728].setIn(Items::minecraft::waxed_weathered_copper, {1.0, 0.0});
	trades[1728].setOut(Items::minecraft::waxed_weathered_cut_copper_slab, 8.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_w_weathered_copper_block_to_cut_copper_stairs.json
	trades[1729].setIn(Items::minecraft::waxed_weathered_copper, {1.0, 0.0});
	trades[1729].setOut(Items::minecraft::waxed_weathered_cut_copper_stairs, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_w_weathered_copper_to_w_weathered_copper_grate.json
	trades[1730].setIn(Items::minecraft::waxed_weathered_copper, {1.0, 0.0});
	trades[1730].setOut(Items::minecraft::waxed_weathered_copper_grate, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_w_weathered_cut_copper_to_cut_copper_slab.json
	trades[1731].setIn(Items::minecraft::waxed_weathered_cut_copper, {1.0, 0.0});
	trades[1731].setOut(Items::minecraft::waxed_weathered_cut_copper_slab, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stonecutter_w_weathered_cut_copper_to_cut_copper_stairs.json
	trades[1732].setIn(Items::minecraft::waxed_weathered_cut_copper, {1.0, 0.0});
	trades[1732].setOut(Items::minecraft::waxed_weathered_cut_copper_stairs, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stone_hoe_from_blackstone.json
	trades[1733].setIn(Items::minecraft::stick, {2.0, 0.0});
	trades[1733].setIn(Items::minecraft::blackstone, {2.0, 0.0});
	trades[1733].setOut(Items::minecraft::stone_hoe, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stone_hoe_from_cobbled_deepslate.json
	trades[1734].setIn(Items::minecraft::stick, {2.0, 0.0});
	trades[1734].setIn(Items::minecraft::cobbled_deepslate, {2.0, 0.0});
	trades[1734].setOut(Items::minecraft::stone_hoe, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stone_hoe.json
	trades[1735].setIn(Items::minecraft::stick, {2.0, 0.0});
	trades[1735].setIn(Items::minecraft::stone_tool_materials, {2.0, 0.0});
	trades[1735].setOut(Items::minecraft::stone_hoe, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stone_pickaxe_from_blackstone.json
	trades[1736].setIn(Items::minecraft::stick, {2.0, 0.0});
	trades[1736].setIn(Items::minecraft::blackstone, {3.0, 0.0});
	trades[1736].setOut(Items::minecraft::stone_pickaxe, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stone_pickaxe_from_cobbled_deepslate.json
	trades[1737].setIn(Items::minecraft::stick, {2.0, 0.0});
	trades[1737].setIn(Items::minecraft::cobbled_deepslate, {3.0, 0.0});
	trades[1737].setOut(Items::minecraft::stone_pickaxe, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stone_pickaxe.json
	trades[1738].setIn(Items::minecraft::stick, {2.0, 0.0});
	trades[1738].setIn(Items::minecraft::stone_tool_materials, {3.0, 0.0});
	trades[1738].setOut(Items::minecraft::stone_pickaxe, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stone_pressure_plate.json
	trades[1739].setIn(Items::minecraft::stone, {2.0, 0.0});
	trades[1739].setOut(Items::minecraft::stone_pressure_plate, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stone_shovel_from_blackstone.json
	trades[1740].setIn(Items::minecraft::stick, {2.0, 0.0});
	trades[1740].setIn(Items::minecraft::blackstone, {1.0, 0.0});
	trades[1740].setOut(Items::minecraft::stone_shovel, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stone_shovel_from_cobbled_deepslate.json
	trades[1741].setIn(Items::minecraft::stick, {2.0, 0.0});
	trades[1741].setIn(Items::minecraft::cobbled_deepslate, {1.0, 0.0});
	trades[1741].setOut(Items::minecraft::stone_shovel, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stone_shovel.json
	trades[1742].setIn(Items::minecraft::stick, {2.0, 0.0});
	trades[1742].setIn(Items::minecraft::stone_tool_materials, {1.0, 0.0});
	trades[1742].setOut(Items::minecraft::stone_shovel, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stone_stairs.json
	trades[1743].setIn(Items::minecraft::stone, {6.0, 0.0});
	trades[1743].setOut(Items::minecraft::normal_stone_stairs, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stone_sword_from_blackstone.json
	trades[1744].setIn(Items::minecraft::stick, {1.0, 0.0});
	trades[1744].setIn(Items::minecraft::blackstone, {2.0, 0.0});
	trades[1744].setOut(Items::minecraft::stone_sword, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stone_sword_from_cobbled_deepslate.json
	trades[1745].setIn(Items::minecraft::stick, {1.0, 0.0});
	trades[1745].setIn(Items::minecraft::cobbled_deepslate, {2.0, 0.0});
	trades[1745].setOut(Items::minecraft::stone_sword, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stone_sword.json
	trades[1746].setIn(Items::minecraft::stick, {1.0, 0.0});
	trades[1746].setIn(Items::minecraft::stone_tool_materials, {2.0, 0.0});
	trades[1746].setOut(Items::minecraft::stone_sword, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/string_to_wool.json
	trades[1747].setIn(Items::minecraft::string, {4.0, 0.0});
	trades[1747].setOut(Items::minecraft::white_wool, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/stripped_mangrove_wood.json
	trades[1748].setIn(Items::minecraft::stripped_mangrove_log, {4.0, 0.0});
	trades[1748].setOut(Items::minecraft::stripped_mangrove_wood, 3.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/sugar.json
	trades[1749].setIn(Items::minecraft::reeds, {1.0, 0.0});
	trades[1749].setOut(Items::minecraft::sugar, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/suspicious_stew_from_allium.json
	trades[1750].setIn(Items::minecraft::brown_mushroom, {1.0, 0.0});
	trades[1750].setIn(Items::minecraft::red_mushroom, {1.0, 0.0});
	trades[1750].setIn(Items::minecraft::bowl, {1.0, 0.0});
	trades[1750].setIn(Items::minecraft::allium, {1.0, 0.0});
	trades[1750].setOut(Items::minecraft::suspicious_stew, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/suspicious_stew_from_azure_bluet.json
	trades[1751].setIn(Items::minecraft::brown_mushroom, {1.0, 0.0});
	trades[1751].setIn(Items::minecraft::red_mushroom, {1.0, 0.0});
	trades[1751].setIn(Items::minecraft::bowl, {1.0, 0.0});
	trades[1751].setIn(Items::minecraft::azure_bluet, {1.0, 0.0});
	trades[1751].setOut(Items::minecraft::suspicious_stew, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/suspicious_stew_from_blue_orchid.json
	trades[1752].setIn(Items::minecraft::brown_mushroom, {1.0, 0.0});
	trades[1752].setIn(Items::minecraft::red_mushroom, {1.0, 0.0});
	trades[1752].setIn(Items::minecraft::bowl, {1.0, 0.0});
	trades[1752].setIn(Items::minecraft::blue_orchid, {1.0, 0.0});
	trades[1752].setOut(Items::minecraft::suspicious_stew, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/suspicious_stew_from_closed_eyeblossom.json
	trades[1753].setIn(Items::minecraft::brown_mushroom, {1.0, 0.0});
	trades[1753].setIn(Items::minecraft::red_mushroom, {1.0, 0.0});
	trades[1753].setIn(Items::minecraft::bowl, {1.0, 0.0});
	trades[1753].setIn(Items::minecraft::closed_eyeblossom, {1.0, 0.0});
	trades[1753].setOut(Items::minecraft::suspicious_stew, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/suspicious_stew_from_cornflower.json
	trades[1754].setIn(Items::minecraft::brown_mushroom, {1.0, 0.0});
	trades[1754].setIn(Items::minecraft::red_mushroom, {1.0, 0.0});
	trades[1754].setIn(Items::minecraft::bowl, {1.0, 0.0});
	trades[1754].setIn(Items::minecraft::cornflower, {1.0, 0.0});
	trades[1754].setOut(Items::minecraft::suspicious_stew, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/suspicious_stew_from_dandelion.json
	trades[1755].setIn(Items::minecraft::brown_mushroom, {1.0, 0.0});
	trades[1755].setIn(Items::minecraft::red_mushroom, {1.0, 0.0});
	trades[1755].setIn(Items::minecraft::bowl, {1.0, 0.0});
	trades[1755].setIn(Items::minecraft::dandelion, {1.0, 0.0});
	trades[1755].setOut(Items::minecraft::suspicious_stew, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/suspicious_stew_from_lily_of_the_valley.json
	trades[1756].setIn(Items::minecraft::brown_mushroom, {1.0, 0.0});
	trades[1756].setIn(Items::minecraft::red_mushroom, {1.0, 0.0});
	trades[1756].setIn(Items::minecraft::bowl, {1.0, 0.0});
	trades[1756].setIn(Items::minecraft::lily_of_the_valley, {1.0, 0.0});
	trades[1756].setOut(Items::minecraft::suspicious_stew, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/suspicious_stew_from_open_eyeblossom.json
	trades[1757].setIn(Items::minecraft::brown_mushroom, {1.0, 0.0});
	trades[1757].setIn(Items::minecraft::red_mushroom, {1.0, 0.0});
	trades[1757].setIn(Items::minecraft::bowl, {1.0, 0.0});
	trades[1757].setIn(Items::minecraft::open_eyeblossom, {1.0, 0.0});
	trades[1757].setOut(Items::minecraft::suspicious_stew, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/suspicious_stew_from_oxeye_daisy.json
	trades[1758].setIn(Items::minecraft::brown_mushroom, {1.0, 0.0});
	trades[1758].setIn(Items::minecraft::red_mushroom, {1.0, 0.0});
	trades[1758].setIn(Items::minecraft::bowl, {1.0, 0.0});
	trades[1758].setIn(Items::minecraft::oxeye_daisy, {1.0, 0.0});
	trades[1758].setOut(Items::minecraft::suspicious_stew, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/suspicious_stew_from_poppy.json
	trades[1759].setIn(Items::minecraft::brown_mushroom, {1.0, 0.0});
	trades[1759].setIn(Items::minecraft::red_mushroom, {1.0, 0.0});
	trades[1759].setIn(Items::minecraft::bowl, {1.0, 0.0});
	trades[1759].setIn(Items::minecraft::poppy, {1.0, 0.0});
	trades[1759].setOut(Items::minecraft::suspicious_stew, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/suspicious_stew_from_torchflower.json
	trades[1760].setIn(Items::minecraft::brown_mushroom, {1.0, 0.0});
	trades[1760].setIn(Items::minecraft::red_mushroom, {1.0, 0.0});
	trades[1760].setIn(Items::minecraft::bowl, {1.0, 0.0});
	trades[1760].setIn(Items::minecraft::torchflower, {1.0, 0.0});
	trades[1760].setOut(Items::minecraft::suspicious_stew, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/suspicious_stew_from_tulip_orange.json
	trades[1761].setIn(Items::minecraft::brown_mushroom, {1.0, 0.0});
	trades[1761].setIn(Items::minecraft::red_mushroom, {1.0, 0.0});
	trades[1761].setIn(Items::minecraft::bowl, {1.0, 0.0});
	trades[1761].setIn(Items::minecraft::orange_tulip, {1.0, 0.0});
	trades[1761].setOut(Items::minecraft::suspicious_stew, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/suspicious_stew_from_tulip_pink.json
	trades[1762].setIn(Items::minecraft::brown_mushroom, {1.0, 0.0});
	trades[1762].setIn(Items::minecraft::red_mushroom, {1.0, 0.0});
	trades[1762].setIn(Items::minecraft::bowl, {1.0, 0.0});
	trades[1762].setIn(Items::minecraft::pink_tulip, {1.0, 0.0});
	trades[1762].setOut(Items::minecraft::suspicious_stew, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/suspicious_stew_from_tulip_red.json
	trades[1763].setIn(Items::minecraft::brown_mushroom, {1.0, 0.0});
	trades[1763].setIn(Items::minecraft::red_mushroom, {1.0, 0.0});
	trades[1763].setIn(Items::minecraft::bowl, {1.0, 0.0});
	trades[1763].setIn(Items::minecraft::red_tulip, {1.0, 0.0});
	trades[1763].setOut(Items::minecraft::suspicious_stew, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/suspicious_stew_from_tulip_white.json
	trades[1764].setIn(Items::minecraft::brown_mushroom, {1.0, 0.0});
	trades[1764].setIn(Items::minecraft::red_mushroom, {1.0, 0.0});
	trades[1764].setIn(Items::minecraft::bowl, {1.0, 0.0});
	trades[1764].setIn(Items::minecraft::white_tulip, {1.0, 0.0});
	trades[1764].setOut(Items::minecraft::suspicious_stew, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/suspicious_stew_from_wither_rose.json
	trades[1765].setIn(Items::minecraft::brown_mushroom, {1.0, 0.0});
	trades[1765].setIn(Items::minecraft::red_mushroom, {1.0, 0.0});
	trades[1765].setIn(Items::minecraft::bowl, {1.0, 0.0});
	trades[1765].setIn(Items::minecraft::wither_rose, {1.0, 0.0});
	trades[1765].setOut(Items::minecraft::suspicious_stew, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/target_block.json
	trades[1766].setIn(Items::minecraft::hay_block, {1.0, 0.0});
	trades[1766].setIn(Items::minecraft::redstone, {4.0, 0.0});
	trades[1766].setOut(Items::minecraft::target, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/tide_armor_trim_smithing_template_duplicate.json
	trades[1767].setIn(Items::minecraft::tide_armor_trim_smithing_template, {1.0, 0.0});
	trades[1767].setIn(Items::minecraft::diamond, {7.0, 0.0});
	trades[1767].setIn(Items::minecraft::prismarine, {1.0, 0.0});
	trades[1767].setOut(Items::minecraft::tide_armor_trim_smithing_template, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/tinted_glass.json
	trades[1768].setIn(Items::minecraft::amethyst_shard, {4.0, 0.0});
	trades[1768].setIn(Items::minecraft::glass, {1.0, 0.0});
	trades[1768].setOut(Items::minecraft::tinted_glass, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/tnt.json
	trades[1769].setIn(Items::minecraft::sand, {4.0, 0.0});
	trades[1769].setIn(Items::minecraft::gunpowder, {5.0, 0.0});
	trades[1769].setOut(Items::minecraft::tnt, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/tnt_minecart.json
	trades[1770].setIn(Items::minecraft::tnt, {1.0, 0.0});
	trades[1770].setIn(Items::minecraft::minecart, {1.0, 0.0});
	trades[1770].setOut(Items::minecraft::tnt_minecart, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/torch_charcoal.json
	trades[1771].setIn(Items::minecraft::stick, {1.0, 0.0});
	trades[1771].setIn(Items::minecraft::charcoal, {1.0, 0.0});
	trades[1771].setOut(Items::minecraft::torch, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/torch_coal.json
	trades[1772].setIn(Items::minecraft::stick, {1.0, 0.0});
	trades[1772].setIn(Items::minecraft::coal, {1.0, 0.0});
	trades[1772].setOut(Items::minecraft::torch, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/torch.json
	trades[1773].setIn(Items::minecraft::stick, {1.0, 0.0});
	trades[1773].setIn(Items::minecraft::coals, {1.0, 0.0});
	trades[1773].setOut(Items::minecraft::torch, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/trapped_chest.json
	trades[1774].setIn(Items::minecraft::chest, {1.0, 0.0});
	trades[1774].setIn(Items::minecraft::tripwire_hook, {1.0, 0.0});
	trades[1774].setOut(Items::minecraft::trapped_chest, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/tripwire_hook_from_crimson_planks.json
	trades[1775].setIn(Items::minecraft::iron_ingot, {1.0, 0.0});
	trades[1775].setIn(Items::minecraft::stick, {1.0, 0.0});
	trades[1775].setIn(Items::minecraft::crimson_planks, {1.0, 0.0});
	trades[1775].setOut(Items::minecraft::tripwire_hook, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/tripwire_hook_from_mangrove_planks.json
	trades[1776].setIn(Items::minecraft::iron_ingot, {1.0, 0.0});
	trades[1776].setIn(Items::minecraft::stick, {1.0, 0.0});
	trades[1776].setIn(Items::minecraft::mangrove_planks, {1.0, 0.0});
	trades[1776].setOut(Items::minecraft::tripwire_hook, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/tripwire_hook_from_warped_planks.json
	trades[1777].setIn(Items::minecraft::iron_ingot, {1.0, 0.0});
	trades[1777].setIn(Items::minecraft::stick, {1.0, 0.0});
	trades[1777].setIn(Items::minecraft::warped_planks, {1.0, 0.0});
	trades[1777].setOut(Items::minecraft::tripwire_hook, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/tripwire_hook.json
	trades[1778].setIn(Items::minecraft::iron_ingot, {1.0, 0.0});
	trades[1778].setIn(Items::minecraft::stick, {1.0, 0.0});
	trades[1778].setIn(Items::minecraft::planks, {1.0, 0.0});
	trades[1778].setOut(Items::minecraft::tripwire_hook, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/tuff_bricks.json
	trades[1779].setIn(Items::minecraft::polished_tuff, {4.0, 0.0});
	trades[1779].setOut(Items::minecraft::tuff_bricks, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/tuff_brick_slab.json
	trades[1780].setIn(Items::minecraft::tuff_bricks, {3.0, 0.0});
	trades[1780].setOut(Items::minecraft::tuff_brick_slab, 6.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/tuff_brick_stairs.json
	trades[1781].setIn(Items::minecraft::tuff_bricks, {6.0, 0.0});
	trades[1781].setOut(Items::minecraft::tuff_brick_stairs, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/tuff_brick_wall.json
	trades[1782].setIn(Items::minecraft::tuff_bricks, {6.0, 0.0});
	trades[1782].setOut(Items::minecraft::tuff_brick_wall, 6.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/tuff_slab.json
	trades[1783].setIn(Items::minecraft::tuff, {3.0, 0.0});
	trades[1783].setOut(Items::minecraft::tuff_slab, 6.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/tuff_stairs.json
	trades[1784].setIn(Items::minecraft::tuff, {6.0, 0.0});
	trades[1784].setOut(Items::minecraft::tuff_stairs, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/tuff_wall.json
	trades[1785].setIn(Items::minecraft::tuff, {6.0, 0.0});
	trades[1785].setOut(Items::minecraft::tuff_wall, 6.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/turtle_helmet.json
	trades[1786].setIn(Items::minecraft::turtle_shell_piece, {5.0, 0.0});
	trades[1786].setOut(Items::minecraft::turtle_helmet, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/vex_armor_trim_smithing_template_duplicate.json
	trades[1787].setIn(Items::minecraft::vex_armor_trim_smithing_template, {1.0, 0.0});
	trades[1787].setIn(Items::minecraft::diamond, {7.0, 0.0});
	trades[1787].setIn(Items::minecraft::cobblestone, {1.0, 0.0});
	trades[1787].setOut(Items::minecraft::vex_armor_trim_smithing_template, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/ward_armor_trim_smithing_template_duplicate.json
	trades[1788].setIn(Items::minecraft::ward_armor_trim_smithing_template, {1.0, 0.0});
	trades[1788].setIn(Items::minecraft::diamond, {7.0, 0.0});
	trades[1788].setIn(Items::minecraft::cobbled_deepslate, {1.0, 0.0});
	trades[1788].setOut(Items::minecraft::ward_armor_trim_smithing_template, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/warped_button.json
	trades[1789].setIn(Items::minecraft::warped_planks, {1.0, 0.0});
	trades[1789].setOut(Items::minecraft::warped_button, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/warped_door.json
	trades[1790].setIn(Items::minecraft::warped_planks, {6.0, 0.0});
	trades[1790].setOut(Items::minecraft::warped_door, 3.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/warped_fence_gate.json
	trades[1791].setIn(Items::minecraft::stick, {4.0, 0.0});
	trades[1791].setIn(Items::minecraft::warped_planks, {2.0, 0.0});
	trades[1791].setOut(Items::minecraft::warped_fence_gate, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/warped_fence.json
	trades[1792].setIn(Items::minecraft::stick, {2.0, 0.0});
	trades[1792].setIn(Items::minecraft::warped_planks, {4.0, 0.0});
	trades[1792].setOut(Items::minecraft::warped_fence, 3.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/warped_fungus_on_a_stick.json
	trades[1793].setIn(Items::minecraft::fishing_rod, {1.0, 0.0});
	trades[1793].setIn(Items::minecraft::warped_fungus, {1.0, 0.0});
	trades[1793].setOut(Items::minecraft::warped_fungus_on_a_stick, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/warped_hanging_sign.json
	trades[1794].setIn(Items::minecraft::stripped_warped_stem, {6.0, 0.0});
	trades[1794].setIn(Items::minecraft::chain, {2.0, 0.0});
	trades[1794].setOut(Items::minecraft::warped_hanging_sign, 6.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/warped_hyphae.json
	trades[1795].setIn(Items::minecraft::warped_stem, {4.0, 0.0});
	trades[1795].setOut(Items::minecraft::warped_hyphae, 3.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/warped_hyphae_stripped.json
	trades[1796].setIn(Items::minecraft::stripped_warped_stem, {4.0, 0.0});
	trades[1796].setOut(Items::minecraft::stripped_warped_hyphae, 3.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/warped_planks_from_stripped_log.json
	trades[1797].setIn(Items::minecraft::stripped_warped_stem, {1.0, 0.0});
	trades[1797].setOut(Items::minecraft::warped_planks, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/warped_planks_from_stripped_warped_hyphae.json
	trades[1798].setIn(Items::minecraft::stripped_warped_hyphae, {1.0, 0.0});
	trades[1798].setOut(Items::minecraft::warped_planks, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/warped_planks_from_warped_hyphae.json
	trades[1799].setIn(Items::minecraft::warped_hyphae, {1.0, 0.0});
	trades[1799].setOut(Items::minecraft::warped_planks, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/warped_planks.json
	trades[1800].setIn(Items::minecraft::warped_stem, {1.0, 0.0});
	trades[1800].setOut(Items::minecraft::warped_planks, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/warped_pressure_plate.json
	trades[1801].setIn(Items::minecraft::warped_planks, {2.0, 0.0});
	trades[1801].setOut(Items::minecraft::warped_pressure_plate, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/warped_sign.json
	trades[1802].setIn(Items::minecraft::warped_planks, {6.0, 0.0});
	trades[1802].setIn(Items::minecraft::stick, {1.0, 0.0});
	trades[1802].setOut(Items::minecraft::warped_sign, 3.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/warped_slab.json
	trades[1803].setIn(Items::minecraft::warped_planks, {3.0, 0.0});
	trades[1803].setOut(Items::minecraft::warped_slab, 6.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/warped_stairs.json
	trades[1804].setIn(Items::minecraft::warped_planks, {6.0, 0.0});
	trades[1804].setOut(Items::minecraft::warped_stairs, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/warped_trapdoor.json
	trades[1805].setIn(Items::minecraft::warped_planks, {6.0, 0.0});
	trades[1805].setOut(Items::minecraft::warped_trapdoor, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/waxing_chiseled_copper.json
	trades[1806].setIn(Items::minecraft::chiseled_copper, {1.0, 0.0});
	trades[1806].setIn(Items::minecraft::honeycomb, {1.0, 0.0});
	trades[1806].setOut(Items::minecraft::waxed_chiseled_copper, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/waxing_copper_block.json
	trades[1807].setIn(Items::minecraft::copper_block, {1.0, 0.0});
	trades[1807].setIn(Items::minecraft::honeycomb, {1.0, 0.0});
	trades[1807].setOut(Items::minecraft::waxed_copper, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/waxing_copper_bulb.json
	trades[1808].setIn(Items::minecraft::copper_bulb, {1.0, 0.0});
	trades[1808].setIn(Items::minecraft::honeycomb, {1.0, 0.0});
	trades[1808].setOut(Items::minecraft::waxed_copper_bulb, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/waxing_copper_door.json
	trades[1809].setIn(Items::minecraft::copper_door, {1.0, 0.0});
	trades[1809].setIn(Items::minecraft::honeycomb, {1.0, 0.0});
	trades[1809].setOut(Items::minecraft::waxed_copper_door, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/waxing_copper_grate.json
	trades[1810].setIn(Items::minecraft::copper_grate, {1.0, 0.0});
	trades[1810].setIn(Items::minecraft::honeycomb, {1.0, 0.0});
	trades[1810].setOut(Items::minecraft::waxed_copper_grate, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/waxing_copper_trapdoor.json
	trades[1811].setIn(Items::minecraft::copper_trapdoor, {1.0, 0.0});
	trades[1811].setIn(Items::minecraft::honeycomb, {1.0, 0.0});
	trades[1811].setOut(Items::minecraft::waxed_copper_trapdoor, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/waxing_cut_copper_block.json
	trades[1812].setIn(Items::minecraft::cut_copper, {1.0, 0.0});
	trades[1812].setIn(Items::minecraft::honeycomb, {1.0, 0.0});
	trades[1812].setOut(Items::minecraft::waxed_cut_copper, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/waxing_cut_copper_slab.json
	trades[1813].setIn(Items::minecraft::cut_copper_slab, {1.0, 0.0});
	trades[1813].setIn(Items::minecraft::honeycomb, {1.0, 0.0});
	trades[1813].setOut(Items::minecraft::waxed_cut_copper_slab, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/waxing_cut_copper_stairs.json
	trades[1814].setIn(Items::minecraft::cut_copper_stairs, {1.0, 0.0});
	trades[1814].setIn(Items::minecraft::honeycomb, {1.0, 0.0});
	trades[1814].setOut(Items::minecraft::waxed_cut_copper_stairs, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/waxing_exposed_chiseled_copper.json
	trades[1815].setIn(Items::minecraft::exposed_chiseled_copper, {1.0, 0.0});
	trades[1815].setIn(Items::minecraft::honeycomb, {1.0, 0.0});
	trades[1815].setOut(Items::minecraft::waxed_exposed_chiseled_copper, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/waxing_exposed_copper_block.json
	trades[1816].setIn(Items::minecraft::exposed_copper, {1.0, 0.0});
	trades[1816].setIn(Items::minecraft::honeycomb, {1.0, 0.0});
	trades[1816].setOut(Items::minecraft::waxed_exposed_copper, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/waxing_exposed_copper_bulb.json
	trades[1817].setIn(Items::minecraft::exposed_copper_bulb, {1.0, 0.0});
	trades[1817].setIn(Items::minecraft::honeycomb, {1.0, 0.0});
	trades[1817].setOut(Items::minecraft::waxed_exposed_copper_bulb, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/waxing_exposed_copper_door.json
	trades[1818].setIn(Items::minecraft::exposed_copper_door, {1.0, 0.0});
	trades[1818].setIn(Items::minecraft::honeycomb, {1.0, 0.0});
	trades[1818].setOut(Items::minecraft::waxed_exposed_copper_door, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/waxing_exposed_copper_grate.json
	trades[1819].setIn(Items::minecraft::exposed_copper_grate, {1.0, 0.0});
	trades[1819].setIn(Items::minecraft::honeycomb, {1.0, 0.0});
	trades[1819].setOut(Items::minecraft::waxed_exposed_copper_grate, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/waxing_exposed_copper_trapdoor.json
	trades[1820].setIn(Items::minecraft::exposed_copper_trapdoor, {1.0, 0.0});
	trades[1820].setIn(Items::minecraft::honeycomb, {1.0, 0.0});
	trades[1820].setOut(Items::minecraft::waxed_exposed_copper_trapdoor, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/waxing_exposed_cut_copper_block.json
	trades[1821].setIn(Items::minecraft::exposed_cut_copper, {1.0, 0.0});
	trades[1821].setIn(Items::minecraft::honeycomb, {1.0, 0.0});
	trades[1821].setOut(Items::minecraft::waxed_exposed_cut_copper, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/waxing_exposed_cut_copper_slab.json
	trades[1822].setIn(Items::minecraft::exposed_cut_copper_slab, {1.0, 0.0});
	trades[1822].setIn(Items::minecraft::honeycomb, {1.0, 0.0});
	trades[1822].setOut(Items::minecraft::waxed_exposed_cut_copper_slab, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/waxing_exposed_cut_copper_stairs.json
	trades[1823].setIn(Items::minecraft::exposed_cut_copper_stairs, {1.0, 0.0});
	trades[1823].setIn(Items::minecraft::honeycomb, {1.0, 0.0});
	trades[1823].setOut(Items::minecraft::waxed_exposed_cut_copper_stairs, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/waxing_oxidized_chiseled_copper.json
	trades[1824].setIn(Items::minecraft::oxidized_chiseled_copper, {1.0, 0.0});
	trades[1824].setIn(Items::minecraft::honeycomb, {1.0, 0.0});
	trades[1824].setOut(Items::minecraft::waxed_oxidized_chiseled_copper, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/waxing_oxidized_copper_block.json
	trades[1825].setIn(Items::minecraft::oxidized_copper, {1.0, 0.0});
	trades[1825].setIn(Items::minecraft::honeycomb, {1.0, 0.0});
	trades[1825].setOut(Items::minecraft::waxed_oxidized_copper, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/waxing_oxidized_copper_bulb.json
	trades[1826].setIn(Items::minecraft::oxidized_copper_bulb, {1.0, 0.0});
	trades[1826].setIn(Items::minecraft::honeycomb, {1.0, 0.0});
	trades[1826].setOut(Items::minecraft::waxed_oxidized_copper_bulb, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/waxing_oxidized_copper_door.json
	trades[1827].setIn(Items::minecraft::oxidized_copper_door, {1.0, 0.0});
	trades[1827].setIn(Items::minecraft::honeycomb, {1.0, 0.0});
	trades[1827].setOut(Items::minecraft::waxed_oxidized_copper_door, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/waxing_oxidized_copper_grate.json
	trades[1828].setIn(Items::minecraft::oxidized_copper_grate, {1.0, 0.0});
	trades[1828].setIn(Items::minecraft::honeycomb, {1.0, 0.0});
	trades[1828].setOut(Items::minecraft::waxed_oxidized_copper_grate, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/waxing_oxidized_copper_trapdoor.json
	trades[1829].setIn(Items::minecraft::oxidized_copper_trapdoor, {1.0, 0.0});
	trades[1829].setIn(Items::minecraft::honeycomb, {1.0, 0.0});
	trades[1829].setOut(Items::minecraft::waxed_oxidized_copper_trapdoor, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/waxing_oxidized_cut_copper_block.json
	trades[1830].setIn(Items::minecraft::oxidized_cut_copper, {1.0, 0.0});
	trades[1830].setIn(Items::minecraft::honeycomb, {1.0, 0.0});
	trades[1830].setOut(Items::minecraft::waxed_oxidized_cut_copper, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/waxing_oxidized_cut_copper_slab.json
	trades[1831].setIn(Items::minecraft::oxidized_cut_copper_slab, {1.0, 0.0});
	trades[1831].setIn(Items::minecraft::honeycomb, {1.0, 0.0});
	trades[1831].setOut(Items::minecraft::waxed_oxidized_cut_copper_slab, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/waxing_oxidized_cut_copper_stairs.json
	trades[1832].setIn(Items::minecraft::oxidized_cut_copper_stairs, {1.0, 0.0});
	trades[1832].setIn(Items::minecraft::honeycomb, {1.0, 0.0});
	trades[1832].setOut(Items::minecraft::waxed_oxidized_cut_copper_stairs, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/waxing_weathered_chiseled_copper.json
	trades[1833].setIn(Items::minecraft::weathered_chiseled_copper, {1.0, 0.0});
	trades[1833].setIn(Items::minecraft::honeycomb, {1.0, 0.0});
	trades[1833].setOut(Items::minecraft::waxed_weathered_chiseled_copper, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/waxing_weathered_copper_block.json
	trades[1834].setIn(Items::minecraft::weathered_copper, {1.0, 0.0});
	trades[1834].setIn(Items::minecraft::honeycomb, {1.0, 0.0});
	trades[1834].setOut(Items::minecraft::waxed_weathered_copper, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/waxing_weathered_copper_bulb.json
	trades[1835].setIn(Items::minecraft::weathered_copper_bulb, {1.0, 0.0});
	trades[1835].setIn(Items::minecraft::honeycomb, {1.0, 0.0});
	trades[1835].setOut(Items::minecraft::waxed_weathered_copper_bulb, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/waxing_weathered_copper_door.json
	trades[1836].setIn(Items::minecraft::weathered_copper_door, {1.0, 0.0});
	trades[1836].setIn(Items::minecraft::honeycomb, {1.0, 0.0});
	trades[1836].setOut(Items::minecraft::waxed_weathered_copper_door, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/waxing_weathered_copper_grate.json
	trades[1837].setIn(Items::minecraft::weathered_copper_grate, {1.0, 0.0});
	trades[1837].setIn(Items::minecraft::honeycomb, {1.0, 0.0});
	trades[1837].setOut(Items::minecraft::waxed_weathered_copper_grate, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/waxing_weathered_copper_trapdoor.json
	trades[1838].setIn(Items::minecraft::weathered_copper_trapdoor, {1.0, 0.0});
	trades[1838].setIn(Items::minecraft::honeycomb, {1.0, 0.0});
	trades[1838].setOut(Items::minecraft::waxed_weathered_copper_trapdoor, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/waxing_weathered_cut_copper_block.json
	trades[1839].setIn(Items::minecraft::weathered_cut_copper, {1.0, 0.0});
	trades[1839].setIn(Items::minecraft::honeycomb, {1.0, 0.0});
	trades[1839].setOut(Items::minecraft::waxed_weathered_cut_copper, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/waxing_weathered_cut_copper_slab.json
	trades[1840].setIn(Items::minecraft::weathered_cut_copper_slab, {1.0, 0.0});
	trades[1840].setIn(Items::minecraft::honeycomb, {1.0, 0.0});
	trades[1840].setOut(Items::minecraft::waxed_weathered_cut_copper_slab, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/waxing_weathered_cut_copper_stairs.json
	trades[1841].setIn(Items::minecraft::weathered_cut_copper_stairs, {1.0, 0.0});
	trades[1841].setIn(Items::minecraft::honeycomb, {1.0, 0.0});
	trades[1841].setOut(Items::minecraft::waxed_weathered_cut_copper_stairs, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/wayfinder_armor_trim_smithing_template_duplicate.json
	trades[1842].setIn(Items::minecraft::wayfinder_armor_trim_smithing_template, {1.0, 0.0});
	trades[1842].setIn(Items::minecraft::diamond, {7.0, 0.0});
	trades[1842].setIn(Items::minecraft::hardened_clay, {1.0, 0.0});
	trades[1842].setOut(Items::minecraft::wayfinder_armor_trim_smithing_template, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/wheat.json
	trades[1843].setIn(Items::minecraft::hay_block, {1.0, 0.0});
	trades[1843].setOut(Items::minecraft::wheat, 9.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/white_banner.json
	trades[1844].setIn(Items::minecraft::white_wool, {6.0, 0.0});
	trades[1844].setIn(Items::minecraft::stick, {1.0, 0.0});
	trades[1844].setOut(Items::minecraft::banner, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/white_candle_from_bonemeal.json
	trades[1845].setIn(Items::minecraft::candle, {1.0, 0.0});
	trades[1845].setIn(Items::minecraft::dye, {1.0, 0.0});
	trades[1845].setOut(Items::minecraft::white_candle, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/white_candle.json
	trades[1846].setIn(Items::minecraft::candle, {1.0, 0.0});
	trades[1846].setIn(Items::minecraft::dye, {1.0, 0.0});
	trades[1846].setOut(Items::minecraft::white_candle, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/white_carpet.json
	trades[1847].setIn(Items::minecraft::white_wool, {2.0, 0.0});
	trades[1847].setOut(Items::minecraft::white_carpet, 3.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/white_concrete_powder_from_bonemeal.json
	trades[1848].setIn(Items::minecraft::bone_meal, {1.0, 0.0});
	trades[1848].setIn(Items::minecraft::sand, {4.0, 0.0});
	trades[1848].setIn(Items::minecraft::gravel, {4.0, 0.0});
	trades[1848].setOut(Items::minecraft::white_concrete_powder, 8.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/white_concrete_powder.json
	trades[1849].setIn(Items::minecraft::white_dye, {1.0, 0.0});
	trades[1849].setIn(Items::minecraft::sand, {4.0, 0.0});
	trades[1849].setIn(Items::minecraft::gravel, {4.0, 0.0});
	trades[1849].setOut(Items::minecraft::white_concrete_powder, 8.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/white_dye_from_bone_meal.json
	trades[1850].setIn(Items::minecraft::dye, {1.0, 0.0});
	trades[1850].setOut(Items::minecraft::dye, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/white_dye_from_lily_of_the_valley.json
	trades[1851].setIn(Items::minecraft::lily_of_the_valley, {1.0, 0.0});
	trades[1851].setOut(Items::minecraft::dye, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/white_stained_glass_from_bonemeal.json
	trades[1852].setIn(Items::minecraft::glass, {8.0, 0.0});
	trades[1852].setIn(Items::minecraft::bone_meal, {1.0, 0.0});
	trades[1852].setOut(Items::minecraft::white_stained_glass, 8.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/white_stained_glass.json
	trades[1853].setIn(Items::minecraft::glass, {8.0, 0.0});
	trades[1853].setIn(Items::minecraft::white_dye, {1.0, 0.0});
	trades[1853].setOut(Items::minecraft::white_stained_glass, 8.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/white_stained_glass_pane_from_pane.json
	trades[1854].setIn(Items::minecraft::glass_pane, {8.0, 0.0});
	trades[1854].setIn(Items::minecraft::white_dye, {1.0, 0.0});
	trades[1854].setOut(Items::minecraft::white_stained_glass_pane, 8.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/white_stained_glass_pane.json
	trades[1855].setIn(Items::minecraft::white_stained_glass, {6.0, 0.0});
	trades[1855].setOut(Items::minecraft::white_stained_glass_pane, 16.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/white_stained_hardened_clay_from_bonemeal.json
	trades[1856].setIn(Items::minecraft::hardened_clay, {8.0, 0.0});
	trades[1856].setIn(Items::minecraft::bone_meal, {1.0, 0.0});
	trades[1856].setOut(Items::minecraft::white_terracotta, 8.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/white_stained_hardened_clay.json
	trades[1857].setIn(Items::minecraft::hardened_clay, {8.0, 0.0});
	trades[1857].setIn(Items::minecraft::white_dye, {1.0, 0.0});
	trades[1857].setOut(Items::minecraft::white_terracotta, 8.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/whtie_candle_from_bonemeal.json
	trades[1858].setIn(Items::minecraft::candle, {1.0, 0.0});
	trades[1858].setIn(Items::minecraft::dye, {1.0, 0.0});
	trades[1858].setOut(Items::minecraft::white_candle, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/wild_armor_trim_smithing_template_duplicate.json
	trades[1859].setIn(Items::minecraft::wild_armor_trim_smithing_template, {1.0, 0.0});
	trades[1859].setIn(Items::minecraft::diamond, {7.0, 0.0});
	trades[1859].setIn(Items::minecraft::mossy_cobblestone, {1.0, 0.0});
	trades[1859].setOut(Items::minecraft::wild_armor_trim_smithing_template, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/wind_charge.json
	trades[1860].setIn(Items::minecraft::breeze_rod, {1.0, 0.0});
	trades[1860].setOut(Items::minecraft::wind_charge, 4.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/wolf_armor.json
	trades[1861].setIn(Items::minecraft::armadillo_scute, {6.0, 0.0});
	trades[1861].setOut(Items::minecraft::wolf_armor, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/wooden_axe_from_crimson_planks.json
	trades[1862].setIn(Items::minecraft::crimson_planks, {3.0, 0.0});
	trades[1862].setIn(Items::minecraft::stick, {2.0, 0.0});
	trades[1862].setOut(Items::minecraft::wooden_axe, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/wooden_axe_from_mangrove_planks.json
	trades[1863].setIn(Items::minecraft::mangrove_planks, {3.0, 0.0});
	trades[1863].setIn(Items::minecraft::stick, {2.0, 0.0});
	trades[1863].setOut(Items::minecraft::wooden_axe, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/wooden_axe_from_warped_planks.json
	trades[1864].setIn(Items::minecraft::warped_planks, {3.0, 0.0});
	trades[1864].setIn(Items::minecraft::stick, {2.0, 0.0});
	trades[1864].setOut(Items::minecraft::wooden_axe, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/wooden_axe.json
	trades[1865].setIn(Items::minecraft::stick, {2.0, 0.0});
	trades[1865].setIn(Items::minecraft::planks, {3.0, 0.0});
	trades[1865].setOut(Items::minecraft::wooden_axe, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/wooden_door.json
	trades[1866].setIn(Items::minecraft::oak_planks, {6.0, 0.0});
	trades[1866].setOut(Items::minecraft::wooden_door, 3.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/wooden_hoe_from_crimson_planks.json
	trades[1867].setIn(Items::minecraft::crimson_planks, {2.0, 0.0});
	trades[1867].setIn(Items::minecraft::stick, {2.0, 0.0});
	trades[1867].setOut(Items::minecraft::wooden_hoe, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/wooden_hoe_from_mangrove_planks.json
	trades[1868].setIn(Items::minecraft::mangrove_planks, {2.0, 0.0});
	trades[1868].setIn(Items::minecraft::stick, {2.0, 0.0});
	trades[1868].setOut(Items::minecraft::wooden_hoe, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/wooden_hoe_from_warped_planks.json
	trades[1869].setIn(Items::minecraft::warped_planks, {2.0, 0.0});
	trades[1869].setIn(Items::minecraft::stick, {2.0, 0.0});
	trades[1869].setOut(Items::minecraft::wooden_hoe, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/wooden_hoe.json
	trades[1870].setIn(Items::minecraft::stick, {2.0, 0.0});
	trades[1870].setIn(Items::minecraft::planks, {2.0, 0.0});
	trades[1870].setOut(Items::minecraft::wooden_hoe, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/wooden_pickaxe_from_crimson_planks.json
	trades[1871].setIn(Items::minecraft::crimson_planks, {3.0, 0.0});
	trades[1871].setIn(Items::minecraft::stick, {2.0, 0.0});
	trades[1871].setOut(Items::minecraft::wooden_pickaxe, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/wooden_pickaxe_from_mangrove_planks.json
	trades[1872].setIn(Items::minecraft::mangrove_planks, {3.0, 0.0});
	trades[1872].setIn(Items::minecraft::stick, {2.0, 0.0});
	trades[1872].setOut(Items::minecraft::wooden_pickaxe, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/wooden_pickaxe_from_warped_planks.json
	trades[1873].setIn(Items::minecraft::warped_planks, {3.0, 0.0});
	trades[1873].setIn(Items::minecraft::stick, {2.0, 0.0});
	trades[1873].setOut(Items::minecraft::wooden_pickaxe, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/wooden_pickaxe.json
	trades[1874].setIn(Items::minecraft::stick, {2.0, 0.0});
	trades[1874].setIn(Items::minecraft::planks, {3.0, 0.0});
	trades[1874].setOut(Items::minecraft::wooden_pickaxe, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/wooden_shovel_from_crimson_planks.json
	trades[1875].setIn(Items::minecraft::crimson_planks, {1.0, 0.0});
	trades[1875].setIn(Items::minecraft::stick, {2.0, 0.0});
	trades[1875].setOut(Items::minecraft::wooden_shovel, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/wooden_shovel_from_mangrove_planks.json
	trades[1876].setIn(Items::minecraft::mangrove_planks, {1.0, 0.0});
	trades[1876].setIn(Items::minecraft::stick, {2.0, 0.0});
	trades[1876].setOut(Items::minecraft::wooden_shovel, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/wooden_shovel_from_warped_planks.json
	trades[1877].setIn(Items::minecraft::warped_planks, {1.0, 0.0});
	trades[1877].setIn(Items::minecraft::stick, {2.0, 0.0});
	trades[1877].setOut(Items::minecraft::wooden_shovel, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/wooden_shovel.json
	trades[1878].setIn(Items::minecraft::stick, {2.0, 0.0});
	trades[1878].setIn(Items::minecraft::planks, {1.0, 0.0});
	trades[1878].setOut(Items::minecraft::wooden_shovel, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/wooden_sword_from_crimson_planks.json
	trades[1879].setIn(Items::minecraft::crimson_planks, {2.0, 0.0});
	trades[1879].setIn(Items::minecraft::stick, {1.0, 0.0});
	trades[1879].setOut(Items::minecraft::wooden_sword, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/wooden_sword_from_mangrove_planks.json
	trades[1880].setIn(Items::minecraft::mangrove_planks, {2.0, 0.0});
	trades[1880].setIn(Items::minecraft::stick, {1.0, 0.0});
	trades[1880].setOut(Items::minecraft::wooden_sword, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/wooden_sword_from_warped_planks.json
	trades[1881].setIn(Items::minecraft::warped_planks, {2.0, 0.0});
	trades[1881].setIn(Items::minecraft::stick, {1.0, 0.0});
	trades[1881].setOut(Items::minecraft::wooden_sword, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/wooden_sword.json
	trades[1882].setIn(Items::minecraft::stick, {1.0, 0.0});
	trades[1882].setIn(Items::minecraft::planks, {2.0, 0.0});
	trades[1882].setOut(Items::minecraft::wooden_sword, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/writable_book.json
	trades[1883].setIn(Items::minecraft::book, {1.0, 0.0});
	trades[1883].setIn(Items::minecraft::dye, {1.0, 0.0});
	trades[1883].setIn(Items::minecraft::feather, {1.0, 0.0});
	trades[1883].setOut(Items::minecraft::writable_book, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/yellow_banner.json
	trades[1884].setIn(Items::minecraft::yellow_wool, {6.0, 0.0});
	trades[1884].setIn(Items::minecraft::stick, {1.0, 0.0});
	trades[1884].setOut(Items::minecraft::banner, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/yellow_candle.json
	trades[1885].setIn(Items::minecraft::candle, {1.0, 0.0});
	trades[1885].setIn(Items::minecraft::dye, {1.0, 0.0});
	trades[1885].setOut(Items::minecraft::yellow_candle, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/yellow_carpet_from_white.json
	trades[1886].setIn(Items::minecraft::white_carpet, {8.0, 0.0});
	trades[1886].setIn(Items::minecraft::yellow_dye, {1.0, 0.0});
	trades[1886].setOut(Items::minecraft::yellow_carpet, 8.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/yellow_carpet.json
	trades[1887].setIn(Items::minecraft::yellow_wool, {2.0, 0.0});
	trades[1887].setOut(Items::minecraft::yellow_carpet, 3.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/yellow_concrete_powder.json
	trades[1888].setIn(Items::minecraft::yellow_dye, {1.0, 0.0});
	trades[1888].setIn(Items::minecraft::sand, {4.0, 0.0});
	trades[1888].setIn(Items::minecraft::gravel, {4.0, 0.0});
	trades[1888].setOut(Items::minecraft::yellow_concrete_powder, 8.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/yellow_dye_from_dandelion.json
	trades[1889].setIn(Items::minecraft::dandelion, {1.0, 0.0});
	trades[1889].setOut(Items::minecraft::dye, 1.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/yellow_dye_from_sunflower.json
	trades[1890].setIn(Items::minecraft::sunflower, {1.0, 0.0});
	trades[1890].setOut(Items::minecraft::yellow_dye, 2.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/yellow_stained_glass.json
	trades[1891].setIn(Items::minecraft::glass, {8.0, 0.0});
	trades[1891].setIn(Items::minecraft::yellow_dye, {1.0, 0.0});
	trades[1891].setOut(Items::minecraft::yellow_stained_glass, 8.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/yellow_stained_glass_pane_from_pane.json
	trades[1892].setIn(Items::minecraft::glass_pane, {8.0, 0.0});
	trades[1892].setIn(Items::minecraft::yellow_dye, {1.0, 0.0});
	trades[1892].setOut(Items::minecraft::yellow_stained_glass_pane, 8.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/yellow_stained_glass_pane.json
	trades[1893].setIn(Items::minecraft::yellow_stained_glass, {6.0, 0.0});
	trades[1893].setOut(Items::minecraft::yellow_stained_glass_pane, 16.0);

	// mojang/bedrock-samples-main/behavior_pack/recipes/yellow_stained_hardened_clay.json
	trades[1894].setIn(Items::minecraft::hardened_clay, {8.0, 0.0});
	trades[1894].setIn(Items::minecraft::yellow_dye, {1.0, 0.0});
	trades[1894].setOut(Items::minecraft::yellow_terracotta, 8.0);

	std::cout << std::endl << inventory << std::endl;
	for (auto& trade : trades) {
		std::cout << trade << std::endl;
	}

	for (size_t i = 0; i < population; ++i) {
		setWeights(weight + (i * Items::trades));
	}

	if (good(inventory, trades)) {
		for (size_t i = 0; i < population; ++i) {
			setWeights(trades, weight + (i * Items::trades));

			inventory.restore();
			for (size_t j = 0; j < 1000; ++j) {
				for (auto& trade : trades) {
					trade.on(inventory);
				}

				inventory.commit();
			}

			std::cout << std::endl << inventory << std::endl;
		}
	}

	return 0;
}
