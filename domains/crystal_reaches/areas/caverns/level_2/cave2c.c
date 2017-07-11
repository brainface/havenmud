/*  Level #2 - Cavern #2 - Section #3  */

#include <lib.h>
#include "../caves.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("underground");
  SetAmbientLight(0);
  SetShort("a small cavern");

  SetLong("This corner of the cavern isn't all that unusual.  The great "
          "forest of rock formations continues on to block you sight in all "
          "directions.  The cavern walls here are worn smooth from the years "
          "of water trickling down from the ceiling.");

  SetSmell( ([
    "default"  :  "The damp air is mingled with the smell of the limestone "
                  "rock that makes up the cavern.",
  ]) );

  SetListen( ([
    "default"  :  "There is a fluttery sound that is echoing around the "
                  "cavern.",
  ]) );

  SetSearch( ([
    ({ "walls", "wall" })  :  "You get your hand covered with limestone mud.",
  ]) );

  SetExits( ([
    "north"      :  ROOMLV2 + "/cave2a",
    "northeast"  :  ROOMLV2 + "/cave2b",
    "east"       :  ROOMLV2 + "/cave2d",
  ]) );
  SetObviousExits("north, northeast, east");

  SetItems( ([
    ({ "small cavern", "cavern" })  :  (: GetLong :),
    ({ "ceiling", "water" })  :
       "Water that has seeped through the ceiling drips down to form the rock "
       "formations that are so prevalent here.  It has also trickled down "
       "the walls and worn them smooth over the years.",
    ({ "wall", "walls", "cavern wall", "cavern walls", "surface" })  :
       "The walls have been worn smooth by the water that has seeped in "
       "through the ceiling.  Over the years the water has slowly eroded and "
       "all of the roughness to the surface.",
    ({ "rock formations", "rock formation", "formations", "formation" })  :
       "Rock formations spread out around you like a forest and quickly block "
       "your view in every direction.  The rock formations are far enough "
       "apart in some area to provide passage to the other parts of the "
       "cavern.",
  ]) );

  SetInventory( ([ NPCS + "/bat" : 1, ]) );
}
