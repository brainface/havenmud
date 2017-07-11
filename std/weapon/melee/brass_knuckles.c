// Vaux@Haven (June 30, 2004)
#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create(){
  item::create();
  SetKeyName("brass knuckles");
  SetId( ({ "knuckles" }) );
  SetAdjectives( ({ "brass", "pair", "pair of" }) );
  SetShort("a pair of brass knuckles");
  SetLong(
    "A small metal weapon worn over the back of the hand "
    "made entirely of brass.  Gripping them in one's fist "
    "provides an excellent means of persuasion."
  );
  SetClass(5);
  SetDamagePoints(850);
  SetValue(100);
  SetWeaponType("melee");
  SetDamageType(BLUNT);
  SetMass(25);
  SetMaterial( ({ "metal" }) );
  SetVendorType(VT_WEAPON);
}



