/* ----------------------------------------------------------------------- */
// Area Title: City of Jidoor
// Filename: road10.c
// Author: Derek Noble
// Angel: dylanthalus@haven
// Creation Date: December 11th, 1998
// Abstract: This is the tenth section of the roads in Jidoor.
// Revision History: Originally created by Zaxan@Haven
//                   Completely Recoded by Zaxan Zimtafarous@Haven
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include "../jidoor.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetTown("Jidoor");
  SetDomain("Valley");
  SetClimate("temperate");
  SetShort("the intersection of Mage Avenue North and Mystic's Crescent");
  SetDayLong("This is the main street in the city of Jidoor. To the "
           "north, there is a small glade resting at the foot of the "
           "Crystal Reaches while to the south, the road leads back towards "
           "the center of the city. West of here there appears to be the "
           "ruins of some building. Mystic's Crescent runs east of here. "
           "Sunlight illuminates the area.");
  SetNightLong("This is the main street in the city of Jidoor. To the "
           "north, there is a small glade resting at the foot of the "
           "Crystal Reaches while to the south, the road leads back towards "
           "the center of the city. West of here there appears to be the "
           "ruins of some building. Mystic's Crescent runs east of here. "
           "Moonlight illuminates the area but "
           "the main source of light is from a globe resting on a post on "
           "the side of the street.");
  SetItems( ([ 
      ({ "street", "road", "avenue","mage avenue", 
         "mage avenue north","crescent","mystic's crescent",
         "intersection" }) : (: GetLong :),
      ({ "building", "ruins", "ruins of some building" }) : 
            "The ruins are west of here but from here, it is quite "
            "evident that it is the ruins of some temple.",
      ({ "glade" }) : "The small glade to the north looks inviting and "
            "beautiful.",
      ({"globe","post","globe resting on a post"}) : "The streetlight is "
            "one of the marvels of Jidoor. It keeps the city well lit at "
            "night.",
      ({"mountain","mountains","crystal reaches"}) : "The Crystal "
           "Reaches surround Jidoor to the north, east and west of "
           "the city.",
          ]) );
  SetItemAdjectives( ([
      "glade" : ({ "small" }),
                   ]) );
   SetInventory( ([ 
      JID_NPC "/sentry" : 1,
      JID_NPC "/mcitizen" : 1,
   ]) );
   SetExits( ([ 
      "north" : JID_ROOM "/glade",
      "south" : JID_ROOM "/road9",
      "east" : JID_ROOM "/road17",
      "west" : JID_ROOM "/ruins",
   ]) );
  SetListen( ([ 
      "default" : "The noise of the city echoes throughout the area.",
           ]) );
  SetSmell( ([ 
      "default" : "Clean fresh air fills the city." 
           ] ));
}
