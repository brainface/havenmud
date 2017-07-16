//
//  Summary: Spears for the guards
//  Created by Rhakz - Angel Cazares
//  Date: 10/14/98
//
#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("bronze spear");
  SetId( ({"spear"}) );
  SetAdjectives( ({ "bronze", "long"}) );
  SetShort("a long bronze spear");
  SetLong(
     "This long object is a hallowed out piece of wood that "
     "has been formed into a spear. The point of this weapon "
     "appears to have been fashioned out of a strong alloy "
     "of bronze. The shaft of the weapon is laden with multiple "
     "colors of dragon scales, adding to it's looks and functionality "
     "by enhancing it's strength. It looks sharp and deadly. "
  );
  SetVendorType(VT_WEAPON);
  SetDamagePoints(1800);
  SetClass(14);
  SetHands(2);
  SetMaterial( ({ "metal"}) );
  SetRepairSkills( ([
                     "metal working" : 5,
                 ]) );
  SetRepairDifficulty(15);
  SetValue(200);
  SetMass(175);
  SetWeaponType("pierce");
  SetDamageType(PIERCE);
}

