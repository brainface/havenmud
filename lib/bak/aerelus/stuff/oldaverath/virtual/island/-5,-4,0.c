/*  by Duhoc Feb.2. 99 */
/*  entrance.c   -- the entrance */

#include <lib.h>
#include <domains.h>
#include "../glim.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("temperate");
  SetShort("near a large mountain");
  SetLong("To the west, a narrow path leads up the mountain between "
   "two jagged peaks of rock. Large boulders along "
   "with relatively small stones litter the path and cause it to curve "
   "and twist rather chaotically as it makes it way westwards. "
   "The stones are jagged and broken, as if they were cast down "
   "from the mountain's peaks by some tremendous upheaval. "
   "To the north and east, the plains of Averath seem to stretch out "
   "infinately, while to the south the sea can be seen off to the south.");
  SetItems( ([
    ({"path"}) :
      "The mountain path goes between to great peaks of rock "
      "and out of sight.",
    ({"wall", "walls", "valley"}) :
      "The walls of the narrow valley are chaotically positioned.",
    ({"boulder", "boulders", "stone", "stones"}) :
      "The stones are jagged and seem to have been ripped from "
      "neaby peaks by a terrible force.",
    ({"peak", "peaks"}) :
      "The nearby peaks tower into the sky and are both part "
      "of one father mountain.",
     ({ "mountain" }) : 
         "This mountain houses Glistendin, the home of the Averath Dwarves.",
  ]) );
 
  SetItemAdjectives( ([
     "path"    : ({"narrow", "winding", "curving", "rocky", "rugged",
                   "mountain"}),
     "wall"    : ({"stone", "chaotic"}),
     "boulder" : ({"jagged", "broken"}),
     "peak"    : ({"jagged", "towering"}),
  ]) );

  SetExits( ([
    "north" : AVERATH_ISLAND "-5,-3,0",
    "south" : AVERATH_ISLAND "-5,-5,0",
    "east"  : AVERATH_ISLAND "-4,-4,0",
    "west"  : AVERATH_ISLAND "-6,-4,0",
  ]) );

  SetSmell( ([
    "default" : "The air smells earthen.",
  ]) );

  SetListen( ([
    "default" : "Stones rattle as they tumble down the slopes.",
  ]) );

}

