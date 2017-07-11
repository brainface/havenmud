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
    "This broad road follows the line of the wall southward. "
    "Several houses line the road, which is kept clean and free "
    "of debris. At certain times of the day, this street is shrouded "
    "in shadow cast from the wall, which stunts the greenery. A "
    "crossroads stands here, with an alleyway leading west toward "
    "the Great Library, and further, the Enniae Temple. The road "
    "follows the wall south to the barracks and north, to the gate."
    );
  SetItems( ([
    ({"greenery" }) : 
    "The few plants here seem dwarfed from lack of light and water.",
    ({"house", "houses" }) : 
    "The residences belong to gnoll citizens.",
    ]) );
  SetExits( ([
   "north" : LISHT_ROOM "gnoll/wr1",
   "south" : LISHT_ROOM "gnoll/wr3",
   "west" : LISHT_ROOM "gnoll/sa2",
    ]) );
  SetSmell("The air smells clean and fresh.");
  SetListen("The sounds of the city can be heard.");
}
