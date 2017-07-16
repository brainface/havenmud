#include <lib.h>
#include "../ph.h"
inherit LIB_NPC;

static void create() {
   ::create();
   SetKeyName("human");
   SetShort("a plain human");
   SetId( ({ "human" }) );
   SetAdjectives( ({ "plain" }) );
   SetGender( ({ "male","female" })[random(2)]);
   SetLong(
     "With few distinguishing features, this plain human is medium height with "
     "shoulder-length hair. " + capitalize(nominative(this_object())) +
     " looks sad and confused, and appears to have little strength."
   );
   SetClass("rogue");
   SetLevel(1);
   SetRace("human");
   SetCurrency("oros",10);
   SetAction(1, ({ 
     "!say Someone, please help me." 
   }) );
   SetCombatAction(1, ({ 
     "!say Help!" 
   }) );
}
