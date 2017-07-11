#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetShort("a short bronze sword");
  SetLong(
     "This short sword is made from a metal alloy called bronze. Compared to "
     "other metals, such as iron, this weapon lacks in strength. This sword "
     "looks like it would be better suited for training rather than actual "
     "combat. "
  );
  SetId( ({ "sword" }) );
  SetAdjectives( ({ "short","bronze" }) );
  SetClass(5);
  SetDamagePoints(1000);
  SetValue(50);
  SetWeaponType("slash");
  SetDamageType(SLASH);
  SetKeyName("shortsword");
  SetMass(75);
  SetMaterial( ({ "metal" }) );
  SetVendorType(VT_WEAPON);
}
