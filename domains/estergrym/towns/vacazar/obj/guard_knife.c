// Coded by Zeratul
// 3-24-2000

#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
#include "../vacazar.h"
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("knife");
  SetId( ({"knife","thin knife","guard knife"}) );
  SetAdjectives( ({"thin"}) );
  SetShort("a thin knife");
  SetLong(
     "This thin knife is the standard weapon of the watchmen rogues. The thin "
     "blade of this weapon makes it an excellent weapon for exploting weak "
     "spots in armour. This knife looks to be quite reliable. "
  );
  SetDamagePoints(950);
  SetValue(200);
  SetMass(90);
  SetClass(18);
  SetVendorType(VT_WEAPON);
  SetDamageType(PIERCE);
  SetWeaponType("knife");
  SetRepairDifficulty(20);
  SetRepairSkills( ([
     "metal working" : 10,
     "weapon smithing" : 10,
  ]) );
  SetMaterial( ({"metal"}) );
  }
