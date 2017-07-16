/* an axe - Duhoc jan. 99 */
#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("axe");
  SetId( ({ "axe", }) );
  SetShort("a copper-hilted hand axe");
	SetAdjectives( ({ "copper", "hilted", "hand" }) );
  SetLong("This hand axe, though small enough to hold in one hand, "
          "is still an effective weapon.  Its head is large and powerful, "
          "and its copper hilt is nice and shiny.");
  SetClass(15);
  SetDamagePoints(1200);
  SetValue(200);
  SetMaterial("metal");
  SetRepairDifficulty(10);
  SetWeaponType("hack");
  SetDamageType(SLASH);
	SetMass(200);
	SetVendorType(VT_WEAPON);
}
