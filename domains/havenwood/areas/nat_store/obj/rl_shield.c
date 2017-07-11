#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <armour_class.h>
#include <size.h>
#include <vendor_types.h>

inherit LIB_ARMOUR;

static void create() {
    armour::create();
    SetKeyName("leather buckler");
    SetId( ({ "buckler" }) );
    SetAdjectives( ({ "small","leather" }) );
    SetShort("a small leather buckler");
    SetLong("This shield is made from a a layer of boiled leather stretched "
      "over a circular steel frame. A steel boss in the center provides some "
      "additional protection for a wielder skilled enough to intercept sword "
      "strikes."
    );
    SetVendorType(VT_ARMOUR);
    SetArmourClass(ARMOUR_REINFORCED);
    SetSize(SIZE_SMALL);
    SetMass(100);
    SetValue(7500);
    SetDamagePoints(3000);
    SetProperty("multiples", 1);
    //SetRestrictLimbs( ({ "left arm", "left hand" }) );
    SetArmourType(A_SHIELD|A_WEAPON);
    SetMaterial( ({ "leather","metal" }) );
    SetRepairDifficulty(70);
}

