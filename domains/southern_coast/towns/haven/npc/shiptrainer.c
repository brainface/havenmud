#include <lib.h>
#include "../haven.h"
inherit LIB_TRAINER;

static void create() {
  ::create();
  SetKeyName("tanislantha");
  SetShort("Tanislantha the Spirit of the Elven Fleet");
  AddAlcohol(75);
  SetId( ({ "tanislantha", "spirit", "tanis" }) );
  SetAdjectives( ({ "spirit" }) );
  SetRace("elf");
  SetGender("male");
  SetTrainingSkills( ({
        "sailing",
        "navigation",
        "knife combat",
        "fishing",
        "swimming",
        "wood working",
        "textile working",
    }) );
  SetLevel(20);
  SetMorality(50);
  SetLong(
    "Tanislantha is the Spirit of the Elven Fleet.  His guidance and training "
    "is what gives the elven fleet their excellent name. For those willing, he "
    "can train the fine arts of seamanship."
    );
  SetInventory( ([
    ]) );
  SetAction(5, ({
        "!speak Yes, I can teach you about many things!",
        "!speak Learn the ways of the sea, young deckhand.",
  }) );
  SetLimit(1);
  SetTown("all");
}

