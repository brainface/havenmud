#include <lib.h>
#include <vehicle.h>
#include "../karak.h"
inherit LIB_SHIPSELLER;

static void create() {
  ::create();
  SetKeyName("tuskar");
  SetId( ({ "tuskar", "builder", "orc" }) );
  SetAdjectives( ({ "galley" }) );
  SetShort("Tuskar the Galley Builder");
  SetLong(
    "Tuskar is the galley builder of Karak Varn.  His business "
    "is ships. Selling ships to the orc navy makes him an immense amount "
    "of currency for his family."
  );
  SetRace("orc");
  SetGender("male");
  SetLocalCurrency("orcteef");
  SetWharf(KARAK_ROOM "rd7");
  SetClass("rogue");
  SetMorality(-100);
  SetLevel(30);
  SetLargestShip(VS_GALLEY);
}
