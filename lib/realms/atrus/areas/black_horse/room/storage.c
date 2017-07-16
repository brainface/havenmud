/* Primary storage room for the Black Horse Inn
   Just filled with some stuff, the good stuff
   is in the basement.
   2/2/14 Atrus */

#include <lib.h>
#include "../bhi.h"

inherit LIB_STOREROOM;

static void create() {
   storeroom::create();
   SetShort("a large storage room");
   SetLong("There isn't much here besides dust and cobwebs.");
   SetPurgeInterval(5);
   SetInventory( ([
   ]) );
   SetInventory( ([
   //  BHI_OBJ "stair3" : 1,
   ]) );
   SetSmell("Dusty smell.");
   SetExits( ([
     "south" : "hallway",
   ]) );
   SetListen("Nothing.");
   SetItemAdjectives( ([
     "door" : ({ "large", "heavy", "black" }),
   ]) );
   SetDoor("south", BHI_OBJ "door1");
 }
