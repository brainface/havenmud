#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;


static void create() {
        item::create();
        SetShort("a dwarven battle axe");
        SetLong("A double bladed battle axe of dwarven construction.");
        SetId( ({"axe", "battle axe", "dwarven axe",
        "dwarven battle axe"}) );
        SetClass(13);
        SetDamagePoints(1800);
        SetMaterial( ({ "metal", "wood" }) );
        SetRepairSkills( ([
          "weapon smithing" : 5,
          "wood working" : 1 ]) );
        SetRepairDifficulty(14);
        SetValue(550);
        SetWeaponType("hack");
        SetDamageType(SLASH);
        SetKeyName("axe");
        SetMass(35);
        SetVendorType(VT_WEAPON);
  }
