#include <lib.h>
#include "../grymxoria.h"
inherit LIB_TELLER;

static void create()
{
  teller::create();
  SetShort("Rakkar, the Grymxoria Bank Teller");
  SetId( ({ "nosferatu", "rakkar", "teller" }) );
  SetLong(
    "Rakkar is shorter than the average nosferatu. He makes "
    "up for this by ruthless control over the value of the "
    "bloodgem, the Grymxorian currency. One word from Rakkar "
    "can ruin the credit of anyone in the city."
  );
  SetRace("nosferatu");
  SetGender("male");
  SetClass("merchant");
  SetLevel(7);
  SetCurrency("bloodgems", random(3000));
  SetBankName("Grymxoria Bank");
  SetLocalCurrency("bloodgems");
  SetCurrencies( ({
    "imperials",
    "bloodgems",
  }) );
  SetLocalFee(0);
  SetNonLocalFee(2);
  SetTown("Grymxoria");
  SetExchangeFee(0.01);
  SetKeyName("rakkar");
  SetAction(5, ({
    "!speak War is coming.",
    "!speak Seek the temple in the mines.",
    "!speak The Nosferatu shall conquer over all.",
  }) );
}
