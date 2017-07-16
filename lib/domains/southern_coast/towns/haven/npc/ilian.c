#include <lib.h>
#include "haven.h"
inherit LIB_TELLER;

static void create() {
  teller::create();
  SetBankName("Haven Bank");
  SetLocalCurrency("imperials");
  SetCurrencies( ({
 		"imperials", 
 		"nuggets", 
 		"dinar", 
 		"chits",
    }) );
  SetLocalFee(0);
  SetNonLocalFee(2);
  SetTown("Haven");
  SetExchangeFee(0.01);
  SetKeyName("ilian");
  SetShort("Ilian, the mistress of the bank");
  SetId( ({ "ilian","mistress", "teller", "banker" }) );
  SetLong("Ilian is the mistress of the Haven Bank.  Her \n"
          "financial wizardry is world reknowned for its \n"
          "creativity and excellence.");
  SetRace("elf");
  SetGender("female");
  SetClass("rogue");
  SetLevel(6);
  SetCurrency("imperials",random(10)+1);
  SetMorality(100);
  SetAction(5, ({
    "!speak Glory be to the Lord of Balance, his church has forgiven "
    "me my debts.",
     }) );
  }
