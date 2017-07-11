#include "../inn.h"
#include <lib.h>
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a connecting chamber");
  SetAmbientLight(35);
  SetLong("This is merely a small chamber used to get to the three upstairs "
          "rooms in the Morning Star Inn.  There is little to see here, "
          "except for a rug on the floor and a wooden sign nailed securely "
          "into the south wall.  There is, of course, a staircase for getting "
          "back to the lower parts of the inn.");
  SetItems( ([ 
             ({ "very steep staircase", "steep oak staircase", "stairs",
                "oak staircase", "steep staircase", "staircase" }) :
                "It is a very steep, oak staircase that leads to the first "
                "floor of the inn.",
             ({ "simple patternless brown rug", "simple rug", "brown rug",
                "patternless rug", "simple brown rug",
                "patternless brown rug", "simple patternless rug", "rug" }) :
                "This is a simple, patternless, brown rug here for modest "
                "decoration.",
             ({ "wooden sign", "sign" }) :
                "The wooden sign is nailed into the south wall and has the "
                "words, \"Any damage of property or theft on the premisis "
                "will be met with severe penalties.\""
             ]) );
  SetRead( ([
            ({ "wooden sign", "sign" }) :
               "Any damage of property or theft on the premisis will be met "
               "with severe penalties."
            ]) );
  SetObviousExits("north, east, west, down");
  SetClimate("indoors");
  SetExits( ([
             "north" : I_ROOM + "/room5",
             "east" : I_ROOM + "/room7",
             "west" : I_ROOM + "/room6",
             "down" : I_ROOM + "/hall2"
             ]) );
}
