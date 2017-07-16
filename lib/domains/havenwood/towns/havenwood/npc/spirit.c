#include <lib.h>
#include <daemons.h>
#include "../wood.h"
inherit LIB_TOWNGUARD;

static void create() {
  ::create();
  SetKeyName("Incarnation of the Havenwood");
  SetShort("the Incarnation of the Havenwood");
  SetId( ({ "tree", "spirit", "incarnation", "havenwood_wander" }) );
  SetLong(
    "This mighty creature stands nearly 50 feet in height, and its branches "
    "extend another 20 without a stretch. The Incarnation of the Havenwood is "
    "the physical manifestation of the spirit of the wood itself, and it uses "
    "the form of a giant tree.  When aroused to anger, the spirit is an extremely "
    "deadly opponent and should not be underestimated. The spirit has been "
    "known to defend the citizens of the Havenwood from all harm."
    );
  SetRace("tree");
  SetClass("fighter");
  SetSkill("melee combat", 1, 1);
  SetLevel(500);
  SetMorality(2500);
  SetLimit(1);
  SetProperty("no bump", 1);
  SetTown("Havenwood");
  SetWander(20);
  SetCombatAction(10, ({
    "!disorient",
    "!disarm",
    "Leaves fall wildly from the branches of the Havenwood Spirit!",
  }) );
}

int eventDie(object agent) {
  if (agent) {
    agent->AddTitle("the Defiler of the Havenwood");
    CHAT_D->eventSendChannel("Havenwood Spirit", "ooc", "I have been defiled by " + agent->GetCapName() + "!");
  }
  return ::eventDie(agent);
}
