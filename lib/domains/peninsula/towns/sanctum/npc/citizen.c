#include <lib.h>
#include "../rome.h"
inherit LIB_SENTIENT;

static void create() {
  mapping inventory = ([]);
  ::create();
  SetKeyName("citizen");
  SetRace("human");
  RemoveLanguage("Enlan");
  SetLanguage("Imperial", 100, 1);
  SetGender(random(2) ? "male" : "female");
  SetShort("a " + GetGender() + " citizen of Sanctum");
  SetId( ({ "citizen", "wander" }) );
  SetAdjectives( ({ GetGender() }) );
  SetMorality(5);
  SetClass("merchant");
  SetLong(
     "This person is one of many citizens of Sanctum. This person looks to be busy, ignoring "
     "everything else and focusing only on what this person has set out to do. "
     );
  SetSkill("melee combat", 1, 1);
  SetLevel(2);
  SetLimit(6);
  SetWander(4);
  if(GetGender() == "male") {
    inventory = ([ ROME_OBJ "toga" : "wear toga", ]);
  } else {
    inventory = ([ ROME_OBJ "stola_poor" : "wear stola", ]);
  }
  SetInventory(inventory);
}

