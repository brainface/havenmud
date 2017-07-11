#include <lib.h>
#include <std.h>
#include <vendor_types.h>
#include "../path.h"
inherit LIB_VENDOR;

static void create() {
  ::create();
  SetStorageRoom(G_ROOM "shop_armoury");
	SetMaxSingleItem(100);
  SetVendorType(VT_WEAPON||VT_ARMOUR);
  SetKeyName("jirvin");
  SetShort("Jirvin, the Armourer of Glimmerdin");
  SetRace("dwarf");
  SetClass("merchant");
  SetLevel(9);
  SetMorality(50);
  SetId( ({ "jirvin", "armourer", "glim_wander" }) );
  SetAdjectives( ({ }) );
  SetGender("male");
  SetLong(
    "Jirvin is the armourer here in town.  He is willing to sell the "
    "same articles to the general public that he does to the militia "
    "and even the Knights."
    );
  SetLocalCurrency("nuggets");
  /*SetMenuItems( ([
    "axe"       : G_OBJ "axe",
    "boots"     : G_OBJ "black_boots",
    "belt"      : G_OBJ "copper_belt",
    "chainmail" : G_OBJ "chainmail",
    "hammer"    : G_OBJ "hammer",
    "sword"     : G_OBJ "flamberge",
    "lorica"    : G_OBJ "lorica",
    "greaves"   : G_OBJ "greaves",
    ]) ); */
  SetAction(4, ({
  	"!speak Ask me to browse, I'll tell you my inventory.",
  	"!speak Ask me to sell, and I'll sell you something.",
  	"!speak Going into battle unarmed is like asking to be killed.",
  	}) );
}
