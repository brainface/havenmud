// Island
// Aerelus

#include <lib.h>
#include <domains.h>
#include "../island.h"

inherit LIB_ROOM;

varargs mixed eventDig(string what, object who);
int BeenDug;

static void create() {
  room::create();
  BeenDug = 0;
  SetAmbientLight(30);
  SetClimate("temperate");
  SetShort("in a dense jungle");
  SetLong(
    "Passage through this jungle is limited, with palm trees and other island "
    "foliage blocking most directions. The jungle extends to the west, while "
    "in the southwest there appears to be a sandy bay just past the trees. "
    "Wild green berries grow on bushes aound this area, providing food for "
    "the birds above and other creatures who call this place home."
  );
  SetItems( ([
  ({ "jungle" }) : (: GetLong :),
  ({ "bay" }) : 
    "The sandy bay lies beyond the trees in the southeast.",
  ({ "trees", "foliage" }) : 
    "Palm trees and other foliage make passage through this jungle very "
    "difficult.",
  ({ "berries", "bushes" }) : 
    "There are some bushes here, home to some small green berries.",    
  ({ "birds" }) : 
    "The birds in the treetops can be heard, but not seen from here.",  
  ]) );
  SetItemAdjectives( ([
    "bay" : ({ "sandy" }),
    "trees" : ({ "palm" }),
    "bay" : ({ "sandy" }),
    "berries" : ({ "green", "wild" }),
    "foliage" : ({ "island" }),
  ]) );
  SetInventory( ([
    ISLAND_NPC "monkey" : 1,
    ISLAND_NPC "monkey2" : 1,        
  ]) );
  SetListen( ([
    "default" : "The sound of the ocean comes from the southeast.",
  ]) );
  SetSmell( ([
    "default" : "The air here is very warm and humid.",
  ]) );
  SetExits( ([
    "west" : ISLAND_ROOM "island2",
    "southwest" : ISLAND_ROOM "port",    
  ]) );  
}

varargs mixed eventDig(object who, string what) {
  object chest = new(ISLAND_OBJ "chest");
	
	if (!chest) {
	  message("action", "Digging doesn't reveal anything.",
      this_player() );
	  return 0;
	}
	
  if (BeenDug == 1) {
  	message("action", "The earth looks freshly turned like someone has "
  	  "already dug here.",
      this_player() );
  	 return 0;
  }
  send_messages( ({ "dig", "bend" }),
    "$agent_name $agent_verb into the ground and then "
    "$agent_verb over to pick something up.",
    who, 0, environment(who) );
  chest->eventMove(ISLAND_ROOM "island3");
  message("action", "You find an old chest buried in the ground.",
      this_player() );
  BeenDug = 1;
  return 1;
}