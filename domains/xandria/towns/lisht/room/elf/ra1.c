#include <lib.h>
#include <domains.h>
#include "../../lisht.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("arid");
  SetExits( ([
    "north" : LISHT_ROOM "elf/rr3",
    "south" : LISHT_ROOM "elf/ra2",
    ]) );
  SetShort("River Alley by the Wall of Lisht");
  SetDayLight(-10);
  SetDayLong(
    "The Wall of Lisht rises along the west side of the alley here, blocking the "
    "harshest rays of the sunlight. The alley continues into the shadows deeper "
    "to the south, while to the north is the iron gate that connects the slave "
    "and citizen portions of Lisht. A small stone hovel sits along the alleyway. "
    "Houses and small buildings line the alley to the south."
    );
  SetNightLong(
    "The Wall of Lisht prevents the stars from shining brightly here. "
    "The alley continues into the shadows deeper "
    "to the south, while to the north is the iron gate that connects the slave "
    "and citizen portions of Lisht. A small stone hovel sits along the alleyway. "
    "Houses and small buildings line the alley to the south."
    );
  SetListen("The alley is quiet, almost depressing.");
  SetInventory( ([
    ]) );
  SetItems( ([
    "wall" : "The Wall of Lisht keeps the slaves in their place, preventing them "
             "from getting to the good citizens of Lisht.",
    "hovel": "This small hovel is home to some slaves.",
    ({ "house", "houses", "building", "buildings" }) : "The houses and buildings are to the south. "
                                                       "There is a small stone hovel here.",
    ]) );
  SetItemAdjectives( ([
    "hovel" : ({ "small", "stone" }),
    ]) );
  SetEnters( ([
    "hovel" : LISHT_ROOM "elf/house",
    ]) );
}
