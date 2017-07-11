#include <lib.h>
#include <domains.h>
#include "../../lisht.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("arid");
  SetExits( ([
    "west" : LISHT_ROOM "gnoll/pr2",
    "east" : LISHT_ROOM "gnoll/gate",
    ]) );
  SetShort("on the Pharaoh's Road");
  SetLong(
    "The Pharaoh's Road leads east and west from here. To the west the road meets "
    "the Lisht Bazaar, a madhouse of sellers and buyers attempting to meet a deal "
    "at all hours of the day. To the east lies the Wall of Lisht, which seperates "
    "the citizens' homes from those of the elven slaves."
    );
  SetSmell("The city is clean and neatly maintained.");
  SetInventory( ([
    ]) );
}
