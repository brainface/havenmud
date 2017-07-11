#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("blue longsword");
  SetId( ({ "sword", "longsword" }) );
  SetAdjectives( ({ "long", "blue" }) );
  SetShort("a long blue sword");
  SetLong(
    "A well-polished blue longsword."
  );
  SetVendorType(VT_WEAPON);
  SetDamagePoints(1500);
  SetValue(200);
  SetClass(14);
  SetMass(100);
  SetMaterial( ({ "metal" }) );
  SetWeaponType("slash");
  SetDamageType(SLASH);
}
