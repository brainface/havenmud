#include <lib.h>
#include <domains.h>
#include "../../planes.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetShort("on the plane of Fire");
  SetLong(
          "The ground has a bright red hue to it which is constantly changing shade. "
          "The ground here continually moves upward and downward as molten rock shifts "
          "under the surface. The searing red landscape stretches in all directions. "
          "There seems to be a form of plant life here but it is charred and dead. "
          "The land is a bleak and lifeless deadland. There is a radiant pillar of light "
          "to the southwest. There is a large castle here.");
  SetItems( ([
     "castle" : "A large castle rests here as if the plane formed around it.",
   ]) );
  
  SetItemAdjectives( ([
     "castle" : ({ "large" }),
    ]) );
  SetProperty("lower plane",1);
  SetClimate("arid");
  SetProperty("no weather", 1);
  SetEnters( ([
    "castle" : "/domains/planes/firecastle/room/room1",
    ]) );
  SetExits( ([
     "north" : FIRE_PLANE + "15,16",
     "south" : FIRE_PLANE + "15,14",
     "west"  : FIRE_PLANE + "14,15",
     "east"  : FIRE_PLANE + "16,15",
    ]) );
  SetSmell( ([
     "default" : "The air is tinged with the odor of smoke.",
    ]) );  
 }
