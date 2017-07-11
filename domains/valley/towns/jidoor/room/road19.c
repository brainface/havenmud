/* ----------------------------------------------------------------------- */
// Area Title: City of Jidoor
// Filename: road19.c
// Author: Derek Noble
// Immortal: dylanthalus@haven
// Creation Date: Feb 14th, 1999
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
  SetShort("the Path of Energy");
  SetDayLong("The Path of Energy runs northeast and southwest through "
             "a light forest. Beyond the trees to the east, west and "
             "north are the Crystal Reaches and the peaks of the "
             "mountains are plainly visible. Sunlight illuminates the "
             "tiny forest area in a warm orange glow.");
  SetNightLong("The Path of Energy runs northeast and southwest through "
             "a light forest. Beyond the trees to the east, west and "
             "north are the Crystal Reaches and the peaks of the "
             "mountains are plainly visible. Moonlight bathes the area "
             "in a soft white glow.");
  SetItems( ([ 
      ({ "path", "street", "jidoor", "city", "road", "section", "forest"
         "path of energy","crescent", "forest"}) : (: GetLong :),
      ({"mountain","mountains","crystal reaches","peaks","mountain peaks",
        "peaks of the mountains"}) : "The Crystal "
           "Reaches surround Jidoor in ever direction but south.",
   ]) );
  SetExits( ([ 
      "northeast" : JID_ROOM "/road20",      
      "southwest" : JID_ROOM "/road14",
    ]) );
  SetListen( ([ 
      "default" : "It is peacefully quiet here.",
           ]) );
  SetSmell( ([ 
      "default" : "The air is clean and fresh." 
           ] ));
}
