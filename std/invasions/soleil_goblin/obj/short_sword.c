// Goblin invasion of Soleil
// Original Coder: Unknown
// Edited: Laoise, 2005

#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("sword");
  SetShort("a short sword");
  SetId( ({"sword"}) );
  SetAdjectives( ({ "short", "sharp" }) );
  SetLong(
    "This weapon is nothing more than a short sword. It is "
    "about twenty-four inches long with a wooden handle. The edge is "
    "very sharp and looks like it could cause some damage. There is a "
    "thin blood groove running the length of the blade."
  );
  SetVendorType(VT_WEAPON);
  SetWeaponType("sword");
  SetDamageType(SLASH);
  SetClass(9);
  SetDamagePoints(400);
  SetValue(125);
  SetMass(155);
  SetMaterial( ({ "metal" }) );
  SetRepairSkills( ([
    "metal working" : 1,
    "weapon smithing" : 1 
  ]) );
  SetRepairDifficulty(4);
}

/* Approved by Dylanthalus on Tue May 18 01:05:57 1999. */