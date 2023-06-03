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
SetShort("a wizard's room");
SetLong("Upon entering this room, a person is surrounded with "
     "tables is lab equipment. There is glassware on all the "
     "tables and strange liquids boiling over small flames.  "
     "In the far corner is a small bed with a nightstand and "
     "nothing else.  There are no decorations in this room and "
     "apperantly whoever works here also lives here.");
SetExits( ([
        "south" : C_ROOM + "throne",
        ]) );
SetClimate("indoor");
SetAmbientLight(60);
}
