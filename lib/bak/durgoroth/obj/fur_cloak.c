// Title: Durgoroth Town
// File: fur_cloak.c
// Author: Tim Morris aka Morgoth@Haven
// Date: March 1998
//
// Abstract: A heavy fur cloak worn by the Durgoth guards
//
// Revision History: 
//

#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <size.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
	armour::create();
	SetKeyName("fur cloak");
	SetId( ({ "cloak" }) );
  SetAdjectives( ({"thick", "fur", "brown", "heavy"}) );  
	SetShort("a thick fur cloak");
	SetLong("A thick, heavy, warm cloak of brown fur that looks "
					"like it could protect the wearer from all but the "
					"coldest blizzard.");
	SetValue(50);
  SetArmourClass(ARMOUR_CLOTH);
  SetSize(SIZE_MEDIUM);
	SetMass(75);
	SetMaterial( ({ "natural" }) );
  SetWarmth(50);
	SetRepairSkills( ([
		"natural working" :  2,
		]) );
	SetRepairDifficulty(5);
	SetDamagePoints(200);
	SetVendorType(VT_ARMOUR);
	// SetProtection(BLUNT, 2);
	// SetProtection(SLASH, 2);
	// SetProtection(PIERCE, 2);
	// SetProtection(HEAT, 2);
	// SetProtection(COLD, 12);
	// SetProtection(SHOCK, 8);
	// SetProtection(WATER, 4);
	// SetProtection(ACID, 2);
	SetArmourType( A_CLOAK );
  }

