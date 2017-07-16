#include <lib.h>
#include "../goblins.h"
inherit LIB_TELLER;

static void create() {
  teller::create();
  SetBankName("Tugrik's Pouch");
  SetLocalCurrency("rounds");
  SetLocalFee(2);
  SetLimit(1);
  SetNonLocalFee(2);
  SetTown("Kresh");
  SetExchangeFee(0.2);
  SetKeyName("tugrik");
  SetShort("Tugrik the Coin Counter");
  SetId( ({ "tugrik", "counter", "banker", "teller" }) );
  SetLong(
    "Tugrik is the Coin Counter here in the Goblin Village.  His wisdom is famed as far "
    "as he can be thrown, and none doubt the honesty and knowledge of mathematical genius "
    "that is Goblin High Finance!"
    );
  SetRace("goblin");
  SetGender("male");
  SetClass("rogue");
  SetLevel(15);
  SetCurrency("rounds",random(10)+1);
  SetMorality(-100);
  SetAction(5, ({
    "!speak One and one and one and one.... two?",
    "!speak One for you and one for me and two for you and two for me...",
     }) );
  }
