#include <lib.h>
#include "../grymxoria.h"
inherit LIB_TELLER;

static void create()
{
  teller::create();
  SetKeyName("rakkar");
  SetShort("rakkar, the Grymxoria Bank Teller");
  SetId( ({ "nosferatu", "rakkar", "teller", "banker" }) );
  SetLong(
    "Rakkar is shorter than the average nosferatu. He makes "
    "up for this by ruthless control over the value of the "
    "bloodgem, the Grymxorian currency. One word from Rakkar "
    "can ruin the credit of anyone in the city."
  );
  SetClass("merchant");
  SetLevel(50);
  SetRace("nosferatu");
  SetGender("male");
  SetMorality(-2000);  
  SetCurrency("bloodgems", random(3000));
  SetAction(5, ({
    "!speak War is coming.",
    "!speak Seek the temple in the mines.",
    "!speak The Nosferatu shall conquer over all.",
  }) );
  SetBankName("Grymxoria Bank");
  SetLocalCurrency("bloodgems");
  SetCurrencies(  ({
    "imperials",
    "bloodgems",
  }) );
  SetLocalFee(0);
  SetNonLocalFee(2);
  SetTown("Grymxoria");
  SetExchangeFee(0.01);
}
