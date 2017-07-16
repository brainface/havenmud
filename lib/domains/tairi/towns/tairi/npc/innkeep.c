/* The innkeeper */
#include <lib.h>
#include "../tairi.h"
inherit LIB_BARKEEP;

static void create() {
  ::create();
  SetKeyName("lin");
  SetShort("Mi Lin, the local innkeeper");
  SetId( ({ "mi", "lin", "innkeeper", "citizen" }) );
  SetAdjectives( ({ "local" }) );
  SetGender("male");
  SetRace("human");
  SetClass("merchant");
  SetLevel(6);
  RemoveLanguage("Enlan");
  SetLanguage("Tai", 100, 1);
  SetLong("Mi Lin is the local innkeeper.  His demeanor is gruff, but "
          "the food he sells is filling and has flavor worthy of "
          "his proud clan.");
  SetTown("Tairi");
  SetLocalCurrency("koken");
  SetMenuItems( ([
      "saki" : TAI_RI_OBJ "saki",
      "rice" : TAI_RI_OBJ "riceball",
    ]) );
}
