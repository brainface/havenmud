/* Moe's Store Room moe_store.c */

#include <lib.h>
#include "../bhi.h"

inherit LIB_STOREROOM;

static void create() {
   storeroom::create();
   SetShort("a small dusty room");
   SetLong("There isn't much here besides dust and cobwebs.");
   SetPurgeInterval(5);
   SetInventory( ([
   ]) );
   SetInventory( ([
     BHI_OBJ "stair3" : 1,
   ]) );
   SetSmell("Dusty smell.");
   SetExits( ([
     "south" : "attic",
   ]) );
   SetListen("Nothing.");
   SetItemAdjectives( ([
     "door" : ({ "large", "heavy", "black" }),
   ]) );
   SetDoor("south", BHI_OBJ "moe_store_door");
 }
