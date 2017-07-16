#include <lib.h>

inherit LIB_FAILURE;

int eventFail(object who, object spell)
{
  send_messages(0, "The energy of $agent_possessive_noun spell "
                "navigates its own path...right back into $agent_possessive "
                "body, causing $agent_possessive joints to freeze up!",
                who, 0, environment(who));
  who->SetParalyzed(2+random(2));
  return 1;
}
