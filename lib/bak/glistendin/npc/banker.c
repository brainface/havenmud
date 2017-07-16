// Duhoc 99
// this is the banker

#include <lib.h>
#include "../glim.h"
inherit LIB_TELLER;

static void create() {
  teller::create();
  SetBankName("Glistendin Bank");
  SetLocalCurrency("glims");
  SetCurrencies( ({
      "ducats", "glims", 
      }) );
  SetLocalFee(0);
  SetNonLocalFee(1);
  SetTown("Glistendin");
  SetExchangeFee(0.01);
  SetKeyName("banker");
  SetShort("a dwarven banker");
  SetId( ({ "banker", "dwarf", "teller" }) );
  SetLong("This is the dwarven banker who runs "
    "Glistendin's bank. He seems rather bored with "
    "his peaceful job.");
  SetRace("dwarf");
  SetGender("male");
  SetClass("merchant");
  SetLevel(15);
  SetCurrency("glims", random(5));
  SetAction(1, ({
    "The banker stares at the wall.",
    "The banker yawns.",
    "The banker taps his foot impatiently.",
     }) );
}
