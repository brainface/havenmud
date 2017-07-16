//
// Filename: ir3.c
// Part of the Imperial Road
// Created by Duuktsaryth@Haven
// Modified by Kazgaroth@Haven
//

#include <lib.h>
#include "../haven.h"

inherit LIB_ROOM;

string CheckTraffic();

static void create() {
   room::create();
   SetShort("Imperial Road");
   SetExits( ([
      "east" : H_ROOM + "imperial_road/ir4",
      "west" : H_ROOM + "imperial_road/ir2",
   ]) );
   SetDayLong("The Imperial Road is almost majestic in the daylight. "
              "Buildings line the roadsides stretching from the corner "
              "to the west to the end of the road, which can vaguely be "
              "seen from here.  Off to the east seems to be some form of "
              "governmental center, as official-looking people move in and "
              "out of these buildings with regularity."
              );
   SetNightLong("With the night, the Imperial Road seems to sleep.  Though "
                "most of the city's official offices are open around the "
                "clock, the road is nearly devoid of traffic.  The stately "
                "buildings that line the road are nearly oppressive in the "
                "starlight."
                );
   SetItems( ([ 
      ({ "business", "scent" }) : 
         "You cannot see that.",
      ({ "building", "buildings" }) :
         "Many buildings line the roadsides here. A house sits by the roadside.",
      ({ "roadside", "roadsides", "sides", "side", "corner" }) :
         "The roadsides stretch east and west here, lined with many "
         "buildings.",
      ({ "center" }) :
         "This center, having a governmental look, lies to "
         "the east.",
      ({ "people", "traffic" }) :
         (: CheckTraffic :),
      ({ "office", "offices" }) :
         "These many offices line the roadsides with their doors "
         "constantly open.",
   ]) );
   SetItemAdjectives( ([
      "building" : ({ "stately" }),
      "center" : ({ "governmental" }),
      "people" : ({ "official-looking" }),
      "office" : ({ "city", "official" }),
      "door"   : ({ "office" }),
      "house"  : ({ "large" }),
   ]) );
   SetListen( ([
      "default" : "The gentle sound of city business emanates from "
                  "this section of town.",
      "business" : "Listening in on others' business?",
   ]) );
   SetSmell( ([ 
      "default" : "An odd scent is on the air.",
      "scent" : "It seems to be the stench of drying ink.",
   ]) );
   SetEnters( ([
      ]) );
}

string CheckTraffic() {
   if(query_night()) {
      return "The street seems completely devoid of all traffic.";
   } else {
      return "Many of Haven's people are wandering the streets here. They "
             "are moving in and out of the buildings here in swift fashion.";
   }
}

/* Approved by Duuktsaryth on Sun Apr 25 19:11:52 1999. */
