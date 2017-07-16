// Island
// Aerelus

#include <lib.h>
#include <domains.h>
#include "../island.h"

inherit LIB_ROOM;

string SearchCrack();
int BeenSearched;

static void create() {
  room::create();
  BeenSearched = 0;
  SetAmbientLight(30);
  SetClimate("temperate");
  SetShort("on a rocky plateau");
  SetLong(
    "Here, near the top of the rock formation, is a small plateau with a "
    "short wall of rocks lining the cliff edge. There appears to be an "
    "engraving on one of the rocks, while a break in the wall leads to "
    "the path down, which looks rather steep. There is a primitive chair "
    "here, made from large tree branches, positioned near the edge of the "
    "plateau. The view here is awe-inspiring, looking out over the green "
    "treetops and beyond to the seemingly endless ocean."    
  );
  SetItems( ([
  ({ "formation", "plateau", "top" }) : (: GetLong :),
  ({ "wall", "rocks" }) : 
    "A short wall of rocks lines the cliff edge, preventing things from "
    "falling off.",
  ({ "edge" }) : 
  	"The edge of the cliff is lined by a short wall. The drop looks "
  	"perilous.",
  ({ "engraving" }) : 
    "On closer inspection, the engraving appears to read 'ten steps east', "
    "and is followed by a crude drawing of some palm trees surrounding a "
    "rock.",
  ({ "chair" }) : 
    "Made from the branches of some nearby trees, this sturdy chair looks "
    "relatively comfortable. There is a narrow crack in the left armrest, "
    "showing the age of this chair.",
  ({ "armrest" }) : 
    "The left armrest appears to have been cracked.",
  ({ "crack" }) : 
    "The crack in the armrest looks big enough to hide something in.",
  ({ "view", "treetops", "ocean" }) : 
  	"The view here is awe-inspiring, looking out over the green "
    "treetops and beyond to the seemingly endless ocean.",
  ]) );
  SetSearch("crack", (: SearchCrack :) );
  SetItemAdjectives( ([
    "formation" : ({ "rock" }),
    "wall" : ({ "short" }),
    "chair" : ({ "primitive" }),
    "hall" : ({ "main", "worship", "tall" }),
    "plateau" : ({ "small", "rocky" }),
    "view" : ({ "awe-inspiring" }),
    "treetops" : ({ "green" }),
    "ocean" : ({ "seemingly", "endless" }),
  ]) );
  SetInventory( ([
    ISLAND_NPC "herman" : 1,
    ISLAND_NPC "monkey2" : 1,
  ]) );
  SetListen( ([
    "default" : "The air whistles as it passes over the rock formation.",
  ]) );
  SetSmell( ([
    "default" : "The air at this altitude is cold and refreshing.",
  ]) );
  SetExits( ([
    "down" : ISLAND_ROOM "path2",    
  ]) );  
}

string SearchCrack()
{
  // Purely coincidental..
  if (BeenSearched)
  {
    // Crack has been searched recently. No joy.
    message("action", "It seems that someone has already forced something "
      "out of the crack.", this_player() );
    return "";
  }
  if (random(150) < this_player()->GetStatLevel("luck"))
  {
    // With a little luck, the player will find a key.
    new(ISLAND_OBJ "island_key")->eventMove(this_player());
    message("action", "You find a key hidden in the crack!", this_player() );
  }
  // Let's let everyone else know what this player is up to.
  send_messages("poke", 
    "$agent_name $agent_verb around the crack, looking for something.",
    this_player(), 0, this_object() );
  return "";
}