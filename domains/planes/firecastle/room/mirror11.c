//
// filename: mirror11
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
     "The hallway continues to the north and a small "
     "stairway leads back down to the second floor. The walls are pocked with "
     "a few scorch marks however two torches sit on the walls on either side "
     "of the northern exit. The floor is covered in rather large burn marks "
     "with several piles of ash about."
   );
   SetItems( ([
      ({ "hallway", "castle" }) :
         (: GetLong :),
      ({ "walls", "wall" }) :
         "The walls are pocket with several scorch and other burn marks except "
         "for two torches sit on either side of the northern exit.",
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
      ({ "stairway" }) :
         "The small stairway sits in the back of the room and leads down to "
         "the second floor of the castle. The stairway appears to be made from "
         "the same unusual material that the rest of the castle is composed "
         "of.",
      ({ "torch", "torches" }) :
         "The two torches flicker slightly with roaring flames however they "
         "provide no light, they rest on either side of the northern exit. ",
      ({ "ash", "piles of ash" }) :
         "Several piles of ash litter the floor. The ash is pure white in "
         "color as if it was snow but with the amount of ash that covers the "
         "floor what ever made it must of been quite large.",
   ]) );
   SetItemAdjectives( ([
      "hallway" : ({ "small" }),
      "mark" : ({ "scorch", "burn", "large" }),
      "torch" : ({ "small" }),
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
      "north" : FCASTLE_ROOM "mirror12",
      "down" : FCASTLE_ROOM "mirror10",
   ]) );
   SetInventory( ([
         FCASTLE_NPC "knight1" : 2,
   ]) );  
}