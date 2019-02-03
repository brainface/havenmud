#include <lib.h>
#include <vehicle.h>
#include "../dalnairn.h"
inherit LIB_SHIPSELLER;

static void create() {
  ::create();
  SetKeyName("harold");
  SetShort("Stromgud the Outfitter of Ships");
  SetId( ({ "stromgud", "outfitter" }) );
  SetLong("Stromgud is the Master Shipwright of Dalnairn. His business "
          "is the most lucrative in the entire city. Selling "
          "ships makes him an immense amount of currency for "
          "his family. He is a proud dark-dwarf with a flowing "
          "blonde beard. ",
  );
  SetRace("dark-dwarf");
  SetGender("male");
  SetLocalCurrency("shards");
  SetWharf(DAL_ROOM "1,0");
  SetClass("viking");
  SetMorality(0);
  SetLevel(random(20) + 100);
  SetLimit(1);
  SetLargestShield(VSH_LARGE);
  SetLargestShip(VS_DREADNAUGHT);
  SetLargestWeapon(VW_DEVASTATING);
  SetShipModifier(0.1);
  SetCurrency("shards", 1000 + random(30));
  SetInventory( ([
    DAL_OBJ + "guardarmour": "wear my suit",
    DAL_OBJ + "sword" : "wield my sword",
    DAL_OBJ + "boots" : "wear my boots",
  ]) );
}

int eventNewShip(object who, string thing, string args) {
  if (who->GetNationality() != "Dalnairn") {
    eventForce("speak I only sell new ships to Dalnairn natives!");
    return 1;
  }
  return ::eventNewShip(who, thing, args);
}
