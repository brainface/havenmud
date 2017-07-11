#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;
#include "../goblin.h"

static void create() {
  item::create();
  SetShort("a longsword");
  SetLong("This weapon is a very impressive longsword.  It is about "
		"forty inches long with a wire wrapped leather handle.  The edge is "
		"very sharp and looks like it could cleave a person in two.  There "
		"is a blood groove running the length of the blade and a serrated "
		"edge along the back side.");
  SetId( ({"sword", "longsword" }) );
  SetClass(12);
  SetDamagePoints(600);
  SetValue(165);
  SetWeaponType("slash");
  SetDamageType(SLASH);
  SetKeyName("sword");
  SetMass(80);
  SetMaterial( ({ "metal" }) );
  SetRepairSkills( ([
  	"metal working"   : 3,
		"weapon smithing" : 3,
		]) );
  SetRepairDifficulty(8);
  SetVendorType(VT_WEAPON);
  SetAdjectives( ({"long"}) );
}