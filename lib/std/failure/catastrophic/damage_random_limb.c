// Zeddicus@Haven
// 09/02/2004 02:26AM
// Randomly pick one of your limbs and damage it.

#include <lib.h>
#include <damage_types.h>

inherit LIB_FAILURE;

int eventFail(object who, object spell)
{
  string limb = who->GetRandomLimb();
  int amount = 0;

  foreach(string skill in spell->GetSkills())
  {
    amount += who->GetSkillLevel(skill);
  }

  who->eventReceiveDamage(this_player(), MAGIC, amount * 10, 0, limb);
  send_messages(0, "$agent_possessive_noun " + limb + " is scorched!",
                who, 0, environment(who));
  return 1;
}
