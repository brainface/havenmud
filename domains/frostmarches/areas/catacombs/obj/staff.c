#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;


static void create() {
  item::create();
  SetKeyName("staff");
  SetId( ({ "staff" }) );
  SetAdjectives( ({ "long", "bone" }) );
  SetShort("a long bone staff");
  SetLong("This long bone staff has a large"
          " uncut gem affixed to the top of it."
          " The bone has been finely sanded and"
          " cleaned to make it extremely white."
          " Given the length of the staff, the"
          " creature it was taken from must have"
          " been monstrous.");
  SetClass(21);
  SetDamagePoints(1000);
  SetValue(1000);
  SetWeaponType("pole");
  SetDamageType(BLUNT | MAGIC);
  SetMass(25);
  SetMaterial( ({ "natural" }) );
  SetVendorType(VT_WEAPON);
  SetHands(2);
}
