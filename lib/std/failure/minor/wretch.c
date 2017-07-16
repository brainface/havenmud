#include <lib.h>

inherit LIB_FAILURE;

int eventFail(object who, object spell)
{
  send_messages(0, "After losing control of the spell, leftover magic invades "
                "$agent_possessive_noun stomach and twists it, causing "
                "$agent_objective to retch uncontrollably.",
                who, 0, environment(who));
  who->AddStaminaPoints(-5 - random(10));
  return 1;
}
