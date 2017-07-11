#include <lib.h>
#include "../goblins.h"
inherit LIB_HEALER;

static void create() {
  ::create();
  SetKeyName("sinni");
  SetShort("Sinni Unt Alla");
  SetId( ({ "sinni", "healer", "alla","goblin" }) );
  SetAdjectives( ({ "sinni", "unt" }) );
  SetRace("goblin");
  SetFriends( ({ "goblin" }) );
  SetGender("female");
  SetClass("shaman");
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
  	"will of old"	        : 100,
  	"pious obstructions"	: 100,
  	"harm body"						: 100,
  	"fireball"            : 100,
    ]) );
  SetCombatAction(75, ({
  	"!cast will of old",
  	"!cast pious obstructions",
  	"!cast harm body",
  	"!cast fireball",
  	}) );
}
