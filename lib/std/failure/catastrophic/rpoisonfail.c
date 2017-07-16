#include <lib.h>
#include <daemons.h>
#include <damage_types.h>

inherit LIB_FAILURE;

int eventFail(object who, object spell)
{
  environment(who)->AddPoisonGas(40 + random(20));

  send_messages( "", "A cloud of %^GREEN%^poison gas%^%^RESET%^ drifts from "
                     "$agent_possessive_noun hands!",
                who, 0, environment(who) );
  if (playerp(who)) CHAT_D->eventSendChannel("FAILURE!", "reports", who->GetCapName() +
        " got the Room Poison failure!");

  return 1;
}
