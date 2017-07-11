/* ----------------------------------------------------------------------- */
// Area Title: City of Jidoor
// Filename: road13.c
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
  SetShort("Mystic's Crescent");
  SetDayLong("Mystic's crescent runs north and south here. There is an "
             "accessible building on the eastern side of the street. "
             "The city of Jidoor is surrounded to the east, "
             "west and north by the Crystal Reaches and the peaks of the "
             "mountains are plainly visible. Sunlight is beaming down "
             "upon the city from beyond the mountains.");
  SetNightLong("Mystic's crescent runs north and south here. There is an "
             "accessible building on the eastern side of the street. "
             "The city of Jidoor is surrounded to the east, "
             "west and north by the Crystal Reaches and the peaks of the "
             "mountains are plainly visible. "
             "Moonlight filters through the sky and "
             "illuminates the city in a white hazy glow.");
  SetItems( ([ 
      ({ "street", "jidoor", "city", "road", 
         "mystic's crescent","crescent"}) : (: GetLong :),
      ({"mountain","mountains","crystal reaches","peaks","mountain peaks",
        "peaks of the mountains"}) : "The Crystal "
           "Reaches surround Jidoor in ever direction but south.",
      ({"building","hall"}) : "The building appears to be some kind of "
           "official "
           "building.  It is made from stone and wood and looks much "
           "the other buildings of the city.",
   ]) );
  SetItemAdjectives( ([
   "building" : ({"official","accessible"}),
                   ]) );
  SetExits( ([ 
      "north" : JID_ROOM "/road18",
      "south" : JID_ROOM "/road12",
    ]) );
  SetEnters( ([ 
      "building" : JID_ROOM "/misc_buildings/war_hall",
    ]) );
  SetListen( ([ 
      "default" : "It is generally quiet here except for some of the "
                  "few sounds of the city life.",
           ]) );
  SetSmell( ([ 
      "default" : "The air is clean and fresh." 
           ] ));
}
