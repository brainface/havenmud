/*  Level #2 - Cavern #2 - Section #2  */

#include <lib.h>
#include "../caves.h"
inherit LIB_ROOM;
int PreExit(string);

static void create() {
  room::create();
  SetClimate("underground");
  SetAmbientLight(0);
  SetShort("a small cavern");

  SetLong("This part of the cavern has a winding path leading off to the "
          "northeast, it is almost unnoticeable behind the large rock "
          "formations there.  Rock formations block your sight in every "
          "direction around you.  However, there are openings wide enough to "
          "be considered paths through the rock formations.");

  SetSmell( ([
    "default"  :  "The air is damp with the scent of limestone rock.",
  ]) );

  SetListen( ([
    "default"  :  "A high pitched squeaking echoes throughout the cavern.",
  ]) );

  SetExits( ([
    "west"       :  ROOMLV2 + "/cave2a",
    "southwest"  :  ROOMLV2 + "/cave2c",
    "south"      :  ROOMLV2 + "/cave2d",
  ]) );
  AddExit("northeast", ROOMLV2 + "/oldhag", (: PreExit :));


  SetItems( ([
    ({ "small cavern", "cavern" })  :  (: GetLong :),
    ({ "winding path", "path", "hidden path" })  :
       "The winding path is very well hidden behind several large rock "
       "formations.  The path winds out of view quickly.",
    ({ "large rock formations", "large rock formation" })  :
       "These large rock formations off to the northeast conceal a hidden "
       "path.  The path in behind winds out of view quickly.",
    ({ "rock formations", "rock formation", "formations", "formation",
       "ancient formations", "ancient formation" })  :
       "Rock formations are plentiful here and block your sight of the cavern "
       "in every direction around you.  There are openings between these "
       "ancient formations that are wide enough to be considered paths to the "
       "other parts of the cavern.",
    ({ "paths" })  :
       "Openings wide enough to be considered paths go through the forest of "
       "rock formations.",
  ]) );

  SetInventory( ([ NPCS + "/bat" : 1, ]) );
}

int PreExit(string dir) {
  if(this_player()->GetProperty("Telgos")) {
    return 0;
  }  else {
    return 1;
  }
}
