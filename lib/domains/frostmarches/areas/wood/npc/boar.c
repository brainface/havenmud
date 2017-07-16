/* a wild boar
   Ela 8/8/98
*/

#include <lib.h>
#include "../wood.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("boar");
  SetId( ({
        "boar", "pig",
         }) );
  SetAdjectives( ({
         "wild", "viscious", "large", "agressive",
         }) );
  SetShort("a wild boar");
  
  SetRace("pig");
  SetClass("animal");
  SetLevel(4);
  SetGender("female");
  SetAction(5, ({
         "The boar squeals and snorts agressively."
         }) );
  SetLong("This viscious wild pig is very large and aggressive. "
         "Its wild unpredictability assures that most who "
         "cross its path leave it in peace.");
}
