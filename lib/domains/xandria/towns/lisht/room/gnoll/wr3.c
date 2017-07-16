//Selket@Haven
//2006
#include <lib.h>
#include <domains.h>
#include "../../lisht.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("arid");
  SetShort("Along Wall Road");
  SetLong(
    "This broad road follows the line of the Wall southward. "
    "Several houses line the road, which is kept clean and free "
    "of debris. At certain times of the day, this street is shrouded "
    "in shadow cast from the wall, which stunts the greenery. A "
    "crossroads is to the north, and to the south stands the "
    "city Barracks. "
    );
  SetItems( ([
    ({"greenery" }) : 
    "The few plants here seem dwarfed from lack of light and water.",
    ({"house", "houses" }) : 
    "The residences belong to gnoll citizens.",
    ]) );
  SetExits( ([
   "north" : LISHT_ROOM "gnoll/wr2",
   "south" : LISHT_ROOM "gnoll/wr4",
    ]) );
  SetSmell("The air smells clean and fresh.");
  SetListen("The sounds of the city can be heard.");
  SetInventory( ([
    LISHT_NPC  + "leatherequipper" : 1
  ] ));
}
