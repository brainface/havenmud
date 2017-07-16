#include <lib.h>
#include "../path.h"
inherit LIB_TRAINER;

static void create() {
  ::create();
  SetKeyName("hurley");
  SetShort("Hurley the Beached");
  AddAlcohol(75);
  SetId( ({ "hurley" }) );
  SetAdjectives( ({ "beached" }) );
  SetRace("halfling");
  SetGender("male");
  SetTrainingSkills( ({
        "sailing",
        "navigation",
        "knife combat",
        "fishing",
       "natural working",
        "swimming",
    }) );
  SetLevel(20);
  SetMorality(50);
  SetLong("Hurley was a sailor... once.  But a few too many "
          "bottles of rum and he's no longer saying \"Yo ho ho\". "
          "However, he's always willing to teach someone and tell "
          "his tales of the sea.");
  SetInventory( ([
    LLORYK "obj/rum" : 1,
    ]) );
  SetAction(5, ({
        "!speak Yo ho ho!",
        "!yell Ahoy Mateys!",
        "!drink my rum",
        "!speak Aye, I can teach you to not be like me!",
  }) );
  SetLimit(1);
  SetTown("all");
}

