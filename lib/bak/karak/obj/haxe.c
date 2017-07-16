#include <lib.h>
#include "../karak.h"
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("axe");
  SetId( ({ "axe", "hand axe" }) );
  SetShort("a steel hand axe");
  SetLong("This finely crafted weapon has a serrated edge and looks "
                   "like a quality weapon.");
  SetVendorType(VT_WEAPON);
  SetDamagePoints(600);
  SetClass(13);
  SetValue(150);
  SetMass(100);
  SetWeaponType("hack");
  SetDamageType(SLASH);

}
