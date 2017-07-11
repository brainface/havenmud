#include <lib.h>
#include "path.h"

inherit LIB_ROOM;

static void create() {
    room::create();
    SetShort("a gloomy hallway");
    SetLong("Flickering torches line the walls of the keep.  The floor is damp "
          "and musty, and a draft is blowing in from the gatehouse.  "
          "The hallway leads west to the library, and south down a dark "
          "passage.");
    SetItems( ([
          ({ "torches" }) :
          "The torches light up the hallway.",
          ({ "dark passage", "passage" }) :
          "The destination of the hallway to the south cannot be seen "
          "through the darkness.",
          ({ "library" }) :
          "Hundreds of books on huge bookcases can be seen in the next room.",
          ({ "gatehouse" }) :
          "The gatehouse is the main entryway to the keep.",
          ({ "mold" }) :
          "The mold is green with blue spots.",
          ({ "hallway", "hall" }) :
          (: GetLong :),
          ({ "floor" }) :
          "The floor is damp and there are patches of mold growing on it.",
          ({ "walls" }) :
          "Strange shadows are cast on the walls by the flickering torches.",
          ]) );
    SetExits( ([
          "west" : BEORN_ROOM + "library.c",
          "east" : BEORN_ROOM + "gatehouse.c",
          "south" : BEORN_ROOM + "hall3.c",
           ]) );
    SetObviousExits("west, east, south");

    SetClimate("indoors");
    SetAmbientLight(30);
}
