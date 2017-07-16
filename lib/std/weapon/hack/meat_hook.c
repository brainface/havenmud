#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;
 
static void create() {
        item::create();
  SetKeyName("meat hook");
  SetId( ({ "hook","gore" }) );
  SetAdjectives( ({ "gore","rusty","curved","meat" }) );
  SetShort("a rusty meat hook");
  SetLong(
    "The rusty curve of this meat hook "
    "is covered in gore:  Be it animal or "
    "humanoid, you cannot tell."
  );
  SetClass(11);
  SetDamagePoints(630);
  SetValue(200);
  SetWeaponType("hack");
  SetDamageType(PIERCE);
  SetKeyName("hook");
  SetMass(25);
  SetMaterial( ({ "metal" }) );
  SetVendorType(VT_WEAPON);
}
