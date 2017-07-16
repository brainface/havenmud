#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>

inherit LIB_ITEM;

static void create() {
  item::create();
  SetShort("a %^RED%^bloody%^RESET%^ blade");
  SetLong(
     "This blade is cylindrical and jagged at the edges. It is "
     "covered in blood."
  );
  SetId( ({ "blade" }) );
  SetAdjectives( ({ "bloody","blade" }) );
  SetClass(45);
  SetDamagePoints(50000);
  SetValue(1500);
  SetWeaponType("slash");
  SetDamageType(SLASH);
  SetKeyName("blade");
  SetMass(10);
  SetMaterial( ({ "metal" }) );
  SetVendorType(VT_WEAPON);
}
