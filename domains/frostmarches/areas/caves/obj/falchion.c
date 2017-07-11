#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ITEM;

static void create() {
    item::create();
    SetKeyName("falchion sword");
    SetId("sword");
    SetAdjectives("falchion");
    SetShort("a falchion sword");
    SetLong("A medium length, heavy chopping blade. It is rather old "
            "and relativly dull.");
    SetVendorType(VT_WEAPON);
    SetDamagePoints(700);
    SetClass(10);
    SetValue(100);
    SetMass(160);
    SetWeaponType("slash");
    SetDamageType(SLASH);
    SetMaterial("metal");
    SetRepairSkills( (["metal working" : 5,
                       "weapon smithing" : 5 ]) );
    SetRepairDifficulty(15);
}
