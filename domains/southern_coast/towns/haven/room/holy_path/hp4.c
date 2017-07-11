//
// Filename: hp4.c
// Part of the Holy Path
// Created by Duuktsaryth@Haven
// Modified by Kazgaroth@Haven
//

#include <lib.h>
#include "../haven.h"

inherit LIB_ROOM;

static void create() {
   room::create();
   SetShort("the Holy Path");
   SetExits( ([ 
      "north" : H_ROOM + "imperial_road/ir2",
      "south" : H_ROOM + "holy_path/hp5",
   ]) );
   SetDayLong("The road leads off to the north and south from here.  To "
              "the south is the Town Hall, while further north is the "
              "Church of Kylin.  In the distance to the south, the sun "
              "reflects off of the Ruined Sea, its dead waters holding "
              "calm under the sky, moving only when a large wind comes "
              "along.");
   SetNightLong("The road travels off to the north and south from here. "
                "Off to the south is the Town Hall of Haven.  Far to the "
                "south is the Ruined Sea, its dead waters twinkling in the "
                "starlight.  Far to the north the spires of the Church of "
                "Kylin block the stars.");
   SetItems( ([
      ({ "road" }) :
         "From here, the road heads off to the north and south.",
      ({ "hall" }) :
         "The Haven Town Hall is located to the south of here.",
      ({ "church", "spire", "spires" }) :
         "The mighty Church of Kylin sits peacefully to the north.",
      ({ "sea", "waters", "water" }) :
         "The Ruined Sea can be seen far to the south.",
   ]) );
   SetItemAdjectives( ([
      "hall" : ({ "haven", "town" }),
      "church" : ({ "kylin" }),
      "sea" : ({ "dead", "ruined" }),
   ]) );
}


/* Approved by Duuktsaryth on Sun Apr 25 18:57:58 1999. */
