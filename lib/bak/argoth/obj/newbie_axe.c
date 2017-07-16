#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;
static void create() {
    item::create();
    SetKeyName("axe");
    SetId( ({ "small stone axe", "primitive axe", "crude axe", "stone axe",
              "small axe", "blunt axe", "axe"}) );
    SetShort("a small stone axe");
    SetLong("This crude, primitive axe is made of a sturdy-looking wooden "
    "pole with a large round rock attached to the end with only a slight "
    "edge to it.  It looks as though it would be handled like an axe, but "
    "it is more likely to smash something than to cut it.");
    SetValue(10);
    SetMass(170);
    SetWeaponType("hack");
    SetDamageType(BLUNT);
    SetDamagePoints(600);
    SetClass(10);
    SetHands(2);
}
