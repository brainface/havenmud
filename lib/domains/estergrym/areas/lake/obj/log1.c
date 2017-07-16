// Coded by Zeratul 11-27-99
#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
#include "../lake.h"
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("log");
  SetId( ({ "log","small log" }) );
  SetAdjectives( ({ "small" }) );
  SetShort("a small log");
  SetLong("From evergreen wood, this log is a dark brown in color. "
     "The size of the piece of wood was cut down by an axe. This piece "
     "of wood would be good for a wood fire. "
     );
  SetPreventGet("It is much too heavy and rooted in the muck to move.");
  SetMass(90);
  SetValue(10);
  SetVendorType(VT_WEAPON);
  SetClass(4);
  SetWeaponType("blunt");
  SetDamageType(BLUNT);
  SetDamagePoints(300);
  SetMaterial( ({ "wood" }) );
  SetRepairDifficulty(4);
  SetRepairSkills( ([
     "wood working" : 1,
     ]) );
  SetProperty("history", "This log is from the Estergrym Mountains. "
     );
}
