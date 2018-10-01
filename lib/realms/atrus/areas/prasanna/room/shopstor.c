#include <lib.h>
#include "prasanna.h"

inherit LIB_ROOM;

static void create() {
   room::create();
   SetTown("Prasanna");
   SetClimate("indoor");
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
      "out" : PR_ROOM "/won2" 
   ]) ); 
  // SetEnters( ([
  //    "building" : PR_ROOM "/bank",
  //    "buildings" : PR_ROOM "/mayor" ]) ); 
   SetInventory( ([ PR_NPC + "/piglet" : 1 ]) );
}
