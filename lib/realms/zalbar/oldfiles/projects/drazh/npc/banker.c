// by Dahaka
// Aug 2004

#include <lib.h>
#include "../drazh.h"
inherit LIB_TELLER;

static void create() {
  teller::create();
  SetKeyName("rassak");
  SetId( ({"rassak","banker","skaven"}) );
  SetAdjectives( ({ "pedlar" }) );
  SetShort("Rassak the Pedlar");
  SetLong(
     "This rather small skaven with light brown fur is in charge of the "
     "town's bank. He keeps the bank in working order, attending to the "
     "citizens as they come and go. "
     );
  SetInventory( ([
     ]) );
  SetBankName("the Bank of Drazh");
  SetLocalCurrency("roni");
  SetCurrencies( ({
     "imperials",
     "nuggets",
     "orcteef",
     "rupies",
     "skins",
     "roni"
     }) );
  SetLocalFee(0);
  SetNonLocalFee(7);
  SetTown("Drazh");
  SetExchangeFee(0.04);
  SetRace("skaven");
  SetGender("male");
  SetClass("merchant");
  SetLevel(7);
  SetMorality(-500);
  SetCurrency("nuggets",random(100));
  SetAction(5, ({
     "!yawn",
     "!speak Keeping this bank in order can be exhausting.",
   }) );
}
