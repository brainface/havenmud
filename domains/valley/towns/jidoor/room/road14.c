/* ----------------------------------------------------------------------- */
// Area Title: City of Jidoor
// Filename: road14.c
// Author: Derek Noble
// Immortal: dylanthalus@haven
// Creation Date: December 11th, 1998
// Abstract: This is part of the main street of Jidoor.
// Revision History: 
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include "../jidoor.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetTown("Jidoor");
  SetDomain("Valley");
  SetClimate("temperate");
  SetShort("the intersection of Mystic's Crescent and the Path of Energy");
  SetDayLong("Mystic's Crescent runs west and south from this point. "
             "Another section of road called the Path of Energy runs "
             "northeast from here. "
             "The city of Jidoor "
             "is surrounded to the east, west and north by the Crystal "
             "Reaches and the peaks of the mountains are plainly "
             "visible. Sunlight illuminates the area in a warm orange "
             "glow.");
  SetNightLong("Mystic's Crescent runs west and south from this point. "
             "Another section of road called the Path of Energy runs "
             "northeast from here. "
             "The city of Jidoor "
             "is surrounded to the east, west and north by the Crystal "
             "Reaches and the peaks of the mountains are plainly "
             "visible. Moonlight bathes the area in a soft white glow.");
  SetItems( ([ 
      ({ "street", "jidoor", "city", "road", "section",
         "mystic's crescent","crescent"}) : (: GetLong :),
      ({"mountain","mountains","crystal reaches","peaks","mountain peaks",
        "peaks of the mountains"}) : "The Crystal "
           "Reaches surround Jidoor in ever direction but south.",
   ]) );
  SetInventory( ([ 
       JID_NPC "/mcitizen" : 1,
       JID_NPC "/fcitizen" : 1,
   ]) );
  SetExits( ([ 
      "west" : JID_ROOM "/road15",
      "northeast" : JID_ROOM "/road19",      
      "south" : JID_ROOM "/road18",
    ]) );
  SetListen( ([ 
      "default" : "It is generally quiet here except for some of the "
                  "few sounds of the city life.",
           ]) );
  SetSmell( ([ 
      "default" : "The air is clean and fresh." 
           ] ));
}
