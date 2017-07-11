/*  A wakasashi */
#include <damage_types.h>
#include <vendor_types.h>
#include <lib.h>
inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("deadly wakizashi");
  SetShort("a deadly wakizashi");
  SetId( ({ "wakizashi","wakasashi" }) ); //grandfathering old name to unbreak npcs.
  SetAdjectives( ({ "deadly" }) );
  SetClass(19);
  SetDamagePoints(2500);
  SetWeaponType("pierce");
  SetVendorType(VT_WEAPON);
  SetDamageType(PIERCE);
  SetMaterial("metal");
  SetRepairSkills( ([
    "metal working" : 5,
    "weapon smithing" : 5,
    ]) );
  SetRepairDifficulty(20);
  SetLong(
     "This weapon is a short piercing sword. It's blade is flat and "
     "has a tip that comes to a razor sharp point. The edge of this "
     "weapon looks extremely sharp and deadly, suggesting it was "
     "crafted by a person with great skill. This weapon is light, strong, "
     "and effective in close quarters combat. "
  );
  
  SetValue(950);
}
