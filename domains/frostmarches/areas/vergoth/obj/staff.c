#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;
#include "../vergoth.h"

static void create() {
  item::create();
  SetKeyName("staff");
  SetShort("an oaken staff");
  SetLong("This is a long oaken staff, about six feet long.  It has a "
	"blue feather strapped along the top of it and a small crystal "
	"mounted on the tip.  There is a leather wrap in the middle of "
	"the staff and the wood is worn.");
  SetHands(2);
  SetId( ({ "staff" }) );
  SetAdjectives( ({ "oaken","long" }) );
  SetClass(12);
  SetWeaponType("pole");
  SetDamageType(BLUNT);
  SetVendorType(VT_WEAPON);
  SetDamagePoints(800);
  SetValue(80);
  SetMass(200);
  SetMaterials( ({ "wood" }) );
  SetRepairDifficulty(5);
  SetRepairSkills( ([
     "wood working" : 1,
     "weapon smithing" : 1,
     ]) );
 }