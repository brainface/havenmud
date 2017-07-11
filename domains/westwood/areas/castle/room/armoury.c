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
SetShort("the castle armoury");
SetLong("What it says, the castle armoury.");
SetExits( ([
        "east" : C_ROOM + "guard",
        ]) );
SetClimate("indoor");
SetAmbientLight(60);
}
