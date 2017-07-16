/* Bic the teller
 * Ranquest@Haven
 * 02/11/99
 */

#include <lib.h>
#include "../ungkh.h"
inherit LIB_TELLER;

static void create() {
  teller::create();
  SetBankName("Ungkh Bank");
  SetLocalCurrency("skins");
  SetCurrencies( ({
      "imperials","cuicui","bloodgems","chits","roni","senones",
      "skins","nuggets","rupies","crystals","shrydes","dinar"
      }) );
  SetLocalFee(1);
  SetNonLocalFee(2);
  SetTown("Ungkh");
  SetExchangeFee(0.02);
  SetKeyName("bic");
  SetShort("bic the dealer");
  SetId( ({ "bic","dealer", "teller","citizen" }) );
  SetLong(
    "Bic is one of those goblins who have found a niche;"
    " somewhere warm and dry, where they can make money."
    " Bic soon found that, with a little capital, he could"
    " quite easily make money with a minimum of risk."
    " The goblin is small, with a look of cunning stupidity"
    " in his eyes.");
  SetRace("goblin");
  RemoveLanguage("Gobyshkin");
  SetLanguage("Uruk",100,1);
  SetGender("male");
  SetClass("merchant");
  SetLevel(16);
  SetCurrency("skins",random(100));
  SetAction(5, ({
    "!exclaim Cheap Rates!",
    "!say I can exchange your money for any currency in the"
      " world.",
     }) );
  SetCombatAction(4, ({
    "!go out",
    "!yell help",
    "!exclaim he's attacking me!",
    }) );
  SetFriends( ({"goblin"}) );
  }
