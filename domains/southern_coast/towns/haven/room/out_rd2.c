//
// Filename: out_rd2.c
// A small road leading to Haven Town
// Created by Zaxan@Haven
// Modified by Kazgaroth@Haven
//

#include <lib.h>
#include <domains.h>
#include "haven.h"

inherit LIB_ROOM;

int PreExit();

static void create() {
   room::create();
   SetShort("a small cobblestone road");
   SetDayLong("This small cobblestone road travels through "
              "Kailie, leading its followers to other places "
              "in the world. The light shines nicely through "
              "the clouds in the sky and illuminates the entire "
              "wilderness. To the west, only more road can be seen, "
              "but to the east, there seems to be a town.");
   SetNightLong("This small cobblestone road travels through "
                "Kailie, leading its followers to other places "
                "in the world. The moon shines down on the wilderness "
                "in an effort to help people see. To the west, only "
                "more road can be seen, but to the east, small "
                "specks of something can be spotted.");
   SetItems( ([
      ({ "road" }) : 
         "This nicely made cobblestone road heads in the eastern and "
         "western directions.",
      ({ "kailie", "world" }) :
         "The world of Kailie stretches in all directions without end.",
      ({ "followers", "follower" }) :
         "Many followers pass through here to get to many different "
         "places in the world",
      ({ "wilderness" }) :
         "The wilderness of Kailie stretches off to the west.",
      ({ "town" }) :
         "A large town can barely be seen to the east.",
      ({ "specks" }) :
         "Small specks of something bright can be seen to "
         "the east.",
   ]) );
   SetItemAdjectives( ([
      "road" : ({ "small", "cobblestone" }),
      "town" : ({ "large" }),
      "specks" : ({ "small" }),
   ]) );
   SetExits( ([
   ]) );
   AddExit("east", H_ROOM "out_rd1" );
   AddExit("west", SOUTHERN_COAST_VIRTUAL "havenroad/22,0", (: PreExit :) );
}


int PreExit() {
  if (this_player()->id("haven_wander")) {
    if (this_player()->GetOwner() == "")
      return 0;
    }
  return 1;
}


/* Approved by Duuktsaryth on Sun Apr 25 18:35:23 1999. */
