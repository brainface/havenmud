/*ship galley
zara 8/5/98
*/

#include <lib.h>
#include "../acove.h"
inherit LIB_ROOM;


static void create() {
room::create();
 SetShort("ship's galley");
 SetClimate("temperate");
  SetAmbientLight(50);
 SetExits( ([
       "east" : ACOVE_ROOMS + "cove11",
       "west" : ACOVE_ROOMS + "cove9",
      ]) );
  SetLong("Like most ship galleys, this one is small. "
         "It is located one floor below deck. "
        "The floor is covered with a variety of "
         "unrecognizable ancient stains. Rat droppings "
        "litter the floor. A very large barrel takes "
         "up one corner of the room." );
  SetItems( ([
        ({ "room", "galley", "one" }) : "As in most ships, this galley is ",
         ({ "stain", "stains" }) : "The stains are many and varied.",
        ({ "floor", "deck" }) : "The floor is filthy and littered.",
         ({ "dropping", "droppings" }) : "These look fresh.",
         "barrel" : "This old oak barrel is empty.",
       ({ "ship","galleon"}) : (: GetLong :),
          ]) );
  SetItemAdjectives( ([
       "galley" : "small",
       "stains" : ({"variety","unrecognizable","ancient"}),
        "barrel" : ({"oak","old","empty","large"}),
        "droppings" : ({"fresh","rat"}),
          ]) );
  SetSmell( ([
          "default" : "The smells here are strong and "
                      "blessedly unidentifiable.",
          ]) );
  SetListen( ([
         "default" : "The sound of rats scurrying "
                      "for cover can be heard.",
          ]) );
  SetInventory( ([
       ACOVE_NPC + "cook" : 1,
       ]) );
}
