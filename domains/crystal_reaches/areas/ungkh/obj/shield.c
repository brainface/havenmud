//Selket@Haven
//2006
#include <lib.h>
#include <armour_types.h>
#include <size.h>
#include <armour_class.h>
#include <damage_types.h>
#include <vendor_types.h>
#include <armour_class.h>

inherit LIB_ARMOUR;


static void create() {
    armour::create();
    SetKeyName("metal shield");
    SetId( ({ "shield" }) );
    SetAdjectives( ({ "metal", "dented" }) );
    SetShort("a dented shield");
    SetLong("This dented shield is a simple piece of "
    "beaten metal, but it is thick and as large as a "
    "troll's head.");
    SetDamagePoints(1000);
    SetVendorType(VT_ARMOUR);
    SetMass(400);
    SetSize(SIZE_VERY_LARGE);
    SetValue(1200);
    SetArmourType(A_SHIELD);
    SetArmourClass(ARMOUR_PLATE);
    SetMaterial( ({ "metal" }) );
    SetRepairDifficulty(15);
}
