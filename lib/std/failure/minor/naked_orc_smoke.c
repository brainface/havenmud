#include <lib.h>

inherit LIB_FAILURE;

int eventFail(object who, object spell)
{
  send_messages("succeed", "$agent_name $agent_verb only in filling the area "
                "with a thick cloud of blue smoke, in which illusions of naked "
                "orcs can be seen dancing.",
                who, 0, environment(who));
  return 1;
}
