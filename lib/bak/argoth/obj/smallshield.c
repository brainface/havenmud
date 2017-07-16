#include <lib.h>
#include <armour_types.h>
#include <vendor_types.h>
#include <armour_class.h>
#include <damage_types.h>
#include <size.h>
inherit LIB_ARMOUR;
static void create() {
     armour::create();
    SetKeyName("shield");
    SetId( ({ "small metal shield", "metal shield", "small shield", "shield"}) );
    SetShort("a small metal shield");
    SetLong("This shield is very thick and is made of metal all the way "
    "through.  It is for this reason that it is quite cumbersome.");
    SetVendorType(VT_ARMOUR);
    SetMass(250);
  SetArmourClass(ARMOUR_PLATE);
    SetValue(120);
    SetDamagePoints(800);
    // SetProtection(BLUNT, 5);
    // SetProtection(PIERCE, 7);
    // SetProtection(SLASH, 6);
    SetArmourType(A_SHIELD);
    SetSize(SIZE_LARGE);
    SetMaterial( ({ "metal" }) );
    SetWarmth(0);
    SetRepairSkills( ([
    "metal working" : 3,
    "armour smithing" : 3,
]) );
    SetRepairDifficulty(20);
}
