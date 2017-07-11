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
    "well-lit inn stands on the western side of the road here, and "
    "the road leads both north toward the gate and south toward a "
    "crossroads and the barracks."
    );
  SetItems( ([
    ({"greenery" }) : 
    "The few plants here seem dwarfed from lack of light and water.",
    ({"inn" }) : 
    "The door of the inn is carved with a lotus blossom. ",
    ({"house", "houses" }) : 
    "The residences belong to gnoll citizens.",
    ]) );
  SetExits( ([
   "north" : LISHT_ROOM "gnoll/gate",
   "south" : LISHT_ROOM "gnoll/wr2",
    ]) );
  SetEnters( ([
   "inn" : LISHT_ROOM "gnoll/inn",
    ]) );
  SetSmell("The air smells clean and fresh.");
  SetListen("Random noise comes from the inn and other buildings.");
}
