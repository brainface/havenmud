#include <lib.h>
#include <armour_types.h>
#include <size.h>
#include <armour_class.h>
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ARMOUR;

static void create() {
    armour::create();
    SetKeyName("armour");
    SetId( ({"platemail", "set"}) );
    SetAdjectives( ({"golden", "plate", "mail"}) );
    SetShort("a set of golden platemail armour");
    SetLong("This set of golden platemail armour looks to have been created "
            "for a very large animal. The golden armour has intricate "
            "markings on each plate piece of the armour.");
    SetMass(5000);
    SetMaterial( ({"metal"}) );
    SetRepairDifficulty(60);
    SetArmourClass(ARMOUR_HEAVY_PLATE);
    SetWarmth(0);
    SetSize(SIZE_VERY_LARGE);
    SetValue(5000);
    SetDamagePoints(5000);
    SetArmourType(A_BODY_ARMOUR);
    SetVendorType(VT_ARMOUR);
    SetRestrictLimbs( ({"torso","left rear leg","right rear leg",
                      "right foreleg","left foreleg"}) );
}
