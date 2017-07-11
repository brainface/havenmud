#include <lib.h>
#include <daemons.h>
#include <dirs.h>
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("duck billed platypus");
  SetId( ({"platypus"}) );
  SetAdjectives( ({"duck billed", "duck-billed"}) );
  SetShort("a duck billed platypus");
  SetRace("platypus", 1);
  SetClass("animal");
  SetLevel(1);
  SetGender("female");
  SetLong("A small furry mammal with a ducklike bill, webbed feet, "
          "and a beaverlike tail protects her eggs a majority of the day.");
  AddLimb("torso", 0, 1);
  AddLimb("tail", "torso", 5);
  AddLimb("left hind leg", "torso", 3);
  AddLimb("right hind leg", "torso", 3);
  AddLimb("left rear webbed foot", "left hind leg", 4);
  AddLimb("right rear webbed foot", "right hind leg", 4);
  AddLimb("left front leg", "torso", 3);
  AddLimb("right front leg", "torso", 3);
  AddLimb("left front webbed foot", "left front leg", 4);
  AddLimb("right front webbed foot", "right front leg", 4);
  AddLimb("head", "torso", 1);
  AddStat("agility", 15,3);
  AddStat("durability", 5,5 );
  AddStat("strength", 20,3 );
  }

int eventDie(object killer) {
  object bandit_inv;
  if(!random(1000)) {
    bandit_inv = new(DIR_INVASIONS + "/sanctum_bandit/bis_inv");
    INVASION_D->eventRegisterInvasion(bandit_inv, killer);
  }
return ::eventDie(killer);
}
