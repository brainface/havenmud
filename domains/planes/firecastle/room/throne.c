//
// filename: throne
// Thoin@Haven 01-16-06
//

#include <lib.h>
#include "../firecastle.h"
inherit LIB_ROOM;
#include <setup.h>
string eventSearchTaps();

static void create() {
   ::create();
   SetShort("a large throne room");
   SetClimate("indoors");
   SetProperty("lower plane",1);
   SetAmbientLight(35);
   SetLong(
           "This large room serves as the throne room for the castle. It is "
           "perfectly clean with several tapestries drapping the walls. In the "
           "center of the room a large chest sits next to a small desk. A large "
           "silver door is the only exit out of the room. Just infront of the "
           "desk a large burn mark covers most of the floor."
   );
   SetItems( ([
      ({ "room", "castle" }) :
         (: GetLong :),
      ({ "walls", "wall", "tapestries" }) :
         "The walls are covered by several tapestries. The tapestries depict "
         "different parts of the same scene, a large man consumed by flames is "
         "slaughtering the inhabitants of a town.",
      ({ "desk" }) :
         "The small desk sits in the center of the room and is covered in "
         "various pieces of half burned paper. The dest is made from an odd "
         "wood and is covered in scratches and burn marks.",
      ({ "floor" }) :
         "The floor is relatively clean and bare except for a large burn mark "
         "that sits just infront of the desk.",
      ({ "material", "stone" }) :
         "This unknown material appears to be a stone of some kind but on "
         "closer inspection it looks as if it is on fire.",
      ({ "mark" }) :
         "The burn mark appears to be fresh and it is large enough that whatever "
         "was immolated here must of been larger then a human.",
      "vortex" : "The vortex is blocked by the tapestries.",
   ]) );
   SetItemAdjectives( ([
      "hallway"  : ({ "small" }),
      "desk"     : ({ "small" }),
      "material" : ({ "unknown" }),
      "mark" : ({ "large", "burn" }),
   ]) );  
   SetListen( ([
      "default" : "The sounds of roaring flames echo through the room.",
   ]) );
   SetSmell( ([
      "default" : "The bitter smell of sulfur fills the air.",
   ]) );
   SetExits( ([ 
      "south" : FCASTLE_ROOM "room14",
   ]) );
   SetInventory( ([
      FCASTLE_NPC "lord" : 1,
      FCASTLE_NPC "guard3" : 1,
      FCASTLE_OBJ "tchest" : 1,
   ]) );
   SetSearch("tapestries", (: eventSearchTaps :) );
   SetEnters( ([
    "vortex" : DIR_STANDARD_DOMAIN "/room/setup",
    ]) );
   SetDoor("south", FCASTLE_OBJ "thronedoor");
}

string eventSearchTaps() {
  object lord = present("lord");
  if (lord)
    if (living(lord)) {
    lord->eventForce("speak What do you think you are doing?");
    return "You get interrupted.";
  }
  return "You look behind a tapestry and find a swirling vortex of elemental energy.";
}

