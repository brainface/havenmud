#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;


static void create() {
        item::create();
        SetShort("a finely crafted longsword");
        SetLong("A finely crafted longsword with intricate designs engraved "
        "on it.");
        SetId( ({"long", "longsword", "sword", "finely crafted sword", 
        "finely crafted longsword", "fine sword" }) );
        SetClass(13);
        SetDamagePoints(1800);
        SetMaterial( ({ "metal" }) );
        SetRepairSkills( ([ "weapon smithing" : 3 ]) );
        SetRepairDifficulty(10);
        SetValue(400);
        SetWeaponType("slash");
        SetDamageType(SLASH);
        SetKeyName("sword");
        SetMass(100);
        SetVendorType(VT_WEAPON);
        SetAdjectives( ({ "long"}) );
}
