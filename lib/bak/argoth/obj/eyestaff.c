#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;
static void create() {
    item::create();
    SetKeyName("eyestaff");
    SetId( ({ "eyestaff"}) );
    SetShort("the Eyestaff");
    SetLong("The Eyestaff is a large staff made out of twisted oak.  At the "
    "top is a large metal sculpture of an eye.");
    SetVendorType(VT_WEAPON);
    SetDamagePoints(1000);
    SetClass(14);
    SetMass(120);
    SetValue(200);
    SetDestroyOnSell(1);
    SetWeaponType("pole");
    SetDamageType(BLUNT);
    SetRepairSkills( ([
    "wood working" : 5,
    "weapon smithing" : 5,
]) );
    SetRepairDifficulty(25);
}
