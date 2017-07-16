#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;
#include "../vergoth.h"

static void create() {
  item::create();
  SetShort("a kitchen knife");
  SetLong("This weapon is nothing more than a small kitchen knife.  It is "
	"about 8 inches long with a wooden handle.  The edge is very sharp "
	"and looks like it could cause some damage.");
  SetId( ({"knife"}) );
  SetClass(8);
  SetDamagePoints(540);
  SetValue(120);
  SetWeaponType("knife");
  SetDamageType(PIERCE);
  SetKeyName("knife");
  SetMass(25);
  SetMaterial( ({ "metal" }) );
  SetRepairSkills( (["metal working" : 3,
	"weapon smithing" : 3 ]) );
  SetRepairDifficulty(3);
  SetVendorType(VT_WEAPON);
  SetAdjectives( ({"kitchen","small"}) );
}