#include <lib.h>
#include "../ruins.h"
inherit LIB_MAYOR;

static void create() {
   mayor::create();
   SetKeyName("sneskika");
   SetShort("Sneskika, Denmother of Arcanith");
   SetId( ({ "sneskika", "denmother", "mayor" }) );
   SetAdjectives( ({ "sneskika","denmother","of" }) );
   SetLong(
     "Despite kobold's relatively short lifespan, this crone "
     "seems to be nearly as old as the ruins itself. Her fur is "
     "thin and white, where it hasn't fallen off entirely. Every "
     "motion she makes is slow and measured, as if carefully "
     "calculated to use the least of her remaining energy. Despite "
     "this, her eyes still gleam with intelligence, and quickly dart "
     "over anyone entering the room."
   );
   SetRace("kobold");
   SetGender("female");
   SetClass("druid");
   SetLevel(75);
   SetTown("Arcanith");
   SetReligion("Magildan");
   SetTax(15);
   SetLocalCurrency("senones");
   SetMorality(100);
   SetInventory( ([
     OBJ "/mayor_cane" : "wield cane",
   ]) );
   SetLimit(1);
   SetAction(5, ({
     "!emote peers at you suspiciously.",
     "!say Do you wish to join our den?",
     "!emote listens to the clerk intensely.",
     "!Another stranger come, then?",
   }) );
   SetCombatAction( 50, ({
     "!cast ice storm",
     "!cast swarm",
     "!cast wall of wood",
     "!cast full regeneration",
   }) );
   SetFirstCommands( ({
     "cast wall of wood",
     "cast wall of wood",
     "cast wall of wood",
     "cast wall of wood",
     "cast wall of wood",
   }) );
   SetTownRanks( ({
     ({ "Chum", "Chum" }),
     ({ "Bolter", "Bolter" }),
     ({ "Scurrier", "Scurrier" }),
     ({ "Scamper", "Scamper" }),
     ({ "Harrier", "Harrier" }),
     ({ "Charger", "Charger" }),
     ({ "Pursuer", "Pursuer" }),
    }) );
}

