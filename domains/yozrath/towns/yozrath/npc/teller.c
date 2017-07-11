#include <lib.h>
#include "../yozrath.h"
inherit LIB_TELLER;

static void create() {
  ::create();
  SetKeyName("azim");
  SetShort("Azim the Humble");
  SetId( ({ "azim", "banker", "teller" }) );
  SetAdjectives( ({ "humble" }) );
  SetLong("Azim is the local moneychanger and banker.  He would be happy to assist you.");
  SetGender("male");
  SetClass("rogue");
  SetRace("human");
  SetBaseLanguage("Padashi");
  SetLevel(50);
  SetAction(5, ({
    "!yell I can convert your foreign coins!",
    "!yell Trade for Dinar here!",
    "!say Do you have an account?",
    "!say You can <request> an account.",
  }) );
  SetInventory( ([
    YOZRATH_OBJ "thobe" : "wear thobe",
  ]) );
  SetMorality(-600);
  SetCurrency("dinar", 500);
  SetBankName("Yozrath Trust");
  SetTown("Yozrath");
  SetLocalCurrency("dinar");
  SetLimit(1);
}
