// Title: Durgoroth Town
// File: nosf_staff.c
// Author: Tim Morris aka Morgoth@Haven
// Date: May 1998
//
// Abstract: A metal shod nosferatu staff
//
// Revision History: 
//

#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
	item::create();
	SetKeyName("staff");
	SetShort("a metal shod staff");
	SetLong("The finely crafted staff is encased in a layer of a "
		"reddish metal and looks like it would deliver quite a "
		"hefty blow.");
	SetId( ({ "metal shod staff", "metal staff", "shod staff" }) );
	SetClass(13);
	SetDamagePoints(1500);
	SetValue(400);
	SetWeaponType("pole");
	SetDamageType(BLUNT);
	SetMass(125);
	SetMaterial( ({ "wood","metal" }) );
	SetRepairDifficulty(12);
	SetRepairSkills( ([
		"weapon smithing" : 5,
		"wood working" : 4,
		"metal working" : 3,
		]) );
	SetVendorType(VT_WEAPON);
	}
