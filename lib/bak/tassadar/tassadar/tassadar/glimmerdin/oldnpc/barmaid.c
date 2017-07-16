#include <lib.h>
#include "../glim.h"

inherit LIB_BARKEEP;

static void create() {
  barkeep::create();
  SetKeyName("tabitha");
  SetShort("a dwarven barmaid");
  SetRace("dwarf");
  SetReligion("Kylin", "Kylin");
  SetClass("merchant");
  SetLevel(9);
  SetId( ({ "waitress","tabitha","barmaid","dwarf"}) );
  SetAdjectives( ({ "dwarven"}) );
  SetGender("female");
  SetLong("Tabitha, the barmaid of the local dwarven tavern, "
    "brings drinks and such to patrons.  She is pretty cute "
    "for a dwarf.");
  SetLocalCurrency("nuggets");
  SetMorality(-65);
  SetFriends( ({"tembeg", "rancor", "raal", "rallor", 
    "tabitha", "dwarf", "civak", "guard", "patrol", 
    "samik", "gracchus", "eredos", "dorscha", "bralor"}) );
  SetMenuItems( ([
                 "beer" : "/std/meal/alcohol/beer",
                 "ale" : G_OBJ + "food/d_ale",
                 "scotch" : G_OBJ + "food/scotch",
                 "brisket" : G_OBJ + "food/brisket",
                 "ribs"  :  G_OBJ + "food/ribs", 
                 ]) );
  }
