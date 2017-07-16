#include <lib.h>
#include "../glim.h"

inherit LIB_SAGE;

static void create() {
  sage::create();
  SetKeyName("Dorscha");
  SetShort("Dorscha, Minister of Foreign Influence");
  SetId( ({ "dorscha", "minister", "dwarf"}) );
  SetAdjectives( ({}) );
  SetLong("Dorscha is one of the few remaining dwarves from before "
    "the Kylin church's founding in Glistendin. She looks quite old, "
    "and is here to help one adjust to the dwarven city.");
  SetGender("female");
  SetRace("dwarf");
  SetClass("bard");
  SetLevel(15);
  SetLocalCurrency("glims");
  SetCharge(20);
  
  SetMorality(-50);
  SetLanguage("Eltherian", 100);
  SetLanguage("Averish", 100);
}
