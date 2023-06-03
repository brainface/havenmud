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
SetShort("the throne room");
SetLong("Entering the throne, one is surrounded in the enviroment "
     "of royalty.  The floors are all covered in an expensive "
     "looking carpet and the walls have murals painted on every "
     "foot.  On the east wall of the room, there is a step up "
     "floor that has a large wooden throne sitting on it.  There "
     "are pillars spread out in regular intervals between the "
     "entry and the throne.");
SetExits( ([
        "north" : C_ROOM + "wizard",
        "south" : C_ROOM + "treasure",
        "west" : C_ROOM + "center",
        ]) );
SetClimate("indoor");
SetAmbientLight(60);
}
