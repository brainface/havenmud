
/* a faerie guard
   Elasandria 4/19/98
*/

#include <lib.h>
#include "../kingdom.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("guard");
  SetShort("a faerie guard");
  SetId( ({"soldier","guard","faerie"}) );
  SetAdjectives( ({"faerie","slight","wiry"}) );
  SetLong("This faerie soldier looks to have a wiry strength to his slight "
          "form. His features are distinctly chiseled and his eyes glitter "
          "with a heightened awareness of his surroundings.");
  SetGender("male");
  SetRace("faerie");
  SetClass("ranger");
  SetMorality(125);
  SetLevel(20);
  SetAction(5,
          ({"!emote smirks.",
           "The faerie guard smirks at you."})
           );
  SetSpellBook( ([
           "tangle" : 100,
           "summon animal" : 100,
           ]) );
  SetCombatAction(75, ({
  				"!cast tangle",
  				"!cast summon animal"})
            );
}
