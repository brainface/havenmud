// Title: Durgoroth Town
// File: axe.c
// Author: Tim Morris aka Morgoth@Haven
// Date: March 1998
//
// Abstract: A large Gorithim battle axe
//
// Revision History: 
//

#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
	item::create();
	SetKeyName("battle axe");
	SetId( ({"axe","weapon"}) );
	SetAdjectives( ({"battle","steel","large"}) );
	SetShort("a large steel battle axe");
	SetLong("This is a large well-crafted, steel-headed battle axe "
        	"with a hard wood handle that looks quite sharp and more "
        	"than deadly.");
	SetClass(15);
	SetDamagePoints(850);
	SetValue(350);
	SetMass(300);
	SetMaterial( ({ "metal","wood" }) );
	SetRepairSkills( ([
		"weapon smithing" : 5,
		"wood working" : 2,
		"metal working" : 5,
		]) );
	SetRepairDifficulty(10);
	SetWeaponType("hack");
	SetDamageType(SLASH);
	SetVendorType(VT_WEAPON);
}
