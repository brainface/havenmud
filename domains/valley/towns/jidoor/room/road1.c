/* ----------------------------------------------------------------------- */
// Area Title: City of Jidoor
// Filename: road1.c
// Author: Derek Noble
// Angel: dylanthalus@haven
// Creation Date: Dec 11th, 1998
// Abstract: This is the first section of the roads in Jidoor.
// Revision History: Originally created by Zaxan@Haven
//                   Completely recoded by Zaxan Zimtafarous@Haven
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include "../jidoor.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetTown("Jidoor");
  SetDomain("Valley");
  SetClimate("temperate");
  SetShort("Mage Avenue South");
  SetDayLong("The main street in Jidoor continues to head north and "
           "south from this point. The mountains of the Crystal "
           "Reaches are easily seen to the east, west and north. "
           "To the south, one can easily see the city gates and the "
           "group of guards stationed there. A small building on the "
           "western side of the road looks inviting. The most visible "
           "thing in the skyline to the north is a massive stone "
           "tower. Sunlight illuminates the area well at this time of "
           "day.");
  SetNightLong("The main street in Jidoor continues to head north and "
           "south from this point. The mountains of the Crystal "
           "Reaches are easily seen to the east, west and north. "
           "To the south, one can easily see the city gates and the "
           "group of guards stationed there. A small building on the "
           "western side of the road look inviting. The most visible "
           "thing in the skyline to the north is a tower rising high "
           "into the sky.  Moonlight illuminates "
           "the area but the main source of light is from a globe resting "
           "on a post on the side of the street.");
  SetItems( ([ 
      ({ "street", "jidoor", "city", "road", "avenue", 
         "mage avenue", "mage avenue south"}) : (: GetLong :),
      ({"mountain","mountains","crystal reaches"}) : "The Crystal "
           "Reaches surround Jidoor to the north, east and west of "
           "the city.",
      ({"main gate", "gate"}) : "To the south is the main gate to "
           "Jidoor.",
      ({"pub","building"}) : "The building has a small sign above "
           "the entrance.",
      ({"tower"}) : "The tower stands nearly fifty feet into the air!",
      ({"globe","post","globe resting on a post"}) : "The streetlight is "
            "one of the marvels of Jidoor. It keeps the city well lit at "
            "night.",
      ({ "sign" }) : "The sign above the building's entrance has some "
            "writing on it.",
           ]) );
  SetItemAdjectives( ([
      "street" : ({ "main" }),
      "building" : ({ "small" }),
      "mountain" : ({ "massive","easily seen" }),
   ]) );
   SetRead("sign", "%^GREEN%^BOLD%^Jidoor City Pub%^RESET%^");
    SetExits( ([ 
      "north" : JID_ROOM "/road2",
      "south" : JID_ROOM "/maingate",
   ]) );
   SetEnters( ([ 
      "pub" : JID_ROOM "/misc_buildings/pub",
   ]) );
  SetListen( ([ 
      "default" : "It's fairly quiet here.",
           ]) );
  SetSmell( ([ 
      "default" : "Clean fresh air fills the city." 
           ] ));
}
