#include <lib.h>
#include "../rome.h"
inherit LIB_HEALER;

static void create() {
  ::create();
  SetKeyName("paulus");
  SetShort("Paulus Evengale, Healer of Sanctum");
  SetId( ({ "paulus", "evengale", "healer" }) );
  SetAdjectives( ({ "paulus", "healer" }) );
  SetRace("human");
  RemoveLanguage("Enlan");
  SetLanguage("Imperial", 100, 1);
  SetClass("priest");
  SetTown("Sanctum");
  SetGender("male");
  SetLevel(4);
  SetCurrency("imperials", 10);
  SetMorality(100);
  SetLong("Paulus Evengale is the local healer.  His abilities range "
          "from both the mundane healing of minor wounds to the full "
          "resurrection of the dead. Of course, he reserves the right "
          "to be richly compensated for his services.");
  SetLocalCurrency("imperials");
  SetFees( ([
    "resurrect" : 15,
    "stamina" : 1,
    "health" : 3,
    "restore" : 6,
    ]) );
  SetLimit(1);
  SetInventory( ([
    ROME_OBJ "toga_evil" : "wear toga",
  ]) );
}
