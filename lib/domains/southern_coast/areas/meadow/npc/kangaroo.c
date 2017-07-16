/* a kangaroo for the meadow
    Kyla 10-19-97
*/
#include <lib.h>
#include <daemons.h>
#include <dirs.h>
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("kangaroo");
  SetId( ({
         "kangaroo", "roo",
          }) );
  SetAdjectives( ({
                "red",
         }) );
  SetShort("a red kangaroo");
  SetRace("mammal");
  SetClass("animal");
  SetLevel(8);
  SetGender("female");
  SetLong("This bouncy red kangaroo looks very agile and very strong.");
  }

int eventDie(object killer) {
  object bandit_inv;
  if(!random(1000)) {
    bandit_inv = new(DIR_INVASIONS + "/sanctum_bandit/bis_inv");
    INVASION_D->eventRegisterInvasion(bandit_inv, killer);
  }
return ::eventDie(killer);
}
