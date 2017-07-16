// Karak Rewrite
// Laoise
// 2007

#include <lib.h>
#include "../karak.h"
inherit LIB_TELLER;

static void create() {
  teller::create();
  SetKeyName("ouphe");
  SetShort("Ouphe the Teller");
  SetId( ({ "ouphe the teller", "ouphe", "teller", "banker" }) );
  SetLong(
    "Ouphe is the teller at the Karak Bank. She was also the project "
    "foreman while the bank was being built. She is big, tough, and knows "
    "everything there is to know about money and currencies. Her presence "
    "in Karak, as with other half-orcs, is tolerated because none of the "
    "full-breed orcs would be willing to endure days spent keeping accounts, "
    "nor a life learning all there is to know of finances. The orcs see her "
    "presence as a lesser insult than one of their own engaging in banking."
  );
  SetRace("half-orc");
  SetGender("female");
  SetClass("rogue");
  SetLevel(30);
  SetTown("Karak");
  SetReligion("Saahagoth", "Saahagoth");
  SetMorality(-500);
  SetCurrency("orcteef", random(200));
  SetInventory( ([
  	]) );  
  SetBankName("Karak Bank");
  SetLocalCurrency("orcteef");
  SetCurrencies( ({
    "imperials", "orcteef", "rounds", "chits", "cuicui", "dinar"
  }) );
  SetLocalFee(0);
  SetNonLocalFee(5);
  SetExchangeFee(0.05);
  SetCombatAction(5 , ({
  	"!disorient",
  	"!disarm",
  	}) );
}
