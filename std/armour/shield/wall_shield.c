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
    SetLong("The wall shield is a large rectangle of metal about "
           "four feet tall.");
    SetVendorType(VT_ARMOUR);
  SetArmourClass(ARMOUR_PLATE);
  SetSize(SIZE_MEDIUM);
    SetMass(500);
    SetValue(180);
    SetDamagePoints(600);
    SetRestrictLimbs( ({ "left arm" }) );
    SetArmourType(A_SHIELD|A_WEAPON);
    SetMaterial( ({ "metal" }) );
    SetRepairDifficulty(25);
    SetRepairSkills( ([
                        "metal working" : 5,
                        "armour smithing" : 5,
                   ]) );
}
