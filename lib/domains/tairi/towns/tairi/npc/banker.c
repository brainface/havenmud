/* The local banker, another Acoma */
#include <lib.h>
#include "../tairi.h"
inherit LIB_TELLER;

static void create() {
  ::create();
  SetKeyName("hailyn");
  SetShort("Acoma Hailyn, moneychanger of Tairi");
  SetId( ({ "hailyn", "acoma", "moneychanger", "citizen", "teller", "banker" }) );
  SetAdjectives( ({ "acoma" }) );
  SetGender("female");
  SetClass("merchant");
  SetLevel(12);
  SetTown("Tairi");
  SetCurrencies( ({ "imperials", "bloodgems", "koken", "nuggets", "roni" }) );
  SetCurrency("koken", random(100) );
  SetMorality(150);
  SetRace("human");
  RemoveLanguage("Enlan");
  SetLanguage("Tai", 100, 1);
  SetLong("Acoma Hailyn is the moneychanger of Tairi. "
          "Her clan is renown for their merchanting abilities, and "
          "she is as gifted as the others. "
          "She will accept deposit accounts, and offers to exchange "
          "currency for most people.");
  SetBankName("Tai MoneyChanger");
  SetLocalCurrency("koken");
  SetNonLocalFee(15);
  SetExchangeFee(0.01);
  SetOpenFee(10);
}
