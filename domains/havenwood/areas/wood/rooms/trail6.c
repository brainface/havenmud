//coded by Syra 8/97

#include <lib.h>
#include "../wood.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a small pathway");
  SetDomain("Havenwood");
  SetSmell( ([
    "default" : "The air smells of earth and flowers.",
    ]) );
  SetListen( ([
    "default" : "Sounds of civilization come from below.",
    ]) );
  SetLong("The underbrush seems to become more sparse here. "
    "In fact, it seems to have been cleared away intentionally. "
         "The animal path leads westward from here, back through "
         "the underbrush. "
    "A large glittering staircase leads downward to what appears "
    "to be a large underground city. A small row of flowers line the "
    "edges of the staircase.");
  SetItems( ([
    "underbrush" : "The underbrush seems sparse here.",
    "pathway" : (:GetLong:),
    "staircase" : "The beautiful staircase leads downward.",
    ({"flowers", "flower", "row"}) : "The row of flowers surround the staircase.",
   ]) );
  SetItemAdjectives( ([
    "staircase" : ({"obsidian", "huge", "beautiful"}),
    "underbrush" : "sparse",
    "flowers" : "row of",
    "pathway" : "small",
    ]) );
  SetExits( ([
            "down" : "/domains/havenwood/towns/malveillant/rooms/stair1",
             "west" : HWD_ROOM + "/trail2",
     ]) );
  SetInventory( ([ 
             HWD_NPC + "/deermouse" : 1,
             HWD_NPC + "/gelfchild" : 1,
             HWD_NPC + "/robin" : 1
     ]) );

}
