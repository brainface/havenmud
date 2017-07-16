#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;


static void create() {
  item::create();
  SetKeyName("metal staff");
  SetId( ({ "staff" }) );
  SetAdjectives( ({ "metal", "shod", "reddish", "red" }) );
  SetShort("a metal shod staff");
  SetLong(
    "A finely crafted staff encased in a layer of a "
    "reddish metal."
  );
  SetVendorType(VT_WEAPON);
  SetValue(400);
  SetMass(70);
  SetWeaponType("pole");
  SetDamageType(BLUNT);
  SetClass(13);
  SetDamagePoints(2000);
  SetMaterial("metal");
  SetRepairDifficulty(10);
}

