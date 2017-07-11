#include <lib.h>
#include "../gurov.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetExits( ([
    "west" : GUROV_ROOM "pr2",
    "east" : GUROV_ROOM "pr4",
    ]) );
  SetShort("the Prince's Road");
  SetLong(
    "The road continues to the east and west from here. To the east, the road "
    "dead-ends into the town wall, while to the west the road passes in front "
    "of the Prince's Keep and continues off to connect with the Center Road, "
    "which is the main road through town. The thin paving stones here make the "
    "road passable in all seasons, but not by much."
    );
  SetSmell("The city smells of human life and pack animals.");
  SetListen("The sounds of the city fill the air.");
  SetItems( ([
    "road" : "The road is paved with thin stones and is fairly wide.",
    ({"stones", "stone" }) : "The paving stones are thin but allow the road "
                             "to be passable in all seasons.",
    ]) );
  SetItemAdjectives( ([
    "stones" : ({ "thin", "paving" }),
    ]) );
}