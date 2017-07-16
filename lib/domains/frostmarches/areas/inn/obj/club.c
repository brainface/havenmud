#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ITEM;

static void create() {
    item::create();
    SetKeyName("club");
    SetRepairSkills( ([
                        "wood working" : 2,
                        "weapon smithing" : 3,
                      ]) );
    SetMaterial( ({ "wood" }) );
    SetRepairDifficulty(8);
    SetId( ({ "club", "wooden club" }) );
    SetAdjectives( ({ "wooden" }) );
    SetShort("a wooden club");
    SetLong("This is a large piece of wood fashioned into a club.");
    SetVendorType(VT_WEAPON);
    SetDamagePoints(600);
    SetClass(10, random(3));
    SetValue(100);
    SetMass(200);
    SetWeaponType("blunt");
    SetDamageType(BLUNT);
}

