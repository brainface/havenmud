/* Langauge teacher for Tairi */
#include <lib.h>
#include "../tairi.h"
inherit LIB_SAGE;

static void create() {
  ::create();
  SetKeyName("lio");
  SetShort("Biao Lio, a sage of Tairi");
  SetRace("human");
  RemoveLanguage("Enlan");
  SetLanguage("Tai", 100, 1);
  SetTaughtLanguages( ({ "Tai", "Gurovian", }) );
  SetTown("Tairi");
  SetGender("male");
  SetClass("merchant");
  SetLevel(3);
  SetCurrency("koken", random(30));
  SetMorality(50);
  SetId( ({ "lio", "biao", "sage", "citizen" }) );
  SetAdjectives( ({ "biao" }) );
  SetLong("Biao Lio is an old man, well respected in the lands of the "
          "Tai. His knowledge of the Tai language is remarkable, and "
          "his willingness to share his knowledge is beyond the kind.");
  SetLocalCurrency("koken");
  SetCharge(500);
}
