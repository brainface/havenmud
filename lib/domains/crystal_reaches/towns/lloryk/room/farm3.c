#include <lib.h>
#include "../path.h"
#include <std.h>
inherit LIB_ROOM;
int Post(string dir);

static void create() {
  ::create();
  SetShort("before a chicken coop");
  SetExits( ([
    "south" : LLORYK "room/farm2",
    "east"  : LLORYK "room/farm4",
    ]) );
  SetLong("The ground has been cleared to make room for the pigs and the "
          "large chicken coop. To the south a small field can be seen while "
          "to the east a hilly pasture is visible.");
  SetItems( ([
      ({ "coop" }) : 
         "The large chicken coop looks like it could hold a large number of "
         "chickens.",
      ({ "ground" }) : 
         "The ground is muddy and covered in pig tracks as well as pig manure.",
      ({ "manure", "tracks" }) : 
         "The pig manure and tracks cover the ground.",
      ({ "field" }) : 
         "A small field can be seen to the south.",
      ({ "pasture" }) : 
         "The hilly pasture is visible to the east.",
   ]) );
  SetItemAdjectives( ([
      "coop" : ({ "chicken", "large" }),
      "manure" : ({ "pig" }),
      "pasture" : ({ "hilly" }),
      "field" : ({ "small" }),
   ]) );
  AddEnter("coop", LLORYK "room/chickencoop", 0, (: Post :) );
    
  SetSmell( ([
    "default" : "Fertilizer and pig stinks up the air.",
    ]) );
  SetListen( ([
    "default" : "The occasional \"moo\" drifts in from afar.",
    ]) );
  SetInventory( ([
    STD_NPC "pig" : 3,
    ]) );
  SetFarmingBonus(15);  
}



int Post(string dir) {
  if (!(this_player()->GetQuestCompleted("Chicken Coop"))) {
    this_player()->AddQuest("the Feather Ruffler", "Chicken Coop");
    this_player()->eventPrint("%^BOLD%^GREEN%^You have crawled inside a chicken coop!%^RESET%^");
    this_player()->AddDevelopmentPoints(10);
    }
  return 0;
}
