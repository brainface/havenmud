// Title: Durgoroth Town
// File: plate_mail.c
// Author: Tim Morris aka Morgoth@Haven
// Date: May 1998
//
// Abstract: A suit of very fine plate mail
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
	SetKeyName("plate mail");
	SetId( ({ "suit of mail","suit of plate","plate","mail" }) );
	SetAdjectives( ({ "full" }) );
	SetShort("a suit of full plate mail");
	SetLong("A fine suit of full plate mail. It covers "
					"the entire body of the wearer with metal plates "
					"over the vitals and chainmail over the joints. "
					"It looks like it could deflect all but the strongest "
					"and best aimed blows.");
	SetVendorType(VT_ARMOUR);
  SetMass(1250);
	SetValue(1150);
  SetSize(SIZE_MEDIUM);
  SetArmourClass(ARMOUR_PLATE);
	SetMaterial( ({ "metal" }) );
  SetWarmth(0);
	SetRepairSkills( ([
		"armour smithing" : 20,
		"metal working" : 20,
		]) );
	SetRepairDifficulty(40);
	SetDamagePoints(2000);
	// SetProtection(BLUNT, 30);
	// SetProtection(SLASH, 35);
	// SetProtection(PIERCE, 32);
	// SetProtection(HEAT, 0);
	// SetProtection(COLD, 15);
	// SetProtection(SHOCK, 0);
	// SetProtection(WATER, 10);
	// SetProtection(ACID, 15);
	SetArmourType( A_BODY_ARMOUR );
  }

