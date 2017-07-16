#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;
#include "../goblin.h"

static void create() {
  item::create();
  SetShort("a small slingshot");
  SetLong("This is a small slingshot.  It is used mostly to shoot small "
	"animals and pesky sisters.  It has a long stringy band strung "
	"from a wooden frame.");
  SetId( ({"slingshot"}) );
  SetClass(3);
  SetDamagePoints(150);
  SetValue(10);
  SetWeaponType("projectile");
  SetDamageType(BLUNT);
  SetKeyName("slingshot");
  SetMass(10);
  SetMaterial( ({ "wood" }) );
  SetRepairSkills( (["wood working" : 2,
	"weapon smithing" : 1 ]) );
  SetRepairDifficulty(2);
  SetVendorType(VT_WEAPON);
  SetAdjectives( ({"small"}) );
}