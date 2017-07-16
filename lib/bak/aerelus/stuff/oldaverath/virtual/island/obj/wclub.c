#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ITEM;

static void create() {
  ::create();

  SetKeyName("club");
  SetId( ({"club"}) );
  SetAdjectives( ({"small","wooden"}) );
  SetShort("a small wooden club");
  SetLong("This small club is carved from wood and looks like it's "
     "not the best weapon. A slight crack runs down it's side. ");
  SetClass(12);
  SetMass(200);
  SetValue(10);
  SetDamageType(BLUNT);
  SetWeaponType("blunt");
  SetVendorType(VT_WEAPON);
}
