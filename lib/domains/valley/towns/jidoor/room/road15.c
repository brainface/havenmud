/* ----------------------------------------------------------------------- */
// Area Title: City of Jidoor
// Filename: road15.c
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
  SetDayLong("Mystic's Crescent runs east and west from here. A small "
             "tower rests on the southern side of the road. "
             "The city of Jidoor "
             "is surrounded to the east, west and north by the Crystal "
             "Reaches and the peaks of the mountains are plainly "
             "visible. The sun's light illuminates the area in a fair "
             "amount of light.");
  SetNightLong("Mystic's Crescent runs west and east from here. A small "
             "tower rests on the southern side of the road. "
             "The city of Jidoor "
             "is surrounded to the east, west and north by the Crystal "
             "Reaches and the peaks of the mountains are plainly "
             "visible. Although it is night, the moonlight casts a fair "
             "amount of light on the city.");
  SetItems( ([ 
      ({ "street", "jidoor", "city", "road", 
         "mystic's crescent","crescent"}) : (: GetLong :),
      ({"tower"}) : "The very small tower rests on the northern side of "
         "of the road and stands about two stories tall.",
      ({"mountain","mountains","crystal reaches","peaks","mountain peaks",
        "peaks of the mountains"}) : "The Crystal "
           "Reaches surround Jidoor in ever direction but south.",
   ]) );
  SetItemAdjectives( ([
      "building" : ({"unmarked"}),
      "tower" : ({"small","two story"}),
   ]) );
  SetExits( ([ 
      "west" : JID_ROOM "/road16",
      "east" : JID_ROOM "/road14",
    ]) );
  SetEnters( ([ 
      "tower" : JID_ROOM "/misc_buildings/merchant_tower1",
    ]) );  
  SetListen( ([ 
      "default" : "It is generally quiet here except for some of the "
                  "few sounds of the city life.",
           ]) );
  SetSmell( ([ 
      "default" : "The air is clean and fresh." 
           ] ));
}
