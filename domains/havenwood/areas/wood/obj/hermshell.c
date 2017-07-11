/* This is the shell of the hermit crab coded by Lynna on February 11, 1998
*/
#include <lib.h>
#include <damage_types.h>
#include <size.h>
#include <armour_class.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
	armour::create();
		SetKeyName( "crab shell" );
		SetShort( "a small shell" );
		SetId( ({ "shell", "crab shell" }) );
		SetAdjectives( ({ "crab", "small" }) );
		SetLong( "This crab shell is left on the shore by the "
			"hermit crabs." );
		// SetProtection(BLUNT, 6);
		// SetProtection(PIERCE, 8);
		// SetProtection(SLASH, 8);
		// SetProtection(COLD, 4);
		// SetProtection(WATER, 6);
		SetClass(3);
    SetSize(SIZE_MEDIUM);
    SetArmourClass(ARMOUR_NATURAL);
		SetMass(5);
		SetDamagePoints(50);
		SetValue(15);
		SetVendorType( VT_TREASURE );
		SetRepairDifficulty(5);
		}
