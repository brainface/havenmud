
#include <lib.h>
#include "../shrine.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a path leading around a shrine");
  SetLong("The marble outer wall of the shrine"
          " can be seen to the north. The fog"
          " here is very intense and makes it not"
          " only hard to see but also hard to breathe."
          " There are many small wooden markers scattered"
          " throughout the area. The path leads east and"
          " west around the perimeter of the shrine.");
  SetItems( ([
          ({ "path", "stone", "stones", "weeds"}) :
          "The path here has seemingly been neglected"
          " and shows signs of aging. The stones that"
          " were once neatly arranged to border the"
          " path are broken or missing and weeds"
          " sprout in random spots along the path.",
          ({ "fog" }) :
          "The fog here is very thick and unnatural.",
          ({ "shrine", "arch" }) :
          "The shrine is a small and modest affair with"
          " a large white marble arch for an entry way.",
          ({ "marker", "markers" }) :
          "These small wooden markers look like a mixture"
          " of grave markers and protection charms."
          ]) );
  SetItemAdjectives( ([
          "path" : ({ "broken", "neglected" }),
          "fog" : ({ "unnatural", "thick" }),
          "shrine" : ({ "small", "modest" }),
          "marker" : ({ "small", "wooden", "wood" }),
          ]) );                 
  SetSmell( ([
          "default" : "The brisk odor of a cold wind lingers.",
       ]) );
  SetListen( ([
          "default" : "The sound of distant moaning"
                      " reaches here.",
        ]) );
  SetExits( ([
           "west" : SHRINE_ROOM "room8",
           "east" : SHRINE_ROOM "room10",
        ]) );
  SetInventory( ([
           SHRINE_NPC "ghost3" : 3,
        ]) );
}
