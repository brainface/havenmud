
#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("axe");
  SetId( ({ "smallaxe","axe" }) );
  SetAdjectives( ({ "axe","smallaxe","rusty" }) );
  SetShort("a rusty smallaxe");
  SetLong("The rusty axe is marked with small pocks that no weaponsmith could "
		"ever fix.");
  SetMass(100); 
  SetValue(25);
  SetDamagePoints(400);
  SetWeaponType("hack");
  SetDamageType(SLASH);
  SetClass(8);
  SetVendorType(VT_WEAPON);
  SetMaterial("metal");
  SetRepairDifficulty(50);
}
