//
// filename: room13
// Thoin@Haven 01-16-06
//

#include <lib.h>
#include "../firecastle.h"

inherit LIB_ROOM;
int GuardStop(string);

static void create() {
   room::create();
   SetShort("a small hallway");
   SetClimate("indoors");
   SetProperty("lower plane",1);
   SetAmbientLight(35);
   SetLong(
           "The hallway continues back to the west and up to the fourth floor, "
           "both directions appear no more significant then the other. The "
           "walls are devoid of anything except for a small torch. The "
           "floor is smooth and looks to of been recently cleaned. A small "
           "stairway leads up to the fourth floor of the castle."
   );
   SetItems( ([
      ({ "hallway", "castle" }) :
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
      ({ "stairway" }) :
         "The small stairway sits in the back of the room and leads up to the fourth "
         "floor of the castle. The stairway appears to be made from the same unusual "
         "material that the rest of the castle is composed of.",
   ]) );
   SetItemAdjectives( ([
      "hallway" : ({ "small" }),
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
      "west" : FCASTLE_ROOM "mirror12",
   ]) );
  AddExit("up", FCASTLE_ROOM "mirror14", (: GuardStop :) );
   SetInventory( ([
      FCASTLE_NPC "guard1" : 1,
      FCASTLE_NPC "mguard1" : 1,
   ]) );
}

int GuardStop(string dir) {
   object guard;
   object who;
   who = this_player();
  guard = present("elemental guard", this_object());
  if ( (guard) && (living(guard)) ) {
     guard->eventForce("speak I cannot let you do that, now leave before we "
                       "have to remove you");
    guard->eventForce("grin "+who->GetKeyName());
    return 0;
   }
   return 1;
  }

