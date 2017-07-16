
#include <lib.h>
#include <armour_class.h>
#include <armour_types.h>
#include <damage_types.h>
#include <vendor_types.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
    armour::create();
    SetKeyName("armour");
    SetId( ({ "armour" }) );
    SetAdjectives( ({ " " }) );
    SetShort("armour");
    SetLong("armour");
    SetVendorType(VT_ARMOUR);
    SetMass(20);
    SetMaterial( ({ "natural" }) );
    SetArmourClass(ARMOUR_NATURAL);
    SetWarmth(0);
    SetValue(0);
    SetDamagePoints(1000);
    SetArmourType(A_ARMOUR);
    SetSize(SIZE_LARGE);
}

