#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;


static void create() {
  item::create();
  SetKeyName("red axe");
  SetShort("a red bladed axe");
  SetId( ({ "axe" }) );
  SetAdjectives( ({ "red", "bladed", "reddish" }) );
  SetLong(
    "A finely crafted axe with a blade "
    "made of a reddish metal."
  );
  SetVendorType(VT_WEAPON);
  SetClass(13);
  SetMaterial( ({"metal"}) );
  SetMass(75);
  SetDamagePoints(2000);
  SetValue(450);
  SetWeaponType("hack");
  SetDamageType(SLASH);
  SetMaterial( ({
  		"metal",
  		"wood",
  		}) );
  SetRepairDifficulty(10);
}

