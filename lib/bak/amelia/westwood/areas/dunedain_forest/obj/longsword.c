/*
 * Coded by Dunedain@Haven
 * 11 September 1997
 */

#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("longsword");
  SetRepairDifficulty(22);
  SetShort("a goblin longsword");
  SetRepairSkills( ([
    "metal working" : 3,
    "weapon smithing" : 3,
    ]) );
  SetMaterial( ({ "metal" }) );
  SetLong("The ragged curves and sharp angles on this longsword betray "
          "its goblin manufacture.  This weapon would come in handy "
          "in slashing an enemy.");
  SetId( ({ "longsword", "sword", "goblin longsword" }) );
  SetAdjectives( ({ "goblin" }) );
  SetVendorType(VT_WEAPON);
  SetValue(350);
  SetClass(15);
  SetWeaponType("slash");
  SetDamageType(SLASH);
  SetDamagePoints(1500);
  SetMass(190);
 }


/* Approved by Balishae on Thu Sep 11 13:57:21 1997. */