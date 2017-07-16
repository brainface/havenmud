#include <lib.h>
#include <vehicle.h>
#include "../gwonish.h"
inherit LIB_SHIPSELLER;

static void create() {
  ::create();
  SetKeyName("siziji");
  SetShort("Siziji the Canoe Maker");
  SetId( ({ "siziji","maker" }) );
  SetAdjectives( ({"sisiz","the","canoe","maker" }) );
  SetLong(
    "This blue-scaled lizardwoman is an expert in the "
    "arduous process of crafting canoes. Her dexterous "
    "clawed fingers work ceaselessly with the thin bark "
    "sheets that will one day be sea worthy vessels."
    );
  SetRace("lizardman");
  SetGender("female");
  SetLocalCurrency("rounds");
  SetWharf(GWONISH_ROOM "gw01");
  SetClass("merchant");
  SetMorality(-100);
  SetLevel(15);
  SetLimit(1);
  SetLargestShield(0);
  SetLargestShip(VS_YACHT);
  SetLargestWeapon(VW_SMALL);
}

