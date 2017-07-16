#include <lib.h>
#include "../karak.h"
inherit LIB_TELLER;

static void create() {
  teller::create();
  SetBankName("Karak Varn Treasury");
  SetLocalCurrency("orcteef");
  SetCurrencies( ({ "imperials", "tiras", "rupies", "orcteef", "marks" }) );
  SetLocalFee(0);
  SetNonLocalFee(1);
  SetTown("Karak");
  SetExchangeFee(0.01);
  SetKeyName("kurgan");
  SetShort("Kurgan, Officer of the Bank");
  SetId( ({ "kurgan", "officer", "teller" }) );
  SetLong("This massive orc looks like he would be more at home on a "
          "blood soaked battlefield than in this small bank.  He looks "
          "really mean and un-neighborly.");
  SetRace("orc");
  SetGender("male");
  SetClass("rogue");
  SetLevel(25 + random(7));
  SetCurrency("orcteef", random(70));
  SetInventory( ([ K_OBJ + "/haxe" : "wield axe" ]) );
}
