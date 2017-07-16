//-- torak@haven --//

#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ARMOUR;

static void create() {
    armour::create();
    SetKeyName("loincloth");
    SetId( ({ "loincloth" }) );
    SetShort("a loincloth");
    SetLong("This worn down loincloth is the common clothing "
            "of the lizardmen.  It stretches from the waist and "
            "hangs down to the knees, with an off-white color to it.");
    SetVendorType(VT_ARMOUR);
    SetMass(50);
    SetArmourClass(ARMOUR_CLOTH);
    SetValue(80);
    SetDamagePoints(400);
    SetArmourType(A_PANTS);
    SetMaterial("textile");
    SetWarmth(7);
}
