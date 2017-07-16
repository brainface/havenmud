#include <lib.h>
#include <damage_types.h>
#include <armour_types.h>
#include <armour_class.h>
#include <vendor_types.h>
#include <size.h>
inherit LIB_ARMOUR;
static void create() {
    armour::create();
    SetKeyName("helm");
    SetId( ({ "an iron helm", "iron helm", "helm" }) );
    SetShort("an iron helm");
    SetLong("This iron helmet is rather large, for allowing the big, "
    "muscular head of an orc to pass through without much trouble.  Small "
    "holes on each side allow sound to pass in, and the front is open to allow "
    "the wearer to see.  A leather strap secures the helmet to the head of the "
    "wearer.");
    SetVendorType(VT_ARMOUR);
    SetValue(100);
  SetArmourClass(ARMOUR_PLATE);
    SetMass(120);
    SetDamagePoints(900);
    // SetProtection(BLUNT, 5);
    // SetProtection(SLASH, 8);
    // SetProtection(PIERCE, 4);
    SetArmourType(A_HELMET);
    SetMaterial( ({ "metal" }) );
    SetWarmth(0);
    SetSize(SIZE_LARGE);
    SetRepairSkills( ([
    "armour smithing" : 5,
    "metal working" : 5,
    ]) );
    SetRepairDifficulty(20);
    SetWear("You slide the helmet over your head and fasten the chinstrap.");
}
