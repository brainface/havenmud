// Thoin@Haven
// 02/20/06
// mana leech disease failure

#include <lib.h>
#include <daemons.h>
#include <std.h>

inherit LIB_FAILURE;

int eventFail(object who, object spell)
{
 
    send_messages( ({"shudder", "cough", "internalize" }), "$agent_name $agent_verb and $agent_verb "
                     "as $agent_nominative $agent_verb the magical energies."
                     ,who,0,environment(who));

  STD_GERMS "greater_mana_leech"->eventInfect(who);
  if (playerp(who)) CHAT_D->eventSendChannel("FAILURE!", "reports", who->GetCapName() +
        " got the Greater Mana Leech failure!");
  return 1;
}
