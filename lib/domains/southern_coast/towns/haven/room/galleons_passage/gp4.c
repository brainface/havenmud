//
// Filename: gp4.c
// Part of Galleon's Passage
// Created by Duuktsaryth@Haven
// Modified by Kazgaroth@Haven
//

#include <lib.h>
#include "../haven.h"

inherit LIB_ROOM;

string CheckTraffic();

static void create() {
   room::create();
   SetShort("Galleon's Passage");
   SetExits( ([ 
      "north" : H_ROOM + "galleons_passage/gp5",
      "south" : H_ROOM + "galleons_passage/gp3",
   ]) );
   SetDayLong("The traffic in this part of town is mostly concerned with "
              "the Haven Guard barracks to the north.  Off to the south "
              "the road intersects the Imperial Road, which is the main "
              "lifeline of the city.  Farther to the south, the daylight "
              "reflects brightly off of the Ruined Sea.");
   SetNightLong("The traffic on the street at this hour is non-existant, "
                "but even this late the city seems calm and safe.  To the "
                "north is the barracks of the Haven Guard.");
   SetItems( ([
      ({ "road", "street" }) :
         (: GetLong :),
      ({ "traffic" }) :
         (: CheckTraffic :),
      ({ "barracks", "training grounds", "training ground" }) :
         "The Haven Guard barracks, training grounds for many warriors, "
         "lies to the north.",
      ({ "warrior", "warriors" }) :
         "Many of the warriors of Haven come from the barracks to the north",
      ({ "lifeline" }) :
         "Imperial Road, the main lifeline of the city, lies ot the south.",
      ({ "city" }) :
         "The City of Haven is the largest city in all of Kailie.",
      ({ "sea" }) :
         "The legendary Ruined Sea lies to the south of here.",
   ]) );
   SetItemAdjectives( ([
      "barracks" : ({ "haven", "guard" }),
      "lifeline" : ({ "main" }),
      "city" : ({ "calm", "safe" }),
      "sea" : ({ "legendary", "ruined" }),
   ]) );
}

string CheckTraffic() {
   if(query_night()) {
      return "The traffic on this street at this hour of night is "
             "practically non-existant.";
   } else {
      return "Much of the traffic here is headed to and from the "
             "barracks to the north.";
   }
}

/* Approved by Duuktsaryth on Sun Apr 25 18:56:22 1999. */
