
// Written by Vanyel
#include <lib.h>
#include <armour_types.h>
#include <size.h>
#include <armour_class.h>
#include <damage_types.h>
#include <vendor_types.h>
#include "../oil.h"

inherit LIB_ARMOUR;

static void create() {
    armour::create();
    SetKeyName("snowshoes");
    SetId( ({ "snowshoes", "shoes" }) );
    SetAdjectives( ({ "snow" }) );
    SetShort("snowshoes");
    SetLong("Shoddily made, these snowshoes don't look like they "
            "could support anything on the snow!");
    SetVendorType(VT_ARMOUR);
    SetMass(50);
    SetMaterial( ({ "wood", "leather" }) );
    SetWarmth(2);
    SetSize(SIZE_MEDIUM);
    SetArmourClass(ARMOUR_CLOTH);
    SetValue(10);
    SetDamagePoints(200);
    SetArmourType(A_BOOT);
    SetProperty("multiples", 1);
	SetRepairSkills(  ([ 
		   "wood working" : 1,
		   "leather working"   : 1,
		   ])  );
	SetRepairDifficulty(5);
}


/* Approved by Balishae on Sat Oct  4 23:43:44 1997. */

