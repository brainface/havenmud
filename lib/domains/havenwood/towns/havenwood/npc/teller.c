#include <lib.h>
#include "../wood.h"
inherit LIB_TELLER;

static void create() {
  teller::create();
  SetBankName("Havenwood Bank");
  SetLocalCurrency("imperials");
  SetLocalFee(0);
  SetNonLocalFee(2);
  SetTown("Havenwood");
  SetExchangeFee(0.01);
  SetKeyName("naili");
  SetShort("Naili the Mistress of Coin");
  SetId( ({ "naili", "mistress", "teller", "banker" }) );
  SetLong(
    "Naili is a distant relation to Ilian in Haven Town. "
  );
  SetRace("wild-elf");
  SetGender("female");
  SetClass("merchant");
  SetLevel(6);
  SetCurrency("imperials",random(10));
  SetAction(5, ({
     }) );
  }
