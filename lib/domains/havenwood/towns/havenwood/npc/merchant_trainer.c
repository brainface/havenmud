#include <lib.h>
#include <std.h>
#include <daemons.h>
#include "../wood.h"
inherit LIB_TRAINER;

static void create() {
  ::create();
  SetKeyName("Maven");
  SetId( ({"maven","greedy"}) );
  SetAdjectives( ({"maven","greedy","the"}) );
  SetShort("Maven the Greedy");
  SetLong(
    "Maven is a tall and slender wild-elf with a "
    "wandering eye. He has something of a bad reputation "
    "among his fellow citizens for ill-advised money-making "
    "schemes. He is well-versed in financial matters, though; "
    "and may be willing to share his knowledge with others."
  );
  SetTown("Havenwood");
  SetRace("wild-elf");
  SetClass("merchant");
  SetLevel(48);
  SetMorality(0);
  SetTown("Havenwood");
  SetCurrency("imperials",random(300) + 100);
  SetAction(10, ({
    "!say What's in this for me?",
    "!emote counts his coins.",
    "!say I'm telling you Fendell, it's a solid plan, "
      "I just need some capital to get started!"
  }) );
  SetGender("male");
  SetInventory( ([
    STD_POLE "staff" : "wield staff",
  ]) );
  SetTrainingSkills( ({
    "bargaining",
    "stealth",
    "stealing",
    "cooking",
    "farming",
    "fishing",
    "textile working",
  }) );
  SetLimit(1);
}

