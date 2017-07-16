// Title: Durgoroth Town
// File: nosf_armour.c
// Author: Tim Morris aka Morgoth@Haven
// Date: March 1998
//
// Abstract: A suit of nosferatu battle armour
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
	SetKeyName("armour");
	SetId( ({ "nosferatu battle armour", "nosferatu armour",
		"battle armour", "plate armour" ,"suit"}) );
	SetShort("Nosferatu battle armour");
	SetLong("The suit of Nosferatu battle armor is comprised of "
					"heavy metal plates placed over the vital areas, combined "
					"with layers of chain mail over the rest of the body with "
					"heavy padding underneath.");
	SetVendorType(VT_ARMOUR);
	SetMass(1500);
  SetArmourClass(ARMOUR_PLATE);
  SetProperty("multiples", 1);
  SetSize(SIZE_MEDIUM);
	SetValue(650);
	SetMaterial( ({ "metal" }) );
  SetWarmth(15);
	SetRepairSkills( ([
		"armour smithing" : 7,
		"metal working" : 7,
		]) );
	SetRepairDifficulty(15);
	SetDamagePoints(1600);
	// SetProtection(BLUNT, 20);
	// SetProtection(SLASH, 25);
	// SetProtection(PIERCE, 23);
	// SetProtection(HEAT, 0);
	// SetProtection(COLD, 15);
	// SetProtection(SHOCK, 0);
	// SetProtection(WATER, 8);
	// SetProtection(ACID, 15);
	SetArmourType( A_BODY_ARMOUR );
  }

