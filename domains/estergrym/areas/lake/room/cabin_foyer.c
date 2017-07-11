/*Cabin Foyer around Lake
  Immortal: Zeratul
  11-26-99
  Alessified 8/2013 - SETITEMS!!!
   And other misc fixes
*/
#include <lib.h>
#include "../lake.h"
inherit LIB_ROOM;

static void create() {
  room::create();

  SetDomain("Estergrym");
  SetClimate("indoors");
  SetShort("A cabin foyer");
  SetLong("Wooden walls, floor and ceiling make up this cabin foyer. "
     "A small throw rug is set just inside the door with some shoes scattered "
     "next to it. There is small set of stairs leading up to the second "
     "floor of the cabin. Some windows are set with wooden shutters open "
     "to let in fresh air and natural light. To the east is a "
     "small kitchen that looks well lit. "
     );
  SetListen( ([
     "default" : "Rustling and talking can be heard.",
     ]) );
  SetSmell( ([
     "default" : "The air smells of evergreen wood.",
     ]) );
  SetItems( ([
     ({"rug"}) : "The small multi-colored rug is made from scraps of "
       "fabric that have been tied together. The color is slightly faded "
       "from years of being trampled on.",
     ({"stair", "stairs"}) : "The wooden stairs are made of the same "
       "evergreen wood that the rest of the cabin has been built from. "
       "They lead up to second level within the cabin.",
     ({"shutter", "shutters"}) : "Wooden shutters frame the windows and "
       "open to offer fresh air from outdoors and natural light.", 
     ({"window", "windows"}) : "These windows look out from the cabin and "
       "provide a pleasant breeze from outside.",
     ({"shoes","shoe"}) : "Several pairs of shoes are strewn about the floor, "
       "sizes ranging from children to adult.",
     ({"walls","wall"}) : "The walls are made of a sturdy, evergreen wood "
       "that looks strong enough to protect well from the outside elements. "
       "Small shuttered windows in the walls allow for light and fresh air.",
     ({"ceiling"}) : "The ceiling could use a little broom-work. ",
     ({"floor", "ground"}) : "The wooden floor is worn in spots from foot "
       "traffic. A small rug sits just inside the door with shoes near it.",
     ]) );
  SetAmbientLight(30);
  SetItemAdjectives( ([
     "shoes" : ({"scattered","strewn"}),
     "walls" : ({"sturdy", "strong", "wooden"}),
     "rug" : ({"throw", "small"}),
     "stair" : ({"wood", "wooden"}),
     "shutter" : ({"wood", "wooden", "open"}),
     "window" : ({"small", "shuttered", "open"}),
     "floor" : ({"wood", "wooden"}),
     ]) );
  SetInventory( ([
     LAKE_NPC + "/garion" : 1,
     ]) );
  SetDoor("out", LAKE_OBJ + "/cabin_door");
  SetExits( ([
     "out" : LAKE_ROOM + "/cabin_out",
     "up" : LAKE_ROOM + "/cabin_room",
     "east" : LAKE_ROOM + "/cabin_kitchen",
     ]) );
}
