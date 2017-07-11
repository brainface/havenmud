// Coded by Zeratul 11-27-99
#include <lib.h>
#include "../lake.h"
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_POLE;

static void create()
  {
  pole::create();
  SetKeyName("fishing pole");
  SetId( ({"pole","rod","fishing pole"}) );
  SetAdjectives( ({ "small","wood" }) );
  SetShort("a small wooden fishing pole");
  SetLong("This small pole appears simply nothing more than a small stick "
     "with a line attached to it. The quality of the pole is decent and "
     "serves its purpose for fishing. "
     );
  SetClass(4);
  SetValue(100);
  SetMass(70);
  SetDamagePoints(200);
  SetWeaponType("blunt");
  SetDamageType(BLUNT);
  SetVendorType(VT_WEAPON | VT_FISHING);
  SetRepairDifficulty(4);
  SetRepairSkills( (["wood working" : 1, ]) );
  SetMaterial( ({ "wood" }) );
  SetStrength(250);
  SetChance(35);
  }
