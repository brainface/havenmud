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
      "west" : PR_ROOM "/wop2",
      //"south" : PR_ROOM "/druid",
      "east" : PR_ROOM "/won2", 
      //"north" : PR_ROOM "/garden1" 
   ]) ); 
   //SetEnters( ([
   //   "building" : PR_ROOM "/shop" ]) ); 
   SetInventory( ([ PR_NPC + "/piglet" : 1 ]) );
}
