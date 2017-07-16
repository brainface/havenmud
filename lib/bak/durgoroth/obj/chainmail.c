// Title: Durgoroth Town
// File: chainmail.c
// Author: Tim Morris aka Morgoth@Haven
// Date: March 1998
//
// Abstract: A shirt of steel chainmail
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
	SetKeyName("chainmail");
	SetId( ({ "chainmail","chain","mail","armour" }) );
	SetAdjectives(({"steel","suit"}));
	SetShort("a suit of steel chainmail");
	SetLong("A well crafted suit of steel chainmail that looks "
					"stong enough to protect the wearer from all but the "
					"strongest blows.");
	SetValue(400);
	SetMass(800);
  SetArmourClass(ARMOUR_CHAIN);
  SetSize(SIZE_MEDIUM);
	SetMaterial( ({ "metal" }) );
  SetWarmth(0);
	SetRepairSkills( ([
		"armour smithing" : 5,
		"metal working" : 5,
		]) );
	SetRepairDifficulty(15);
	SetDamagePoints(900);
	SetVendorType(VT_ARMOUR);
  SetProperty("multiples", 1);
	// SetProtection(BLUNT, 10);
	// SetProtection(SLASH, 18);
	// SetProtection(PIERCE, 12);
	// SetProtection(HEAT, 0);
	// SetProtection(COLD, 10);
	// SetProtection(SHOCK, 0);
	// SetProtection(WATER, 5);
	// SetProtection(ACID, 6);
	SetArmourType( A_BODY_ARMOUR );
  }

