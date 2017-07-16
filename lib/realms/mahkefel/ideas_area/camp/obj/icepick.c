#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;
inherit LIB_DIGGING;


static void create() {
  item::create();
  SetKeyName("icepick");
  SetId( ({"pick","icepick"}) );
  SetAdjectives( ({ "sharp", "ice" }) );
  SetShort("a sharp icepick");
  SetLong(
    "A long, slightly cresent blade of this pick looks like it could "
    "do unpleasant things to ice and anything softer. The handle is "
    "a oak covered in furs to provide grip."
  );
  SetClass(20);
  SetDamagePoints(1000);
  SetValue(850);
  SetWeaponType("hack");
  SetDamageType(PIERCE);
  SetMass(75);
  SetMaterial( ({ "metal" }) );
  SetVendorType(VT_WEAPON);
  SetAdjectives( ({ "steel" }) );
  SetHands(1);
  
  SetRepairDifficulty(25);
  SetProperty("farming item", 1);
}

