#include <lib.h>
#include "../averath.h"
inherit LIB_SENTIENT;

static void create() {
   sentient::create();
   SetTown("Averath");
   SetKeyName("citizen");
   SetShort("a citizen of Averath");
   SetId( ({ "citizen", "of averath", "averath_person", "averath_wander" }) );
   SetAdjectives( ({ "citizen" }) );
   SetLong(
     "This citizen of Averath doesn't seem to pay much attention to other "
     "passers by, and seems focused on themself."
   );   
   SetRace("human");
   SetClass("fighter");
   SetBaseLanguage("Avera");
   SetLevel(1 + random(4));
   if(random(2)) { SetGender("male"); }
   else  { SetGender("female"); }
   SetAction(5, ({ "!emote glances at you, and carries on walking." }) );
   SetCombatAction(20, ({ "!shout Help!", }) );
   SetInventory( ([                    
   ]) );
   SetWander(10);
  SetLimit(5);
   SetCurrency("ducats", 50);   
   SetMorality(50);
}
