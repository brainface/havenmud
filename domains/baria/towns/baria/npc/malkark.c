//
// Draco sage
// Created by: Rhakz@Haven -- Angel Cazares
// For: Baria
// Date: 06/04/99
//
// Fixed by Gaby
// Date: 08/05/99
#include <lib.h>
#include "../jungle.h"
inherit LIB_SAGE;

static void create() {
  sage::create();
  SetKeyName("Malkark");
  SetShort("Malkark the Wise Sage");
  SetId( ({ "sage","malkark","draconian","wise sage",
            "malkark the wise sage"
       }) );
  SetAdjectives( ({"wise","strong"}) );
  SetLong("Malkark is a draconian dedicated to teach languages to "
          "those who are willing to learn and can afford the price. "
          "His set of shiny red scales emphasizes his strong body."
         );
  SetRace("draconian");
  SetMorality(-300);
  SetClass("rogue");
  SetLevel(40);
  SetTown("Baria");
  SetGender("male");
  SetCurrency( ([ 
                 "chits" : 30 + random(15), 
             ]) );
  SetLocalCurrency("chits");
  SetCharge(300);
  SetTaughtLanguages( ({ "Dragonish", "Barian" }) );
}
