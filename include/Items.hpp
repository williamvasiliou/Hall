#ifndef ITEMS_H
#define ITEMS_H

#include <algorithm>
#include <cstddef>
#include <iterator>
#include <string>

namespace Items {
	static const size_t size = 1019;

	typedef struct {
		const std::string name;
		const double rate;
		const size_t index;
		const size_t size;
	} Item;

	static const Item item[size] {
		{"acacia_boat", 0.0, 497, 1},
		{"acacia_door", 0.0, 0, 0},
		{"acacia_fence", 0.0, 0, 0},
		{"acacia_fence_gate", 0.0, 0, 0},
		{"acacia_hanging_sign", 0.0, 0, 0},
		{"acacia_log", 0.0, 1066, 2},
		{"acacia_planks", 0.0, 1014, 7},
		{"acacia_sapling", 0.0, 0, 0},
		{"acacia_sign", 0.0, 0, 0},
		{"acacia_slab", 0.0, 0, 0},
		{"acacia_stairs", 0.0, 0, 0},
		{"acacia_wood", 0.0, 1065, 1},
		{"activator_rail", 0.0, 0, 0},
		{"allium", 0.0, 2433, 2},
		{"amethyst_block", 0.0, 0, 0},
		{"amethyst_shard", 0.0, 1071, 4},
		{"ancient_debris", 0.0, 2220, 1},
		{"andesite", 0.0, 994, 10},
		{"andesite_slab", 0.0, 0, 0},
		{"andesite_stairs", 0.0, 0, 0},
		{"andesite_wall", 0.0, 0, 0},
		{"anvil", 0.0, 0, 0},
		{"apple", 0.0, 2349, 1},
		{"appleenchanted", 0.0, 1128, 1},
		{"armadillo_scute", 0.0, 2779, 1},
		{"armor_stand", 0.0, 0, 0},
		{"arrow", 0.0, 743, 15},
		{"azure_bluet", 0.0, 2409, 2},
		{"baked_potato", 0.0, 2603, 2},
		{"bamboo", 0.0, 1099, 2},
		{"bamboo_block", 0.0, 1116, 1},
		{"bamboo_button", 0.0, 0, 0},
		{"bamboo_door", 0.0, 0, 0},
		{"bamboo_fence", 0.0, 0, 0},
		{"bamboo_fence_gate", 0.0, 0, 0},
		{"bamboo_hanging_sign", 0.0, 0, 0},
		{"bamboo_mosaic", 0.0, 1114, 2},
		{"bamboo_mosaic_slab", 0.0, 0, 0},
		{"bamboo_mosaic_stairs", 0.0, 0, 0},
		{"bamboo_planks", 0.0, 1101, 10},
		{"bamboo_pressure_plate", 0.0, 0, 0},
		{"bamboo_raft", 0.0, 0, 0},
		{"bamboo_sign", 0.0, 0, 0},
		{"bamboo_slab", 0.0, 1113, 1},
		{"bamboo_stairs", 0.0, 0, 0},
		{"bamboo_trapdoor", 0.0, 0, 0},
		{"banner", 0.0, 0, 0},
		{"banner_pattern", 0.0, 0, 0},
		{"barrel", 0.0, 0, 0},
		{"basalt", 0.0, 2318, 3},
		{"beacon", 0.0, 0, 0},
		{"bed", 0.0, 0, 0},
		{"beef", 0.0, 371, 2},
		{"beehive", 0.0, 0, 0},
		{"beetroot", 0.0, 458, 3},
		{"beetroot_seeds", 0.0, 0, 0},
		{"beetroot_soup", 0.0, 0, 0},
		{"bell", 0.0, 0, 0},
		{"birch_boat", 0.0, 0, 0},
		{"birch_door", 0.0, 0, 0},
		{"birch_fence", 0.0, 0, 0},
		{"birch_fence_gate", 0.0, 0, 0},
		{"birch_hanging_sign", 0.0, 0, 0},
		{"birch_log", 0.0, 1383, 2},
		{"birch_planks", 0.0, 1365, 7},
		{"birch_sapling", 0.0, 0, 0},
		{"birch_sign", 0.0, 0, 0},
		{"birch_slab", 0.0, 0, 0},
		{"birch_stairs", 0.0, 0, 0},
		{"birch_wood", 0.0, 1382, 1},
		{"black_candle", 0.0, 0, 0},
		{"black_carpet", 0.0, 0, 0},
		{"black_concrete_powder", 0.0, 0, 0},
		{"black_dye", 0.0, 855, 7},
		{"black_glazed_terracotta", 0.0, 0, 0},
		{"black_stained_glass", 0.0, 1450, 1},
		{"black_stained_glass_pane", 0.0, 0, 0},
		{"black_terracotta", 0.0, 2328, 1},
		{"black_wool", 0.0, 852, 3},
		{"blackstone", 0.0, 1475, 24},
		{"blackstone_slab", 0.0, 0, 0},
		{"blackstone_stairs", 0.0, 0, 0},
		{"blackstone_wall", 0.0, 0, 0},
		{"blast_furnace", 0.0, 0, 0},
		{"blaze_powder", 0.0, 1645, 7},
		{"blaze_rod", 0.0, 1518, 13},
		{"blue_candle", 0.0, 0, 0},
		{"blue_carpet", 0.0, 0, 0},
		{"blue_concrete_powder", 0.0, 0, 0},
		{"blue_dye", 0.0, 927, 6},
		{"blue_glazed_terracotta", 0.0, 0, 0},
		{"blue_ice", 0.0, 0, 0},
		{"blue_orchid", 0.0, 2402, 2},
		{"blue_stained_glass", 0.0, 1539, 1},
		{"blue_stained_glass_pane", 0.0, 0, 0},
		{"blue_terracotta", 0.0, 2324, 1},
		{"blue_wool", 0.0, 1531, 2},
		{"boat", 0.0, 1035, 8},
		{"bolt_armor_trim_smithing_template", 0.0, 1549, 2},
		{"bone", 0.0, 1574, 1},
		{"bone_block", 0.0, 1573, 1},
		{"bone_meal", 0.0, 2774, 3},
		{"book", 0.0, 769, 11},
		{"bookshelf", 0.0, 2396, 4},
		{"bow", 0.0, 2166, 1},
		{"bowl", 0.0, 1345, 20},
		{"brain_coral_block", 0.0, 0, 0},
		{"bread", 0.0, 0, 0},
		{"breeze_rod", 0.0, 1652, 5},
		{"brewing_stand", 0.0, 0, 0},
		{"brick", 0.0, 1795, 2},
		{"brick_block", 0.0, 1117, 6},
		{"brick_slab", 0.0, 0, 0},
		{"brick_stairs", 0.0, 0, 0},
		{"brick_wall", 0.0, 0, 0},
		{"brown_candle", 0.0, 0, 0},
		{"brown_carpet", 0.0, 0, 0},
		{"brown_concrete_powder", 0.0, 0, 0},
		{"brown_dye", 0.0, 921, 6},
		{"brown_glazed_terracotta", 0.0, 0, 0},
		{"brown_mushroom", 0.0, 2200, 19},
		{"brown_stained_glass", 0.0, 1800, 1},
		{"brown_stained_glass_pane", 0.0, 0, 0},
		{"brown_terracotta", 0.0, 2325, 1},
		{"brown_wool", 0.0, 849, 3},
		{"brush", 0.0, 0, 0},
		{"bubble_coral_block", 0.0, 0, 0},
		{"bucket", 0.0, 325, 2},
		{"bundle", 0.0, 0, 0},
		{"cactus", 0.0, 2221, 1},
		{"cake", 0.0, 0, 0},
		{"calibrated_sculk_sensor", 0.0, 0, 0},
		{"campfire", 0.0, 0, 0},
		{"candle", 0.0, 1385, 21},
		{"carpet", 0.0, 2407, 2},
		{"carrot", 0.0, 461, 5},
		{"carrotonastick", 0.0, 0, 0},
		{"cartography_table", 0.0, 0, 0},
		{"carved_pumpkin", 0.0, 2417, 1},
		{"cauldron", 0.0, 0, 0},
		{"chain", 0.0, 1052, 12},
		{"chainmail_boots", 0.0, 2222, 1},
		{"chainmail_chestplate", 0.0, 2223, 1},
		{"chainmail_helmet", 0.0, 2224, 1},
		{"chainmail_leggings", 0.0, 2225, 1},
		{"charcoal", 0.0, 1817, 15},
		{"cherry_boat", 0.0, 1972, 1},
		{"cherry_button", 0.0, 0, 0},
		{"cherry_chest_boat", 0.0, 0, 0},
		{"cherry_door", 0.0, 0, 0},
		{"cherry_fence", 0.0, 0, 0},
		{"cherry_fence_gate", 0.0, 0, 0},
		{"cherry_hanging_sign", 0.0, 0, 0},
		{"cherry_log", 0.0, 1976, 2},
		{"cherry_planks", 0.0, 1962, 10},
		{"cherry_pressure_plate", 0.0, 0, 0},
		{"cherry_sapling", 0.0, 0, 0},
		{"cherry_sign", 0.0, 0, 0},
		{"cherry_slab", 0.0, 0, 0},
		{"cherry_stairs", 0.0, 0, 0},
		{"cherry_trapdoor", 0.0, 0, 0},
		{"cherry_wood", 0.0, 1979, 1},
		{"chest", 0.0, 1021, 14},
		{"chest_boat", 0.0, 0, 0},
		{"chest_minecart", 0.0, 0, 0},
		{"chicken", 0.0, 365, 2},
		{"chiseled_bookshelf", 0.0, 0, 0},
		{"chiseled_copper", 0.0, 2749, 1},
		{"chiseled_deepslate", 0.0, 0, 0},
		{"chiseled_nether_bricks", 0.0, 0, 0},
		{"chiseled_polished_blackstone", 0.0, 0, 0},
		{"chiseled_quartz_block", 0.0, 0, 0},
		{"chiseled_red_sandstone", 0.0, 2627, 1},
		{"chiseled_resin_bricks", 0.0, 0, 0},
		{"chiseled_sandstone", 0.0, 2643, 1},
		{"chiseled_stone_bricks", 0.0, 2418, 1},
		{"chiseled_tuff", 0.0, 0, 0},
		{"chiseled_tuff_bricks", 0.0, 0, 0},
		{"chorus_fruit", 0.0, 2226, 1},
		{"chorus_fruit_popped", 0.0, 2197, 2},
		{"clay", 0.0, 2227, 1},
		{"clay_ball", 0.0, 951, 3},
		{"clock", 0.0, 0, 0},
		{"closed_eyeblossom", 0.0, 2354, 2},
		{"clownfish", 0.0, 491, 1},
		{"coal", 0.0, 0, 26},
		{"coal_block", 0.0, 1989, 1},
		{"coal_ore", 0.0, 2228, 1},
		{"coals", 0.0, 1952, 4},
		{"coarse_dirt", 0.0, 0, 0},
		{"coast_armor_trim_smithing_template", 0.0, 1991, 1},
		{"cobbled_deepslate", 0.0, 1755, 30},
		{"cobbled_deepslate_slab", 0.0, 1983, 1},
		{"cobbled_deepslate_stairs", 0.0, 0, 0},
		{"cobbled_deepslate_wall", 0.0, 0, 0},
		{"cobblestone", 0.0, 1075, 21},
		{"cobblestone_slab", 0.0, 0, 0},
		{"cobblestone_wall", 0.0, 0, 0},
		{"cocoa_beans", 0.0, 1797, 3},
		{"comparator", 0.0, 0, 0},
		{"compass", 0.0, 411, 9},
		{"composter", 0.0, 0, 0},
		{"conduit", 0.0, 0, 0},
		{"cooked_beef", 0.0, 0, 0},
		{"cooked_chicken", 0.0, 0, 0},
		{"cooked_fish", 0.0, 0, 0},
		{"cooked_porkchop", 0.0, 0, 0},
		{"cooked_rabbit", 0.0, 2605, 2},
		{"cooked_salmon", 0.0, 0, 0},
		{"cookie", 0.0, 0, 0},
		{"copper_block", 0.0, 1551, 11},
		{"copper_bulb", 0.0, 2750, 1},
		{"copper_door", 0.0, 2751, 1},
		{"copper_grate", 0.0, 2752, 1},
		{"copper_ingot", 0.0, 1801, 6},
		{"copper_ore", 0.0, 2231, 1},
		{"copper_trapdoor", 0.0, 2753, 1},
		{"cornflower", 0.0, 1536, 2},
		{"cracked_deepslate_bricks", 0.0, 0, 0},
		{"cracked_deepslate_tiles", 0.0, 0, 0},
		{"cracked_nether_bricks", 0.0, 0, 0},
		{"cracked_polished_blackstone_bricks", 0.0, 0, 0},
		{"cracked_stone_bricks", 0.0, 0, 0},
		{"crafter", 0.0, 0, 0},
		{"crafting_table", 0.0, 2014, 1},
		{"creaking_heart", 0.0, 0, 0},
		{"crimson_button", 0.0, 0, 0},
		{"crimson_door", 0.0, 0, 0},
		{"crimson_fence", 0.0, 0, 0},
		{"crimson_fence_gate", 0.0, 0, 0},
		{"crimson_hanging_sign", 0.0, 0, 0},
		{"crimson_hyphae", 0.0, 2127, 1},
		{"crimson_planks", 0.0, 1212, 30},
		{"crimson_pressure_plate", 0.0, 0, 0},
		{"crimson_sign", 0.0, 0, 0},
		{"crimson_slab", 0.0, 1139, 5},
		{"crimson_stairs", 0.0, 0, 0},
		{"crimson_stem", 0.0, 1923, 6},
		{"crimson_trapdoor", 0.0, 0, 0},
		{"crossbow", 0.0, 0, 0},
		{"crying_obsidian", 0.0, 2641, 1},
		{"cut_copper", 0.0, 2017, 6},
		{"cut_copper_slab", 0.0, 2015, 2},
		{"cut_copper_stairs", 0.0, 2754, 1},
		{"cut_red_sandstone", 0.0, 2628, 1},
		{"cut_sandstone", 0.0, 2644, 1},
		{"cyan_candle", 0.0, 0, 0},
		{"cyan_carpet", 0.0, 0, 0},
		{"cyan_concrete_powder", 0.0, 0, 0},
		{"cyan_dye", 0.0, 939, 6},
		{"cyan_glazed_terracotta", 0.0, 0, 0},
		{"cyan_stained_glass", 0.0, 2132, 1},
		{"cyan_stained_glass_pane", 0.0, 0, 0},
		{"cyan_terracotta", 0.0, 2337, 1},
		{"cyan_wool", 0.0, 2129, 2},
		{"dandelion", 0.0, 2736, 2},
		{"dark_oak_boat", 0.0, 498, 1},
		{"dark_oak_door", 0.0, 0, 0},
		{"dark_oak_fence", 0.0, 0, 0},
		{"dark_oak_fence_gate", 0.0, 0, 0},
		{"dark_oak_hanging_sign", 0.0, 0, 0},
		{"dark_oak_log", 0.0, 2142, 2},
		{"dark_oak_planks", 0.0, 2133, 7},
		{"dark_oak_sapling", 0.0, 0, 0},
		{"dark_oak_slab", 0.0, 0, 0},
		{"dark_oak_stairs", 0.0, 0, 0},
		{"dark_oak_wood", 0.0, 2141, 1},
		{"dark_prismarine", 0.0, 2584, 3},
		{"dark_prismarine_slab", 0.0, 0, 0},
		{"dark_prismarine_stairs", 0.0, 0, 0},
		{"darkoak_sign", 0.0, 0, 0},
		{"daylight_detector", 0.0, 0, 0},
		{"deepslate", 0.0, 0, 0},
		{"deepslate_brick_slab", 0.0, 0, 0},
		{"deepslate_brick_stairs", 0.0, 0, 0},
		{"deepslate_brick_wall", 0.0, 0, 0},
		{"deepslate_bricks", 0.0, 1994, 12},
		{"deepslate_coal_ore", 0.0, 2247, 1},
		{"deepslate_copper_ore", 0.0, 2248, 1},
		{"deepslate_diamond_ore", 0.0, 2249, 1},
		{"deepslate_emerald_ore", 0.0, 2250, 1},
		{"deepslate_gold_ore", 0.0, 2251, 1},
		{"deepslate_iron_ore", 0.0, 2252, 1},
		{"deepslate_lapis_ore", 0.0, 2253, 1},
		{"deepslate_redstone_ore", 0.0, 2254, 1},
		{"deepslate_tile_slab", 0.0, 0, 0},
		{"deepslate_tile_stairs", 0.0, 0, 0},
		{"deepslate_tile_wall", 0.0, 0, 0},
		{"deepslate_tiles", 0.0, 2006, 7},
		{"detector_rail", 0.0, 0, 0},
		{"diamond", 0.0, 327, 38},
		{"diamond_axe", 0.0, 2659, 1},
		{"diamond_block", 0.0, 2165, 1},
		{"diamond_boots", 0.0, 2660, 1},
		{"diamond_chestplate", 0.0, 2661, 1},
		{"diamond_helmet", 0.0, 2662, 1},
		{"diamond_hoe", 0.0, 2663, 1},
		{"diamond_leggings", 0.0, 2664, 1},
		{"diamond_ore", 0.0, 2255, 1},
		{"diamond_pickaxe", 0.0, 2665, 1},
		{"diamond_shovel", 0.0, 2666, 1},
		{"diamond_sword", 0.0, 2667, 1},
		{"diorite", 0.0, 982, 12},
		{"diorite_slab", 0.0, 0, 0},
		{"diorite_stairs", 0.0, 0, 0},
		{"diorite_wall", 0.0, 0, 0},
		{"dirt", 0.0, 1990, 1},
		{"dirt_with_roots", 0.0, 0, 0},
		{"disc_fragment_5", 0.0, 2611, 1},
		{"dispenser", 0.0, 0, 0},
		{"dragon_breath", 0.0, 1794, 1},
		{"dried_kelp", 0.0, 2167, 1},
		{"dried_kelp_block", 0.0, 374, 2},
		{"dripstone_block", 0.0, 0, 0},
		{"dropper", 0.0, 2013, 1},
		{"dune_armor_trim_smithing_template", 0.0, 2170, 1},
		{"dye", 0.0, 780, 62},
		{"echo_shard", 0.0, 2612, 2},
		{"egg", 0.0, 1807, 2},
		{"emerald", 0.0, 26, 249},
		{"emerald_block", 0.0, 2182, 1},
		{"emerald_ore", 0.0, 2256, 1},
		{"emptymap", 0.0, 1177, 2},
		{"enchanting_table", 0.0, 0, 0},
		{"end_brick_stairs", 0.0, 0, 0},
		{"end_bricks", 0.0, 2189, 5},
		{"end_crystal", 0.0, 0, 0},
		{"end_rod", 0.0, 0, 0},
		{"end_stone", 0.0, 2183, 6},
		{"end_stone_brick_slab", 0.0, 0, 0},
		{"end_stone_brick_wall", 0.0, 0, 0},
		{"ender_chest", 0.0, 0, 0},
		{"ender_eye", 0.0, 2194, 2},
		{"ender_pearl", 0.0, 2196, 1},
		{"experience_bottle", 0.0, 0, 0},
		{"exposed_chiseled_copper", 0.0, 2755, 1},
		{"exposed_copper", 0.0, 2025, 9},
		{"exposed_copper_bulb", 0.0, 2756, 1},
		{"exposed_copper_door", 0.0, 2757, 1},
		{"exposed_copper_grate", 0.0, 2758, 1},
		{"exposed_copper_trapdoor", 0.0, 2759, 1},
		{"exposed_cut_copper", 0.0, 2034, 6},
		{"exposed_cut_copper_slab", 0.0, 2023, 2},
		{"exposed_cut_copper_stairs", 0.0, 2760, 1},
		{"eye_armor_trim_smithing_template", 0.0, 2199, 1},
		{"feather", 0.0, 736, 4},
		{"fence_gate", 0.0, 0, 0},
		{"fermented_spider_eye", 0.0, 1657, 19},
		{"fern", 0.0, 0, 0},
		{"fire_charge", 0.0, 0, 0},
		{"fire_coral_block", 0.0, 0, 0},
		{"fish", 0.0, 485, 3},
		{"fishing_rod", 0.0, 1956, 2},
		{"fletching_table", 0.0, 0, 0},
		{"flint", 0.0, 726, 10},
		{"flint_and_steel", 0.0, 0, 0},
		{"flow_armor_trim_smithing_template", 0.0, 2219, 1},
		{"flower_pot", 0.0, 0, 0},
		{"frame", 0.0, 2347, 1},
		{"furnace", 0.0, 1501, 17},
		{"ghast_tear", 0.0, 1676, 3},
		{"glass", 0.0, 1180, 29},
		{"glass_bottle", 0.0, 444, 2},
		{"glass_pane", 0.0, 394, 17},
		{"glow_frame", 0.0, 0, 0},
		{"glow_ink_sac", 0.0, 2348, 1},
		{"glowstone", 0.0, 2631, 2},
		{"glowstone_dust", 0.0, 1744, 11},
		{"gold_block", 0.0, 2353, 1},
		{"gold_ingot", 0.0, 421, 17},
		{"gold_nugget", 0.0, 2350, 3},
		{"gold_ore", 0.0, 2268, 1},
		{"golden_apple", 0.0, 0, 0},
		{"golden_axe", 0.0, 2257, 1},
		{"golden_boots", 0.0, 2258, 1},
		{"golden_carrot", 0.0, 1679, 1},
		{"golden_chestplate", 0.0, 2259, 1},
		{"golden_helmet", 0.0, 2260, 1},
		{"golden_hoe", 0.0, 2261, 1},
		{"golden_leggings", 0.0, 2262, 1},
		{"golden_pickaxe", 0.0, 2263, 1},
		{"golden_rail", 0.0, 0, 0},
		{"golden_shovel", 0.0, 2264, 1},
		{"golden_sword", 0.0, 2265, 1},
		{"granite", 0.0, 972, 10},
		{"granite_slab", 0.0, 0, 0},
		{"granite_stairs", 0.0, 0, 0},
		{"granite_wall", 0.0, 0, 0},
		{"gravel", 0.0, 704, 22},
		{"gray_candle", 0.0, 0, 0},
		{"gray_carpet", 0.0, 0, 0},
		{"gray_concrete_powder", 0.0, 0, 0},
		{"gray_dye", 0.0, 862, 6},
		{"gray_glazed_terracotta", 0.0, 0, 0},
		{"gray_stained_glass", 0.0, 2356, 1},
		{"gray_stained_glass_pane", 0.0, 0, 0},
		{"gray_terracotta", 0.0, 2335, 1},
		{"gray_wool", 0.0, 846, 3},
		{"green_candle", 0.0, 0, 0},
		{"green_carpet", 0.0, 0, 0},
		{"green_concrete_powder", 0.0, 0, 0},
		{"green_dye", 0.0, 915, 6},
		{"green_glazed_terracotta", 0.0, 0, 0},
		{"green_stained_glass", 0.0, 2359, 1},
		{"green_stained_glass_pane", 0.0, 0, 0},
		{"green_terracotta", 0.0, 2326, 1},
		{"green_wool", 0.0, 2357, 2},
		{"grindstone", 0.0, 2360, 9},
		{"gunpowder", 0.0, 1788, 5},
		{"hardened_clay", 0.0, 1451, 24},
		{"hay_block", 0.0, 2740, 2},
		{"heart_of_the_sea", 0.0, 1993, 1},
		{"heavy_core", 0.0, 2430, 1},
		{"heavy_weighted_pressure_plate", 0.0, 0, 0},
		{"honey_block", 0.0, 2375, 1},
		{"honey_bottle", 0.0, 2373, 2},
		{"honeycomb", 0.0, 1242, 42},
		{"honeycomb_block", 0.0, 0, 0},
		{"hopper", 0.0, 2376, 1},
		{"hopper_minecart", 0.0, 0, 0},
		{"horn_coral_block", 0.0, 0, 0},
		{"horsearmorgold", 0.0, 2269, 1},
		{"horsearmoriron", 0.0, 2270, 1},
		{"horsearmorleather", 0.0, 0, 0},
		{"host_armor_trim_smithing_template", 0.0, 2377, 1},
		{"ice", 0.0, 2501, 1},
		{"ink_sac", 0.0, 1421, 4},
		{"iron_axe", 0.0, 2271, 1},
		{"iron_bars", 0.0, 0, 0},
		{"iron_block", 0.0, 1096, 2},
		{"iron_boots", 0.0, 2272, 1},
		{"iron_chestplate", 0.0, 2273, 1},
		{"iron_door", 0.0, 0, 0},
		{"iron_helmet", 0.0, 2274, 1},
		{"iron_hoe", 0.0, 2275, 1},
		{"iron_ingot", 0.0, 275, 50},
		{"iron_leggings", 0.0, 2278, 1},
		{"iron_nugget", 0.0, 1958, 4},
		{"iron_ore", 0.0, 2279, 1},
		{"iron_pickaxe", 0.0, 2280, 1},
		{"iron_shovel", 0.0, 2281, 1},
		{"iron_sword", 0.0, 2282, 1},
		{"iron_trapdoor", 0.0, 0, 0},
		{"jukebox", 0.0, 0, 0},
		{"jungle_boat", 0.0, 496, 1},
		{"jungle_door", 0.0, 0, 0},
		{"jungle_fence", 0.0, 0, 0},
		{"jungle_fence_gate", 0.0, 0, 0},
		{"jungle_hanging_sign", 0.0, 0, 0},
		{"jungle_log", 0.0, 2387, 2},
		{"jungle_planks", 0.0, 2378, 7},
		{"jungle_sapling", 0.0, 0, 0},
		{"jungle_sign", 0.0, 0, 0},
		{"jungle_slab", 0.0, 0, 0},
		{"jungle_stairs", 0.0, 0, 0},
		{"jungle_wood", 0.0, 2386, 1},
		{"kelp", 0.0, 2283, 1},
		{"ladder", 0.0, 0, 0},
		{"lantern", 0.0, 0, 0},
		{"lapis_block", 0.0, 2391, 1},
		{"lapis_lazuli", 0.0, 1533, 3},
		{"lapis_ore", 0.0, 2284, 1},
		{"lead", 0.0, 0, 0},
		{"leather", 0.0, 758, 9},
		{"leather_boots", 0.0, 0, 0},
		{"leather_chestplate", 0.0, 0, 0},
		{"leather_helmet", 0.0, 0, 0},
		{"leather_leggings", 0.0, 0, 0},
		{"lectern", 0.0, 0, 0},
		{"lever", 0.0, 0, 0},
		{"light_blue_candle", 0.0, 0, 0},
		{"light_blue_carpet", 0.0, 0, 0},
		{"light_blue_concrete_powder", 0.0, 0, 0},
		{"light_blue_dye", 0.0, 874, 6},
		{"light_blue_glazed_terracotta", 0.0, 0, 0},
		{"light_blue_stained_glass", 0.0, 2404, 1},
		{"light_blue_stained_glass_pane", 0.0, 0, 0},
		{"light_blue_terracotta", 0.0, 2331, 1},
		{"light_blue_wool", 0.0, 2400, 2},
		{"light_gray_candle", 0.0, 0, 0},
		{"light_gray_carpet", 0.0, 0, 0},
		{"light_gray_concrete_powder", 0.0, 0, 0},
		{"light_gray_dye", 0.0, 891, 6},
		{"light_gray_stained_glass", 0.0, 2413, 1},
		{"light_gray_stained_glass_pane", 0.0, 0, 0},
		{"light_gray_terracotta", 0.0, 2336, 1},
		{"light_gray_wool", 0.0, 2405, 2},
		{"light_weighted_pressure_plate", 0.0, 0, 0},
		{"lightning_rod", 0.0, 0, 0},
		{"lilac", 0.0, 2435, 1},
		{"lily_of_the_valley", 0.0, 2738, 2},
		{"lime_candle", 0.0, 0, 0},
		{"lime_carpet", 0.0, 0, 0},
		{"lime_concrete_powder", 0.0, 0, 0},
		{"lime_dye", 0.0, 868, 6},
		{"lime_glazed_terracotta", 0.0, 0, 0},
		{"lime_stained_glass", 0.0, 2416, 1},
		{"lime_stained_glass_pane", 0.0, 0, 0},
		{"lime_terracotta", 0.0, 2333, 1},
		{"lime_wool", 0.0, 2414, 2},
		{"lingering_potion", 0.0, 0, 0},
		{"lit_pumpkin", 0.0, 0, 0},
		{"lodestone", 0.0, 0, 0},
		{"lodestone_compass", 0.0, 2614, 1},
		{"log", 0.0, 1810, 7},
		{"log2", 0.0, 1832, 7},
		{"logs", 0.0, 1949, 3},
		{"logs_that_burn", 0.0, 2285, 1},
		{"loom", 0.0, 0, 0},
		{"mace", 0.0, 0, 0},
		{"magenta_candle", 0.0, 0, 0},
		{"magenta_carpet", 0.0, 0, 0},
		{"magenta_concrete_powder", 0.0, 0, 0},
		{"magenta_dye", 0.0, 945, 6},
		{"magenta_glazed_terracotta", 0.0, 0, 0},
		{"magenta_stained_glass", 0.0, 2436, 1},
		{"magenta_stained_glass_pane", 0.0, 0, 0},
		{"magenta_terracotta", 0.0, 2330, 1},
		{"magenta_wool", 0.0, 2431, 2},
		{"magma", 0.0, 0, 0},
		{"magma_cream", 0.0, 1680, 3},
		{"mangrove_boat", 0.0, 0, 0},
		{"mangrove_button", 0.0, 0, 0},
		{"mangrove_door", 0.0, 0, 0},
		{"mangrove_fence", 0.0, 0, 0},
		{"mangrove_fence_gate", 0.0, 0, 0},
		{"mangrove_hanging_sign", 0.0, 0, 0},
		{"mangrove_log", 0.0, 1839, 8},
		{"mangrove_planks", 0.0, 1284, 31},
		{"mangrove_pressure_plate", 0.0, 0, 0},
		{"mangrove_propagule", 0.0, 0, 0},
		{"mangrove_roots", 0.0, 2461, 1},
		{"mangrove_sign", 0.0, 0, 0},
		{"mangrove_slab", 0.0, 1144, 5},
		{"mangrove_stairs", 0.0, 0, 0},
		{"mangrove_trapdoor", 0.0, 0, 0},
		{"mangrove_wood", 0.0, 1847, 7},
		{"map", 0.0, 0, 0},
		{"melon", 0.0, 2437, 3},
		{"melon_block", 0.0, 469, 1},
		{"melon_seeds", 0.0, 0, 0},
		{"minecart", 0.0, 1980, 3},
		{"moss_block", 0.0, 2440, 3},
		{"moss_carpet", 0.0, 0, 0},
		{"mossy_cobblestone", 0.0, 2443, 6},
		{"mossy_cobblestone_slab", 0.0, 0, 0},
		{"mossy_cobblestone_stairs", 0.0, 0, 0},
		{"mossy_cobblestone_wall", 0.0, 0, 0},
		{"mossy_stone_brick_slab", 0.0, 0, 0},
		{"mossy_stone_brick_stairs", 0.0, 0, 0},
		{"mossy_stone_brick_wall", 0.0, 0, 0},
		{"mossy_stone_bricks", 0.0, 2449, 5},
		{"mud", 0.0, 2462, 2},
		{"mud_brick_slab", 0.0, 0, 0},
		{"mud_brick_stairs", 0.0, 0, 0},
		{"mud_brick_wall", 0.0, 0, 0},
		{"mud_bricks", 0.0, 2455, 6},
		{"muddy_mangrove_roots", 0.0, 0, 0},
		{"mushroom_stew", 0.0, 0, 0},
		{"muttonCooked", 0.0, 0, 0},
		{"muttonRaw", 0.0, 2286, 1},
		{"muttonraw", 0.0, 373, 1},
		{"nametag", 0.0, 0, 0},
		{"nautilus_shell", 0.0, 1992, 1},
		{"nether_brick", 0.0, 2232, 8},
		{"nether_brick_fence", 0.0, 0, 0},
		{"nether_brick_slab", 0.0, 1984, 1},
		{"nether_brick_stairs", 0.0, 0, 0},
		{"nether_brick_wall", 0.0, 0, 0},
		{"nether_gold_ore", 0.0, 2287, 1},
		{"nether_wart", 0.0, 446, 4},
		{"nether_wart_block", 0.0, 0, 0},
		{"netherbrick", 0.0, 2482, 3},
		{"netherite_axe", 0.0, 0, 0},
		{"netherite_block", 0.0, 2485, 1},
		{"netherite_boots", 0.0, 0, 0},
		{"netherite_chestplate", 0.0, 0, 0},
		{"netherite_helmet", 0.0, 0, 0},
		{"netherite_hoe", 0.0, 0, 0},
		{"netherite_ingot", 0.0, 2419, 11},
		{"netherite_leggings", 0.0, 0, 0},
		{"netherite_pickaxe", 0.0, 0, 0},
		{"netherite_scrap", 0.0, 2486, 1},
		{"netherite_shovel", 0.0, 0, 0},
		{"netherite_sword", 0.0, 0, 0},
		{"netherite_upgrade_smithing_template", 0.0, 2487, 1},
		{"netherrack", 0.0, 2288, 3},
		{"netherstar", 0.0, 1179, 1},
		{"normal_stone_slab", 0.0, 2369, 4},
		{"normal_stone_stairs", 0.0, 0, 0},
		{"noteblock", 0.0, 0, 0},
		{"oak_boat", 0.0, 494, 1},
		{"oak_fence", 0.0, 0, 0},
		{"oak_hanging_sign", 0.0, 0, 0},
		{"oak_log", 0.0, 2490, 2},
		{"oak_planks", 0.0, 1540, 9},
		{"oak_sapling", 0.0, 0, 0},
		{"oak_slab", 0.0, 0, 0},
		{"oak_stairs", 0.0, 0, 0},
		{"oak_wood", 0.0, 2489, 1},
		{"observer", 0.0, 0, 0},
		{"obsidian", 0.0, 1209, 3},
		{"open_eyeblossom", 0.0, 2494, 2},
		{"orange_candle", 0.0, 0, 0},
		{"orange_carpet", 0.0, 0, 0},
		{"orange_concrete_powder", 0.0, 0, 0},
		{"orange_dye", 0.0, 909, 6},
		{"orange_glazed_terracotta", 0.0, 0, 0},
		{"orange_stained_glass", 0.0, 2500, 1},
		{"orange_stained_glass_pane", 0.0, 0, 0},
		{"orange_terracotta", 0.0, 2329, 1},
		{"orange_tulip", 0.0, 2496, 2},
		{"orange_wool", 0.0, 2492, 2},
		{"oxeye_daisy", 0.0, 1125, 3},
		{"oxidized_chiseled_copper", 0.0, 2761, 1},
		{"oxidized_copper", 0.0, 2042, 9},
		{"oxidized_copper_bulb", 0.0, 2762, 1},
		{"oxidized_copper_door", 0.0, 2763, 1},
		{"oxidized_copper_grate", 0.0, 2764, 1},
		{"oxidized_copper_trapdoor", 0.0, 2765, 1},
		{"oxidized_cut_copper", 0.0, 2051, 6},
		{"oxidized_cut_copper_slab", 0.0, 2040, 2},
		{"oxidized_cut_copper_stairs", 0.0, 2766, 1},
		{"packed_ice", 0.0, 1538, 1},
		{"packed_mud", 0.0, 2454, 1},
		{"painting", 0.0, 0, 0},
		{"pale_hanging_moss", 0.0, 0, 0},
		{"pale_moss_block", 0.0, 2503, 1},
		{"pale_moss_carpet", 0.0, 0, 0},
		{"pale_oak_boat", 0.0, 2514, 1},
		{"pale_oak_button", 0.0, 0, 0},
		{"pale_oak_chest_boat", 0.0, 0, 0},
		{"pale_oak_door", 0.0, 0, 0},
		{"pale_oak_fence", 0.0, 0, 0},
		{"pale_oak_fence_gate", 0.0, 0, 0},
		{"pale_oak_hanging_sign", 0.0, 0, 0},
		{"pale_oak_log", 0.0, 2122, 3},
		{"pale_oak_planks", 0.0, 2504, 10},
		{"pale_oak_pressure_plate", 0.0, 0, 0},
		{"pale_oak_sapling", 0.0, 0, 0},
		{"pale_oak_sign", 0.0, 0, 0},
		{"pale_oak_slab", 0.0, 0, 0},
		{"pale_oak_stairs", 0.0, 0, 0},
		{"pale_oak_trapdoor", 0.0, 0, 0},
		{"pale_oak_wood", 0.0, 2519, 1},
		{"paper", 0.0, 377, 17},
		{"peony", 0.0, 2524, 1},
		{"phantom_membrane", 0.0, 1683, 1},
		{"pink_candle", 0.0, 0, 0},
		{"pink_carpet", 0.0, 0, 0},
		{"pink_concrete_powder", 0.0, 0, 0},
		{"pink_dye", 0.0, 897, 6},
		{"pink_glazed_terracotta", 0.0, 0, 0},
		{"pink_petals", 0.0, 2525, 1},
		{"pink_stained_glass", 0.0, 2528, 1},
		{"pink_stained_glass_pane", 0.0, 0, 0},
		{"pink_terracotta", 0.0, 2334, 1},
		{"pink_tulip", 0.0, 2526, 2},
		{"pink_wool", 0.0, 2522, 2},
		{"piston", 0.0, 2723, 1},
		{"pitcher_plant", 0.0, 2131, 1},
		{"planks", 0.0, 1154, 23},
		{"podzol", 0.0, 0, 0},
		{"pointed_dripstone", 0.0, 2168, 2},
		{"polished_andesite", 0.0, 2529, 3},
		{"polished_andesite_slab", 0.0, 0, 0},
		{"polished_andesite_stairs", 0.0, 0, 0},
		{"polished_basalt", 0.0, 0, 0},
		{"polished_blackstone", 0.0, 2532, 14},
		{"polished_blackstone_brick_slab", 0.0, 0, 0},
		{"polished_blackstone_brick_stairs", 0.0, 0, 0},
		{"polished_blackstone_brick_wall", 0.0, 0, 0},
		{"polished_blackstone_bricks", 0.0, 2240, 7},
		{"polished_blackstone_button", 0.0, 0, 0},
		{"polished_blackstone_pressure_plate", 0.0, 0, 0},
		{"polished_blackstone_slab", 0.0, 1985, 1},
		{"polished_blackstone_stairs", 0.0, 0, 0},
		{"polished_blackstone_wall", 0.0, 0, 0},
		{"polished_deepslate", 0.0, 2149, 15},
		{"polished_deepslate_slab", 0.0, 0, 0},
		{"polished_deepslate_stairs", 0.0, 0, 0},
		{"polished_deepslate_wall", 0.0, 0, 0},
		{"polished_diorite", 0.0, 2546, 3},
		{"polished_diorite_slab", 0.0, 0, 0},
		{"polished_diorite_stairs", 0.0, 0, 0},
		{"polished_granite", 0.0, 2549, 3},
		{"polished_granite_slab", 0.0, 0, 0},
		{"polished_granite_stairs", 0.0, 0, 0},
		{"polished_tuff", 0.0, 2569, 12},
		{"polished_tuff_slab", 0.0, 0, 0},
		{"polished_tuff_stairs", 0.0, 0, 0},
		{"polished_tuff_wall", 0.0, 0, 0},
		{"poppy", 0.0, 2617, 2},
		{"porkchop", 0.0, 369, 2},
		{"potato", 0.0, 456, 2},
		{"potion", 0.0, 1787, 1},
		{"potion_type", 0.0, 1575, 70},
		{"prismarine", 0.0, 2587, 6},
		{"prismarine_brick_slab", 0.0, 0, 0},
		{"prismarine_bricks", 0.0, 2581, 3},
		{"prismarine_bricks_stairs", 0.0, 0, 0},
		{"prismarine_crystals", 0.0, 2645, 1},
		{"prismarine_shard", 0.0, 2144, 5},
		{"prismarine_slab", 0.0, 0, 0},
		{"prismarine_stairs", 0.0, 0, 0},
		{"prismarine_wall", 0.0, 0, 0},
		{"pufferfish", 0.0, 492, 2},
		{"pumpkin", 0.0, 466, 3},
		{"pumpkin_pie", 0.0, 0, 0},
		{"pumpkin_seeds", 0.0, 0, 0},
		{"purple_candle", 0.0, 0, 0},
		{"purple_carpet", 0.0, 0, 0},
		{"purple_concrete_powder", 0.0, 0, 0},
		{"purple_dye", 0.0, 933, 6},
		{"purple_glazed_terracotta", 0.0, 0, 0},
		{"purple_stained_glass", 0.0, 2595, 1},
		{"purple_stained_glass_pane", 0.0, 0, 0},
		{"purple_terracotta", 0.0, 2323, 1},
		{"purple_wool", 0.0, 2593, 2},
		{"purpur_block", 0.0, 2597, 6},
		{"purpur_pillar", 0.0, 2596, 1},
		{"purpur_slab", 0.0, 0, 0},
		{"purpur_stairs", 0.0, 0, 0},
		{"quartz", 0.0, 1004, 10},
		{"quartz_block", 0.0, 2291, 11},
		{"quartz_bricks", 0.0, 0, 0},
		{"quartz_ore", 0.0, 2302, 1},
		{"quartz_pillar", 0.0, 0, 0},
		{"quartz_slab", 0.0, 0, 0},
		{"quartz_stairs", 0.0, 0, 0},
		{"rabbit", 0.0, 367, 2},
		{"rabbit_foot", 0.0, 438, 3},
		{"rabbit_hide", 0.0, 767, 2},
		{"rabbit_stew", 0.0, 0, 0},
		{"rail", 0.0, 0, 0},
		{"raiser_armor_trim_smithing_template", 0.0, 2607, 1},
		{"raw_copper", 0.0, 2229, 2},
		{"raw_copper_block", 0.0, 2608, 1},
		{"raw_gold", 0.0, 2266, 2},
		{"raw_gold_block", 0.0, 2609, 1},
		{"raw_iron", 0.0, 2276, 2},
		{"raw_iron_block", 0.0, 2610, 1},
		{"record_5", 0.0, 0, 0},
		{"recovery_compass", 0.0, 0, 0},
		{"red_candle", 0.0, 0, 0},
		{"red_carpet", 0.0, 0, 0},
		{"red_concrete_powder", 0.0, 0, 0},
		{"red_dye", 0.0, 885, 6},
		{"red_glazed_terracotta", 0.0, 0, 0},
		{"red_mushroom", 0.0, 2464, 18},
		{"red_nether_brick", 0.0, 2622, 5},
		{"red_nether_brick_slab", 0.0, 0, 0},
		{"red_nether_brick_stairs", 0.0, 0, 0},
		{"red_nether_brick_wall", 0.0, 0, 0},
		{"red_sand", 0.0, 2303, 2},
		{"red_sandstone", 0.0, 2305, 9},
		{"red_sandstone_slab", 0.0, 0, 0},
		{"red_sandstone_stairs", 0.0, 0, 0},
		{"red_sandstone_wall", 0.0, 0, 0},
		{"red_stained_glass", 0.0, 2629, 1},
		{"red_stained_glass_pane", 0.0, 0, 0},
		{"red_terracotta", 0.0, 2327, 1},
		{"red_tulip", 0.0, 2620, 2},
		{"red_wool", 0.0, 2615, 2},
		{"redstone", 0.0, 1701, 43},
		{"redstone_block", 0.0, 2630, 1},
		{"redstone_lamp", 0.0, 0, 0},
		{"redstone_ore", 0.0, 2314, 1},
		{"redstone_torch", 0.0, 1068, 3},
		{"reeds", 0.0, 2520, 2},
		{"repeater", 0.0, 0, 0},
		{"resin_block", 0.0, 2125, 2},
		{"resin_brick", 0.0, 2633, 1},
		{"resin_brick_slab", 0.0, 1986, 1},
		{"resin_brick_stairs", 0.0, 0, 0},
		{"resin_brick_wall", 0.0, 0, 0},
		{"resin_bricks", 0.0, 2634, 7},
		{"resin_clump", 0.0, 2315, 2},
		{"respawn_anchor", 0.0, 0, 0},
		{"rib_armor_trim_smithing_template", 0.0, 2642, 1},
		{"rose_bush", 0.0, 2619, 1},
		{"rotten_flesh", 0.0, 420, 1},
		{"saddle", 0.0, 0, 0},
		{"salmon", 0.0, 488, 3},
		{"sand", 0.0, 1425, 23},
		{"sandstone", 0.0, 2171, 11},
		{"sandstone_slab", 0.0, 0, 0},
		{"sandstone_stairs", 0.0, 0, 0},
		{"sandstone_wall", 0.0, 0, 0},
		{"scaffolding", 0.0, 0, 0},
		{"sculk_sensor", 0.0, 1809, 1},
		{"sea_pickle", 0.0, 2317, 1},
		{"sealantern", 0.0, 0, 0},
		{"sentry_armor_trim_smithing_template", 0.0, 2646, 1},
		{"shaper_armor_trim_smithing_template", 0.0, 2647, 1},
		{"shears", 0.0, 0, 0},
		{"shield", 0.0, 0, 0},
		{"shulker_shell", 0.0, 2648, 1},
		{"sign", 0.0, 0, 0},
		{"silence_armor_trim_smithing_template", 0.0, 2656, 1},
		{"silver_glazed_terracotta", 0.0, 0, 0},
		{"skull", 0.0, 1123, 2},
		{"slime", 0.0, 1684, 3},
		{"slime_ball", 0.0, 2392, 4},
		{"small_dripleaf_block", 0.0, 0, 0},
		{"smithing_table", 0.0, 0, 0},
		{"smoker", 0.0, 0, 0},
		{"smooth_basalt", 0.0, 0, 0},
		{"smooth_quartz", 0.0, 2668, 3},
		{"smooth_quartz_slab", 0.0, 0, 0},
		{"smooth_quartz_stairs", 0.0, 0, 0},
		{"smooth_red_sandstone", 0.0, 2671, 3},
		{"smooth_red_sandstone_slab", 0.0, 0, 0},
		{"smooth_red_sandstone_stairs", 0.0, 0, 0},
		{"smooth_sandstone", 0.0, 2674, 2},
		{"smooth_sandstone_slab", 0.0, 0, 0},
		{"smooth_sandstone_stairs", 0.0, 0, 0},
		{"smooth_stone", 0.0, 1499, 2},
		{"smooth_stone_slab", 0.0, 1098, 1},
		{"snout_armor_trim_smithing_template", 0.0, 2676, 1},
		{"snow", 0.0, 2678, 1},
		{"snow_layer", 0.0, 0, 0},
		{"snowball", 0.0, 2677, 1},
		{"soul_campfire", 0.0, 0, 0},
		{"soul_fire_base_blocks", 0.0, 2715, 2},
		{"soul_lantern", 0.0, 0, 0},
		{"soul_sand", 0.0, 2679, 18},
		{"soul_soil", 0.0, 2697, 18},
		{"soul_torch", 0.0, 2717, 1},
		{"speckled_melon", 0.0, 1687, 2},
		{"spider_eye", 0.0, 1689, 3},
		{"spire_armor_trim_smithing_template", 0.0, 2718, 1},
		{"splash_potion", 0.0, 1793, 1},
		{"sponge", 0.0, 0, 0},
		{"spruce_boat", 0.0, 495, 1},
		{"spruce_door", 0.0, 0, 0},
		{"spruce_fence", 0.0, 0, 0},
		{"spruce_fence_gate", 0.0, 0, 0},
		{"spruce_hanging_sign", 0.0, 0, 0},
		{"spruce_log", 0.0, 2721, 2},
		{"spruce_planks", 0.0, 2649, 7},
		{"spruce_sapling", 0.0, 0, 0},
		{"spruce_sign", 0.0, 0, 0},
		{"spruce_slab", 0.0, 0, 0},
		{"spruce_stairs", 0.0, 0, 0},
		{"spruce_wood", 0.0, 2720, 1},
		{"spyglass", 0.0, 0, 0},
		{"stick", 0.0, 499, 205},
		{"sticky_piston", 0.0, 0, 0},
		{"stone", 0.0, 954, 18},
		{"stone_axe", 0.0, 0, 0},
		{"stone_brick_slab", 0.0, 0, 0},
		{"stone_brick_stairs", 0.0, 0, 0},
		{"stone_brick_wall", 0.0, 0, 0},
		{"stone_bricks", 0.0, 2338, 9},
		{"stone_button", 0.0, 0, 0},
		{"stone_crafting_materials", 0.0, 1785, 2},
		{"stone_hoe", 0.0, 0, 0},
		{"stone_pickaxe", 0.0, 0, 0},
		{"stone_pressure_plate", 0.0, 2164, 1},
		{"stone_shovel", 0.0, 0, 0},
		{"stone_stairs", 0.0, 0, 0},
		{"stone_sword", 0.0, 0, 0},
		{"stone_tool_materials", 0.0, 2724, 5},
		{"stonecutter_block", 0.0, 0, 0},
		{"string", 0.0, 470, 15},
		{"stripped_acacia_log", 0.0, 1043, 9},
		{"stripped_acacia_wood", 0.0, 1064, 1},
		{"stripped_bamboo_block", 0.0, 1111, 2},
		{"stripped_birch_log", 0.0, 1372, 9},
		{"stripped_birch_wood", 0.0, 1381, 1},
		{"stripped_cherry_log", 0.0, 1973, 3},
		{"stripped_cherry_wood", 0.0, 1978, 1},
		{"stripped_crimson_hyphae", 0.0, 2128, 1},
		{"stripped_crimson_stem", 0.0, 1929, 7},
		{"stripped_dark_oak_log", 0.0, 1854, 9},
		{"stripped_dark_oak_wood", 0.0, 2140, 1},
		{"stripped_jungle_log", 0.0, 1863, 9},
		{"stripped_jungle_wood", 0.0, 2385, 1},
		{"stripped_mangrove_log", 0.0, 1872, 10},
		{"stripped_mangrove_wood", 0.0, 1882, 7},
		{"stripped_oak_log", 0.0, 1889, 9},
		{"stripped_oak_wood", 0.0, 2488, 1},
		{"stripped_pale_oak_log", 0.0, 2515, 3},
		{"stripped_pale_oak_wood", 0.0, 2518, 1},
		{"stripped_spruce_log", 0.0, 1898, 9},
		{"stripped_spruce_wood", 0.0, 2719, 1},
		{"stripped_warped_hyphae", 0.0, 2747, 1},
		{"stripped_warped_stem", 0.0, 1936, 7},
		{"sugar", 0.0, 1692, 5},
		{"sunflower", 0.0, 2782, 1},
		{"suspicious_stew", 0.0, 0, 0},
		{"sweet_berries", 0.0, 376, 1},
		{"target", 0.0, 0, 0},
		{"tide_armor_trim_smithing_template", 0.0, 2742, 1},
		{"tinted_glass", 0.0, 0, 0},
		{"tnt", 0.0, 2743, 1},
		{"tnt_minecart", 0.0, 0, 0},
		{"torch", 0.0, 2389, 2},
		{"torchflower", 0.0, 2498, 2},
		{"trapped_chest", 0.0, 0, 0},
		{"trim_materials", 0.0, 2658, 1},
		{"trim_templates", 0.0, 0, 0},
		{"trimmable_armors", 0.0, 2657, 1},
		{"tripwire_hook", 0.0, 740, 3},
		{"tube_coral_block", 0.0, 0, 0},
		{"tuff", 0.0, 2552, 17},
		{"tuff_brick_slab", 0.0, 1987, 1},
		{"tuff_brick_stairs", 0.0, 0, 0},
		{"tuff_brick_wall", 0.0, 0, 0},
		{"tuff_bricks", 0.0, 2729, 7},
		{"tuff_slab", 0.0, 1988, 1},
		{"tuff_stairs", 0.0, 0, 0},
		{"tuff_wall", 0.0, 0, 0},
		{"turtle_helmet", 0.0, 1697, 1},
		{"turtle_shell_piece", 0.0, 441, 3},
		{"undyed_shulker_box", 0.0, 0, 0},
		{"vex_armor_trim_smithing_template", 0.0, 2744, 1},
		{"vine", 0.0, 1129, 3},
		{"ward_armor_trim_smithing_template", 0.0, 2745, 1},
		{"warped_button", 0.0, 0, 0},
		{"warped_door", 0.0, 0, 0},
		{"warped_fence", 0.0, 0, 0},
		{"warped_fence_gate", 0.0, 0, 0},
		{"warped_fungus", 0.0, 2746, 1},
		{"warped_fungus_on_a_stick", 0.0, 0, 0},
		{"warped_hanging_sign", 0.0, 0, 0},
		{"warped_hyphae", 0.0, 2748, 1},
		{"warped_planks", 0.0, 1315, 30},
		{"warped_pressure_plate", 0.0, 0, 0},
		{"warped_sign", 0.0, 0, 0},
		{"warped_slab", 0.0, 1149, 5},
		{"warped_stairs", 0.0, 0, 0},
		{"warped_stem", 0.0, 1943, 6},
		{"warped_trapdoor", 0.0, 0, 0},
		{"waterlily", 0.0, 0, 0},
		{"waxed_chiseled_copper", 0.0, 0, 0},
		{"waxed_copper", 0.0, 1562, 11},
		{"waxed_copper_bulb", 0.0, 0, 0},
		{"waxed_copper_door", 0.0, 0, 0},
		{"waxed_copper_grate", 0.0, 0, 0},
		{"waxed_copper_trapdoor", 0.0, 0, 0},
		{"waxed_cut_copper", 0.0, 2058, 5},
		{"waxed_cut_copper_slab", 0.0, 2057, 1},
		{"waxed_cut_copper_stairs", 0.0, 0, 0},
		{"waxed_exposed_chiseled_copper", 0.0, 0, 0},
		{"waxed_exposed_copper", 0.0, 2064, 8},
		{"waxed_exposed_copper_bulb", 0.0, 0, 0},
		{"waxed_exposed_copper_door", 0.0, 0, 0},
		{"waxed_exposed_copper_grate", 0.0, 0, 0},
		{"waxed_exposed_copper_trapdoor", 0.0, 0, 0},
		{"waxed_exposed_cut_copper", 0.0, 2072, 5},
		{"waxed_exposed_cut_copper_slab", 0.0, 2063, 1},
		{"waxed_exposed_cut_copper_stairs", 0.0, 0, 0},
		{"waxed_oxidized_chiseled_copper", 0.0, 0, 0},
		{"waxed_oxidized_copper", 0.0, 2078, 8},
		{"waxed_oxidized_copper_bulb", 0.0, 0, 0},
		{"waxed_oxidized_copper_door", 0.0, 0, 0},
		{"waxed_oxidized_copper_grate", 0.0, 0, 0},
		{"waxed_oxidized_copper_trapdoor", 0.0, 0, 0},
		{"waxed_oxidized_cut_copper", 0.0, 2086, 5},
		{"waxed_oxidized_cut_copper_slab", 0.0, 2077, 1},
		{"waxed_oxidized_cut_copper_stairs", 0.0, 0, 0},
		{"waxed_weathered_chiseled_copper", 0.0, 0, 0},
		{"waxed_weathered_copper", 0.0, 2092, 8},
		{"waxed_weathered_copper_bulb", 0.0, 0, 0},
		{"waxed_weathered_copper_door", 0.0, 0, 0},
		{"waxed_weathered_copper_grate", 0.0, 0, 0},
		{"waxed_weathered_copper_trapdoor", 0.0, 0, 0},
		{"waxed_weathered_cut_copper", 0.0, 2100, 5},
		{"waxed_weathered_cut_copper_slab", 0.0, 2091, 1},
		{"waxed_weathered_cut_copper_stairs", 0.0, 0, 0},
		{"wayfinder_armor_trim_smithing_template", 0.0, 2773, 1},
		{"weathered_chiseled_copper", 0.0, 2767, 1},
		{"weathered_copper", 0.0, 2107, 9},
		{"weathered_copper_bulb", 0.0, 2768, 1},
		{"weathered_copper_door", 0.0, 2769, 1},
		{"weathered_copper_grate", 0.0, 2770, 1},
		{"weathered_copper_trapdoor", 0.0, 2771, 1},
		{"weathered_cut_copper", 0.0, 2116, 6},
		{"weathered_cut_copper_slab", 0.0, 2105, 2},
		{"weathered_cut_copper_stairs", 0.0, 2772, 1},
		{"web", 0.0, 1698, 3},
		{"wet_sponge", 0.0, 2321, 1},
		{"wheat", 0.0, 450, 6},
		{"wheat_seeds", 0.0, 0, 0},
		{"white_candle", 0.0, 0, 0},
		{"white_carpet", 0.0, 1406, 15},
		{"white_concrete_powder", 0.0, 0, 0},
		{"white_dye", 0.0, 880, 5},
		{"white_glazed_terracotta", 0.0, 0, 0},
		{"white_stained_glass", 0.0, 2777, 1},
		{"white_stained_glass_pane", 0.0, 0, 0},
		{"white_terracotta", 0.0, 2322, 1},
		{"white_tulip", 0.0, 2411, 2},
		{"white_wool", 0.0, 843, 3},
		{"wild_armor_trim_smithing_template", 0.0, 2778, 1},
		{"wind_charge", 0.0, 0, 0},
		{"wither_rose", 0.0, 1448, 2},
		{"wolf_armor", 0.0, 0, 0},
		{"wood", 0.0, 1907, 16},
		{"wooden_axe", 0.0, 0, 0},
		{"wooden_door", 0.0, 0, 0},
		{"wooden_hoe", 0.0, 0, 0},
		{"wooden_pickaxe", 0.0, 0, 0},
		{"wooden_shovel", 0.0, 0, 0},
		{"wooden_slabs", 0.0, 1132, 7},
		{"wooden_sword", 0.0, 0, 0},
		{"wool", 0.0, 2502, 1},
		{"writable_book", 0.0, 842, 1},
		{"yellow_candle", 0.0, 0, 0},
		{"yellow_carpet", 0.0, 0, 0},
		{"yellow_concrete_powder", 0.0, 0, 0},
		{"yellow_dye", 0.0, 903, 6},
		{"yellow_glazed_terracotta", 0.0, 0, 0},
		{"yellow_stained_glass", 0.0, 2783, 1},
		{"yellow_stained_glass_pane", 0.0, 0, 0},
		{"yellow_terracotta", 0.0, 2332, 1},
		{"yellow_wool", 0.0, 2780, 2},
	};

