#include <lib.h>
#include <domains.h>
#include "../rome.h"
#include <std.h>
inherit LIB_FISHING;

int Guild(string);

static void create() {
        ::create();
  SetShort("Under the Sanctum docks");
  SetProperty("shallows", 1);
  SetExits( ([
          "up" : ROME_ROOM "docks",
          ]) );
  AddExit("north", ROME_ROOM "guild2", (: Guild :));
  SetLong("The Inner Sea surrounds everything here. The large wooden pillars keep "
          "the dock well above the water as well as prevent access to the ocean. "
          "There is a small staircase leading to the north which is the only "
          "other exit except going back up.");
   SetItems( ([
          "dock" : "The road is made of small to medium sized pieces of stone. "
                   "It continues to the north.",
     ({ "pillars" }) : "The wooden pillars surround the area keeping the docks "
             "well above the water line. There are so many pillars that they make "
             "it impossible to reach the ocean.",
     ({ "staircase", }) : "The small staircase is covered in water and slim "
                             "making it incredibly hard to climb.",
    ]) );
  SetItemAdjectives( ([
    "pillars" : ({ "large", "wooden" }),
    "staircase" : ({ "small" }),
    ]) );
  SetInventory( ([
    ]) );
  SetSmell( ([
    "default" : "The smell of the sea wafts from the south.",
    ]) );
  SetListen( ([
    "default" : "The sounds of the city swell from the north.",
    ]) );
  SetMaxFishing(10);
  SetFish( ([
    STD_FISH "guppy" : 200,
    STD_FISH "trout" : 100,
    ]) );
  SetChance(25);
  SetSpeed(5);
} 

int Guild(string dir) {
   if(this_player()->GetClass() != "rogue" && this_player()->GetClass() != "assassin" ){
   message("system", "You slip of the first stair and fall into the water.",this_player());
   return 0;
   }
   return 1;
 }

