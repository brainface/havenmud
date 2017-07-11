#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;


static void create() {
  item::create();
  SetKeyName("gaff hook");
  SetId( ({ "hook", "gaff", "hook" }) );
  SetAdjectives( ({ "bone", "gaff", "fishing" }) );
  SetShort("a bone gaff hook");
  SetLong(
    "This implement was formerly a fishing "
    "tool, but someone has turned it into "
    "a weapon.  It appears to have been "
    "carved from a large bone."
  );  
  SetClass(14);
  SetDamagePoints(960);
  SetValue(450);
  SetWeaponType("pierce");
  SetDamageType(PIERCE);
  SetMass(190);
  SetMaterial( ({ "metal", "natural" }) );
  SetVendorType(VT_WEAPON);
}

