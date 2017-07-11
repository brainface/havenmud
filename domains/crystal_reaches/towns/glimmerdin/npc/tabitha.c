#include <lib.h>
#include <std.h>
#include "../path.h"
inherit LIB_BARKEEP;

static void create() {
  barkeep::create();
  SetKeyName("tabitha");
  SetShort("Tabitha, a dwarven barmaid");
  SetRace("dwarf");
  SetClass("merchant");
  SetLevel(9);
  SetMorality(150);
  SetId( ({ "tabitha", "barmaid", "dwarf", "glim_wander" }) );
  SetAdjectives( ({ "dwarven"}) );
  SetGender("female");
  SetLong("Tabitha the barmaid is quite cute for a dwarf, if only she "
          "didn't have that full beard.");
  SetLocalCurrency("nuggets");
  SetMenuItems( ([
   "beer" : STD_MEAL "alcohol/beer",
   "ale"  : G_OBJ "d_ale",
   ]) );
  SetAction(5, ({
  	"!speak You could ask me to browse.",
  	"!speak You could ask me to sell, if you wanted to buy.",
  	}) );
}
