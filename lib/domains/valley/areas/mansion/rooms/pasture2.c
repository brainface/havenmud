/* a small pasture
    kyla 1-98 
*/
#include <lib.h>
#include "../mansion.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a small clearing");
SetDomain("Valley");
  SetClimate("temperate");
  SetExits( ([
          "north" : MANSION_ROOMS + "clearing2",
          "east" : MANSION_ROOMS + "pasture3",
          "west" : MANSION_ROOMS + "pasture1",
          "southeast" : MANSION_ROOMS + "pasture4",
          "northeast" : MANSION_ROOMS + "clearing3",
          "northwest" : MANSION_ROOMS + "clearing1",
          ]) );
  SetListen( ([
          "default" : "Mooing can be heard in the distance.",
           ]) );
  SetSmell( ([
         "default" : "The smell of long grass is prominant here.",
          ]) );
  SetInventory( ([
         PASTURE_NPC + "cow" : 2,
         PASTURE_NPC + "horse" : 1,
              ]) );
  SetLong("This part of the pasture looks like it is used quite often. "
         "The grass is long here and the ground is covered with footprints. "
         "The pasture stretches to the west and to east. To the north lies "
         "a small clearing, and a large building lies to the south.");
  SetItems( ([
       "grass" : "The grass is long and some of it has been chewed.",
       "ground" : "The ground is covered with footprints.",
     ({"footprint", "footprints"}) : "These are large hooved footprints.",
       "clearing" : "The clearing is north of here.",
       "building" : "This is the wall of a large building.",
        "wall" : "This is a large wooden wall.",
           ]) );
  }
