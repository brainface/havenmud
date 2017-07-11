#include <lib.h>
#include "../newbie.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a desolate field");
  SetInventory( ([
    NEWBIE_NPC "/lowskel" : random(3) + 1,
    ]) );
  SetClimate("sub-arctic");
  SetLong("The desolate fields of the Old Cemetery spread out to the "
          "south and west from here. To the west lies the path leading "
          "back into the new cemetery. Off to the southwest lies a small "
          "structure rising from the ground like a forgotten soldier.");
  SetItems( ([
     "structure" : "An old crypt rises from the ground to the southwest.",
    ]) );
  SetSmell( ([
    "default" : "The rotten smell of old decayed flesh rises from the ground.",
     ]) );
  SetListen( ([
    "default" : "The eerie silence is chilling.",
    ]) );
  SetDayLight(-10);
  SetExits( ([
     "south" : NEWBIE_ROOM + "/field8",
     "west"  : NEWBIE_ROOM + "/field6",
     ]) );
  }
