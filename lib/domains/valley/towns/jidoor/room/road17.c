/* ----------------------------------------------------------------------- */
// Area Title: City of Jidoor
// Filename: road17.c
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
  SetDayLong("Mystic's Crescent runs east and west from here. An entrance "
             "to the local cemetery is north of here. The city of Jidoor "
             "is surrounded to the east, west and north by the Crystal "
             "Reaches and the peaks of the mountains are plainly "
             "visible. Sunlight illuminates the area in an orange glow.");
  SetNightLong("Mystic's Crescent runs east and west from here. An "
             "entrance to the local cemetery is north of here. The "
             "city of Jidoor is surrounded to the east, west and north by "
             "the Crystal Reaches and the peaks of the mountains are "
             "plainly visible. Moonlight illuminates the area in a white "
             "glow.");
  SetItems( ([ 
      ({ "street", "jidoor", "city", "road", 
         "mystic's crescent","crescent"}) : (: GetLong :),
      ({"mountain","mountains","crystal reaches","peaks","mountain peaks",
        "peaks of the mountains"}) : "The Crystal "
           "Reaches surround Jidoor in ever direction but south.",
      ({ "cemetery" }) : "The local cemetery is just north of here and "
               "appears to be a foreboding area.",
   ]) );
  SetItemAdjectives( ([
      "house" : ({"nice looking", "nice"}),
      "cemetery" : ({ "local" }),
   ]) );
  SetInventory( ([ 
   ]) );
  SetExits( ([ 
      "west" : JID_ROOM "/road10",
      "east" : JID_ROOM "/road16",
      "north" : JID_ROOM "/cemetery",
    ]) );
  SetListen( ([ 
      "default" : "It is generally quiet here except for some of the "
                  "few sounds of the city life.",
           ]) );
  SetSmell( ([ 
      "default" : "The air is clean and fresh." 
           ] ));
}
