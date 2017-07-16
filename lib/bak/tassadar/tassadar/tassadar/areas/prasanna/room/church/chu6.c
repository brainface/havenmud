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
      "west" : PR_CHU "/chu5",
      "south" : PR_CHU "/chu9",
      //"east" : PR_CHU "/chu8", 
      "north" : PR_CHU "/chu3",
      //"out" : PR_ROOM "/won2" 
   ]) ); 
   //SetEnters( ([
   //   "building" : PR_ROOM "/shop",
   //   "church" : PR_CHU "/chu8" ]) ); 
   SetInventory( ([ PR_NPC + "/piglet" : 1 ]) );
}
