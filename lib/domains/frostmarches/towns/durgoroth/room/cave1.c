// updated lib chapel 2/june torak@haven

#include <lib.h>
#include "../durgoroth.h"

inherit LIB_CHAPEL;

static void create() {
  ::create();
  SetClimate("indoors");
  SetAmbientLight(45);
  SetShort("within the cave");
  SetLong("The cave is dark and dreary. The only"
          " light a light blue ambient light that" 
          " seems to have no source. The walls of the"
          " cave have been made smooth by what can"
          " only be assumed was magical means. The"
          " cave continues to the north or one may"
          " exit through the mouth of the cave.");
  SetInventory( ([
          DURG_NPC "shaman" : 1,
     ]) );
  SetReligion("Saahagoth");
  SetListen( ([
          "default" : "A soft humming echoes throughout"
                      " the cave.",
     ]) );
  SetExits( ([
       "out" : DURG_ROOM "road09",
       "north" : DURG_ROOM "start",
     ]) );
}
