#include <lib.h>
#include "../gurov.h"
inherit LIB_HEALER;

static void create() {
  ::create();
  SetKeyName("yevgenni");
  SetShort("Yevgenni the Healer");
  SetId( ({ "yevgenni", "healer" }) );
  SetAdjectives( ({  }) );
  SetRace("human");
  SetBaseLanguage("Gurovian");
  SetGender("male");
  SetClass("priest");
  SetLevel(4);
  SetCurrency("rubles", 10);
  SetMorality(100);
  SetLong("Yevgenni is the local healer.  His abilities range "
          "from both the mundane healing of minor wounds to the full "
          "resurrection of the dead. Of course, he reserves the right "
          "to be richly compensated for his services.");
  SetLocalCurrency("rubles");
  SetFees( ([
    "resurrect" : 5,
    "stamina" : 1,
    "health" : 3,
    "restore" : 6,
    ]) );
  SetTown("Gurov");
  SetLimit(1);
}
