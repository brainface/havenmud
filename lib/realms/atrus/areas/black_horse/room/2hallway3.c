/* 2hallway3.c for Black Horse Inn
   20MAY2013
   Atrus@Haven
*/

#include "../bhi.h"
#include <lib.h>
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("an upstairs hallway");
  SetClimate("indoors");
  SetAmbientLight(35);
  SetExits( ([
    "east" : "2hallway4",
    "south" : "2hallway2",
    ]) );
  SetLong(
         "Hallway3."
          );
  SetItems( ([
  ({ "lamps", "lamp" }) : "Two large oil lamps sit on the table.",
  ({ "beam", "beams" }) : "Heavy wooden beams make up the sub floor of the floor above.",
  ({ "ceiling", "up" }) : "Overlapping wooden planks make up the ceiling and in turn "
            "the roof of the entryway. They are tightly secured and tar smeared to "
            "prevent leaks and rot.",
  ({ "floor", "down", "ground", "path" }) : "The floor here is made of tight fitting logs that "
            "are sharply shaped to offer a flat walking surface. There is a well defined "
            "path worn from the south to the east.",
    ]) );
  SetItemAdjectives( ([
    ]) );
  SetInventory( ([
  ]) );
  SetSmell("The waft of roasting mutton comes from the east.");
  SetListen("The sounds of conversation come from the east.");
  SetItemAdjectives( ([
    //"door" : ({ "large", "heavy", "black" }),
    ]) );
  }
