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
      ({ "buildings","building" }) : 
         "This is the sprawling city of Prasanna, and seems to glow as the "
         "light hits it. The buildings are elegant and inviting.",

   ]) );
   SetExits( ([ 
      "west" : PR_ROOM "/square",
     /* "south" : PR_ROOM "/wop1", */
      "east" : PR_ROOM "/talver5",
     /* "north" : PR_PAL "/estate1" */
   ]) ); 
   SetEnters( ([
      "building" : PR_ROOM "/post" ]) );
   SetInventory( ([ PR_NPC + "/piglet" : 1 ]) );
}
