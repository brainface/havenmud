// Thoin
// Recovery Time failure

#include <lib.h>

inherit LIB_FAILURE;

int eventFail(object who, object spell)
{
  send_messages(0, "The %^CYAN%^energy%^RESET%^ of $agent_possessive_noun spell "
                "dissipates into the air causing $agent_objective "
                "to become dazed and confused.",
                who, 0, environment(who));
  who->AddRecoveryTime(random(100));
  return 1;
}

