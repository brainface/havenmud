#include <lib.h>
#include "prasanna.h"

inherit LIB_ROOM;

static void create() {
   room::create();
   SetTown("Prasanna");
   SetClimate("indoors");
   SetDomain("Valley");
   SetShort("short goes here");
   SetLong("Long goes here."
  );
   SetItems( ([ 
      ({ "church" }) : 
         "This is the sprawling city of Prasanna, and seems to glow as the "
         "light hits it. The buildings are elegant and inviting.",
      ({ "buildings","building" }) : 
         "This is the sprawling city of Prasanna, and seems to glow as the "
         "light hits it. The buildings are elegant and inviting.",
   ]) );
   SetExits( ([ 
      "up" : PR_TOW "/evo",
      "down" : PR_TOW "/ent",
      //"out" : PR_ROOM "/wop3" 
   ]) ); 
   //SetEnters( ([
   //   "building" : PR_ROOM "/shop",
   //   "church" : PR_CHU "/chu8" ]) ); 
   SetInventory( ([ PR_NPC + "/piglet" : 1 ]) );
}
