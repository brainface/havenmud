#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>

inherit LIB_ITEM;


static void create() {
  ::create();
  SetId( ({"shiv"}) );
  SetAdjectives( ({ "wooden" }) );
  SetShort("a wooden shiv");
  SetLong(
    "This shiv is the perfect size to puncture a deep wound "
    "in any intended victim. The circular handle is flawlessly "
    "lightweight and would fit easily hidden or tucked away. "
    "The handle has a hardened wood tip, with twine to ensure "
    "a better grip. It resembles a glorified chop stick with a "
    "much more deadlier point."
  );
  SetClass(13);
  SetDamagePoints(1200);
  SetValue(90);
  SetWeaponType("knife");
  SetDamageType(PIERCE);
  SetKeyName("shiv");
  SetMass(25);
  SetMaterial( ({ "wood" }) );
  SetVendorType(VT_WEAPON);
  SetRepairDifficulty(5);
}