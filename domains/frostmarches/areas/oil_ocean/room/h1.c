//Illura@haven
//h1
//Nov 2010
#include <lib.h>
#include <std.h>
#include <dirs.h>
#include "../oil.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("arid");
  SetShort("a geyser");
  SetLong(
    "The oil ocean's black, irregular surface extends in all "
    "directions from here, although the north and west are "
    "virtually impassable. Here among the smaller hissing "
    "vents is a huge hole that burbles and snorts boiling hot "
    "oil from deep below the ground. Warm, sticky fluid from "
    "earlier eruptions covers the ground."
  );
  SetExits( ([
    "south" : OIL_ROOM "/h2",
    "west" : OIL_ROOM "/g1",
  ]) );
  SetItems( ([
    ({"oil", "ocean"}) : "The oil ocean is composed of shifting dark sand and swirling oils, layered with water from the true ocean to the far west. The ground is stickier here because of the nearby geyser.",
    ({"vent", "vents"}) : "Steam and oil vapor are released from the vents. It doesn't smell very good.",
    ({"hole", "geyser"}) : "The enormous hole in the ground makes a lot of obnoxious noises and occasionally lets loose a fountain of searing hot oil. Best to keep your distance.",
  ]) );
  SetItemAdjectives( ([
    "vent" : ({"smaller", "hissing"}),
    "hole" : ({"huge"}),
    "fluid" : ({"warm", "sticky"})
  ]) );
  SetInventory( ([
    OIL_NPC + "lizard" : 3,
  ]) );
  SetListen( ([
    "default" : "The geyser bubbles and emits noises almost as bad as an ogre after a pot of gelfling stew.",
  ]) );
  SetSmell( ([
    "default" : "The air is acrid, full of vapor that stings your nose.",
  ]) );
}
