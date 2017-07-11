
/* an attendent
   Elasandria 4/16/98
*/

#include <lib.h>
#include "../kingdom.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("attendent");
  SetShort("an attendent for the queen");
  SetId( ({"attendent","woman","faerie"}) );
  SetAdjectives( ({"young","petite","little","eager","happy"}) );
  SetLong("This young faerie looks eager to please her queen and smiles "
        "happily, humming under her breath.");
  SetGender("female");
  SetRace("faerie");
  SetClass("enchanter");
  SetLevel(8);
  SetMorality(180);
  SetAction(5,
            ({"!emote kneels beside the queen, awaiting her next command.",
            "The eager attendent kneels beside the queen, awaiting her next "
            "command."})
            );
  SetInventory( ([
           ]) );
  SetSpellBook( ([
           "buffer" : 80,
           "missile" : 80,
           ]) );
  SetCombatAction(75, ({
  				 "!cast buffer",
  				 "!cast missile"})
           );
}
