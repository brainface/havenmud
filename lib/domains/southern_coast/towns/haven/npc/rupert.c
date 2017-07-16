#include <lib.h>
#include "../haven.h"
inherit LIB_BARKEEP;

static void create() {
  barkeep::create();
  SetKeyName("rupert");
  SetShort("Rupert Avery, the owner of the inn");
  SetRace("elf");
  SetClass("rogue");
  SetLevel(9);
  SetMorality(15);
  SetId( ({ "owner", "rupert", "avery", "rupert avery" }) );
  SetGender("male");
  SetLong("Rupert Avery is the youngest son of the prestigious Avery \n"
          "family. His inn has been in business nearly sixty years.");
  SetLocalCurrency("imperials");
  SetMenuItems( ([
    "stew" : H_OBJ + "stew",
  ]) );
}
