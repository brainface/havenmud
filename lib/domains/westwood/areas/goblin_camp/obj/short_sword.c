#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;
#include "../goblin.h"

static void create() {
  item::create();
  SetShort("a shortsword");
  SetLong("This weapon is nothing more than a shortsword.  It is "
					"about twenty-four inches long with a wooden handle.  The edge is "
					"very sharp and looks like it could cause some damage.  There is a "
					"thin blood groove running the length of the blade.");
  SetId( ({"sword", "shortsword"}) );
  SetClass(8);
  SetDamagePoints(350);
  SetValue(125);
  SetWeaponType("sword");
  SetDamageType(SLASH);
  SetKeyName("sword");
  SetMass(55);
  SetMaterial( ({ "metal" }) );
  SetRepairSkills( ([
  	"metal working" : 1,
		"weapon smithing" : 1 
		]) );
  SetRepairDifficulty(4);
  SetVendorType(VT_WEAPON);
  SetAdjectives( ({"short"}) );
}