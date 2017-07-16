//Illura@haven
//Room 11
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
    "south" : TAIGA_ROOM "8",
    "east" : TAIGA_ROOM "12",

  ]) );
  SetItems( ([
    ({"snow", "drifts", "drift"}) : "The snow is white and windblown.",
    "moss" : "Emeraldine green, peeking out between piles of snow.",
    ({"lichen", "lichens"}) : "Tasty greenery for roaming elk.",
  ]) );
  SetItemAdjectives( ([
    "moss" : "boreal",
    "drifts" : "shallow"
  ]) );
  SetInventory( ([
    TAIGA_NPC + "elk" : 3,
  ]) );
  SetListen( ([
    "default" : "The wind whips across the taiga.",
  ]) );
  SetSmell( ([
    "default" : "The air is crisp and cool.",
  ]) );
}
