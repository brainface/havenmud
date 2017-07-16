//
// Purlad, the bank teller
// Created by Zaxan@Haven
//

#include <lib.h>
#include "../jidoor.h"

inherit LIB_TELLER;

static void create() {
   teller::create();
   SetBankName("Jidoor Bank");
   SetLocalCurrency("rupies");
   SetCurrencies( ({ "rupies", "nuggets", "imperials", "senones",
               "crystals", "roni", "cuicui","rounds", "koken"}) );
   SetLocalFee(0);
   SetTown("Jidoor");
   SetExchangeFee(0.01);
   SetKeyName("purlad");
   SetMorality(10);
   SetShort("Purlad, the bank teller");
   SetId( ({ "purlad","teller" }) );
   SetAdjectives( ({ "bank" }) );
   SetLong("Purlad is the bank teller. She sits behind the counter "
           "all day waiting for customers to serve.");
   SetRace("sprite");
   SetGender("female");
   SetClass("rogue");
   SetLevel(40);
   SetCurrency("rupies",random(500));
}
