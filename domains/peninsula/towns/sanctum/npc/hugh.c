#include <lib.h>
#include "../rome.h"
inherit LIB_SHIPSELLER;
#include <vehicle.h>

static void create() {
  ::create();
  SetKeyName("Hugh");
  SetShort("Hugh the Crafter of the Free Sanctum Fleet");
  AddAlcohol(750);
  SetId( ({ "Hugh" }) );
  SetAdjectives( ({ "crafter", "of the free sanctum fleet" }) );
  SetRace("human");
  SetGender("male");
  SetMorality(50);
  SetClass("merchant");
  SetLevel(90);
  SetLong(
    "Hugh is the crafter of the Sanctum Fleet. His skill in ship making is the "
    "best on the peninsula. His ships are well known to those even not born in "
    "Sanctum."
    );
  SetInventory( ([
    ]) );
  SetAction(5, ({
        "!speak Yes, I can sell even you a fine sailing vessel!",
        "!speak Buy a special made ship today for a low price!",
  }) );
  SetLimit(1);
  SetTown("Sanctum");
  RemoveLanguage("Enlan");
  SetLanguage("Imperial", 100, 1);
  SetWharf(ROME_ROOM "docks");
  SetLargestShield(VSH_LARGE);
  SetLargestShip(VS_DREADNAUGHT);
  SetLargestWeapon(VW_DEVASTATING);
}
