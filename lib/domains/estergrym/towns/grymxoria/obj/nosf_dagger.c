#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;


static void create() {
  item::create();
  SetKeyName("dagger");
  SetId( ({"dagger" }) );
  SetAdjectives( ({ "red", "bladed", "reddish" }) );
  SetShort("a red bladed dagger");
  SetLong(
    "A finely crafted dagger with a blade "
    "made of a reddish metal."
  );
  SetVendorType(VT_WEAPON);
  SetMass(15);
  SetClass(13);
  SetDamagePoints(2000);
  SetValue(400);
  SetWeaponType("knife");
  SetDamageType(SLASH);
  SetMaterial("metal");
  SetRepairDifficulty(10);
}

