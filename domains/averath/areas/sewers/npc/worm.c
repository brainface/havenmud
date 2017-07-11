// Averath Sewers
// Aerelus

#include <lib.h>
#include <damage_types.h>
#include "../sewers.h"
inherit LIB_NPC;

static void create() {
  ::create();
  SetKeyName("slithering worm");
  SetShort("a slithering worm");
  SetId( ({ "worm" }) );
  SetAdjectives( ({ "slithering" }) );
  SetLong(
    "Around four feet long, this hideous worm wriggles around the lower caves. "
    "It is utterly disgusting, making a squishing sound as it darts around "
    "the cave at a respectable speed, for a worm."    
    );  
  SetRace("worm");
  SetClass("animal");
  SetGender("male");
  SetLevel(15);    
  SetCombatAction(1, ({
    "!emote wriggles up your body and tries to choke you!",
  	}) );
  SetAction(1, ({
    "!emote slitheres across the ground.",    
  	}) );  
  SetEncounter(0);
  SetMorality(0);
}