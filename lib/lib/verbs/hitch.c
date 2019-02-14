/*    /lib/hitch.c
 *  not about marriagen
 */
// TODO: make it so you can only hitch a living to a lib_wagon

#include <position.h>

private int          MaxHitchers = 1;
private object       Hitcher;

object GetHitcher() {
  return Hitcher;
}

// leave agent as 0 if you don't want to send the message
mixed eventReceiveHitch(object target, object agent) {
  // add target to hitch list
  if (agent) {
    send_messages("hitch", "$agent_name $agent_verb " + 
      this_object()->GetShort() + " to " + target->GetShort() + ".",
      agent, 0, environment() );
  }
  //environment()->eventPrint(this_player()->GetShort() + " hitches " +
  //  this_object()->GetShort() + " to " + target->GetShort() + ".");
  Hitcher = target;
  return 1;
}

mixed eventReleaseHitch(object agent) {
  // only send a message if agent was passed
  if (agent) {
    send_messages("unhitch", "$agent_name $agent_verb " + this_object()->GetShort() +
      " from " + Hitcher->GetShort() + ".", agent, 0, environment());
  }
  Hitcher = 0;
  return 1;
}

mixed indirect_hitch_obj_to_liv() {
  if (Hitcher) {
    return "But " + Hitcher->GetShort() + " is already hitched to "
      + this_object()->GetShort() + "!";
  }
  return 1;
}

mixed indirect_hitch_liv_to_obj() {
  return indirect_hitch_obj_to_liv();
}

mixed direct_hitch_obj_to_liv() {
  if (Hitcher) {
    return "But " + Hitcher->GetShort() + " is already hitched to "
      + this_object()->GetShort() + "!";
  }
  return 1;
}

mixed direct_hitch_liv_to_obj() {
  return direct_hitch_obj_to_liv();
}

mixed direct_unhitch_obj() {
  if (!Hitcher) {
    return "Nothing is hitched to " + this_object()->GetShort() + ".";
  }
  return 1;
}

