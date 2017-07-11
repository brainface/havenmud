#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;


static void create() {
  item::create();
  SetShort("a small knife");
  SetLong(
    "This knife looks like it would be better "
    "at carving apples rather then monsters."
  );
  SetId( ({ "knife" }) );
  SetClass(5);
  SetDamagePoints(650);
  SetValue(00);
  SetWeaponType("knife");
  SetDamageType(PIERCE);
  SetKeyName("knife");
  SetMass(15);
  SetMaterial( ({ "metal" }) );
  SetVendorType(VT_WEAPON);
  SetAdjectives( ({ "small" }) );
}
