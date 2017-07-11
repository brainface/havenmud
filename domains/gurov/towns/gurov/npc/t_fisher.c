#include <lib.h>
#include "../gurov.h"
#include <std.h>
inherit LIB_TRAINER;

static void create() {
  ::create();
  SetKeyName("isha");
  SetShort("Isha the Fisherman");
  SetRace("human");
  SetGender("male");
  SetBaseLanguage("Gurovian");
  SetId( ({ "isha", "fisher", "fisherman" }) );
  SetAdjectives( ({ "fisherman", }) );
  SetTown("Gurov");
  SetClass("merchant");
  SetLevel(15);
  SetMorality(75);
  SetTrainingSkills( ({
    "fishing",
    "knife combat",
    "navigation",
    }) );
  SetLong("Isha is a man of advancing years. His main joy in life is "
          "standing along the docks in Gurov, quietly fishing his life "
          "away. He would be willing to teach anyone that wanted to learn.");
  SetAction(4, ({
    "!fish with pole",
    "!speak Here... fishy fishy fishy...",
    "!speak I'd teach you if you asked me.",
    "!speak So.  Fine day for fishing, yes?",
    }) );
  SetLimit(1);
  SetInventory( ([
    STD_FISH "pole" : "wield pole",
    ]) );
}
