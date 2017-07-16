#include <lib.h>
#include "../ruins.h"
inherit LIB_HEALER;

static void create() {
  ::create();
  SetKeyName("elana");
  SetShort("Elana the Healer");
  SetId( ({ "elana", "healer" }) );
  SetAdjectives( ({  }) );
  SetRace("human");
  SetBaseLanguage("Koblich");
  SetGender("female");
  SetClass("rogue");
  SetLevel(4);
  SetCurrency("senones", 10);
  SetMorality(100);
  SetLong("Elana is the local healer.  Her abilities range "
          "from both the mundane healing of minor wounds to the full "
          "resurrection of the dead. Of course, she reserves the right "
          "to be richly compensated for her services.");
  SetLocalCurrency("senones");
  SetFees( ([
    "resurrect" : 2,
    "stamina" : 1,
    "health" : 3,
    "restore" : 6,
    ]) );
  SetTown("Arcanith");
  SetLimit(1);
}
