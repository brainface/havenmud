#include <lib.h>
#include "../haven.h"
inherit LIB_TRAINER;

static void create() {
  ::create();
  SetKeyName("quevalin");
  SetShort("Quevalin the Concerto Maestro");
  SetId( ({ "quevalin", "maestro" }) );
  SetAdjectives( ({ "concerto" }) );
  SetRace("elf");
  SetGender("male");
  SetClass("bard");
  SetSkill("instrumental music",1,1);
  SetSkill("vocal music",1,1);
  SetSkill("melee combat",1,1);
  SetSkill("disorient",1,2);
    
  SetTrainingSkills( ({
"stealth",
"bargaining",
  }) );
  SetLevel(180);
  SetMorality(1500);
  SetLong(
    "Quevalin the Concerto Maestro is the greatest living elven musician. "
    "His epic poems of the loss of the dark-elves and the split of the "
    "elven race rend the hearts of those who hear them, and his deep faith "
    "in Duuktsaryth keeps him grounded in a reality far from ideal or "
    "Orderly."
    );
  SetInventory( ([
  	"/std/instruments/lyre" : 1,
    ]) );
  SetSongBook( ([
  	"star strike" 						 : 100,
  	"vibration of destruction" : 100,
  	"reverberating note" 			 : 100,
  	"melody of war"			       : 100,
  	"ballad of spring"			   : 100,
  	"ballad of summer" 				 : 100,
  	"ballad of autumn" 				 : 100,
  	"ballad of winter" 				 : 100,
  	"ballad of seasons"				 : 100,
  	"hymn of the chorist"			 : 100,
  	]) );
  SetAction(5, ({
  	"!speak Yes, I can teach you about music!",
  	"!speak You require an instrument to play my songs.",
    }) );
  SetCombatAction(40, ({
  	"!sing ballad of seasons",
  	"!sing melody of war",
  	"!sing reverberating note",
  	"!sing star strike",
  	"!sing vibration of destruction",
  	"!disorient",
  	}) );
  SetLimit(1);
  SetTown("Haven");
}

  	
  	
