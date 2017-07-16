/* Mother Bear - Level #1 Caverns */

#include <lib.h>
#include "../caves.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("bear");
  SetId( ({ "bear" }) );
  SetAdjectives( ({ "mother" }) );
  SetShort("a mother bear");

  SetLong("The mother bear has frayed black fur and is foaming at the mouth.  "
          "She appears to be a very determined foe.");

  SetRace("bear");
  SetClass("animal");
  SetLevel(2);
  SetGender("female");
  SetFriends( ({ "cub" }) );
  SetMorality(-200);
  SetDie("The mother bear growls one last time before she drops to the "
         "ground.");

  SetAction(5, ({"The mother bear growls angrily!",
                 "The mother bear sets herself into an position to protect "
                 "her young.",
  }) );

  SetCombatAction(10, ({"The mother bear rears up on her hind legs and attacks!",
                        "The mother bear foams at the mouth and drools on you.",
  }) );
}
