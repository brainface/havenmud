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
  SetKeyName("rapier");
  SetRepairDifficulty(22);
  SetMaterial( ({ "metal" }) );
  SetRepairSkills( ([
    "metal working" : 1,
    "weapon smithing" : 3,
  ]) );
  SetShort("a goblin rapier");
  SetAdjectives( ({ "goblin" }) );
  SetId( ({ "rapier", "goblin rapier" }) );
  SetLong("This is a long, thin sword of goblin make.  From the intricate "
          "designs on it, one can tell that it must only have been carried "
          "by goblin warriors of the highest caliber.");
  SetClass(11);
  SetDamagePoints(1200);
  SetValue(200);
  SetMass(100);
  SetVendorType(VT_WEAPON);
  SetWeaponType("pierce");
  SetDamageType(PIERCE);
}


/* Approved by Balishae on Thu Sep 11 14:07:11 1997. */