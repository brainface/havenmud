#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;
#include "../goblin.h"

static void create() {
  item::create();
  SetShort("a longsword");
  SetLong("This weapon is a very impressive longsword.  It is about "
					"forty-five inches long with a wire wrapped leather handle.  The "
					"edge is very sharp and looks like it could cleave a person in two.  "
					"There is a blood groove running the length of the blade and a "
					"serrated along both sides.");
  SetId( ({"sword", "longsword"}) );
  SetClass(14);
  SetDamagePoints(750);
  SetValue(250);
  SetWeaponType("slash");
  SetDamageType(SLASH);
  SetKeyName("sword");
  SetMass(80);
  SetMaterial( ({ "metal" }) );
  SetRepairSkills( ([
  	"metal working" : 4,
		"weapon smithing" : 4,
		]) );
  SetRepairDifficulty(9);
  SetVendorType(VT_WEAPON);
  SetAdjectives( ({"long"}) );
}