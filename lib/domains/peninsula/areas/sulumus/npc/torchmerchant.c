// Proximo@Via Imperialis
// 06/02/2003

#include <lib.h>
#include <std.h>
#include <vendor_types.h>
#include "../sulumus.h"

inherit LIB_BARKEEP;

static void create() {
  barkeep::create();
  SetKeyName("merchant");
  SetId( ({ "merchant" }) );
  SetAdjectives( ({ "a", "short", "portly" }) );
  SetShort("a short portly merchant");
  SetClass("merchant");
  SetLong(
     "This short and very round merchant is the supplier of exploration "
     "supplies. He seems like a reasonable, laid back man. "
  );
  SetLimit(1);
  SetRace("human"); SetBaseLanguage("Imperial");
  SetGender("male");
  RemoveLanguage("Human");
  SetLanguage("Imperial", 100, 1);
  
  SetClass("merchant");
  SetLevel(12);
  SetInventory( ([
     S_OBJ + "pants" : "wear pants",
     S_OBJ + "shirt" : "wear shirt",
     S_OBJ + "robe" : "wear robe",
     STD_OBJ + "storage/pouch" : "wear pouch",
  ]) );
  SetFriends( ({
  }) );
  SetLimit(1);
  SetMenuItems( ([
     "torch" : STD_LIGHT + "torch",
     "leather pouch" : STD_OBJ + "storage/pouch",
     "robe" : S_OBJ + "robe",
  ]) );
  SetCurrency("imperials", random(225));
  SetLocalCurrency("imperials");
  SetMorality(-125);
  SetAction(3, ({
  }) );
  SetCombatAction(3, ({
  }) );
}
