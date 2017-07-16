// Thoin
// Recovery Time failure

#include <lib.h>
#include <daemons.h>

inherit LIB_FAILURE;

int eventFail(object who, object spell)
{
  int amt = random(200);
  amt -= who->GetStatLevel("luck");
  if (amt < 25) amt = 25;
  
  send_messages(0, "The %^CYAN%^energy%^RESET%^ of $agent_possessive_noun spell "
                "dissipates into the air causing $agent_objective "
                "to become dazed and confused.",
                who, 0, environment(who));
  who->AddRecoveryTime(amt);
  if (playerp(who)) CHAT_D->eventSendChannel("FAILURE!", "reports", who->GetCapName() +
        " got the Daze failure for " + amt + "!");
  return 1;
}
