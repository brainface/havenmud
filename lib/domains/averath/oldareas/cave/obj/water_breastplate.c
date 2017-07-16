
// Water Breastplate
// Laoise
// May 2001

#include <lib.h>
#include <armour_class.h>
#include <armour_types.h>
#include <damage_types.h>
#include <size.h>
#include <vendor_types.h>

inherit LIB_ARMOUR;

static void create() {
    ::create();
    SetProperty("laoise_flag", 1);
    SetKeyName("water breastplate");
    SetId( ({ "breastplate", "plate" }) );
    SetAdjectives( ({ "water", "formed", "breast" }) );
    SetShort("a water-formed breastplate");
    SetLong(
    "Shaped into a petite female torso this breastplate is a dark "
    "blue color with swirling motion in its depths. It appears to "
    "be formed of solidified ocean water with hinges on the sides "
    "which allow the breastplate to be opened and closed so that it "
    "can be worn. In the center of the chest is a small sigil in the "
    "shape of a starfish."
    );
    SetWear("The breastplate formed of water stretches and forms to "
    "your torso, fitting perfectly.");
    SetArmourType(A_VEST);
    SetVendorType(VT_ARMOUR);
    SetArmourClass(ARMOUR_NATURAL);
    SetProtectionBonus(WATER, 20);
    SetMass(10);
    SetValue(200);
    SetDamagePoints(600);
    SetSize(SIZE_MEDIUM);
}
