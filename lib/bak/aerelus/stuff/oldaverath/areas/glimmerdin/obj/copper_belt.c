#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
#include <armour_types.h>
#include <size.h>
#include <armour_class.h>

inherit LIB_ARMOUR;

static void create() {
    armour::create();
    SetKeyName("copper-studded belt");
    SetId( ({ "belt"}) );
    SetAdjectives( ({ "copper", "studded", }) );
    SetShort("a copper-studded belt");
    SetLong("The thick leather belt is augmented with copper studs "
            "to add extra protection.");
    SetVendorType(VT_ARMOUR);
    SetArmourType(A_BELT);
    SetArmourClass(ARMOUR_REINFORCED);
    SetMass(20);
    SetValue(80);
    SetDamagePoints(400);
    SetSize(SIZE_SMALL);
}
