//Illura@haven
//Room 19
//August 2009
#include <lib.h>
#include <std.h>
#include <dirs.h>
#include "../taiga.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("arctic");
  SetShort("at the edge of the Gurovian Wastes");
  SetLong(
    "The Wastes are a widely expanding, mostly impassible "
    "tundra region. The wind whips at the constantly changing "
    "terrain of glittering snowdrifts. Some of the drifts are "
    "piled in the shapes of frozen creatures, even looking at "
    "first like people made of frozen, glimmering ice crystal. "
    "Southward stands an ancient boreal woodland."
  );
  SetExits( ([
    "south" : TAIGA_ROOM "16",
    "north" : TAIGA_ROOM "22",
    "west" : TAIGA_ROOM "18",
  ]) );
  SetItems( ([
    "trees" : "The few trees here are black and withered.",
    ({"drifts", "snow"}) : "Snow covers the ground and stands in piles that look almost like people.",
    ({"crystal", "ice"}) : "Ice covers the snow in glassine sheets.",
    "forest" : "The taiga is south.",
  ]) );
  SetItemAdjectives( ([
    "trees" : "black",
    "drifts" : "blown",
    "forest" : "boreal",
  ]) );
  SetInventory( ([
    TAIGA_NPC + "mistress" : 3,
  ]) );
  SetListen( ([
    "default" : "The wind howls across the wastes.",
  ]) );
  SetSmell( ([
    "default" : "The thin air leaves your nostrils tingling.",
  ]) );
}
