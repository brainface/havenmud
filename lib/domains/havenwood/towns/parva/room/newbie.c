#include <lib.h>
#include "../parva.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetShort("a comfortable office in Parva");
  SetExits( ([
    "west" : PARVA_ROOM "town_hall",
    ]) );
  SetClimate("indoors");
  SetAmbientLight(35);
  SetLong(
    "This comfortable office houses the local board of captains. The "
    "board of captains seeks to insure that all citizens of Parva are "
    "equipped properly, so as not to embarrass the city. A weapons rack "
    "sits at the back of the wall, and a small selection of utility items "
    "hang on the walls."
    );
  SetInventory( ([
    PARVA_NPC "newbie_helper" : 1,
      PARVA_OBJ "donation" : 1,
    ]) );
  SetItems( ([
    "rack" : "The weapons rack has a limited selection of basic weapons.",
    ({ "item", "items" }) : "Some basic utility items, like a fishing pole, hang on the walls.",
    ]) );
}
