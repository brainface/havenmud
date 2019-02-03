#include <lib.h>
#include "../gurov.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("sub-arctic");
  SetExits( ([
    "east" : GUROV_ROOM "pr3",
    "west" : GUROV_ROOM "pr1",
    ]) );
  SetShort("the Prince's Road in front of the Keep");
  SetLong(
    "The Prince's Road passes in front of the Keep here. The keep is a "
    "large and imposing structure that serves as the base of defense for "
    "the Principality. Off to the east, the road leads to a dead-end in "
    "front of the town wall, while to the west the road connects with "
    "the Center Road that travels through town."
    );
  SetSmell("The smells of the city are pungent and welcome.");
  SetListen("Echoes from the town reverberate off the keep and town wall.");
  SetItems( ([
    "keep" : "The Keep of the Prince of Gurov is a large and easily defensible structure.",
    ]) );
  SetEnters( ([
    "keep" : GUROV_ROOM "keep1",
    ]) );
}