/* ----------------------------------------------------------------------- */
// Area Title: City of Jidoor
// Filename: road8.c
// Author: Derek Noble
// Angel: dylanthalus@haven
// Creation Date: Dec 11th, 1998
// Abstract: This is the eighth section of the roads in Jidoor.
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
  SetShort("Mage Avenue North");
  SetDayLong("The main street in Jidoor continues to head north and "
           "south from this point.  A couple of buildings are visible, "
           "but they don't appear to be accessible from here. "
           "The mountains of the Crystal Reaches are easily seen "
           "beyond their rooftops. Sunlight illuminates the area well "
           "at this time of day.");
  SetNightLong("The main street in Jidoor continues to head north and "
           "south from this point.  A couple of buildings are visible, "
           "but they don't appear to be accessible from here. "
           "The mountains of the Crystal Reaches are easily seen "
           "beyond their rooftops. Moonlight illuminates the area but "
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
      "mountain" : ({ "massive","easily seen" }),
   ]) );
  SetExits( ([ 
      "south" : JID_ROOM "/twnsquare",
      "north" : JID_ROOM "/road9",
          ]) );
  SetListen( ([ 
      "default" : "The sounds of the city are all around.",
           ]) );
  SetSmell( ([ 
      "default" : "The air smells fresh and clean." 
           ] ));
}
