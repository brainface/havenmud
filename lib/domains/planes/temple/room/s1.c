/*  Lamrani Temple, Southern Hallway, Room 1 */
#include <lib.h>
#include "../temple.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetProperty("lower plane",1);
  SetClimate("indoors");
  SetAmbientLight(35);
  SetShort("along the southern hallway");
  SetExits( ([
    "north" : TEMPLE_ROOM "entrance",
    "south" : TEMPLE_ROOM "s2",
    "west"  : TEMPLE_ROOM "s3",
    ]) );
  SetLong("The marble floor continues off to the south, north, and west. "
          "The scenes on the walls have taken a violent turn, depicting "
          "scenes of war, carnage, and other extremely violent deaths. "
          "To the west, there appears to be some kind of prayer room, "
          "while to the south is a large and open choir room.");
  SetListen( ([
     "default" : "The chanting sound comes from the south.",
      ]) );
  SetSmell( ([
      "default" : "The smell of incense comes from the west.",
    ]) );
 }
