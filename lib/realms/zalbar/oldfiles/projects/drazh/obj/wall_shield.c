// by Dahaka
// Aug 2004


#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ARMOUR;

static void create() {
    armour::create();
    SetKeyName("wall shield");
    SetId( ({ "shield" }) );
    SetAdjectives( ({ "wall" }) );
    SetShort("a wall shield");
    SetLong(
      "The wall shield is a large piece of metal shaped "
      "into the shape of a rectangle. Due to the largeness "
      "and the way the shield was formed it must be held "
      "in the left arm and left claw."
      );
    SetVendorType(VT_ARMOUR);
    SetMass(500);
    SetValue(180);
    SetDamagePoints(1800);
    SetArmourClass(ARMOUR_PLATE);
    SetProperty("multiples",1);
    SetRestrictLimbs( ({"left arm", "left claw"}) );
    SetArmourType(A_SHIELD|A_WEAPON);
    SetMaterial( ({ "metal" }) );
    SetRepairDifficulty(25);
    SetRepairSkills( ([
      "metal working"   : 5,
      "armour smithing" : 5,
      ]) );
}