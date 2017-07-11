//
// Filename: hp2.c
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
      "north" : H_ROOM + "holy_path/hp1",
      "south" : H_ROOM + "holy_path/hp3",
   ]) );
   SetDayLong("The road continues off to the north and south here. "
              "Further north, Holy Path comes to an end outside the "
              "Church of Kylin.  Off to the south, it meets up with "
              "the Imperial Road.  There is a small building to the west.");
   SetNightLong("The road continues off to the north and south here. "
                "Further north, the stars twinkle in reflection off "
                "the face of the Church of Kylin.  Off to the south, "
                "Holy Path meets up with the Imperial Road. "
                "There is a small but cozy building to the west.");
   SetListen( ([ 
      "default" : "A slight hum comes from the north.",
   ]) );
   SetItems( ([
      ({ "road", "path" }) :
         (: GetLong :),
      ({ "building" }) :
         "This is a small cozy-looking building.",
      ({ "church" }) :
         "The Church of Kylin, the largest of all in Kailie, lies to "
         "the north of here.",
   ]) );
   SetItemAdjectives( ([ 
      "road" : ({ "holy" }),
      "building" : ({ "cozy", "small" }),
      "church" : ({ "kylin" }),
   ]) );
   SetEnters( ([
      "building" : H_ROOM + "sisterhood/entrance",
   ]) );
}


/* Approved by Duuktsaryth on Sun Apr 25 18:57:18 1999. */
