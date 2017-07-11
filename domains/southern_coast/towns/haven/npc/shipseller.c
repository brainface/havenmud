#include <lib.h>
#include <vehicle.h>
#include "../haven.h"
inherit LIB_SHIPSELLER;

static void create() {
  ::create();
  SetKeyName("aruthan");
  SetShort("Aruthan the Crafter of Vessels");
  SetId( ({ "aruthan", "crafter" }) );
  SetAdjectives( ({ }) );
  SetLong(
    "Aruthan is the Crafter of Vessels for the Elves.  His elegant ships are "
    "a sight that can be easily recognized for leagues at sea. His work is "
    "without equal."
    );
  SetRace("elf");
  SetGender("male");
  SetLocalCurrency("imperials");
  SetWharf(H_ROOM "wharf");
  SetClass("merchant");
  SetMorality(750);
  SetLevel(30);
  SetLimit(1);
  SetLargestShield(VSH_LARGE);
  SetLargestShip(VS_DREADNAUGHT);
  SetLargestWeapon(VW_DEVASTATING);
}
