#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;


static void create() {
        item::create();
        SetShort("a short spear");
        SetLong("A standard short spear with an steel point and a wooden "
        "haft.");
        SetId( ({"spear", "short spear"}) );
        SetClass(12);
        SetDamagePoints(1500);
        SetMaterial( ({ "metal", "wood" }) );
        SetRepairSkills( ([
          "weapon smithing" : 3,
          "wood working" : 1 ]) );
        SetRepairDifficulty(11);
        SetValue(360);
        SetWeaponType("pierce");
        SetDamageType(PIERCE);
        SetKeyName("spear");
        SetMass(100);
        SetVendorType(VT_WEAPON);
        SetAdjectives( ({ "short"}) );
  }
