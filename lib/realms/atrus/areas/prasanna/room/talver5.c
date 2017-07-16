#include <lib.h>
#include "prasanna.h"

inherit LIB_ROOM;

static void create() {
   room::create();
   SetTown("Prasanna");
   SetClimate("temperate");
   SetDomain("Valley");
   SetShort("short goes here");
   SetLong("Long goes here."
  );
   SetItems( ([ 
      ({ "church","building" }) : 
         "This is the sprawling city of Prasanna, and seems to glow as the "
         "light hits it. The buildings are elegant and inviting.",
   ]) );
   SetExits( ([ 
      "west" : PR_ROOM "/talver4",
     /* "south" : PR_ROOM "/wop1", */
      "east" : PR_ROOM "/talver6",
     /* "north" : PR_PAL "/estate1" */
   ]) ); 
   SetEnters( ([
      "church" : PR_CHU "/chu2" ]) );
   SetInventory( ([ PR_NPC + "/piglet" : 1 ]) );
}
