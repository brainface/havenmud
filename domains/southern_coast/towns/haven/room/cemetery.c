//
// Filename: cemetary.c
// Haven Town Cemetary
// Created by Duuktsaryth@Haven
// Modified by Kazgaroth@Haven
//

#include <lib.h>
#include <std.h>
#include <domains.h>
#include "haven.h"

inherit LIB_ROOM;

int PreExit();

static void create() {
   room::create();
   SetShort("a cemetery");
   SetExits( ([
      "out" : "holy_path/hp1",
   ]) );
   SetDayLong("During the day, the Haven Town cemetery is a quiet, "
              "peaceful place that eminates its position as the final "
              "resting place of the Elven greatest legends.  Graves "
              "line the paths, with tombs occasionally jutting from the "
              "ground like hands from the past. To the south, there "
              "seems to be a section of the cemetery that has fallen "
              "into what can only be described as swampland over the "
              "years of neglect.");
   SetNightLong("At night, the Haven Town cemetery looks positively evil. "
                "Its status as the final resting place of legends gives it "
                "an aura of its own power and contempt for life itself. "
                "The graves and tombs which adorn the ground enhance the "
                "image of this place as beyond death. To the south, a "
                "section of the cemetery has fallen into what can only "
                "be described as a swamplike state over the years of "
                "neglect and scorn.");
   SetNightLight(20);
   SetItems( ([
      ({ "cemetary", "swampland" }) :
         (: GetLong :),
      ({ "grave", "graves" }) : 
         "These graves are for those heroes of recent memory who have "
         "fought and died for Haven Town.",
      ({ "tomb","tombs", "hand", "hands" }) : 
         "These tombs spring from the ground like relics from an ancient "
         "age which was forgotten by its present.",
      ({ "path", "paths" }) :
         "These paths lead through the cemetary, visting each tomb.",
      ({ "ground" }) :
         "The ground here is lined with tombs of the Elven legends.",
   ]) );
   SetItemAdjectives( ([
      "cemetary" : ({ "haven", "town", "haven town" })
   ]) );
   SetListen( ([
      "default" : "The graveyard has the stillness of death.",
   ]) );
   SetSmell( ([
      "default" : "The smell of freshly dug earth wafts the air.",
   ]) );
   AddExit("south", SOUTHERN_COAST_AREAS "dw/room/field6", (: PreExit :));
   SetInventory( ([
      STD_OBJ "reztotem" : 1,
   ]) );
}

int PreExit() {
   if(this_player()->id("haven_wander")) return 0;
  if ( (this_player()->GetLevel() < 2) && userp(this_player()) ) {
    this_player()->eventPrint("You can't quite get your nerve up to enter the Old Cemetery yet. <Level 2 required!>");
    return 0;
  }
   return 1;
}


/* Approved by Duuktsaryth on Sun Apr 25 18:32:51 1999. */
