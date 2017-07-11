#include <lib.h>
#include <std.h>
#include "../gwonish.h"
inherit LIB_MAYOR;

static void create() {
   mayor::create();
   SetKeyName("Sslan Sslar");
   SetShort("High Chief Sslan Sslar");
   SetId( ({ "chief", "sslan", "sslar", }) );
   SetAdjectives( ({ "high", "chief", "sslan" }) );
   SetLong(
     "Sslan Sslar is the High Chief of the Lizardman Tribe in Gwonish. "
     "His nasty greenish skin has a sickly yellow cast to it. He is the "
     "sole arbiter of social rank here in the swamp."
     );
   SetRace("lizardman");
   SetGender("male");
   SetClass("fighter");
   SetLevel(75);
   SetTown("Gwonish");
   SetTax(15);
   SetLocalCurrency("rounds");
   SetMorality(-500);
   SetInventory( ([
     GWONISH_OBJ "serrated"   : "wield sword",
     STD_CLOTHING "body/loin" : "wear loincloth",
     ]) );
   SetLimit(1);
   SetTownRanks( ({
    ({ "Worm", "Worm" }),
    ({ "Citizen", "Citizen" }),
    ({ "Raider", "Raider" }),
    ({ "Hunter", "Huntress" }),
    ({ "Chief", "Chief" }),
    ({ "Elder", "Elder" }),
    ({ "High Chief", "High Chief" }),
    }) );
}