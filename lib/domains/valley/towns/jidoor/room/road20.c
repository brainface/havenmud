/* ----------------------------------------------------------------------- */
// Area Title: City of Jidoor
// Filename: road20.c
// Author: Derek Noble
// Immortal: dylanthalus@haven
// Creation Date: February 14th, 1999
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
  SetDayLong("The Path of Energy ends here before the archway of the "
             "the Magildan Temple.  The path runs back to the southwest "
             "through a light forest. Beyond the trees to the east, west "
             "and north are the Crystal Reaches and the peaks of the "
             "mountains are plainly visible. Sunlight illuminates the "
             "tiny forest area in a warm orange glow.");
  SetNightLong("The Path of Energy ends here before the archway of the "
             "the Magildan Temple.  The path runs back to the southwest "
             "through a light forest. Beyond the trees to the east, west "
             "and north are the Crystal Reaches and the peaks of the "
             "mountains are plainly visible. Moonlight bathes the area "
             "in a soft white glow.");
  SetItems( ([ 
      ({ "path", "street", "jidoor", "city", "road", "section", "forest"
         "path of energy","crescent", "forest"}) : (: GetLong :),
      ({"mountain","mountains","crystal reaches","peaks","mountain peaks",
        "peaks of the mountains"}) : "The Crystal "
           "Reaches surround Jidoor in ever direction but south.",
      ({"archway"}) : "The archway is a beatifully crafted stone arch that "
           "allows access to the temple north of here.",
   ]) );
  SetExits( ([ 
      "north" : JID_ROOM "/temple/f",      
      "southwest" : JID_ROOM "/road19",
    ]) );
  SetListen( ([ 
      "default" : "It is peacefully quiet here.",
           ]) );
  SetSmell( ([ 
      "default" : "The air is clean and fresh." 
           ] ));
}
