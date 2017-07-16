#include <lib.h>
#include <daemons.h>
#include <dirs.h>
inherit LIB_NPC;
static void create() {
  npc::create();
  SetKeyName("dingo");
  SetId( ({"dingo", "dog"}) );
  SetAdjectives( ({"wild"}) );
  SetShort("a wild dingo");
  SetRace("dog");
  SetClass("animal");
  SetGender("male");
  SetLevel(3);
  SetLong("This wild canine appears to be quite ferocious.");
}

int eventDie(object killer) {
  object bandit_inv;
  if (!random(1000)) {
    bandit_inv = new(DIR_INVASIONS + "/sanctum_bandit/bis_inv");
    INVASION_D->eventRegisterInvasion(bandit_inv, killer);
  }
return ::eventDie(killer);
}
