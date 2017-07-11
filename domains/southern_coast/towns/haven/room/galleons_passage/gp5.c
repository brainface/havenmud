//
// Filename: gp5.c
// Part of Galleon's Passage
// Created by Duuktsaryth@Haven
// Modified by Kazgaroth@Haven
//

#include <lib.h>
#include "../haven.h"

inherit LIB_ROOM;

static void create() {
   room::create();
   SetShort("Galleon's Path");
   SetExits( ([
      "south" : H_ROOM + "galleons_passage/gp4",
      "north" : H_ROOM + "misc_buildings/grove",
   ]) );
   SetDayLong("The road ends here, leading back to the south towards "
              "the wharf and the Ruined Sea beyond that.  To the east "
              "is the headquarters of the Haven Town Guard.  The barracks "
              "is in a large building that seems to be made to withstand "
              "any civil disturbance.");
   SetNightLong("The road leads off to the Ruined Sea to the south.  To "
                "the east is the only sign of life at this time of night, "
                "the barracks of the Haven Town Guard.  Its mighty doors "
                "look like they could withstand a long siege.");
   SetItems( ([
      ({ "building", "barracks", "headquarters", "building" }) :
         "This is the Haven Town Guard's barracks.",
      ({ "road" }) :
         "Here, the road ends before the Haven Town Guard's barracks and "
         "heads south.",
      ({ "wharf" }) :
         "The commercial area of Haven, better known as the wharf, is "
         "located to the south of here.",
      ({ "sea" }) :
         "The Ruined Sea lies to the south from here.",
      ({ "door", "doors" }) :
         "The doors of the Haven Town Guard's barracks look like they "
         "could withstand quite a bit of damage.",
   ]) );
   SetItemAdjectives( ([
      "building" : ({ "haven", "town", "guard's", "guard" }),
      "sea" : ({ "ruined" }),
      "door" : ({ "mighty" }),
   ]) );
   SetEnters( ([
     "barracks" : H_ROOM + "barracks/barracks",
   ]) );
}


/* Approved by Duuktsaryth on Sun Apr 25 18:56:40 1999. */
