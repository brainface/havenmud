// mahkefel 
// pirate cutlass
#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("steel cutlass");
  SetId( ({"cutlass"}) );
  SetAdjectives( ({ "steel" }) );
  SetShort("a steel cutlass");
  SetLong(
    "This long, sickle shaped blade has numerous "
    "discolorations marking where dents have been "
    "repaired and blood has been cleaned. The hilt "
    "features simple leather worn by constant use "
    "in a sure grip."
  );
  SetClass(25);
  SetDamagePoints(2000);
  SetValue(2500);
  SetWeaponType("slash");
  SetDamageType(SLASH);
  SetKeyName("steel cutlass");
  SetMass(350);
  SetMaterial( ({ "metal" }) );
  SetVendorType(VT_WEAPON);
  SetHands(1);
}

