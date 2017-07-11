#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetShort("a rotting branch");
  SetLong(
   "This is a rotting branch from one of the mighty"
   " black spruce trees from the bog.  It is moist"
   " and covered in fungus.",   
);
  SetId( ({ "branch" }) );
  SetAdjectives( ({ "rotting" }) );
  SetClass(8);
  SetDamagePoints(100);
  SetValue(5);
  SetWeaponType("blunt");
  SetDamageType(BLUNT);
  SetKeyName("branch");
  SetMass(40);
  SetMaterial( ({ "wood" }) );
  SetVendorType(VT_WEAPON);
}
