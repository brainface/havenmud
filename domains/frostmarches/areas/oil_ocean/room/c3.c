//Illura@haven
//c3
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
    "The syrupy oils and clumps of bitumen that make up the "
    "expanse of the Great Oil Ocean is all that you can see from "
    "horizon to horizon. Standing like the houses of sprites "
    "are small forms of white coral, bleached reefs that must "
    "have been living before the oil edged out into the sea. Most "
    "of these delicate structures have sunk below the surface, "
    "but what remains of the lacy coral makes you ponder "
    "your own tenuous mortality."
  );
  SetExits( ([
    "north" : OIL_ROOM "/c2",
    "south" : OIL_ROOM "/c4",
    "west" : OIL_ROOM "/b3",
    "east" : OIL_ROOM "/d3",
  ]) );
  SetItems( ([
    ({"oils", "oil", "clump", "clumps", "bitumen", "ocean"}) : "The Oil Ocean extends in all directions, made of tar sands and black substances that swirl and shimmer and ooze mysteriously.",
    ({"coral", "reef", "reefs", "forms"}) : "These reefs must have been the homes to tiny fish and other sea creatures in the forgotten past.",
  ]) );
  SetItemAdjectives( ([
    "oils" : ({"syrupy"}),
    "coral" : ({"white", "bleached", "delicate", "lacy"}),
  ]) );
  SetInventory( ([
    OIL_NPC + "creature" : 3,
  ]) );
  SetListen( ([
    "default" : "A slurping noise comes from the ground, as though the oil digests everything that sinks down into it.",
  ]) );
  SetSmell( ([
    "default" : "An ancient oceanic scent permeates the air.",
  ]) );
}
