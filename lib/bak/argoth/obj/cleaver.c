#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ITEM;
static void create() {
    item::create();

    SetKeyName("battle cleaver");
    SetId( ({ "battle cleaver", "cleaver"}) );
    SetAdjectives( ({ "battle" }) );
    SetShort("a battle cleaver");
    SetLong("This dangerous looking weapon is made up of a large metal pole "
    "and a huge, rectangular blade that curves at the edge.  It looks like "
    "it could disembowel just about anything.");
    SetVendorType(VT_WEAPON);
    SetDamagePoints(2400);
    SetClass(15);
    SetMass(150);
    SetValue(750);
    SetWeaponType("hack");
    SetDamageType(SLASH);
    SetMaterial( ({ "metal" }) );
    SetRepairSkills( ([
    "metal working" : 5,
    "weapon smithing" : 5,
]) );
    SetRepairDifficulty(60);
}
