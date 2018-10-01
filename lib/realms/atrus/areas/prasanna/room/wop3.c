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
      //"west" : PR_ROOM "/wop2",
      //"south" : PR_ROOM "/wop3",
      //"east" : PR_ROOM "/won1", 
      "north" : PR_ROOM "/wop2" 
   ]) ); 
   SetEnters( ([
      "building" : PR_TOW "/ent" ]) ); 
   SetInventory( ([ PR_NPC + "/piglet" : 1 ]) );
}
