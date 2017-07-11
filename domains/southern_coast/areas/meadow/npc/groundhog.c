// groundhog for meadow 
// Kyla 9-29-97
#include <lib.h>
#include <daemons.h>
#include <dirs.h>
#include "../meadow.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("groundhog");
  SetShort("a furry groundhog");
  SetId( ({ "groundhog", "rodent" }) );
  SetAdjectives( ({ "furry", "chubby" }) );
  SetRace("rodent");
  SetClass("animal");
  SetLevel(1);
  SetGender("male");
  SetLong("A chubby rodent with big teeth looks harmless.");
}

int eventDie(object killer) {
  object bandit_inv;
  if(!random(1000)) {
    bandit_inv = new(DIR_INVASIONS + "/sanctum_bandit/bis_inv");
    INVASION_D->eventRegisterInvasion(bandit_inv, killer);
  }
return ::eventDie(killer);
}
