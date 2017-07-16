// Title: Durgoroth Town
// File: brass_knuckles.c
// Author: Tim Morris aka Morgoth@Haven
// Date: March 1998
//
// Abstract: Brass knuckles, a medium blunt melee weapon
//
// Revision History: 
//

#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
	item::create();
	SetKeyName("brass knuckles");
	SetId( ({"brass knuckles","set","knuckles","weapon"}) );
	SetAdjectives( ({"brass"}) );
	SetShort("a set of brass knuckles");
	SetLong("The set of heavy dented brass knuckles is used to "
					"deliver a punishing punch in a brawl.");
	SetClass(14);
	SetDamagePoints(800);
	SetValue(80);
	SetMass(10);
	SetMaterial( ({ "metal" }) );
	SetRepairSkills( ([
		"weapon smithing" : 3,
		"metal working" : 3,
		 ]) );
	SetRepairDifficulty(8);
	SetWeaponType("melee");
	SetDamageType(BLUNT);
	SetVendorType(VT_WEAPON);
}
