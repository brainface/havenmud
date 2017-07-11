//Selket@Haven
//2006
#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetShort("a mallet");
  SetKeyName("mallet");
  SetId( ({ "mallet" }) );
  SetLong(
     "This iron mallet is used for pounding pieces of ceramic "
     "into position, or pounding enemies heads out of position. "
  );
  SetClass(5);
  SetDamagePoints(500);
  SetValue(50);
  SetWeaponType("blunt");
  SetDamageType(BLUNT);
  SetMass(75);
  SetMaterial( ({ "metal" }) );
  SetVendorType(VT_WEAPON);
}
