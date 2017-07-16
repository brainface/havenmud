#include <lib.h>
#include "prasanna.h"

inherit LIB_ROOM;

static void create() {
   room::create();
   SetClimate("indoors");
  SetDomain("Valley");
   SetAmbientLight(50);   
   SetShort("the widows cabin");
   SetLong("This appears to be no more than an empty closet or porch. "
           "An old bed sits in the corner, but doesn't appear to have been "
           "slept in for a very very long time. Aside from the bed, the "
           "room is empty, with nothing of interest. A rather small door "
           "leads out the back." );
   SetItems( ([ 
      ({ "old bed","bed" }) :
         "This bed actually looks quite comfortable, but hasn't been used "
         "in ages.",
      ({ "corner" }) :
         "There are four corner in the room, one of which houses an "
         "old bed.",
      ({ "widows cabin","cabin" }) :
         "This is the home of the widow and her child.",      ({ "closet","porch","room" }) :
         "This is merely a small room, with no contents.",
      ({ "door","small door" }) : 
         "Just a door that seems quite plain. ",
      ({ "wall" }) : 
         "The wall that the door is built into. "
   ]) );
   SetExits( ([ 
      "out" : PR_ROOM "/corral", 
      "north" : PR_ROOM "/cabin"
   ]) );
}

