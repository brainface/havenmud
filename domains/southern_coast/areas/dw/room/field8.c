#include <lib.h>
#include "../newbie.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a desolate field");
  SetClimate("sub-arctic");
  SetDayLong("The daylight is no comfort in this bleak patch "
             "of ruined field. To the west a large structure "
             "rises above the ground in a hideous mockery of the "
             "new cemetery. The land is passable in many directions "
             "from here, with easier ground to the west."
              );
  SetNightLong("The stars give no aid to the traveller as they shine "
               "down onto the ruined lands of the old cemetery. To the west "
               "a large structure rises into the sky like a black hand "
               "grasping the night. The ground is passable to the north, "
               "south, and west.");
  SetSmell( ([
    "default" : "The putrid odor of death hangs in the air.",
    ]) );
  SetListen( ([
    "default" : "Silence is the only sound.",
    ]) );
  SetItems( ([
    "structure" : "The structure appears to be some kind of crypt.",
    ]) );
  SetInventory( ([
    NEWBIE_NPC + "/skel" : 2,
   ]) );
  SetDayLight(-10);
  SetExits( ([
     "north" : NEWBIE_ROOM + "/field9",
     "west"  : NEWBIE_ROOM + "/field5",
     "south" : NEWBIE_ROOM + "/field7",
     ]) );
  }
