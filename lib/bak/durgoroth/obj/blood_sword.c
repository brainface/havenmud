// Title: Durgoroth Town
// File: blood_sword.c
// Author: Tim Morris aka Morgoth@Haven
// Date: March 1998
//
// Abstract: A nosferatu sword
//
// Revision History: 
//

#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
	item::create();
	SetKeyName("sword");
	SetShort("a blood sword");
	SetLong("The broad sword has a blade of a reddish metal "
					"that looks very deadly. This type of sword is the "
					"standard issue to officers and soldiers of the "
					"Saa'HaGoth crusade.");
	SetId( ({"sword", "weapon"}) );
	SetAdjectives( ({ "broad", "blood" }) );
	SetClass(16);
	SetMass(170);
	SetDamagePoints(1200);
	SetMaterial( ({ "metal" }) );
	SetRepairSkills( ([
		"weapon smithing" : 6,
		"metal working" : 6,
		]) );
	SetRepairDifficulty(12);
	SetValue(200);
	SetWeaponType("slash");
	SetDamageType(SLASH);
	SetVendorType(VT_WEAPON);
	}
