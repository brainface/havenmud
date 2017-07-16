//
// Filename: wharf.c
// The Haven Town Wharf
// Created by Duuk@Haven
// Modified by Kazgaroth@Haven
//

#include <lib.h>
#include <std.h>

inherit LIB_FISHING;

int ClosedTavern();

static void create() {
   fishing::create();
   SetShort("the wharf");
   SetExits( ([
      "north" : "room1",
   ]) );
   SetDayLong("The business of the wharf is a surly hustle and bustle "
              "during the day, with ships being loaded and unloaded "
              "with the practiced ease of the harbor master's crew. "
              "Further to the north are the main roads of Haven Town, "
              "while to the south the Ruined Sea stretches out as far "
              "as the eye can see.  To the east is a tavern.");
   SetNightLong("At night, the wharf is less busy than during the day, "
                "but even in the slowest hour of the night there is a "
                "considerable amount of traffic.  Ships lie at dockside "
                "awaiting the morrow's activities.  Off to the north the "
                "town of Haven spreads out in orderly fashion, while to "
                "the south the Ruined Sea extends to infinitum.  A large "
                "tavern is to the east.");
   SetItems( ([
      ({ "tavern", "building" }) : 
         "This warm and inviting building is the Divine Chalice, a "
         "local tavern.",
      ({ "ship", "ships" }) : 
         "The ships are from exotic ports of call.",
      ({ "cargo", "contents" }) :
         "The crates' contents are unguessable.",
      ({ "crew" }) :
         "The harbor master's crew is assisting in the unloading and "
         "loading of ships.",
      ({ "road", "roads" }) :
         "These main roads of Haven Town head off to the north.",
      ({ "sea" }) :
         "The Ruined Sea to the south stretches out beyond what can be "
         "seen.",
      ({ "traffic" }) :
         "Being an important place of business, traffic is always running "
         "through here.",
      ({ "sign" }) :
         "This small sign is tacked to the door of the tavern.",
      ({ "door" }) :
         "This door to the tavern has a small sign tacked onto it.",
   ]) );
   SetItemAdjectives( ([
      "tavern" : ({ "warm", "inviting" }),
      "ship" : ({ "exotic" }),
      "crew" : ({ "harbor", "master's", "harbor master's" }),
      "road" : ({ "main" }),
      "sea" : ({ "ruined" }),
      "sign" : ({ "small" }),
      "door" : ({ "tavern" }),
   ]) );
   SetRead( ([
      "sign" : "Until further notice, the Divine Chalice Tavern is "
               "closed.",
   ]) );
   SetEnters( ([
   ]) );
   SetListen( ([
      "default" : "The bustle of business is in the air.",
   ]) );
   SetSmell( ([
      "default" : "The smell of the sea abounds here.",
   ]) );
   SetSpeed(5);
   SetFish( ([
      DIR_STD "fish/guppy" : 100,
      DIR_STD "fish/shark" : 10,
   ]) );
   SetChance(25);
   SetMaxFishing(12);
}

int ClosedTavern() {
   message("system", "Tacked onto the door is a sign. \n"
           "The door does not budge when you try to open it.",
           this_player());
   return 0;
}


/* Approved by Duuk on Sun Apr 25 18:36:06 1999. */
