//coded by Syra 8/97
#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
        item::create();
        SetShort("Tarandus' golden bow");
        SetLong("A large golden recurve bow strung with spun mane hair from "
                "the Hind. ");
        SetId( ({"golden bow","bow"}) );
        SetClass(11);
        SetDamagePoints(1500);
        SetValue(250);
        SetWeaponType("projectile");
        SetDamageType(PIERCE);
        SetKeyName("golden bow");
        SetHands(2);
        SetMass(45);
        SetVendorType(VT_WEAPON);
        SetAdjectives( ({ "tarandus'","golden"}) );
        SetMaterial("natural");
        SetRepairDifficulty(85);

}