	namespace minecraft {
		static const size_t acacia_boat = 0;
		static const size_t acacia_door = 1;
		static const size_t acacia_fence = 2;
		static const size_t acacia_fence_gate = 3;
		static const size_t acacia_hanging_sign = 4;
		static const size_t acacia_log = 5;
		static const size_t acacia_planks = 6;
		static const size_t acacia_sapling = 7;
		static const size_t acacia_sign = 8;
		static const size_t acacia_slab = 9;
		static const size_t acacia_stairs = 10;
		static const size_t acacia_wood = 11;
		static const size_t activator_rail = 12;
		static const size_t allium = 13;
		static const size_t amethyst_block = 14;
		static const size_t amethyst_shard = 15;
		static const size_t ancient_debris = 16;
		static const size_t andesite = 17;
		static const size_t andesite_slab = 18;
		static const size_t andesite_stairs = 19;
		static const size_t andesite_wall = 20;
		static const size_t anvil = 21;
		static const size_t apple = 22;
		static const size_t appleenchanted = 23;
		static const size_t armadillo_scute = 24;
		static const size_t armor_stand = 25;
		static const size_t arrow = 26;
		static const size_t azure_bluet = 27;
		static const size_t baked_potato = 28;
		static const size_t bamboo = 29;
		static const size_t bamboo_block = 30;
		static const size_t bamboo_button = 31;
		static const size_t bamboo_door = 32;
		static const size_t bamboo_fence = 33;
		static const size_t bamboo_fence_gate = 34;
		static const size_t bamboo_hanging_sign = 35;
		static const size_t bamboo_mosaic = 36;
		static const size_t bamboo_mosaic_slab = 37;
		static const size_t bamboo_mosaic_stairs = 38;
		static const size_t bamboo_planks = 39;
		static const size_t bamboo_pressure_plate = 40;
		static const size_t bamboo_raft = 41;
		static const size_t bamboo_sign = 42;
		static const size_t bamboo_slab = 43;
		static const size_t bamboo_stairs = 44;
		static const size_t bamboo_trapdoor = 45;
		static const size_t banner = 46;
		static const size_t banner_pattern = 47;
		static const size_t barrel = 48;
		static const size_t basalt = 49;
		static const size_t beacon = 50;
		static const size_t bed = 51;
		static const size_t beef = 52;
		static const size_t beehive = 53;
		static const size_t beetroot = 54;
		static const size_t beetroot_seeds = 55;
		static const size_t beetroot_soup = 56;
		static const size_t bell = 57;
		static const size_t birch_boat = 58;
		static const size_t birch_door = 59;
		static const size_t birch_fence = 60;
		static const size_t birch_fence_gate = 61;
		static const size_t birch_hanging_sign = 62;
		static const size_t birch_log = 63;
		static const size_t birch_planks = 64;
		static const size_t birch_sapling = 65;
		static const size_t birch_sign = 66;
		static const size_t birch_slab = 67;
		static const size_t birch_stairs = 68;
		static const size_t birch_wood = 69;
		static const size_t black_candle = 70;
		static const size_t black_carpet = 71;
		static const size_t black_concrete_powder = 72;
		static const size_t black_dye = 73;
		static const size_t black_glazed_terracotta = 74;
		static const size_t black_stained_glass = 75;
		static const size_t black_stained_glass_pane = 76;
		static const size_t black_terracotta = 77;
		static const size_t black_wool = 78;
		static const size_t blackstone = 79;
		static const size_t blackstone_slab = 80;
		static const size_t blackstone_stairs = 81;
		static const size_t blackstone_wall = 82;
		static const size_t blast_furnace = 83;
		static const size_t blaze_powder = 84;
		static const size_t blaze_rod = 85;
		static const size_t blue_candle = 86;
		static const size_t blue_carpet = 87;
		static const size_t blue_concrete_powder = 88;
		static const size_t blue_dye = 89;
		static const size_t blue_glazed_terracotta = 90;
		static const size_t blue_ice = 91;
		static const size_t blue_orchid = 92;
		static const size_t blue_stained_glass = 93;
		static const size_t blue_stained_glass_pane = 94;
		static const size_t blue_terracotta = 95;
		static const size_t blue_wool = 96;
		static const size_t boat = 97;
		static const size_t bolt_armor_trim_smithing_template = 98;
		static const size_t bone = 99;
		static const size_t bone_block = 100;
		static const size_t bone_meal = 101;
		static const size_t book = 102;
		static const size_t bookshelf = 103;
		static const size_t bow = 104;
		static const size_t bowl = 105;
		static const size_t brain_coral_block = 106;
		static const size_t bread = 107;
		static const size_t breeze_rod = 108;
		static const size_t brewing_stand = 109;
		static const size_t brick = 110;
		static const size_t brick_block = 111;
		static const size_t brick_slab = 112;
		static const size_t brick_stairs = 113;
		static const size_t brick_wall = 114;
		static const size_t brown_candle = 115;
		static const size_t brown_carpet = 116;
		static const size_t brown_concrete_powder = 117;
		static const size_t brown_dye = 118;
		static const size_t brown_glazed_terracotta = 119;
		static const size_t brown_mushroom = 120;
		static const size_t brown_stained_glass = 121;
		static const size_t brown_stained_glass_pane = 122;
		static const size_t brown_terracotta = 123;
		static const size_t brown_wool = 124;
		static const size_t brush = 125;
		static const size_t bubble_coral_block = 126;
		static const size_t bucket = 127;
		static const size_t bundle = 128;
		static const size_t cactus = 129;
		static const size_t cake = 130;
		static const size_t calibrated_sculk_sensor = 131;
		static const size_t campfire = 132;
		static const size_t candle = 133;
		static const size_t carpet = 134;
		static const size_t carrot = 135;
		static const size_t carrotonastick = 136;
		static const size_t cartography_table = 137;
		static const size_t carved_pumpkin = 138;
		static const size_t cauldron = 139;
		static const size_t chain = 140;
		static const size_t chainmail_boots = 141;
		static const size_t chainmail_chestplate = 142;
		static const size_t chainmail_helmet = 143;
		static const size_t chainmail_leggings = 144;
		static const size_t charcoal = 145;
		static const size_t cherry_boat = 146;
		static const size_t cherry_button = 147;
		static const size_t cherry_chest_boat = 148;
		static const size_t cherry_door = 149;
		static const size_t cherry_fence = 150;
		static const size_t cherry_fence_gate = 151;
		static const size_t cherry_hanging_sign = 152;
		static const size_t cherry_log = 153;
		static const size_t cherry_planks = 154;
		static const size_t cherry_pressure_plate = 155;
		static const size_t cherry_sapling = 156;
		static const size_t cherry_sign = 157;
		static const size_t cherry_slab = 158;
		static const size_t cherry_stairs = 159;
		static const size_t cherry_trapdoor = 160;
		static const size_t cherry_wood = 161;
		static const size_t chest = 162;
		static const size_t chest_boat = 163;
		static const size_t chest_minecart = 164;
		static const size_t chicken = 165;
		static const size_t chiseled_bookshelf = 166;
		static const size_t chiseled_copper = 167;
		static const size_t chiseled_deepslate = 168;
		static const size_t chiseled_nether_bricks = 169;
		static const size_t chiseled_polished_blackstone = 170;
		static const size_t chiseled_quartz_block = 171;
		static const size_t chiseled_red_sandstone = 172;
		static const size_t chiseled_resin_bricks = 173;
		static const size_t chiseled_sandstone = 174;
		static const size_t chiseled_stone_bricks = 175;
		static const size_t chiseled_tuff = 176;
		static const size_t chiseled_tuff_bricks = 177;
		static const size_t chorus_fruit = 178;
		static const size_t chorus_fruit_popped = 179;
		static const size_t clay = 180;
		static const size_t clay_ball = 181;
		static const size_t clock = 182;
		static const size_t closed_eyeblossom = 183;
		static const size_t clownfish = 184;
		static const size_t coal = 185;
		static const size_t coal_block = 186;
		static const size_t coal_ore = 187;
		static const size_t coals = 188;
		static const size_t coarse_dirt = 189;
		static const size_t coast_armor_trim_smithing_template = 190;
		static const size_t cobbled_deepslate = 191;
		static const size_t cobbled_deepslate_slab = 192;
		static const size_t cobbled_deepslate_stairs = 193;
		static const size_t cobbled_deepslate_wall = 194;
		static const size_t cobblestone = 195;
		static const size_t cobblestone_slab = 196;
		static const size_t cobblestone_wall = 197;
		static const size_t cocoa_beans = 198;
		static const size_t comparator = 199;
		static const size_t compass = 200;
		static const size_t composter = 201;
		static const size_t conduit = 202;
		static const size_t cooked_beef = 203;
		static const size_t cooked_chicken = 204;
		static const size_t cooked_fish = 205;
		static const size_t cooked_porkchop = 206;
		static const size_t cooked_rabbit = 207;
		static const size_t cooked_salmon = 208;
		static const size_t cookie = 209;
		static const size_t copper_block = 210;
		static const size_t copper_bulb = 211;
		static const size_t copper_door = 212;
		static const size_t copper_grate = 213;
		static const size_t copper_ingot = 214;
		static const size_t copper_ore = 215;
		static const size_t copper_trapdoor = 216;
		static const size_t cornflower = 217;
		static const size_t cracked_deepslate_bricks = 218;
		static const size_t cracked_deepslate_tiles = 219;
		static const size_t cracked_nether_bricks = 220;
		static const size_t cracked_polished_blackstone_bricks = 221;
		static const size_t cracked_stone_bricks = 222;
		static const size_t crafter = 223;
		static const size_t crafting_table = 224;
		static const size_t creaking_heart = 225;
		static const size_t crimson_button = 226;
		static const size_t crimson_door = 227;
		static const size_t crimson_fence = 228;
		static const size_t crimson_fence_gate = 229;
		static const size_t crimson_hanging_sign = 230;
		static const size_t crimson_hyphae = 231;
		static const size_t crimson_planks = 232;
		static const size_t crimson_pressure_plate = 233;
		static const size_t crimson_sign = 234;
		static const size_t crimson_slab = 235;
		static const size_t crimson_stairs = 236;
		static const size_t crimson_stem = 237;
		static const size_t crimson_trapdoor = 238;
		static const size_t crossbow = 239;
		static const size_t crying_obsidian = 240;
		static const size_t cut_copper = 241;
		static const size_t cut_copper_slab = 242;
		static const size_t cut_copper_stairs = 243;
		static const size_t cut_red_sandstone = 244;
		static const size_t cut_sandstone = 245;
		static const size_t cyan_candle = 246;
		static const size_t cyan_carpet = 247;
		static const size_t cyan_concrete_powder = 248;
		static const size_t cyan_dye = 249;
		static const size_t cyan_glazed_terracotta = 250;
		static const size_t cyan_stained_glass = 251;
		static const size_t cyan_stained_glass_pane = 252;
		static const size_t cyan_terracotta = 253;
		static const size_t cyan_wool = 254;
		static const size_t dandelion = 255;
		static const size_t dark_oak_boat = 256;
		static const size_t dark_oak_door = 257;
		static const size_t dark_oak_fence = 258;
		static const size_t dark_oak_fence_gate = 259;
		static const size_t dark_oak_hanging_sign = 260;
		static const size_t dark_oak_log = 261;
		static const size_t dark_oak_planks = 262;
		static const size_t dark_oak_sapling = 263;
		static const size_t dark_oak_slab = 264;
		static const size_t dark_oak_stairs = 265;
		static const size_t dark_oak_wood = 266;
		static const size_t dark_prismarine = 267;
		static const size_t dark_prismarine_slab = 268;
		static const size_t dark_prismarine_stairs = 269;
		static const size_t darkoak_sign = 270;
		static const size_t daylight_detector = 271;
		static const size_t deepslate = 272;
		static const size_t deepslate_brick_slab = 273;
		static const size_t deepslate_brick_stairs = 274;
		static const size_t deepslate_brick_wall = 275;
		static const size_t deepslate_bricks = 276;
		static const size_t deepslate_coal_ore = 277;
		static const size_t deepslate_copper_ore = 278;
		static const size_t deepslate_diamond_ore = 279;
		static const size_t deepslate_emerald_ore = 280;
		static const size_t deepslate_gold_ore = 281;
		static const size_t deepslate_iron_ore = 282;
		static const size_t deepslate_lapis_ore = 283;
		static const size_t deepslate_redstone_ore = 284;
		static const size_t deepslate_tile_slab = 285;
		static const size_t deepslate_tile_stairs = 286;
		static const size_t deepslate_tile_wall = 287;
		static const size_t deepslate_tiles = 288;
		static const size_t detector_rail = 289;
		static const size_t diamond = 290;
		static const size_t diamond_axe = 291;
		static const size_t diamond_block = 292;
		static const size_t diamond_boots = 293;
		static const size_t diamond_chestplate = 294;
		static const size_t diamond_helmet = 295;
		static const size_t diamond_hoe = 296;
		static const size_t diamond_leggings = 297;
		static const size_t diamond_ore = 298;
		static const size_t diamond_pickaxe = 299;
		static const size_t diamond_shovel = 300;
		static const size_t diamond_sword = 301;
		static const size_t diorite = 302;
		static const size_t diorite_slab = 303;
		static const size_t diorite_stairs = 304;
		static const size_t diorite_wall = 305;
		static const size_t dirt = 306;
		static const size_t dirt_with_roots = 307;
		static const size_t disc_fragment_5 = 308;
		static const size_t dispenser = 309;
		static const size_t dragon_breath = 310;
		static const size_t dried_kelp = 311;
		static const size_t dried_kelp_block = 312;
		static const size_t dripstone_block = 313;
		static const size_t dropper = 314;
		static const size_t dune_armor_trim_smithing_template = 315;
		static const size_t dye = 316;
		static const size_t echo_shard = 317;
		static const size_t egg = 318;
		static const size_t emerald = 319;
		static const size_t emerald_block = 320;
		static const size_t emerald_ore = 321;
		static const size_t emptymap = 322;
		static const size_t enchanting_table = 323;
		static const size_t end_brick_stairs = 324;
		static const size_t end_bricks = 325;
		static const size_t end_crystal = 326;
		static const size_t end_rod = 327;
		static const size_t end_stone = 328;
		static const size_t end_stone_brick_slab = 329;
		static const size_t end_stone_brick_wall = 330;
		static const size_t ender_chest = 331;
		static const size_t ender_eye = 332;
		static const size_t ender_pearl = 333;
		static const size_t experience_bottle = 334;
		static const size_t exposed_chiseled_copper = 335;
		static const size_t exposed_copper = 336;
		static const size_t exposed_copper_bulb = 337;
		static const size_t exposed_copper_door = 338;
		static const size_t exposed_copper_grate = 339;
		static const size_t exposed_copper_trapdoor = 340;
		static const size_t exposed_cut_copper = 341;
		static const size_t exposed_cut_copper_slab = 342;
		static const size_t exposed_cut_copper_stairs = 343;
		static const size_t eye_armor_trim_smithing_template = 344;
		static const size_t feather = 345;
		static const size_t fence_gate = 346;
		static const size_t fermented_spider_eye = 347;
		static const size_t fern = 348;
		static const size_t fire_charge = 349;
		static const size_t fire_coral_block = 350;
		static const size_t fish = 351;
		static const size_t fishing_rod = 352;
		static const size_t fletching_table = 353;
		static const size_t flint = 354;
		static const size_t flint_and_steel = 355;
		static const size_t flow_armor_trim_smithing_template = 356;
		static const size_t flower_pot = 357;
		static const size_t frame = 358;
		static const size_t furnace = 359;
		static const size_t ghast_tear = 360;
		static const size_t glass = 361;
		static const size_t glass_bottle = 362;
		static const size_t glass_pane = 363;
		static const size_t glow_frame = 364;
		static const size_t glow_ink_sac = 365;
		static const size_t glowstone = 366;
		static const size_t glowstone_dust = 367;
		static const size_t gold_block = 368;
		static const size_t gold_ingot = 369;
		static const size_t gold_nugget = 370;
		static const size_t gold_ore = 371;
		static const size_t golden_apple = 372;
		static const size_t golden_axe = 373;
		static const size_t golden_boots = 374;
		static const size_t golden_carrot = 375;
		static const size_t golden_chestplate = 376;
		static const size_t golden_helmet = 377;
		static const size_t golden_hoe = 378;
		static const size_t golden_leggings = 379;
		static const size_t golden_pickaxe = 380;
		static const size_t golden_rail = 381;
		static const size_t golden_shovel = 382;
		static const size_t golden_sword = 383;
		static const size_t granite = 384;
		static const size_t granite_slab = 385;
		static const size_t granite_stairs = 386;
		static const size_t granite_wall = 387;
		static const size_t gravel = 388;
		static const size_t gray_candle = 389;
		static const size_t gray_carpet = 390;
		static const size_t gray_concrete_powder = 391;
		static const size_t gray_dye = 392;
		static const size_t gray_glazed_terracotta = 393;
		static const size_t gray_stained_glass = 394;
		static const size_t gray_stained_glass_pane = 395;
		static const size_t gray_terracotta = 396;
		static const size_t gray_wool = 397;
		static const size_t green_candle = 398;
		static const size_t green_carpet = 399;
		static const size_t green_concrete_powder = 400;
		static const size_t green_dye = 401;
		static const size_t green_glazed_terracotta = 402;
		static const size_t green_stained_glass = 403;
		static const size_t green_stained_glass_pane = 404;
		static const size_t green_terracotta = 405;
		static const size_t green_wool = 406;
		static const size_t grindstone = 407;
		static const size_t gunpowder = 408;
		static const size_t hardened_clay = 409;
		static const size_t hay_block = 410;
		static const size_t heart_of_the_sea = 411;
		static const size_t heavy_core = 412;
		static const size_t heavy_weighted_pressure_plate = 413;
		static const size_t honey_block = 414;
		static const size_t honey_bottle = 415;
		static const size_t honeycomb = 416;
		static const size_t honeycomb_block = 417;
		static const size_t hopper = 418;
		static const size_t hopper_minecart = 419;
		static const size_t horn_coral_block = 420;
		static const size_t horsearmorgold = 421;
		static const size_t horsearmoriron = 422;
		static const size_t horsearmorleather = 423;
		static const size_t host_armor_trim_smithing_template = 424;
		static const size_t ice = 425;
		static const size_t ink_sac = 426;
		static const size_t iron_axe = 427;
		static const size_t iron_bars = 428;
		static const size_t iron_block = 429;
		static const size_t iron_boots = 430;
		static const size_t iron_chestplate = 431;
		static const size_t iron_door = 432;
		static const size_t iron_helmet = 433;
		static const size_t iron_hoe = 434;
		static const size_t iron_ingot = 435;
		static const size_t iron_leggings = 436;
		static const size_t iron_nugget = 437;
		static const size_t iron_ore = 438;
		static const size_t iron_pickaxe = 439;
		static const size_t iron_shovel = 440;
		static const size_t iron_sword = 441;
		static const size_t iron_trapdoor = 442;
		static const size_t jukebox = 443;
		static const size_t jungle_boat = 444;
		static const size_t jungle_door = 445;
		static const size_t jungle_fence = 446;
		static const size_t jungle_fence_gate = 447;
		static const size_t jungle_hanging_sign = 448;
		static const size_t jungle_log = 449;
		static const size_t jungle_planks = 450;
		static const size_t jungle_sapling = 451;
		static const size_t jungle_sign = 452;
		static const size_t jungle_slab = 453;
		static const size_t jungle_stairs = 454;
		static const size_t jungle_wood = 455;
		static const size_t kelp = 456;
		static const size_t ladder = 457;
		static const size_t lantern = 458;
		static const size_t lapis_block = 459;
		static const size_t lapis_lazuli = 460;
		static const size_t lapis_ore = 461;
		static const size_t lead = 462;
		static const size_t leather = 463;
		static const size_t leather_boots = 464;
		static const size_t leather_chestplate = 465;
		static const size_t leather_helmet = 466;
		static const size_t leather_leggings = 467;
		static const size_t lectern = 468;
		static const size_t lever = 469;
		static const size_t light_blue_candle = 470;
		static const size_t light_blue_carpet = 471;
		static const size_t light_blue_concrete_powder = 472;
		static const size_t light_blue_dye = 473;
		static const size_t light_blue_glazed_terracotta = 474;
		static const size_t light_blue_stained_glass = 475;
		static const size_t light_blue_stained_glass_pane = 476;
		static const size_t light_blue_terracotta = 477;
		static const size_t light_blue_wool = 478;
		static const size_t light_gray_candle = 479;
		static const size_t light_gray_carpet = 480;
		static const size_t light_gray_concrete_powder = 481;
		static const size_t light_gray_dye = 482;
		static const size_t light_gray_stained_glass = 483;
		static const size_t light_gray_stained_glass_pane = 484;
		static const size_t light_gray_terracotta = 485;
		static const size_t light_gray_wool = 486;
		static const size_t light_weighted_pressure_plate = 487;
		static const size_t lightning_rod = 488;
		static const size_t lilac = 489;
		static const size_t lily_of_the_valley = 490;
		static const size_t lime_candle = 491;
		static const size_t lime_carpet = 492;
		static const size_t lime_concrete_powder = 493;
		static const size_t lime_dye = 494;
		static const size_t lime_glazed_terracotta = 495;
		static const size_t lime_stained_glass = 496;
		static const size_t lime_stained_glass_pane = 497;
		static const size_t lime_terracotta = 498;
		static const size_t lime_wool = 499;
		static const size_t lingering_potion = 500;
		static const size_t lit_pumpkin = 501;
		static const size_t lodestone = 502;
		static const size_t lodestone_compass = 503;
		static const size_t log = 504;
		static const size_t log2 = 505;
		static const size_t logs = 506;
		static const size_t logs_that_burn = 507;
		static const size_t loom = 508;
		static const size_t mace = 509;
		static const size_t magenta_candle = 510;
		static const size_t magenta_carpet = 511;
		static const size_t magenta_concrete_powder = 512;
		static const size_t magenta_dye = 513;
		static const size_t magenta_glazed_terracotta = 514;
		static const size_t magenta_stained_glass = 515;
		static const size_t magenta_stained_glass_pane = 516;
		static const size_t magenta_terracotta = 517;
		static const size_t magenta_wool = 518;
		static const size_t magma = 519;
		static const size_t magma_cream = 520;
		static const size_t mangrove_boat = 521;
		static const size_t mangrove_button = 522;
		static const size_t mangrove_door = 523;
		static const size_t mangrove_fence = 524;
		static const size_t mangrove_fence_gate = 525;
		static const size_t mangrove_hanging_sign = 526;
		static const size_t mangrove_log = 527;
		static const size_t mangrove_planks = 528;
		static const size_t mangrove_pressure_plate = 529;
		static const size_t mangrove_propagule = 530;
		static const size_t mangrove_roots = 531;
		static const size_t mangrove_sign = 532;
		static const size_t mangrove_slab = 533;
		static const size_t mangrove_stairs = 534;
		static const size_t mangrove_trapdoor = 535;
		static const size_t mangrove_wood = 536;
		static const size_t map = 537;
		static const size_t melon = 538;
		static const size_t melon_block = 539;
		static const size_t melon_seeds = 540;
		static const size_t minecart = 541;
		static const size_t moss_block = 542;
		static const size_t moss_carpet = 543;
		static const size_t mossy_cobblestone = 544;
		static const size_t mossy_cobblestone_slab = 545;
		static const size_t mossy_cobblestone_stairs = 546;
		static const size_t mossy_cobblestone_wall = 547;
		static const size_t mossy_stone_brick_slab = 548;
		static const size_t mossy_stone_brick_stairs = 549;
		static const size_t mossy_stone_brick_wall = 550;
		static const size_t mossy_stone_bricks = 551;
		static const size_t mud = 552;
		static const size_t mud_brick_slab = 553;
		static const size_t mud_brick_stairs = 554;
		static const size_t mud_brick_wall = 555;
		static const size_t mud_bricks = 556;
		static const size_t muddy_mangrove_roots = 557;
		static const size_t mushroom_stew = 558;
		static const size_t muttonCooked = 559;
		static const size_t muttonRaw = 560;
		static const size_t muttonraw = 561;
		static const size_t nametag = 562;
		static const size_t nautilus_shell = 563;
		static const size_t nether_brick = 564;
		static const size_t nether_brick_fence = 565;
		static const size_t nether_brick_slab = 566;
		static const size_t nether_brick_stairs = 567;
		static const size_t nether_brick_wall = 568;
		static const size_t nether_gold_ore = 569;
		static const size_t nether_wart = 570;
		static const size_t nether_wart_block = 571;
		static const size_t netherbrick = 572;
		static const size_t netherite_axe = 573;
		static const size_t netherite_block = 574;
		static const size_t netherite_boots = 575;
		static const size_t netherite_chestplate = 576;
		static const size_t netherite_helmet = 577;
		static const size_t netherite_hoe = 578;
		static const size_t netherite_ingot = 579;
		static const size_t netherite_leggings = 580;
		static const size_t netherite_pickaxe = 581;
		static const size_t netherite_scrap = 582;
		static const size_t netherite_shovel = 583;
		static const size_t netherite_sword = 584;
		static const size_t netherite_upgrade_smithing_template = 585;
		static const size_t netherrack = 586;
		static const size_t netherstar = 587;
		static const size_t normal_stone_slab = 588;
		static const size_t normal_stone_stairs = 589;
		static const size_t noteblock = 590;
		static const size_t oak_boat = 591;
		static const size_t oak_fence = 592;
		static const size_t oak_hanging_sign = 593;
		static const size_t oak_log = 594;
		static const size_t oak_planks = 595;
		static const size_t oak_sapling = 596;
		static const size_t oak_slab = 597;
		static const size_t oak_stairs = 598;
		static const size_t oak_wood = 599;
		static const size_t observer = 600;
		static const size_t obsidian = 601;
		static const size_t open_eyeblossom = 602;
		static const size_t orange_candle = 603;
		static const size_t orange_carpet = 604;
		static const size_t orange_concrete_powder = 605;
		static const size_t orange_dye = 606;
		static const size_t orange_glazed_terracotta = 607;
		static const size_t orange_stained_glass = 608;
		static const size_t orange_stained_glass_pane = 609;
		static const size_t orange_terracotta = 610;
		static const size_t orange_tulip = 611;
		static const size_t orange_wool = 612;
		static const size_t oxeye_daisy = 613;
		static const size_t oxidized_chiseled_copper = 614;
		static const size_t oxidized_copper = 615;
		static const size_t oxidized_copper_bulb = 616;
		static const size_t oxidized_copper_door = 617;
		static const size_t oxidized_copper_grate = 618;
		static const size_t oxidized_copper_trapdoor = 619;
		static const size_t oxidized_cut_copper = 620;
		static const size_t oxidized_cut_copper_slab = 621;
		static const size_t oxidized_cut_copper_stairs = 622;
		static const size_t packed_ice = 623;
		static const size_t packed_mud = 624;
		static const size_t painting = 625;
		static const size_t pale_hanging_moss = 626;
		static const size_t pale_moss_block = 627;
		static const size_t pale_moss_carpet = 628;
		static const size_t pale_oak_boat = 629;
		static const size_t pale_oak_button = 630;
		static const size_t pale_oak_chest_boat = 631;
		static const size_t pale_oak_door = 632;
		static const size_t pale_oak_fence = 633;
		static const size_t pale_oak_fence_gate = 634;
		static const size_t pale_oak_hanging_sign = 635;
		static const size_t pale_oak_log = 636;
		static const size_t pale_oak_planks = 637;
		static const size_t pale_oak_pressure_plate = 638;
		static const size_t pale_oak_sapling = 639;
		static const size_t pale_oak_sign = 640;
		static const size_t pale_oak_slab = 641;
		static const size_t pale_oak_stairs = 642;
		static const size_t pale_oak_trapdoor = 643;
		static const size_t pale_oak_wood = 644;
		static const size_t paper = 645;
		static const size_t peony = 646;
		static const size_t phantom_membrane = 647;
		static const size_t pink_candle = 648;
		static const size_t pink_carpet = 649;
		static const size_t pink_concrete_powder = 650;
		static const size_t pink_dye = 651;
		static const size_t pink_glazed_terracotta = 652;
		static const size_t pink_petals = 653;
		static const size_t pink_stained_glass = 654;
		static const size_t pink_stained_glass_pane = 655;
		static const size_t pink_terracotta = 656;
		static const size_t pink_tulip = 657;
		static const size_t pink_wool = 658;
		static const size_t piston = 659;
		static const size_t pitcher_plant = 660;
		static const size_t planks = 661;
		static const size_t podzol = 662;
		static const size_t pointed_dripstone = 663;
		static const size_t polished_andesite = 664;
		static const size_t polished_andesite_slab = 665;
		static const size_t polished_andesite_stairs = 666;
		static const size_t polished_basalt = 667;
		static const size_t polished_blackstone = 668;
		static const size_t polished_blackstone_brick_slab = 669;
		static const size_t polished_blackstone_brick_stairs = 670;
		static const size_t polished_blackstone_brick_wall = 671;
		static const size_t polished_blackstone_bricks = 672;
		static const size_t polished_blackstone_button = 673;
		static const size_t polished_blackstone_pressure_plate = 674;
		static const size_t polished_blackstone_slab = 675;
		static const size_t polished_blackstone_stairs = 676;
		static const size_t polished_blackstone_wall = 677;
		static const size_t polished_deepslate = 678;
		static const size_t polished_deepslate_slab = 679;
		static const size_t polished_deepslate_stairs = 680;
		static const size_t polished_deepslate_wall = 681;
		static const size_t polished_diorite = 682;
		static const size_t polished_diorite_slab = 683;
		static const size_t polished_diorite_stairs = 684;
		static const size_t polished_granite = 685;
		static const size_t polished_granite_slab = 686;
		static const size_t polished_granite_stairs = 687;
		static const size_t polished_tuff = 688;
		static const size_t polished_tuff_slab = 689;
		static const size_t polished_tuff_stairs = 690;
		static const size_t polished_tuff_wall = 691;
		static const size_t poppy = 692;
		static const size_t porkchop = 693;
		static const size_t potato = 694;
		static const size_t potion = 695;
		static const size_t potion_type = 696;
		static const size_t prismarine = 697;
		static const size_t prismarine_brick_slab = 698;
		static const size_t prismarine_bricks = 699;
		static const size_t prismarine_bricks_stairs = 700;
		static const size_t prismarine_crystals = 701;
		static const size_t prismarine_shard = 702;
		static const size_t prismarine_slab = 703;
		static const size_t prismarine_stairs = 704;
		static const size_t prismarine_wall = 705;
		static const size_t pufferfish = 706;
		static const size_t pumpkin = 707;
		static const size_t pumpkin_pie = 708;
		static const size_t pumpkin_seeds = 709;
		static const size_t purple_candle = 710;
		static const size_t purple_carpet = 711;
		static const size_t purple_concrete_powder = 712;
		static const size_t purple_dye = 713;
		static const size_t purple_glazed_terracotta = 714;
		static const size_t purple_stained_glass = 715;
		static const size_t purple_stained_glass_pane = 716;
		static const size_t purple_terracotta = 717;
		static const size_t purple_wool = 718;
		static const size_t purpur_block = 719;
		static const size_t purpur_pillar = 720;
		static const size_t purpur_slab = 721;
		static const size_t purpur_stairs = 722;
		static const size_t quartz = 723;
		static const size_t quartz_block = 724;
		static const size_t quartz_bricks = 725;
		static const size_t quartz_ore = 726;
		static const size_t quartz_pillar = 727;
		static const size_t quartz_slab = 728;
		static const size_t quartz_stairs = 729;
		static const size_t rabbit = 730;
		static const size_t rabbit_foot = 731;
		static const size_t rabbit_hide = 732;
		static const size_t rabbit_stew = 733;
		static const size_t rail = 734;
		static const size_t raiser_armor_trim_smithing_template = 735;
		static const size_t raw_copper = 736;
		static const size_t raw_copper_block = 737;
		static const size_t raw_gold = 738;
		static const size_t raw_gold_block = 739;
		static const size_t raw_iron = 740;
		static const size_t raw_iron_block = 741;
		static const size_t record_5 = 742;
		static const size_t recovery_compass = 743;
		static const size_t red_candle = 744;
		static const size_t red_carpet = 745;
		static const size_t red_concrete_powder = 746;
		static const size_t red_dye = 747;
		static const size_t red_glazed_terracotta = 748;
		static const size_t red_mushroom = 749;
		static const size_t red_nether_brick = 750;
		static const size_t red_nether_brick_slab = 751;
		static const size_t red_nether_brick_stairs = 752;
		static const size_t red_nether_brick_wall = 753;
		static const size_t red_sand = 754;
		static const size_t red_sandstone = 755;
		static const size_t red_sandstone_slab = 756;
		static const size_t red_sandstone_stairs = 757;
		static const size_t red_sandstone_wall = 758;
		static const size_t red_stained_glass = 759;
		static const size_t red_stained_glass_pane = 760;
		static const size_t red_terracotta = 761;
		static const size_t red_tulip = 762;
		static const size_t red_wool = 763;
		static const size_t redstone = 764;
		static const size_t redstone_block = 765;
		static const size_t redstone_lamp = 766;
		static const size_t redstone_ore = 767;
		static const size_t redstone_torch = 768;
		static const size_t reeds = 769;
		static const size_t repeater = 770;
		static const size_t resin_block = 771;
		static const size_t resin_brick = 772;
		static const size_t resin_brick_slab = 773;
		static const size_t resin_brick_stairs = 774;
		static const size_t resin_brick_wall = 775;
		static const size_t resin_bricks = 776;
		static const size_t resin_clump = 777;
		static const size_t respawn_anchor = 778;
		static const size_t rib_armor_trim_smithing_template = 779;
		static const size_t rose_bush = 780;
		static const size_t rotten_flesh = 781;
		static const size_t saddle = 782;
		static const size_t salmon = 783;
		static const size_t sand = 784;
		static const size_t sandstone = 785;
		static const size_t sandstone_slab = 786;
		static const size_t sandstone_stairs = 787;
		static const size_t sandstone_wall = 788;
		static const size_t scaffolding = 789;
		static const size_t sculk_sensor = 790;
		static const size_t sea_pickle = 791;
		static const size_t sealantern = 792;
		static const size_t sentry_armor_trim_smithing_template = 793;
		static const size_t shaper_armor_trim_smithing_template = 794;
		static const size_t shears = 795;
		static const size_t shield = 796;
		static const size_t shulker_shell = 797;
		static const size_t sign = 798;
		static const size_t silence_armor_trim_smithing_template = 799;
		static const size_t silver_glazed_terracotta = 800;
		static const size_t skull = 801;
		static const size_t slime = 802;
		static const size_t slime_ball = 803;
		static const size_t small_dripleaf_block = 804;
		static const size_t smithing_table = 805;
		static const size_t smoker = 806;
		static const size_t smooth_basalt = 807;
		static const size_t smooth_quartz = 808;
		static const size_t smooth_quartz_slab = 809;
		static const size_t smooth_quartz_stairs = 810;
		static const size_t smooth_red_sandstone = 811;
		static const size_t smooth_red_sandstone_slab = 812;
		static const size_t smooth_red_sandstone_stairs = 813;
		static const size_t smooth_sandstone = 814;
		static const size_t smooth_sandstone_slab = 815;
		static const size_t smooth_sandstone_stairs = 816;
		static const size_t smooth_stone = 817;
		static const size_t smooth_stone_slab = 818;
		static const size_t snout_armor_trim_smithing_template = 819;
		static const size_t snow = 820;
		static const size_t snow_layer = 821;
		static const size_t snowball = 822;
		static const size_t soul_campfire = 823;
		static const size_t soul_fire_base_blocks = 824;
		static const size_t soul_lantern = 825;
		static const size_t soul_sand = 826;
		static const size_t soul_soil = 827;
		static const size_t soul_torch = 828;
		static const size_t speckled_melon = 829;
		static const size_t spider_eye = 830;
		static const size_t spire_armor_trim_smithing_template = 831;
		static const size_t splash_potion = 832;
		static const size_t sponge = 833;
		static const size_t spruce_boat = 834;
		static const size_t spruce_door = 835;
		static const size_t spruce_fence = 836;
		static const size_t spruce_fence_gate = 837;
		static const size_t spruce_hanging_sign = 838;
		static const size_t spruce_log = 839;
		static const size_t spruce_planks = 840;
		static const size_t spruce_sapling = 841;
		static const size_t spruce_sign = 842;
		static const size_t spruce_slab = 843;
		static const size_t spruce_stairs = 844;
		static const size_t spruce_wood = 845;
		static const size_t spyglass = 846;
		static const size_t stick = 847;
		static const size_t sticky_piston = 848;
		static const size_t stone = 849;
		static const size_t stone_axe = 850;
		static const size_t stone_brick_slab = 851;
		static const size_t stone_brick_stairs = 852;
		static const size_t stone_brick_wall = 853;
		static const size_t stone_bricks = 854;
		static const size_t stone_button = 855;
		static const size_t stone_crafting_materials = 856;
		static const size_t stone_hoe = 857;
		static const size_t stone_pickaxe = 858;
		static const size_t stone_pressure_plate = 859;
		static const size_t stone_shovel = 860;
		static const size_t stone_stairs = 861;
		static const size_t stone_sword = 862;
		static const size_t stone_tool_materials = 863;
		static const size_t stonecutter_block = 864;
		static const size_t string = 865;
		static const size_t stripped_acacia_log = 866;
		static const size_t stripped_acacia_wood = 867;
		static const size_t stripped_bamboo_block = 868;
		static const size_t stripped_birch_log = 869;
		static const size_t stripped_birch_wood = 870;
		static const size_t stripped_cherry_log = 871;
		static const size_t stripped_cherry_wood = 872;
		static const size_t stripped_crimson_hyphae = 873;
		static const size_t stripped_crimson_stem = 874;
		static const size_t stripped_dark_oak_log = 875;
		static const size_t stripped_dark_oak_wood = 876;
		static const size_t stripped_jungle_log = 877;
		static const size_t stripped_jungle_wood = 878;
		static const size_t stripped_mangrove_log = 879;
		static const size_t stripped_mangrove_wood = 880;
		static const size_t stripped_oak_log = 881;
		static const size_t stripped_oak_wood = 882;
		static const size_t stripped_pale_oak_log = 883;
		static const size_t stripped_pale_oak_wood = 884;
		static const size_t stripped_spruce_log = 885;
		static const size_t stripped_spruce_wood = 886;
		static const size_t stripped_warped_hyphae = 887;
		static const size_t stripped_warped_stem = 888;
		static const size_t sugar = 889;
		static const size_t sunflower = 890;
		static const size_t suspicious_stew = 891;
		static const size_t sweet_berries = 892;
		static const size_t target = 893;
		static const size_t tide_armor_trim_smithing_template = 894;
		static const size_t tinted_glass = 895;
		static const size_t tnt = 896;
		static const size_t tnt_minecart = 897;
		static const size_t torch = 898;
		static const size_t torchflower = 899;
		static const size_t trapped_chest = 900;
		static const size_t trim_materials = 901;
		static const size_t trim_templates = 902;
		static const size_t trimmable_armors = 903;
		static const size_t tripwire_hook = 904;
		static const size_t tube_coral_block = 905;
		static const size_t tuff = 906;
		static const size_t tuff_brick_slab = 907;
		static const size_t tuff_brick_stairs = 908;
		static const size_t tuff_brick_wall = 909;
		static const size_t tuff_bricks = 910;
		static const size_t tuff_slab = 911;
		static const size_t tuff_stairs = 912;
		static const size_t tuff_wall = 913;
		static const size_t turtle_helmet = 914;
		static const size_t turtle_shell_piece = 915;
		static const size_t undyed_shulker_box = 916;
		static const size_t vex_armor_trim_smithing_template = 917;
		static const size_t vine = 918;
		static const size_t ward_armor_trim_smithing_template = 919;
		static const size_t warped_button = 920;
		static const size_t warped_door = 921;
		static const size_t warped_fence = 922;
		static const size_t warped_fence_gate = 923;
		static const size_t warped_fungus = 924;
		static const size_t warped_fungus_on_a_stick = 925;
		static const size_t warped_hanging_sign = 926;
		static const size_t warped_hyphae = 927;
		static const size_t warped_planks = 928;
		static const size_t warped_pressure_plate = 929;
		static const size_t warped_sign = 930;
		static const size_t warped_slab = 931;
		static const size_t warped_stairs = 932;
		static const size_t warped_stem = 933;
		static const size_t warped_trapdoor = 934;
		static const size_t waterlily = 935;
		static const size_t waxed_chiseled_copper = 936;
		static const size_t waxed_copper = 937;
		static const size_t waxed_copper_bulb = 938;
		static const size_t waxed_copper_door = 939;
		static const size_t waxed_copper_grate = 940;
		static const size_t waxed_copper_trapdoor = 941;
		static const size_t waxed_cut_copper = 942;
		static const size_t waxed_cut_copper_slab = 943;
		static const size_t waxed_cut_copper_stairs = 944;
		static const size_t waxed_exposed_chiseled_copper = 945;
		static const size_t waxed_exposed_copper = 946;
		static const size_t waxed_exposed_copper_bulb = 947;
		static const size_t waxed_exposed_copper_door = 948;
		static const size_t waxed_exposed_copper_grate = 949;
		static const size_t waxed_exposed_copper_trapdoor = 950;
		static const size_t waxed_exposed_cut_copper = 951;
		static const size_t waxed_exposed_cut_copper_slab = 952;
		static const size_t waxed_exposed_cut_copper_stairs = 953;
		static const size_t waxed_oxidized_chiseled_copper = 954;
		static const size_t waxed_oxidized_copper = 955;
		static const size_t waxed_oxidized_copper_bulb = 956;
		static const size_t waxed_oxidized_copper_door = 957;
		static const size_t waxed_oxidized_copper_grate = 958;
		static const size_t waxed_oxidized_copper_trapdoor = 959;
		static const size_t waxed_oxidized_cut_copper = 960;
		static const size_t waxed_oxidized_cut_copper_slab = 961;
		static const size_t waxed_oxidized_cut_copper_stairs = 962;
		static const size_t waxed_weathered_chiseled_copper = 963;
		static const size_t waxed_weathered_copper = 964;
		static const size_t waxed_weathered_copper_bulb = 965;
		static const size_t waxed_weathered_copper_door = 966;
		static const size_t waxed_weathered_copper_grate = 967;
		static const size_t waxed_weathered_copper_trapdoor = 968;
		static const size_t waxed_weathered_cut_copper = 969;
		static const size_t waxed_weathered_cut_copper_slab = 970;
		static const size_t waxed_weathered_cut_copper_stairs = 971;
		static const size_t wayfinder_armor_trim_smithing_template = 972;
		static const size_t weathered_chiseled_copper = 973;
		static const size_t weathered_copper = 974;
		static const size_t weathered_copper_bulb = 975;
		static const size_t weathered_copper_door = 976;
		static const size_t weathered_copper_grate = 977;
		static const size_t weathered_copper_trapdoor = 978;
		static const size_t weathered_cut_copper = 979;
		static const size_t weathered_cut_copper_slab = 980;
		static const size_t weathered_cut_copper_stairs = 981;
		static const size_t web = 982;
		static const size_t wet_sponge = 983;
		static const size_t wheat = 984;
		static const size_t wheat_seeds = 985;
		static const size_t white_candle = 986;
		static const size_t white_carpet = 987;
		static const size_t white_concrete_powder = 988;
		static const size_t white_dye = 989;
		static const size_t white_glazed_terracotta = 990;
		static const size_t white_stained_glass = 991;
		static const size_t white_stained_glass_pane = 992;
		static const size_t white_terracotta = 993;
		static const size_t white_tulip = 994;
		static const size_t white_wool = 995;
		static const size_t wild_armor_trim_smithing_template = 996;
		static const size_t wind_charge = 997;
		static const size_t wither_rose = 998;
		static const size_t wolf_armor = 999;
		static const size_t wood = 1000;
		static const size_t wooden_axe = 1001;
		static const size_t wooden_door = 1002;
		static const size_t wooden_hoe = 1003;
		static const size_t wooden_pickaxe = 1004;
		static const size_t wooden_shovel = 1005;
		static const size_t wooden_slabs = 1006;
		static const size_t wooden_sword = 1007;
		static const size_t wool = 1008;
		static const size_t writable_book = 1009;
		static const size_t yellow_candle = 1010;
		static const size_t yellow_carpet = 1011;
		static const size_t yellow_concrete_powder = 1012;
		static const size_t yellow_dye = 1013;
		static const size_t yellow_glazed_terracotta = 1014;
		static const size_t yellow_stained_glass = 1015;
		static const size_t yellow_stained_glass_pane = 1016;
		static const size_t yellow_terracotta = 1017;
		static const size_t yellow_wool = 1018;
	} // namespace minecraft

