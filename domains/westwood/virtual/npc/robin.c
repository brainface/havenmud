#include <lib.h>
inherit LIB_NPC;

static void create(){
  npc::create();
  SetKeyName("red-breasted robin");
  SetId( ({"robin","bird"}) );
  SetAdjectives( ({"red-breasted","red"}) );
  SetShort("a red-breasted robin");
  SetLong("This stocky bird has a dull red breast that contrasts "
    "the dull brown color of her back. On her fragile legs, she "
    "hops around excitedly on a branch. ");
  SetRace("bird");
  SetGender("female");
  SetClass("animal");
  SetAction(5,({"The robin's sweet voice serenades to anyone "
      "who cares to listen.","!sing sweetly",
  }) );
  SetLevel(2);
}
