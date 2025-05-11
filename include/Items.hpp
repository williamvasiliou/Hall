#ifndef ITEMS_H
#define ITEMS_H

#include <cstdint>
#include <string>

namespace Items {
	static inline const size_t size = 1019;

	typedef struct {
		const std::string name;
		const double rate;
		const size_t index;
		const size_t next;
	} Item;

	static const Item item[size] = {
		{"acacia_boat", 0.0, 0, 1},
		{"acacia_door", 0.0, 1, 1},
		{"acacia_fence", 0.0, 1, 1},
		{"acacia_fence_gate", 0.0, 1, 1},
		{"acacia_hanging_sign", 0.0, 1, 1},
		{"acacia_log", 0.0, 1, 3},
		{"acacia_planks", 0.0, 3, 10},
		{"acacia_sapling", 0.0, 10, 10},
		{"acacia_sign", 0.0, 10, 10},
		{"acacia_slab", 0.0, 10, 10},
		{"acacia_stairs", 0.0, 10, 10},
		{"acacia_wood", 0.0, 10, 11},
		{"activator_rail", 0.0, 11, 11},
		{"allium", 0.0, 11, 13},
		{"amethyst_block", 0.0, 13, 13},
		{"amethyst_shard", 0.0, 13, 17},
		{"ancient_debris", 0.0, 17, 18},
		{"andesite", 0.0, 18, 28},
		{"andesite_slab", 0.0, 28, 28},
		{"andesite_stairs", 0.0, 28, 28},
		{"andesite_wall", 0.0, 28, 28},
		{"anvil", 0.0, 28, 28},
		{"apple", 0.0, 28, 29},
		{"appleenchanted", 0.0, 29, 30},
		{"armadillo_scute", 0.0, 30, 31},
		{"armor_stand", 0.0, 31, 31},
		{"arrow", 0.0, 31, 46},
		{"azure_bluet", 0.0, 46, 48},
		{"baked_potato", 0.0, 48, 50},
		{"bamboo", 0.0, 50, 52},
		{"bamboo_block", 0.0, 52, 53},
		{"bamboo_button", 0.0, 53, 53},
		{"bamboo_door", 0.0, 53, 53},
		{"bamboo_fence", 0.0, 53, 53},
		{"bamboo_fence_gate", 0.0, 53, 53},
		{"bamboo_hanging_sign", 0.0, 53, 53},
		{"bamboo_mosaic", 0.0, 53, 55},
		{"bamboo_mosaic_slab", 0.0, 55, 55},
		{"bamboo_mosaic_stairs", 0.0, 55, 55},
		{"bamboo_planks", 0.0, 55, 65},
		{"bamboo_pressure_plate", 0.0, 65, 65},
		{"bamboo_raft", 0.0, 65, 65},
		{"bamboo_sign", 0.0, 65, 65},
		{"bamboo_slab", 0.0, 65, 66},
		{"bamboo_stairs", 0.0, 66, 66},
		{"bamboo_trapdoor", 0.0, 66, 66},
		{"banner", 0.0, 66, 66},
		{"banner_pattern", 0.0, 66, 66},
		{"barrel", 0.0, 66, 66},
		{"basalt", 0.0, 66, 69},
		{"beacon", 0.0, 69, 69},
		{"bed", 0.0, 69, 69},
		{"beef", 0.0, 69, 71},
		{"beehive", 0.0, 71, 71},
		{"beetroot", 0.0, 71, 74},
		{"beetroot_seeds", 0.0, 74, 74},
		{"beetroot_soup", 0.0, 74, 74},
		{"bell", 0.0, 74, 74},
		{"birch_boat", 0.0, 74, 74},
		{"birch_door", 0.0, 74, 74},
		{"birch_fence", 0.0, 74, 74},
		{"birch_fence_gate", 0.0, 74, 74},
		{"birch_hanging_sign", 0.0, 74, 74},
		{"birch_log", 0.0, 74, 76},
		{"birch_planks", 0.0, 76, 83},
		{"birch_sapling", 0.0, 83, 83},
		{"birch_sign", 0.0, 83, 83},
		{"birch_slab", 0.0, 83, 83},
		{"birch_stairs", 0.0, 83, 83},
		{"birch_wood", 0.0, 83, 84},
		{"black_candle", 0.0, 84, 84},
		{"black_carpet", 0.0, 84, 84},
		{"black_concrete_powder", 0.0, 84, 84},
		{"black_dye", 0.0, 84, 91},
		{"black_glazed_terracotta", 0.0, 91, 91},
		{"black_stained_glass", 0.0, 91, 92},
		{"black_stained_glass_pane", 0.0, 92, 92},
		{"black_terracotta", 0.0, 92, 93},
		{"black_wool", 0.0, 93, 96},
		{"blackstone", 0.0, 96, 120},
		{"blackstone_slab", 0.0, 120, 120},
		{"blackstone_stairs", 0.0, 120, 120},
		{"blackstone_wall", 0.0, 120, 120},
		{"blast_furnace", 0.0, 120, 120},
		{"blaze_powder", 0.0, 120, 127},
		{"blaze_rod", 0.0, 127, 140},
		{"blue_candle", 0.0, 140, 140},
		{"blue_carpet", 0.0, 140, 140},
		{"blue_concrete_powder", 0.0, 140, 140},
		{"blue_dye", 0.0, 140, 146},
		{"blue_glazed_terracotta", 0.0, 146, 146},
		{"blue_ice", 0.0, 146, 146},
		{"blue_orchid", 0.0, 146, 148},
		{"blue_stained_glass", 0.0, 148, 149},
		{"blue_stained_glass_pane", 0.0, 149, 149},
		{"blue_terracotta", 0.0, 149, 150},
		{"blue_wool", 0.0, 150, 152},
		{"boat", 0.0, 152, 160},
		{"bolt_armor_trim_smithing_template", 0.0, 160, 162},
		{"bone", 0.0, 162, 163},
		{"bone_block", 0.0, 163, 164},
		{"bone_meal", 0.0, 164, 167},
		{"book", 0.0, 167, 178},
		{"bookshelf", 0.0, 178, 182},
		{"bow", 0.0, 182, 183},
		{"bowl", 0.0, 183, 203},
		{"brain_coral_block", 0.0, 203, 203},
		{"bread", 0.0, 203, 203},
		{"breeze_rod", 0.0, 203, 208},
		{"brewing_stand", 0.0, 208, 208},
		{"brick", 0.0, 208, 210},
		{"brick_block", 0.0, 210, 216},
		{"brick_slab", 0.0, 216, 216},
		{"brick_stairs", 0.0, 216, 216},
		{"brick_wall", 0.0, 216, 216},
		{"brown_candle", 0.0, 216, 216},
		{"brown_carpet", 0.0, 216, 216},
		{"brown_concrete_powder", 0.0, 216, 216},
		{"brown_dye", 0.0, 216, 222},
		{"brown_glazed_terracotta", 0.0, 222, 222},
		{"brown_mushroom", 0.0, 222, 241},
		{"brown_stained_glass", 0.0, 241, 242},
		{"brown_stained_glass_pane", 0.0, 242, 242},
		{"brown_terracotta", 0.0, 242, 243},
		{"brown_wool", 0.0, 243, 246},
		{"brush", 0.0, 246, 246},
		{"bubble_coral_block", 0.0, 246, 246},
		{"bucket", 0.0, 246, 248},
		{"bundle", 0.0, 248, 248},
		{"cactus", 0.0, 248, 249},
		{"cake", 0.0, 249, 249},
		{"calibrated_sculk_sensor", 0.0, 249, 249},
		{"campfire", 0.0, 249, 249},
		{"candle", 0.0, 249, 270},
		{"carpet", 0.0, 270, 272},
		{"carrot", 0.0, 272, 277},
		{"carrotonastick", 0.0, 277, 277},
		{"cartography_table", 0.0, 277, 277},
		{"carved_pumpkin", 0.0, 277, 278},
		{"cauldron", 0.0, 278, 278},
		{"chain", 0.0, 278, 290},
		{"chainmail_boots", 0.0, 290, 291},
		{"chainmail_chestplate", 0.0, 291, 292},
		{"chainmail_helmet", 0.0, 292, 293},
		{"chainmail_leggings", 0.0, 293, 294},
		{"charcoal", 0.0, 294, 309},
		{"cherry_boat", 0.0, 309, 310},
		{"cherry_button", 0.0, 310, 310},
		{"cherry_chest_boat", 0.0, 310, 310},
		{"cherry_door", 0.0, 310, 310},
		{"cherry_fence", 0.0, 310, 310},
		{"cherry_fence_gate", 0.0, 310, 310},
		{"cherry_hanging_sign", 0.0, 310, 310},
		{"cherry_log", 0.0, 310, 312},
		{"cherry_planks", 0.0, 312, 322},
		{"cherry_pressure_plate", 0.0, 322, 322},
		{"cherry_sapling", 0.0, 322, 322},
		{"cherry_sign", 0.0, 322, 322},
		{"cherry_slab", 0.0, 322, 322},
		{"cherry_stairs", 0.0, 322, 322},
		{"cherry_trapdoor", 0.0, 322, 322},
		{"cherry_wood", 0.0, 322, 323},
		{"chest", 0.0, 323, 337},
		{"chest_boat", 0.0, 337, 337},
		{"chest_minecart", 0.0, 337, 337},
		{"chicken", 0.0, 337, 339},
		{"chiseled_bookshelf", 0.0, 339, 339},
		{"chiseled_copper", 0.0, 339, 340},
		{"chiseled_deepslate", 0.0, 340, 340},
		{"chiseled_nether_bricks", 0.0, 340, 340},
		{"chiseled_polished_blackstone", 0.0, 340, 340},
		{"chiseled_quartz_block", 0.0, 340, 340},
		{"chiseled_red_sandstone", 0.0, 340, 341},
		{"chiseled_resin_bricks", 0.0, 341, 341},
		{"chiseled_sandstone", 0.0, 341, 342},
		{"chiseled_stone_bricks", 0.0, 342, 343},
		{"chiseled_tuff", 0.0, 343, 343},
		{"chiseled_tuff_bricks", 0.0, 343, 343},
		{"chorus_fruit", 0.0, 343, 344},
		{"chorus_fruit_popped", 0.0, 344, 346},
		{"clay", 0.0, 346, 347},
		{"clay_ball", 0.0, 347, 350},
		{"clock", 0.0, 350, 350},
		{"closed_eyeblossom", 0.0, 350, 352},
		{"clownfish", 0.0, 352, 353},
		{"coal", 0.0, 353, 379},
		{"coal_block", 0.0, 379, 380},
		{"coal_ore", 0.0, 380, 381},
		{"coals", 0.0, 381, 385},
		{"coarse_dirt", 0.0, 385, 385},
		{"coast_armor_trim_smithing_template", 0.0, 385, 386},
		{"cobbled_deepslate", 0.0, 386, 416},
		{"cobbled_deepslate_slab", 0.0, 416, 417},
		{"cobbled_deepslate_stairs", 0.0, 417, 417},
		{"cobbled_deepslate_wall", 0.0, 417, 417},
		{"cobblestone", 0.0, 417, 438},
		{"cobblestone_slab", 0.0, 438, 438},
		{"cobblestone_wall", 0.0, 438, 438},
		{"cocoa_beans", 0.0, 438, 441},
		{"comparator", 0.0, 441, 441},
		{"compass", 0.0, 441, 450},
		{"composter", 0.0, 450, 450},
		{"conduit", 0.0, 450, 450},
		{"cooked_beef", 0.0, 450, 450},
		{"cooked_chicken", 0.0, 450, 450},
		{"cooked_fish", 0.0, 450, 450},
		{"cooked_porkchop", 0.0, 450, 450},
		{"cooked_rabbit", 0.0, 450, 452},
		{"cooked_salmon", 0.0, 452, 452},
		{"cookie", 0.0, 452, 452},
		{"copper_block", 0.0, 452, 463},
		{"copper_bulb", 0.0, 463, 464},
		{"copper_door", 0.0, 464, 465},
		{"copper_grate", 0.0, 465, 466},
		{"copper_ingot", 0.0, 466, 472},
		{"copper_ore", 0.0, 472, 473},
		{"copper_trapdoor", 0.0, 473, 474},
		{"cornflower", 0.0, 474, 476},
		{"cracked_deepslate_bricks", 0.0, 476, 476},
		{"cracked_deepslate_tiles", 0.0, 476, 476},
		{"cracked_nether_bricks", 0.0, 476, 476},
		{"cracked_polished_blackstone_bricks", 0.0, 476, 476},
		{"cracked_stone_bricks", 0.0, 476, 476},
		{"crafter", 0.0, 476, 476},
		{"crafting_table", 0.0, 476, 477},
		{"creaking_heart", 0.0, 477, 477},
		{"crimson_button", 0.0, 477, 477},
		{"crimson_door", 0.0, 477, 477},
		{"crimson_fence", 0.0, 477, 477},
		{"crimson_fence_gate", 0.0, 477, 477},
		{"crimson_hanging_sign", 0.0, 477, 477},
		{"crimson_hyphae", 0.0, 477, 478},
		{"crimson_planks", 0.0, 478, 508},
		{"crimson_pressure_plate", 0.0, 508, 508},
		{"crimson_sign", 0.0, 508, 508},
		{"crimson_slab", 0.0, 508, 513},
		{"crimson_stairs", 0.0, 513, 513},
		{"crimson_stem", 0.0, 513, 519},
		{"crimson_trapdoor", 0.0, 519, 519},
		{"crossbow", 0.0, 519, 519},
		{"crying_obsidian", 0.0, 519, 520},
		{"cut_copper", 0.0, 520, 526},
		{"cut_copper_slab", 0.0, 526, 528},
		{"cut_copper_stairs", 0.0, 528, 529},
		{"cut_red_sandstone", 0.0, 529, 530},
		{"cut_sandstone", 0.0, 530, 531},
		{"cyan_candle", 0.0, 531, 531},
		{"cyan_carpet", 0.0, 531, 531},
		{"cyan_concrete_powder", 0.0, 531, 531},
		{"cyan_dye", 0.0, 531, 537},
		{"cyan_glazed_terracotta", 0.0, 537, 537},
		{"cyan_stained_glass", 0.0, 537, 538},
		{"cyan_stained_glass_pane", 0.0, 538, 538},
		{"cyan_terracotta", 0.0, 538, 539},
		{"cyan_wool", 0.0, 539, 541},
		{"dandelion", 0.0, 541, 543},
		{"dark_oak_boat", 0.0, 543, 544},
		{"dark_oak_door", 0.0, 544, 544},
		{"dark_oak_fence", 0.0, 544, 544},
		{"dark_oak_fence_gate", 0.0, 544, 544},
		{"dark_oak_hanging_sign", 0.0, 544, 544},
		{"dark_oak_log", 0.0, 544, 546},
		{"dark_oak_planks", 0.0, 546, 553},
		{"dark_oak_sapling", 0.0, 553, 553},
		{"dark_oak_slab", 0.0, 553, 553},
		{"dark_oak_stairs", 0.0, 553, 553},
		{"dark_oak_wood", 0.0, 553, 554},
		{"dark_prismarine", 0.0, 554, 557},
		{"dark_prismarine_slab", 0.0, 557, 557},
		{"dark_prismarine_stairs", 0.0, 557, 557},
		{"darkoak_sign", 0.0, 557, 557},
		{"daylight_detector", 0.0, 557, 557},
		{"deepslate", 0.0, 557, 557},
		{"deepslate_brick_slab", 0.0, 557, 557},
		{"deepslate_brick_stairs", 0.0, 557, 557},
		{"deepslate_brick_wall", 0.0, 557, 557},
		{"deepslate_bricks", 0.0, 557, 569},
		{"deepslate_coal_ore", 0.0, 569, 570},
		{"deepslate_copper_ore", 0.0, 570, 571},
		{"deepslate_diamond_ore", 0.0, 571, 572},
		{"deepslate_emerald_ore", 0.0, 572, 573},
		{"deepslate_gold_ore", 0.0, 573, 574},
		{"deepslate_iron_ore", 0.0, 574, 575},
		{"deepslate_lapis_ore", 0.0, 575, 576},
		{"deepslate_redstone_ore", 0.0, 576, 577},
		{"deepslate_tile_slab", 0.0, 577, 577},
		{"deepslate_tile_stairs", 0.0, 577, 577},
		{"deepslate_tile_wall", 0.0, 577, 577},
		{"deepslate_tiles", 0.0, 577, 584},
		{"detector_rail", 0.0, 584, 584},
		{"diamond", 0.0, 584, 622},
		{"diamond_axe", 0.0, 622, 623},
		{"diamond_block", 0.0, 623, 624},
		{"diamond_boots", 0.0, 624, 625},
		{"diamond_chestplate", 0.0, 625, 626},
		{"diamond_helmet", 0.0, 626, 627},
		{"diamond_hoe", 0.0, 627, 628},
		{"diamond_leggings", 0.0, 628, 629},
		{"diamond_ore", 0.0, 629, 630},
		{"diamond_pickaxe", 0.0, 630, 631},
		{"diamond_shovel", 0.0, 631, 632},
		{"diamond_sword", 0.0, 632, 633},
		{"diorite", 0.0, 633, 645},
		{"diorite_slab", 0.0, 645, 645},
		{"diorite_stairs", 0.0, 645, 645},
		{"diorite_wall", 0.0, 645, 645},
		{"dirt", 0.0, 645, 646},
		{"dirt_with_roots", 0.0, 646, 646},
		{"disc_fragment_5", 0.0, 646, 647},
		{"dispenser", 0.0, 647, 647},
		{"dragon_breath", 0.0, 647, 648},
		{"dried_kelp", 0.0, 648, 649},
		{"dried_kelp_block", 0.0, 649, 651},
		{"dripstone_block", 0.0, 651, 651},
		{"dropper", 0.0, 651, 652},
		{"dune_armor_trim_smithing_template", 0.0, 652, 653},
		{"dye", 0.0, 653, 715},
		{"echo_shard", 0.0, 715, 717},
		{"egg", 0.0, 717, 719},
		{"emerald", 0.0, 719, 968},
		{"emerald_block", 0.0, 968, 969},
		{"emerald_ore", 0.0, 969, 970},
		{"emptymap", 0.0, 970, 972},
		{"enchanting_table", 0.0, 972, 972},
		{"end_brick_stairs", 0.0, 972, 972},
		{"end_bricks", 0.0, 972, 977},
		{"end_crystal", 0.0, 977, 977},
		{"end_rod", 0.0, 977, 977},
		{"end_stone", 0.0, 977, 983},
		{"end_stone_brick_slab", 0.0, 983, 983},
		{"end_stone_brick_wall", 0.0, 983, 983},
		{"ender_chest", 0.0, 983, 983},
		{"ender_eye", 0.0, 983, 985},
		{"ender_pearl", 0.0, 985, 986},
		{"experience_bottle", 0.0, 986, 986},
		{"exposed_chiseled_copper", 0.0, 986, 987},
		{"exposed_copper", 0.0, 987, 996},
		{"exposed_copper_bulb", 0.0, 996, 997},
		{"exposed_copper_door", 0.0, 997, 998},
		{"exposed_copper_grate", 0.0, 998, 999},
		{"exposed_copper_trapdoor", 0.0, 999, 1000},
		{"exposed_cut_copper", 0.0, 1000, 1006},
		{"exposed_cut_copper_slab", 0.0, 1006, 1008},
		{"exposed_cut_copper_stairs", 0.0, 1008, 1009},
		{"eye_armor_trim_smithing_template", 0.0, 1009, 1010},
		{"feather", 0.0, 1010, 1014},
		{"fence_gate", 0.0, 1014, 1014},
		{"fermented_spider_eye", 0.0, 1014, 1033},
		{"fern", 0.0, 1033, 1033},
		{"fire_charge", 0.0, 1033, 1033},
		{"fire_coral_block", 0.0, 1033, 1033},
		{"fish", 0.0, 1033, 1036},
		{"fishing_rod", 0.0, 1036, 1038},
		{"fletching_table", 0.0, 1038, 1038},
		{"flint", 0.0, 1038, 1048},
		{"flint_and_steel", 0.0, 1048, 1048},
		{"flow_armor_trim_smithing_template", 0.0, 1048, 1049},
		{"flower_pot", 0.0, 1049, 1049},
		{"frame", 0.0, 1049, 1050},
		{"furnace", 0.0, 1050, 1067},
		{"ghast_tear", 0.0, 1067, 1070},
		{"glass", 0.0, 1070, 1099},
		{"glass_bottle", 0.0, 1099, 1101},
		{"glass_pane", 0.0, 1101, 1118},
		{"glow_frame", 0.0, 1118, 1118},
		{"glow_ink_sac", 0.0, 1118, 1119},
		{"glowstone", 0.0, 1119, 1121},
		{"glowstone_dust", 0.0, 1121, 1132},
		{"gold_block", 0.0, 1132, 1133},
		{"gold_ingot", 0.0, 1133, 1150},
		{"gold_nugget", 0.0, 1150, 1153},
		{"gold_ore", 0.0, 1153, 1154},
		{"golden_apple", 0.0, 1154, 1154},
		{"golden_axe", 0.0, 1154, 1155},
		{"golden_boots", 0.0, 1155, 1156},
		{"golden_carrot", 0.0, 1156, 1157},
		{"golden_chestplate", 0.0, 1157, 1158},
		{"golden_helmet", 0.0, 1158, 1159},
		{"golden_hoe", 0.0, 1159, 1160},
		{"golden_leggings", 0.0, 1160, 1161},
		{"golden_pickaxe", 0.0, 1161, 1162},
		{"golden_rail", 0.0, 1162, 1162},
		{"golden_shovel", 0.0, 1162, 1163},
		{"golden_sword", 0.0, 1163, 1164},
		{"granite", 0.0, 1164, 1174},
		{"granite_slab", 0.0, 1174, 1174},
		{"granite_stairs", 0.0, 1174, 1174},
		{"granite_wall", 0.0, 1174, 1174},
		{"gravel", 0.0, 1174, 1196},
		{"gray_candle", 0.0, 1196, 1196},
		{"gray_carpet", 0.0, 1196, 1196},
		{"gray_concrete_powder", 0.0, 1196, 1196},
		{"gray_dye", 0.0, 1196, 1202},
		{"gray_glazed_terracotta", 0.0, 1202, 1202},
		{"gray_stained_glass", 0.0, 1202, 1203},
		{"gray_stained_glass_pane", 0.0, 1203, 1203},
		{"gray_terracotta", 0.0, 1203, 1204},
		{"gray_wool", 0.0, 1204, 1207},
		{"green_candle", 0.0, 1207, 1207},
		{"green_carpet", 0.0, 1207, 1207},
		{"green_concrete_powder", 0.0, 1207, 1207},
		{"green_dye", 0.0, 1207, 1213},
		{"green_glazed_terracotta", 0.0, 1213, 1213},
		{"green_stained_glass", 0.0, 1213, 1214},
		{"green_stained_glass_pane", 0.0, 1214, 1214},
		{"green_terracotta", 0.0, 1214, 1215},
		{"green_wool", 0.0, 1215, 1217},
		{"grindstone", 0.0, 1217, 1226},
		{"gunpowder", 0.0, 1226, 1231},
		{"hardened_clay", 0.0, 1231, 1255},
		{"hay_block", 0.0, 1255, 1257},
		{"heart_of_the_sea", 0.0, 1257, 1258},
		{"heavy_core", 0.0, 1258, 1259},
		{"heavy_weighted_pressure_plate", 0.0, 1259, 1259},
		{"honey_block", 0.0, 1259, 1260},
		{"honey_bottle", 0.0, 1260, 1262},
		{"honeycomb", 0.0, 1262, 1304},
		{"honeycomb_block", 0.0, 1304, 1304},
		{"hopper", 0.0, 1304, 1305},
		{"hopper_minecart", 0.0, 1305, 1305},
		{"horn_coral_block", 0.0, 1305, 1305},
		{"horsearmorgold", 0.0, 1305, 1306},
		{"horsearmoriron", 0.0, 1306, 1307},
		{"horsearmorleather", 0.0, 1307, 1307},
		{"host_armor_trim_smithing_template", 0.0, 1307, 1308},
		{"ice", 0.0, 1308, 1309},
		{"ink_sac", 0.0, 1309, 1313},
		{"iron_axe", 0.0, 1313, 1314},
		{"iron_bars", 0.0, 1314, 1314},
		{"iron_block", 0.0, 1314, 1316},
		{"iron_boots", 0.0, 1316, 1317},
		{"iron_chestplate", 0.0, 1317, 1318},
		{"iron_door", 0.0, 1318, 1318},
		{"iron_helmet", 0.0, 1318, 1319},
		{"iron_hoe", 0.0, 1319, 1320},
		{"iron_ingot", 0.0, 1320, 1370},
		{"iron_leggings", 0.0, 1370, 1371},
		{"iron_nugget", 0.0, 1371, 1375},
		{"iron_ore", 0.0, 1375, 1376},
		{"iron_pickaxe", 0.0, 1376, 1377},
		{"iron_shovel", 0.0, 1377, 1378},
		{"iron_sword", 0.0, 1378, 1379},
		{"iron_trapdoor", 0.0, 1379, 1379},
		{"jukebox", 0.0, 1379, 1379},
		{"jungle_boat", 0.0, 1379, 1380},
		{"jungle_door", 0.0, 1380, 1380},
		{"jungle_fence", 0.0, 1380, 1380},
		{"jungle_fence_gate", 0.0, 1380, 1380},
		{"jungle_hanging_sign", 0.0, 1380, 1380},
		{"jungle_log", 0.0, 1380, 1382},
		{"jungle_planks", 0.0, 1382, 1389},
		{"jungle_sapling", 0.0, 1389, 1389},
		{"jungle_sign", 0.0, 1389, 1389},
		{"jungle_slab", 0.0, 1389, 1389},
		{"jungle_stairs", 0.0, 1389, 1389},
		{"jungle_wood", 0.0, 1389, 1390},
		{"kelp", 0.0, 1390, 1391},
		{"ladder", 0.0, 1391, 1391},
		{"lantern", 0.0, 1391, 1391},
		{"lapis_block", 0.0, 1391, 1392},
		{"lapis_lazuli", 0.0, 1392, 1395},
		{"lapis_ore", 0.0, 1395, 1396},
		{"lead", 0.0, 1396, 1396},
		{"leather", 0.0, 1396, 1405},
		{"leather_boots", 0.0, 1405, 1405},
		{"leather_chestplate", 0.0, 1405, 1405},
		{"leather_helmet", 0.0, 1405, 1405},
		{"leather_leggings", 0.0, 1405, 1405},
		{"lectern", 0.0, 1405, 1405},
		{"lever", 0.0, 1405, 1405},
		{"light_blue_candle", 0.0, 1405, 1405},
		{"light_blue_carpet", 0.0, 1405, 1405},
		{"light_blue_concrete_powder", 0.0, 1405, 1405},
		{"light_blue_dye", 0.0, 1405, 1411},
		{"light_blue_glazed_terracotta", 0.0, 1411, 1411},
		{"light_blue_stained_glass", 0.0, 1411, 1412},
		{"light_blue_stained_glass_pane", 0.0, 1412, 1412},
		{"light_blue_terracotta", 0.0, 1412, 1413},
		{"light_blue_wool", 0.0, 1413, 1415},
		{"light_gray_candle", 0.0, 1415, 1415},
		{"light_gray_carpet", 0.0, 1415, 1415},
		{"light_gray_concrete_powder", 0.0, 1415, 1415},
		{"light_gray_dye", 0.0, 1415, 1421},
		{"light_gray_stained_glass", 0.0, 1421, 1422},
		{"light_gray_stained_glass_pane", 0.0, 1422, 1422},
		{"light_gray_terracotta", 0.0, 1422, 1423},
		{"light_gray_wool", 0.0, 1423, 1425},
		{"light_weighted_pressure_plate", 0.0, 1425, 1425},
		{"lightning_rod", 0.0, 1425, 1425},
		{"lilac", 0.0, 1425, 1426},
		{"lily_of_the_valley", 0.0, 1426, 1428},
		{"lime_candle", 0.0, 1428, 1428},
		{"lime_carpet", 0.0, 1428, 1428},
		{"lime_concrete_powder", 0.0, 1428, 1428},
		{"lime_dye", 0.0, 1428, 1434},
		{"lime_glazed_terracotta", 0.0, 1434, 1434},
		{"lime_stained_glass", 0.0, 1434, 1435},
		{"lime_stained_glass_pane", 0.0, 1435, 1435},
		{"lime_terracotta", 0.0, 1435, 1436},
		{"lime_wool", 0.0, 1436, 1438},
		{"lingering_potion", 0.0, 1438, 1438},
		{"lit_pumpkin", 0.0, 1438, 1438},
		{"lodestone", 0.0, 1438, 1438},
		{"lodestone_compass", 0.0, 1438, 1439},
		{"log", 0.0, 1439, 1446},
		{"log2", 0.0, 1446, 1453},
		{"logs", 0.0, 1453, 1456},
		{"logs_that_burn", 0.0, 1456, 1457},
		{"loom", 0.0, 1457, 1457},
		{"mace", 0.0, 1457, 1457},
		{"magenta_candle", 0.0, 1457, 1457},
		{"magenta_carpet", 0.0, 1457, 1457},
		{"magenta_concrete_powder", 0.0, 1457, 1457},
		{"magenta_dye", 0.0, 1457, 1463},
		{"magenta_glazed_terracotta", 0.0, 1463, 1463},
		{"magenta_stained_glass", 0.0, 1463, 1464},
		{"magenta_stained_glass_pane", 0.0, 1464, 1464},
		{"magenta_terracotta", 0.0, 1464, 1465},
		{"magenta_wool", 0.0, 1465, 1467},
		{"magma", 0.0, 1467, 1467},
		{"magma_cream", 0.0, 1467, 1470},
		{"mangrove_boat", 0.0, 1470, 1470},
		{"mangrove_button", 0.0, 1470, 1470},
		{"mangrove_door", 0.0, 1470, 1470},
		{"mangrove_fence", 0.0, 1470, 1470},
		{"mangrove_fence_gate", 0.0, 1470, 1470},
		{"mangrove_hanging_sign", 0.0, 1470, 1470},
		{"mangrove_log", 0.0, 1470, 1478},
		{"mangrove_planks", 0.0, 1478, 1509},
		{"mangrove_pressure_plate", 0.0, 1509, 1509},
		{"mangrove_propagule", 0.0, 1509, 1509},
		{"mangrove_roots", 0.0, 1509, 1510},
		{"mangrove_sign", 0.0, 1510, 1510},
		{"mangrove_slab", 0.0, 1510, 1515},
		{"mangrove_stairs", 0.0, 1515, 1515},
		{"mangrove_trapdoor", 0.0, 1515, 1515},
		{"mangrove_wood", 0.0, 1515, 1522},
		{"map", 0.0, 1522, 1522},
		{"melon", 0.0, 1522, 1525},
		{"melon_block", 0.0, 1525, 1526},
		{"melon_seeds", 0.0, 1526, 1526},
		{"minecart", 0.0, 1526, 1529},
		{"moss_block", 0.0, 1529, 1532},
		{"moss_carpet", 0.0, 1532, 1532},
		{"mossy_cobblestone", 0.0, 1532, 1538},
		{"mossy_cobblestone_slab", 0.0, 1538, 1538},
		{"mossy_cobblestone_stairs", 0.0, 1538, 1538},
		{"mossy_cobblestone_wall", 0.0, 1538, 1538},
		{"mossy_stone_brick_slab", 0.0, 1538, 1538},
		{"mossy_stone_brick_stairs", 0.0, 1538, 1538},
		{"mossy_stone_brick_wall", 0.0, 1538, 1538},
		{"mossy_stone_bricks", 0.0, 1538, 1543},
		{"mud", 0.0, 1543, 1545},
		{"mud_brick_slab", 0.0, 1545, 1545},
		{"mud_brick_stairs", 0.0, 1545, 1545},
		{"mud_brick_wall", 0.0, 1545, 1545},
		{"mud_bricks", 0.0, 1545, 1551},
		{"muddy_mangrove_roots", 0.0, 1551, 1551},
		{"mushroom_stew", 0.0, 1551, 1551},
		{"muttonCooked", 0.0, 1551, 1551},
		{"muttonRaw", 0.0, 1551, 1552},
		{"muttonraw", 0.0, 1552, 1553},
		{"nametag", 0.0, 1553, 1553},
		{"nautilus_shell", 0.0, 1553, 1554},
		{"nether_brick", 0.0, 1554, 1562},
		{"nether_brick_fence", 0.0, 1562, 1562},
		{"nether_brick_slab", 0.0, 1562, 1563},
		{"nether_brick_stairs", 0.0, 1563, 1563},
		{"nether_brick_wall", 0.0, 1563, 1563},
		{"nether_gold_ore", 0.0, 1563, 1564},
		{"nether_wart", 0.0, 1564, 1568},
		{"nether_wart_block", 0.0, 1568, 1568},
		{"netherbrick", 0.0, 1568, 1571},
		{"netherite_axe", 0.0, 1571, 1571},
		{"netherite_block", 0.0, 1571, 1572},
		{"netherite_boots", 0.0, 1572, 1572},
		{"netherite_chestplate", 0.0, 1572, 1572},
		{"netherite_helmet", 0.0, 1572, 1572},
		{"netherite_hoe", 0.0, 1572, 1572},
		{"netherite_ingot", 0.0, 1572, 1583},
		{"netherite_leggings", 0.0, 1583, 1583},
		{"netherite_pickaxe", 0.0, 1583, 1583},
		{"netherite_scrap", 0.0, 1583, 1584},
		{"netherite_shovel", 0.0, 1584, 1584},
		{"netherite_sword", 0.0, 1584, 1584},
		{"netherite_upgrade_smithing_template", 0.0, 1584, 1585},
		{"netherrack", 0.0, 1585, 1588},
		{"netherstar", 0.0, 1588, 1589},
		{"normal_stone_slab", 0.0, 1589, 1593},
		{"normal_stone_stairs", 0.0, 1593, 1593},
		{"noteblock", 0.0, 1593, 1593},
		{"oak_boat", 0.0, 1593, 1594},
		{"oak_fence", 0.0, 1594, 1594},
		{"oak_hanging_sign", 0.0, 1594, 1594},
		{"oak_log", 0.0, 1594, 1596},
		{"oak_planks", 0.0, 1596, 1605},
		{"oak_sapling", 0.0, 1605, 1605},
		{"oak_slab", 0.0, 1605, 1605},
		{"oak_stairs", 0.0, 1605, 1605},
		{"oak_wood", 0.0, 1605, 1606},
		{"observer", 0.0, 1606, 1606},
		{"obsidian", 0.0, 1606, 1609},
		{"open_eyeblossom", 0.0, 1609, 1611},
		{"orange_candle", 0.0, 1611, 1611},
		{"orange_carpet", 0.0, 1611, 1611},
		{"orange_concrete_powder", 0.0, 1611, 1611},
		{"orange_dye", 0.0, 1611, 1617},
		{"orange_glazed_terracotta", 0.0, 1617, 1617},
		{"orange_stained_glass", 0.0, 1617, 1618},
		{"orange_stained_glass_pane", 0.0, 1618, 1618},
		{"orange_terracotta", 0.0, 1618, 1619},
		{"orange_tulip", 0.0, 1619, 1621},
		{"orange_wool", 0.0, 1621, 1623},
		{"oxeye_daisy", 0.0, 1623, 1626},
		{"oxidized_chiseled_copper", 0.0, 1626, 1627},
		{"oxidized_copper", 0.0, 1627, 1636},
		{"oxidized_copper_bulb", 0.0, 1636, 1637},
		{"oxidized_copper_door", 0.0, 1637, 1638},
		{"oxidized_copper_grate", 0.0, 1638, 1639},
		{"oxidized_copper_trapdoor", 0.0, 1639, 1640},
		{"oxidized_cut_copper", 0.0, 1640, 1646},
		{"oxidized_cut_copper_slab", 0.0, 1646, 1648},
		{"oxidized_cut_copper_stairs", 0.0, 1648, 1649},
		{"packed_ice", 0.0, 1649, 1650},
		{"packed_mud", 0.0, 1650, 1651},
		{"painting", 0.0, 1651, 1651},
		{"pale_hanging_moss", 0.0, 1651, 1651},
		{"pale_moss_block", 0.0, 1651, 1652},
		{"pale_moss_carpet", 0.0, 1652, 1652},
		{"pale_oak_boat", 0.0, 1652, 1653},
		{"pale_oak_button", 0.0, 1653, 1653},
		{"pale_oak_chest_boat", 0.0, 1653, 1653},
		{"pale_oak_door", 0.0, 1653, 1653},
		{"pale_oak_fence", 0.0, 1653, 1653},
		{"pale_oak_fence_gate", 0.0, 1653, 1653},
		{"pale_oak_hanging_sign", 0.0, 1653, 1653},
		{"pale_oak_log", 0.0, 1653, 1656},
		{"pale_oak_planks", 0.0, 1656, 1666},
		{"pale_oak_pressure_plate", 0.0, 1666, 1666},
		{"pale_oak_sapling", 0.0, 1666, 1666},
		{"pale_oak_sign", 0.0, 1666, 1666},
		{"pale_oak_slab", 0.0, 1666, 1666},
		{"pale_oak_stairs", 0.0, 1666, 1666},
		{"pale_oak_trapdoor", 0.0, 1666, 1666},
		{"pale_oak_wood", 0.0, 1666, 1667},
		{"paper", 0.0, 1667, 1684},
		{"peony", 0.0, 1684, 1685},
		{"phantom_membrane", 0.0, 1685, 1686},
		{"pink_candle", 0.0, 1686, 1686},
		{"pink_carpet", 0.0, 1686, 1686},
		{"pink_concrete_powder", 0.0, 1686, 1686},
		{"pink_dye", 0.0, 1686, 1692},
		{"pink_glazed_terracotta", 0.0, 1692, 1692},
		{"pink_petals", 0.0, 1692, 1693},
		{"pink_stained_glass", 0.0, 1693, 1694},
		{"pink_stained_glass_pane", 0.0, 1694, 1694},
		{"pink_terracotta", 0.0, 1694, 1695},
		{"pink_tulip", 0.0, 1695, 1697},
		{"pink_wool", 0.0, 1697, 1699},
		{"piston", 0.0, 1699, 1700},
		{"pitcher_plant", 0.0, 1700, 1701},
		{"planks", 0.0, 1701, 1724},
		{"podzol", 0.0, 1724, 1724},
		{"pointed_dripstone", 0.0, 1724, 1726},
		{"polished_andesite", 0.0, 1726, 1729},
		{"polished_andesite_slab", 0.0, 1729, 1729},
		{"polished_andesite_stairs", 0.0, 1729, 1729},
		{"polished_basalt", 0.0, 1729, 1729},
		{"polished_blackstone", 0.0, 1729, 1743},
		{"polished_blackstone_brick_slab", 0.0, 1743, 1743},
		{"polished_blackstone_brick_stairs", 0.0, 1743, 1743},
		{"polished_blackstone_brick_wall", 0.0, 1743, 1743},
		{"polished_blackstone_bricks", 0.0, 1743, 1750},
		{"polished_blackstone_button", 0.0, 1750, 1750},
		{"polished_blackstone_pressure_plate", 0.0, 1750, 1750},
		{"polished_blackstone_slab", 0.0, 1750, 1751},
		{"polished_blackstone_stairs", 0.0, 1751, 1751},
		{"polished_blackstone_wall", 0.0, 1751, 1751},
		{"polished_deepslate", 0.0, 1751, 1766},
		{"polished_deepslate_slab", 0.0, 1766, 1766},
		{"polished_deepslate_stairs", 0.0, 1766, 1766},
		{"polished_deepslate_wall", 0.0, 1766, 1766},
		{"polished_diorite", 0.0, 1766, 1769},
		{"polished_diorite_slab", 0.0, 1769, 1769},
		{"polished_diorite_stairs", 0.0, 1769, 1769},
		{"polished_granite", 0.0, 1769, 1772},
		{"polished_granite_slab", 0.0, 1772, 1772},
		{"polished_granite_stairs", 0.0, 1772, 1772},
		{"polished_tuff", 0.0, 1772, 1784},
		{"polished_tuff_slab", 0.0, 1784, 1784},
		{"polished_tuff_stairs", 0.0, 1784, 1784},
		{"polished_tuff_wall", 0.0, 1784, 1784},
		{"poppy", 0.0, 1784, 1786},
		{"porkchop", 0.0, 1786, 1788},
		{"potato", 0.0, 1788, 1790},
		{"potion", 0.0, 1790, 1791},
		{"potion_type", 0.0, 1791, 1861},
		{"prismarine", 0.0, 1861, 1867},
		{"prismarine_brick_slab", 0.0, 1867, 1867},
		{"prismarine_bricks", 0.0, 1867, 1870},
		{"prismarine_bricks_stairs", 0.0, 1870, 1870},
		{"prismarine_crystals", 0.0, 1870, 1871},
		{"prismarine_shard", 0.0, 1871, 1876},
		{"prismarine_slab", 0.0, 1876, 1876},
		{"prismarine_stairs", 0.0, 1876, 1876},
		{"prismarine_wall", 0.0, 1876, 1876},
		{"pufferfish", 0.0, 1876, 1878},
		{"pumpkin", 0.0, 1878, 1881},
		{"pumpkin_pie", 0.0, 1881, 1881},
		{"pumpkin_seeds", 0.0, 1881, 1881},
		{"purple_candle", 0.0, 1881, 1881},
		{"purple_carpet", 0.0, 1881, 1881},
		{"purple_concrete_powder", 0.0, 1881, 1881},
		{"purple_dye", 0.0, 1881, 1887},
		{"purple_glazed_terracotta", 0.0, 1887, 1887},
		{"purple_stained_glass", 0.0, 1887, 1888},
		{"purple_stained_glass_pane", 0.0, 1888, 1888},
		{"purple_terracotta", 0.0, 1888, 1889},
		{"purple_wool", 0.0, 1889, 1891},
		{"purpur_block", 0.0, 1891, 1897},
		{"purpur_pillar", 0.0, 1897, 1898},
		{"purpur_slab", 0.0, 1898, 1898},
		{"purpur_stairs", 0.0, 1898, 1898},
		{"quartz", 0.0, 1898, 1908},
		{"quartz_block", 0.0, 1908, 1919},
		{"quartz_bricks", 0.0, 1919, 1919},
		{"quartz_ore", 0.0, 1919, 1920},
		{"quartz_pillar", 0.0, 1920, 1920},
		{"quartz_slab", 0.0, 1920, 1920},
		{"quartz_stairs", 0.0, 1920, 1920},
		{"rabbit", 0.0, 1920, 1922},
		{"rabbit_foot", 0.0, 1922, 1925},
		{"rabbit_hide", 0.0, 1925, 1927},
		{"rabbit_stew", 0.0, 1927, 1927},
		{"rail", 0.0, 1927, 1927},
		{"raiser_armor_trim_smithing_template", 0.0, 1927, 1928},
		{"raw_copper", 0.0, 1928, 1930},
		{"raw_copper_block", 0.0, 1930, 1931},
		{"raw_gold", 0.0, 1931, 1933},
		{"raw_gold_block", 0.0, 1933, 1934},
		{"raw_iron", 0.0, 1934, 1936},
		{"raw_iron_block", 0.0, 1936, 1937},
		{"record_5", 0.0, 1937, 1937},
		{"recovery_compass", 0.0, 1937, 1937},
		{"red_candle", 0.0, 1937, 1937},
		{"red_carpet", 0.0, 1937, 1937},
		{"red_concrete_powder", 0.0, 1937, 1937},
		{"red_dye", 0.0, 1937, 1943},
		{"red_glazed_terracotta", 0.0, 1943, 1943},
		{"red_mushroom", 0.0, 1943, 1961},
		{"red_nether_brick", 0.0, 1961, 1966},
		{"red_nether_brick_slab", 0.0, 1966, 1966},
		{"red_nether_brick_stairs", 0.0, 1966, 1966},
		{"red_nether_brick_wall", 0.0, 1966, 1966},
		{"red_sand", 0.0, 1966, 1968},
		{"red_sandstone", 0.0, 1968, 1977},
		{"red_sandstone_slab", 0.0, 1977, 1977},
		{"red_sandstone_stairs", 0.0, 1977, 1977},
		{"red_sandstone_wall", 0.0, 1977, 1977},
		{"red_stained_glass", 0.0, 1977, 1978},
		{"red_stained_glass_pane", 0.0, 1978, 1978},
		{"red_terracotta", 0.0, 1978, 1979},
		{"red_tulip", 0.0, 1979, 1981},
		{"red_wool", 0.0, 1981, 1983},
		{"redstone", 0.0, 1983, 2026},
		{"redstone_block", 0.0, 2026, 2027},
		{"redstone_lamp", 0.0, 2027, 2027},
		{"redstone_ore", 0.0, 2027, 2028},
		{"redstone_torch", 0.0, 2028, 2031},
		{"reeds", 0.0, 2031, 2033},
		{"repeater", 0.0, 2033, 2033},
		{"resin_block", 0.0, 2033, 2035},
		{"resin_brick", 0.0, 2035, 2036},
		{"resin_brick_slab", 0.0, 2036, 2037},
		{"resin_brick_stairs", 0.0, 2037, 2037},
		{"resin_brick_wall", 0.0, 2037, 2037},
		{"resin_bricks", 0.0, 2037, 2044},
		{"resin_clump", 0.0, 2044, 2046},
		{"respawn_anchor", 0.0, 2046, 2046},
		{"rib_armor_trim_smithing_template", 0.0, 2046, 2047},
		{"rose_bush", 0.0, 2047, 2048},
		{"rotten_flesh", 0.0, 2048, 2049},
		{"saddle", 0.0, 2049, 2049},
		{"salmon", 0.0, 2049, 2052},
		{"sand", 0.0, 2052, 2075},
		{"sandstone", 0.0, 2075, 2086},
		{"sandstone_slab", 0.0, 2086, 2086},
		{"sandstone_stairs", 0.0, 2086, 2086},
		{"sandstone_wall", 0.0, 2086, 2086},
		{"scaffolding", 0.0, 2086, 2086},
		{"sculk_sensor", 0.0, 2086, 2087},
		{"sea_pickle", 0.0, 2087, 2088},
		{"sealantern", 0.0, 2088, 2088},
		{"sentry_armor_trim_smithing_template", 0.0, 2088, 2089},
		{"shaper_armor_trim_smithing_template", 0.0, 2089, 2090},
		{"shears", 0.0, 2090, 2090},
		{"shield", 0.0, 2090, 2090},
		{"shulker_shell", 0.0, 2090, 2091},
		{"sign", 0.0, 2091, 2091},
		{"silence_armor_trim_smithing_template", 0.0, 2091, 2092},
		{"silver_glazed_terracotta", 0.0, 2092, 2092},
		{"skull", 0.0, 2092, 2094},
		{"slime", 0.0, 2094, 2097},
		{"slime_ball", 0.0, 2097, 2101},
		{"small_dripleaf_block", 0.0, 2101, 2101},
		{"smithing_table", 0.0, 2101, 2101},
		{"smoker", 0.0, 2101, 2101},
		{"smooth_basalt", 0.0, 2101, 2101},
		{"smooth_quartz", 0.0, 2101, 2104},
		{"smooth_quartz_slab", 0.0, 2104, 2104},
		{"smooth_quartz_stairs", 0.0, 2104, 2104},
		{"smooth_red_sandstone", 0.0, 2104, 2107},
		{"smooth_red_sandstone_slab", 0.0, 2107, 2107},
		{"smooth_red_sandstone_stairs", 0.0, 2107, 2107},
		{"smooth_sandstone", 0.0, 2107, 2109},
		{"smooth_sandstone_slab", 0.0, 2109, 2109},
		{"smooth_sandstone_stairs", 0.0, 2109, 2109},
		{"smooth_stone", 0.0, 2109, 2111},
		{"smooth_stone_slab", 0.0, 2111, 2112},
		{"snout_armor_trim_smithing_template", 0.0, 2112, 2113},
		{"snow", 0.0, 2113, 2114},
		{"snow_layer", 0.0, 2114, 2114},
		{"snowball", 0.0, 2114, 2115},
		{"soul_campfire", 0.0, 2115, 2115},
		{"soul_fire_base_blocks", 0.0, 2115, 2117},
		{"soul_lantern", 0.0, 2117, 2117},
		{"soul_sand", 0.0, 2117, 2135},
		{"soul_soil", 0.0, 2135, 2153},
		{"soul_torch", 0.0, 2153, 2154},
		{"speckled_melon", 0.0, 2154, 2156},
		{"spider_eye", 0.0, 2156, 2159},
		{"spire_armor_trim_smithing_template", 0.0, 2159, 2160},
		{"splash_potion", 0.0, 2160, 2161},
		{"sponge", 0.0, 2161, 2161},
		{"spruce_boat", 0.0, 2161, 2162},
		{"spruce_door", 0.0, 2162, 2162},
		{"spruce_fence", 0.0, 2162, 2162},
		{"spruce_fence_gate", 0.0, 2162, 2162},
		{"spruce_hanging_sign", 0.0, 2162, 2162},
		{"spruce_log", 0.0, 2162, 2164},
		{"spruce_planks", 0.0, 2164, 2171},
		{"spruce_sapling", 0.0, 2171, 2171},
		{"spruce_sign", 0.0, 2171, 2171},
		{"spruce_slab", 0.0, 2171, 2171},
		{"spruce_stairs", 0.0, 2171, 2171},
		{"spruce_wood", 0.0, 2171, 2172},
		{"spyglass", 0.0, 2172, 2172},
		{"stick", 0.0, 2172, 2377},
		{"sticky_piston", 0.0, 2377, 2377},
		{"stone", 0.0, 2377, 2395},
		{"stone_axe", 0.0, 2395, 2395},
		{"stone_brick_slab", 0.0, 2395, 2395},
		{"stone_brick_stairs", 0.0, 2395, 2395},
		{"stone_brick_wall", 0.0, 2395, 2395},
		{"stone_bricks", 0.0, 2395, 2404},
		{"stone_button", 0.0, 2404, 2404},
		{"stone_crafting_materials", 0.0, 2404, 2406},
		{"stone_hoe", 0.0, 2406, 2406},
		{"stone_pickaxe", 0.0, 2406, 2406},
		{"stone_pressure_plate", 0.0, 2406, 2407},
		{"stone_shovel", 0.0, 2407, 2407},
		{"stone_stairs", 0.0, 2407, 2407},
		{"stone_sword", 0.0, 2407, 2407},
		{"stone_tool_materials", 0.0, 2407, 2412},
		{"stonecutter_block", 0.0, 2412, 2412},
		{"string", 0.0, 2412, 2427},
		{"stripped_acacia_log", 0.0, 2427, 2436},
		{"stripped_acacia_wood", 0.0, 2436, 2437},
		{"stripped_bamboo_block", 0.0, 2437, 2439},
		{"stripped_birch_log", 0.0, 2439, 2448},
		{"stripped_birch_wood", 0.0, 2448, 2449},
		{"stripped_cherry_log", 0.0, 2449, 2452},
		{"stripped_cherry_wood", 0.0, 2452, 2453},
		{"stripped_crimson_hyphae", 0.0, 2453, 2454},
		{"stripped_crimson_stem", 0.0, 2454, 2461},
		{"stripped_dark_oak_log", 0.0, 2461, 2470},
		{"stripped_dark_oak_wood", 0.0, 2470, 2471},
		{"stripped_jungle_log", 0.0, 2471, 2480},
		{"stripped_jungle_wood", 0.0, 2480, 2481},
		{"stripped_mangrove_log", 0.0, 2481, 2491},
		{"stripped_mangrove_wood", 0.0, 2491, 2498},
		{"stripped_oak_log", 0.0, 2498, 2507},
		{"stripped_oak_wood", 0.0, 2507, 2508},
		{"stripped_pale_oak_log", 0.0, 2508, 2511},
		{"stripped_pale_oak_wood", 0.0, 2511, 2512},
		{"stripped_spruce_log", 0.0, 2512, 2521},
		{"stripped_spruce_wood", 0.0, 2521, 2522},
		{"stripped_warped_hyphae", 0.0, 2522, 2523},
		{"stripped_warped_stem", 0.0, 2523, 2530},
		{"sugar", 0.0, 2530, 2535},
		{"sunflower", 0.0, 2535, 2536},
		{"suspicious_stew", 0.0, 2536, 2536},
		{"sweet_berries", 0.0, 2536, 2537},
		{"target", 0.0, 2537, 2537},
		{"tide_armor_trim_smithing_template", 0.0, 2537, 2538},
		{"tinted_glass", 0.0, 2538, 2538},
		{"tnt", 0.0, 2538, 2539},
		{"tnt_minecart", 0.0, 2539, 2539},
		{"torch", 0.0, 2539, 2541},
		{"torchflower", 0.0, 2541, 2543},
		{"trapped_chest", 0.0, 2543, 2543},
		{"trim_materials", 0.0, 2543, 2544},
		{"trim_templates", 0.0, 2544, 2545},
		{"trimmable_armors", 0.0, 2545, 2546},
		{"tripwire_hook", 0.0, 2546, 2549},
		{"tube_coral_block", 0.0, 2549, 2549},
		{"tuff", 0.0, 2549, 2566},
		{"tuff_brick_slab", 0.0, 2566, 2567},
		{"tuff_brick_stairs", 0.0, 2567, 2567},
		{"tuff_brick_wall", 0.0, 2567, 2567},
		{"tuff_bricks", 0.0, 2567, 2574},
		{"tuff_slab", 0.0, 2574, 2575},
		{"tuff_stairs", 0.0, 2575, 2575},
		{"tuff_wall", 0.0, 2575, 2575},
		{"turtle_helmet", 0.0, 2575, 2576},
		{"turtle_shell_piece", 0.0, 2576, 2579},
		{"undyed_shulker_box", 0.0, 2579, 2579},
		{"vex_armor_trim_smithing_template", 0.0, 2579, 2580},
		{"vine", 0.0, 2580, 2583},
		{"ward_armor_trim_smithing_template", 0.0, 2583, 2584},
		{"warped_button", 0.0, 2584, 2584},
		{"warped_door", 0.0, 2584, 2584},
		{"warped_fence", 0.0, 2584, 2584},
		{"warped_fence_gate", 0.0, 2584, 2584},
		{"warped_fungus", 0.0, 2584, 2585},
		{"warped_fungus_on_a_stick", 0.0, 2585, 2585},
		{"warped_hanging_sign", 0.0, 2585, 2585},
		{"warped_hyphae", 0.0, 2585, 2586},
		{"warped_planks", 0.0, 2586, 2616},
		{"warped_pressure_plate", 0.0, 2616, 2616},
		{"warped_sign", 0.0, 2616, 2616},
		{"warped_slab", 0.0, 2616, 2621},
		{"warped_stairs", 0.0, 2621, 2621},
		{"warped_stem", 0.0, 2621, 2627},
		{"warped_trapdoor", 0.0, 2627, 2627},
		{"waterlily", 0.0, 2627, 2627},
		{"waxed_chiseled_copper", 0.0, 2627, 2627},
		{"waxed_copper", 0.0, 2627, 2638},
		{"waxed_copper_bulb", 0.0, 2638, 2638},
		{"waxed_copper_door", 0.0, 2638, 2638},
		{"waxed_copper_grate", 0.0, 2638, 2638},
		{"waxed_copper_trapdoor", 0.0, 2638, 2638},
		{"waxed_cut_copper", 0.0, 2638, 2643},
		{"waxed_cut_copper_slab", 0.0, 2643, 2644},
		{"waxed_cut_copper_stairs", 0.0, 2644, 2644},
		{"waxed_exposed_chiseled_copper", 0.0, 2644, 2644},
		{"waxed_exposed_copper", 0.0, 2644, 2652},
		{"waxed_exposed_copper_bulb", 0.0, 2652, 2652},
		{"waxed_exposed_copper_door", 0.0, 2652, 2652},
		{"waxed_exposed_copper_grate", 0.0, 2652, 2652},
		{"waxed_exposed_copper_trapdoor", 0.0, 2652, 2652},
		{"waxed_exposed_cut_copper", 0.0, 2652, 2657},
		{"waxed_exposed_cut_copper_slab", 0.0, 2657, 2658},
		{"waxed_exposed_cut_copper_stairs", 0.0, 2658, 2658},
		{"waxed_oxidized_chiseled_copper", 0.0, 2658, 2658},
		{"waxed_oxidized_copper", 0.0, 2658, 2666},
		{"waxed_oxidized_copper_bulb", 0.0, 2666, 2666},
		{"waxed_oxidized_copper_door", 0.0, 2666, 2666},
		{"waxed_oxidized_copper_grate", 0.0, 2666, 2666},
		{"waxed_oxidized_copper_trapdoor", 0.0, 2666, 2666},
		{"waxed_oxidized_cut_copper", 0.0, 2666, 2671},
		{"waxed_oxidized_cut_copper_slab", 0.0, 2671, 2672},
		{"waxed_oxidized_cut_copper_stairs", 0.0, 2672, 2672},
		{"waxed_weathered_chiseled_copper", 0.0, 2672, 2672},
		{"waxed_weathered_copper", 0.0, 2672, 2680},
		{"waxed_weathered_copper_bulb", 0.0, 2680, 2680},
		{"waxed_weathered_copper_door", 0.0, 2680, 2680},
		{"waxed_weathered_copper_grate", 0.0, 2680, 2680},
		{"waxed_weathered_copper_trapdoor", 0.0, 2680, 2680},
		{"waxed_weathered_cut_copper", 0.0, 2680, 2685},
		{"waxed_weathered_cut_copper_slab", 0.0, 2685, 2686},
		{"waxed_weathered_cut_copper_stairs", 0.0, 2686, 2686},
		{"wayfinder_armor_trim_smithing_template", 0.0, 2686, 2687},
		{"weathered_chiseled_copper", 0.0, 2687, 2688},
		{"weathered_copper", 0.0, 2688, 2697},
		{"weathered_copper_bulb", 0.0, 2697, 2698},
		{"weathered_copper_door", 0.0, 2698, 2699},
		{"weathered_copper_grate", 0.0, 2699, 2700},
		{"weathered_copper_trapdoor", 0.0, 2700, 2701},
		{"weathered_cut_copper", 0.0, 2701, 2707},
		{"weathered_cut_copper_slab", 0.0, 2707, 2709},
		{"weathered_cut_copper_stairs", 0.0, 2709, 2710},
		{"web", 0.0, 2710, 2713},
		{"wet_sponge", 0.0, 2713, 2714},
		{"wheat", 0.0, 2714, 2720},
		{"wheat_seeds", 0.0, 2720, 2720},
		{"white_candle", 0.0, 2720, 2720},
		{"white_carpet", 0.0, 2720, 2735},
		{"white_concrete_powder", 0.0, 2735, 2735},
		{"white_dye", 0.0, 2735, 2740},
		{"white_glazed_terracotta", 0.0, 2740, 2740},
		{"white_stained_glass", 0.0, 2740, 2741},
		{"white_stained_glass_pane", 0.0, 2741, 2741},
		{"white_terracotta", 0.0, 2741, 2742},
		{"white_tulip", 0.0, 2742, 2744},
		{"white_wool", 0.0, 2744, 2747},
		{"wild_armor_trim_smithing_template", 0.0, 2747, 2748},
		{"wind_charge", 0.0, 2748, 2748},
		{"wither_rose", 0.0, 2748, 2750},
		{"wolf_armor", 0.0, 2750, 2750},
		{"wood", 0.0, 2750, 2766},
		{"wooden_axe", 0.0, 2766, 2766},
		{"wooden_door", 0.0, 2766, 2766},
		{"wooden_hoe", 0.0, 2766, 2766},
		{"wooden_pickaxe", 0.0, 2766, 2766},
		{"wooden_shovel", 0.0, 2766, 2766},
		{"wooden_slabs", 0.0, 2766, 2773},
		{"wooden_sword", 0.0, 2773, 2773},
		{"wool", 0.0, 2773, 2774},
		{"writable_book", 0.0, 2774, 2775},
		{"yellow_candle", 0.0, 2775, 2775},
		{"yellow_carpet", 0.0, 2775, 2775},
		{"yellow_concrete_powder", 0.0, 2775, 2775},
		{"yellow_dye", 0.0, 2775, 2781},
		{"yellow_glazed_terracotta", 0.0, 2781, 2781},
		{"yellow_stained_glass", 0.0, 2781, 2782},
		{"yellow_stained_glass_pane", 0.0, 2782, 2782},
		{"yellow_terracotta", 0.0, 2782, 2783},
		{"yellow_wool", 0.0, 2783, 2785},
	};

