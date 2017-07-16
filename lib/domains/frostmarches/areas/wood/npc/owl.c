/* an owl
   Ela 11/2/98
*/

#include <lib.h>
#include "../wood.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("owl");
  SetShort("an owl");
  SetId( ({ "owl","bird","fighter","predator"}) );
  SetAdjectives( ({ "fierce" }) );
  
  SetRace("bird");
  SetClass("animal");
  SetGender("female");
  SetLevel(2);
  SetAction(2, ({
       "The owl watches the wood with a predator's keen eye.",
       }) );
  SetLong("The owl's feathers are mostly brown and white, "
        "allowing it to blend well with its surroundings. "
        "Brilliant yellow eyes and sharp talons make it "
        "a fierce fighter.");
}
