/*                                                                   */
//
// Creator: Angel Cazares - Rhakz
// Date: 09/18/98
// File Name: javelin.c
// Area: the dark pyramid
//

#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("black javelin");
  SetShort("a black javelin");
  SetLong("The black javelin has been made out of ebony. It looks "
          "durable and powerful enough to pierce all but the hardest "
          "fleshes.");
  SetHands(1);
  SetId( ({ "javelin" }) );
  SetAdjectives( ({"black","ebony"}) );
  SetClass(11);
  SetWeaponType("projectile");
  SetDamageType(PIERCE);
  SetDamagePoints(600);
  SetValue(100);
  SetMass(100);
  SetVendorType(VT_WEAPON);
  SetMaterials( ({ "wood" }) );
  SetRepairDifficulty(10);
  SetRepairSkills( ([
                     "wood working" : 10,
                     "weapon smithing" : 10,
                 ]) );
}