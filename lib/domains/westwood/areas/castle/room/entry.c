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
SetShort("the castle entry");
SetLong("This is the entry way into a very impressive looking "
  "castle.  The castle walls are a pure white color with unused "
  "torch mounts and have small arrow slits scattered along the "
  "entire length.  The entry into the castle is guarded with a "
  "large portcullis on both sides and a small hole in the roof "
  "appears to be a means for someone to stop attackers.  To the "
  "east if the center room into the castle and to the west if "
  "the exit.");
SetExits( ([
  "west" : C_ROOM + "drawbridge",
  "east" : C_ROOM + "center",
]) );
SetClimate("indoors");
SetAmbientLight(60);
}
