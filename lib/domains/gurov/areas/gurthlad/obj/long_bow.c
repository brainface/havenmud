#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;


static void create() {
        item::create();
        SetKeyName("bow");
        SetAdjectives( ({ "long"}) );
        SetShort("a long bow");
        SetLong("A standard long bow made of good wood and animal sinew.");
        SetId( ({"bow", "long bow"}) );
        SetClass(11);
        SetDamagePoints(1300);
        SetMaterial( ({ "wood" }) );
				SetRepairSkills( ([ "weapon smithing" : 1 ]) );
        SetRepairDifficulty(10);
        SetValue(300);
        SetWeaponType("projectile");
        SetDamageType(PIERCE);
        SetHands(2);
        SetMass(45);
        SetVendorType(VT_WEAPON);
        
}
