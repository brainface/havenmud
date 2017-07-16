/* ----------------------------------------------------------------------- */
// Area Title: City of Jidoor
// Filename: road9.c
// Author: Derek Noble
// Angel: dylanthalus@haven
// Creation Date: Dec 11th, 1998
// Abstract: This is the ninth section of the roads in Jidoor.
// Revision History: Originally created by Zaxan@Haven
//                   Completely recoded by Zaxan Zimtafarous@Haven
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include "../jidoor.h"

inherit LIB_ROOM;
//int PreEnter(string dir) ;

static void create() {
  room::create();
  SetTown("Jidoor");
  SetDomain("Valley");
  SetClimate("temperate");
  SetShort("Mage Avenue North");
  SetDayLong("The main street in Jidoor continues to head north and "
           "south from this point.  A few buildings are visible "
           "from here, but they don't appear to be accessible from this "
           "point on the road."
           " The mountains of the Crystal Reaches are easily "
           "seen beyond the rooftops. Sunlight illuminates the area "
           "well at this time of day.");
  SetNightLong("The main street in Jidoor continues to head north and "
           "south from this point.  A few of buildings are visible "
           "from here, but they don't appear to be accessible from this "
           "point on the road. The mountains of the Crystal Reaches are "
           "easily seen "
           "beyond the rooftops. Moonlight illuminates the area but "
           "the main source of light is from a globe resting on a post on "
           "the side of the street.");
  SetItems( ([ 
      ({ "street", "road", "avenue","mage avenue", 
         "mage avenue north" }) : (: GetLong :),
      ({"building","buildings"}) : "The buildings are made from wood "
           "and stone.",
      ({"mountain","mountains","crystal reaches"}) : "The Crystal "
           "Reaches surround Jidoor to the north, east and west of "
           "the city.",
      ({"rooftop","rooftops"}) : "The rooftops of the buildings are "
           "not high enough to conceal the massive mountains beyond "
           "the city.",
      ({"globe","post","globe resting on a post"}) : "The streetlight is "
            "one of the marvels of Jidoor. It keeps the city well lit at "
            "night.",
           ]) );
  SetItemAdjectives( ([
      "street" : ({ "main" }),
      "house" : ({"nice looking", "nice"}),
      "mountain" : ({ "massive","easily seen" }),
   ]) );
  SetExits( ([ 
      "north" : JID_ROOM "/road10",
      "south" : JID_ROOM "/road8",
   ]) );
  SetListen( ([ 
      "default" : "The sounds of the city are all around.",
           ]) );
  SetSmell( ([ 
      "default" : "The air smells fresh and clean." 
           ] ));
}
/*
int PreEnter(string dir) 
{
   if(this_player()->id("jid_protect")) { return 0; }
   else return 1;
}
*/
