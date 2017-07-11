#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ITEM;

static void create() {
    item::create();
    SetKeyName("spiked club");
    SetId("club");
    SetAdjectives( ({"spiked"}) );
    SetShort("a spiked club");
    SetLong("This is a large wooden club with metal spikes sticking out "
            "of it. It is very heavy.");
    SetVendorType(VT_WEAPON);
    SetDamagePoints(800);
    SetClass(17);
    SetValue(150);
    SetMass(400);
    SetWeaponType("blunt");
    SetDamageType(BLUNT|PIERCE);
    SetMaterial("wood");
    SetRepairSkills( ([
                       "wood working" : 5,
                       "weapon smithing" : 3,
                   ]) );
    SetRepairDifficulty(10);
}
