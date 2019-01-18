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
SetShort("the treasure room");
SetLong("In this room, there are shelves lining the walls.  The "
     "shelves filled with treasures of all varieties.  The floor "
     "is covered with a white carpet and the room is lit by a "
     "gem embedded in the ceiling.  To the north is the exit "
     "into a throne room.");
SetExits( ([
        "north" : C_ROOM + "throne",
        ]) );
SetClimate("indoors");
SetAmbientLight(60);
}
