#include <lib.h>
#include "../parva.h"
inherit LIB_MAYOR;

static void create() {
   mayor::create();
   SetKeyName("Thrash Greyjoy");
   SetShort("Admiral Thrash Greyjoy of Parva");
   SetId( ({ "thrash", "admiral", "greyjoy", "parva_wander" }) );
   SetAdjectives( ({ "admiral", "thrash", "greyjoy" }) );
   SetLong(
     "Admiral Thrash Greyjoy is a well respected and feared sea captain "
     "whose roots in Parva go back many generations. His family is one of "
     "the most powerful, with his brother Aeron as High Clerist of Damhair. "
     "Admiral Greyjoy is a man with whom a great deal of authority is vested. "
     "Those seeking rank in Parva, from citizen to Grande Duque, must talk "
     "to him."
     );
   SetRace("human");
   SetGender("male");
   SetClass("sailor");
   SetClass("rogue");
   SetLevel(75);
   SetTown("Parva");
   SetReligion("Damhair");
   SetTax(15);
   SetLocalCurrency("oros");
   SetMorality(-100);
   SetInventory( ([
     PARVA_OBJ + "mayor_boots" : "wear boots",
     PARVA_OBJ + "mayor_belt"  : "wear belt",
     PARVA_OBJ + "mayor_pants" : "wear pants",
     PARVA_OBJ + "mayor_shirt" : "wear shirt",
     PARVA_OBJ + "mayor_knife" : 2,
     ]) );
   SetFirstCommands( ({ "wield knives" }) );
   SetLimit(1);
   SetAction(5, 
     ({ "!speak Those that live in Parva know the rules of the sea, and respect the Drowned God." })
     );
   SetTownRanks( ({
    ({ "Chum", "Chum" }),
    ({ "Citizen", "Citizen" }),
    ({ "Senor", "Senora" }),
    ({ "Vizconde", "Vizcondesa" }),
    ({ "Conde", "Condesa" }),
    ({ "Duque", "Duquesa" }),
    ({ "Grande Duque", "Grande Duquesa" }),
    }) );
}