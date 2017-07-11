#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;


static void create() {
        item::create();
        SetKeyName("sword");
        SetShort("a short sword");
        SetLong("A rusty, nicked, and slightly blood stained "
        "short sword.");
        SetId( ({"short", "short sword","short"}) );
        SetClass(9);
        SetDamagePoints(250);
        SetMaterial( ({ "metal" }) );
        SetRepairSkills( ([ "weapon smithing" : 1 ]) );
        SetRepairDifficulty(6);
        SetValue(50);
        SetWeaponType("slash");
        SetDamageType(SLASH);
        
        SetMass(55);
        SetVendorType(VT_WEAPON);
        SetAdjectives( ({ "short"}) );
}
