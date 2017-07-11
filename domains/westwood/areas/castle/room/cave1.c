// Coded by Gabriel@Haven 10/07/99
// High level 90+ area
// Located inside WestWood
// Ivory Castle/Pokenay Lake
//
// Revision History:

#include <lib.h>        
inherit LIB_ROOM;       
#include "../castle.h"          
 
static void create() {
room::create();
SetShort("a damp cave");
SetLong("This is a dark and damp cave.  It lies behind a waterfall "
  "and is slightly mossy on the floor.  Green lichen grows all "
  "about the walls.  It appears that a cave-in has occurred here "
  "and is blocking the rest of the cave.  Entering the waterfall "
  "is the only way to leave.");
SetExits( ([
  "out" : "/domains/westwood/virtual/westwood/25,29",
]) );
SetClimate("indoor");
SetAmbientLight(25);
}
