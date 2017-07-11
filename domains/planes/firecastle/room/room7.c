//
// filename: room7
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
     "The hallway continues to the southeast and leads back to the stairway to "
     "the west. The walls are perfectly clean and bare except for a small "
     "torch sitting on the northern wall. The floor is covered in rather large "
     "burn marks with several piles of ash about."
   );
   SetItems( ([
      ({ "hallway", "castle" }) :
         (: GetLong :),
      ({ "walls", "wall" }) :
         "The walls are clean and bare except for a small torch sitting on the "
         "northern wall.",
      ({ "torch" }) :
         "The small torch doesn't appear to be providing the light for the "
         "as it is not lit nor does it appear to be able to be lit.",
      ({ "floor" }) :
         "The floor is made from the same material that the walls are made from. The "
         "parts of the floor that arn't covered by the marks have piles of "
         "ash resting upon them.",
      ({ "material", "stone" }) :
         "This unknown material appears to be a stone of some kind but on "
         "closer inspection it looks as if it is on fire.",
      ({ "ash", "piles of ash" }) :
         "Several piles of ash litter the floor. The ash is pure white in "
         "color as if it was snow but with the amount of ash that covers the "
         "floor what ever made it must of been quite large.",
   ]) );
   SetItemAdjectives( ([
      "hallway" : ({ "small" }),
      "torch" : ({ "small" }),
      "wall" : ({ "northern" }),
      "painting" : ({ "large" }),
      "material" : ({ "unknown", "unusual", "odd" }),
      "stairway" : ({ "small" }),
   ]) );  
   SetListen( ([
      "default" : "The sounds of roaring flames echo through the room.",
   ]) );
   SetSmell( ([
      "default" : "The bitter smell of sulfur fills the air.",
   ]) );
   SetExits( ([ 
      "southeast" : FCASTLE_ROOM "room8",
      "west" : FCASTLE_ROOM "room6",
   ]) );
   SetInventory( ([
         FCASTLE_NPC "mage1" : 2,
   ]) );
}
