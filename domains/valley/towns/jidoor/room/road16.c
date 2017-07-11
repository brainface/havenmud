
/* ----------------------------------------------------------------------- */
// Area Title: City of Jidoor
// Filename: road16.c
// Author: Derek Noble
// Immortal: dylanthalus@haven
// Creation Date: December 11th, 1998
// Abstract: This is part of the main street of Jidoor.
// Revision History: 
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include "../jidoor.h"

inherit LIB_ROOM;
//int PreEnter(string dir);

static void create() {
  room::create();
  SetTown("Jidoor");
  SetDomain("Valley");
  SetClimate("temperate");
  SetShort("Mystic's Crescent");
  SetDayLong("Mystic's Crescent runs east and west here. An unmarked "
             "building of some kind rests on the southern side of the "
             "road. The city of Jidoor "
             "is surrounded to the east, west and north by the Crystal "
             "Reaches and the peaks of the mountains are plainly "
             "visible. Sunlight filters through the peaks of the mountains "
             "and illuminates the area in it's warm light.");
  SetNightLong("Mystic's Crescent runs east and west here. An unmarked "
             "building of some kind rests on the southern side of the "
             "road. The city of Jidoor "
             "is surrounded to the east, west and north by the Crystal "
             "Reaches and the peaks of the mountains are plainly "
             "visible. The moonlight finds it's way through the mountain "
             "peaks an on to the city street.");
  SetItems( ([ 
      ({ "street", "jidoor", "city", "road", 
         "mystic's crescent","crescent"}) : (: GetLong :),
      ({"mountain","mountains","crystal reaches","peaks","mountain peaks",
        "peaks of the mountains"}) : "The Crystal "
           "Reaches surround Jidoor in ever direction but south.",
      ({"building","hall"}) : "The building is unmarked and it is "
           "impossible discern what lies within it from out here.",
   ]) );
  SetItemAdjectives( ([
      "building" : ({"unmarked"}),
   ]) );
  SetInventory( ([ 
   ]) );
  SetExits( ([ 
      "west" : JID_ROOM "/road17",
      "east" : JID_ROOM "/road15",
    ]) );
  SetEnters( ([ 
      "building" : JID_ROOM "/misc_buildings/rogue_hall",
    ]) );
  SetListen( ([ 
      "default" : "It is generally quiet here except for some of the "
                  "few sounds of the city life.",
           ]) );
  SetSmell( ([ 
      "default" : "The air smells clean and fresh." 
           ] ));
}

/*
int PreEnter(string dir)
{
  if(this_player()->id("jid_protect")) { return 0; }
/domains/valley/towns/jidoor/room/road16.c (39-76 97%): 

   else return 1;
}
*/
