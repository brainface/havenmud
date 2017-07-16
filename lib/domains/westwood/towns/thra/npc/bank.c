#include <lib.h>
#include "../thra.h"
inherit LIB_TELLER;

static void create() {
  teller::create();
  SetBankName("Guardian Tree");
  SetLocalCurrency("cuicui");
  SetLocalFee(2);
  SetLimit(1);
  SetNonLocalFee(2);
  SetTown("Thra");
  SetExchangeFee(0.2);
  SetKeyName("siolyn");
  SetShort("Siolyn the Treasurer of the Tree");
  SetId( ({ "siolyn", "treasurer", "gelfling", "banker", "teller" }) );
  SetLong(
    "Siolyn handles the finances for the village of Thra.  Though much smaller than "
    "the former lands of the Gelflings, the village still has need of quality financial "
    "institutions, and the Guardian Tree acts as one for the village."
    );
  SetRace("gelfling");
  SetGender("female");
  SetClass("evoker");
  SetLevel(35);
  SetCurrency("cuicui",random(10)+1);
  SetMorality(-100);
  SetAction(5, ({
    "!speak Please, trust in the services I offer.",
    "!speak The Guardian Tree is a secure facility.",
    "!cast sphere",
     }) );
  SetSpellBook( ([
    "fireball" : 100,
    "sphere"   : 100,
    "shock"    : 100,    
    ]) );
  SetCombatAction(25, ({
    "!cast fireball",
    "!cast sphere",
    "!cast shock",
  }) );
  SetFirstCommands( ({
    "cast sphere", "cast sphere",
  }) );
}
