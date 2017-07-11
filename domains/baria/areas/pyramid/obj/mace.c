//
// Creator: Angel Cazares - Rhakz
// Date: 09/18/98
// File Name: mace.c
// Area: the dark pyramid
//
#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("heavy-spiked mace");
  SetShort("a heavy-spiked mace");
  SetLong("This heavy mace was specially crafted to bash "
          "the enemy without mercy.");
  SetHands(2);
  SetId( ({ "mace" }) );
  SetAdjectives( ({"heavy","spiked","heavy-spiked"}) );
  SetClass(11);
  SetWeaponType("blunt");
  SetDamageType(BLUNT);
  SetDamagePoints(800);
  SetValue(100);
  SetMass(150);
  SetVendorType(VT_WEAPON);
  SetMaterials( ({ "wood" }) );
  SetRepairDifficulty(10);
  SetRepairSkills( ([
                     "wood working" : 10,
                     "weapon smithing" : 10,
                 ]) );
}
