#include <lib.h>
#include "../glim.h"

inherit LIB_BARKEEP;

static void create() {
  barkeep::create();
  SetKeyName("liddie");
  SetShort("Liddie, a dwarven barmaid");
  SetRace("dwarf");
  SetClass("merchant");
  SetLevel(9);
  SetId( ({ "liddie", "barmaid", "dwarf" }) );
  SetAdjectives( ({ "dwarven"}) );
  SetGender("female");
  SetLong("Liddie, the barmaid of the local dwarven tavern, "
    "brings drinks and such to patrons.  She is pretty cute "
    "for a dwarf.");
  SetLocalCurrency("glims");
  SetMorality(-65);
  SetMenuItems( ([
                 "beer"    : G_OBJ + "beer",
                 "ale"     : G_OBJ + "d_ale",
                 "scotch"  : G_OBJ + "scotch",
                 "brisket" : G_OBJ + "brisket",
                 "ribs"    : G_OBJ + "ribs", 
   ]) );
}
