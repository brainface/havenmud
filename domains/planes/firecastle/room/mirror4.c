//
// filename: mirror4
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
              "The hallway continues to the south and a small stairway "
              "leads to the second floor of the castle. On the western wall "
              "a small tattered painting hangs. The floor is covered in a "
              "slightly burned rug. "
   );
   SetItems( ([
      ({ "hallway", "castle" }) :
         (: GetLong :),
      ({ "walls", "wall" }) :
         "The walls are bare except for a small painting. They are also made "
         "from some odd material similar to that of the floor.",
      ({ "painting" }) :
         "The paining appears to be slightly burned but it depicts "
         "a vivid scene of a man immolating thousands of people.",
      ({ "floor" }) :
         "The floor is completely clean and made from the same smooth material "
         "the walls are made from. A rug covers most of the floor.",
      ({ "material", "stone" }) :
         "This unknown material appears to be a stone of some kind but on "
         "closer inspection it looks as if it is on fire.",
      ({ "rug" }) :
         "This burned rug attempts to cover the floor but only manages to cover "
         "part of it. It once was a wondrous design but now it is merely tatters.",
   ]) );
   SetItemAdjectives( ([
      "hallway" : ({ "small" }),
      "walls" : ({ "western" }),
      "painting" : ({ "small", "tattered" }),
      "material" : ({ "unknown" }),
      "rug" : ({ "burned", "slightly" }),
   ]) );  
   SetListen( ([
      "default" : "The sounds of roaring flames echo through the room.",
   ]) );
   SetSmell( ([
      "default" : "The bitter smell of sulfur fills the air.",
   ]) );
   SetExits( ([ 
      "up" : FCASTLE_ROOM "mirror6",
      "south" : FCASTLE_ROOM "mirror2",
   ]) );
   SetInventory( ([
      FCASTLE_NPC "knight1" : 1,
      FCASTLE_NPC "mage1" : 1,
   ]) );
}
