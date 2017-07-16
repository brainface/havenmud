#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetShort("a dented bronze sword");
  SetLong(
     "This short sword is made from a metal alloy called bronze. Compared to "
     "other metals, such as iron, this weapon lacks in strength. This sword "
     "looks like it would be better suited for training rather than actual "
     "combat. "
     "This weapon has seen too much use, and is damaged."
  );
  SetId( ({ "sword", "shortsword" }) );
  SetAdjectives( ({ "short", "bronze", "dented" }) );
  SetClass(6);
  SetDamagePoints(650);
  SetValue(00);
  SetWeaponType("slash");
  SetDamageType(SLASH);
  SetKeyName("bronze sword");
  SetMass(75);
  SetMaterial( ({ "metal"}) );
  SetVendorType(VT_WEAPON);
}
