/*  The entrance to the caves/(my area)  */

#include <domains.h>
#include <lib.h>
#include "../caves.h"
inherit LIB_ROOM;

int PreExit(string);

static void create() {
  room::create();
  SetClimate("underground");
  SetShort("at the end of a downward tunnel");
  SetLong("The path levels off here, with branches leading east and northwest. "
             "To the northwest, the tunnel leads further "
             "into the caverns. There is a noticeable path leading to "
             "the tunnel as it is worn smooth and the ground has been "
             "cleared of debris. To the east, the path seems to lead "
             "into some kind of lair.");
  SetSmell( ([
    "default"  :  "Stale air and wet fur are mingling in the breeze.",
    ]) );
  SetListen( ([
    "default"  :  "A deep growling comes from the east.",
    ]) );
  SetExits( ([
    "northwest"  :  ROOMLV1 + "-8,-3,-1",
    "east"       :  ROOMLV1 + "-6,-4,-1",
    ]) );
  AddExit("up", ROOMLV1 + "-7,-4,0", (: PreExit :) );
  SetItems( ([
    ({ "cave entrance", "entrance" })  :  (: GetLong :),
    ({ "path", "noticeable path", "worn path" })  :
       "The path is worn from years of use and has been cleared of debris.",
    ({ "rock", "rocks", "debris", "ground" })  :
       "The small rocks that litter the room have been cleared along the "
       "path leading to the northwest.",
    ({ "walls", "wall" })  :
       "The walls seem to dance in the dim light as shadows dance in the "
       "cracks of the rough wall.",
     ]) );
}

int PreExit(string dir) {
  if(this_player()->GetProperty("Telgos")) {
    return 0;
  }
  else {
    return 1;
  }
}
