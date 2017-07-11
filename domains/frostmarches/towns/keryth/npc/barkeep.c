#include <lib.h>
#include <std.h>
#include "../keryth.h"

inherit LIB_BARKEEP;

static void create() {
  barkeep::create();
  SetKeyName("skel");
  SetShort("Skel the Bartender");
  SetId( ({ "skel the bartender", "skel", "bartender", "barkeep" }) );
  SetLong("This small Goden man stands her quietly, keeping watch on his "
          "patrons and always ready to serve up a beer.  He exudes an air of "
          "confidence and hospitality.");
  SetRace("goden");
  SetGender("male");
  SetClass("merchant");
  SetLevel(20);
  SetMorality(-100);
  SetInventory( ([
    STD_CLOTHING + "shirt/leather_jerkin" : "wear jerkin",
    K_OBJ + "/pants" : "wear pants"
    ]) );
  SetMenuItems( ([
    "stew"   : K_OBJ + "/foxstew",
    "mutton" : K_OBJ + "/mutton",
    "ale"    : K_OBJ + "/ale"
    ]) );
  SetLocalCurrency("senones");
  SetCurrency("senones", random(100)+12);
 
}
