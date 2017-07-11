//
// filename: room3
// Thoin@Haven 01-16-06
//

#include <lib.h>
#include "../firecastle.h"

inherit LIB_ROOM;

static void create() {
   room::create();
   SetShort("a small hallway");
   SetClimate("indoors");
   SetProperty("lower plane",1);
   SetAmbientLight(35);
   SetLong(
              "The hallway continues to the north and back to the southwest "
              "both directions appear no different. The walls are devoid of "
              "anything except for a small torch. The floor is smooth and "
              "looks to of been recently cleaned. "
   );
   SetItems( ([
      ({ "hallway" }) :
         (: GetLong :),
      ({ "walls", "wall" }) :
         "The walls are bare except for a single torch. The walls are made "
         "from some odd material similar to that of the floor.",
      ({ "torch" }) :
         "The small torch hangs on the wall but oddly enough it doesn't "
         "seem to be providing any light for the room and is merely there "
         "for decoration.",
      ({ "floor" }) :
         "The floor is completely clean and made from the same smooth material "
         "the walls are made from.",
      ({ "material", "stone" }) :
         "This unknown material appears to be a stone of some kind but on "
         "closer inspection it looks as if it is on fire.",
   ]) );
   SetItemAdjectives( ([
      "hallway" : ({ "small" }),
      "torch" : ({ "small" }),
      "material" : ({ "unknown" }),
   ]) );  
   SetListen( ([
      "default" : "The sounds of roaring flames echo through the room.",
   ]) );
   SetSmell( ([
      "default" : "The bitter smell of sulfur fills the air.",
   ]) );
   SetExits( ([ 
      "southwest" : FCASTLE_ROOM "room1",
      "north" : FCASTLE_ROOM "room5",
   ]) );
   SetInventory( ([
      FCASTLE_NPC "mage1" : 2,
   ]) );
}
