//Selket@Haven
//2006
#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("scythe");
  SetId( ({ "sword", "scythe" }) );
  SetAdjectives( ({ "sharp" }) );
  SetShort("a sharp scythe");
  SetLong(
    "A very keen-edged scythe used to slash down offending "
    "shrubbery."
  );
  SetVendorType(VT_WEAPON);
  SetDamagePoints(1000);
  SetClass(12);
  SetValue(200);
  SetMass(100);
  SetWeaponType("slash");
  SetDamageType(SLASH);
  SetMaterial( ({ "metal" }) );
}
