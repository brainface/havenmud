#include <lib.h>
#include <daemons.h>
#include <dirs.h>
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("emu");
  SetId( ({"bird", "emu"}) );
  SetAdjectives( ({"feathery", "large"}) );
  SetShort("a large emu");
  SetRace("bird");
  SetClass("animal");
  SetLevel(3);
  SetGender("female");
  SetLong("This feathery bird is four feet tall and appears quite strong.");
}

int eventDie(object killer) {
  object bandit_inv;
  if(!random(1000)) {
    bandit_inv = new(DIR_INVASIONS + "/sanctum_bandit/bis_inv");
    INVASION_D->eventRegisterInvasion(bandit_inv, killer);
  }
return ::eventDie(killer);
}
