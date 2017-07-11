#include <lib.h>
inherit LIB_SENTIENT;
#include "../castle.h"

static void create() {
   sentient::create();
   SetKeyName("quiet serf");
   SetShort("a quiet serf");
   SetId( ({ "serf" }) );
   SetAdjectives( ({ "quiet" }) );
   SetLong("The serf seems calm and composed, ready for some more "
           "long hours of hard, back-breaking work.  He is probably "
           "just wandering through the castle to pick up tools or "
           "consult with someone, but could probably hold his "
           "own in a battle, if necessary, though not as well as "
           "any of the soldiers or guards.");
   SetGender("male");
   SetRace("human");
   SetClass("rogue");
   SetLevel(18+random(4));
   SetMorality(110);
   SetLimit(3); 
   SetWander(35);
}