	namespace minecraft {
		static inline const size_t acacia_boat = 0;
		static inline const size_t acacia_door = 1;
		static inline const size_t acacia_fence = 2;
		static inline const size_t acacia_fence_gate = 3;
		static inline const size_t acacia_hanging_sign = 4;
		static inline const size_t acacia_log = 5;
		static inline const size_t acacia_planks = 6;
		static inline const size_t acacia_sapling = 7;
		static inline const size_t acacia_sign = 8;
		static inline const size_t acacia_slab = 9;
		static inline const size_t acacia_stairs = 10;
		static inline const size_t acacia_wood = 11;
		static inline const size_t activator_rail = 12;
		static inline const size_t allium = 13;
		static inline const size_t amethyst_block = 14;
		static inline const size_t amethyst_shard = 15;
		static inline const size_t ancient_debris = 16;
		static inline const size_t andesite = 17;
		static inline const size_t andesite_slab = 18;
		static inline const size_t andesite_stairs = 19;
		static inline const size_t andesite_wall = 20;
		static inline const size_t anvil = 21;
		static inline const size_t apple = 22;
		static inline const size_t appleenchanted = 23;
		static inline const size_t armadillo_scute = 24;
		static inline const size_t armor_stand = 25;
		static inline const size_t arrow = 26;
		static inline const size_t azure_bluet = 27;
		static inline const size_t baked_potato = 28;
		static inline const size_t bamboo = 29;
		static inline const size_t bamboo_block = 30;
		static inline const size_t bamboo_button = 31;
		static inline const size_t bamboo_door = 32;
		static inline const size_t bamboo_fence = 33;
		static inline const size_t bamboo_fence_gate = 34;
		static inline const size_t bamboo_hanging_sign = 35;
		static inline const size_t bamboo_mosaic = 36;
		static inline const size_t bamboo_mosaic_slab = 37;
		static inline const size_t bamboo_mosaic_stairs = 38;
		static inline const size_t bamboo_planks = 39;
		static inline const size_t bamboo_pressure_plate = 40;
		static inline const size_t bamboo_raft = 41;
		static inline const size_t bamboo_sign = 42;
		static inline const size_t bamboo_slab = 43;
		static inline const size_t bamboo_stairs = 44;
		static inline const size_t bamboo_trapdoor = 45;
		static inline const size_t banner = 46;
		static inline const size_t banner_pattern = 47;
		static inline const size_t barrel = 48;
		static inline const size_t basalt = 49;
		static inline const size_t beacon = 50;
		static inline const size_t bed = 51;
		static inline const size_t beef = 52;
		static inline const size_t beehive = 53;
		static inline const size_t beetroot = 54;
		static inline const size_t beetroot_seeds = 55;
		static inline const size_t beetroot_soup = 56;
		static inline const size_t bell = 57;
		static inline const size_t birch_boat = 58;
		static inline const size_t birch_door = 59;
		static inline const size_t birch_fence = 60;
		static inline const size_t birch_fence_gate = 61;
		static inline const size_t birch_hanging_sign = 62;
		static inline const size_t birch_log = 63;
		static inline const size_t birch_planks = 64;
		static inline const size_t birch_sapling = 65;
		static inline const size_t birch_sign = 66;
		static inline const size_t birch_slab = 67;
		static inline const size_t birch_stairs = 68;
		static inline const size_t birch_wood = 69;
		static inline const size_t black_candle = 70;
		static inline const size_t black_carpet = 71;
		static inline const size_t black_concrete_powder = 72;
		static inline const size_t black_dye = 73;
		static inline const size_t black_glazed_terracotta = 74;
		static inline const size_t black_stained_glass = 75;
		static inline const size_t black_stained_glass_pane = 76;
		static inline const size_t black_terracotta = 77;
		static inline const size_t black_wool = 78;
		static inline const size_t blackstone = 79;
		static inline const size_t blackstone_slab = 80;
		static inline const size_t blackstone_stairs = 81;
		static inline const size_t blackstone_wall = 82;
		static inline const size_t blast_furnace = 83;
		static inline const size_t blaze_powder = 84;
		static inline const size_t blaze_rod = 85;
		static inline const size_t blue_candle = 86;
		static inline const size_t blue_carpet = 87;
		static inline const size_t blue_concrete_powder = 88;
		static inline const size_t blue_dye = 89;
		static inline const size_t blue_glazed_terracotta = 90;
		static inline const size_t blue_ice = 91;
		static inline const size_t blue_orchid = 92;
		static inline const size_t blue_stained_glass = 93;
		static inline const size_t blue_stained_glass_pane = 94;
		static inline const size_t blue_terracotta = 95;
		static inline const size_t blue_wool = 96;
		static inline const size_t boat = 97;
		static inline const size_t bolt_armor_trim_smithing_template = 98;
		static inline const size_t bone = 99;
		static inline const size_t bone_block = 100;
		static inline const size_t bone_meal = 101;
		static inline const size_t book = 102;
		static inline const size_t bookshelf = 103;
		static inline const size_t bow = 104;
		static inline const size_t bowl = 105;
		static inline const size_t brain_coral_block = 106;
		static inline const size_t bread = 107;
		static inline const size_t breeze_rod = 108;
		static inline const size_t brewing_stand = 109;
		static inline const size_t brick = 110;
		static inline const size_t brick_block = 111;
		static inline const size_t brick_slab = 112;
		static inline const size_t brick_stairs = 113;
		static inline const size_t brick_wall = 114;
		static inline const size_t brown_candle = 115;
		static inline const size_t brown_carpet = 116;
		static inline const size_t brown_concrete_powder = 117;
		static inline const size_t brown_dye = 118;
		static inline const size_t brown_glazed_terracotta = 119;
		static inline const size_t brown_mushroom = 120;
		static inline const size_t brown_stained_glass = 121;
		static inline const size_t brown_stained_glass_pane = 122;
		static inline const size_t brown_terracotta = 123;
		static inline const size_t brown_wool = 124;
		static inline const size_t brush = 125;
		static inline const size_t bubble_coral_block = 126;
		static inline const size_t bucket = 127;
		static inline const size_t bundle = 128;
		static inline const size_t cactus = 129;
		static inline const size_t cake = 130;
		static inline const size_t calibrated_sculk_sensor = 131;
		static inline const size_t campfire = 132;
		static inline const size_t candle = 133;
		static inline const size_t carpet = 134;
		static inline const size_t carrot = 135;
		static inline const size_t carrotonastick = 136;
		static inline const size_t cartography_table = 137;
		static inline const size_t carved_pumpkin = 138;
		static inline const size_t cauldron = 139;
		static inline const size_t chain = 140;
		static inline const size_t chainmail_boots = 141;
		static inline const size_t chainmail_chestplate = 142;
		static inline const size_t chainmail_helmet = 143;
		static inline const size_t chainmail_leggings = 144;
		static inline const size_t charcoal = 145;
		static inline const size_t cherry_boat = 146;
		static inline const size_t cherry_button = 147;
		static inline const size_t cherry_chest_boat = 148;
		static inline const size_t cherry_door = 149;
		static inline const size_t cherry_fence = 150;
		static inline const size_t cherry_fence_gate = 151;
		static inline const size_t cherry_hanging_sign = 152;
		static inline const size_t cherry_log = 153;
		static inline const size_t cherry_planks = 154;
		static inline const size_t cherry_pressure_plate = 155;
		static inline const size_t cherry_sapling = 156;
		static inline const size_t cherry_sign = 157;
		static inline const size_t cherry_slab = 158;
		static inline const size_t cherry_stairs = 159;
		static inline const size_t cherry_trapdoor = 160;
		static inline const size_t cherry_wood = 161;
		static inline const size_t chest = 162;
		static inline const size_t chest_boat = 163;
		static inline const size_t chest_minecart = 164;
		static inline const size_t chicken = 165;
		static inline const size_t chiseled_bookshelf = 166;
		static inline const size_t chiseled_copper = 167;
		static inline const size_t chiseled_deepslate = 168;
		static inline const size_t chiseled_nether_bricks = 169;
		static inline const size_t chiseled_polished_blackstone = 170;
		static inline const size_t chiseled_quartz_block = 171;
		static inline const size_t chiseled_red_sandstone = 172;
		static inline const size_t chiseled_resin_bricks = 173;
		static inline const size_t chiseled_sandstone = 174;
		static inline const size_t chiseled_stone_bricks = 175;
		static inline const size_t chiseled_tuff = 176;
		static inline const size_t chiseled_tuff_bricks = 177;
		static inline const size_t chorus_fruit = 178;
		static inline const size_t chorus_fruit_popped = 179;
		static inline const size_t clay = 180;
		static inline const size_t clay_ball = 181;
		static inline const size_t clock = 182;
		static inline const size_t closed_eyeblossom = 183;
		static inline const size_t clownfish = 184;
		static inline const size_t coal = 185;
		static inline const size_t coal_block = 186;
		static inline const size_t coal_ore = 187;
		static inline const size_t coals = 188;
		static inline const size_t coarse_dirt = 189;
		static inline const size_t coast_armor_trim_smithing_template = 190;
		static inline const size_t cobbled_deepslate = 191;
		static inline const size_t cobbled_deepslate_slab = 192;
		static inline const size_t cobbled_deepslate_stairs = 193;
		static inline const size_t cobbled_deepslate_wall = 194;
		static inline const size_t cobblestone = 195;
		static inline const size_t cobblestone_slab = 196;
		static inline const size_t cobblestone_wall = 197;
		static inline const size_t cocoa_beans = 198;
		static inline const size_t comparator = 199;
		static inline const size_t compass = 200;
		static inline const size_t composter = 201;
		static inline const size_t conduit = 202;
		static inline const size_t cooked_beef = 203;
		static inline const size_t cooked_chicken = 204;
		static inline const size_t cooked_fish = 205;
		static inline const size_t cooked_porkchop = 206;
		static inline const size_t cooked_rabbit = 207;
		static inline const size_t cooked_salmon = 208;
		static inline const size_t cookie = 209;
		static inline const size_t copper_block = 210;
		static inline const size_t copper_bulb = 211;
		static inline const size_t copper_door = 212;
		static inline const size_t copper_grate = 213;
		static inline const size_t copper_ingot = 214;
		static inline const size_t copper_ore = 215;
		static inline const size_t copper_trapdoor = 216;
		static inline const size_t cornflower = 217;
		static inline const size_t cracked_deepslate_bricks = 218;
		static inline const size_t cracked_deepslate_tiles = 219;
		static inline const size_t cracked_nether_bricks = 220;
		static inline const size_t cracked_polished_blackstone_bricks = 221;
		static inline const size_t cracked_stone_bricks = 222;
		static inline const size_t crafter = 223;
		static inline const size_t crafting_table = 224;
		static inline const size_t creaking_heart = 225;
		static inline const size_t crimson_button = 226;
		static inline const size_t crimson_door = 227;
		static inline const size_t crimson_fence = 228;
		static inline const size_t crimson_fence_gate = 229;
		static inline const size_t crimson_hanging_sign = 230;
		static inline const size_t crimson_hyphae = 231;
		static inline const size_t crimson_planks = 232;
		static inline const size_t crimson_pressure_plate = 233;
		static inline const size_t crimson_sign = 234;
		static inline const size_t crimson_slab = 235;
		static inline const size_t crimson_stairs = 236;
		static inline const size_t crimson_stem = 237;
		static inline const size_t crimson_trapdoor = 238;
		static inline const size_t crossbow = 239;
		static inline const size_t crying_obsidian = 240;
		static inline const size_t cut_copper = 241;
		static inline const size_t cut_copper_slab = 242;
		static inline const size_t cut_copper_stairs = 243;
		static inline const size_t cut_red_sandstone = 244;
		static inline const size_t cut_sandstone = 245;
		static inline const size_t cyan_candle = 246;
		static inline const size_t cyan_carpet = 247;
		static inline const size_t cyan_concrete_powder = 248;
		static inline const size_t cyan_dye = 249;
		static inline const size_t cyan_glazed_terracotta = 250;
		static inline const size_t cyan_stained_glass = 251;
		static inline const size_t cyan_stained_glass_pane = 252;
		static inline const size_t cyan_terracotta = 253;
		static inline const size_t cyan_wool = 254;
		static inline const size_t dandelion = 255;
		static inline const size_t dark_oak_boat = 256;
		static inline const size_t dark_oak_door = 257;
		static inline const size_t dark_oak_fence = 258;
		static inline const size_t dark_oak_fence_gate = 259;
		static inline const size_t dark_oak_hanging_sign = 260;
		static inline const size_t dark_oak_log = 261;
		static inline const size_t dark_oak_planks = 262;
		static inline const size_t dark_oak_sapling = 263;
		static inline const size_t dark_oak_slab = 264;
		static inline const size_t dark_oak_stairs = 265;
		static inline const size_t dark_oak_wood = 266;
		static inline const size_t dark_prismarine = 267;
		static inline const size_t dark_prismarine_slab = 268;
		static inline const size_t dark_prismarine_stairs = 269;
		static inline const size_t darkoak_sign = 270;
		static inline const size_t daylight_detector = 271;
		static inline const size_t deepslate = 272;
		static inline const size_t deepslate_brick_slab = 273;
		static inline const size_t deepslate_brick_stairs = 274;
		static inline const size_t deepslate_brick_wall = 275;
		static inline const size_t deepslate_bricks = 276;
		static inline const size_t deepslate_coal_ore = 277;
		static inline const size_t deepslate_copper_ore = 278;
		static inline const size_t deepslate_diamond_ore = 279;
		static inline const size_t deepslate_emerald_ore = 280;
		static inline const size_t deepslate_gold_ore = 281;
		static inline const size_t deepslate_iron_ore = 282;
		static inline const size_t deepslate_lapis_ore = 283;
		static inline const size_t deepslate_redstone_ore = 284;
		static inline const size_t deepslate_tile_slab = 285;
		static inline const size_t deepslate_tile_stairs = 286;
		static inline const size_t deepslate_tile_wall = 287;
		static inline const size_t deepslate_tiles = 288;
		static inline const size_t detector_rail = 289;
		static inline const size_t diamond = 290;
		static inline const size_t diamond_axe = 291;
		static inline const size_t diamond_block = 292;
		static inline const size_t diamond_boots = 293;
		static inline const size_t diamond_chestplate = 294;
		static inline const size_t diamond_helmet = 295;
		static inline const size_t diamond_hoe = 296;
		static inline const size_t diamond_leggings = 297;
		static inline const size_t diamond_ore = 298;
		static inline const size_t diamond_pickaxe = 299;
		static inline const size_t diamond_shovel = 300;
		static inline const size_t diamond_sword = 301;
		static inline const size_t diorite = 302;
		static inline const size_t diorite_slab = 303;
		static inline const size_t diorite_stairs = 304;
		static inline const size_t diorite_wall = 305;
		static inline const size_t dirt = 306;
		static inline const size_t dirt_with_roots = 307;
		static inline const size_t disc_fragment_5 = 308;
		static inline const size_t dispenser = 309;
		static inline const size_t dragon_breath = 310;
		static inline const size_t dried_kelp = 311;
		static inline const size_t dried_kelp_block = 312;
		static inline const size_t dripstone_block = 313;
		static inline const size_t dropper = 314;
		static inline const size_t dune_armor_trim_smithing_template = 315;
		static inline const size_t dye = 316;
		static inline const size_t echo_shard = 317;
		static inline const size_t egg = 318;
		static inline const size_t emerald = 319;
		static inline const size_t emerald_block = 320;
		static inline const size_t emerald_ore = 321;
		static inline const size_t emptymap = 322;
		static inline const size_t enchanting_table = 323;
		static inline const size_t end_brick_stairs = 324;
		static inline const size_t end_bricks = 325;
		static inline const size_t end_crystal = 326;
		static inline const size_t end_rod = 327;
		static inline const size_t end_stone = 328;
		static inline const size_t end_stone_brick_slab = 329;
		static inline const size_t end_stone_brick_wall = 330;
		static inline const size_t ender_chest = 331;
		static inline const size_t ender_eye = 332;
		static inline const size_t ender_pearl = 333;
		static inline const size_t experience_bottle = 334;
		static inline const size_t exposed_chiseled_copper = 335;
		static inline const size_t exposed_copper = 336;
		static inline const size_t exposed_copper_bulb = 337;
		static inline const size_t exposed_copper_door = 338;
		static inline const size_t exposed_copper_grate = 339;
		static inline const size_t exposed_copper_trapdoor = 340;
		static inline const size_t exposed_cut_copper = 341;
		static inline const size_t exposed_cut_copper_slab = 342;
		static inline const size_t exposed_cut_copper_stairs = 343;
		static inline const size_t eye_armor_trim_smithing_template = 344;
		static inline const size_t feather = 345;
		static inline const size_t fence_gate = 346;
		static inline const size_t fermented_spider_eye = 347;
		static inline const size_t fern = 348;
		static inline const size_t fire_charge = 349;
		static inline const size_t fire_coral_block = 350;
		static inline const size_t fish = 351;
		static inline const size_t fishing_rod = 352;
		static inline const size_t fletching_table = 353;
		static inline const size_t flint = 354;
		static inline const size_t flint_and_steel = 355;
		static inline const size_t flow_armor_trim_smithing_template = 356;
		static inline const size_t flower_pot = 357;
		static inline const size_t frame = 358;
		static inline const size_t furnace = 359;
		static inline const size_t ghast_tear = 360;
		static inline const size_t glass = 361;
		static inline const size_t glass_bottle = 362;
		static inline const size_t glass_pane = 363;
		static inline const size_t glow_frame = 364;
		static inline const size_t glow_ink_sac = 365;
		static inline const size_t glowstone = 366;
		static inline const size_t glowstone_dust = 367;
		static inline const size_t gold_block = 368;
		static inline const size_t gold_ingot = 369;
		static inline const size_t gold_nugget = 370;
		static inline const size_t gold_ore = 371;
		static inline const size_t golden_apple = 372;
		static inline const size_t golden_axe = 373;
		static inline const size_t golden_boots = 374;
		static inline const size_t golden_carrot = 375;
		static inline const size_t golden_chestplate = 376;
		static inline const size_t golden_helmet = 377;
		static inline const size_t golden_hoe = 378;
		static inline const size_t golden_leggings = 379;
		static inline const size_t golden_pickaxe = 380;
		static inline const size_t golden_rail = 381;
		static inline const size_t golden_shovel = 382;
		static inline const size_t golden_sword = 383;
		static inline const size_t granite = 384;
		static inline const size_t granite_slab = 385;
		static inline const size_t granite_stairs = 386;
		static inline const size_t granite_wall = 387;
		static inline const size_t gravel = 388;
		static inline const size_t gray_candle = 389;
		static inline const size_t gray_carpet = 390;
		static inline const size_t gray_concrete_powder = 391;
		static inline const size_t gray_dye = 392;
		static inline const size_t gray_glazed_terracotta = 393;
		static inline const size_t gray_stained_glass = 394;
		static inline const size_t gray_stained_glass_pane = 395;
		static inline const size_t gray_terracotta = 396;
		static inline const size_t gray_wool = 397;
		static inline const size_t green_candle = 398;
		static inline const size_t green_carpet = 399;
		static inline const size_t green_concrete_powder = 400;
		static inline const size_t green_dye = 401;
		static inline const size_t green_glazed_terracotta = 402;
		static inline const size_t green_stained_glass = 403;
		static inline const size_t green_stained_glass_pane = 404;
		static inline const size_t green_terracotta = 405;
		static inline const size_t green_wool = 406;
		static inline const size_t grindstone = 407;
		static inline const size_t gunpowder = 408;
		static inline const size_t hardened_clay = 409;
		static inline const size_t hay_block = 410;
		static inline const size_t heart_of_the_sea = 411;
		static inline const size_t heavy_core = 412;
		static inline const size_t heavy_weighted_pressure_plate = 413;
		static inline const size_t honey_block = 414;
		static inline const size_t honey_bottle = 415;
		static inline const size_t honeycomb = 416;
		static inline const size_t honeycomb_block = 417;
		static inline const size_t hopper = 418;
		static inline const size_t hopper_minecart = 419;
		static inline const size_t horn_coral_block = 420;
		static inline const size_t horsearmorgold = 421;
		static inline const size_t horsearmoriron = 422;
		static inline const size_t horsearmorleather = 423;
		static inline const size_t host_armor_trim_smithing_template = 424;
		static inline const size_t ice = 425;
		static inline const size_t ink_sac = 426;
		static inline const size_t iron_axe = 427;
		static inline const size_t iron_bars = 428;
		static inline const size_t iron_block = 429;
		static inline const size_t iron_boots = 430;
		static inline const size_t iron_chestplate = 431;
		static inline const size_t iron_door = 432;
		static inline const size_t iron_helmet = 433;
		static inline const size_t iron_hoe = 434;
		static inline const size_t iron_ingot = 435;
		static inline const size_t iron_leggings = 436;
		static inline const size_t iron_nugget = 437;
		static inline const size_t iron_ore = 438;
		static inline const size_t iron_pickaxe = 439;
		static inline const size_t iron_shovel = 440;
		static inline const size_t iron_sword = 441;
		static inline const size_t iron_trapdoor = 442;
		static inline const size_t jukebox = 443;
		static inline const size_t jungle_boat = 444;
		static inline const size_t jungle_door = 445;
		static inline const size_t jungle_fence = 446;
		static inline const size_t jungle_fence_gate = 447;
		static inline const size_t jungle_hanging_sign = 448;
		static inline const size_t jungle_log = 449;
		static inline const size_t jungle_planks = 450;
		static inline const size_t jungle_sapling = 451;
		static inline const size_t jungle_sign = 452;
		static inline const size_t jungle_slab = 453;
		static inline const size_t jungle_stairs = 454;
		static inline const size_t jungle_wood = 455;
		static inline const size_t kelp = 456;
		static inline const size_t ladder = 457;
		static inline const size_t lantern = 458;
		static inline const size_t lapis_block = 459;
		static inline const size_t lapis_lazuli = 460;
		static inline const size_t lapis_ore = 461;
		static inline const size_t lead = 462;
		static inline const size_t leather = 463;
		static inline const size_t leather_boots = 464;
		static inline const size_t leather_chestplate = 465;
		static inline const size_t leather_helmet = 466;
		static inline const size_t leather_leggings = 467;
		static inline const size_t lectern = 468;
		static inline const size_t lever = 469;
		static inline const size_t light_blue_candle = 470;
		static inline const size_t light_blue_carpet = 471;
		static inline const size_t light_blue_concrete_powder = 472;
		static inline const size_t light_blue_dye = 473;
		static inline const size_t light_blue_glazed_terracotta = 474;
		static inline const size_t light_blue_stained_glass = 475;
		static inline const size_t light_blue_stained_glass_pane = 476;
		static inline const size_t light_blue_terracotta = 477;
		static inline const size_t light_blue_wool = 478;
		static inline const size_t light_gray_candle = 479;
		static inline const size_t light_gray_carpet = 480;
		static inline const size_t light_gray_concrete_powder = 481;
		static inline const size_t light_gray_dye = 482;
		static inline const size_t light_gray_stained_glass = 483;
		static inline const size_t light_gray_stained_glass_pane = 484;
		static inline const size_t light_gray_terracotta = 485;
		static inline const size_t light_gray_wool = 486;
		static inline const size_t light_weighted_pressure_plate = 487;
		static inline const size_t lightning_rod = 488;
		static inline const size_t lilac = 489;
		static inline const size_t lily_of_the_valley = 490;
		static inline const size_t lime_candle = 491;
		static inline const size_t lime_carpet = 492;
		static inline const size_t lime_concrete_powder = 493;
		static inline const size_t lime_dye = 494;
		static inline const size_t lime_glazed_terracotta = 495;
		static inline const size_t lime_stained_glass = 496;
		static inline const size_t lime_stained_glass_pane = 497;
		static inline const size_t lime_terracotta = 498;
		static inline const size_t lime_wool = 499;
		static inline const size_t lingering_potion = 500;
		static inline const size_t lit_pumpkin = 501;
		static inline const size_t lodestone = 502;
		static inline const size_t lodestone_compass = 503;
		static inline const size_t log = 504;
		static inline const size_t log2 = 505;
		static inline const size_t logs = 506;
		static inline const size_t logs_that_burn = 507;
		static inline const size_t loom = 508;
		static inline const size_t mace = 509;
		static inline const size_t magenta_candle = 510;
		static inline const size_t magenta_carpet = 511;
		static inline const size_t magenta_concrete_powder = 512;
		static inline const size_t magenta_dye = 513;
		static inline const size_t magenta_glazed_terracotta = 514;
		static inline const size_t magenta_stained_glass = 515;
		static inline const size_t magenta_stained_glass_pane = 516;
		static inline const size_t magenta_terracotta = 517;
		static inline const size_t magenta_wool = 518;
		static inline const size_t magma = 519;
		static inline const size_t magma_cream = 520;
		static inline const size_t mangrove_boat = 521;
		static inline const size_t mangrove_button = 522;
		static inline const size_t mangrove_door = 523;
		static inline const size_t mangrove_fence = 524;
		static inline const size_t mangrove_fence_gate = 525;
		static inline const size_t mangrove_hanging_sign = 526;
		static inline const size_t mangrove_log = 527;
		static inline const size_t mangrove_planks = 528;
		static inline const size_t mangrove_pressure_plate = 529;
		static inline const size_t mangrove_propagule = 530;
		static inline const size_t mangrove_roots = 531;
		static inline const size_t mangrove_sign = 532;
		static inline const size_t mangrove_slab = 533;
		static inline const size_t mangrove_stairs = 534;
		static inline const size_t mangrove_trapdoor = 535;
		static inline const size_t mangrove_wood = 536;
		static inline const size_t map = 537;
		static inline const size_t melon = 538;
		static inline const size_t melon_block = 539;
		static inline const size_t melon_seeds = 540;
		static inline const size_t minecart = 541;
		static inline const size_t moss_block = 542;
		static inline const size_t moss_carpet = 543;
		static inline const size_t mossy_cobblestone = 544;
		static inline const size_t mossy_cobblestone_slab = 545;
		static inline const size_t mossy_cobblestone_stairs = 546;
		static inline const size_t mossy_cobblestone_wall = 547;
		static inline const size_t mossy_stone_brick_slab = 548;
		static inline const size_t mossy_stone_brick_stairs = 549;
		static inline const size_t mossy_stone_brick_wall = 550;
		static inline const size_t mossy_stone_bricks = 551;
		static inline const size_t mud = 552;
		static inline const size_t mud_brick_slab = 553;
		static inline const size_t mud_brick_stairs = 554;
		static inline const size_t mud_brick_wall = 555;
		static inline const size_t mud_bricks = 556;
		static inline const size_t muddy_mangrove_roots = 557;
		static inline const size_t mushroom_stew = 558;
		static inline const size_t muttonCooked = 559;
		static inline const size_t muttonRaw = 560;
		static inline const size_t muttonraw = 561;
		static inline const size_t nametag = 562;
		static inline const size_t nautilus_shell = 563;
		static inline const size_t nether_brick = 564;
		static inline const size_t nether_brick_fence = 565;
		static inline const size_t nether_brick_slab = 566;
		static inline const size_t nether_brick_stairs = 567;
		static inline const size_t nether_brick_wall = 568;
		static inline const size_t nether_gold_ore = 569;
		static inline const size_t nether_wart = 570;
		static inline const size_t nether_wart_block = 571;
		static inline const size_t netherbrick = 572;
		static inline const size_t netherite_axe = 573;
		static inline const size_t netherite_block = 574;
		static inline const size_t netherite_boots = 575;
		static inline const size_t netherite_chestplate = 576;
		static inline const size_t netherite_helmet = 577;
		static inline const size_t netherite_hoe = 578;
		static inline const size_t netherite_ingot = 579;
		static inline const size_t netherite_leggings = 580;
		static inline const size_t netherite_pickaxe = 581;
		static inline const size_t netherite_scrap = 582;
		static inline const size_t netherite_shovel = 583;
		static inline const size_t netherite_sword = 584;
		static inline const size_t netherite_upgrade_smithing_template = 585;
		static inline const size_t netherrack = 586;
		static inline const size_t netherstar = 587;
		static inline const size_t normal_stone_slab = 588;
		static inline const size_t normal_stone_stairs = 589;
		static inline const size_t noteblock = 590;
		static inline const size_t oak_boat = 591;
		static inline const size_t oak_fence = 592;
		static inline const size_t oak_hanging_sign = 593;
		static inline const size_t oak_log = 594;
		static inline const size_t oak_planks = 595;
		static inline const size_t oak_sapling = 596;
		static inline const size_t oak_slab = 597;
		static inline const size_t oak_stairs = 598;
		static inline const size_t oak_wood = 599;
		static inline const size_t observer = 600;
		static inline const size_t obsidian = 601;
		static inline const size_t open_eyeblossom = 602;
		static inline const size_t orange_candle = 603;
		static inline const size_t orange_carpet = 604;
		static inline const size_t orange_concrete_powder = 605;
		static inline const size_t orange_dye = 606;
		static inline const size_t orange_glazed_terracotta = 607;
		static inline const size_t orange_stained_glass = 608;
		static inline const size_t orange_stained_glass_pane = 609;
		static inline const size_t orange_terracotta = 610;
		static inline const size_t orange_tulip = 611;
		static inline const size_t orange_wool = 612;
		static inline const size_t oxeye_daisy = 613;
		static inline const size_t oxidized_chiseled_copper = 614;
		static inline const size_t oxidized_copper = 615;
		static inline const size_t oxidized_copper_bulb = 616;
		static inline const size_t oxidized_copper_door = 617;
		static inline const size_t oxidized_copper_grate = 618;
		static inline const size_t oxidized_copper_trapdoor = 619;
		static inline const size_t oxidized_cut_copper = 620;
		static inline const size_t oxidized_cut_copper_slab = 621;
		static inline const size_t oxidized_cut_copper_stairs = 622;
		static inline const size_t packed_ice = 623;
		static inline const size_t packed_mud = 624;
		static inline const size_t painting = 625;
		static inline const size_t pale_hanging_moss = 626;
		static inline const size_t pale_moss_block = 627;
		static inline const size_t pale_moss_carpet = 628;
		static inline const size_t pale_oak_boat = 629;
		static inline const size_t pale_oak_button = 630;
		static inline const size_t pale_oak_chest_boat = 631;
		static inline const size_t pale_oak_door = 632;
		static inline const size_t pale_oak_fence = 633;
		static inline const size_t pale_oak_fence_gate = 634;
		static inline const size_t pale_oak_hanging_sign = 635;
		static inline const size_t pale_oak_log = 636;
		static inline const size_t pale_oak_planks = 637;
		static inline const size_t pale_oak_pressure_plate = 638;
		static inline const size_t pale_oak_sapling = 639;
		static inline const size_t pale_oak_sign = 640;
		static inline const size_t pale_oak_slab = 641;
		static inline const size_t pale_oak_stairs = 642;
		static inline const size_t pale_oak_trapdoor = 643;
		static inline const size_t pale_oak_wood = 644;
		static inline const size_t paper = 645;
		static inline const size_t peony = 646;
		static inline const size_t phantom_membrane = 647;
		static inline const size_t pink_candle = 648;
		static inline const size_t pink_carpet = 649;
		static inline const size_t pink_concrete_powder = 650;
		static inline const size_t pink_dye = 651;
		static inline const size_t pink_glazed_terracotta = 652;
		static inline const size_t pink_petals = 653;
		static inline const size_t pink_stained_glass = 654;
		static inline const size_t pink_stained_glass_pane = 655;
		static inline const size_t pink_terracotta = 656;
		static inline const size_t pink_tulip = 657;
		static inline const size_t pink_wool = 658;
		static inline const size_t piston = 659;
		static inline const size_t pitcher_plant = 660;
		static inline const size_t planks = 661;
		static inline const size_t podzol = 662;
		static inline const size_t pointed_dripstone = 663;
		static inline const size_t polished_andesite = 664;
		static inline const size_t polished_andesite_slab = 665;
		static inline const size_t polished_andesite_stairs = 666;
		static inline const size_t polished_basalt = 667;
		static inline const size_t polished_blackstone = 668;
		static inline const size_t polished_blackstone_brick_slab = 669;
		static inline const size_t polished_blackstone_brick_stairs = 670;
		static inline const size_t polished_blackstone_brick_wall = 671;
		static inline const size_t polished_blackstone_bricks = 672;
		static inline const size_t polished_blackstone_button = 673;
		static inline const size_t polished_blackstone_pressure_plate = 674;
		static inline const size_t polished_blackstone_slab = 675;
		static inline const size_t polished_blackstone_stairs = 676;
		static inline const size_t polished_blackstone_wall = 677;
		static inline const size_t polished_deepslate = 678;
		static inline const size_t polished_deepslate_slab = 679;
		static inline const size_t polished_deepslate_stairs = 680;
		static inline const size_t polished_deepslate_wall = 681;
		static inline const size_t polished_diorite = 682;
		static inline const size_t polished_diorite_slab = 683;
		static inline const size_t polished_diorite_stairs = 684;
		static inline const size_t polished_granite = 685;
		static inline const size_t polished_granite_slab = 686;
		static inline const size_t polished_granite_stairs = 687;
		static inline const size_t polished_tuff = 688;
		static inline const size_t polished_tuff_slab = 689;
		static inline const size_t polished_tuff_stairs = 690;
		static inline const size_t polished_tuff_wall = 691;
		static inline const size_t poppy = 692;
		static inline const size_t porkchop = 693;
		static inline const size_t potato = 694;
		static inline const size_t potion = 695;
		static inline const size_t potion_type = 696;
		static inline const size_t prismarine = 697;
		static inline const size_t prismarine_brick_slab = 698;
		static inline const size_t prismarine_bricks = 699;
		static inline const size_t prismarine_bricks_stairs = 700;
		static inline const size_t prismarine_crystals = 701;
		static inline const size_t prismarine_shard = 702;
		static inline const size_t prismarine_slab = 703;
		static inline const size_t prismarine_stairs = 704;
		static inline const size_t prismarine_wall = 705;
		static inline const size_t pufferfish = 706;
		static inline const size_t pumpkin = 707;
		static inline const size_t pumpkin_pie = 708;
		static inline const size_t pumpkin_seeds = 709;
		static inline const size_t purple_candle = 710;
		static inline const size_t purple_carpet = 711;
		static inline const size_t purple_concrete_powder = 712;
		static inline const size_t purple_dye = 713;
		static inline const size_t purple_glazed_terracotta = 714;
		static inline const size_t purple_stained_glass = 715;
		static inline const size_t purple_stained_glass_pane = 716;
		static inline const size_t purple_terracotta = 717;
		static inline const size_t purple_wool = 718;
		static inline const size_t purpur_block = 719;
		static inline const size_t purpur_pillar = 720;
		static inline const size_t purpur_slab = 721;
		static inline const size_t purpur_stairs = 722;
		static inline const size_t quartz = 723;
		static inline const size_t quartz_block = 724;
		static inline const size_t quartz_bricks = 725;
		static inline const size_t quartz_ore = 726;
		static inline const size_t quartz_pillar = 727;
		static inline const size_t quartz_slab = 728;
		static inline const size_t quartz_stairs = 729;
		static inline const size_t rabbit = 730;
		static inline const size_t rabbit_foot = 731;
		static inline const size_t rabbit_hide = 732;
		static inline const size_t rabbit_stew = 733;
		static inline const size_t rail = 734;
		static inline const size_t raiser_armor_trim_smithing_template = 735;
		static inline const size_t raw_copper = 736;
		static inline const size_t raw_copper_block = 737;
		static inline const size_t raw_gold = 738;
		static inline const size_t raw_gold_block = 739;
		static inline const size_t raw_iron = 740;
		static inline const size_t raw_iron_block = 741;
		static inline const size_t record_5 = 742;
		static inline const size_t recovery_compass = 743;
		static inline const size_t red_candle = 744;
		static inline const size_t red_carpet = 745;
		static inline const size_t red_concrete_powder = 746;
		static inline const size_t red_dye = 747;
		static inline const size_t red_glazed_terracotta = 748;
		static inline const size_t red_mushroom = 749;
		static inline const size_t red_nether_brick = 750;
		static inline const size_t red_nether_brick_slab = 751;
		static inline const size_t red_nether_brick_stairs = 752;
		static inline const size_t red_nether_brick_wall = 753;
		static inline const size_t red_sand = 754;
		static inline const size_t red_sandstone = 755;
		static inline const size_t red_sandstone_slab = 756;
		static inline const size_t red_sandstone_stairs = 757;
		static inline const size_t red_sandstone_wall = 758;
		static inline const size_t red_stained_glass = 759;
		static inline const size_t red_stained_glass_pane = 760;
		static inline const size_t red_terracotta = 761;
		static inline const size_t red_tulip = 762;
		static inline const size_t red_wool = 763;
		static inline const size_t redstone = 764;
		static inline const size_t redstone_block = 765;
		static inline const size_t redstone_lamp = 766;
		static inline const size_t redstone_ore = 767;
		static inline const size_t redstone_torch = 768;
		static inline const size_t reeds = 769;
		static inline const size_t repeater = 770;
		static inline const size_t resin_block = 771;
		static inline const size_t resin_brick = 772;
		static inline const size_t resin_brick_slab = 773;
		static inline const size_t resin_brick_stairs = 774;
		static inline const size_t resin_brick_wall = 775;
		static inline const size_t resin_bricks = 776;
		static inline const size_t resin_clump = 777;
		static inline const size_t respawn_anchor = 778;
		static inline const size_t rib_armor_trim_smithing_template = 779;
		static inline const size_t rose_bush = 780;
		static inline const size_t rotten_flesh = 781;
		static inline const size_t saddle = 782;
		static inline const size_t salmon = 783;
		static inline const size_t sand = 784;
		static inline const size_t sandstone = 785;
		static inline const size_t sandstone_slab = 786;
		static inline const size_t sandstone_stairs = 787;
		static inline const size_t sandstone_wall = 788;
		static inline const size_t scaffolding = 789;
		static inline const size_t sculk_sensor = 790;
		static inline const size_t sea_pickle = 791;
		static inline const size_t sealantern = 792;
		static inline const size_t sentry_armor_trim_smithing_template = 793;
		static inline const size_t shaper_armor_trim_smithing_template = 794;
		static inline const size_t shears = 795;
		static inline const size_t shield = 796;
		static inline const size_t shulker_shell = 797;
		static inline const size_t sign = 798;
		static inline const size_t silence_armor_trim_smithing_template = 799;
		static inline const size_t silver_glazed_terracotta = 800;
		static inline const size_t skull = 801;
		static inline const size_t slime = 802;
		static inline const size_t slime_ball = 803;
		static inline const size_t small_dripleaf_block = 804;
		static inline const size_t smithing_table = 805;
		static inline const size_t smoker = 806;
		static inline const size_t smooth_basalt = 807;
		static inline const size_t smooth_quartz = 808;
		static inline const size_t smooth_quartz_slab = 809;
		static inline const size_t smooth_quartz_stairs = 810;
		static inline const size_t smooth_red_sandstone = 811;
		static inline const size_t smooth_red_sandstone_slab = 812;
		static inline const size_t smooth_red_sandstone_stairs = 813;
		static inline const size_t smooth_sandstone = 814;
		static inline const size_t smooth_sandstone_slab = 815;
		static inline const size_t smooth_sandstone_stairs = 816;
		static inline const size_t smooth_stone = 817;
		static inline const size_t smooth_stone_slab = 818;
		static inline const size_t snout_armor_trim_smithing_template = 819;
		static inline const size_t snow = 820;
		static inline const size_t snow_layer = 821;
		static inline const size_t snowball = 822;
		static inline const size_t soul_campfire = 823;
		static inline const size_t soul_fire_base_blocks = 824;
		static inline const size_t soul_lantern = 825;
		static inline const size_t soul_sand = 826;
		static inline const size_t soul_soil = 827;
		static inline const size_t soul_torch = 828;
		static inline const size_t speckled_melon = 829;
		static inline const size_t spider_eye = 830;
		static inline const size_t spire_armor_trim_smithing_template = 831;
		static inline const size_t splash_potion = 832;
		static inline const size_t sponge = 833;
		static inline const size_t spruce_boat = 834;
		static inline const size_t spruce_door = 835;
		static inline const size_t spruce_fence = 836;
		static inline const size_t spruce_fence_gate = 837;
		static inline const size_t spruce_hanging_sign = 838;
		static inline const size_t spruce_log = 839;
		static inline const size_t spruce_planks = 840;
		static inline const size_t spruce_sapling = 841;
		static inline const size_t spruce_sign = 842;
		static inline const size_t spruce_slab = 843;
		static inline const size_t spruce_stairs = 844;
		static inline const size_t spruce_wood = 845;
		static inline const size_t spyglass = 846;
		static inline const size_t stick = 847;
		static inline const size_t sticky_piston = 848;
		static inline const size_t stone = 849;
		static inline const size_t stone_axe = 850;
		static inline const size_t stone_brick_slab = 851;
		static inline const size_t stone_brick_stairs = 852;
		static inline const size_t stone_brick_wall = 853;
		static inline const size_t stone_bricks = 854;
		static inline const size_t stone_button = 855;
		static inline const size_t stone_crafting_materials = 856;
		static inline const size_t stone_hoe = 857;
		static inline const size_t stone_pickaxe = 858;
		static inline const size_t stone_pressure_plate = 859;
		static inline const size_t stone_shovel = 860;
		static inline const size_t stone_stairs = 861;
		static inline const size_t stone_sword = 862;
		static inline const size_t stone_tool_materials = 863;
		static inline const size_t stonecutter_block = 864;
		static inline const size_t string = 865;
		static inline const size_t stripped_acacia_log = 866;
		static inline const size_t stripped_acacia_wood = 867;
		static inline const size_t stripped_bamboo_block = 868;
		static inline const size_t stripped_birch_log = 869;
		static inline const size_t stripped_birch_wood = 870;
		static inline const size_t stripped_cherry_log = 871;
		static inline const size_t stripped_cherry_wood = 872;
		static inline const size_t stripped_crimson_hyphae = 873;
		static inline const size_t stripped_crimson_stem = 874;
		static inline const size_t stripped_dark_oak_log = 875;
		static inline const size_t stripped_dark_oak_wood = 876;
		static inline const size_t stripped_jungle_log = 877;
		static inline const size_t stripped_jungle_wood = 878;
		static inline const size_t stripped_mangrove_log = 879;
		static inline const size_t stripped_mangrove_wood = 880;
		static inline const size_t stripped_oak_log = 881;
		static inline const size_t stripped_oak_wood = 882;
		static inline const size_t stripped_pale_oak_log = 883;
		static inline const size_t stripped_pale_oak_wood = 884;
		static inline const size_t stripped_spruce_log = 885;
		static inline const size_t stripped_spruce_wood = 886;
		static inline const size_t stripped_warped_hyphae = 887;
		static inline const size_t stripped_warped_stem = 888;
		static inline const size_t sugar = 889;
		static inline const size_t sunflower = 890;
		static inline const size_t suspicious_stew = 891;
		static inline const size_t sweet_berries = 892;
		static inline const size_t target = 893;
		static inline const size_t tide_armor_trim_smithing_template = 894;
		static inline const size_t tinted_glass = 895;
		static inline const size_t tnt = 896;
		static inline const size_t tnt_minecart = 897;
		static inline const size_t torch = 898;
		static inline const size_t torchflower = 899;
		static inline const size_t trapped_chest = 900;
		static inline const size_t trim_materials = 901;
		static inline const size_t trim_templates = 902;
		static inline const size_t trimmable_armors = 903;
		static inline const size_t tripwire_hook = 904;
		static inline const size_t tube_coral_block = 905;
		static inline const size_t tuff = 906;
		static inline const size_t tuff_brick_slab = 907;
		static inline const size_t tuff_brick_stairs = 908;
		static inline const size_t tuff_brick_wall = 909;
		static inline const size_t tuff_bricks = 910;
		static inline const size_t tuff_slab = 911;
		static inline const size_t tuff_stairs = 912;
		static inline const size_t tuff_wall = 913;
		static inline const size_t turtle_helmet = 914;
		static inline const size_t turtle_shell_piece = 915;
		static inline const size_t undyed_shulker_box = 916;
		static inline const size_t vex_armor_trim_smithing_template = 917;
		static inline const size_t vine = 918;
		static inline const size_t ward_armor_trim_smithing_template = 919;
		static inline const size_t warped_button = 920;
		static inline const size_t warped_door = 921;
		static inline const size_t warped_fence = 922;
		static inline const size_t warped_fence_gate = 923;
		static inline const size_t warped_fungus = 924;
		static inline const size_t warped_fungus_on_a_stick = 925;
		static inline const size_t warped_hanging_sign = 926;
		static inline const size_t warped_hyphae = 927;
		static inline const size_t warped_planks = 928;
		static inline const size_t warped_pressure_plate = 929;
		static inline const size_t warped_sign = 930;
		static inline const size_t warped_slab = 931;
		static inline const size_t warped_stairs = 932;
		static inline const size_t warped_stem = 933;
		static inline const size_t warped_trapdoor = 934;
		static inline const size_t waterlily = 935;
		static inline const size_t waxed_chiseled_copper = 936;
		static inline const size_t waxed_copper = 937;
		static inline const size_t waxed_copper_bulb = 938;
		static inline const size_t waxed_copper_door = 939;
		static inline const size_t waxed_copper_grate = 940;
		static inline const size_t waxed_copper_trapdoor = 941;
		static inline const size_t waxed_cut_copper = 942;
		static inline const size_t waxed_cut_copper_slab = 943;
		static inline const size_t waxed_cut_copper_stairs = 944;
		static inline const size_t waxed_exposed_chiseled_copper = 945;
		static inline const size_t waxed_exposed_copper = 946;
		static inline const size_t waxed_exposed_copper_bulb = 947;
		static inline const size_t waxed_exposed_copper_door = 948;
		static inline const size_t waxed_exposed_copper_grate = 949;
		static inline const size_t waxed_exposed_copper_trapdoor = 950;
		static inline const size_t waxed_exposed_cut_copper = 951;
		static inline const size_t waxed_exposed_cut_copper_slab = 952;
		static inline const size_t waxed_exposed_cut_copper_stairs = 953;
		static inline const size_t waxed_oxidized_chiseled_copper = 954;
		static inline const size_t waxed_oxidized_copper = 955;
		static inline const size_t waxed_oxidized_copper_bulb = 956;
		static inline const size_t waxed_oxidized_copper_door = 957;
		static inline const size_t waxed_oxidized_copper_grate = 958;
		static inline const size_t waxed_oxidized_copper_trapdoor = 959;
		static inline const size_t waxed_oxidized_cut_copper = 960;
		static inline const size_t waxed_oxidized_cut_copper_slab = 961;
		static inline const size_t waxed_oxidized_cut_copper_stairs = 962;
		static inline const size_t waxed_weathered_chiseled_copper = 963;
		static inline const size_t waxed_weathered_copper = 964;
		static inline const size_t waxed_weathered_copper_bulb = 965;
		static inline const size_t waxed_weathered_copper_door = 966;
		static inline const size_t waxed_weathered_copper_grate = 967;
		static inline const size_t waxed_weathered_copper_trapdoor = 968;
		static inline const size_t waxed_weathered_cut_copper = 969;
		static inline const size_t waxed_weathered_cut_copper_slab = 970;
		static inline const size_t waxed_weathered_cut_copper_stairs = 971;
		static inline const size_t wayfinder_armor_trim_smithing_template = 972;
		static inline const size_t weathered_chiseled_copper = 973;
		static inline const size_t weathered_copper = 974;
		static inline const size_t weathered_copper_bulb = 975;
		static inline const size_t weathered_copper_door = 976;
		static inline const size_t weathered_copper_grate = 977;
		static inline const size_t weathered_copper_trapdoor = 978;
		static inline const size_t weathered_cut_copper = 979;
		static inline const size_t weathered_cut_copper_slab = 980;
		static inline const size_t weathered_cut_copper_stairs = 981;
		static inline const size_t web = 982;
		static inline const size_t wet_sponge = 983;
		static inline const size_t wheat = 984;
		static inline const size_t wheat_seeds = 985;
		static inline const size_t white_candle = 986;
		static inline const size_t white_carpet = 987;
		static inline const size_t white_concrete_powder = 988;
		static inline const size_t white_dye = 989;
		static inline const size_t white_glazed_terracotta = 990;
		static inline const size_t white_stained_glass = 991;
		static inline const size_t white_stained_glass_pane = 992;
		static inline const size_t white_terracotta = 993;
		static inline const size_t white_tulip = 994;
		static inline const size_t white_wool = 995;
		static inline const size_t wild_armor_trim_smithing_template = 996;
		static inline const size_t wind_charge = 997;
		static inline const size_t wither_rose = 998;
		static inline const size_t wolf_armor = 999;
		static inline const size_t wood = 1000;
		static inline const size_t wooden_axe = 1001;
		static inline const size_t wooden_door = 1002;
		static inline const size_t wooden_hoe = 1003;
		static inline const size_t wooden_pickaxe = 1004;
		static inline const size_t wooden_shovel = 1005;
		static inline const size_t wooden_slabs = 1006;
		static inline const size_t wooden_sword = 1007;
		static inline const size_t wool = 1008;
		static inline const size_t writable_book = 1009;
		static inline const size_t yellow_candle = 1010;
		static inline const size_t yellow_carpet = 1011;
		static inline const size_t yellow_concrete_powder = 1012;
		static inline const size_t yellow_dye = 1013;
		static inline const size_t yellow_glazed_terracotta = 1014;
		static inline const size_t yellow_stained_glass = 1015;
		static inline const size_t yellow_stained_glass_pane = 1016;
		static inline const size_t yellow_terracotta = 1017;
		static inline const size_t yellow_wool = 1018;
	} // namespace minecraft

