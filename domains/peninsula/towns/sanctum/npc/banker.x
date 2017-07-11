#include <lib.h>
#include "../rome.h"
inherit LIB_TELLER;

static void create() {
  ::create();
  SetKeyName("althus");
  SetLimit(1);
  SetShort("Althus, Moneychanger and Banker of Sanctum");
  SetId( ({ "althus", "banker", "moneychanger" }) );
  SetRace("human");
  SetClass("merchant");
  RemoveLanguage("Enlan");
  SetLanguage("Imperial", 100, 1);
  SetLevel(12);
  SetGender("male");
  SetLong("Althus is a large and portly man of advancing years. "
          "His girth is measured only by his wealth, as he is "
          "without doubt one of the wealthiest persons in Sanctum.");
  SetInventory( ([
    ]) );
  SetCurrency("imperials", 25);
  SetLocalCurrency("imperials");
  SetBankName("Sanctum Moneychanger");
  SetTown("Sanctum");
  SetLocalFee(0);
  SetNonLocalFee(2);
  SetCurrencies( ({ "imperials" }) );
  SetMorality(-100);
  SetAction(5, ({
    "!speak How can I assist you today?",
    "!speak Perhaps you would like to open an account with me?",
    "!speak You should invest your money safely with me!",
    }) );
}
