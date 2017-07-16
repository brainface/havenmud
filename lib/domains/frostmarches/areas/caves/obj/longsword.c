#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ITEM;

static void create() {
    item::create();
    SetKeyName("longsword");
    SetId( ({"longsword", "sword"}) );
    SetAdjectives("standard");
    SetShort("a standard longsword");
    SetLong("A standard longsword, it's fairly sharp and well built");
    SetVendorType(VT_WEAPON);
    SetDamagePoints(750);
    SetClass(14);
    SetValue(150);
    SetMass(160);
    SetWeaponType("slash");
    SetDamageType(SLASH);
    SetMaterial("metal");
    SetRepairSkills( (["metal working" : 5,
                       "weapon smithing" : 7,
                   ]) );
    SetRepairDifficulty(20);
}
