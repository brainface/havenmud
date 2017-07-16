#include <lib.h>
#include <vehicle.h>
#include "../gurov.h"
inherit LIB_SHIPSELLER;

static void create() {
  ::create();
  SetKeyName("nevsky");
  SetShort("Nevsky the Reknowned Shipwright");
  SetId( ({ "nevsky", "shipwright" }) );
  SetAdjectives( ({ "reknowned" }) );
  SetLong("Nevsky is the Master Shipwright of Gurov.  His business "
          "is the most lucrative in the entire Principality.  Selling "
          "ships to the Prince makes him an immense amount of currency for "
          "his family.");
  SetRace("human");
  SetBaseLanguage("Gurovian");
  SetGender("male");
  SetLocalCurrency("rubles");
  SetWharf(GUROV_ROOM "bay4");
  SetClass("sailor");
  SetMorality(100);
  SetLevel(30);
  SetLimit(1);
  SetLargestShield(VSH_SMALL);
  SetLargestShip(VS_CRUISER);
}
