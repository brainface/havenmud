// Edited SetDamageType from KNIFE
// Taigis 6/22/04

#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;
static void create() {
    item::create();
    SetKeyName("knife");
    SetId( ({ "finely made knife", "fine knife", "knife"}) );
    SetShort("a finely made knife");
    SetLong("The blade of the knife is quite sharp, and it looks like it was "
    "crafted by a master of weaponsmithing for a master of skullduggery and "
    "sneaking around.");
    SetMass(90);
    SetValue(150);
    SetVendorType(VT_WEAPON);
    SetClass(14);
    SetWeaponType("knife");
    SetDamageType(PIERCE);
    SetDamagePoints(1500);
    SetMaterial( ({ "metal" }) );
    SetRepairSkills( ([
    "metal working" : 4,
    "weapon smithing" : 4,
]) );
    SetRepairDifficulty(30);
}
