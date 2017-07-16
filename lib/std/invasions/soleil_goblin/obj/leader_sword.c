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
  SetShort("a long sword");
  SetId( ({"sword"}) );
  SetAdjectives( ({ "long", "impressive", "sharp" }) );
  SetLong(
    "This weapon is a very impressive long sword. It is about "
    "forty-five inches long with a wire wrapped leather handle. The "
    "edge is very sharp and looks like it could cleave a person in two. "
    "There is a blood groove running the length of the blade and a "
    "serrated along both sides."
  );
  SetVendorType(VT_WEAPON);
  SetWeaponType("sword");
  SetDamageType(SLASH);
  SetClass(14);
  SetDamagePoints(750);
  SetValue(250);
  SetMass(350);
  SetMaterial( ({ "metal" }) );
  SetRepairSkills( ([
    "metal working" : 4,
    "weapon smithing" : 4,
    "leather working" : 3, ]) );
  SetRepairDifficulty(9);
}

/* Approved by Dylanthalus on Tue May 18 01:04:06 1999. */