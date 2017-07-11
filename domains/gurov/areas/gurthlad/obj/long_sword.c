#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;


static void create() {
        item::create();
        SetKeyName("sword");  
        SetAdjectives( ({ "long"}) );
        SetShort("a longsword");
        SetLong("A good longsword of decent craftmanship.");
        SetId( ({"long", "longsword","sword "}) );
        SetClass(11);
        SetDamagePoints(1400);
        SetMaterial( ({ "metal" }) );
        SetRepairSkills( ([ "weapon smithing" : 2 ]) );
        SetRepairDifficulty(10);
        SetValue(140);
        SetWeaponType("slash");
        SetDamageType(SLASH);
        SetMass(100);
        SetVendorType(VT_WEAPON);
      
}
