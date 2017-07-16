#include <lib.h>
#include <vehicle.h>
#include "../keryth.h"
inherit LIB_SHIPSELLER;

static void create() {
  ::create();
  SetKeyName("harold");
  SetShort("Harold the Outfitter of Longships");
  SetId( ({ "harold", "outfitter" }) );
  SetLong("Harold is the Master Shipwright of Keryth.  His business "
          "is the most lucrative in the entire city.  Selling "
          "ships to the viking raiders makes him an immense amount of currency for "
          "his family.");
  SetRace("goden");
  SetGender("male");
  SetLocalCurrency("senones");
  SetWharf(K_ROOM "/wharf");
  SetClass("viking");
  SetMorality(-100);
  SetLevel(30);
  SetLimit(1);
  SetLargestShip(VS_CRUISER);
  SetShipModifier(0.2);
  SetCurrency("senones" ,1 + random(30));
}

int eventNewShip(object who, string thing, string args) {
  if (who->GetNationality() != "Keryth") {
    eventForce("speak I only sell new ships to Keryth natives!");
    return 1;
  }
  return ::eventNewShip(who, thing, args);
}
