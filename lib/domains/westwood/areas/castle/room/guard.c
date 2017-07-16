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
SetShort("a guard room");
SetLong("Room where guards live/train.");
SetExits( ([
  "west"  : C_ROOM + "armoury",
  "south" : C_ROOM + "center",
]) );
SetClimate("indoor");
SetAmbientLight(60);
}
