#include <lib.h>
#include "../yozrath.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetShort("in front of the Sheik's Palace");
  SetExits( ([
    "east" : YOZRATH_ROOM "oasis3",
    ]) );
  SetClimate("arid");
  SetLong(
    "The palm trees give way to a curved path that leads to "
    "the arched stone of the Sheik's Palace. Smooth brown "
    "sandstone is chiseled into a remarkable structure that "
    "demonstrates the skill of the Yozrathi craftsmen. To the "
    "east lies the central watering hole of the oasis, a focal "
    "point for the city of Yozrath."
    );
  SetItems( ([
    "palace" : "The palace of the Sheik is an intricately designed "
               "sandstone structure that is the marvel of the desert.",
    "path"   : "The curved path leads from the oasis to the palace.",
    "sandstone" : "The sandstone is smoothly hewn and well maintained.",
    ]) );
  SetItemAdjectives( ([
    "palace" : ({ "sheik's", }),
    "path"   : ({ "curved", }),
    "sandstone" : ({ "smooth", "brown" }),
    ]) );
  SetSmell("The faint smell of water comes from the east.");
  SetListen("The Sheik's Palace is quiet and calm.");
  SetEnters( ([
    "palace" : YOZRATH_ROOM "palace",
    ]) );
}

   