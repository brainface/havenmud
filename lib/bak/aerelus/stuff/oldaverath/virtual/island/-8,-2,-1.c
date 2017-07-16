/*  A Narrowing Path near the Gnome's Burrow */

#include <lib.h>
#include "../caves.h"
inherit LIB_ROOM;
int PreExit(string);

static void create() {
  room::create();
  SetClimate("indoors");
  SetAmbientLight(20);
  SetShort("a narrowing path");
  SetLong("This is a narrowing path that gently curves towards the west.  "
          "The ceiling and walls begin to close in to where the path is only "
          "six feet tall and a like width.  "
          "The ground seems exceptionally clean and worn from long use.  "
          "Around the corner up ahead a faint light is shining through, "
          "onto the path.");
  SetSmell( ([
    "default"  :  "The faint smell of burnt wood is noticable here.",
    ({ "wood", "burnt wood" })  :  "The smell of burnt wood tickles your "
                                   "nose.",
  ]) );
  SetExits( ([
    "south"  :  ROOMLV1 + "-8,-3,-1",
  ]) );
  AddExit("west", ROOMLV1 + "-9,-2,-1", (: PreExit :) );
  SetItems( ([
    ({ "path", "worn path", "narrowing path", "ground" })  :
       "A faint light shines onto the worn path up ahead.  The path appears "
       "to be cleaned by someone, as it is without dust or debris.",
    ({ "light", "faint light" })  :
       "The faint light spills out from around the corner up ahead.",
    ({ "ceiling", "walls", "wall" })  :
       "The walls and ceiling close in on you as you follow the path towards "
       "the faint light that lights the path ahead.",
    ({ "debris", "dust" })  :
       "There is no debris here! No dust either for that matter!",
  ]) );
}

int PreExit(string dir) {
  if(this_player()->GetProperty("Telgos")) {
    return 0;
  }  else {
    return 1;
  }
}
