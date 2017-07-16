#include <lib.h>
#include <std.h>
#include "../ruins.h"

inherit LIB_TELLER;

static void create() {
  teller::create();
  SetBankName("Arcanith");
  SetLocalCurrency("senones");
  SetLocalFee(1);
  SetNonLocalFee(3);
  // mahkefel 2014: removed. she now acts as aracanith.
  //SetTown("Keryth");
  SetExchangeFee(0.05);
  SetKeyName("lotai");
  SetShort("Lotai, the Currency Specialist");
  SetId( ({ "lotai", "specialist", "banker", "teller" }) );
  SetAdjectives( ({ "currency" }) );
  SetLong(
    "Lotai is Presmyr's wife and mother of his young. She chooses to "
    "remain in Arcanith with her husband, doing some minor currency "
    "functions for the locals."
    );
  SetRace("goden");
  SetBaseLanguage("Koblich");
  SetGender("female");
  SetClass("rogue");
  SetMorality(-50);
  SetLevel(15);
  SetCurrency("senones", random(100));
  SetLimit(1);
  SetAction(2, ({
    "!speak Do you have coins you need exchanged?",
    "!say I could hold on to your money and keep it safe.",
     }) );
  SetInventory( ([
    STD_CLOTHING "pant/drab_med" : "wear pants",
    STD_CLOTHING "boot/boot"       : "wear boots",
    STD_CLOTHING "shirt/tunic_med"     : "wear tunic"
  ]) );
  SetFirstCommands( ({ "follow presmyr" }) );
}

