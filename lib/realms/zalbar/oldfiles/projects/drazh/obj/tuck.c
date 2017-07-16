// by Dahaka
// Aug 2004


#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("tuck");
  SetId( ({"sword","tuck"}) );
  SetAdjectives( ({"long","darken"}) );
  SetShort("a darken tuck");
  SetLong(
     "This long straight bladed thrusting sword is made from "
     "blacken metal. The pommel and guard are also made from "
     "the blacked metal, but the hilt is wrapped in leather "
     "to give the wielder a better grip with this piercing "
     "sword.");
  SetDamagePoints(1600);
  SetValue(200);
  SetMass(180);
  SetClass(14);
  SetVendorType(VT_WEAPON);
  SetDamageType(PIERCE);
  SetWeaponType("pierce");
  SetRepairDifficulty(23);
  SetRepairSkills( ([
     "metal working"   : 15,
     "weapon smithing" : 15,
     ]) );
  SetMaterial( ({"metal"}) );
  }