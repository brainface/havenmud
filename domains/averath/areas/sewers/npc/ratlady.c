// Averath Sewers
// Aerelus

#include <lib.h>
#include <damage_types.h>
#include "../sewers.h"
inherit LIB_NPC;

static void create() {
  ::create();
  SetKeyName("Calliste the Rat Lover");
  SetShort("a crazy-looking woman");
  SetId( ({ "woman", "calliste" }) );
  SetAdjectives( ({ "rat", "lover", "crazy", "looking", "crazy-looking" }) );
  SetLong(
    "Calliste the Rat Lover, as she is known to the local bandit population, "
    "is a very skinny woman. She looks unwashed, possibly for months, and has "
    "a constant grin on her face. She seems to love the local rats, giving "
    "them any scraps of food she comes across."    
  );  
  SetRace("human");
  SetClass("rogue");
  SetGender("female");
  SetBaseLanguage("Avera");
  SetLevel(5);  
  AddCurrency("ducats", random(10)+1);
  SetCombatAction(1, ({
    "!say Help me, my lovelies! Go for the ankles! Hehe!.",
    "!grin",
  }) );
  SetAction(3, ({
    "!snuggle first rat",
    "!chuckle",
    "!say My rats are the best, don't you think? I call this one Wiggles!",
  }) );
  SetInventory( ([      
     SEWERS_OBJ "oldrobe" : "wear robe",    
  ]) );
  SetEncounter(0);
  SetMorality(400);
}