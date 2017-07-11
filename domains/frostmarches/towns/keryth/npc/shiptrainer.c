#include <lib.h>
inherit LIB_TRAINER;

static void create() {
  ::create();
  SetKeyName("gustav");
  SetId( ({ "gustav" }) );
  SetAdjectives( ({ "wise" }) );
  SetShort("Gustav the Wise");
  SetLong("Gustav was a sailor once. But a few too many "
          "years at sea and he's no longer able to keep up with the young. "
          "However, he's always willing to teach someone and tell "
          "his tales of the sea.");

  SetRace("goden");
  SetGender("male");
  SetTrainingSkills( ({
        "sailing",
        "navigation",
      "wood working", // added by torak 5/31/17 permission from mahkefel
        "knife combat",
        "fishing",
        "swimming",
        "bargaining",
        "stealing",
        }) );
  SetClass("sailor");
  SetLevel(20);
  SetMorality(50);
  SetLocalCurrency("senones");
  SetInventory( ([

    ]) );
  SetAction(5, ({
        "!speak Aye, I can teach you!",
  }) );
  SetLimit(1);
  SetTown("all");
}

