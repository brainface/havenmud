//Illura@haven
//f4
//Nov 2010
#include <lib.h>
#include <std.h>
#include <dirs.h>
#include "../oil.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("arid");
  SetShort("the great oil ocean");
  SetLong(
    "The oil ocean's black, irregular surface extends in all "
    "directions from here, dotted with pools of stale ocean "
    "water and sticky tarballs. The ooze creeps viscously "
    "in one direction, then another, almost with silent "
    "purpose."
  );
  SetExits( ([
    "north" : OIL_ROOM "/f3",
    "south" : OIL_ROOM "/f5",
    "west" : OIL_ROOM "/e4",
    "east" : OIL_ROOM "/g4",
  ]) );
  SetItems( ([
    ({"oil", "ooze"}) : "The oil ocean is composed of shifting dark sand and swirling oils, layered with water from the true ocean to the far west.",
    ({"ocean", "water"}) : "Water has seeped in from the underground aquafer in some places, but mostly the water is saline, carried by the wind from the western sea.",
    ({"tar", "ball", "balls", "tarballs"}) : "Some of the oil has coagulated with the water to form sticky tarballs. Mostly, they are round, but some of them display bite marks, as though something has been chewing on them. They don't look edible to you.",
  ]) );
  SetItemAdjectives( ([
    "water" : ({"stale"}),
    "tar" : ({"sticky"}),
  ]) );
  SetInventory( ([
    OIL_NPC + "lizard" : 3,
    OIL_NPC + "octopus" : 3,
  ]) );
  SetListen( ([
    "default" : "The only sound is the deadly slow shift of the ooze.",
  ]) );
  SetSmell( ([
    "default" : "The air stinks of sun-lit tar and stale water.",
  ]) );
}
