#include <lib.h>

inherit LIB_FAILURE;

int eventFail(object who, object spell)
{
  send_messages("succeed", "$agent_possessive_noun spell pops and fizzles, "
                "succeeding only in covering $agent_possessive face with soot.",
                who, 0, environment(who));
  who->eventForce("cough");
  return 1;
}
