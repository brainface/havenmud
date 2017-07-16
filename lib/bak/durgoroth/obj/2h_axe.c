// Title: Durgoroth Town
// File: 2h_axe.c
// Author: Tim Morris aka Morgoth@Haven
// Date: May 1998
//
// Abstract: A huge two-handed Gorithim axe
//
// Revision History: 
//

#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
	item::create();
	SetKeyName("huge axe");
	SetId( ({ "battle axe","axe"}) );
	SetAdjectives( ({"two-handed","two handed","huge"}) );
	SetShort("a huge two-handed battle axe");
	SetLong("This is a huge two-handed battle axe that looks like "
					"it could easily cut a man in two, or simply crush "
					"him from the force of the blow. The axe has a handle "
					"of dark polished wood and a head of glimmering, rune "
					"etched steel with a razor sharp edge.");
	SetClass(22);
	SetDamagePoints(2000);
	SetValue(1500);
	SetMass(550);
	SetHands(2);
	SetMaterial( ({ "metal","wood" }) );
	SetRepairSkills( ([
		"weapon smithing" : 20,
		"wood working" : 5,
		"metal working" : 20,
		]) );
	SetRepairDifficulty(40);
	SetWeaponType("hack");
	SetDamageType(SLASH|BLUNT);
	SetVendorType(VT_WEAPON);
	SetProperty("history", "This fine axe belonged to the near "
		"legendary Gorithim barbarian, Dergast. He used it "
		"throughout his many years of adventuring, and named it "
		"\"The Cleaver\".");
}
