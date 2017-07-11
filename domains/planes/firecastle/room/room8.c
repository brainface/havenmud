//
// filename: room8
// Thoin@Haven 01-16-06
//

#include <lib.h>
#include "../firecastle.h"

inherit LIB_ROOM;
string eventLookMirror();

static void create() {
   room::create();
   SetShort("a small hallway");
   SetClimate("indoors");
   SetProperty("lower plane",1);
   SetAmbientLight(35);
   SetLong(
     "The hallway ends in front of a large mirror. The hallways continues back "
     "the northwest. The only object in the room is the large mirror resting "
     "on the northern wall. The floor is covered in rather large "
     "burn marks with several piles of ash about."
   );
   SetItems( ([
      ({ "hallway", "castle" }) :
         (: GetLong :),
      ({ "walls", "wall" }) :
         "The walls are bare except for a large mirror resting on the "
         "northern wall.",
      ({ "mirror" }) : (: eventLookMirror :),
      ({ "floor" }) :
         "The floor is made from the same material as the walls. The "
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
      "mirror" : ({ "large" }),
      "wall" : ({ "northern" }),
      "material" : ({ "unknown", "unusual", "odd" }),
   ]) );  
   SetListen( ([
      "default" : "The sounds of roaring flames echo through the room.",
   ]) );
   SetSmell( ([
      "default" : "The bitter smell of sulfur fills the air.",
   ]) );
   SetExits( ([ 
      "northwest" : FCASTLE_ROOM "room7",
   ]) );
  SetEnters( ([
      "mirror" : FCASTLE_ROOM "mirror1",
   ]) );
   SetInventory( ([
   ]) );
}

string eventLookMirror() {
  object who = this_player();

  if ((who->GetStatLevel("intelligence")) < 50){
    return "As you gaze into the mirror you see a perfect reflection of "
           "yourself and the room you are standing in." ;
   } else {
    return "As you gaze into the mirror you notice that you have no reflection "
    "in the mirror and that the room in the mirror is completely different "
    "from the one you are standing in.";
 }
}
