//
// a magical axe
// created by Ranquest@Haven
#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
#include "main.h"
inherit LIB_ITEM;

static void create() {
  item::create();
  SetShort("a jewelled axe");
  SetLong("This axe was crafted by a master. The edge of the blade "
    			"seems to shimmer, and the power locked within struggles to "
    			"escape. Runes crawl along the haft of the axe, threading their "
    			"way past jewels and gems embedded in the wood and outlined in "
    			"gold.");
  SetKeyName("axe");
  SetId( ({ "axe" }) );
  SetAdjectives( ({ "jewelled" }) );
  SetProperty("history",
    "This axe was the fabled KingMaker, the "
    "legacy passed on to generations of kings and warlords through "
    "the ages. It was believed lost at the end of King Radchek's reign "
    "in the earth tremors. It is rumoured to enhance the leadership of "
    "he who wields it.");
  SetProperty("magic",
    "The rumours that this axe would enhance charisma were, alas, no "
    "more than that. It has been enchanted to be very sharp, though.");
  SetDamagePoints(2000);
  SetClass(19);
  SetVendorType(VT_WEAPON);
  SetMaterial( ({"metal","wood"}) );
  SetRepairSkills( ([
  	"weapon smithing" : 5,
    "metal working" : 5,
    "wood working" : 2,
    ]) );
  SetRepairDifficulty(40);
  SetValue(2500);
  SetMass(150);
  SetWeaponType("hack");
  SetDamageType(SLASH|BLUNT);
}
