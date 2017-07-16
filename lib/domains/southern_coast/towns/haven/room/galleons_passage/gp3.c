//
// Filename: gp3.c
// Part of Galleon's Passage
// Created by Duuktsaryth@Haven
// Modified by Kazgaroth@Haven
//

#include <lib.h>
#include "../haven.h"

inherit LIB_ROOM;

static void create() {
   room::create();
   SetShort("Galleon's Passage");
   SetInventory( ([
      H_NPC + "guard" : 1,
   ]) );
   SetExits( ([
      "north" : H_ROOM + "galleons_passage/gp4",
      "south" : H_ROOM + "imperial_road/ir7",
   ]) );
   SetDayLong("To the south, the road meets up with the Imperial Road, "
              "which is the chief path through Haven Town.  Further to "
              "the north is the Haven Guard barracks, which is the home "
              "of the warriors that protect the town.  To the south is "
              "the Ruined Sea and the wharf district which borders it.");
   SetNightLong("The road meets up with the Imperial Road to the south, "
                "and even at night the traffic along that road seems to "
                "not stop.  Far to the north is the Haven Guard barracks, "
                "while to the south is the wharf.");
   SetItems( ([
      ({ "road", "path" }) :
         "To the south of here, the road meets with Imperial Road, the "
         "main path through the city. To the north lies the Haven Guard "
         "barracks.",
      ({ "barracks", "home" }) :
         "The Haven Guard barracks, home of the protectors of Haven, lies "
         "to the north.",
      ({ "warrior", "warriors" }) :
         "The many warriors that help protect the city are trained in "
         "the barracks to the north.",
      ({ "town", "city" }) :
         "The town of Haven stretches in all directions from here. The "
         "only path through the city, however, is a road that runs north "
         "and south through here.",
      ({ "sea" }) :
         "To the south lies the legendary Ruined Sea.",
      ({ "district", "wharf" }) :
         "The wharf district of Haven lies to the south of here.",
      ({ "traffic" }) :
         "Even during the night hours the traffic on this road does "
         "not cease.",
   ]) );
   SetItemAdjectives( ([
      "road" : ({ "main", "chief" }),
      "barracks" : ({ "haven", "town", "guard" }),
      "town" : ({ "haven" }),
      "sea" : ({ "ruined", "legendary" }),
      "district" : ({ "wharf" }),
   ]) );
}


/* Approved by Duuktsaryth on Sun Apr 25 18:55:43 1999. */
