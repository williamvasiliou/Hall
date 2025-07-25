#ifndef ITEMS_H
#define ITEMS_H

#include <cstddef>
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

	namespace sum {
		static const size_t index[Items::size] = {
			0, 2, 3, 4, 5, 6, 8, 19, 20, 21, 22, 23, 25, 26, 29, 30, 34, 35, 46, 47, 49, 51, 52, 54, 55, 56,  57,
			74, 77, 80, 82, 84, 85, 86, 87, 88, 89, 92, 93, 94, 106, 107, 108, 109, 111, 112, 113, 131, 138, 147,
			150, 151, 152, 154, 158, 161, 162, 163, 166, 167,  168, 169, 170, 171, 173, 184, 185, 186, 187,  188,
			190, 192, 195, 197, 205, 207, 210, 212, 216, 220,  244, 246, 248, 250, 251, 259, 272, 274, 277,  279,
			286, 288, 290, 293, 296, 298, 302, 305, 313, 315,  316, 318, 321, 333, 342, 346, 370, 371, 373,  378,
			381, 385, 392, 393, 395, 397, 399, 402, 404, 411,  413, 433, 436, 438, 442, 446, 447, 448, 454,  455,
			457, 459, 460, 491, 513, 515, 520, 521, 525, 526,  527, 540, 542, 544, 546, 548, 563, 565, 566,  567,
			568, 569, 570, 571, 573, 587, 588, 589, 590, 591,  592, 593, 595, 613, 621, 622, 624, 625, 629,  631,
			633, 636, 637, 639, 641, 643, 647, 649, 653, 654,  657, 659, 662, 664, 666, 667, 725, 727, 728,  732,
			733, 734, 764, 767, 769, 771, 792, 793, 795, 798,  799, 810, 814, 815, 816, 818, 820, 822, 825,  827,
			829, 841, 843, 845, 848, 859, 860, 862, 865, 866,  867, 868, 869, 870, 871, 877, 878, 879, 880,  881,
			882, 883, 885, 919, 920, 921, 927, 928, 934, 935,  938, 939, 947, 952, 956, 959, 962, 963, 966,  967,
			975, 977, 979, 981, 984, 987, 990, 992, 993, 994, 995, 996, 998, 1009, 1010, 1011, 1012, 1014,  1019,
			1020, 1022, 1023, 1027, 1028, 1032, 1036, 1040, 1055, 1056, 1057, 1058, 1059, 1060, 1061, 1062, 1063,
			1068, 1073, 1078, 1089, 1090, 1131, 1135, 1137, 1140, 1143, 1146, 1149, 1152, 1153, 1156, 1159, 1162,
			1175, 1176, 1178, 1180, 1181, 1182, 1183, 1184, 1185, 1188, 1191, 1194, 1196, 1197, 1282, 1284, 1286,
			1623, 1625, 1626, 1633, 1634, 1637, 1644, 1645, 1646, 1652, 1654, 1657, 1658, 1661, 1663, 1664, 1668,
			1677, 1679, 1680, 1683, 1684, 1692, 1697, 1701, 1702, 1706, 1707, 1727, 1728, 1731, 1732, 1735, 1739,
			1743, 1754, 1755, 1756, 1757, 1760, 1780, 1783, 1815, 1820, 1838, 1839, 1840, 1845, 1856, 1858, 1881,
			1895, 1896, 1897, 1899, 1901, 1904, 1906, 1908, 1910, 1912, 1914, 1915, 1917, 1919, 1930, 1931, 1933,
			1935, 1957, 1958, 1961, 1962, 1970, 1972, 1974, 1976, 1979, 1983, 1984, 1987, 1988, 1995, 1997, 1999,
			2001, 2004, 2007, 2020, 2026, 2051, 2054, 2055, 2056, 2057, 2059, 2062, 2104, 2105, 2107, 2108, 2109,
			2110, 2111, 2113, 2114, 2115, 2119, 2123, 2124, 2127, 2130, 2133, 2134, 2137, 2139, 2194, 2197, 2216,
			2217, 2220, 2223, 2226, 2227, 2231, 2233, 2234, 2235, 2236, 2237, 2239, 2250, 2251, 2252, 2253, 2254,
			2256, 2258, 2259, 2261, 2263, 2266, 2267, 2268, 2278, 2280, 2283, 2286, 2288, 2292, 2293, 2294, 2297,
			2298, 2305, 2307, 2309, 2311, 2314, 2317, 2318, 2321, 2322, 2329, 2331, 2333, 2336, 2339, 2340, 2341,
			2342, 2345, 2346, 2349, 2350, 2357, 2359, 2361, 2363, 2366, 2369, 2370, 2371, 2372, 2373, 2380, 2387,
			2390, 2391, 2395, 2396, 2397, 2400, 2401, 2409, 2411, 2413, 2415, 2418, 2421, 2422, 2426, 2427, 2428,
			2429, 2430, 2431, 2432, 2440, 2475, 2476, 2477, 2478, 2479, 2485, 2486, 2487, 2495, 2498, 2501, 2503,
			2505, 2509, 2513, 2514, 2522, 2523, 2525, 2527, 2528, 2530, 2532, 2539, 2541, 2543, 2545, 2547, 2554,
			2555, 2556, 2557, 2558, 2559, 2560, 2562, 2571, 2572, 2574, 2576, 2578, 2579, 2583, 2584, 2588, 2589,
			2591, 2592, 2593, 2594, 2595, 2608, 2609, 2610, 2612, 2613, 2614, 2615, 2618, 2619, 2624, 2626, 2630,
			2632, 2634, 2635, 2637, 2650, 2651, 2652, 2653, 2655, 2656, 2659, 2662, 2663, 2666, 2667, 2675, 2677,
			2679, 2681, 2684, 2687, 2690, 2694, 2698, 2707, 2709, 2710, 2713, 2714, 2722, 2727, 2731, 2734, 2736,
			2738, 2739, 2741, 2742, 2744, 2745, 2746, 2747, 2748, 2749, 2750, 2753, 2767, 2768, 2769, 2770, 2771,
			2772, 2773, 2775, 2793, 2794, 2795, 2796, 2799, 2800, 2809, 2811, 2812, 2814, 2816, 2819, 2822, 2825,
			2830, 2831, 2854, 2855, 2858, 2864, 2866, 2869, 2871, 2887, 2891, 2895, 2899, 2909, 2910, 2911, 2915,
			2918, 2921, 2938, 2941, 2944, 2947, 2953, 2955, 2958, 2964, 2966, 2969, 2983, 2986, 2989, 2992, 2995,
			2997, 2999, 3000, 3070, 3077, 3078, 3082, 3084, 3085, 3090, 3091, 3093, 3095, 3097, 3101, 3103, 3105,
			3106, 3109, 3110, 3117, 3119, 3121, 3123, 3126, 3129, 3136, 3138, 3140, 3142, 3153, 3166, 3168, 3169,
			3172, 3173, 3175, 3177, 3180, 3182, 3185, 3186, 3187, 3190, 3192, 3195, 3197, 3200, 3202, 3203, 3205,
			3206, 3209, 3210, 3218, 3220, 3239, 3245, 3246, 3248, 3250, 3253, 3263, 3264, 3268, 3270, 3272, 3274,
			3277, 3280, 3283, 3330, 3332, 3333, 3334, 3338, 3341, 3342, 3345, 3347, 3350, 3352, 3354, 3362, 3365,
			3366, 3367, 3368, 3369, 3370, 3373, 3397, 3409, 3410, 3414, 3416, 3417, 3418, 3420, 3421, 3422, 3423,
			3425, 3430, 3431, 3432, 3433, 3435, 3437, 3441, 3447, 3448, 3452, 3468, 3469, 3473, 3474, 3476, 3480,
			3481, 3483, 3486, 3487, 3489, 3492, 3494, 3495, 3497, 3498, 3499, 3534, 3536, 3537, 3555, 3573, 3577,
			3581, 3584, 3585, 3587, 3588, 3590, 3591, 3592, 3593, 3594, 3596, 3607, 3608, 3609, 3610, 3611, 3613,
			3614, 3823, 3824, 3843, 3847, 3849, 3852, 3855, 3866, 3867, 3869, 3873, 3877, 3879, 3883, 3885, 3888,
			3893, 3894, 3910, 3919, 3921, 3923, 3932, 3934, 3937, 3939, 3941, 3948, 3957, 3959, 3968, 3970, 3980,
			3989, 3998, 4000, 4003, 4005, 4014, 4016, 4018, 4025, 4032, 4033, 4050, 4051, 4052, 4053, 4054, 4056,
			4057, 4062, 4064, 4065, 4066, 4067, 4068, 4075, 4076, 4093, 4098, 4102, 4106, 4116, 4119, 4121, 4123,
			4125, 4128, 4129, 4130, 4134, 4135, 4136, 4137, 4138, 4139, 4140, 4141, 4142, 4144, 4178, 4179, 4180,
			4186, 4187, 4193, 4194, 4195, 4199, 4211, 4213, 4215, 4218, 4219, 4227, 4232, 4236, 4240, 4249, 4251,
			4252, 4255, 4256, 4264, 4269, 4273, 4277, 4286, 4288, 4289, 4292, 4293, 4301, 4306, 4310, 4314, 4323,
			4325, 4326, 4329, 4330, 4338, 4343, 4347, 4348, 4352, 4361, 4363, 4364, 4367, 4368, 4376, 4381, 4385,
			4388, 4389, 4396, 4397, 4400, 4417, 4419, 4425, 4427, 4430, 4432, 4436, 4439, 4444, 4445, 4446, 4448,
			4449, 4465, 4469, 4470, 4474, 4478, 4482, 4489, 4493, 4494, 4496, 4497, 4500, 4501, 4509, 4511, 4513,
			4515, 4518,
		};

		static const size_t next[Items::size] = {
			2, 3, 4, 5, 6, 8, 19, 20, 21, 22, 23, 25, 26, 29, 30, 34, 35, 46, 47, 49, 51, 52, 54, 55, 56, 57,  74,
			77, 80, 82, 84, 85, 86, 87, 88, 89, 92, 93, 94, 106, 107, 108, 109, 111, 112, 113, 131, 138, 147, 150,
			151, 152, 154, 158, 161, 162, 163,  166, 167, 168, 169, 170, 171,  173, 184, 185, 186, 187, 188,  190,
			192, 195, 197, 205, 207, 210, 212,  216, 220, 244, 246, 248, 250,  251, 259, 272, 274, 277, 279,  286,
			288, 290, 293, 296, 298, 302, 305,  313, 315, 316, 318, 321, 333,  342, 346, 370, 371, 373, 378,  381,
			385, 392, 393, 395, 397, 399, 402,  404, 411, 413, 433, 436, 438,  442, 446, 447, 448, 454, 455,  457,
			459, 460, 491, 513, 515, 520, 521,  525, 526, 527, 540, 542, 544,  546, 548, 563, 565, 566, 567,  568,
			569, 570, 571, 573, 587, 588, 589,  590, 591, 592, 593, 595, 613,  621, 622, 624, 625, 629, 631,  633,
			636, 637, 639, 641, 643, 647, 649,  653, 654, 657, 659, 662, 664,  666, 667, 725, 727, 728, 732,  733,
			734, 764, 767, 769, 771, 792, 793,  795, 798, 799, 810, 814, 815,  816, 818, 820, 822, 825, 827,  829,
			841, 843, 845, 848, 859, 860, 862,  865, 866, 867, 868, 869, 870,  871, 877, 878, 879, 880, 881,  882,
			883, 885, 919, 920, 921, 927, 928,  934, 935, 938, 939, 947, 952,  956, 959, 962, 963, 966, 967,  975,
			977, 979, 981, 984, 987, 990, 992, 993, 994, 995, 996, 998, 1009, 1010, 1011, 1012, 1014, 1019,  1020,
			1022, 1023, 1027, 1028, 1032, 1036, 1040, 1055, 1056, 1057, 1058, 1059, 1060, 1061, 1062, 1063,  1068,
			1073, 1078, 1089, 1090, 1131, 1135, 1137, 1140, 1143, 1146, 1149, 1152, 1153, 1156, 1159, 1162,  1175,
			1176, 1178, 1180, 1181, 1182, 1183, 1184, 1185, 1188, 1191, 1194, 1196, 1197, 1282, 1284, 1286,  1623,
			1625, 1626, 1633, 1634, 1637, 1644, 1645, 1646, 1652, 1654, 1657, 1658, 1661, 1663, 1664, 1668,  1677,
			1679, 1680, 1683, 1684, 1692, 1697, 1701, 1702, 1706, 1707, 1727, 1728, 1731, 1732, 1735, 1739,  1743,
			1754, 1755, 1756, 1757, 1760, 1780, 1783, 1815, 1820, 1838, 1839, 1840, 1845, 1856, 1858, 1881,  1895,
			1896, 1897, 1899, 1901, 1904, 1906, 1908, 1910, 1912, 1914, 1915, 1917, 1919, 1930, 1931, 1933,  1935,
			1957, 1958, 1961, 1962, 1970, 1972, 1974, 1976, 1979, 1983, 1984, 1987, 1988, 1995, 1997, 1999,  2001,
			2004, 2007, 2020, 2026, 2051, 2054, 2055, 2056, 2057, 2059, 2062, 2104, 2105, 2107, 2108, 2109,  2110,
			2111, 2113, 2114, 2115, 2119, 2123, 2124, 2127, 2130, 2133, 2134, 2137, 2139, 2194, 2197, 2216,  2217,
			2220, 2223, 2226, 2227, 2231, 2233, 2234, 2235, 2236, 2237, 2239, 2250, 2251, 2252, 2253, 2254,  2256,
			2258, 2259, 2261, 2263, 2266, 2267, 2268, 2278, 2280, 2283, 2286, 2288, 2292, 2293, 2294, 2297,  2298,
			2305, 2307, 2309, 2311, 2314, 2317, 2318, 2321, 2322, 2329, 2331, 2333, 2336, 2339, 2340, 2341,  2342,
			2345, 2346, 2349, 2350, 2357, 2359, 2361, 2363, 2366, 2369, 2370, 2371, 2372, 2373, 2380, 2387,  2390,
			2391, 2395, 2396, 2397, 2400, 2401, 2409, 2411, 2413, 2415, 2418, 2421, 2422, 2426, 2427, 2428,  2429,
			2430, 2431, 2432, 2440, 2475, 2476, 2477, 2478, 2479, 2485, 2486, 2487, 2495, 2498, 2501, 2503,  2505,
			2509, 2513, 2514, 2522, 2523, 2525, 2527, 2528, 2530, 2532, 2539, 2541, 2543, 2545, 2547, 2554,  2555,
			2556, 2557, 2558, 2559, 2560, 2562, 2571, 2572, 2574, 2576, 2578, 2579, 2583, 2584, 2588, 2589,  2591,
			2592, 2593, 2594, 2595, 2608, 2609, 2610, 2612, 2613, 2614, 2615, 2618, 2619, 2624, 2626, 2630,  2632,
			2634, 2635, 2637, 2650, 2651, 2652, 2653, 2655, 2656, 2659, 2662, 2663, 2666, 2667, 2675, 2677,  2679,
			2681, 2684, 2687, 2690, 2694, 2698, 2707, 2709, 2710, 2713, 2714, 2722, 2727, 2731, 2734, 2736,  2738,
			2739, 2741, 2742, 2744, 2745, 2746, 2747, 2748, 2749, 2750, 2753, 2767, 2768, 2769, 2770, 2771,  2772,
			2773, 2775, 2793, 2794, 2795, 2796, 2799, 2800, 2809, 2811, 2812, 2814, 2816, 2819, 2822, 2825,  2830,
			2831, 2854, 2855, 2858, 2864, 2866, 2869, 2871, 2887, 2891, 2895, 2899, 2909, 2910, 2911, 2915,  2918,
			2921, 2938, 2941, 2944, 2947, 2953, 2955, 2958, 2964, 2966, 2969, 2983, 2986, 2989, 2992, 2995,  2997,
			2999, 3000, 3070, 3077, 3078, 3082, 3084, 3085, 3090, 3091, 3093, 3095, 3097, 3101, 3103, 3105,  3106,
			3109, 3110, 3117, 3119, 3121, 3123, 3126, 3129, 3136, 3138, 3140, 3142, 3153, 3166, 3168, 3169,  3172,
			3173, 3175, 3177, 3180, 3182, 3185, 3186, 3187, 3190, 3192, 3195, 3197, 3200, 3202, 3203, 3205,  3206,
			3209, 3210, 3218, 3220, 3239, 3245, 3246, 3248, 3250, 3253, 3263, 3264, 3268, 3270, 3272, 3274,  3277,
			3280, 3283, 3330, 3332, 3333, 3334, 3338, 3341, 3342, 3345, 3347, 3350, 3352, 3354, 3362, 3365,  3366,
			3367, 3368, 3369, 3370, 3373, 3397, 3409, 3410, 3414, 3416, 3417, 3418, 3420, 3421, 3422, 3423,  3425,
			3430, 3431, 3432, 3433, 3435, 3437, 3441, 3447, 3448, 3452, 3468, 3469, 3473, 3474, 3476, 3480,  3481,
			3483, 3486, 3487, 3489, 3492, 3494, 3495, 3497, 3498, 3499, 3534, 3536, 3537, 3555, 3573, 3577,  3581,
			3584, 3585, 3587, 3588, 3590, 3591, 3592, 3593, 3594, 3596, 3607, 3608, 3609, 3610, 3611, 3613,  3614,
			3823, 3824, 3843, 3847, 3849, 3852, 3855, 3866, 3867, 3869, 3873, 3877, 3879, 3883, 3885, 3888,  3893,
			3894, 3910, 3919, 3921, 3923, 3932, 3934, 3937, 3939, 3941, 3948, 3957, 3959, 3968, 3970, 3980,  3989,
			3998, 4000, 4003, 4005, 4014, 4016, 4018, 4025, 4032, 4033, 4050, 4051, 4052, 4053, 4054, 4056,  4057,
			4062, 4064, 4065, 4066, 4067, 4068, 4075, 4076, 4093, 4098, 4102, 4106, 4116, 4119, 4121, 4123,  4125,
			4128, 4129, 4130, 4134, 4135, 4136, 4137, 4138, 4139, 4140, 4141, 4142, 4144, 4178, 4179, 4180,  4186,
			4187, 4193, 4194, 4195, 4199, 4211, 4213, 4215, 4218, 4219, 4227, 4232, 4236, 4240, 4249, 4251,  4252,
			4255, 4256, 4264, 4269, 4273, 4277, 4286, 4288, 4289, 4292, 4293, 4301, 4306, 4310, 4314, 4323,  4325,
			4326, 4329, 4330, 4338, 4343, 4347, 4348, 4352, 4361, 4363, 4364, 4367, 4368, 4376, 4381, 4385,  4388,
			4389, 4396, 4397, 4400, 4417, 4419, 4425, 4427, 4430, 4432, 4436, 4439, 4444, 4445, 4446, 4448,  4449,
			4465, 4469, 4470, 4474, 4478, 4482, 4489, 4493, 4494, 4496, 4497, 4500, 4501, 4509, 4511, 4513,  4515,
			4518, 4521,
		};

		static inline const size_t size = 4521;
		static const size_t item[size] = {
			0, 1640, 2, 3, 4, 5, 6, 11, 0,  2, 3, 4, 6, 7, 8, 9, 10, 13,  1069, 1842, 1069, 13, 10, 9, 11, 14,  819,
			1417, 1824, 15, 15, 225,  1171, 1435, 517, 16,  17, 18, 949, 1199, 1200,  1201, 1269, 1270, 1272,  1756,
			1199, 17, 1200, 18, 1201,  19, 645, 1619, 44,  1528, 20, 21, 1643, 1653,  1654, 1655, 1656, 1657,  1658,
			1659, 1660, 1661, 1662, 1663, 1664,  1665, 1666, 1667, 779, 1418, 1825,  590, 1007, 1008, 22, 1059,  22,
			32, 23, 25, 26, 27,  28, 29, 30, 31, 30,  31, 23, 25, 26, 27,  32, 33, 34, 35, 36,  37, 38, 39, 34,  35,
			36, 29, 37, 38, 39,  76, 96, 207, 399, 660,  674, 758, 773, 794, 813,  894, 931, 989, 1020, 1511,  1551,
			1599, 1748, 40, 41, 42, 43, 44, 45, 1600, 46, 47, 48, 49, 50, 51, 52, 53, 54, 602, 951, 1274, 56,  1741,
			518, 1587, 57, 58, 59, 60, 61, 1025, 1614, 1835, 61,  1568, 1802, 1890, 62, 64, 65, 66, 67, 68, 73,  62,
			64, 65, 66, 68, 69,  70, 71, 72, 75,  1070, 1840, 1070, 75, 72,  71, 73, 77, 78,  79, 80, 1735, 81,  82,
			80, 81, 85, 88, 89, 425,  1699, 1851, 612, 1778, 85,  86, 87, 87, 88, 89,  90, 612, 1777, 76, 79,  1697,
			1719, 91, 92, 93, 202, 547, 952, 1113, 1178, 1184, 1187, 1191, 1195, 1202, 1203, 1204, 1214, 1275, 1276,
			1277, 1278, 1284, 1290, 1291, 1300, 91, 1202, 92, 1203, 93, 1204, 94, 95, 129, 184, 499, 504, 505,  506,
			832, 95, 201, 202, 203, 327, 336,  345, 351, 358, 364, 370, 376, 497,  97, 98, 99, 100, 1731, 101,  102,
			100, 101, 106, 109, 110,  1744, 1849, 608, 1779,  105, 1883, 765, 1419, 1823,  106, 107, 108, 108,  109,
			110, 111, 608, 1773, 96, 99, 1715, 1, 24, 63,  285, 412, 729, 835, 1158, 113, 114, 117, 115, 116,  1516,
			1520, 1524, 118, 119, 120, 121, 122, 492, 1550,  1682, 1683, 1685, 1688, 1692, 119, 120, 121, 122,  753,
			754, 755, 756, 1681, 123, 482,  1646, 1650, 61, 124, 125, 126,  127, 869, 1007, 1008, 1417, 1418,  1419,
			1420, 1421, 1422, 1423,  1424, 1425, 1426,  1427, 1428, 1429,  1430, 1431, 1432,  1864, 128, 1616,  130,
			186, 513, 812, 1527,  201, 202, 203, 204,  514, 528, 1751,  40, 204, 205, 206,  1205, 1207, 1209,  1205,
			205, 1207, 206, 1209,  208, 209, 210, 211,  1732, 212, 213,  211, 212, 215, 218,  219, 1743, 1861,  609,
			1780, 503, 869, 1007,  1417, 1418, 1419,  1420, 1421, 1422,  1423, 1424, 1425,  1426, 1427, 1428,  1429,
			1430, 1431, 1432, 1870, 215, 216, 217, 217, 218,  219, 220, 609, 1774, 207, 210, 1696, 1716, 221,  1865,
			222, 224, 1571, 1628, 1880,  1881, 223, 520, 1820,  224, 1623, 225, 226, 227,  228, 229, 230, 231,  232,
			233, 234, 235, 236,  237, 238, 239, 240,  241, 242, 243, 244,  245, 246, 247, 248,  249, 250, 251,  252,
			253, 254, 255, 1631, 77, 78, 97,  98, 208, 209, 256, 400, 661, 675,  759, 774, 795, 814, 895, 932,  990,
			1021, 1512, 1513, 1525, 1552, 772, 793, 257, 648,  1007, 1008, 1615, 257, 258, 259, 260, 261, 805,  264,
			5, 28, 67, 265, 272,  386, 416, 733, 839, 884,  917, 1162, 1461, 521, 1569,  522, 1574, 523, 1573,  524,
			1570, 227, 228, 229, 230, 231, 232,  233, 234, 235, 236, 237, 238,  239, 505, 1439, 266, 268, 267,  268,
			269, 270, 271, 272,  273, 283, 266, 267,  269, 270, 271, 273,  274, 275, 276, 277,  278, 279, 280,  282,
			277, 1844, 278, 279, 280, 282, 276,  283, 1, 24, 63, 268, 284, 285,  286, 287, 288, 289, 412, 702,  729,
			835, 913, 1068, 1158, 1441, 1, 24, 63, 285, 412,  729, 835, 1158, 289, 525, 1580, 290, 326, 1218,  1223,
			1473, 291, 292, 293, 1213, 294,  1212, 1214, 1311, 1034, 1320, 295,  1324, 1056, 1329, 807, 1347,  1348,
			1753, 296, 1359, 297, 1292, 1355, 1360, 526, 497,  526, 1000, 298, 527, 298, 528, 1750, 299, 1691,  667,
			1420, 1635, 240, 241, 242, 243, 244,  245, 246, 247, 248, 249, 250,  251, 252, 253, 254, 255, 300,  301,
			506, 516, 519, 529,  535, 536, 573, 576,  577, 578, 579, 580,  581, 582, 583, 584,  588, 604, 623,  624,
			625, 626, 627, 628, 629, 630,  631, 632, 633, 634, 635, 636,  1153, 1154, 1440, 1562, 1584, 1627,  1796,
			1886, 300, 301, 529, 226, 504, 1152, 1438, 302, 303,  203, 292, 304, 305, 306, 307, 308, 309, 432,  436,
			440, 444, 446, 448, 453,  458, 463, 548, 962,  963, 965, 968, 971, 1075,  1179, 1185, 1188, 1192,  1196,
			1455, 291, 304, 305,  306, 307, 308, 309,  16, 303, 310, 311,  479, 482, 487, 530,  757, 856, 857,  893,
			945, 946, 947, 948, 1061,  1215, 1216, 1217, 1454,  1215, 311, 1217, 213, 216,  220, 313, 55, 262,  314,
			491, 806, 1018, 1594, 1595, 1596, 1597, 1690, 315,  316, 317, 318, 319, 518, 525, 1585, 546, 1629,  589,
			1586, 593, 1007, 1008, 598, 1632, 320, 1621, 113, 321, 327, 329, 331, 705, 1218, 1219, 1220, 1221, 1222,
			1474, 327, 1475, 328, 1476,  329, 1219, 1477, 221,  321, 328, 330, 531, 532,  537, 705, 706, 792,  1171,
			532, 330, 1478, 103, 1421, 1831, 322, 323, 533, 534,  622, 324, 324, 325, 334, 341, 342, 343, 381,  382,
			383, 384, 385, 386, 387, 390, 58, 120, 125, 259, 286, 341, 382, 383, 384, 385, 389, 390, 391, 392,  393,
			394, 395, 396, 397, 509, 684, 725, 809, 880, 946, 1065, 1089, 1173, 1443, 1530, 1535, 1539, 1543,  1547,
			393, 394, 48, 49, 316, 395, 428, 754, 396, 240, 387, 389, 1093, 1117, 1118, 397, 398, 1648, 1652,  1052,
			331, 332, 333, 1220, 1223, 1224,  1225, 1479, 326, 332, 1221, 1224,  1480, 333, 1222, 1225, 1481,  1035,
			1109, 1319, 1057, 1111, 1328, 400, 401, 402, 1729,  403, 402, 403, 406, 407, 409, 410, 1746, 1862,  620,
			1781, 407, 408, 408, 409, 410,  620, 1771, 399, 401, 1713, 1422,  1556, 1821, 411, 1641, 413, 414,  415,
			416, 417, 422, 411, 413, 414, 415,  417, 418, 419, 420, 421, 424,  1071, 1843, 424, 421, 420, 422,  425,
			426, 985, 1226, 1227,  1226, 985, 1227, 1071,  427, 428, 429,  430, 446, 431, 432,  433, 434, 435,  436,
			437, 438, 439, 440,  441, 442, 322, 431,  433, 435, 437, 439,  441, 443, 444, 445,  449, 454, 459,  462,
			464, 536, 537, 538,  539, 540, 541, 542,  543, 447, 448, 449,  450, 451, 452, 453,  454, 455, 456,  457,
			458, 459, 460, 461,  323, 447, 450, 452,  455, 457, 460, 462,  463, 464, 465, 467,  113, 114, 303,  468,
			469, 470, 471, 472,  473, 474, 475, 476,  477, 478, 488, 492,  500, 513, 538, 544,  704, 724, 725,  726,
			727, 878, 1010, 1053,  1061, 1062, 1075,  1113, 1156, 1434,  1454, 1455, 1509,  1526, 1572, 1808,  1892,
			469, 1079, 1809, 1893, 468,  470, 471, 1080, 1577,  472, 1081, 1579, 473,  1082, 1578, 474, 1083,  1807,
			475, 1084, 1576, 544, 476, 1085,  1811, 477, 1086, 1810, 478, 1087,  1894, 16, 479, 480, 481, 657,  973,
			1228, 1229, 1230, 1279, 1280, 1282,  1755, 1228, 480, 1229, 481, 1230,  302, 1877, 1017, 482, 171,  483,
			484, 574, 483, 484, 1589,  485, 486, 1760, 324, 487,  488, 77, 78, 83, 84,  97, 98, 103, 104, 115,  116,
			117, 208, 209, 214,  320, 400, 404, 405,  520, 542, 575, 601,  661, 665, 666, 668,  669, 675, 744,  745,
			759, 763, 764, 765,  766, 767, 772, 774,  778, 779, 780, 781,  782, 783, 784, 785,  786, 793, 795,  799,
			800, 814, 818, 819,  820, 821, 822, 823,  824, 826, 895, 900,  901, 902, 932, 936,  939, 940, 990,  994,
			995, 1021, 1025, 1026,  1028, 1512, 1513, 1517,  1518, 1525, 1550, 1552,  1556, 1604, 1686, 1018,  1019,
			224, 987, 489, 490, 539, 545,  1562, 1563, 1564, 1565, 1566, 1567,  1568, 1569, 1570, 1571, 1572,  1573,
			1574, 1575, 1576, 1577, 1578, 1579,  1580, 1581, 1582, 1583, 1584,  1585, 1586, 1587, 1588, 1589,  1590,
			1591, 1592, 1593, 1594, 1595, 1596,  1597, 1598, 1599, 1600, 1601,  1602, 1603, 1604, 1605, 1606,  1607,
			1608, 1609, 1610, 1611, 1612, 1613,  1614, 1615, 1616, 1617, 1618,  1619, 1620, 1621, 1622, 1623,  1624,
			1625, 1626, 1627, 1628, 1629, 1630,  1631, 1632, 1633, 1634, 1635,  1636, 1637, 1638, 1639, 1640,  1641,
			1642, 1643, 1644, 1645, 1646, 1647,  1648, 1649, 1650, 1651, 1652,  1653, 1654, 1655, 1656, 1657,  1658,
			1659, 1660, 1661, 1662, 1663, 1664,  1665, 1666, 1667, 1668, 1669,  1670, 1671, 1672, 1673, 1674,  1675,
			1676, 1677, 1678, 1679, 1680, 1681,  1682, 1683, 1684, 1685, 1686,  1687, 1688, 1689, 1690, 1691,  1692,
			1693, 1694, 1695, 1696, 1697, 1698,  1699, 1700, 1701, 1702, 1703,  1704, 1705, 1706, 1707, 1708,  1709,
			1710, 1711, 1712, 1713, 1714, 1715,  1716, 1717, 1718, 1719, 1720,  1721, 1722, 1723, 1724, 1725,  1726,
			1727, 1728, 1729, 1730, 1731, 1732,  1733, 1734, 1735, 1736, 1737,  1738, 1739, 1740, 1741, 1742,  1743,
			1744, 1745, 1746, 1747, 1748, 1749,  1750, 1751, 1752, 1753, 1754,  1755, 1756, 1757, 1758, 1759,  1760,
			1761, 1762, 1763, 1764, 1765, 1766,  1767, 1768, 1769, 1770, 1771,  1772, 1773, 1774, 1775, 1776,  1777,
			1778, 1779, 1780, 1781, 1782, 1783,  1784, 1785, 1786, 1787, 1788,  1789, 1790, 1791, 1792, 1793,  1794,
			1795, 1796, 1797, 1798, 1799, 1800,  1801, 1802, 1803, 1804, 1805,  1806, 1807, 1808, 1809, 1810,  1811,
			1812, 1813, 1814, 1815, 1816, 1817,  1818, 1819, 1820, 1821, 1822,  1823, 1824, 1825, 1826, 1827,  1828,
			1829, 1830, 1831, 1832, 1833, 1834,  1835, 1836, 1837, 1838, 1839,  1840, 1841, 1842, 1843, 1844,  1845,
			1846, 1847, 1848, 1849, 1850, 1851,  1852, 1853, 1854, 1855, 1856,  1857, 1858, 1859, 1860, 1861,  1862,
			1863, 1864, 1865, 1866, 1867, 1868,  1869, 1870, 1871, 1872, 1873,  1874, 1875, 1876, 1877, 1878,  1879,
			1880, 1881, 1882, 1883,  1884, 1885, 1886,  1887, 1888, 1889,  1890, 1891, 1892,  1893, 1894, 489,  490,
			545, 55, 262, 263, 491,  806, 851, 1592, 492,  493, 1233, 1234, 493, 494,  495, 1232, 1234, 1236,  1237,
			496, 497, 495, 500, 1231, 1233, 1235, 1237, 1231, 1232, 494, 1235, 1236, 498, 496, 498, 499, 499,  1609,
			1611, 335, 1238, 1242, 1482, 336,  337, 338, 1239, 1240, 1241, 1242,  1243, 1483, 336, 1484, 1485,  337,
			1243, 1486, 1487, 338, 339, 340,  1238, 1239, 1244, 1245, 1488, 335,  339, 1240, 1244, 1489, 340,  1241,
			1245, 1490, 500, 21, 221, 1550, 1649, 502, 131, 147,  150, 153, 154, 155, 156, 157, 158, 159, 160,  162,
			172, 175, 176, 177,  178, 181, 187, 503,  1816, 504, 505,  506, 1866, 546, 1629,  1630, 257, 507,  1460,
			1634, 508, 509, 510,  511, 21, 508, 509,  510, 511, 512,  1644, 1645, 1671, 1803,  1891, 512, 513,  514,
			639, 723, 1598, 94, 515,  547, 548, 1092, 1093,  1094, 1095, 1096, 1097,  1098, 1099, 1100, 1101,  1102,
			1103, 1104, 1105, 1106, 1107, 132, 188,  496, 56, 85, 86, 106, 107,  215, 216, 407, 427, 428, 429,  430,
			496, 594, 599, 637,  638, 670, 679, 768,  787, 801, 827,  903, 941, 996, 1037,  1435, 1519, 1520,  1558,
			1687, 637, 698, 699, 700,  1608, 88, 109, 218, 409,  638, 672, 681, 770, 789,  803, 829, 905, 943,  998,
			1039, 1522, 1560, 1593, 639, 639, 640, 1043, 1052,  1606, 1814, 146, 148, 151, 163, 166, 169, 173,  179,
			182, 189, 640, 641,  642, 299, 540, 549,  550, 586, 641, 642,  643, 644, 645, 646,  647, 649, 650,  651,
			652, 653, 654, 655, 656,  791, 876, 1603, 551, 552,  553, 554, 555, 556, 557,  558, 559, 560, 643,  644,
			648, 1155, 550, 645, 551, 646, 552,  647, 133, 648, 1624, 553, 649,  554, 650, 555, 651, 556, 652,  557,
			653, 654, 558, 655, 559, 656, 657, 658, 659,  975, 1246, 1247, 1248, 1285, 1286, 1288, 1754, 1246,  658,
			1247, 659, 1248, 81,  82, 101, 102, 212,  213, 302, 403, 664,  678, 762, 777, 798,  817, 898, 935,  993,
			1024, 1515, 1516, 1555, 1644, 661, 662, 663, 1727,  664, 663, 664, 667, 670, 672, 673, 1700, 1856,  618,
			1782, 670, 671, 671,  672, 618, 673, 1769,  660, 662, 1695,  1711, 675, 676, 677,  1733, 678, 677,  678,
			679, 681, 682, 1742,  1852, 610, 1783, 679,  680, 680, 681,  610, 682, 1775, 674,  676, 1717, 683,  684,
			685, 686, 687, 688,  689, 690, 691, 692,  693, 694, 695, 165,  504, 505, 506, 1436,  1884, 89, 90,  110,
			111, 219, 220, 410, 527, 673, 682, 704, 771, 790, 804, 830, 906, 944, 999, 1010, 1040, 1062, 1509, 1523,
			1524, 1561, 696, 1433, 1510,  319, 812, 697, 698, 699,  698, 699, 700, 57, 58,  59, 60, 256, 701,  1473,
			1474, 1475, 1476, 1477, 1478, 1479,  1480, 1481, 1482, 1483, 1484,  1485, 1486, 1487, 1488, 1489,  1490,
			1491, 1492, 1493, 1494, 1495, 1496,  1497, 1498, 1499, 1500, 1501,  1502, 1503, 1504, 1505, 1506,  1507,
			1508, 701, 702, 703, 703, 1867, 560,  561, 751, 1677, 704, 907, 82,  86, 90, 426, 563, 707, 1804,  1887,
			708, 19, 709, 715, 564, 710, 1564, 565, 711, 1566, 712, 566, 713, 1565, 567, 714, 14, 19, 94, 222,  264,
			265, 314, 324, 398,  467, 512, 541, 562,  569, 697, 702, 707,  708, 709, 710, 711,  712, 713, 714,  715,
			716, 717, 718, 719, 720, 721,  722, 854, 945, 946, 947, 948,  1009, 1063, 1064, 1065, 1066, 1067,  1088,
			1089, 1090, 1091, 1198, 1442, 1443,  1444, 1445, 1567, 1801, 1889, 568,  717, 1563, 265, 521, 522,  523,
			524, 561, 563, 564, 565, 566, 567,  568, 570, 571, 572, 716, 718,  743, 1151, 569, 570, 719, 1806,  571,
			720, 1805, 572, 721, 1888, 722, 724, 725, 726, 727,  728, 1639, 730, 731, 732, 733, 734, 739, 728,  730,
			731, 732, 734, 735, 736, 737, 738, 741, 1072, 1841, 1072, 741, 738, 737, 739, 574, 1819, 742, 743, 1684,
			744, 745, 102, 107, 111, 575, 746,  118, 223, 723, 747, 748, 749,  750, 751, 752, 1668, 748, 1673,  749,
			1670, 1675, 750, 1672, 1678,  752, 1669, 753, 754,  755, 756, 757, 759, 760,  761, 1723, 762, 761,  762,
			768, 770, 771, 1702,  1858, 614, 1784, 768,  769, 769, 770,  614, 771, 1765, 758,  760, 1707, 774,  775,
			776, 1728, 777, 776, 777, 787, 789, 790, 1737, 1853, 787, 788, 788, 789, 619, 790, 1770, 773, 775, 1712,
			791, 792, 825, 1423, 1518,  1832, 795, 796, 797,  1725, 798, 797, 798, 801,  803, 804, 1701, 1859,  616,
			1785, 801, 802, 802, 803, 616, 804, 1767, 794, 796, 1709, 171, 805, 807, 1019, 227, 579, 580, 582,  583,
			1123, 1132, 228, 241, 577, 578,  1094, 1124, 1133, 226, 1092, 1116,  576, 808, 809, 810, 811, 812,  814,
			815, 816, 1722, 817, 816, 817, 825, 827, 829, 830, 1747, 1854, 613, 1786, 827, 828, 828, 829, 613,  830,
			1764, 813, 815, 1706, 831, 134, 190,  831, 832, 833, 834, 836, 837,  838, 839, 229, 242, 581, 840,  849,
			1095, 1119, 1120, 59, 121, 126, 260,  287, 342, 510, 688, 726, 810,  833, 834, 836, 837, 838, 840,  841,
			842, 843, 844, 845, 846, 847, 848, 881, 947, 1066, 1090, 1174, 1444, 1531, 1536, 1540, 1544, 1548,  844,
			1845, 868, 845, 50, 51, 317, 429, 755, 846, 847,  848, 230, 243, 584, 843, 849, 1096, 1121, 1122,  1594,
			1596, 1597, 852, 853, 1155, 852,  1620, 853, 1837, 289, 703, 854,  1437, 855, 857, 863, 1878, 855,  856,
			857, 858, 859, 1249,  1250, 1251, 1526,  1249, 858, 1250, 859,  1251, 1252, 860,  1253, 861, 1254,  860,
			861, 862, 863, 1252, 1253, 1254,  868, 908, 864, 1255, 865, 1256,  866, 1257, 864, 865, 866, 867,  1255,
			1256, 1257, 868, 869, 585, 585, 1588, 1693, 319, 1815, 533, 870, 871, 872, 873, 1213, 1258, 1259,  1260,
			871, 293, 1258, 872, 1259, 873,  1260, 586, 191, 874, 1029, 1610,  874, 587, 870, 871, 1029, 1079,  875,
			877, 1080, 1081, 1082, 1083, 807, 875, 876, 877,  1079, 1080, 1081, 1082, 1083, 1084, 1085, 1086,  1087,
			1084, 1085, 517, 876, 1086, 1087,  878, 587, 878, 1053, 56, 683,  684, 688, 692, 1344, 1193, 1345,  879,
			880, 881, 882, 112, 1637,  501, 883, 884, 885, 890,  112, 334, 501, 502, 883,  885, 886, 887, 888,  889,
			892, 1073, 1533, 1838,  892, 889, 888, 890,  893, 56, 492,  498, 899, 1424, 1833,  895, 896, 897,  1721,
			898, 897, 898, 899, 903, 905, 906, 1740, 1860, 606, 1787, 903, 904, 904, 905, 606, 906, 1763, 900, 1428,
			1827, 894, 896, 1705, 42, 785, 1425, 1830, 344, 1261, 1265, 1491, 345, 346, 347, 1262, 1263, 1264, 1265,
			1266, 1492, 345, 1493, 1494, 346,  1266, 1495, 1496, 347, 348, 349,  1261, 1262, 1267, 1268, 1497,  344,
			348, 1263, 1267, 1498,  349, 1264, 1268,  1499, 105, 907, 1882,  867, 908, 909,  1749, 1869, 910,  1879,
			910, 911, 913, 912,  913, 914, 915, 916,  917, 381, 918, 928,  911, 912, 914, 915,  916, 918, 919,  920,
			921, 922, 923, 924,  925, 927, 922, 1846,  923, 924, 925, 927,  921, 928, 40, 41,  42, 43, 44, 45,  118,
			258, 259, 260, 261, 262, 263, 806, 851, 929, 1591,  1680, 937, 135, 932, 933, 934, 1726, 935, 934,  935,
			937, 938, 941, 943,  944, 1738, 1850, 617,  1788, 938, 941,  942, 942, 943, 617,  944, 1768, 939,  1429,
			1829, 931, 933, 1710, 945,  946, 947, 948, 1176, 406,  46, 57, 119, 124, 258,  284, 290, 325, 508,  683,
			724, 808, 879, 945, 1064,  1088, 1172, 1442, 1529,  1534, 1538, 1542, 1546,  1885, 485, 486, 1876,  949,
			950, 1269, 1271, 1273, 1759, 1270, 1271, 950, 1272, 1273, 951, 1274, 952, 956, 957, 958, 959, 960,  961,
			1206, 1208, 1210, 1211,  1212, 1284, 1333,  1342, 1400, 953,  1206, 1275, 1334,  954, 1208, 1276,  1343,
			955, 1210, 1277, 1401, 534, 953, 954, 955, 956, 1211, 1278, 1334, 1343, 1401, 957, 958, 294, 959,  1290,
			1333, 960, 1291, 1342,  961, 1300, 1400, 434,  438, 442, 443,  445, 451, 456, 461,  465, 962, 963,  964,
			966, 967, 969, 970, 972, 964, 965, 966, 967, 968, 969, 970, 971, 972, 973, 974, 1279, 1281, 1283,  1758,
			1280, 1281, 974, 1282, 1283, 975,  976, 1285, 1287, 1289, 1757, 1286,  1287, 976, 1288, 1289, 977,  978,
			979, 980, 1292, 1293, 1294, 1295, 1296, 1297, 1298, 1299, 1361, 1449, 978, 1293, 1362, 979, 1294,  1363,
			980, 1295, 1364, 1026, 1426, 1822,  589, 1582, 590, 1613, 165, 129,  130, 131, 132, 133, 134, 135,  136,
			137, 138, 139, 140,  141, 142, 143, 144,  145, 146, 147, 148,  149, 150, 151, 152,  153, 154, 155,  156,
			157, 158, 159, 160,  161, 162, 163, 164,  166, 167, 168, 169,  170, 172, 173, 174,  175, 176, 177,  178,
			179, 180, 181, 182,  183, 184, 185, 186,  187, 188, 189, 190,  191, 192, 193, 194,  195, 196, 197,  198,
			199, 200, 981, 983, 986, 1303, 1304, 1305, 1434, 1301, 982, 984, 1301, 1302, 984, 1302, 1060, 425,  426,
			981, 982, 1060, 1303, 983, 1304, 986, 1305, 136, 1636, 987, 988, 1617, 1818, 987, 1618, 988, 1836,  990,
			991, 992, 1730, 993, 992, 993, 996, 998, 999, 1745, 1857, 607, 1789, 996, 997, 997, 998, 607, 999, 1772,
			989, 991, 1714, 1000, 1002, 1156, 1306, 1307, 1308, 1309, 1001, 1307, 1001, 1308, 1002, 1309, 313,  427,
			428, 429, 430, 479, 592, 657, 893, 1003, 1761, 591, 930, 1003, 1004, 1005, 1006, 1310, 1311, 1312, 1313,
			1314, 1315, 1794, 1004, 1310, 592, 1005, 1313, 1795,  1314, 1006, 1315, 593, 1581, 137, 192, 1605,  747,
			1674, 1007, 1008, 1583, 1009, 1010, 531, 1011, 1012, 1011, 1012, 549, 1013, 1014, 1013, 1014, 562, 1015,
			1016, 1015, 1016, 1017, 1018, 1019,  1021, 1022, 1023, 1734, 1024,  1023, 1024, 1027, 1037, 1039,  1040,
			1736, 1847, 611, 1790,  869, 1008, 1417,  1418, 1419, 1420,  1421, 1422, 1423,  1424, 1425, 1426,  1427,
			1428, 1429, 1430, 1431, 1432, 1871,  1029, 1030, 1031, 1316, 1317,  1318, 1316, 1030, 1317, 1031,  1318,
			594, 1032, 1875, 595,  1032, 1033, 1036,  1109, 1319, 1320,  1321, 1322, 1323,  1321, 1033, 1034,  1035,
			1322, 1036, 1323, 1037,  1038, 1038, 1039,  611, 1040, 1776,  1028, 1430, 1826,  1020, 1022, 1718,  145,
			149, 152, 161, 164,  167, 168, 170, 174,  180, 183, 185, 193,  200, 299, 314, 324,  327, 336, 345,  351,
			358, 364, 370, 376, 467,  482, 487, 543, 596, 654,  879, 880, 881, 882, 893,  945, 946, 947, 948,  1041,
			1042, 1043, 1044, 1045, 1433, 1602, 1041, 1042, 1043,  596, 14, 313, 1044, 1045, 929, 1416, 1817,  1045,
			381, 1046, 1051, 597, 1050, 295, 1047, 1325, 1048, 1326, 1049, 1327, 1047, 1048, 1049, 1050, 1324, 1325,
			1326, 1327, 597, 1046, 1051, 1052, 1053, 1027, 1601, 1679, 598, 1632, 1633, 81, 82, 101, 102, 212,  213,
			403, 599, 664, 678, 762, 777,  798, 817, 898, 935, 993, 1024,  1054, 1436, 1515, 1516, 1555, 1874,  488,
			600, 1054, 1055, 1058,  1111, 1328, 1329, 1330,  1331, 1332, 1340, 1330,  1055, 1056, 1057, 1331,  1058,
			1332, 1059, 225, 601,  1812, 1060, 1061,  1062, 1063, 1698,  1064, 1065, 1066,  1067, 1575, 1068,  1073,
			1075, 619, 1791, 41, 43, 138, 194, 1076, 1077, 746, 832, 1076, 1077, 1176, 1813, 1873, 1088, 1089, 1090,
			1091, 1092, 1093, 1094, 1095, 1096,  1097, 1098, 1099, 1100, 1101,  1102, 1103, 1104, 1105, 1106,  1107,
			602, 591, 1108, 1335, 1336, 1335, 1108, 1336, 595, 1110, 1337, 1338, 1337, 1110, 1338, 600, 1112,  1339,
			1339, 1112, 1340, 94, 621, 1341, 20, 1341, 1113,  1114, 1115, 1115, 1114, 1116, 1117, 1118, 1119,  1120,
			1121, 1122, 1123, 1124, 1125, 1126,  1127, 1128, 1129, 1130, 1131,  1132, 1133, 1134, 1135, 1136,  1137,
			1138, 1139, 1140, 1141, 1142, 1143,  1144, 1145, 1146, 1147, 1148,  1149, 1150, 1116, 1152, 1151,  1118,
			1120, 1122, 1123, 1124, 1125, 1126,  1127, 1128, 1129, 1130, 1131,  1142, 1144, 1146, 1148, 1150,  1153,
			1117, 1119, 1121, 1132, 1133, 1134,  1135, 1136, 1137, 1138, 1139,  1140, 1141, 1143, 1145, 1147,  1149,
			1154, 1151, 1152, 1153,  1154, 139, 195,  1155, 1625, 140, 196,  503, 1156, 165,  171, 603, 1157,  1638,
			1159, 1160, 1161, 1162, 1163, 1168,  1074, 1157, 1159, 1160, 1161,  1163, 1164, 1165, 1166, 1167,  1170,
			1839, 1074, 1170, 1167, 1166,  1168, 1171, 3, 4,  14, 20, 21, 26,  27, 36, 47, 48,  49, 50, 51, 52,  53,
			54, 65, 66, 76,  96, 123, 207, 221,  226, 227, 228, 229,  230, 231, 232, 233,  234, 235, 236, 237,  238,
			239, 240, 241, 242,  243, 244, 245, 246,  247, 248, 249, 250,  251, 252, 253, 254,  255, 270, 271,  278,
			384, 385, 394, 398,  399, 414, 415, 469,  474, 476, 477, 478,  501, 502, 507, 646,  651, 653, 654,  655,
			656, 660, 674, 683,  684, 688, 692, 707,  714, 719, 720, 721,  723, 731, 732, 742,  757, 758, 773,  794,
			813, 837, 838, 845, 883, 894,  909, 915, 916, 923, 931, 989,  1009, 1020, 1044, 1069, 1070, 1071,  1072,
			1073, 1074, 1116, 1117, 1118, 1119,  1120, 1121, 1122, 1123, 1124,  1125, 1126, 1127, 1128, 1129,  1130,
			1131, 1132, 1133, 1134, 1135, 1136,  1137, 1138, 1139, 1140, 1141,  1142, 1143, 1144, 1145, 1146,  1147,
			1148, 1149, 1150, 1152, 1153, 1154,  1160, 1161, 1172, 1173, 1174,  1175, 1177, 1178, 1179, 1183,  1184,
			1185, 1186, 1187, 1188, 1190, 1191,  1192, 1194, 1195, 1196, 1438,  1439, 1440, 1442, 1443, 1444,  1445,
			1458, 1459, 1469, 1511, 1529, 1530,  1531, 1532, 1534, 1535, 1536,  1537, 1538, 1539, 1540, 1541,  1542,
			1543, 1544, 1545, 1546, 1547, 1548, 1549, 1551, 1642,  1176, 141, 197, 313, 530, 621, 1045, 1182,  1189,
			1193, 1197, 1198, 1344, 1345, 1346,  1347, 1349, 1351, 1353, 1752,  1177, 1178, 1179, 1797, 1349,  1350,
			1180, 1351, 1352, 1181, 1353, 1354, 622, 862, 863, 1180, 1181, 1197, 1346, 1348, 1350, 1352, 1354, 1182,
			201, 515, 1183, 1184, 1185, 1800, 1186, 1187, 1188, 1799, 467, 1189, 1190, 1191, 1192, 1798, 310,  1216,
			1194, 1195, 1196, 1177, 1183, 1186, 1190, 1194, 1198, 123, 223, 256, 312, 398, 466, 507, 746, 808,  809,
			810, 811, 1059, 1414,  1626, 1647, 5, 7,  12, 231, 244, 623,  1097, 1125, 1134, 8,  12, 28, 33, 67,  69,
			74, 232, 245, 625,  1098, 1126, 1135, 70,  74, 272, 274, 281,  275, 281, 388, 391,  246, 386, 388,  392,
			1099, 1141, 1142, 233, 247,  416, 418, 423, 627,  1100, 1127, 1136, 419, 423,  234, 248, 629, 733,  735,
			740, 1101, 1128, 1137, 736, 740,  235, 249, 631, 839, 841, 850,  1102, 1143, 1144, 1415, 236, 250,  632,
			842, 850, 1103, 1145, 1146, 1415,  237, 251, 633, 884, 886, 891,  1104, 1129, 1138, 887, 891, 917,  919,
			926, 920, 926, 238, 252,  635, 1105, 1130, 1139,  1162, 1164, 1169, 1165,  1169, 1463, 1466, 253,  1106,
			1147, 1148, 1461, 1463, 1465, 142,  198, 224, 503, 700, 987, 1416,  1557, 1417, 1418, 1419, 1420,  1421,
			1422, 1423, 1424, 1425, 1426, 1427,  1428, 1429, 1430, 1431, 1432,  1622, 1590, 1433, 1434, 1435,  1436,
			1437, 1437, 743, 805, 1438, 1439, 1440, 902, 1427, 1441, 1078, 1078, 1078, 398, 1441, 1442, 1443,  1444,
			1445, 1651, 1863, 977,  1359, 1360, 1361, 1362,  1363, 1364, 1365, 1366,  1367, 1368, 1369, 1370,  1371,
			1450, 1451, 1452, 297,  1296, 1356, 1365, 1446,  1297, 1357, 1366, 1447,  1298, 1358, 1367, 1448,  1299,
			1355, 1356, 1357, 1358,  1368, 1446, 1447,  1448, 1449, 296,  1369, 1450, 1370,  1451, 1371, 1452,  143,
			1453, 1453, 1607, 1676, 1068, 1454, 45, 856, 862, 1868, 1455, 1456, 1457, 1458, 1459, 1460, 1460,  1461,
			1462, 1467, 60, 122, 127,  261, 288, 343, 511,  692, 727, 811, 882, 948,  1067, 1091, 1175, 1445,  1456,
			1457, 1458, 1459, 1464, 1465, 1466,  1467, 1468, 1469, 1470, 1471,  1472, 1532, 1537, 1541, 1545,  1549,
			1468, 1469, 52, 53, 318, 430, 756, 1470, 1471, 254, 1107, 1149, 1150, 1462, 1464, 1472, 1872, 350, 1375,
			1402, 1473, 114, 351,  352, 353, 354,  706, 1372, 1373, 1374,  1375, 1376, 1474,  351, 1475, 352,  1476,
			353, 1376, 1477, 1478, 354,  355, 356, 1372, 1377,  1378, 1402, 1479, 350,  355, 1373, 1377, 1480,  356,
			1374, 1378, 1481, 357, 1382, 1403, 1482, 358, 359,  360, 1379, 1380, 1381, 1382, 1383, 1483, 358,  1484,
			1485, 359, 1383, 1486, 1487, 360,  361, 362, 1379, 1384, 1385, 1403,  1488, 357, 361, 1380, 1384,  1489,
			362, 1381, 1385, 1490, 363, 1386,  1404, 1491, 364, 365, 366, 1386,  1387, 1388, 1389, 1390, 1492,  364,
			1493, 1494, 365, 1390, 1495, 1496,  366, 367, 368, 1387, 1391, 1392,  1404, 1497, 363, 367, 1388,  1391,
			1498, 368, 1389, 1392, 1499, 369, 1393, 1405, 1500,  370, 371, 372, 1393, 1394, 1395, 1396, 1397,  1501,
			370, 1502, 1503, 371, 1397,  1504, 1505, 372, 373,  374, 1394, 1398, 1399,  1405, 1506, 369, 373,  1395,
			1398, 1507, 374, 1396, 1399, 1508, 1509, 375, 1406,  1410, 1500, 376, 377, 378, 1407, 1408, 1409,  1410,
			1411, 1501, 376, 1502, 1503, 377,  1411, 1504, 1505, 378, 379, 380,  1406, 1407, 1412, 1413, 1506,  375,
			379, 1408, 1412, 1507, 380, 1409, 1413, 1508, 144,  199, 312, 603, 128, 224, 320, 696, 908, 1510,  1612,
			1834, 1512, 1513, 1525,  80, 100, 211, 402,  663, 677, 761,  776, 797, 816, 897,  934, 992, 1023,  1514,
			1554, 1720, 1515, 1516,  1515, 1519, 1522, 1523,  1703, 1848, 605, 1792,  1519, 1520, 1521, 1521,  1522,
			605, 1523, 1524, 1762, 786, 1431, 1828, 1414, 1511,  1514, 1694, 1704, 1526, 1527, 84, 1432, 1528,  239,
			255, 516, 519, 535, 573,  588, 604, 624, 626,  628, 630, 634, 636, 1131,  1140, 1529, 1530, 1531,  1532,
			1533, 1534, 1535, 1536,  1537, 1538, 1539,  1540, 1541, 1542, 1543,  1544, 1545, 46,  47, 54, 290,  315,
			427, 753, 1546, 1547, 1548, 1549, 909, 1550, 1689, 1552, 1553, 1554, 1724, 1555, 1554, 1555, 1557, 1558,
			1560, 1561, 1739, 1855, 615, 1793, 1558, 1559, 1559, 1560, 615, 1561, 1766, 1551, 1553, 1708,
		};

		static const double quantity[size] = {
			1, -1, 3, 3, 1, 6, -1,  -4, -5, -6, -4, -2, 4, 4,  4, 4, -6, -3, -6, 1, 3,  6, 4, -1, 3, 6, -1, -1,  1,
			1, -4, -3, -1, -4, -1, 2,  -6, -6, -4, -1, -1, -1,  -1, -1, -1, -16, 2, 4, 1,  6, 1, 1, -1, 4, -1,  -6,
			1, 4, 16, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, -1, -1,  1, 1, -1, -1, -9, -6, 1, -1, 1, 3,  3,
			1, 6, 1, -3, -6, 6, 4,  -1, -6, -4, -2, 2, 2, -2,  -5, -6, -3, -6, -6, 1, 1,  3, -2, 6, 4, 2, 1, 1,  1,
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1, 1, 1, 1, -1,  -4,
			-1, 1, 1, -1, -10, 1, 1, 1, 1, -6,  -1, -15, 1, 1, 1, 1, 1, 1, 3,  3, 1, 6, -1, -4, -5, -6, -4, -2,  4,
			4, 4, 4, -6, -3, -6, 1, 3, 6, 4, -1, 3, 1, 1, 3,  8, 4, 8, 8, -1, -1, -1, -1, -1, -1, -12, 3, 1, 1,  8,
			8, -6, 16, 8, 8, 8, -1, 1, -6, -2, -18, 1, -3, -6, -6, -3, -8, -4, -1, -3, -2, -3, -1, -2, -1, -1,  -1,
			-1, -1, -1, -1, -1, -1, -1,  -1, -1, 6, 2, 4, 1,  6, 1, 1, 2, -1, -1, -1,  -1, -1, -1, -1, -1, -1,  -1,
			-1, -1, -1, -1, -1, -1, -1, -1, -1,  -1, 1, 1, 3, 8, 4, 8, 8, -1,  -1, -1, -1, -1, -12, 3, 1, 1, 1,  1,
			-1, -1, 1, 8, 8, -6, 16, 8, 8,  8, -1, 1, -6, -2, 1, -1, -1, -1,  -1, -1, -1, -1, -1, 1, 1, -1, 1,  -1,
			-1, -1, -1, 1, -3, -3, -3, -3, -1, -1, 0, -4, 0, 0, 0, 1, 1, 1, 1, -1, -1, -1, -1, 1, 1, -1, 1, 1,  -1,
			4, 4, 4, 4, -1, -1, -1, -1, -1,  -1, -1, -1, -1, -1, -1, -1, -1, -1,  -1, -1, -1, -1, -1, 1, 1, 6,  -1,
			-1, -1, -1, -1, 1, 1, 1,  -4, -3, 1, 10, -1, 1, -6,  -6, -1, -1, -1, 2, 4, 1,  6, 1, 1, 1, 3, 8, 4,  8,
			8, -1, -1, -1, -1, -1, -12, 3, 1,  1, -1, -1, -1, -1, -1, -1, -1,  -1, -1, -1, -1, -1, -1, -1, -1,  -1,
			-1, -1, -1, 1, 8, 8, -6, 16, 8, 8, 8, -1, 1, -6, -2,  -18, 1, 1, 1, 1, 0, -1, 1, 1, 1, 1, -1, 1, 1,  1,
			1, 1, 1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1, 1, 1,  -1,
			-1, -1, -1, -1, -1, 1, -1, -1, -1,  -1, -1, -1, -1, -1, -1, -1, -1,  -1, -1, -1, -1, 0, 0, -1, -1,  -1,
			-1, -22, 1, 1, 1, 1, 1,  -1, 1, -2, -2, -2, 1,  -2, -2, -2, -2, -2, -2, -2,  -2, -2, -1, 1, -1, 1,  -1,
			1, -1, 1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, -1, 1, 1, 3, 3, 1, 6, -1,  -4,
			-5, -1, -6, -4, -2, 4, 4,  4, 4, -2, -6, -3, -6, -6,  1, 1, 3, 6, 4, 2, -1,  3, -1, -1, -1, -1, 1,  -1,
			1, 1, 1, -1, -1, -1, -1,  -1, -1, -1, -1, -1, 1, 1,  1, 1, 1, 1, 1, 1, 1,  -1, -14, 1, 1, 4, 1, -1,  1,
			1, 1, 1, 1, 1, 1, 1, -6, 1, 1, 1, -6, 1, -8, 1,  1, 4, 1, 1, 1, 1, 1, 1, -1, -1, 1, -4, 1, -1, -4,  -1,
			-10, 1, 1, -1, -1, -6, -1, -1, -1,  -1, -1, -1, -1, -1, -1, -1, -1,  -1, -1, -1, -1, -1, 9, -9, -1,  1,
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, -1, -1,  -1,
			-15, -15, -10, -15, -15, -1, 1, -1, -1, -1, -1, -1,  4, 1, -3, -1, -3, -1, -6, -1, -6, -1, -1, -1,  -1,
			-1, -1, -1, -1, -1, -1, -8, -4, -1, -1, -1, -1, -1,  -3, -2, -3, -1, -2, -1, -2, 6, 2, 4, 1, 6, 1,  -1,
			-1, -6, -6, -2, -7, -7, -1, -1, -1,  -1, -6, -4, -4, -4, -4, -1, -1,  -1, -1, -1, 2, 6, 1, -1, -1,  -1,
			1, -1, -1, 1, -1, -1, -1, -1, -1, -1,  -1, 1, 1, 1, 1, 1, 1, 1, 1, 8,  1, 6, 1, 5, 1, -1, -1, 1, 6,  8,
			18, -1, 1, -3, -4, -4, -1,  -1, -1, -1, -1, -1, -1,  4, -1, 3, -1, 4, 4, -1,  -1, -9, -6, -6, 1, 1,  1,
			9, 9, -3, -2, -1, 2, -1, -1, -1, 1, 1, 1, 1, 1, 1,  1, -1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 1, 6, 3, -1,  -6,
			-6, -3, -4, -8, -4, -1, -6,  -4, -2, 4, 4, 4, 4,  -2, -6, -3, -6, -6, -4,  -2, -8, -2, -8, -3, -6,  -4,
			-2, -1, -3, -2, -3, -1, -2,  1, 3, -2, -2, -7, 6,  -3, -4, 4, -3, -4, -1, -4,  -3, -3, 2, 1, 1, 1,  -6,
			4, -3, -6, 4, -1, -1, -1, -1, -2, 6, 8, 2, -1, 4, 4, 1, -1, -6, 4, 1, -6, 4, 1, 1, 3, 8, 4, 8, -1,  -1,
			2, -1, -1, -1, -12, 3, 1, 1, 8, -6, 16, 8, 8, -1,  1, -6, -2, 1, -1, -1, 1, 1, -1, 3, 3, 1, 6, -1,  -4,
			-5, -6, -4, -2, 4, 4, 4, 4, -6, -3,  -6, 1, 6, 4, -1, 3, 1, 1, -6, -1,  -1, 2, 4, 1, 3, 1, 1, 1, 1,  1,
			6, 2, 2, 2, 4, 1, 1, 1, 6, 1,  1, 1, -1, -3, -1, -6, -1, -6, -1,  4, 1, 1, -1, -1, -1, -4, -1, -1,  -1,
			-1, -1, -1, -1, -1, -1, 6,  2, 2, 2, 2, 4, 1, 1,  1, 1, 6, 1, 1, 1, 1,  -1, -3, -1, -6, -1, -6, -1,  4,
			1, 1, 1, 6, -7, -7, -7, 9, -3,  -9, -4, -8, -5, -2, -7, -3, -1, -2,  -7, -2, -7, -7, 1, 1, -7, -1,  -1,
			-1, -1, -7, -7, -7, -7, -7, -7, -7, -7, -7, -7, -7,  -7, -7, -1, -1, -1, 1, -1, 1, 1, -1, 1, 1, -1,  1,
			1, -1, 1, 1, -1, 1, 1, -1, 1, 1,  -1, 1, -1, 1, -1, 1, 1, -1, 1,  1, -1, 1, -1, 2, -6, -6, -1, -4,  -1,
			-1, -1, -1, -1, -1, -16, 2, 4, 1, 6, 1, -2, 2, -9, 1, -1, 9, -9, 1, -1, 1, -10, 1, 1, 4, -1, 1, 1,  -1,
			-1, 0, 1, -1, -1, 1, 0, -9, 9, 3, -1, -1, 0, -1, -1,  0, 0, 1, 1, 1, 1, -1, 0, 0, 0, 0, -1, -9, 9,  -1,
			0, 0, 1, 0, 0, -1, -1, 0, 1, 0, 0, 0, 0, 0, 1, 1,  -1, -1, 0, 0, -1, 0, 1, 0, 0, 0, 0, 0, 0, -1, 1,  0,
			1, -1, 0, 1, 0, -1, 0, 0, -1, 1,  1, 1, -1, -1, 0, 1, -1, -1, -1,  1, 1, -5, -8, -8, -1, -1, 9, -9,  1,
			1, 1, -7, -4, -5, -9, 1, -36, -1,  -3, 1, 1, -1, -4, -5, -14, -8, -8,  -16, 1, 1, 1, -1, 1, -1, -1,  1,
			1, 1, 1, 1, -7, 1, -13, 1, -14, -12, -7, -3, -8, 1, -1, 1, -1, 1, -4, 1, 1, -5, 1, -3, 1, 1, 1, 1,  -1,
			1, -1, -1, 1, -3, -1, -1, -3, -4, 1,  1, -3, -1, 1, -2, -1, 1, -3, 1,  1, 1, 1, 1, 1, 1, 1, -1, -1,  1,
			-2, 1, -3, 1, -2, 1, -3, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, 1, -3, -7, 1,  -5,
			-4, 1, -7, 1, -6, -5, -6, 1, -9,  -1, 1, -1, -1, 1, -1, -1, 1, -4,  -5, -1, -20, 1, 1, 1, 1, -2, 1,  1,
			1, 1, 1, -1, -1, -1, -1, -1, -1,  -1, -1, -1, -1, -1, -1, -1, -1,  -1, -1, -1, -1, -1, -1, -1, -1,  -1,
			-1, -1, -1, -1, -1, -1, -1, -1, -1, 1,  1, 1, 1, 1, -3, 1, 1, 1, 1,  1, 1, -3, -2, 1, -1, 1, -1, 1,  1,
			1, -1, -1, -1, -1, 1, -1, -1, -1, -1, -1, -1, -1,  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,  -1,
			-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,  -1, 1, -1, -1, -1, -1, 1, -36, 1, -1, -2, -3,  -4,
			1, -12, -5, -13, -2, -4, -2, -5,  -1, -1, -1, -3, -3, -1, -1, -1,  -1, -1, -1, -1, -1, -1, -1, -1,  -1,
			-1, -1, -1, -1, -1, -5,  -5, -5, -5, -5, -5, -5,  -5, -5, -1, -1, -1, -1,  -1, -1, -1, -1, -1, -1,  -1,
			-1, -1, -1, -1, -1, -3,  -3, -3, -3, -3, -1, -1,  -1, -1, -1, -1, -1, -1,  -1, -1, -1, -1, -5, -5,  -3,
			-6, -1, -3, 1, -3, -2, 1, -36, 1, 1,  -12, -8, -1, 1, -1, 0, 1, 1, 0,  1, 1, 1, 1, 4, 1, 1, -6, -6,  4,
			-1, -1, -1, 1, 1, 4, -4, -1, -1, -1,  -1, -1, 2, 2, 6, 1, 1, 1, -1,  -1, 1, -1, 1, 1, 1, 1, 4, -1,  -3,
			-4, -4, -1, -1, -1, -1, -1,  -1, 4, -1, -1, 4, 4,  -1, -1, 4, -3, -6, -1, 4,  -1, -1, -1, -2, 6, 8,  2,
			-1, 4, 4, 1, -1, 1, -1,  -1, -1, -24, 1, -1, -1,  -1, -1, -1, -1, -1, -1,  -1, -1, -1, -1, -1, -1,  -1,
			-1, -1, -1, -1, 1, 1, 3, 3, 3,  1, -1, -6, -15, -1, 1, -1, 1, 1,  1, 1, 1, -1, -2, -2, -2, -2, -1,  10,
			-26, -26, -30, -24, 1, 1, 1,  -1, 1, 1, -1, 1, 1,  1, -1, -1, -1, -1, -1,  -1, -1, -1, -1, -1, -1,  -1,
			-1, -1, -1, -1, -1, -1, -1, -5, -8, -8, -8, -8, -8,  -8, -8, -3, -3, -3, -3, -7, 1, 1, -3, -6, -8,  -8,
			-8, -8, -8, -8, -8, -8, -8,  -8, -1, -8, -8, -8, 4,  3, 4, -4, 1, -9, -8,  -8, -8, -8, 16, -8, -8,  -8,
			-8, -8, -8, -8, -8, -8, -8, -8, -8,  -11, 1, -1, 1, -1, -3, 1, 1,  -1, -1, -1, -1, -1, -1, -1, -1,  -1,
			-1, -4, 1, -1, -4, 1, 1, 1, 1,  -9, 9, 1, -1, -8, -3, -4, -8, -5,  -2, -7, -3, -6, -1, -2, -2, -4,  -3,
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1,  -9, 9, -8, -8, -1, 1, -1, 1, -1, 1,  -1, 1, 3, -1, 1, -1, 1, -1, 1,  -1,
			1, -1, 1, 6, -1, 1, -1, 1, 1, -6, -6, -4, -1, -1,  -1, -1, -1, -1, -16, 2, 4, 1, 6, 1, -4, -4, -4,  -4,
			-4, -4, -2, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -10, 1, 3, 8, 4, 8, -1, -1, 1,  -1,
			-1, -1, -12, 3, 1, 1, 8, -6, 16, 8, -1, 8, 1, -6,  -2, -18, 1, 1, 3, 8, 4, 8, -1, -1, -1, -1, -1,  -12,
			3, 1, 1, 8, -6, 16, 8, -1, 8, 1, -6, -2, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, -1, -1, -1, -1,  -5,
			1, -8, -8, -8, -8, -8, -8, -8, 1, -8, -8, -1, -8,  -8, -8, -8, -8, -8, -8, -1, -8, -1, -1, -8, -8,  -8,
			1, -1, -1, -1, -1, 1, 1,  -1, -4, 4, -1, -3, -3,  -3, -3, -1, -4, -1, -1,  -1, -1, -1, -1, -1, -1,  -1,
			-1, -1, -1, -1, -1, -1,  -1, -1, -1, -1, -1, -1,  -1, -1, -1, -1, -1, -1,  -1, -1, -1, -1, -1, -1,  -1,
			-1, -1, 1, 1, -1, 1, 1, -1, -1, 1, 1, 1, -9, -1, -1, -1, -1, -1, 1, 1, 1, 16, -3, 1, -1, -1, 1, 1,  -1,
			1, 1, 3, -1, 1, 1, -1, 1, -6, -4, -5, -3, -7, -1, -4, -5, -1, -6, -1, 1, 1, 1, -2, -5, -3, -6, -9,  -4,
			-8, -6, -5, -2, 9, 1, -7, -1, -3, -1, -2, -4, -5,  -1, -1, -1, -1, -6, -2, -1, -1, -1, -1, -2, -2,  -2,
			-2, -1, -1, -1, -1, -1, -4, -4, -4, -1, 1, 1, -2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, -9, 9,  -8,
			-8, -1, -1, 1, 1, -1, 1, 1, -1, 1, 1, 1, 1, 1, 1,  1, 1, -1, 3, 3, 1, 6, -1, -4, -5, -6, -4, -2, 4,  4,
			4, 4, -6, -3, -6, 1, 3, 6, 4, -1, 3, -1, 1, 3,  1, 1, 1, -1, -1, -1, -1, -1, 2, -1, -1, -1, 1, -4,  -8,
			-5, -7, -7, -6, 1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,  3, 8, 4, 8, -1, -1, -1, -1, -1,  -12,
			3, 1, 1, 8, -6, 16, 8, -1, 8, 1,  -6, -2, 1, 1, 3, 8, 4, 8, -1,  -1, -1, -1, -1, -12, 3, 8, -6, 16,  8,
			-1, 8, 1, -6, -2, 1, 1, 1, -1, -1, -1, 1, 1, 3,  8, 4, 8, -1, -1, -1, -1, -1, -12, 3, 1, 1, 8, -6,  16,
			8, -1, 8, 1, -6, -2, 1, 1, 1,  1, -1, -3, -1, -1, -1, -1, -3, -3,  -3, -3, -1, -1, -4, -3, -3, -3,  -4,
			-3, -1, 1, 1, 1, 1, 1, 1, 3, 8, 4, 8, -1, -1, 2, -1, -1, -1, -12, 3, 1, 1, 8, -6, 16, 8, -1, 8, 1,  -6,
			-2, 1, 1, -1, -1, -4, 1, 1, 1, 3, 3, 1, 6, -3, -3, -1, -1, -4, -4, -3, -3, -6, -6, -3, -4, -8, -4,  -4,
			-2, -8, -2, -5, -1, -6, -4,  -2, 4, 4, 4, 4, -2,  -6, -3, -6, -6, -8, -3,  -6, -4, -2, -1, -3, -2,  -3,
			-1, -2, 1, 1, -1, 3, -2, -2, -7, -3, -4, 6, 4, 2,  -3, -3, -1, -1, 3, -4, -3, -3, 1, 1, 1, -9, -1,  -1,
			1, -4, 1, 1, -1, -1, 1,  -1, -2, -1, -1, 2, 3, 1,  1, -6, -6, -1, -1, -1, -1,  2, 4, 1, 6, 1, 2, 4,  1,
			6, 1, -6, -6, 1, 1, -1, -1, -1, -1, -1, 6, 2, 4,  1, 6, 1, -3, -6, -6, 4, -1, -1, -1, 1, 1, 1, -1,  -7,
			1, -8, 1, -1, 1, -4, -6, -6, -1, -1, -1, -1, 6, -2,  2, 4, 1, 6, 1, -1, -1, -9, -2, -22, 1, 1, -4,  -2,
			-2, 1, 1, -1, 1, 1, 1, 1, -1, -9, 1, 9, -1, -1,  -1, -1, -1, -1, -1, -1, -1, 1, 1, 1, -4, 1, 1, 1,  -1,
			-1, -1, -1, -1, -1, -1, -1, 2, 4, 1, 1, 1, 1, 1,  1, -1, 3, 3, 6, -1, -4, -5, -4, -4, -2, -4, 4, 4,  4,
			4, -6, -3, -6, -6, 1, 6, 4, -1, 3, 1, -3, -4, -8, -1, -1, 1, 1, 3, 8, 4, 8, -1, -1, 1, -1, -1, -1, -12,
			3, 1, 1, 8, -6, 16, 8, -1, 8, 1, -1, -1, 1, -6, -2, 1, -1, -1, -1, 1, 1, 1, 4, -1, -3, -4, -4, -1,  -1,
			-1, -1, -1, -1, 4, -1, -1, 4, 4,  -1, -1, 4, -3, -6, -1, 4, -1, -1,  -1, -2, 6, 8, 2, -1, 4, 4, 1,  -1,
			-9, 1, 1, -4, 1, 1, 3, 1, -2, 2, 3, 1, -1, 1, 1,  3, 3, 1, 6, -2, -1, -4, -5, -1, -6, -4, -2, 4, 4,  4,
			4, -2, -6, -3, -6, -6, 1,  1, 3, 6, 4, 2, -1,  3, -1, -1, -1, -1, -1, -1,  -3, -2, -2, -2, -2, -1,  -1,
			-8, -9, 3, -24, -24, -1, -1, 1, 3, 8, 4, 8, -1, -1,  2, 1, -1, -1, -1, -12, 3, 1, 1, -1, 8, -6, 16,  8,
			-1, 8, 1, -1, -1, 1, -6,  -2, 1, 1, 1, 1, 1,  -1, -1, -6, -6, -6, -3, -4,  -8, -6, -4, -4, -2, -8,  -2,
			-8, -3, -6, -4, -2, -1, -3,  -2, -3, -1, -2, 3, -4, -4,  2, 4, -6, 1, -1, -1, 4,  2, 2, 4, 1, 1, 4,  1,
			4, -4, -1, -2, -3, -6, -6, -1, -1, -1, -1, -1, 1, -1,  -1, -1, 6, 2, 2, 2, 4, 1, 1, 1, 6, 1, 1, 1,  -1,
			-3, -6, -6, 4, 1, 1, -1, -1, -1, 1, 1, -2, 6, 2,  2, 4, 1, 1, 6, 1, 1, -1, -1, -1, -4, -1, -1, -1,  -1,
			-1, 4, 1, -3, -1, -6, -1, -6,  -1, 6, 2, 2, 4, 1, 1,  6, 1, 1, 4, -6, 1, -1,  -1, 4, 2, 2, 4, 1, 1,  4,
			-6, 1, -1, -1, 4, 2, 2, 4, 1, 1, 4, -3, -6, -6,  -1, -1, -1, -1, -1, -1, -1, -1, 1, -4, 6, 2, 2, 4,  1,
			1, 6, 1, 1, -1, -1, 1, -1, -7, -1,  -26, -1, 0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 1, -6, -6, -1, -1, -1, -1, 2, 1, -6, -1, -1, 4,  1,
			-5, -8, -8, -4, -9, -4, 2, 4, 1, 6,  1, -1, -4, -1, -1, -6, 1, 1, 4,  4, 1, 1, 3, 8, 4, 8, -1, -1,  -1,
			-1, -1, -12, 3, 1, 1, 8, -6, 16, 8, -1, 8, 1, -6,  -2, 1, 4, -6, -1, 0, -1, -1, -1, -3, 1, 6, 2, 4,  1,
			-1, -3, -3, -3, -3, -2, 1, -1, -1, -4, -12, -1, 0,  1, -4, -2, -6, -1, -1, 0, -1, -1, -1, 1, 4, 1,  -1,
			2, 1, 1, 2, 4, 1, -1, -4, -1, -1, -2, -4, -9, 1,  1, 1, 16, 1, -1, 9, -9, -1, 1, -1, 9, -9, -1, 1,  -1,
			9, -9, -1, 1, 1, 1, 1, 1, 3, 8, 4, 8, -1, -1, 2, -1, -1, -1, -12, 3, 1, 1, -1, -1, -1, -1, -1, -1,  -1,
			-1, -1, -1, -1, -1, -1, -1,  -1, -1, -1, -1, 1, 1,  -6, -6, -1, -1, -1, 2, 4,  1, 6, 1, -1, -4, 4,  -1,
			1, -6, -6, -4, -1, -1, -1, -1, -1, 2, 4, 4, 4, 1,  6, 1, 8, -6, 16, 8, -1, 8, 1, -1, -1, 1, -6, -2,  1,
			-1, -1, -1, -1, -1, -1,  -1, -1, -1, -1, -1, -1,  -1, -1, -1, -1, -2, -1,  -1, -1, -1, -1, -1, -1,  -1,
			-1, -1, -1, 1, 1, -1, -1, -1, -1, -1, -2, -1, -1,  -1, -1, 9, -9, -4, -1, -1, -4, 2, -1, 1, 1, -1,  -1,
			-3, 1, -2, -3, -1, 1, 1,  -1, 1, -1, 1, -4, -2, 6,  2, 4, 1, 6, 1, -3, -6,  -6, 1, -1, -1, -1, -1,  -1,
			-9, 9, 1, 1, -1, -32, 1, -1, -6, -13, -4, -4, -4,  -4, -4, -4, -4, -1, -4, -4, -4, -4, -4, -4, -4,  -4,
			-4, -4, -4, -4, -4, -4, -4, 8, -1, -1, 1, -6, -6, -4,  -1, -1, -1, -1, -1, -1, 2, 4, 4, 4, 1, 6, 1,  6,
			-1, -1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, -2, 3,  1, 1, 1, -1, -1, -1, -1, 1, -1, -1, -1, -9, 9, -1,  1,
			2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,  1, 1, -6, -1, -1, 2, 4, 1, 1, -6,  -1,
			-1, 2, 4, 1, 1, -6, -1, 2, 4, 1,  -3, 1, -1, -1, 2, 1, 1, -3, 6, -4,  1, 1, 1, 1, 1, 1, 1, 1, 1, 1,  1,
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, -1, -1, 1, -1, -1, -1, -1,  -1,
			-1, -1, -1, -1, -1, -1,  -1, -1, -1, -1, -1, -1,  -1, -1, -1, -1, -1, -1,  -1, -1, -1, -1, -1, -1,  -1,
			-1, -1, -1, -1, -1, -1, -1, 4, 4, 4, -1, -1, 1, 3, -1, -1, -1, 1, 1, -1, 1, 1, -1, 3, 3, 1, 6, -1,  -4,
			-6, -5, -6, -4, -2, 4, 4, 4, 4, -6, -3, 1, 3, 6,  4, -1, 3, 1, -2, -4, -2, -6, -1, -2, -4, -1, -6,  -6,
			-6, -6, -6, -6, -6, -6,  -2, -4, -1, -1, -3, -1,  -1, -3, -3, -3, -3, -3,  -3, -3, -3, -3, -3, -3,  -3,
			-3, -3, -3, -3, -3, -3,  -3, -3, -3, -3, -3, -3,  -3, -3, -3, -3, -3, -3,  -2, -4, -1, -2, -4, -1,  -3,
			-1, -2, -4, -2, -2, -2,  -2, -1, -2, -4, -3, -2,  -2, -2, -1, -2, -1, -1,  -1, -2, -2, -2, -2, -2,  -2,
			-2, -2, -1, -8, -2, -4,  -7, -1, -1, -1, -1, -1,  -2, -4, -1, -2, -1, -8,  -2, -4, -1, -1, -1, -1,  -1,
			-1, -1, -1, -1, -1, -1,  -1, -3, -3, -3, -3, -3,  -3, -3, -3, -3, -3, -3,  -3, -3, -3, -3, -3, -3,  -3,
			-3, -3, -3, -3, -3, -3, -3,  -3, -3, -3, -3, -3, -3,  -3, -3, -3, -3, -1, -1,  -1, -2, -4, 4, 4, 4,  4,
			-2, -2, -2, -2, -2, -2,  -2, -2, -2, -2, -2, -2,  -1, -1, -1, -1, -1, -1,  -1, -1, -1, -1, -2, -4,  -1,
			-1, -2, -2, -2, -2, -2,  -2, -2, -2, -2, -2, -2,  -2, -2, -2, -2, -2, -1,  -1, -1, -1, -1, -32, 1,  -1,
			-1, -3, 1, -1, -3, -1, -2, -6, -4, -3, -1, -1, -1, -1,  -1, -1, -1, -20, 1, 1, 1, 1, 2, 2, 4, 1, 1,  6,
			1, 1, -1, -1, -1, -6, -6, 4, 1, -1, -1, -1, -1, 1, -3,  -8, 1, 1, 1, 1, 1, 1, 1, 1, -1, 1, 1, 1, 1,  1,
			4, 1, 1, 1, 1, -3, -2, -3, -1, -2, 1, -3, -1,  -1, 9, -2, 0, -2, -4, -2, -2, -2, -2, -1, -4, -20,  -14,
			-6, -1, -4, -3, -3, -1, -4, -3, -3, -1, 3, -6, -1,  -6, -1, -4, -3, -3, -1, -4, -3, -3, -1, 3, -6,  -1,
			-4, -1, 3, 3, -1, -3, -6, -4, -1,  -4, -3, -3, -3, -3, -6, -1, -4,  -1, -4, -3, -3, -1, 3, -3, -3,  -1,
			-6, -1, -4, -4, -3, -3, -1, 3, -3, -3, -1, -6, -1,  -4, -4, -3, -3, -4, -3, -3, -1, -1, 3, -4, -3,  -3,
			3, -3, -3, -1, -6, -1, -4, -4, -3,  -3, -1, 3, -6, -1, -4, -1, 3,  -3, -3, -1, -4, -3, -3, -6, -1,  -4,
			-1, 3, 3, -1, -3, -4, -3, -3, -6, -4, -1, -1, -1, -2,  -1, 3, -1, 1, -1, 1, 1, 1, 1, 1, 1, 1, 1, 1,  1,
			1, 1, 1, 1, 1, 1, 1, -10, 1, 1,  2, 1, -1, 1, -1, -1, 4, 4, 4, -1,  -1, 1, -1, -1, 0, -1, -1, 2, 1,  1,
			1, -8, 1, -4, -1, -1, -1,  -1, -1, -1, -1, -1, -1,  -1, -1, -1, -1, -3, -6, -6,  -2, 2, 2, 2, 6, 1,  1,
			1, 4, 1, 1, 1, 6, 1, -1, -1, -1, -1, 1, -3, -6, -6,  4, -2, 2, 6, 1, 4, 1, 6, -1, 1, -5, -4, -4, 1,  1,
			-1, -1, -1, 1, 1, 1, 3, 3, 1, -1, 1, 6, 3, -1, -6, -6, -3, -4, -8, -4, -4, -2, -8, -2, -8, -3, -6,  -4,
			-2, -1, -1, -6, -4, -2, 4, 4, 4, 4, -2, -6, -3,  -6, -6, -3, -2, -3, -1, -2, 1, 3, -2, -2, -7, -3,  -4,
			6, 4, -3, -4, -3, -3, -4, -1, 2,  2, 1, 4, 1, 1, -1, -3, -6, -4,  -4, -1, -1, -1, -1, -1, -1, 1, 4,  1,
			3, 1, 4, 4, 1, 1, 4, -3, -6, 4, -1, -1, -1, 1, -2, 6, 8, 2, 1, 4, 4, 1, 1, 1, 4, 1, 1, -3, -4, -4,  -1,
			-1, -1, -1, -1, 1, 4, 1, 1,  4, 4, 1, 1, 4, -3, -6,  4, -1, -1, -1, 1, -2, 6,  8, 2, 1, 4, 4, 1, 1,  1,
			4, 1, 1, -3, -4, -4, -1, -1, -1, -1,  -1, 1, 4, 1, 1, 4, 4, 1, 1,  4, -3, -6, 4, -1, -1, -1, 1, -2,  6,
			8, 2, 1, 4, 4, 1, 1, 1,  4, 1, 1, -3, -4, -4, -1,  -1, -1, -1, -1, 1, 4, 1,  1, 4, 4, 1, 1, 4, -3,  -6,
			4, -1, -1, -1, 1, -2, 6, 8, 2, 1,  4, 4, 1, 1, 1, 1, 1, 4, -1,  -3, -4, -4, -1, -1, -1, -1, -1, -1,  4,
			-1, -1, 4, 4, -1, -1, 4, -3, -6, -1, 4, -1, -1, -1,  -2, 6, 8, 2, -1, 4, 4, 1, -1, -1, -1, -1, -1,  -3,
			-3, -2, -9, -1, 9, -20, 1, 1, 1, 1, -8, -8, -8,  -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, 3, -8,  4,
			8, 8, -1, -1, -1, -1, -12, 3, 1, 1, 8, 8, -6, 16,  8, -1, 8, 8, 1, -1, -1, 1, 1, -6, -2, -18, 1, 1,  4,
			-1, -1, 1, -3, -3, -1, -1, -1, -1, -1, -1, -1, -1, -1,  -1, -1, -1, -3, -3, 1, 1, 1, 1, 3, 1, 1, 1,  1,
			1, 1, 1, 1, 1, 1, 1, 1, -2, -2,  -2, -3, -7, -3, -4, 1, 1, 1, 1, -1,  1, -2, 1, 3, 8, 4, 8, -1, -1,  2,
			-1, -1, -1, -12, 3, 1, 1, 8, -6, 16, 8, -1, 8, 1, -6, -2, 1,
		};
	} // namespace sum
} // namespace Items

#endif // ITEMS_H
