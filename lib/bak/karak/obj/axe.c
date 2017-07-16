#include <lib.h>
#include "../karak.h"
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("axe");
  SetId( ({ "axe", "battleaxe" }) );
  SetShort("a massive black battleaxe");
  SetLong("A large axe with a serrated edge for tearing apart flesh");
  SetVendorType(VT_WEAPON);
  SetDamagePoints(700);
  SetClass(14);
  SetValue(300);
  SetMass(200);
  SetWeaponType("hack");
  SetDamageType(SLASH);

}
