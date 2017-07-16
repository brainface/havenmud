// Title: Durgoroth Town
// File: blood_lance.c
// Author: Tim Morris aka Morgoth@Haven
// Date: March 1998
//
// Abstract: A nosferatu blood lance
//
// Revision History: 
//

#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
	item::create();
	SetShort("a blood lance");
	SetLong("The long lance has a wooden shaft and a "
					"barbed point made of a hard red metal.");
	SetId( ({ "lance", "blood lance" }) );
	SetHands(2);
	SetClass(14);
	SetDamagePoints(1750);
	SetMaterial( ({ "metal", "wood" }) );
	SetRepairSkills( ([
		"weapon smithing" : 3,
		"wood working" : 1,
		"metal working" : 3,
		]) );
	SetRepairDifficulty(10);
	SetValue(300);
	SetWeaponType("pierce");
	SetDamageType(PIERCE);
	SetKeyName("lance");
	SetMass(130);
	SetVendorType(VT_WEAPON);
	SetAdjectives( ({ "long" }) );
}
