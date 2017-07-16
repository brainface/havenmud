//--    Torak@Haven    --//
//-- Obsidian Apostles --//

#include <lib.h>
#include "obsidian.h"
inherit LIB_ROOM;

static void create() {

  room::create();
  SetDomain("Estergrym");
  SetClimate("indoors");
  SetShort("a resting room");
  SetLong("This small area seems to be a resting "
          "place of sorts that only members may use.  "
          "A couch and table are here for drinking "
          "and reading.  A hallway south leads back "
          "to the main hall.");
  SetItems( ([
    ({ "area", "place" }) :
       (: GetLong :),
    ({ "couch", "table" }) :
       "The couch is comfortable and a table sits in "
       "front of it for studying and drinking.",
    ({ "hallway" }) :
       "The hallway leads back out to the main hall.",
    ]) );
  SetInventory( ([
/*
OBSIDIAN + "board" : 1,
*/
    ]) );
  SetProperty("no teleport",1);
  SetExits( ([
    "south" : OBSIDIAN + "main",
  ]) );
  }
