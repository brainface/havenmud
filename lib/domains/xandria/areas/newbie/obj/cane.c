//Selket@Haven
//2006
#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("cane");
  SetId( ({ "cane"}) );
  SetAdjectives( ({ "walking" }) );
  SetShort("a walking cane");
  SetLong(
     "This cane is made of some battered wood and can serve "
     "as both a weapon and a crutch in hard times."
  );
  SetClass(8);
  SetDamagePoints(470);
  SetHands(2);
  SetValue(50);
  SetWeaponType("pole");
  SetDamageType(BLUNT);
  SetMass(165);
  SetMaterial( ({ "wood" }) );
  SetVendorType(VT_WEAPON);
}
