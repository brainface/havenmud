/* ----------------------------------------------------------------------- */
// Area Title: City of Jidoor
// Filename: road12.c
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
  SetShort("the intersection of Magildan Avenue East and Mystic's Crescent");
  SetDayLong("Magildan Avenue East is just west of here and to the North "
             "lies Mystic's Crescent.  Sunlight bathes the area in a gentle "
             "orange luminesence. The city of Jidoor is surrounded to the "
             "east, west and north by the Crystal Reaches and the peaks of "
             "the mountains are plainly visible.");
  SetNightLong("Magildan Avenue East is just west of here and to the North "
             "lies Mystic's Crescent.  Moonlight bathes the area in a soft "
             "white luminesence. The city of Jidoor is surrounded to the "
             "east, west and north by the Crystal Reaches and the peaks of "
             "the mountains are plainly visible.");
  SetItems( ([ 
      ({ "street", "jidoor", "city", "road", "avenue", 
         "magildan avenue", "magildan avenue east","intersection",
         "mystic's crescent","crescent"}) : (: GetLong :),
      ({"mountain","mountains","crystal reaches","peaks","mountain peaks",
        "peaks of the mountains"}) : "The Crystal "
           "Reaches surround Jidoor in ever direction but south.",
   ]) );
  SetInventory( ([ 
      JID_NPC "/sentry" : 1,
      JID_NPC "/mchild" : 1,
   ]) );
  SetExits( ([ 
      "north" : JID_ROOM "/road13",
      "west" : JID_ROOM "/road11",
    ]) );
  SetListen( ([ 
      "default" : "It is generally quiet here except for some of the "
                  "few sounds of the city life.",
           ]) );
  SetSmell( ([ 
      "default" : "The air is clean and fresh." 
           ] ));
}
