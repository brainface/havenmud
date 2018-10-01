/* hallway.c for Black Horse Inn
   20MAY2013
   Atrus@Haven
*/

#include "../bhi.h"
#include <lib.h>
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("hallway of the Black Horse Inn");
  SetClimate("indoors");
  SetAmbientLight(35);
  SetExits( ([
    "south" : "entryway",
    "east" : "bar",
    "north" : "storage",
    ]) );
  SetLong(
         "This short hallway gives home more to the staircase proceeding to the "
         "second floor of the inn. Under the stairs is an opening with a small "
         "staircase going down to the basement. To the east is the bar area, while "
         "south leaves the estabishment. There is a door to the north. The walls are "
         "heaily panneled and whitewashed. The floor is tightly hewn logs. The ceiling "
         "has very heavy support beams running evenly and parallel. Light is offered from "
         "several lamps on a table on the south wall."
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
    "door" : ({ "large", "heavy", "black" }),
    ]) );
  SetInventory( ([
    BHI_OBJ "stair1" : 1,
  ]) );
  SetSmell("The waft of roasting mutton comes from the east.");
  SetListen("The sounds of conversation come from the east.");
  SetDoor("north", BHI_OBJ "door1");
 }
