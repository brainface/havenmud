#include <lib.h>
#include "../dalnairn.h"
inherit LIB_TRAINER;

static void create() {
  ::create();
  SetKeyName("grom");
  SetId( ({ "grom" }) );
  SetAdjectives( ({ "wise" }) );
  SetShort("Grom the Wise");
  SetLong("Grom was a viking once. But a few too many "
          "years at sea and he's no longer able to keep up with the young. "
          "However, he's always willing to teach someone and tell "
          "his tales of the sea.");
  SetRace("dark-dwarf");
  SetGender("male");
  SetTrainingSkills( ({
    "sailing",
    "navigation",
    "wood working",
    "knife combat",
    "fishing",
    "swimming",
    "bargaining",
    "stealing",
  }) );
  SetClass("viking");
  SetLevel(random(25) + random(25) + 50);
  SetMorality(0);
  SetLocalCurrency("shards");
  SetInventory( ([
    DAL_OBJ + "guardarmour": "wear my suit",
    DAL_OBJ + "sword" : "wield my sword",
    DAL_OBJ + "boots" : "wear my boots",
    ]) );
  SetAction(5, ({
        "!speak Aye, I can teach you!",
  }) );
  SetLimit(1);
  SetTown("all");
}
