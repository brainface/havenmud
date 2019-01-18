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
SetShort("a small kitchen");
SetLong("This kitchen is very quaint and well equipped for this "
     "area.  There are two furnaces along the north wall and "
     "cabinets line the southern wall.  Running down the middle "
     "of the room is a long table used mostly to prepare food "
     "on.  This room is designed for functional use only and "
     "therefore has no decorations.  To the east is the exit "
     "back to the dining room.");
SetExits( ([
        "east" : C_ROOM + "dining",
        ]) );
SetClimate("indoors");
SetAmbientLight(60);
}
