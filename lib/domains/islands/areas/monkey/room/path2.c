// Island
// Aerelus

#include <lib.h>
#include <domains.h>
#include <damage_types.h>
#include "../island.h"

inherit LIB_ROOM;
int PreExit(string dir);
int HeadChance;
int FallDamage;
int HeadDamage;
int SleepTime;

static void create() {
  room::create();
  SetAmbientLight(30);
  SetClimate("temperate");
  SetShort("on a rocky path");
  SetLong(
    "The path through the jungle here is covered with rocks, as the jungle "
    "ends at the base of a large rock formation. The path seems to continue "
    "upwards to the summit, though the rocks look like they could slip at any "
    "moment. The jungle continues to the southwest, eventually leading back "
    "to the bay."      
  );
  SetItems( ([
  ({ "jungle" }) : (: GetLong :),
  ({ "path" }) : 
    "Covered with rocks, the path ends here at the base of the rock "
    "formation.",
  ({ "formation", "summit", "base" }) : 
    "The path leads up this rock formation, presumably to the summit.",
  ({ "rocks" }) : 
    "Some of the rocks on the summit path look very unstable.",    
  ]) );
  SetItemAdjectives( ([
    "formation" : ({ "rock", "large" }),
  ]) );
  SetInventory( ([
    ISLAND_NPC "monkey" : 1,    
  ]) );
  SetListen( ([
    "default" : "The distant sound of the ocean can be heard to the south.",
  ]) );
  SetSmell( ([
    "default" : "The ocean air is a little salty, but very refreshing.",
  ]) );
  SetExits( ([    
    "southwest" : ISLAND_ROOM "path1",    
  ]) );
  AddExit( "up", ISLAND_ROOM "summit", (: PreExit :));
}  

int PreExit(string dir) 
{	  
    // You shall not pass! If the player isn't very agile, he should 
    // fall down.
    if (random(100) > this_player()->GetStatLevel("agility")) {
    send_messages("climb", 
    	"As $agent_name $agent_verb up the path, one of the rocks gives way, "
    	"causing $agent_objective to fall back down!",
    	this_player(), 0, this_object() );  	  
  	// When falling, the player may be unlucky enough to whack their head
  	// against a rock (3/5 chance).
  	HeadChance = random(4);  		
  	HeadDamage = 0;
  	if (HeadChance > 1)
  	{  		
  	  send_messages("fall", 
    	  "As $agent_name $agent_verb, $agent_possessive head strikes a rock, "
    	  "knocking $agent_objective unconscious.",
    	this_player(), 0, this_object() );  	
    	// Player is knocked unconscious for a little.
    	SleepTime = random(10);
    	if (SleepTime < 1)
    	{
    		SleepTime = 1;
    	}
   	  this_player()->SetSleeping(SleepTime);   	  
   	  // And takes some head damage.
   	  HeadDamage = random(100);
   	  if (HeadDamage < 50)
   	  {
   	  	HeadDamage = 50;
   	  }
   	  this_player()->eventReceiveDamage(this_player(), BLUNT, 
   	    HeadDamage, "head");
    }
    // So, even if the player doesn't hit their head, they will still take 
    // some damage. Based on their coordination, since they could know how
    // to fall properly, etc.    
    FallDamage = random(300) - this_player()->GetStatLevel("coordination");
    if (FallDamage < 100)
    {
    	FallDamage = 100;
    }
    this_player()->eventReceiveDamage(this_player(), BLUNT, 
      FallDamage, "torso");    
  	return 0;
  }
  // Otherwise, they can pass.
  return 1;    
}

