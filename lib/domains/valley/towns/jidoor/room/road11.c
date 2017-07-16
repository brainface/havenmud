/* ----------------------------------------------------------------------- */
// Area Title: City of Jidoor
// Filename: road11.c
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
  SetShort("Magildan Avenue East");
  SetDayLong("The avenue contines east here and west here. "
             "The city of Jidoor "
             "is surrounded to the east, west and north by the Crystal "
             "Reaches and the peaks of the mountains are plainly "
             "visible. Sunlight filters down from above illuminating "
             "the area in an orange glow.");
  SetNightLong("The avenue contines east here and west here. "
             "The city of Jidoor "
             "is surrounded to the east, west and north by the Crystal "
             "Reaches and the peaks of the mountains are plainly "
             "visible. Moonlight filters down from above illuminating "
             "the area in a hazy white glow.");
  SetItems( ([ 
      ({ "street", "jidoor", "city", "road", "avenue", 
         "magildan avenue", "magildan avenue east"}) : (: GetLong :),
      ({"mountain","mountains","crystal reaches","peaks","mountain peaks",
        "peaks of the mountains"}) : "The Crystal "
           "Reaches surround Jidoor in ever direction but south.",
   ]) );
  SetInventory( ([ 
      JID_NPC "/fchild" : 1,
   ]) );
  SetExits( ([ 
      "west" : JID_ROOM "/road5",
      "east" : JID_ROOM "/road12",
    ]) );
  SetListen( ([ 
      "default" : "It is generally quiet here except for some of the "
                  "few sounds of the city life.",
           ]) );
  SetSmell( ([ 
      "default" : "The air is clean and fresh." 
           ] ));
}
