//
// filename: mirror12
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
     "The hallway continues to the east and back to the south. "
     "The walls are relatively bare except for a large painting resting on the "
     "northern wall. The floor is covered in rather large burn marks "
     "with several piles of ash about."
   );
   SetItems( ([
      ({ "hallway", "castle" }) :
         (: GetLong :),
      ({ "walls", "wall" }) :
         "The walls are pocket with several scorch and other burn marks except "
         "for a painting which hangs on the northern wall.",
      ({ "mark", "marks" }) :
         "The scorch marks don't appear to of been made recently however they "
         "do appear to of been made by large claws and or talons.",
      ({ "floor" }) :
         "The floor is covered in similar burn marks that mark the walls. The "
         "parts of the floor that arn't covered by the marks have piles of "
         "ash resting upon them.",
      ({ "material", "stone" }) :
         "This unknown material appears to be a stone of some kind but on "
         "closer inspection it looks as if it is on fire.",
      ({ "painting" }) :
         "The large painting is made from a silk like material and covers most "
         "of the nothern wall. The painting is of a beautiful castle resting "
         "on the side of a mountain with low clouds barely covering the very "
         "top of the castle.",
      ({ "ash", "piles of ash" }) :
         "Several piles of ash litter the floor. The ash is pure white in "
         "color as if it was snow but with the amount of ash that covers the "
         "floor what ever made it must of been quite large.",
   ]) );
   SetItemAdjectives( ([
      "hallway" : ({ "small" }),
      "mark" : ({ "scorch", "burn", "large" }),
      "painting" : ({ "large" }),
      "material" : ({ "unknown", "unusual", "odd" }),
      "wall" : ({ "northern" }),
   ]) );  
   SetListen( ([
      "default" : "The sounds of roaring flames echo through the room.",
   ]) );
   SetSmell( ([
      "default" : "The bitter smell of sulfur fills the air.",
   ]) );
   SetExits( ([ 
      "south" : FCASTLE_ROOM "mirror11",
      "east" : FCASTLE_ROOM "mirror13",
   ]) );
   SetInventory( ([
         FCASTLE_NPC "rogue1" : 1,
         FCASTLE_NPC "mage1" : 1,
   ]) );
}