	static const size_t trades = 2784;

	static const size_t trade[trades] = {
		0, 22, 65, 234, 324, 572, 573, 574, 575, 576, 577, 578, 579, 580, 581, 582,
		583, 584, 585, 586, 587, 633, 838, 1485, 1486, 1772, 1, 2, 3, 4, 6, 7, 8,
		11, 12, 13, 14, 15, 16, 17, 21, 23, 24, 30, 32, 34, 35, 36, 37, 38, 40,
		42, 44, 47, 49, 54, 56, 57, 59, 60, 61, 62, 63, 66, 67, 69, 70, 72, 81,
		82, 84, 86, 88, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103,
		104, 105, 107, 108, 110, 111, 113, 115, 116, 117, 119, 120, 122, 123, 125,
		126, 128, 129, 130, 131, 136, 142, 143, 144, 145, 146, 147, 148, 149, 150,
		151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165,
		166, 167, 168, 169, 170, 171, 172, 173, 179, 186, 187, 189, 191, 195, 196,
		197, 198, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212,
		213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227,
		228, 229, 230, 231, 232, 233, 235, 236, 237, 238, 240, 242, 243, 244, 245,
		247, 248, 249, 250, 251, 252, 253, 254, 255, 256, 257, 258, 259, 260, 261,
		262, 263, 264, 265, 266, 267, 268, 269, 270, 271, 272, 273, 274, 275, 276,
		277, 278, 279, 280, 281, 282, 283, 284, 285, 286, 287, 288, 289, 290, 291,
		292, 293, 294, 295, 296, 297, 298, 299, 300, 301, 302, 303, 304, 305, 306,
		307, 308, 309, 310, 311, 312, 313, 314, 315, 316, 317, 318, 319, 320, 321,
		322, 323, 325, 326, 328, 331, 332, 822, 5, 239, 327, 347, 352, 427, 555,
		597, 598, 647, 657, 731, 800, 845, 1030, 1035, 1040, 1041, 1042, 1043, 1044,
		1045, 1046, 1047, 1050, 1051, 1052, 1053, 1054, 1055, 1187, 1278, 1279,
		1280, 1281, 1342, 1396, 1397, 1398, 1399, 1400, 1421, 1422, 1423, 1424,
		1567, 1775, 1776, 1777, 1778, 9, 557, 10, 246, 330, 446, 447, 636, 801,
		802, 803, 804, 805, 806, 808, 809, 810, 811, 821, 825, 833, 846, 1037, 1057,
		1058, 1059, 1060, 1210, 1343, 1386, 1394, 1395, 1408, 1446, 1489, 1767,
		1787, 1788, 1842, 1859, 18, 857, 19, 926, 20, 922, 25, 850, 26, 27, 817,
		28, 29, 118, 373, 374, 375, 376, 377, 378, 451, 591, 592, 593, 594, 595,
		596, 1139, 1184, 31, 420, 441, 550, 741, 1004, 1013, 1102, 1121, 1135, 1161,
		1237, 1275, 1330, 1371, 1854, 1892, 32, 33, 34, 35, 388, 595, 824, 1139,
		1352, 39, 41, 632, 974, 975, 976, 977, 979, 980, 981, 982, 983, 984, 985,
		986, 989, 1125, 1209, 43, 470, 528, 45, 114, 1786, 46, 1032, 48, 527, 1211,
		1362, 50, 461, 557, 653, 1029, 1241, 51, 923, 52, 394, 1358, 53, 590, 978,
		1340, 1341, 55, 1320, 1321, 58, 64, 85, 456, 556, 589, 731, 799, 840, 1079,
		1141, 1142, 1143, 1144, 1392, 1747, 67, 68, 878, 70, 71, 931, 73, 74, 469,
		75, 76, 77, 78, 79, 80, 336, 337, 347, 353, 354, 359, 360, 369, 379, 380,
		381, 382, 383, 384, 385, 387, 398, 399, 409, 429, 456, 540, 554, 559, 560,
		561, 562, 563, 564, 565, 566, 567, 568, 569, 570, 571, 572, 573, 574, 575,
		576, 577, 578, 579, 580, 581, 582, 583, 584, 585, 586, 587, 588, 603, 604,
		611, 717, 718, 727, 731, 732, 747, 748, 801, 806, 809, 810, 811, 834, 835,
		840, 976, 981, 983, 984, 985, 986, 993, 1007, 1019, 1023, 1027, 1028, 1040,
		1047, 1052, 1053, 1054, 1056, 1064, 1065, 1075, 1090, 1091, 1105, 1126,
		1146, 1170, 1171, 1178, 1216, 1227, 1242, 1248, 1249, 1256, 1264, 1322,
		1342, 1353, 1377, 1402, 1403, 1404, 1405, 1406, 1407, 1449, 1450, 1451,
		1452, 1453, 1454, 1455, 1456, 1457, 1458, 1459, 1460, 1461, 1462, 1463,
		1464, 1465, 1466, 1467, 1468, 1469, 1470, 1471, 1472, 1473, 1474, 1475,
		1476, 1477, 1478, 1479, 1480, 1481, 1482, 1483, 1485, 1486, 1487, 1493,
		1494, 1510, 1511, 1512, 1733, 1734, 1735, 1736, 1737, 1738, 1740, 1741,
		1742, 1744, 1745, 1746, 1771, 1772, 1773, 1775, 1776, 1777, 1778, 1791,
		1792, 1802, 1844, 1862, 1863, 1864, 1865, 1867, 1868, 1869, 1870, 1871,
		1872, 1873, 1874, 1875, 1876, 1877, 1878, 1879, 1880, 1881, 1882, 1884,
		82, 414, 415, 434, 435, 545, 546, 635, 736, 997, 1011, 1095, 1110, 1131,
		1150, 1231, 1268, 1326, 1357, 1848, 1849, 1888, 83, 109, 241, 329, 354,
		841, 842, 843, 844, 845, 87, 354, 554, 1883, 89, 731, 1774, 91, 92, 93,
		94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 451, 556, 1056,
		1080, 1081, 1082, 1083, 1085, 112, 1084, 120, 121, 123, 126, 130, 452, 453,
		454, 455, 825, 1883, 124, 410, 411, 416, 430, 431, 437, 448, 541, 542, 547,
		653, 733, 737, 739, 994, 998, 1000, 1001, 1002, 1008, 1077, 1092, 1096,
		1098, 1099, 1100, 1106, 1107, 1112, 1113, 1114, 1115, 1116, 1119, 1127,
		1128, 1132, 1133, 1147, 1152, 1153, 1154, 1155, 1156, 1158, 1159, 1228,
		1234, 1265, 1272, 1273, 1323, 1327, 1328, 1354, 1845, 1846, 1850, 1858,
		1883, 1885, 127, 132, 1844, 1847, 133, 993, 996, 134, 540, 544, 135, 409,
		413, 137, 412, 415, 419, 420, 423, 759, 138, 995, 997, 1003, 1004, 1006,
		139, 1129, 1131, 1134, 1135, 1137, 140, 1093, 1095, 1101, 1102, 1104, 141,
		1849, 1853, 1854, 1857, 174, 1355, 1357, 1370, 1371, 1373, 175, 1108, 1110,
		1120, 1121, 1123, 176, 1266, 1268, 1274, 1275, 1277, 177, 1886, 1888, 1891,
		1892, 1894, 178, 1229, 1231, 1236, 1237, 1239, 180, 1009, 1011, 1012, 1013,
		1015, 181, 543, 546, 549, 550, 553, 182, 432, 435, 440, 441, 444, 183, 1324,
		1326, 1329, 1330, 1332, 184, 734, 736, 740, 741, 743, 185, 1148, 1150, 1160,
		1161, 1163, 188, 631, 859, 190, 474, 533, 646, 955, 1378, 1513, 1516, 1567,
		1664, 1665, 1667, 1669, 1671, 1672, 1673, 1739, 1743, 192, 991, 992, 1308,
		1564, 1565, 1566, 1604, 1606, 1608, 193, 349, 813, 814, 990, 1306, 1546,
		1547, 1548, 1598, 1600, 1602, 194, 350, 351, 1282, 1517, 1518, 1519, 1588,
		1590, 1592, 199, 646, 760, 761, 762, 763, 812, 990, 1226, 1336, 333, 335,
		336, 337, 343, 344, 1402, 334, 357, 396, 601, 617, 622, 745, 1035, 1062,
		1168, 1246, 1401, 1491, 1774, 334, 357, 396, 617, 745, 1062, 1168, 1491,
		338, 339, 346, 563, 576, 956, 1429, 1456, 1465, 338, 361, 400, 605, 719,
		749, 1066, 1172, 1217, 1250, 1495, 1794, 340, 341, 342, 345, 347, 646, 1378,
		348, 558, 1504, 1768, 349, 636, 643, 644, 812, 815, 820, 862, 1090, 1189,
		1190, 1226, 1278, 1279, 1280, 1281, 1394, 1533, 1534, 1535, 1787, 352, 1048,
		353, 355, 1392, 356, 358, 359, 360, 367, 368, 369, 370, 371, 372, 361, 365,
		362, 363, 364, 366, 373, 538, 539, 1525, 1527, 1529, 374, 376, 375, 1117,
		1758, 377, 378, 1190, 1194, 379, 386, 387, 623, 651, 763, 1089, 380, 381,
		648, 760, 1086, 382, 383, 649, 761, 1087, 384, 385, 650, 762, 1088, 386,
		393, 455, 460, 594, 621, 623, 676, 844, 1028, 1060, 1144, 1215, 1281, 1400,
		1424, 1508, 1778, 1865, 1870, 1874, 1878, 1882, 388, 824, 389, 389, 418,
		419, 439, 440, 548, 549, 740, 760, 761, 762, 763, 829, 970, 971, 1003, 1012,
		1101, 1120, 1134, 1160, 1236, 1274, 1329, 1370, 1768, 1852, 1853, 1891,
		389, 825, 830, 390, 452, 457, 591, 618, 673, 715, 716, 717, 718, 726, 727,
		728, 729, 730, 841, 1019, 1057, 1141, 1212, 1278, 1397, 1421, 1505, 1775,
		1862, 1867, 1871, 1875, 1879, 390, 391, 392, 393, 589, 1034, 1806, 1807,
		1808, 1809, 1810, 1811, 1812, 1813, 1814, 1815, 1816, 1817, 1818, 1819,
		1820, 1821, 1822, 1823, 1824, 1825, 1826, 1827, 1828, 1829, 1830, 1831,
		1832, 1833, 1834, 1835, 1836, 1837, 1838, 1839, 1840, 1841, 391, 453, 458,
		592, 619, 674, 842, 1023, 1058, 1142, 1166, 1167, 1169, 1170, 1171, 1177,
		1178, 1179, 1180, 1181, 1213, 1279, 1398, 1422, 1506, 1776, 1863, 1868,
		1872, 1876, 1880, 392, 454, 459, 593, 620, 675, 843, 1027, 1059, 1143, 1214,
		1280, 1399, 1423, 1507, 1777, 1789, 1790, 1791, 1792, 1801, 1802, 1803,
		1804, 1805, 1864, 1869, 1873, 1877, 1881, 394, 1202, 1340, 1341, 1750, 1751,
		1752, 1753, 1754, 1755, 1756, 1757, 1758, 1759, 1760, 1761, 1762, 1763,
		1764, 1765, 395, 397, 398, 399, 405, 406, 1403, 400, 401, 408, 564, 577,
		958, 1430, 1457, 1466, 402, 403, 404, 407, 410, 411, 430, 431, 541, 542,
		733, 994, 1008, 1092, 1106, 1127, 1147, 1228, 1265, 1323, 1354, 1845, 1846,
		1858, 1885, 412, 432, 543, 734, 995, 1009, 1093, 1108, 1129, 1148, 1229,
		1266, 1324, 1355, 1886, 414, 418, 422, 758, 414, 415, 434, 435, 545, 546,
		736, 932, 997, 1011, 1095, 1110, 1131, 1150, 1231, 1268, 1326, 1357, 1387,
		1769, 1848, 1849, 1888, 417, 1765, 421, 422, 423, 443, 444, 552, 553, 743,
		1006, 1015, 1037, 1104, 1123, 1137, 1163, 1239, 1277, 1332, 1343, 1373,
		1395, 1842, 1856, 1857, 1894, 424, 425, 426, 482, 879, 1290, 1446, 1510,
		1520, 1521, 1522, 1532, 1594, 1595, 1596, 1597, 1603, 1609, 1610, 1619,
		1733, 1736, 1740, 1744, 427, 1660, 427, 1425, 1426, 1427, 1428, 1429, 1430,
		1431, 1432, 1433, 1434, 1435, 1436, 1437, 1438, 1439, 1440, 428, 482, 483,
		484, 659, 668, 678, 684, 691, 697, 703, 709, 832, 429, 433, 434, 439, 443,
		436, 1754, 438, 442, 445, 666, 834, 835, 1216, 1222, 1223, 1406, 1866, 446,
		447, 446, 659, 661, 663, 1038, 1536, 1537, 1538, 1539, 1540, 1807, 447,
		684, 685, 686, 687, 1039, 1697, 1698, 1699, 1700, 1701, 449, 450, 462, 463,
		464, 465, 466, 467, 468, 469, 470, 471, 472, 473, 474, 475, 476, 477, 478,
		479, 480, 481, 485, 486, 487, 488, 489, 490, 491, 492, 493, 494, 495, 496,
		497, 498, 499, 500, 502, 503, 504, 505, 506, 508, 509, 510, 511, 512, 513,
		514, 515, 516, 517, 518, 519, 520, 521, 522, 523, 524, 525, 526, 527, 528,
		529, 530, 531, 532, 533, 534, 535, 536, 462, 520, 831, 837, 838, 839, 1164,
		463, 522, 846, 1145, 1860, 464, 480, 486, 489, 490, 491, 492, 493, 494,
		495, 496, 498, 508, 511, 512, 513, 514, 517, 523, 465, 524, 829, 466, 467,
		526, 1165, 468, 471, 530, 1409, 472, 531, 473, 532, 836, 475, 534, 557,
		836, 1320, 476, 477, 535, 645, 478, 485, 488, 497, 500, 503, 504, 506, 510,
		516, 519, 521, 529, 536, 632, 647, 657, 659, 668, 678, 684, 691, 697, 703,
		709, 800, 815, 820, 984, 1212, 1213, 1214, 1215, 1226, 1278, 1279, 1280,
		1281, 1374, 1376, 1377, 1378, 1766, 479, 481, 487, 499, 502, 505, 509, 515,
		518, 525, 973, 483, 624, 637, 638, 639, 640, 641, 642, 764, 767, 771, 775,
		779, 780, 784, 789, 794, 880, 1295, 1296, 1297, 1300, 1303, 1408, 1511,
		1734, 1737, 1741, 1745, 1788, 484, 905, 501, 501, 837, 838, 839, 1769, 507,
		507, 537, 847, 545, 548, 552, 551, 554, 654, 660, 662, 1124, 1504, 557,
		1320, 558, 559, 911, 913, 915, 916, 1463, 1472, 559, 560, 561, 562, 563,
		564, 565, 566, 567, 568, 569, 570, 571, 837, 1771, 560, 573, 909, 910, 1426,
		1455, 1464, 561, 574, 914, 1176, 1182, 1427, 1451, 1452, 562, 575, 917,
		1175, 1428, 1453, 1454, 565, 579, 749, 750, 757, 960, 1432, 1458, 1467,
		566, 580, 962, 1066, 1067, 1074, 1433, 1459, 1468, 567, 581, 964, 1172,
		1173, 1183, 1434, 1475, 1476, 1748, 568, 582, 965, 1174, 1435, 1477, 1478,
		569, 583, 966, 1217, 1218, 1225, 1436, 1460, 1469, 570, 584, 968, 1437,
		1461, 1470, 1495, 1496, 1503, 571, 587, 848, 851, 867, 906, 921, 937, 957,
		959, 961, 963, 967, 969, 1462, 1471, 572, 720, 725, 1425, 1449, 1450, 578,
		719, 721, 724, 1431, 1473, 1474, 585, 1438, 1479, 1480, 1794, 1796, 1797,
		586, 1439, 1481, 1482, 1795, 1800, 588, 1440, 1483, 588, 839, 1487, 1773,
		590, 1793, 598, 1049, 1076, 1484, 599, 600, 602, 603, 604, 610, 611, 612,
		613, 615, 601, 605, 607, 614, 606, 616, 608, 609, 622, 1036, 1770, 625,
		626, 627, 628, 629, 630, 634, 635, 636, 652, 652, 655, 768, 770, 772, 774,
		776, 778, 781, 783, 785, 790, 795, 656, 786, 788, 791, 793, 796, 798, 657,
		657, 658, 1813, 664, 665, 1541, 1542, 1543, 1812, 667, 1822, 668, 669, 670,
		1557, 1558, 1559, 1560, 1561, 1816, 671, 672, 1556, 1562, 1563, 1821, 677,
		1831, 678, 679, 680, 1581, 1582, 1583, 1584, 1585, 1825, 681, 682, 1580,
		1586, 1587, 1830, 683, 688, 689, 1693, 1702, 1703, 690, 691, 692, 693, 1712,
		1713, 1714, 1715, 1716, 694, 695, 1694, 1717, 1718, 696, 697, 698, 699,
		1719, 1720, 1721, 1722, 1723, 700, 701, 1695, 1724, 1725, 702, 703, 704,
		705, 1726, 1727, 1728, 1729, 1730, 706, 707, 1696, 1731, 1732, 708, 1840,
		709, 710, 711, 1705, 1706, 1707, 1708, 1709, 1834, 712, 713, 1704, 1710,
		1711, 1839, 714, 1251, 1261, 714, 1384, 722, 723, 732, 735, 738, 742, 744,
		746, 747, 748, 754, 755, 1404, 751, 752, 753, 756, 758, 759, 1314, 1315,
		1393, 765, 766, 769, 773, 777, 782, 787, 792, 797, 1298, 1299, 1301, 1302,
		1304, 1305, 800, 807, 815, 816, 818, 819, 821, 821, 933, 1390, 1391, 1444,
		1647, 1648, 1649, 1650, 1651, 1659, 823, 826, 833, 1549, 1551, 1553, 1555,
		827, 828, 1550, 1552, 1554, 829, 830, 831, 832, 1333, 833, 836, 1202, 1340,
		1750, 1751, 1752, 1753, 1754, 1755, 1756, 1757, 1758, 1759, 1760, 1761,
		1762, 1763, 1764, 1765, 846, 849, 852, 853, 854, 855, 856, 858, 860, 861,
		863, 1344, 864, 865, 1203, 1205, 1206, 1531, 1577, 1578, 1579, 866, 1286,
		1287, 1288, 1652, 1661, 1691, 868, 869, 870, 871, 872, 873, 874, 875, 876,
		877, 881, 882, 883, 884, 885, 886, 887, 888, 889, 890, 1346, 891, 892, 893,
		894, 895, 896, 897, 898, 899, 1348, 900, 901, 902, 903, 904, 907, 908, 912,
		918, 919, 920, 1210, 1386, 924, 1263, 1337, 1338, 1339, 1629, 1630, 1631,
		1632, 1633, 1634, 925, 927, 1365, 928, 1368, 1369, 1442, 1638, 1639, 1640,
		1641, 1642, 929, 930, 1379, 934, 935, 1284, 1593, 936, 938, 939, 940, 941,
		942, 943, 944, 945, 946, 947, 948, 949, 950, 951, 952, 953, 954, 1193, 1194,
		1514, 1515, 1663, 1666, 1668, 1670, 972, 972, 975, 978, 988, 1488, 987,
		999, 1753, 1005, 1007, 1010, 1014, 1016, 1017, 1018, 1020, 1021, 1022, 1024,
		1025, 1026, 1019, 1023, 1027, 1028, 1031, 1033, 1032, 1036, 1037, 1061,
		1063, 1064, 1065, 1071, 1072, 1405, 1068, 1069, 1070, 1073, 1076, 1138,
		1078, 1079, 1164, 1410, 1509, 1086, 1087, 1088, 1089, 1091, 1094, 1097,
		1752, 1103, 1105, 1109, 1107, 1128, 1111, 1751, 1118, 1764, 1122, 1126,
		1130, 1136, 1138, 1140, 1140, 1207, 1412, 1413, 1414, 1415, 1416, 1417,
		1418, 1419, 1420, 1145, 1146, 1149, 1151, 1750, 1157, 1162, 1185, 1186,
		1488, 1188, 1189, 1193, 1191, 1192, 1568, 1569, 1570, 1859, 1195, 1196,
		1571, 1572, 1573, 1197, 1198, 1199, 1200, 1574, 1575, 1576, 1201, 1201,
		1241, 1202, 1341, 1750, 1751, 1752, 1753, 1754, 1755, 1756, 1757, 1758,
		1759, 1760, 1761, 1762, 1763, 1764, 1765, 1203, 1204, 1362, 1208, 1209,
		1210, 1219, 1220, 1221, 1224, 1227, 1230, 1232, 1757, 1233, 1761, 1235,
		1760, 1238, 1240, 1242, 1243, 1244, 1245, 1247, 1248, 1249, 1255, 1256,
		1257, 1258, 1260, 1246, 1250, 1252, 1259, 1253, 1254, 1262, 1749, 1264,
		1267, 1269, 1270, 1271, 1762, 1276, 1283, 1589, 1591, 1285, 1289, 1291,
		1292, 1293, 1294, 1523, 1524, 1526, 1528, 1530, 1653, 1662, 1692, 1307,
		1599, 1601, 1309, 1605, 1607, 1310, 1678, 1679, 1680, 1681, 1682, 1683,
		1684, 1685, 1686, 1687, 1688, 1689, 1690, 1783, 1784, 1785, 1311, 1312,
		1313, 1611, 1612, 1613, 1614, 1615, 1616, 1617, 1618, 1779, 1316, 1620,
		1621, 1317, 1544, 1545, 1318, 1319, 1622, 1623, 1624, 1767, 1322, 1325,
		1331, 1334, 1335, 1489, 1625, 1626, 1627, 1628, 1340, 1341, 1340, 1341,
		1343, 1345, 1347, 1349, 1350, 1351, 1352, 1351, 1353, 1356, 1359, 1759,
		1360, 1361, 1763, 1363, 1364, 1635, 1636, 1637, 1366, 1367, 1372, 1375,
		1376, 1385, 1380, 1381, 1382, 1383, 1643, 1644, 1645, 1646, 1385, 1386,
		1388, 1389, 1393, 1394, 1395, 1401, 1407, 1490, 1492, 1493, 1494, 1500,
		1501, 1408, 1411, 1411, 1412, 1413, 1414, 1415, 1416, 1417, 1418, 1419,
		1420, 1441, 1654, 1655, 1443, 1656, 1657, 1445, 1658, 1446, 1447, 1448,
		1449, 1451, 1453, 1455, 1456, 1457, 1458, 1459, 1460, 1461, 1462, 1463,
		1473, 1475, 1477, 1479, 1481, 1485, 1450, 1452, 1454, 1464, 1465, 1466,
		1467, 1468, 1469, 1470, 1471, 1472, 1474, 1476, 1478, 1480, 1482, 1486,
		1483, 1487, 1484, 1489, 1497, 1498, 1499, 1502, 1509, 1512, 1735, 1738,
		1742, 1746, 1674, 1675, 1676, 1677, 1780, 1781, 1782, 1755, 1889, 1756,
		1851, 1766, 1843, 1767, 1770, 1787, 1788, 1793, 1798, 1799, 1806, 1808,
		1809, 1810, 1811, 1814, 1815, 1817, 1818, 1819, 1820, 1823, 1824, 1826,
		1827, 1828, 1829, 1832, 1833, 1835, 1836, 1837, 1838, 1841, 1842, 1848,
		1852, 1856, 1855, 1859, 1861, 1884, 1887, 1890, 1893,
	};

	template <typename T>
	void remove_copy_if(size_t i, T& result) {
		if (i < size) {
			const std::string& name = item[i].name;

			std::remove_copy_if(name.begin(), name.end(), std::back_inserter(result), [](char c){ return c == '_'; });
		}
	}
} // namespace Items

#endif // ITEMS_H
