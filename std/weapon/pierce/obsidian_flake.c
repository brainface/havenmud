#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;


static void create() {
  item::create();
  SetKeyName("obsidian flake");
  SetId( ({ "flake", "knife" }) );
  SetAdjectives( ({ "obsidian", "simple", "knife" }) );
  SetShort("an obsidian flake");
  SetLong(
    "A simple flake off a larger chunk of "
    "obsidian.  And yet it will cut like a knife!"
  );
  SetClass(6);
  SetDamagePoints(250);
  SetValue(75);
  SetWeaponType("pierce");
  SetDamageType(SLASH);
  SetMass(25);
  SetMaterial( ({ "stone" }) );
  SetVendorType(VT_WEAPON);
}

