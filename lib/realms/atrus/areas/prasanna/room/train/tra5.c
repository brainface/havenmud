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
      ({ "church" }) : 
         "This is the sprawling city of Prasanna, and seems to glow as the "
         "light hits it. The buildings are elegant and inviting.",
      ({ "buildings","building" }) : 
         "This is the sprawling city of Prasanna, and seems to glow as the "
         "light hits it. The buildings are elegant and inviting.",
   ]) );
   SetExits( ([ 
      "west" : PR_TRA "/tra4",
      "south" : PR_TRA "/tra2",
      "east" : PR_TRA "/tra6", 
      "north" : PR_TRA "/tra8",
      "northeast" : PR_TRA "/tra9",
      "northwest" : PR_TRA "/tra7",
      "southeast" : PR_TRA "/tra3",
      "southwest" : PR_TRA "/tra1",
      //"out" : PR_ROOM "/won2" 
   ]) ); 
   //SetEnters( ([
   //   "building" : PR_ROOM "/shop",
   //   "church" : PR_CHU "/chu8" ]) ); 
   SetInventory( ([ PR_NPC + "/piglet" : 1 ]) );
}
