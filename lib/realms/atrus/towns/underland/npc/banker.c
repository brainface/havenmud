#include <lib.h>
inherit LIB_TELLER;

static void create() {
  ::create();
  SetKeyName("rupert");
  SetRace("gnome");
  SetTown("Underland");
  SetBankName("Floeholm Capital");
  SetGender("male");
  SetShort("Rupert Spinthrift the Banker");
  SetId( ({ "banker", "gnome", "rupert", "spinthrift" }) );
  SetAdjectives( ({ "jaypee" }) );
  SetLong(
    "Rupert Spinthrift is the branch general manager of The Capital bank of Floeholm. "
    "His demeaner is proper and dignified while his eyes hint at a silent greed. "
    "Those having business with the banker should <greet> him."
    );
  SetClass("merchant");
  SetLevel(20+random(8));
}
