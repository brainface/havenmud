// Coded by Gabriel@Haven 10/07/99
// High level 90+ area
// Located inside WestWood
// Ivory Castle/Pokenay Lake
//
// Revision History:

#include <lib.h>        
inherit LIB_ROOM;       
#include "../castle.h"          

int PreExit();
 
static void create() 
{
room::create();

SetShort("a drawbridge");
SetLong("Test room for my drawbridge");
AddExit("east",C_ROOM + "entry",(:PreExit:));
SetClimate("temperate");
}

int PreExit() {
  if(query_night())
  {
     message("enter_mesg","The drawbridge is closed at night.",
     this_player());
     return 0;
  }
  else
  {
    return 0;
  }
}
