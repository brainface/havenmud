#include <lib.h>
#include <daemons.h>
#include "../path.h"
inherit LIB_TELLER;

static void create() {
  teller::create();
  SetBankName("Shire Trade Commissariat");
  SetLocalCurrency("rounds");
  SetCurrencies( ({ 
  	"imperials",
    "rounds",
    "rupies", 
    "orcteef", 
    "nuggets",
    }) );
  SetLocalFee(0);
  SetNonLocalFee(1);
  SetTown("Lloryk");
  SetExchangeFee(0.01);
  SetKeyName("keller");
  SetShort("Keller Underhill, Commissar of Trade");
  SetId( ({ "keller", "commissar", "underhill", "teller", "banker" }) );
  SetAdjectives( ({ "keller", "trade", }) );
  SetLong("Keller is remarkably well built for a halfling, even in his "
          "advancing years his chest is much larger than his belly.  He "
          "wears a fine looking three-piece suit and a friendly smile.");
  SetRace("halfling");
  SetGender("male");
  SetClass("rogue");
  SetMorality(-500);
  SetLevel(18);
  SetCurrency("rounds", random(750)+1);
}

string *GetCurrencies() { return ECONOMY_D->GetCurrencies(); }
