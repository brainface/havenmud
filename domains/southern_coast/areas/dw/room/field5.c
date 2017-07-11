#include <lib.h>
#include "../newbie.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a desolate field");
  SetClimate("sub-arctic");
  SetNightLong("At night, this area of the graveyard is a black hole "
              "in the land. Centered here is a large crypt which takes "
              "up a vast amount of space. Off in all directions the "
              "graveyard continues.");
  SetDayLong("The sunlight adds warmth, but little light, to this "
             "blighted area of desolate waste. In the center of this clearing "
             "is a large crypt, which dominates the view in all directions. "
             "In all directions, the ruins of the graveyard can be seen.");
  SetDayLight(-10);
  SetSmell( ([
    "default" : "The scent of old, rotted matter hangs in the air.",
  ]) );
  SetListen( ([
    "default" : "The sounds of life are lacking here.",
  ]) );
  SetExits( ([
     "north" : NEWBIE_ROOM + "/field6",
     "east"  : NEWBIE_ROOM + "/field8",
     "west"  : NEWBIE_ROOM + "/field2",
     "south" : NEWBIE_ROOM + "/field4",
     ]) );
  SetItems( ([
     "crypt" : "An ancient crypt.",
   ]) );
  SetEnters( ([
    "crypt" : NEWBIE_ROOM + "/crypt",
   ]) );
  }
