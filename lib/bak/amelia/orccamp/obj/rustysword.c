
#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("sword");
  SetId( ({ "sword" }) );
  SetAdjectives( ({ "rusty" }) );
  SetShort("a rusty sword");
  SetLong("The rusty sword is marked with small pocks that no weaponsmith could "
		"ever fix.");
  SetMass(100); 
  SetValue(25);
  SetDamagePoints(400);
  SetWeaponType("slash");
  SetDamageType(SLASH);
  SetClass(8);
  SetVendorType(VT_WEAPON);
}
