// by Dahaka
// Aug 2004

#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
#include "../drazh.h"
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("axe");
  SetId( ({"axe"}) );
  SetAdjectives( ({"hand","steel"}) );
  SetShort("a hand axe");
  SetLong(
     "This hand axe is the standard weapon of the watchmen fighters. The "
     "long, metal handle is wrapped in leather to help wield the solid "
     "metal axe. The axe head has a serrated edge which look to be very "
     "durable. "
     );
  SetDamagePoints(800);
  SetValue(10);
  SetMass(120);
  SetClass(5);
  SetVendorType(VT_WEAPON);
  SetDamageType(SLASH);
  SetWeaponType("hack");
  SetRepairDifficulty(10);
  SetRepairSkills( ([
     "metal working"   : 5,
     "weapon smithing" : 5,
     ]) );
  SetMaterial( ({"metal"}) );
}
