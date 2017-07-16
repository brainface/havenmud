
/* A room in the kingdom
   Elasandria 4/9/98
*/
#include <lib.h>
#include "../kingdom.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a path");
  SetDomain("FrostMarches");
  SetClimate("temperate");
  SetLong(
    "This path appears to be seldomly used and has become overgrown. "
    "To the east lies the road to Keryth. To the west, however, a "
    "dense wall of trees seems to bar the way."
  );
  SetItems( ([
    ({"lush plant","plants","fern","ferns"}) : "These plants are lush "
      "and green and sparkle with a dewy wetness.",
    ({"dense tree","trees","tree","forest","wall"}) : "The subtle way "
      "the trees seem to be shifting appears to be an illusion.",
    "path" : "This path is barely wide enough for a sprite to walk "
      "through as it is choked with sprawling ferns.",
    "road" : "This road leads north to the town Keryth.",
  ]) );
  SetItemAdjectives( ([
    "lush plant" : ({"green","sprawling"}),
  ]) );
  SetSmell( ([
    "default" : "The faint smell of wet earth is carried on the wind.",
  ]) );
  SetListen( ([
    "default" : "The faint rustling of leaves can be heard.",
  ]) );
  SetInventory( ([
  ]) );
  SetExits( ([
    "northwest" : KINGDOM_ROOMS + "kingdom15",
    "west" : KINGDOM_ROOMS + "kingdom20",
    "east" : "/domains/frostmarches/virtual/frostmarchrd/0,28"
  ]) );
}
