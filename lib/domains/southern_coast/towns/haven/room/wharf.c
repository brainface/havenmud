//
// Filename: wharf.c
// The Haven Town Wharf
// Created by Duuktsaryth@Haven
// Modified by Kazgaroth@Haven
//

#include <lib.h>
#include <std.h>
#include "../haven.h"
#include <domains.h>

inherit LIB_FISHING;
int MakeCaptain();


int CheckPC();
int ClosedTavern();

static void create() {
   fishing::create();
  SetNoClean(1);
   SetShort("the wharf");
  SetProperty("coastal", 1);
   SetExits( ([
      "north" : "merchants_way/mw1",
   ]) );
   AddExit("south", INNERSEA_VIRTUAL "ocean/0,0", (: CheckPC :));
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
      ({ "door" }) :
         "This door to the tavern has a small sign tacked onto it.",
   ]) );
   SetItemAdjectives( ([
      "tavern" : ({ "warm", "inviting" }),
      "ship" : ({ "exotic" }),
      "crew" : ({ "harbor", "master's", "harbor master's" }),
      "road" : ({ "main" }),
      "sea" : ({ "ruined" }),
      "door" : ({ "tavern" }),
   ]) );
   SetEnters( ([
      "tavern" : H_ROOM + "shops/tavern",
   ]) );
   SetListen( ([
      "default" : "The bustle of business is in the air.",
   ]) );
   SetSmell( ([
      "default" : "The smell of the sea abounds here.",
   ]) );
   SetSpeed(5);
   SetFish( ([
      STD_FISH "guppy" : 100,
      STD_FISH "trout" : 10,
      STD_FISH "boot" : 1,
      STD_FISH "fire/flamefin_1" : 5,
      STD_FISH "fire/flamefin_2" : 1,
   ]) );
   SetChance(25);
   SetMaxFishing(12);
  SetInventory( ([
    //H_OBJ "ferry" : 1,
    H_OBJ "yacht"  : 1,
    //H_NPC "ferrycaptain" : 1,
    STD_OBJ "dock_sign" : 1,
    H_NPC "t_fisher" : 1,
    ]) );

    call_out( (: MakeCaptain :), 0);
}

int CheckPC() {
  if(this_player()->id("haven_wander")) return 0;
  return 1;
}


int ClosedTavern() {
   message("system", "Tacked onto the door is a sign. "
           "The door does not budge when you try to open it.",
           this_player());
   return 0;
}

int MakeCaptain() {
  object captain = new(H_NPC "ferrycaptain");
  object ferry = new(H_OBJ "ferry");
  if (!captain) return 0;
  if (!ferry) return 0;
  ferry->eventMove(this_object());
  captain->eventMove(ferry);
  return 1;
}


/* Approved by Duuktsaryth on Sun Apr 25 18:36:06 1999. */

