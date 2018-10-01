// by Dahaka
// Aug 2004

#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("axe");
  SetId( ({"axe"}) );
  SetAdjectives( ({"hand","steel","long"}) );
  SetShort("a steel axe");
  SetLong(
     "This hand axe is the standard weapon of the watchmen fighters. The "
     "long, metal handle is wrapped in leather to help wield the solid "
     "metal axe. This axe looks to be very durable. "
     );
  SetDamagePoints(950);
  SetValue(200);
  SetMass(180);
  SetClass(13);
  SetVendorType(VT_WEAPON);
  SetDamageType(SLASH);
  SetWeaponType("hack");
  SetRepairDifficulty(23);
  SetRepairSkills( ([
     "metal working"   : 10,
     "weapon smithing" : 10,
     ]) );
  SetMaterial( ({"metal"}) );
}
