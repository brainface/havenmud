//
// Filename: ir8.c
// Part of the Imperial Road
// Created by Duuktsaryth@Haven
// Modified by Kazgaroth@Haven
//

#include <lib.h>
#include "../haven.h"

inherit LIB_ROOM;

int PreEnter();

static void create() {
   room::create();
   SetShort("the Imperial Road");
   SetExits( ([ 
      "west" : H_ROOM + "imperial_road/ir7",
   ]) );
   SetDayLong("Daylight seems to bend around the spires and towers of "
              "the Grand Library of Haven Town. Off to the west is the "
              "city center, and Imperial Road seems to dead-end "
              "here at the Library. The library itself seems to fairly "
              "crackle with the energy that it holds within.");
   SetNightLong("Starlight seems to bend around the spires and towers of "
                "the Grand Library of Haven Town. Off to the west is the "
                "city center, and Imperial Road seems to dead-end "
                "here at the Library.  The library itself seems to fairly "
                "crackle with the energy that it holds within.");
   SetItems( ([ 
      ({ "library" }) : 
         "This is the city library, perhaps you could <enter> it?",
      ({ "spire", "spires", "tower", "towers", "slab", "slabs", "marble" }) :
         "These spires and towers of the Grand Library are made of "
         "great slabs of marble.",
      ({ "center" }) :
         "The center of the city lies to the west of here.",
   ]) );
   SetItemAdjectives( ([
      "library" : ({ "great", "haven", "city", "town" }),
      "spire" : ({ "great" }),
      "center" : ({ "city" }),
   ]) );
   AddEnter("library", H_ROOM + "library/entrance", (: PreEnter :));
   SetInventory( ([
      H_NPC + "mage_guard" : 1,
   ]) );
   SetSmell( ([
      "default" : "The scents of burning incense and coal fill the air.",
   ]) );
   SetListen( ([
      "default" : "There is a hum of activity coming from the Library.",
   ]) );
}

int PreEnter() {
   if((this_player()->id("haven_wander")) &&
     (present("mage_guard"))) {
      message("system", "The warrior mage stops the " +
              this_player()->GetKeyName() + " from entering the Library.",
              this_object() );
      return 0;
   }
   return 1;
}

/* Approved by Duuktsaryth on Sun Apr 25 19:19:17 1999. */