	static inline const size_t trades = 2785;
	static const size_t trade[trades] = {
		2510, 10, 15, 0, 3, 4,  6, 14, 17, 1633, 13,  1270, 2124, 21, 400, 1860,  2193, 868, 24, 25, 1463,  1906,
		1907, 1908, 1976, 1977, 1979, 2646, 997, 64, 2363, 2524, 2526, 2528, 2530, 2532, 2534, 2536, 2538,  2540,
		2542, 2544, 2546, 2548, 2550,  2552, 1205, 2128, 1531, 1536,  33, 1612, 47, 45, 46,  34, 37, 38, 40,  49,
		50, 51, 53, 54, 55, 44, 953,  1465, 1981, 869, 2452, 99, 1567, 2482,  111, 116, 101, 104, 105, 107,  115,
		118, 1635, 114, 126, 128, 136, 141,  143, 725, 2589, 140, 963, 119,  125, 2587, 147, 148, 149, 356,  898,
		1466, 1716, 1870, 1879,  1885, 1892, 1899, 1909,  1910, 1911, 1921, 1982,  1983, 1984, 1985, 1991,  1997,
		1998, 2007, 210, 320, 829, 841, 844,  847, 1286, 153, 354, 357, 358,  591, 602, 613, 621, 630, 638,  646,
		654, 825, 161, 163,  172, 177, 179, 2634,  1182, 2132, 176, 959,  154, 160, 1, 35,  102, 534, 708,  1130,
		1290, 1843, 184, 187, 192, 191, 2341, 2348, 2355, 195, 197, 199, 201, 816, 2405, 2568, 2570, 2572,  2576,
		2581, 1160, 1162, 1164, 1166, 800, 100, 1334, 1532, 1537, 2125, 2129, 2133, 2136, 2140, 2144, 2148, 2152,
		2156, 2160, 2164, 2168, 2172, 2176, 2180, 2184, 212, 324, 862, 1257, 2362, 360, 865, 56, 361, 362,  1912,
		1914, 1916, 370, 372, 379,  384, 386, 2633, 838,  1335, 1533, 2126, 2130,  2134, 2137, 2141, 2145,  2149,
		2153, 2157, 2161, 2165,  2169, 2173, 2177,  2181, 2185, 383, 960,  363, 369, 2586,  396, 2436, 871,  121,
		123, 156, 158, 365, 367,  689, 1024, 1046, 1172,  1196, 1226, 1261, 1375,  1427, 1507, 1559, 2333,  2335,
		2357, 2410, 1192, 1222, 494, 1002, 1534, 1538, 2483,  1243, 8, 42, 109, 519, 669, 715, 1137, 1297,  1360,
		1409, 1850, 2241, 872, 873, 874, 875,  405, 408, 411, 414, 417, 420,  423, 426, 429, 432, 435, 438,  441,
		845, 2201, 512, 521, 532, 510, 511,  514, 515, 517, 525, 526, 528, 529,  531, 524, 2, 36, 103, 513,  535,
		539, 709, 1089, 1131, 1291, 1402,  1631, 1844, 2205, 876, 2445, 2255,  1577, 1609, 1247, 877, 826,  1524,
		878, 550, 879, 2640, 1034, 2138, 2505, 444, 447, 450,  453, 456, 459, 462, 465, 468, 471, 474, 477,  480,
		483, 486, 489, 554, 848, 1831, 1834, 2203, 2427, 2449, 2495, 2686, 2776, 553, 880, 402, 842, 1828,  2199,
		557, 359, 544, 560,  561, 562, 563, 564,  565, 742, 746, 750,  754, 756, 758, 763,  768, 773, 899,  1476,
		1477, 1479, 1482, 1485, 1645, 1872, 1881, 1887, 1894, 1901, 2230, 543, 22, 558, 566, 567, 796, 801,  807,
		881, 1168, 1316, 1318, 1370,  1447, 1451, 1455, 1459,  1616, 1922, 1923, 1924,  2227, 375, 381, 388,  86,
		504, 814, 1245, 1553, 2459,  2461, 2462, 2464, 1535,  1539, 185, 592, 595,  597, 1096, 1925, 1926,  1927,
		1928, 1929, 2257, 2259, 2261, 2263, 390, 582, 594,  596, 1221, 1861, 883, 2265, 169, 2142, 585, 674,  93,
		198, 206, 498, 536, 609, 663, 664, 665, 667, 677, 678, 680, 681, 682, 854, 1064, 1123, 1251, 1352,  1452,
		1625, 1673, 1863, 2210, 2366, 2375, 2383, 2391, 2399, 72, 74, 575, 732, 1163, 445, 671, 673, 1681,  1724,
		1727, 1602, 598, 599, 1930, 1931, 1932, 2267, 590, 2269, 2271, 1578, 1610, 692, 694, 700, 703, 705, 2636,
		702, 971, 687, 691,  2146, 2418, 2511, 717,  722, 707, 710,  711, 713, 721, 724,  1637, 720, 1499,  1933,
		1934, 583, 741, 743,  745, 747, 749, 751,  759, 764, 769, 772,  774, 887, 888, 889,  890, 891, 892,  893,
		894, 584, 757, 760, 762, 765, 767, 770, 186, 188, 559, 781, 783, 784, 785, 786, 787, 789, 790, 792,  794,
		809, 817, 831, 863, 1093, 1121, 1124, 1125, 1127,  1347, 1543, 1604, 1617, 1619, 1646, 1717, 1839,  2190,
		2228, 2231, 2327, 2359, 2437, 2698, 2782, 1653, 780, 1655, 1657, 1659, 1661, 1663, 895, 1665, 1667, 1669,
		23, 798, 799, 1018, 1487, 1935, 1936, 1937, 1986, 1987, 1989, 2645, 555, 1552, 294, 804, 803, 2454,  586,
		810, 122, 124, 134, 157, 159, 170, 190, 366, 368, 378, 580, 690, 697, 698, 1025, 1032, 1033, 1035,  1036,
		1047, 1150, 1173, 1180,  1181, 1183, 1184, 1193,  1197, 1204, 1206, 1207,  1208, 1209, 1210, 1223,  1227,
		1234, 1235, 1262, 1269,  1271, 1272, 1273, 1274,  1275, 1277, 1376, 1385,  1428, 1435, 1439, 1508,  1515,
		1516, 1560, 2334, 2336, 2344, 2358, 2406, 2411, 2574, 1554, 1555, 397, 1501, 813, 2428, 2429, 2430, 2431,
		2433, 2434, 2435, 2438,  2439, 2440, 2441, 2442,  2443, 2444, 2448, 2450,  2451, 2457, 2460, 2463,  2465,
		2466, 2467, 2468, 2470,  2472, 2474, 2477, 2479,  2484, 2486, 2487, 2489,  2490, 2491, 2492, 2493,  2496,
		2497, 2500, 2501, 2504,  2513, 2514, 2517, 2519,  2521, 2523, 2525, 2527,  2529, 2531, 2533, 2535,  2537,
		2539, 2541, 2543, 2545,  2547, 2549, 2551, 2553,  2555, 2556, 2558, 2559,  2561, 2563, 2564, 2565,  2567,
		2569, 2571, 2573, 2575,  2577, 2579, 2580, 2582,  2583, 2588, 2594, 2595,  2596, 2597, 2598, 2599,  2600,
		2601, 2602, 2603, 2604,  2605, 2606, 2607, 2608,  2609, 2610, 2611, 2612,  2613, 2614, 2615, 2616,  2617,
		2618, 2619, 2620, 2621,  2622, 2623, 2624, 2625,  2631, 2638, 2639, 2641,  2643, 2647, 2648, 2649,  2650,
		2652, 2653, 2654, 2655,  2656, 2657, 2658, 2659,  2660, 2661, 2662, 2663,  2664, 2665, 2666, 2667,  2668,
		2669, 2670, 2671, 2672,  2673, 2674, 2675, 2676,  2677, 2678, 2679, 2680,  2681, 2682, 2683, 2684,  2685,
		2687, 2688, 2689, 2690,  2692, 2694, 2695, 2696,  2697, 2699, 2700, 2701,  2702, 2703, 2704, 2705,  2706,
		2707, 2708, 2709, 2710,  2711, 2712, 2713, 2714,  2715, 2716, 2717, 2718,  2719, 2720, 2721, 2722,  2723,
		2724, 2725, 2726, 2727,  2728, 2729, 2730, 2731,  2732, 2733, 2734, 2735,  2736, 2737, 2738, 2739,  2740,
		2741, 2742, 2743, 2744,  2745, 2746, 2747, 2748,  2749, 2750, 2751, 2752,  2753, 2754, 2755, 2756,  2757,
		2758, 2759, 2760, 2761,  2762, 2763, 2764, 2765,  2766, 2767, 2768, 2769,  2770, 2771, 2772, 2773,  2774,
		2775, 2777, 2778, 2780, 2783, 2784, 812, 896, 87, 815, 819, 820, 1939, 1941, 1943, 821, 832, 1938,  1940,
		1942, 1944, 822, 827, 830,  2273, 603, 605, 606,  1946, 1947, 1948, 1949,  1950, 2275, 2277, 2279,  2281,
		2283, 607, 608, 1945, 1951, 1952,  2285, 601, 2287, 2289, 833, 30,  391, 2407, 2520, 214, 246, 252,  258,
		260, 262, 264, 266, 268, 270, 272,  276, 296, 302, 304, 306, 308,  314, 326, 897, 2498, 2499, 495,  2239,
		31, 852, 855, 856, 858, 860, 2516, 2557, 2693,  2781, 864, 990, 150, 1679, 1682, 1683, 1685, 1687,  1689,
		1691, 1693, 1695, 1697, 1699, 1701, 1703, 1705, 1707,  1709, 216, 328, 823, 88, 137, 138, 173, 174,  380,
		382, 701, 729, 733, 735, 738, 824, 988, 989, 1037, 1054, 1185, 1213, 1236, 1278, 1387, 1440, 1517,  1580,
		2194, 2346, 2349, 2420, 1085, 2476, 142, 178, 385,  704, 1040, 1057, 1188, 1216, 1239, 1281, 1390,  1443,
		1520, 1583, 2351, 2423, 2458,  991, 1589, 1603, 244,  248, 254, 278, 284, 290,  298, 310, 316, 330,  992,
		994, 551, 993, 996, 998,  999, 1001, 1004, 1005,  1006, 1008, 1009, 1011,  1014, 1016, 1220, 1344,  2471,
		995, 1003, 1837, 901, 902,  903, 218, 904, 905,  906, 907, 908, 909, 910,  1020, 1021, 1489, 1953,  1954,
		1955, 1992, 1993, 1995, 2644, 129, 131, 164, 166, 373, 376, 556, 695, 1029, 1051, 1177, 1201, 1231, 1266,
		1380, 1432, 1512, 1564,  2338, 2342, 2415,  2515, 1027, 1030,  1038, 1041, 1042,  2590, 1039, 969,  1022,
		1026, 2585, 1049, 1052,  1055, 1058, 1059,  2632, 1056, 961,  1044, 1048, 1067,  1068, 1069, 1073,  1074,
		1075, 1079, 1080, 1081, 282, 843,  846, 849, 2195, 144, 145, 180,  181, 387, 389, 706, 1043, 1060,  1094,
		1190, 1218, 1241, 1283,  1392, 1445, 1522,  1544, 1585, 1620,  2328, 2353, 2356,  2425, 2188, 2330,  578,
		1258, 1086, 1084, 1087, 91, 94, 95, 97, 492, 1088, 2256, 2258, 2260, 2262, 2264, 2266, 2268, 2270,  2272,
		2274, 2276, 2278, 2280,  2282, 2284, 2286, 2288,  2290, 2291, 2293, 2295,  2297, 2299, 2301, 2303,  2305,
		2307, 2309, 2311, 2313, 2315, 2317,  2319, 2321, 2323, 2325, 1091, 911,  912, 1095, 1394, 132, 139,  146,
		727, 914, 26, 1108, 915, 916, 917, 918, 18, 27, 151, 393, 507, 508, 572, 587, 683, 777, 861, 1083,  1090,
		1098, 1100, 1101, 1102,  1103, 1104, 1105, 1106,  1110, 1111, 1112, 1114,  1116, 1118, 1314, 1448,  1453,
		1456, 1460, 1541, 1622,  1623, 1626, 1627, 1629,  1671, 1674, 1675, 1677,  1904, 2207, 2211, 2213,  2216,
		2432, 2691, 2779, 919, 509,  1109, 1148, 1826, 920,  921, 922, 923, 2509,  1139, 1144, 1129, 1132,  1133,
		1135, 1143, 1146, 1639,  1142, 925, 1151,  167, 175, 182, 926,  193, 394, 1119,  1155, 1156, 1157,  1158,
		1159, 2554, 1175, 1178,  1186, 1189, 1191,  2592, 1187, 965,  1170, 1174, 1199,  1202, 1214, 1217,  1219,
		2627, 1215, 970, 1194, 1198, 1276, 2150, 2345, 1229, 1232, 1237, 1240, 1242, 2591, 1238, 967, 1224, 1228,
		1556, 406, 930, 931, 933, 934,  1742, 1769, 409, 448, 928, 929,  1684, 1745, 1772, 403, 1680, 1721,  927,
		1264, 1267, 1279, 1282, 1284,  2637, 1280, 964, 1259,  1263, 220, 332, 1285,  412, 451, 932, 1299,  1309,
		1686, 1730, 1733, 96, 200, 207, 500, 537, 610, 857, 1070, 1126, 1253, 1288, 1289, 1292, 1293, 1295, 1303,
		1304, 1306, 1307, 1308, 1354, 1457, 1628, 1676, 1864,  2214, 2368, 2377, 2385, 2393, 2401, 1332, 76,  78,
		576, 736, 1165, 415, 454,  935, 1302, 1688, 1736,  1739, 1312, 1313, 1838,  2488, 540, 1092, 2197,  1315,
		1319, 1326, 1320, 1321,  1956, 1957, 1958, 2360,  1322, 1323, 1959, 1960,  1961, 1333, 1395, 1328,  1329,
		1330, 1962, 1963, 1964, 936,  2453, 579, 884, 1338,  1340, 1341, 1920, 1965,  1966, 1967, 545, 937,  334,
		1342, 1571, 2478, 1337,  1339, 1572, 1346, 1248,  1343, 1654, 1656, 1658,  1660, 1662, 1664, 1666,  1668,
		1670, 1345, 1348, 938,  1349, 1605, 89,  1061, 1065, 1071, 1076,  2507, 1362, 1367,  183, 600, 834,  836,
		1358, 1366, 1369, 1641, 2372, 1365, 90, 818, 828,  1383, 2154, 1378, 1381, 1388, 1391, 1393, 2630,  1389,
		957, 1384, 2170, 1373, 1377,  60, 1211, 2158, 2292,  614, 616, 617, 1969,  1970, 1971, 1972, 1973,  2294,
		2296, 2298, 2300, 2302, 618, 619,  1968, 1974, 1975, 2304, 612, 2306,  2308, 171, 1331, 1399, 1403,  661,
		1411, 1422, 1400, 1401, 1404,  1405, 1407, 1415, 1416,  1418, 1419, 1421, 1414, 57,  58, 61, 62, 65,  66,
		194, 496, 499, 501, 502, 505, 506, 1246, 1311, 2456, 2566, 1436, 222, 1430, 1433, 1441, 1444, 1446, 2628,
		1437, 1442, 968, 1438,  2174, 1425, 1429, 1866,  699, 68, 92,  196, 205, 497, 533,  541, 589, 853,  1062,
		1122, 1249, 1350, 1449, 1624, 1672, 1862, 2208, 2364, 2373, 2381, 2389, 2397, 805, 806, 1464, 1978, 1980,
		1470, 1471, 1472, 1473,  1474, 1475, 1913,  1915, 1917, 1918,  1919, 2040, 2049,  2107, 885, 1467,  1468,
		1469, 2041, 2050, 2108, 546, 744, 748, 752, 753,  755, 761, 766, 771, 775, 1478, 1480, 1481, 1483,  1484,
		1486, 1488, 1988, 1990,  1490, 1994, 1996, 1492,  1493, 1494, 1999, 2000,  2001, 2002, 2003, 2004,  2005,
		2006, 2222, 1568, 2162,  940, 2447, 941, 2481,  283, 211, 213,  215, 217, 219, 221,  223, 224, 226,  228,
		230, 232, 234, 236, 238, 240, 242, 245, 247, 249, 250, 253, 255, 256, 259, 261, 263, 265, 267, 269,  271,
		273, 274, 277, 279, 280, 285, 286, 288, 291, 292, 297, 299, 300, 303, 305, 307, 309, 311, 312, 315,  317,
		318, 321, 322, 325, 327,  329, 331, 333, 335, 336,  338, 340, 342, 344, 346,  348, 350, 352, 1497,  1500,
		2010, 2011, 2012, 2191, 1498, 2008, 2009, 1614, 726, 728, 1495, 1496, 1615, 225, 2506, 1502, 1504,  2485,
		1510, 1513, 1518, 1521,  1523, 2635, 1519,  958, 1505, 1509,  1526, 1840, 2013,  2014, 2015, 2016,  1525,
		569, 730, 734, 737,  739, 797, 1019,  1371, 1527, 2651, 942,  1424, 1528, 1529,  1530, 2017, 2018,  2019,
		2020, 2021, 2022, 943, 944,  2446, 227, 337, 2473,  1154, 2560, 1545, 882,  1547, 1546, 900, 1549,  1548,
		913, 1551, 1550, 1562,  1565, 1581, 1584,  1586, 2626, 1336,  1540, 2127, 2131,  2135, 2139, 2143,  2147,
		2151, 2155, 2159, 2163,  2166, 2171, 2175,  2178, 2182, 2186,  1573, 1574, 2023,  2024, 2025, 945,  1575,
		946, 1576, 1579, 1712, 2026, 2027,  2028, 2029, 2030, 1582, 962, 1570,  2179, 1557, 1561, 243, 251,  257,
		275, 281, 287, 289, 293, 301, 313, 319, 323, 339, 353, 552, 573, 588, 593, 604, 615, 622, 631, 639,  647,
		655, 778, 802, 808, 1012, 1351, 1353, 1355, 1356,  1372, 1450, 1454, 1458, 1461, 1588, 1590, 1591,  1593,
		2189, 1587, 947, 19, 570,  1594, 1423, 2123, 662,  1601, 1600, 547, 1597,  1598, 1599, 2031, 2032,  2033,
		2034, 948, 1596, 1606, 1569, 2469, 949, 2502, 2503,  130, 133, 165, 168, 374, 377, 696, 950, 1031,  1053,
		1179, 1203, 1233, 1268, 1382, 1434, 1514, 1566, 1607, 2196, 2339, 2343, 2416, 811, 951, 1608, 1611, 1714,
		2035, 2036, 2037, 2038, 2039, 2047, 401, 952, 1618, 1621, 1632, 1647, 59, 63, 229, 341, 1649, 1152, 1287,
		1648, 1867, 1711, 2042, 2043, 1713, 2044, 2045, 1715, 2046, 152, 2048, 28, 1718, 1720, 1719, 1722,  1829,
		1728, 1734, 1740, 1743,  1746, 1748, 1751, 1754,  1757, 1760, 1763, 1766,  1799, 1805, 1811, 1817,  1823,
		1832, 1725, 1731, 1737,  1770, 1773, 1775, 1778,  1781, 1784, 1787, 1790,  1793, 1796, 1802, 1808,  1814,
		1820, 1835, 1827, 231, 343,  233, 345, 839, 1841,  295, 2508, 1852, 1857,  1643, 1842, 1845, 1846,  1848,
		1856, 1859, 1855, 5, 7, 20, 29, 32, 39, 41, 52, 70, 73, 75, 77, 79, 80, 82, 84, 106, 108, 120, 155,  203,
		364, 392, 404, 407, 410, 413, 416, 418, 421, 424, 427, 430, 433, 436, 439, 442, 446, 449, 452, 455,  457,
		460, 463, 466, 469, 472, 475, 478, 481, 484, 487, 490, 516, 518, 527, 666, 668, 679, 684, 688, 712,  714,
		782, 788, 791, 793, 795, 835, 837, 850, 1000, 1007, 1010, 1013, 1015, 1017, 1023, 1045, 1063, 1066, 1072,
		1077, 1099, 1107, 1113,  1115, 1117, 1120, 1134,  1136, 1147, 1169, 1171,  1195, 1225, 1260, 1294,  1296,
		1305, 1359, 1374, 1397,  1406, 1408, 1417, 1426,  1506, 1542, 1558, 1592,  1634, 1636, 1638, 1640,  1642,
		1644, 1723, 1726, 1729,  1732, 1735, 1738, 1741,  1744, 1747, 1749, 1752,  1755, 1758, 1761, 1764,  1767,
		1771, 1774, 1776, 1779,  1782, 1785, 1788, 1791,  1794, 1797, 1800, 1803,  1806, 1809, 1812, 1815,  1818,
		1821, 1824, 1830, 1833,  1836, 1847, 1849, 1868,  1871, 1873, 1877, 1880,  1882, 1883, 1886, 1888,  1890,
		1893, 1895, 1897, 1900,  1902, 2200, 2202, 2204,  2209, 2212, 2215, 2217,  2235, 2237, 2250, 2331,  2365,
		2367, 2369, 2370, 2374,  2376, 2378, 2379, 2382,  2384, 2386, 2387, 2390,  2392, 2394, 2395, 2398,  2400,
		2402, 2403, 2408, 2512, 235, 347, 571, 972, 1595,  1876, 1889, 1896, 1903, 1905, 2051, 2052, 2053,  2054,
		2056, 2058, 2060, 2642, 973, 1324, 1327, 1874, 1875,  2055, 2057, 2059, 2061, 355, 866, 779, 1869,  1878,
		1884, 1891, 1898, 204, 395,  493, 685, 776, 851,  1153, 1250, 1252, 1254,  1255, 1613, 2121, 2494,  2518,
		9, 11, 16, 419, 458, 974, 1690, 1750, 1777, 12,  43, 48, 110, 112, 117, 422, 461, 976, 1692, 1753,  1780,
		113, 520, 522, 530, 523, 675, 464, 670, 672, 676,  1694, 1798, 1801, 425, 467, 716, 718, 723, 978,  1696,
		1756, 1783, 719, 428,  470, 980, 1138,  1140, 1145, 1698, 1759,  1786, 1141, 431,  473, 982, 1298,  1300,
		1310, 1700, 1804, 1807, 2122,  434, 476, 983, 1301,  1702, 1810, 1813, 437,  479, 984, 1361, 1363,  1368,
		1704, 1762, 1789, 1364, 1410, 1412, 1420, 1413, 440, 482, 986, 1706, 1765, 1792, 1851, 1853, 1858,  1854,
		2247, 485, 1708, 1816, 1819, 2242,  2244, 2246, 237, 349, 398, 840,  1503, 2419, 2455, 2192, 2198,  1149,
		1244, 1386, 2167, 1650,  1651, 1652, 686,  2206, 2522, 1491,  2066, 2067, 2068,  2069, 2070, 2071,  2072,
		2073, 2074, 2075, 2076,  2077, 2078, 2223,  2224, 2225, 549,  2062, 2063, 2064,  2065, 2219, 2220,  2221,
		548, 239, 2226, 2475, 2562,  2229, 67, 1317, 1325,  2232, 2240, 2248, 98, 202,  208, 503, 538, 611,  859,
		1078, 1128, 1256, 1357,  1462, 1630, 1678, 1865,  2218, 2233, 2234, 2236,  2238, 2249, 2251, 2252,  2253,
		2254, 2371, 2380, 2388, 2396, 2404, 81, 83, 577, 740, 1167, 488, 1710, 1822, 1825, 2243, 2245, 189,  623,
		624, 625, 626, 1097, 2079, 2080, 2081, 2082, 2083, 627, 628, 2084, 2085, 2109, 620, 632, 633, 634,  2086,
		2087, 2088, 2089, 2090, 635,  636, 2091, 2092, 2110,  629, 640, 641, 642,  2093, 2094, 2095, 2096,  2097,
		643, 644, 2098, 2099, 2111, 637, 648, 649, 650, 2100, 2101, 2102, 2103, 2104, 651, 652, 2105, 2106, 2112,
		645, 2329, 2310, 656, 657,  658, 2114, 2115, 2116,  2117, 2118, 2312, 2314,  2316, 2318, 2320, 659,  660,
		2113, 2119, 2120, 2322, 653, 2324, 2326, 241, 351,  568, 954, 209, 399, 581, 1082, 1396, 2480, 127,  162,
		371, 693, 1028, 1050, 1176, 1200, 1230, 1265, 1379, 1431, 1511, 1563, 2413, 2340, 2347, 2352, 2354, 2593,
		2350, 956, 1212, 2183, 2332, 2337,  2584, 2361, 135, 2187, 443, 491,  867, 870, 886, 924, 939, 955,  975,
		977, 979, 981, 985, 987, 1768, 1795, 69, 71, 85, 542, 574, 731, 1161, 1398, 2578, 2414, 2417, 2421, 2424,
		2426, 2629, 2422, 966, 2409, 2412,
	};
} // namespace Items

#endif // ITEMS_H
