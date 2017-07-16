//
// Filename: hp6.c
// Part of the Holy Path
// Created by Duuktsaryth@Haven
// Modified by Kazgaroth@Haven
//

#include <lib.h>
#include "../haven.h"

inherit LIB_ROOM;

static void create() {
   room::create();
   SetShort("Corner of Merchants' Way and Holy Path");
   SetExits( ([
      "north" : H_ROOM + "holy_path/hp5",
      "east"  : H_ROOM + "merchants_way/mw5",
   ]) );
   SetDayLong("The road turns here.  To the east the road continues on as "
              "Merchants' Way, the main commercial part of Haven Town.  To "
              "the north is Holy Path, the road which leads to the church "
              "of Kylin.  To the north can be seen the town hall, where "
              "new residents can go to become citizens." );
   SetNightLong("The road turns here.  To the east the road continues on "
                "along the starlit seas, becoming the Merchants' Way, the "
                "main commercial section of Haven Town.  To the north is "
                "the town hall, where new residents can go to become full "
                "citizens of Haven Town.");
   SetItems( ([
      ({ "road", "path" }) :
         "Here, the road turns to the east and heads down Merchants' Way, "
         "while on the other end, it heads north to the church.",
      ({ "part", "way" }) :
         "Merchants' Way is the main commercial part of the city.",
      ({ "church" }) :
         "To the north down the Holy Path lies the Church of Kylin.",
      ({ "hall" }) :
         "Slightly to the north of here lies the town hall. This is where "
         "new residents can become citizens.",
      ({ "sea", "seas" }) :
         "The starlit seas to the south give off a peaceful glow.",
   ]) );
   SetItemAdjectives( ([
      "road" : ({ "holy" }),
      "part" : ({ "merchants'" }),
      "church" : ({ "kylin" }),
      "hall" : ({ "town" }),
      "sea" : ({ "starlit" }),
   ]) );
}

/* Approved by Duuktsaryth on Sun Apr 25 18:58:54 1999. */
