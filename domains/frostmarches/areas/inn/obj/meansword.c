#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ITEM;

static void create() {
    item::create();
    SetKeyName("sword");
    SetRepairSkills( ([
                        "metal working" : 4,
                        "weapon smithing" : 4,
                      ]) );
    SetMaterial( ({ "metal" }) );
    SetRepairDifficulty(13);
    SetId( ({ "sword", "mean sword", "mean looking sword" }) );
    SetAdjectives( ({ "mean" }) );
    SetShort("a mean looking sword");
    SetLong("A mean looking steel sword.");
    SetVendorType(VT_WEAPON);
    SetDamagePoints(750);
    SetClass(12, random(4));
    SetValue(140);
    SetMass(300);
    SetWeaponType("slash");
    SetDamageType(SLASH);
}

