//Illura@haven
//Room 18
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
    "Not called a waste for nothing, the tundra is empty of "
    "nearly anything but snow and the occasional stunted black "
    "tree. Some of the drifts look at first glance like monsters "
    "half-formed, frozen in stasis under a sheet of shimmering "
    "ice crystal. To the south stands an ancient boreal forest."
  );
  SetExits( ([
    "south" : TAIGA_ROOM "15",
    "north" : TAIGA_ROOM "21",
    "east" : TAIGA_ROOM "19",
     "west" : TAIGA_ROOM "17",
  ]) );
  SetItems( ([
    "trees" : "The few trees here are black and withered.",
    ({"drifts", "snow"}) : "Snow covers the ground and stands in piles that look like frozen monsters.",
    ({"crystal", "ice"}) : "Ice covers the snow in glassine sheets.",
    "forest" : "The taiga is south.",
  ]) );
  SetItemAdjectives( ([
    "trees" : "black",
    "drifts" : "blown",
    "forest" : "boreal",
  ]) );
  SetInventory( ([
    TAIGA_NPC + "windrider" : 3,
  ]) );
  SetListen( ([
    "default" : "The wind howls across the wastes.",
  ]) );
  SetSmell( ([
    "default" : "The thin air leaves your nostrils tingling.",
  ]) );
}
