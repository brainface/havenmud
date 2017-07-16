#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("knife");
  SetShort("a small knife");
  SetId( ({"knife"}) );
  SetAdjectives( ({"small"}) );
  SetLong("This small knife looks dull and almost worthless. ");
  SetMass(25);
  SetValue(0);
  SetClass(9);
  SetWeaponType("knife");
  SetDamageType(SLASH);
  SetVendorType(VT_WEAPON);
   SetDamagePoints(800);
}
