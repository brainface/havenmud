// mahkefel 2017
// a wagon seller for the southern coast.
#include <lib.h>
#include <std.h>
#include <domains.h>
inherit LIB_WAGONSELLER;

static void create() {
  ::create();
  SetKeyName("vesta");
  SetShort("Vesta the Caravaneer");
  SetId( ({ "vesta", "caravaneer" }) );
  SetAdjectives( ({ "vesta the" }) );
  SetLong(
  "An ambitious young trader, Vesta took control of Sanctum's caravans after "
  "the former head caravanner was lost to bandits somewhere deep in the "
  "Yozrath. Seldom spoke rumors describe his fate as a little too convenient "
  "for Vesta's rise."
  );
  SetRace("human");
  SetGender("female");
  SetLocalCurrency("imperials");
  SetClass("merchant");
  SetMorality(0);
  SetLevel(15);
  SetLimit(1);
  SetTown("Sanctum");

  AddStableItem("wagon", STD_VEHICLES "wagon");
  AddStableItem("caravan", STD_VEHICLES "caravan");
}

