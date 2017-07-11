#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("broadsword");
  SetRepairDifficulty(12);
  SetRepairSkills( ([
    "metal working" : 1,
    "weapon smithing" : 1,
   ]) );
  SetMaterial("metal");
  SetShort("a large broadsword");
  SetId( ({ "sword", "broadsword" }) );
  SetAdjectives( ({ "broad", "large" }) );
  SetLong("This oversized sword is thick for hefty overhand hacking "
          "in a manner more like an axe than a true sword.");
  SetWeaponType("hack");
  SetDamageType(SLASH);
  SetVendorType(VT_WEAPON);
  SetDamagePoints(750);
  SetClass(13);
  SetMass(275);
  SetValue(300);
  }


/* Approved by Balishae on Thu Sep 11 13:54:07 1997. */