// Edited SetDamageType because KNIFE is no longer
// a valid type
// Taigis 6/22/04

#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;
static void create() {
    item::create();
    SetKeyName("knife");
    SetId( ({ "curved knife", "knife" }) );
    SetShort("a curved knife");
    SetLong("This knife looks sharp, pointy, and dangerous.");
    SetMass(70);
    SetValue(80);
    SetVendorType(VT_WEAPON);
    SetClass(11);
    SetWeaponType("knife");
    SetDamageType(PIERCE);
    SetDamagePoints(1000);
    SetMaterial( ({ "metal" }) );
    SetRepairSkills( ([
    "metal working" : 3,
    "weapon smithing" : 3,
]) );
    SetRepairDifficulty(20);
}
