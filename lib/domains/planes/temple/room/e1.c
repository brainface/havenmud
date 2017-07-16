/*  Lamrani Temple, East Room #1 */
#include <lib.h>
#include "../temple.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetProperty("lower plane", 1);
  SetClimate("indoors");
  SetShort("along a hallway in the temple");
  SetAmbientLight(35);
  SetExits( ([
    "west" : TEMPLE_ROOM "entrance",
    "south" : TEMPLE_ROOM "e2",
    ]) );
  SetSmell( ([
    "default" : "The scent of incense is slightly less overwhelming here.",
    ]) );
  SetListen( ([
    "default" : "The sound of chanting is fainter here.",
    ]) );
  SetLong("Along this hallway in the temple, the symbols on the walls "
          "appear more serene, as if to suggest death in natural ways. "
          "The marble floor continues to lead into the temple to the "
          "south and back to the west towards the entrance to the "
           "temple proper.");
  SetItems( ([
    "floor" : "The floor is made of marble, and is exquisitely polished.",
    ({ "symbol", "symbols" }) : "The symbols of death are less violent "
                                "here, suggesting a quiet death.",
    ]) );
 }
