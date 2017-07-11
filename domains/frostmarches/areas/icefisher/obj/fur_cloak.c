#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <armour_class.h>
#include <size.h>
#include <vendor_types.h>
#include "../ice.h"
inherit LIB_ARMOUR;

static void create() {
	armour::create();
	SetKeyName("cloak");
	SetId( ({ "cloak", }) );
	SetAdjectives( ({ 
		"fur", "thick", "wolverine", "grey", "silvery",
		}) );
	SetShort("a thick, silvery grey fur cloak");
	SetLong("This warm, full-length cape of soft wolverine fur "
		"would be great protection against the worst of "
		"arctic storms. It even has a layer of tough, "
		"flexible willow stays inside, offering good defense "
		"against many forms of attack."
		);
        SetProperty("multiples", 1);
	SetValue(125);
	SetMass(100);
  SetArmourClass(ARMOUR_CLOTH);
  SetSize(SIZE_MEDIUM);
	SetMaterial( ({ "natural" }) );
        SetWarmth(30);
	SetRepairSkills( ([
		"natural working" :  2,
		]) );
	SetRepairDifficulty(7);
	SetDamagePoints(250);
	SetVendorType(VT_ARMOUR);
	// SetProtection(BLUNT, 2);
	// SetProtection(SLASH, 8);
	// SetProtection(PIERCE, 12);
	// SetProtection(HEAT, 2);
	// SetProtection(COLD, 12);
	// SetProtection(SHOCK, 8);
	// SetProtection(WATER, 12);
	// SetProtection(ACID, 2);
	SetArmourType( A_CLOAK );
  }


/** Approved by Laoise at Fri Jul  9 20:22:16 2004. **/
