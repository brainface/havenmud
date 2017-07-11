//Illura@haven
//Room 12
//August 2009
#include <lib.h>
#include <std.h>
#include <dirs.h>
#include "../taiga.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("sub-arctic");
  SetShort("Within the verdant taiga");
  SetLong(
    "Where shallow drifts of snow do not cover it, the boreal "
    "mosses are a deep, bright green, thriving with growth. "
    "Clipped edges on the lichens show that where they spring "
    "up, they provide a tasty treat for the elk roaming here. "
    "The taiga thickens to the south, and the snows grow deeper "
    "as one trudges northward."
  );
  SetExits( ([
    "south" : TAIGA_ROOM "9",
    "east" : TAIGA_ROOM "13",

    "north" : TAIGA_ROOM "14",
    "west" : TAIGA_ROOM "11",
  ]) );
  SetItems( ([
    ({"snow", "drifts", "drift"}) : "The snow is white and windblown.",
    ({"moss", "mosses"}) : "Emeraldine green, peeking out between piles of snow.",
    ({"lichen", "lichens"}) : "Tasty greenery for roaming elk.",
  ]) );
  SetItemAdjectives( ([
    "drifts" : "shallow",
    "moss" : "boreal"
  ]) );
  SetInventory( ([
    TAIGA_NPC + "elk" : 4,
  ]) );
  SetListen( ([
    "default" : "The wind whips across the taiga.",
  ]) );
  SetSmell( ([
    "default" : "The air is crisp and cool.",
  ]) );
}
