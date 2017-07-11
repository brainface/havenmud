
#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
#include "../camp.h"
inherit LIB_ITEM;


static void create() {
        item::create();
        SetShort("a large knife");
        SetLong("This weapon is useful in  "
                "everyday chores as well as self-defense.");
        SetId( ({"knife"}) );
        SetAdjectives( ({"large"}) );
        SetMaterial( ({ "metal", "wood" }) );
        SetRepairSkills( ([
           "metal working" : 1,
           "wood working" : 1,
           "weapon smithing" : 1,
              ]) );
        SetClass(7);
        SetDamagePoints(450);
        SetValue(90);
        SetWeaponType("knife");
        SetDamageType(PIERCE);
        SetKeyName("knife");
        SetMass(20);
        SetVendorType(VT_WEAPON);
        SetAdjectives( ({"large"}) );
}
