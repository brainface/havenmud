
#include <lib.h>
#include "../durgoroth.h"
inherit LIB_TELLER;

static void create() {
  teller::create();
  SetBankName("Durgoroth Bank");
  SetLocalCurrency("crystals");
  SetLocalFee(0);
  SetNonLocalFee(2);
  SetTown("Durgoroth");
  SetExchangeFee(0.01);
  SetKeyName("balishae");
  SetShort("Balishae the hoarder of crystals");
  SetId( ({ "balishae", "hoarder", "teller", "banker" }) );
  SetLong(
    "Balishae is an ugly daemon with deep scars all"
    " over his body. He has taken great measures"
    " to ensure the safety of his collections and"
    " has fitted the store with many protections to"
    " quell the savage rage and the sticky finger."
  );
  SetRace("daemon");
  SetGender("male");
  SetClass("merchant");
  SetSkill("melee combat",1,1);
  SetLevel(200);
}


