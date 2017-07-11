#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;


static void create() {
  item::create();
  SetKeyName("lance");
  SetId( ({ "lance" }) );
  SetAdjectives( ({ "red", "reddish", "metal", "footman's" }) );
  SetShort("a red tipped lance");
  SetLong(
    "A finely crafted footman�s lance with a tip "
    "made of a reddish metal."
  );
  SetVendorType(VT_WEAPON);
  SetMass(60);
  SetClass(13);
  SetDamagePoints(2000);
  SetValue(450);
  SetWeaponType("pierce");
  SetDamageType(PIERCE);
  SetMaterial( ({
  		"metal",
  		"wood",
  	  }) );
  SetRepairDifficulty(10);
}

