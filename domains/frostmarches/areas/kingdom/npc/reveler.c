
/*  a reveler
   Ela 4/20/98
*/

#include <lib.h>
#include "../kingdom.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("reveler");
  SetShort("a faerie reveler");
  SetId( ({"reveler","faerie"}) );
  SetAdjectives( ({" "}) );
  SetLong("All faeries enjoy their pleasures and this particular guy is no "
         "exception. His eyes sparkle with glee as he happily dances and "
         "plays.");
  SetGender("male");
  SetRace("faerie");
  SetClass("enchanter");
  SetLevel(8);
  SetMorality(110);
  SetAction(5, ({
  			"!emote drunkenly raises a toast to you.",
        "!emote whispers a baudy joke and laughs uproariously."}) 
        );
  SetInventory( ([
         ]) );
  SetSpellBook( ([
         "buffer"  : 100,
         "missile" : 100,
         ]) );
  SetCombatAction(70, ({
  			"!cast buffer",
  			"!cast middile",
  			})
          );
}
