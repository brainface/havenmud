//
// Summary: the bank teller of baria
// Created by Rhakz - Angel Cazares
// For Baria
// Date: 10/17/98
//
#include <lib.h>
#include "../jungle.h"
inherit LIB_TELLER;

static void create() {
  teller::create();
  SetBankName("the Barian Jungle Bank");
  SetLocalCurrency("chits");
  SetCurrencies( ({ "imperials",
                    "crystals",
                    "nuggets",
                    "rupies",
                    "roni",
                    "bloodgems",
                    "orcteef",
                    "skins",
                    "rounds",
  }) );
  SetLocalFee(0);
  SetNonLocalFee(3);
  SetExchangeFee(0.03);
  SetKeyName("Pakal");
  SetShort("Pakal the bank teller");
  SetId( ({ "pakal","pakal the bank teller", "teller","bank "
            "teller", "banker" }) );
  SetLong("Pakal is the person who watches over the money of "
          "the Barians, and also the money of non-barians who "
          "have an account in this bank. He is the twin brother "
          "of Chief Mianin, and Pakal is nearly as strong as him."
         );
  SetRace("human");
  SetGender("male");
  SetClass("fighter");
  SetTown("Baria");
  SetLevel(30);
  SetMorality(75);
  RemoveLanguage("Enlan");
  SetLanguage("Barian", 100, 1);
  SetCurrency("chits", 20 + random(25));
  SetAction(5, ({
                 "!say My brother is taking good care of Baria.",
                 "!emote starts counting some coins.",
                 "!say Your money is safe with me."
             }) );
}

