#include <lib.h>
#include "../goblins.h"
inherit LIB_HEALER;

static void create() {
  ::create();
  SetKeyName("sinni");
  SetShort("Sinni Unt Alla");
  SetId( ({ "sinni", "healer", "alla" }) );
  SetAdjectives( ({ "sinni", "unt" }) );
  SetRace("goblin");
  SetGender("female");
  SetClass("cleric");
  SetLevel(90);
  SetStat("wisdom", 10000, 1);
  SetCurrency("rounds", 70);
  SetMorality(100);
  SetLong("Sinni is the daughter of the khan and the local healer.  Her abilities range "
          "from both the mundane healing of minor wounds to the full "
          "resurrection of the dead. Of course, she reserves the right "
          "to be richly compensated for her services.");
  SetLocalCurrency("rounds");
  SetFees( ([
    "resurrect" : 5,
    "stamina" : 1,
    "health" : 3,
    "restore" : 6,
    ]) );
  SetTown("Kresh");
  SetLimit(1);
  SetSpellBook( ([
  	"empower"											 : 100,
  	"divine power" 								 : 100,
  	"summon lesser effigy" 				 : 100,
  	"summon relic of the faithful" : 100,
    ]) );
  SetInventory( ([
  
  	]) );
  SetCombatAction(80, ({
  	"!cast empower on sinni",
  	"!cast divine power",
  	"!cast summon lesser effigy",
  	"!cast summon relic of the faithful",
    }) );
}
