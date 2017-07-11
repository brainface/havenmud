#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ITEM;

static void create() {
    item::create();
    SetKeyName("shamanic staff");
    SetId("staff");
    SetAdjectives("shamanic");
    SetShort("a shamanic staff");
    SetLong("This is a ash staff with evil marking's cut into it.");
    SetVendorType(VT_WEAPON);
    SetDamagePoints(550);
    SetClass(8);
    SetValue(30);
    SetMass(60);
    SetWeaponType("pole");
    SetDamageType(BLUNT);
    SetMaterial("wood");
    SetRepairSkills( ([
                       "wood working" : 2,
                       "weapon smithing" : 2,
                   ]) );
    SetRepairDifficulty(10);
}
