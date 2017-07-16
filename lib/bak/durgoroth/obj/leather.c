// Title: Durgoroth Town
// File: leather.c
// Author: Arika@Haven
// Date: March 1998
//
// Abstract: A suit of nosferatu battle armour
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
	SetKeyName("armour");
  SetId( ({ "padded leather armour", "padded armour",
            "leather armour", "armour"}) );
  SetShort("padded leather armour");
  SetLong("This simple piece of armour is made up of "
          "a layer of leather that overlays a layer of thick "
          "padding.  While not offering as much protection "
          "as most metal armours, it is much lighter and "
          "allows for much better mobility.");
	SetVendorType(VT_ARMOUR);
	SetMass(100);
  SetSize(SIZE_MEDIUM);
  SetArmourClass(ARMOUR_LEATHER);
  SetWarmth(10);
	SetValue(350);
	SetMaterial( ({ "leather", "textile"}) );
	SetRepairSkills( ([
		"armour smithing" : 3,
		"leather working" : 3,
		"textile working" : 3,
		]) );
	SetRepairDifficulty(8);
	SetDamagePoints(1000);
	// SetProtection(BLUNT, 10);
	// SetProtection(SLASH, 12);
	// SetProtection(PIERCE, 9);
	// SetProtection(HEAT, 3);
	// SetProtection(COLD, 10);
	// SetProtection(SHOCK, 2);
	// SetProtection(WATER, 3);
	// SetProtection(ACID, 8);
	SetArmourType( A_BODY_ARMOUR );
  }

