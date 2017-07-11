//Selket@Haven
//2006
#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetShort("a gigantic rolling pin");
  SetId( ({ "pin" }) );
  SetAdjectives( ({ "gigantic", "rolling" }) );
  SetLong(
     "This rolling pin could roll out biscuits the size of "
     "halflings, and could probably flatten out a few "
     "halflings besides."
  );
  SetClass(5);
  SetDamagePoints(600);
  SetValue(1200);
  SetWeaponType("blunt");
  SetDamageType(BLUNT);
  SetKeyName("club");
  SetMass(275);
  SetMaterial( ({ "wood" }) );
  SetVendorType(VT_WEAPON);
  SetRepairDifficulty(5);
}
