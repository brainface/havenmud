// Zeddicus@Haven
// Monday, September 06 2004 17:22
// Poison the caster.

#include <lib.h>
#include <damage_types.h>

inherit LIB_FAILURE;

int eventFail(object who, object spell)
{
  who->AddPoison(20+random(20));

  send_messages(0, "By $agent_possessive_noun fumbling, some of "
                   "$agent_possessive blood is made "
                   "%^GREEN%^BOLD%^TOXIC%^RESET%^, poisoning $agent_objective!",
                   who, 0, environment(who));
  return 1;
}
