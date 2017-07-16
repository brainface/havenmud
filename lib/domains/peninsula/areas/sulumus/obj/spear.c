// Proximo@Via Imperialis
// 05/30/2003

#include <lib.h>
#include "../sulumus.h"
#include <vendor_types.h>
#include <damage_types.h>

inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("sharpened spear");
  SetId( ({ "spear" }) );
  SetAdjectives( ({ "a", "sharpened" }) );
  SetShort("a sharpened spear");
  SetLong(
     "This spear was crafted from wood and stone. By tieing together a long wood "
     "shaft to a sharp stone tip, this instrument can be quiet deadly. The tip of "
     "the spear looks to have been extra carefully sharpened for an added punch. "
     );
  SetClass(15);
  SetHands(2);
  SetProperty("history", "This spear was crafted by two different specialists. "
     "It's wood shaft was carved from a fine wood by a wood working specialist who "
     "then used an enchantment spell to magically straighten the wood, as well as "
     "reinforcing it. The stone tip looks to have been very carefully sharpened "
     "bit by bit until a razor-sharp edge was crafted by a stone working specialist.");
  SetWeaponType("pierce");
  SetMaterial( ({ "natural", "wood" }) );
  SetRepairDifficulty(20);
  SetDamageType(PIERCE);
  SetVendorType(VT_WEAPON);
  SetMass(225);
  SetValue(60);
  SetDamagePoints(1400);
}
