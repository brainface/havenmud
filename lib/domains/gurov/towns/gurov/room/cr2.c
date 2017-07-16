#include <lib.h>
#include "../gurov.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetExits( ([
    "north" : GUROV_ROOM "cr3",
    "south" : GUROV_ROOM "cr1",
    ]) );
  SetShort("along the Center Road");
  SetLong(
    "The Center Road leads off to the north and south from here. Off "
    "to the north the road leads deeper into town, while to the "
    "south the road leads back towards the town wall and the city gate. "
    "A small house sits casually along the road, home to a Gurov family. "
    "The thinly paved road isn't much, but it does an excellent job of "
    "guiding people through the capital of the Principality."
    );
  SetItems( ([
    "wall" : "The town wall is off to the south.",
    "gate" : "The gate is off to the south.",
    "house" : "The small house seems cozy and lived in.",
    "road"  : "The road is paved with thin stones.",
    ({ "stone", "stones" }) : "The stones are thin but servicible as "
              "paving.",
    ]) );
  SetItemAdjectives( ([
    "wall" : ({ "town", "city" }),
    "gate" : ({ "town", "city" }),
    "house" : ({ "small", "cozy" }),
    "road" : ({ "thinly", "paved" }),
    "stone" : ({ "thin", "paving" }),
    ]) );
  SetEnters( ([
    "house" : GUROV_ROOM "houses/house2",
    ]) );
  SetSmell( ([
    "default" : "The air is crisp and smells clean.",
    ]) );
  SetListen( ([
    "default" : "The occasional sound of city life echoes along the road.",
    ]) );
}