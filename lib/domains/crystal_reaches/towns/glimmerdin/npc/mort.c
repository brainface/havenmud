#include <lib.h>
#include <std.h>
#include "../path.h"
inherit LIB_BARKEEP;

static void create() {
  barkeep::create();
  SetKeyName("mort");
  SetShort("Mort, the proprietor of the inn");
  SetRace("dwarf");
  SetClass("merchant");
  SetLevel(9);
  SetId( ({ "innkeeper", "mort", "proprietor", "glim_wander" }) );
  SetAdjectives( ({ }) );
  SetGender("male");
  SetLong(
    "Mort is the owner of the Glimmerdin Inn.  He has a hurried, busy "
    "look on his face that cannot be misunderstood to be anything but "
    "concern for his business."
    );
  SetLocalCurrency("nuggets");
  SetMorality(100);
  SetMenuItems( ([
    "ribs"    : G_OBJ "ribs",
    "brisket" : G_OBJ "brisket",
    "scotch"  : STD_MEAL "alcohol/scotch",
    ]) );
  SetAction(4, ({
  	"!speak Ask me to browse, I'll tell you my menu.",
  	"!speak Ask me to sell, and I'll sell you something.",
  	"!speak Sit, eat, drink and be merry!",
  	}) );
}
