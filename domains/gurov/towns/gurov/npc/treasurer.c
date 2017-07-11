#include <lib.h>
#include <std.h>
#include "../gurov.h"
inherit LIB_TELLER;

static void create() {
  ::create();
  SetTown("Gurov");
  SetBankName("Gurov Treasury");
  SetOpenFee(5);
  SetExchangeFee(5);
  SetLocalFee(5);
  SetNonLocalFee(25);
  SetLocalCurrency("rubles");
  SetShort("Grimble the Treasurer");
  SetId( ({ "treasurer", "grimble", "teller", "banker" }) );
  SetAdjectives( ({ "treasurer", "gurov" }) );
  SetFriends( ({ "guard" }) );
  SetKeyName("grimble");
  SetLong(
    "Grimble the Treasurer runs the treasury like a man possessed. "
    "His intense love of numbers causes many in the Principality to "
    "tremble, and his clenched fist cannot be reckoned with. In his "
    "hands the money of the citizens of Gurov is safe."
    );
  SetAction(3, ({
    "!speak You could <ask> me <for> an <account> in our treasury.",
  }) );
  SetLimit(1);
  SetRace("human");
  SetBaseLanguage("Gurovian");
  SetClass("merchant");
  SetLevel(60);
  SetInventory( ([
    STD_KNIFE "stiletto" : "wield stiletto",
    ]) );
  SetCurrency("rubles", 10 + random(65));
  SetMorality(-50);
  SetGender("male");
}
