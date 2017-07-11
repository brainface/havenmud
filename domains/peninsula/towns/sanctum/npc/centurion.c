#include <lib.h>
#include "../rome.h"
inherit LIB_TOWNGUARD;

static void create() {
  ::create();
  SetKeyName("centurion");
  SetRace("human");
  SetTown("Sanctum");
  RemoveLanguage("Enlan");
  SetLanguage("Imperial", 100, 1);
  SetGender("male");
  SetClass("fighter");
  SetLevel(15);
  SetCurrency("imperials", 100);
  SetInventory( ([
    ROME_OBJ "bsword" : "wield sword",
    ]) );
  SetShort("a Sanctum centurion");
  SetId( ({ "centurion", "wander" }) );
  SetAdjectives( ({ "sanctum" }) );
  SetLong("This staunch defender of the Imperial City has a fierce "
          "look and hardened visage that strikes fear into the hearts "
          "of the barbarian tribes and civilized nations both.");
  SetWander(1);
  SetLimit(6);
}
