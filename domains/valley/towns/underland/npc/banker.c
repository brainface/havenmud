#include <lib.h>
inherit LIB_TELLER;

static void create() {
  ::create();
  SetKeyName("jaypee");
  SetRace("gnome");
  SetTown("Underland");
  SetBankName("Underland Mint");
  SetGender("male");
  SetShort("JayPee Murgen the Banker");
  SetId( ({ "banker", "gnome", "jaypee", "murgen", "teller" }) );
  SetAdjectives( ({ "jaypee" }) );
  SetLong(
    "JayPee Murgen is the chief financier here in the Underland. His control "
    "over the currency market is undisputed. Those having business with the "
    "banker should <greet> him."
    );
  SetClass("merchant");
  SetLevel(20);
}
