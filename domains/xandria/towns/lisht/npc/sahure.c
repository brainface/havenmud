//Selket@Haven
//2006
#include <lib.h>
#include "haven.h"
inherit LIB_TELLER;

static void create() {
  teller::create();
  SetBankName("Bank of Lisht");

  SetLocalCurrency("deben");
  SetLocalFee(0);
  SetNonLocalFee(1);
  SetTown("Lisht");
  SetExchangeFee(0.01);
  SetKeyName("Sahure");
  SetShort("Sahure the Respected");
  SetId( ({ "sahure", "teller", "banker" }) );
  SetAdjectives( ({ "respected" }) );
  SetLong("Sahure is the teller of the bank here, and although "
          "he alone guards the riches of the city, his hulking "
          "body shows that he fares quite easily against thieves "
          "or anyone at all. His dark eyes glint as though they "
          "are flecked with gold.");
  SetRace("gnoll");
  SetGender("male");
  SetClass("rogue");
  SetLevel(10);
  SetCurrency("deben",random(20));
  SetBaseLanguage("Rehshai");
  SetAction(5, ({
    "!speak The careful hand of Selket counts souls as we count "
    "small change.",
    "!emote casts his watchful eyes upon you.",
     }) );
  }
