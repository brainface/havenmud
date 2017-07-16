
#include <lib.h>
#include "../defs.h"
#include <domains.h>


inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("indoors");
  SetObviousExits("northeast, northwest, southeast");
  SetShort("another fork in the cave");
  SetLong(
          "The cave forks off again in this section. Sand lies "
          "on the ground being brushed by a light draft. The "
          "east portion of the cave is a column which has been "
          "carved from the cavern wall itself. The ground "
          "bends off into three directions.");
  SetExits( ([
            "northeast"     : TOWER_ROOMS "cave10",
            "northwest"     : TOWER_ROOMS "cave11",
            "southeast"     : TOWER_ROOMS "cave07",
           ]) );
  SetSmell( ([
            "default" : "Something gives off a slight smell of sulfur.",
           ]) );
  SetListen( ([
            "default" : "The sifting of sand is heard from a soft draft."
           ]) );
  
  SetItems( ([
     "ceiling" : "The ceiling is rounded and bends off to the different "
                 "passages. A column is holding it up.",
     "walls"   : "The walls have a rough look to them and a crudely "
                 "formed column has been made near the east wall.",
     "column"  : "The column appears as if it was chiseled with an "
                 "old bladed instrument. It is in poor craft and "
                 "looks as though it is lax in quality. It still "
                 "does the job.",
     "sand"    : "The sand is a fine dark powder and gently wisps "
                 "about from a slight draft.", 
    ({ "ground", "floor" }) : "It is made of a dark packed clay and "
                               "lines the cavern ground. Some sections "
                               "are covered in a light sand trailing to "
                               "the northeast.",
              ]) );
    SetItemAdjectives( ([
    "column" : ({ "crudely","formed","cave" }),
    "sand" : ({ "fine","dark","powder" }),
  ]) );
}