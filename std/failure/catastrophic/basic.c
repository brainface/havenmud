/* Basic minor spell failure */
#include <lib.h>
inherit LIB_FAILURE;


int eventFail(object who, object spell) {
  send_messages("summon",
    "$agent_name $agent_verb a catastrophic puff of smoke.",
    who, 0, environment(who) );
  return 1;
  }
  