//
// Filename: gp2.c
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
   SetExits( ([
      "north" : H_ROOM + "imperial_road/ir7",
      "south" : H_ROOM + "galleons_passage/gp1",
   ]) );
   SetLong("The road continues to the north and south from here. "
           "Farther to the north the road meets up with Imperial "
           "Road, which is the central road in Haven Town.  To the "
           "south is the wharf district.");
   SetItems( ([
      ({ "road" }) :
         "From here, the road continues north to Imperial Road and south "
         "to the wharf district.",
      ({ "district" }) :
         "The district to the south of here is a place where much business "
         "is conducted.",
   ]) );
   SetItemAdjectives( ([
      "district" : ({ "wharf" }),
   ]) );
}


/* Approved by Duuktsaryth on Sun Apr 25 18:55:31 1999. */
