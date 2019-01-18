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
SetShort("a center hallway");
SetLong("Center hallway leading to everywhere in the castle.");
SetExits( ([
  "north" : C_ROOM + "guard",
  "south" : C_ROOM + "dining",
  "west"  : C_ROOM + "entry",
  "east"  : C_ROOM + "throne",
]) );
SetClimate("indoors");
SetAmbientLight(60);
}
