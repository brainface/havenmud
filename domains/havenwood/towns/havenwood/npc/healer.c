#include <lib.h>
#include "../wood.h"
inherit LIB_HEALER;

static void create() {
  ::create();
  SetKeyName("Pylora the Healer");
  SetShort("Pylora the Healer");
  SetId( ({ "pylora", "mendicant", "healer" }) );
  SetAdjectives( ({ "pylora", "healer" }) );
  SetRace("wild-elf");
  SetGender("female");
  SetClass("priest");
  SetStat("wisdom", 10000, 1);
  SetMorality(100);
  SetLong("Pylora is the local healer.  Her abilities range "
          "from both the mundane healing of minor wounds to the full "
          "resurrection of the dead. Of course, she reserves the right "
          "to be richly compensated for her services.");
   SetLevel(40);
  SetCurrency("imperials", 10);
  SetLocalCurrency("imperials");
  SetFees( ([
    "resurrect" : 15,
    "stamina" : 1,
    "health" : 3,
    "restore" : 6,
    ]) );
  SetTown("Havenwood");
  SetLimit(1);
}
