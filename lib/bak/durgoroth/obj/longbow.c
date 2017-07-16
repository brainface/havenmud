// Title: Durgoroth Town
// File: longbow.c
// Author: Tim Morris aka Morgoth@Haven
// Date: March 1998
//
// Abstract: A long bow used by the Durgoroth guards
//
// Revision History: 
//

#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
	item::create();
	SetKeyName("longbow");
	SetId( ({"fine longbow","longbow","fine bow","bow"}) );
	SetShort("a fine longbow");
	SetLong("The fine longbow is made of a flexible black wood "
					"with a few raven feathers fluttering at its tip.");
	SetClass(14);
	SetDamagePoints(700);
	SetValue(250);
	SetMass(100);
	SetHands(2);
	SetMaterial( ({ "wood" }) );
	SetRepairSkills( ([
		"weapon smithing" : 5,
		"wood working" : 2,
		]) );
	SetRepairDifficulty(10);
	SetWeaponType("projectile");
	SetDamageType(PIERCE);
	SetVendorType(VT_WEAPON);
}
