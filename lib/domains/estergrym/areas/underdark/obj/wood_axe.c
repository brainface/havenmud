#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;


static void create() {
        item::create();
        SetShort("a wood chopping axe");
        SetLong("A standard double bladed wood cutting axe.");
        SetId( ({"axe", "wood axe", "wood cutting axe",
        "wood chopping axe"}) );
        SetClass(10);
        SetDamagePoints(1500);
        SetMaterial( ({ "metal", "wood" }) );
        SetRepairSkills( ([
          "weapon smithing" : 3,
          "wood working" : 1 ]) );
        SetRepairDifficulty(10);
        SetValue(300);
        SetWeaponType("hack");
        SetDamageType(SLASH);
        SetKeyName("axe");
        SetHands(2);
        SetMass(125);
        SetVendorType(VT_WEAPON);
}
