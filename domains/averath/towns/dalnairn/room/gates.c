// Dalnairn
// Aerelus

#include <lib.h>
#include <domains.h>
#include "../dalnairn.h"

inherit LIB_ROOM;
int PreExit();

static void create() {
  room::create();
  SetAmbientLight(30);
  SetClimate("temperate");
  SetShort("before the gates of Dalnairn");
  SetLong(
    "The path ends here before the great city of Dalnairn. Home to a large "
    "population of dark-dwarf who follow the Soirin faith, it is a beautiful "
    "sight to behold. Most of the buildings, including the tall gates here, "
    "are made from obsidian; the dark, naturally occuring glass-like "
    "mineraloid which the dark-dwarf have been mining from this now dormant, "
    "grass-covered volcano. The path leads down the mountain to the east, "
    "while the city lies west."
  );
  SetItems( ([
  ({ "path" }) :
    "The path ends here before the gates of Dalnairn, and leads down the "
    "mountain.",
  ({ "buildings" }) : 
    "None of the buildings are enterable from here. They are mostly "
    "constructed with stone and obsidian.",
  ({ "gates" }) : 
    "The tall obisidian gates lead to Dalnairn, home of the Duergar race. ",
  ({ "obsidian", "mineraloid" }) : 
    "Most of the buildings in the city, including the gates here, are made "
    "from the dark glass-like mineraloid obsidian.",
  ({ "volcano", "grass", "mountain" }) : 
    "This mountain was once a volcano. Now dormant, it is covered with thick "
    "green grass.",
  ({ "path" }) : 
    "The path leads down the mountain to other parts of Averath.",
  ({ "city", "dalnairn" }) : 
    "The city of Dalnairn, home of the Duergar, lies west through the gates.",    
  ]) );
  SetItemAdjectives( ([
    "gates" : ({ "tall", "obsidian" }),
    "buildings" : ({ "stone", "obsidian" }),
    "volcano" : ({ "grass-covered", "dormant" }),    	
  ]) );
  SetInventory( ([
    DAL_NPC "guard" : 2,    
  ]) );
  SetListen( ([
    "default" : "The sounds of city life drift in from the west.",
  ]) );
  SetSmell( ([
    "default" : "At this height, the air is clean and refreshing.",
  ]) );
  SetExits( ([    
    "west" : DAL_ROOM "road1",    
  ]) );
  // Link to somewhere on averath here
  AddExit("east", DAL_DIR "../../virtual/averathroad/-30,0", (: PreExit :) );
}

int PreExit() {
  if (this_player()->id("dalnairn_people")) {
    if (this_player()->GetOwner() == "")
      return 0;
    }
  return 1;
}