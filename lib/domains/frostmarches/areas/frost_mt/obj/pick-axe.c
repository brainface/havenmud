//
// A pick-axe
// Created by Zaxan@Haven
// 23rd of November, 1997
//

#include <lib.h>
#include "path.h"
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ITEM;
inherit LIB_DIGGING;

static void create() {
	item::create();
	SetKeyName("pick-axe");
	SetId( ({ "axe", "pickaxe", "pick-axe" }) );
	SetAdjectives( ({ "sharp", "dangerous", "pick" }) );
	SetShort("a pick-axe");
	SetLong("This pick-axe has a two very sharp tips, one at each "
		"end, that look very dangerous to the touch.");
	SetWeaponType("hack");
	SetDamageType(PIERCE);
	SetVendorType(VT_WEAPON);
	SetDamagePoints(700);
	SetValue(200);
	SetMass(50);
	SetClass(12);
	SetRepairDifficulty(15);
	SetRepairSkills( ([ "weapon smithing" : 2,
			    "wood working" : 1,
			    "metal working" : 1 ]) );
	SetMaterial( ({ "metal", "wood" }) );
}
