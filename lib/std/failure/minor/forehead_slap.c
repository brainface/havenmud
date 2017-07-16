#include <lib.h>
#include <position.h>

inherit LIB_FAILURE;

int eventFail(object who, object spell)
{
  send_messages(0, "The magic of $agent_possessive_noun failed spell manifests "
                "itself as a front of dense, hot air, and slaps "
                "$agent_objective hard on the forehead.",
                who, 0, environment(who));
  send_messages("fall", "$agent_name dizzily $agent_verb on $agent_possessive "
                "rump.",
                who, 0, environment(who));
  if (who->GetPosition() != POSITION_LYING) 
  who->SetPosition(POSITION_SITTING);
  return 1;
}
