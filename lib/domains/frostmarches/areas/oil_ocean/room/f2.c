//Illura@haven
//f2
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
    "The barren landscape is littered here with scraps of metal "
    "and raw ore, as well as twisted, warped planks of old "
    "wood. A smudgy, lumpy track is worn into the bitumen "
    "that covers the oil underneath, seemingly worn by "
    "small feet and the wheels of narrow carts. To the west "
    "you can make out a smoking structure."
  );
  SetExits( ([
    "north" : OIL_ROOM "/f1",
    "south" : OIL_ROOM "/f3",
    "west" : OIL_ROOM "/e2",
    "east" : OIL_ROOM "/g2"
  ]) );
  SetItems( ([
    ({"oil"}) : "The oil ocean is composed of shifting dark sand and swirling oils, layered with water from the true ocean to the far west.",
    ({"metal", "scraps", "ore", "plank", "planks", "wood"}) : "There is evidence of civilization strewn all around, the leavings from some factory or settlement of some kind.",
    ({"track"}) : "The track can hardly be called a road, and is made only of crunchy, compressed bitumen."
  ]) );
  SetItemAdjectives( ([
    "ore" : ({"raw, old"}),
    "track" : ({"smudgy", "lumpy"}),
  ]) );
  SetInventory( ([
    OIL_NPC + "oilhorse" : 5,
  ]) );
  SetListen( ([
    "default" : "A banging and whirring noise of activity can distantly be heard.",
  ]) );
  SetSmell( ([
    "default" : "The air hangs thickly with smoke and tar.",
  ]) );
}
