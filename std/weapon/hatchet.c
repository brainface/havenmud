#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetShort("a long hatchet");
  SetLong(
     "Compared to the average hatchet, this item has a longer handle than "
     "most, stretching about two feet long. The blade is a simple, straight "
     "edge. This weapon looks as if it was design to cut wood rather than be "
     "an instrument in battle. "
  );
  SetId( ({ "hatchet","axe" }) );
  SetAdjectives( ({ "long" }) );
  SetClass(5);
  SetDamagePoints(375);
  SetValue(50);
  SetWeaponType("hack");
  SetDamageType(SLASH);
  SetKeyName("hatchet");
  SetMass(75);
  SetMaterial( ({ "metal", "wood" }) );
  SetVendorType(VT_WEAPON);
}
