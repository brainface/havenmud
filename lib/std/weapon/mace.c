#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetShort("a small metal mace");
  SetLong(
   "This small mace is made of a sturdy metal.  While not very impressive, "
   "it is better than clubbing people with sticks."
  );
  SetId( ({ "mace" }) );
  SetAdjectives( ({ "small", "metal" }) );
  SetClass(8);
  SetDamagePoints(1500);
  SetValue(50);
  SetWeaponType("blunt");
  SetDamageType(BLUNT);
  SetKeyName("mace");
  SetMass(75);
  SetMaterial( ({ "metal" }) );
  SetVendorType(VT_WEAPON);
}
