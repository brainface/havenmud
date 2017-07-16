#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
  ::create();

  SetKeyName("two-handed sword");
  SetId( ({"sword"}) );
  SetAdjectives( ({"rusty","two-handed"}) );
  SetShort("a rusty two-handed sword");
  SetLong("This two-handed sword is rusty and worn from too much "
     "time spent in dampness. It looks like a poor weapon, but will "
     "do for those needing a large weapon.");
  SetClass(8);
  SetDamageType(SLASH);
  SetVendorType(VT_WEAPON);
  SetWeaponType("slash");
  SetHands(2);
  SetDamagePoints(800);
  SetValue(2);
  SetMass(200);
}
