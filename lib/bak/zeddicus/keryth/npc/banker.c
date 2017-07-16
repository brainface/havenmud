#include <lib.h>
#include <std.h>
#include "../keryth.h"

inherit LIB_TELLER;

static void create() {
  teller::create();
  SetBankName("Keryth Bank");
  SetLocalCurrency("senones");
  SetCurrencies( ({
    "senones", "imperials", "bloodgems", "chits", "orcteef", "dinar"
  }) );
  SetLocalFee(1);
  SetNonLocalFee(3);
  SetTown("Keryth");
  SetExchangeFee(0.05);
  SetKeyName("rods");
  SetShort("Rods, the Banker of Keryth");
  SetId( ({ "rods", "banker", "teller" }) );
  SetLong("Rods works tirelessly at the Keryth Bank, keeping track of all "
          "all accounts.  He has a tired look and for a Goden, an unusually "
          "large belly.");
  SetRace("goden");
  SetGender("male");
  SetClass("rogue");
  SetMorality(-50);
  SetLevel(15);
  SetCurrency("senones", random(100));
  SetAction(5, ({"!speak What do you need?", "!cough" }) );
  SetInventory( ([
    STD_CLOTHING "pant/drab_pants" : "wear pants",
    STD_CLOTHING "boot/boot" : "wear boots",
    STD_CLOTHING "shirt/tunic" : "wear tunic"
  ]) );
}
