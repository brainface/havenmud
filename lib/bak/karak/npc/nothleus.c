#include <lib.h>
#include "../karak.h"
inherit LIB_HEALER;

static void create() {
  healer::create();
  SetKeyName("nothleus");
  SetTown("Karak");
  SetGender("female");
  SetLong("This is a local healer.  Her calm appearance is one \n"
          "that suggests she could help anyone if paid well enough.");
  SetShort("Nothleus the healer");
  SetRace("orc");
  SetId( ({ "nothleus", "healer" }) );
  SetReligion("Saahagoth", "Saahagoth");
  SetClass("cleric");
  SetLevel(10);
  SetCurrency("orcteef",random(10));
  SetLocalCurrency("orcteef");
  SetFees( ([
    "resurrect" : 15,
    "stamina" : 1,
    "health" : 3,
    "restore" : 6,
    ]) );
}


/* Approved by Balishae on Thu Sep 18 14:11:17 1997. */
