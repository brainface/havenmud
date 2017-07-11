// Coded by Zeratul
// 3-18-2000

#include <lib.h>
#include "../vacazar.h"
inherit LIB_TELLER;

static void create() {
  teller::create();
  SetKeyName("vegor");
  SetId( ({"vegor","banker","teller"}) );
  SetAdjectives( ({ "banker" }) );
  SetShort("Vegor the bank teller");
  SetLong(
     "This rather small skaven is in charge of the city's bank. He keeps the "
     "bank in working order, attending to the citizens as they come and go. "
  );
  SetInventory( ([
  ]) );
  SetBankName("Vacazar Bank");
  SetLocalCurrency("vacari");
  SetCurrencies( ({
  "imperials","koken","roni","rupies",
  }) );
  SetLocalFee(0);
  SetNonLocalFee(3);
  SetTown("Vacazar");
  SetExchangeFee(0.02);
  SetRace("skaven");
  SetGender("male");
  SetClass("merchant");
  SetLevel(7);
  SetCurrency("vacari",random(100));
  SetAction(5, ({
     "!yawn",
     "!speak Keeping this bank in order can be exhausting.",
  }) );
  }
