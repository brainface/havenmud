/*  What happens when a target dies... */
#include <lib.h>
inherit LIB_SENTIENT;
int CheckUndead();

static void create() {
  sentient::create();
  SetKeyName("vampyre");
  SetProperty("cemetary npc", 1);
  SetMorality(-100);
  SetId( ({ "vampyre" }) );
  SetFriends( ({ "vampyre", "vampire" }) );
  SetUndead(1);
  SetUndeadType("vampire");
  SetLong("A vampyre is a newly dead corpse raised by a vampire.");
  SetRace("human");
  SetClass("fighter");
  SetSkill("melee combat",1,2);
  SetLevel(5);
  SetShort("a vampyre");
  SetGender("male");
  SetEncounter( (: CheckUndead :) );
  SetWanderSpeed(5);
  SetNoClean(1);
}

int CheckUndead() {
  if (this_player()->GetUndead()) return 0;
  SetAttack(this_player());
  return 1;
 }
