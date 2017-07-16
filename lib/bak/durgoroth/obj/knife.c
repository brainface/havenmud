// Title: Durgoroth Town
// File: knife.c
// Author: Arika@Haven
// Date: January 1999
//
// Abstract: A knife for Saahagoth Clerics
//
// Revision History: 
//

#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
	item::create();
	SetKeyName("knife");
  SetId( ({"knife"}) );
	SetAdjectives( ({"small"}) );
	SetShort("a small knife");
  SetLong("This is a small knife.  It's blade is made "
          "of a very dark material that seems to absorb "
          "any light.  It's handle is crafted out of "
          "some sort of bleached bone. ");
	SetClass(9);
	SetDamagePoints(850);
	SetValue(200);
	SetMass(30);
	SetMaterial( ({ "natural" }) );
	SetRepairSkills( ([
		"weapon smithing" : 3,
		"natural working" : 3,
		]) );
	SetRepairDifficulty(6);
	SetWeaponType("knife");
	SetDamageType(SLASH);
	SetVendorType(VT_WEAPON);
}
