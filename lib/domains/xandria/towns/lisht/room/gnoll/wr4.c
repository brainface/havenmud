//Selket@Haven
//2006
#include <lib.h>
#include <domains.h>
#include "../../lisht.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("arid");
  SetShort("Before a Barracks");
  SetLong(
    "The Wall Road ends here, barricaded on two sides by the high "
    "fortifications. A large barracks stands here, the training "
    "area for the great warriors and soldiers of Lisht, as well "
    "as the military headquarters. The barracks is a low building, "
    "but the front is studded with sharp stakes that apparently "
    "keep the wrong people from trying to enter. The Road leads "
    "back to the north."
    );
  SetItems( ([
    ({"greenery" }) : 
    "The few plants here seem dwarfed from lack of light and water.",
    ({"barracks" }) : 
    "It is a very big barracks. ",
    ({"house", "houses" }) : 
    "The residences belong to gnoll citizens.",
    ]) );
  SetExits( ([
   "north" : LISHT_ROOM "gnoll/wr3",
   "south" : XANDRIA_AREAS "newbie/room/1a",
    ]) );
  SetEnters( ([
   "barracks" : LISHT_ROOM "gnoll/barracks",
    ]) );
  SetSmell("The air smells clean and fresh.");
  SetListen("Random noise comes from the inn and other buildings.");
}
