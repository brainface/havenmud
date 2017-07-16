// Title: Durgoroth Town
// File: wall_shield.c
// Author: Tim Morris aka Morgoth@Haven
// Date: March 1998
//
// Abstract: A nosferatu wall shield
//
// Revision History: 
//

#include <lib.h>
#include <armour_types.h>
#include <size.h>
#include <armour_class.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
	armour::create();
	SetKeyName("shield");
	SetId( ({ "shield", "wall shield" }) );
	SetAdjectives( ({ "wall" }) );
	SetShort("a wall shield");
	SetLong("The shield is a large rectangle of metal about four "
					"feet tall with the emblem of the Nosferatu Crusade "
					"emblazoned on it's surface.");
	SetVendorType(VT_ARMOUR);
  SetMass(250);
  SetSize(SIZE_MEDIUM);
  SetArmourClass(ARMOUR_PLATE);
	SetValue(150);
	SetDamagePoints(600);
	SetMaterial( ({ "metal" }) );
  SetWarmth(0);
	SetRepairSkills( ([
		"armour smithing" : 4,
		"metal working" : 4,
		]) );
	SetRepairDifficulty(10);
	// SetProtection(BLUNT, 15);
	// SetProtection(SLASH, 15);
	// SetProtection(PIERCE, 15);
	// SetProtection(HEAT, 1);
	// SetProtection(COLD, 0);
	// SetProtection(SHOCK, 0);
	// SetProtection(WATER, 0);
	// SetProtection(ACID, 5);
	SetArmourType(A_SHIELD|A_WEAPON);
}
