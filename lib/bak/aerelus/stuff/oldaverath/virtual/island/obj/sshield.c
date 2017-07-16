#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <vendor_types.h>
#include <armour_class.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
    armour::create();
    SetKeyName("small shield");
    SetId( ({ "shield", "small shield" }) );
    SetShort("a small shield");
    SetLong("This shield is a small circle of iron, with a "
            "leather strap on the back. The shield is covered "
            "in dents and rust, betelling it's age and condition.");
    SetVendorType(VT_ARMOUR);
    SetArmourType(A_SHIELD);
    SetMass(400);
    SetValue(25);
    SetDamagePoints(500);
    SetSize(SIZE_MEDIUM);
}
