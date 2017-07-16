/* ----------------------------------------------------------------------- */
// Area Title: City of Jidoor
// Filename: road2.c
// Author: Derek Noble
// Angel: dylanthalus@haven
// Creation Date: Dec 11th, 1998
// Abstract: This is the second section of the roads in Jidoor.
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
           "south from this point. The Great Library of Jidoor is plainly "
           "visible to the east of the road.  The mountains of the Crystal "
           "Reaches are easily seen to the west and north but the library's "
           "rear tower blocks them from eastern view. Sunlight illuminates "
           "the area well at this time of day.");
  SetNightLong("The main street in Jidoor continues to head north and "
           "south from this point. The Great Library of Jidoor is plainly "
           "visible to the east of the road.  The mountains of the Crystal "
           "Reaches are easily seen to the west and north but the library's "
           "rear tower blocks them from eastern view. Moonlight illuminates "
           "the area but the main source of light is from a globe resting "
           "on a post on the side of the street.");
  SetItems( ([ 
      ({ "street", "jidoor", "city", "road", "avenue", 
         "mage avenue", "mage avenue south"}) : (: GetLong :),
      ({"library","great library","great library of jidoor"}) : "The "
           "massive steps and pillars of "
           "the entrance to the library are inviting and scholarly "
           "looking.",
      ({"step","steps"}) : "The massive marble steps lead up into the "
           "library",
      ({"pillar","pillars"}) : "Four massive pillars are standing in front "
           "of the great library.",
      ({"mountain","mountains","crystal reaches"}) : "The Crystal "
           "Reaches surround Jidoor to the north, east and west of "
           "the city.",
      ({"globe","post","globe resting on a post"}) : "The streetlight is "
            "one of the marvels of Jidoor. It keeps the city well lit at "
            "night.",
      ({"tower","rear tower","library's rear tower"}) : "The massive stone "
            "tower of the library stands nearly nearly fifty feet into "
            "the air!",
           ]) );
  SetItemAdjectives( ([
      "street" : ({ "main" }),
      "mountain" : ({ "massive","easily seen" }),
   ]) );
  SetExits( ([ 
      "north" : JID_ROOM "/road3",
      "south" : JID_ROOM "/road1",
   ]) );
  SetEnters( ([
     "library" : JID_ROOM + "/library/lib_foyer",
    ]) );
  SetListen( ([ 
      "default" : "It is relatively quiet here.",
           ]) );
  SetSmell( ([ 
      "default" : "Clean fresh smelling air fills the city." 
           ] ));
}
