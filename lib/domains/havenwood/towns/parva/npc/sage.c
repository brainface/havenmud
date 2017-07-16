#include <lib.h>
#include <std.h>
inherit LIB_SAGE;

static void create() {
  ::create();
  SetKeyName("Dumo");
  SetRace("human");
  SetGender("male");
  SetClass("rogue");
  SetLevel(15);
  SetMorality(-100);
  SetInventory( ([
    STD_KNIFE + "/stiletto" : "wield stiletto",
    ]) );
  SetShort("Dumo el Doro the Sage of Parva");
  SetId( ({ "dumo", "doro", "sage" }) );
  SetAdjectives( ({ "dumo", "el" }) );
  SetLong("Dumo is a well travelled man in his later years. "
          "He is fluent in several languages, and will happily "
          "teach them to anyone who asks. He has an enormous greying beard, "
          "which keeps his chest warm during the cold Parvan winters.");
  SetTaughtLanguages( ({ "Enlan", "Eltherian", "Blaodric", "Tai", "Gurovian" }) );
  SetTown("Parva");
  SetLocalCurrency("oros");
  SetCharge(500);
}
