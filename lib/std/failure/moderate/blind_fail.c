// Thoin@Haven
// 02/20/06
// blindness failure

#include <lib.h>

inherit LIB_FAILURE;

int eventFail(object who, object spell)
{
 
    send_messages(0, "$agent_possessive_noun spell fails in a brilliant flash "
                     "of %^BOLD%^%^WHITE%^light%^RESET%^ blinding $agent_name."
                     ,who,0,environment(who));

  who->eventBlind(who, 5+random(5));
  return 1;
}
