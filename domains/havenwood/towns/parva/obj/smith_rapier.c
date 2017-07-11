//Selket@Haven
//2006
#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetShort("a slim rapier");
  SetId( ({ "rapier", "sword" }) );
  SetAdjectives( ({ "slim" }) );
  SetKeyName("rapier");
  SetLong(
     "This is a sturdily made steel rapier, used to "
     "quickly skewer the enemy in combat. It is lighter "
     "than a broadsword, but incapable of inflicting the "
     "same sort of damage. "
  );
  SetClass(16);
  SetDamagePoints(1000);
  SetValue(50);
  SetWeaponType("pierce");
  SetDamageType(PIERCE);
  SetMass(70);
  SetMaterial( ({ "metal" }) );
  SetRepairDifficulty(25);
  SetVendorType(VT_WEAPON);
}