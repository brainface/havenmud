#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <armour_class.h>
#include <size.h>
#include <vendor_types.h>

inherit LIB_ARMOUR;

static void create() {
    armour::create();
    SetKeyName("wall shield");
    SetId( ({ "shield" }) );
    SetAdjectives( ({ "wall" }) );
    SetShort("a wall shield");
    SetLong("The wall shield is a small rectangle of black metal about "
           "two feet tall. It is made of heavy black steel plates reinforced "
           "with metal bars. It has a leather strap to allow the wearer to easily "
           "handle it in combat. It appears to be specially designed to fit the "
           "left hand and arm.");
    SetVendorType(VT_ARMOUR);
    SetArmourClass(ARMOUR_PLATE);
    SetSize(SIZE_SMALL);
    SetMass(500);
    SetValue(12000);
    SetDamagePoints(3000);
    SetProperty("multiples", 1); 
    SetRestrictLimbs( ({ "left arm", "left hand" }) );
    SetArmourType(A_SHIELD|A_WEAPON);
    SetMaterial( ({ "metal" }) );
    SetRepairDifficulty(70);
}
