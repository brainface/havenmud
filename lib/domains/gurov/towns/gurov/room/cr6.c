#include <lib.h>
#include "../gurov.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetExits( ([
    "north" : GUROV_ROOM "cr7",
    "south" : GUROV_ROOM "cr5",
    "west"  : GUROV_ROOM "alley1",
    ]) );
  SetShort("The Center Road by a small alley");
  SetLong(
    "The Center Road continues to the north and south from here. "
    "Lying directly to the west is a small alley that seems ill-kept. "
    "Further along to the north lies the Gurov Bay, where ships from "
    "far off ports make calls to trade with the Principality. In the "
    "distance to the south lies the city gate and town wall that "
    "protect the city from invaders."
    );
  SetItems( ([
    "alley" : "The alley is fairly poorly lit and does not seem to be affluent.",
    ]) );
  SetSmell("A strange odor comes from the alley.");
  SetListen("City life fills the road with sound.");
}