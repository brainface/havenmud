//
// Filename: ir6.c
// Part of the Imperial Road
// Created by Duuktsaryth@Haven
// Modified by Kazgaroth@Haven
//

#include <lib.h>
#include "../haven.h"

inherit LIB_ROOM;

static void create() {
   room::create();
   SetShort("the Imperial Road");
   SetExits( ([
      "west" : H_ROOM + "imperial_road/ir5",
      "east" : H_ROOM + "imperial_road/ir7",
   ]) );
   SetLong("The road continues to the east and west from here.  Off to "
           "the east the road meets the Galleon's Passage, a road which "
           "leads to the wharf district.  Farther to the east is the "
           "Haven Library, while directly to the north lies the town "
           "post office.");
   SetItems( ([
      ({ "office" }) : 
         "This is the town post office. Perhaps you could <enter> it?",
      ({ "passage" }) :
         "Galleon's Passage meets this road to the east, leading to the "
         "wharf district",
      ({ "wharf", "district" }) :
         "The wharf district can be found by following Galleon's Passage "
         "located to the east.",
      ({ "library" }) :
         "The Haven Library, famous for its home to many powerful "
         "magic users, lies to the east.",
   ]) );
   SetItemAdjectives( ([
      "office" : ({ "post", "town" }),
      "passage" : ({ "galleon's" }),
      "district" : ({ "wharf" }),
      "library" : ({ "haven" }),
   ]) );
   SetEnters( ([
      "office" : H_ROOM + "misc_buildings/office",
   ]) );
}


/* Approved by Duuktsaryth on Sun Apr 25 19:18:46 1999. */
