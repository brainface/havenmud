#include <lib.h>
#include <vehicle.h>
#include "../argoth.h"
inherit LIB_SHIPSELLER;

static void create() {
  ::create();
  SetKeyName("tuskar");
  SetShort("Tuskar the Galley Builder");
  SetId( ({ "tuskar", "builder" }) );
  SetAdjectives( ({ "galley" }) );
  SetLong("Tuskar is the Master Shipwright of Gurov.  His business "
          "is ships.  Selling "
          "ships to the orc navy makes him an immense amount of currency for "
          "his family.");
  SetRace("orc");
  SetGender("male");
  SetLocalCurrency("khuca");
  SetWharf(ARGOTH_ROOM "rd8");
  SetClass("rogue");
  SetMorality(100);
  SetLevel(30);
/*
  SetLimit(1);
*/
  SetLargestShip(VS_GALLEY);
}
