/*    /lib/mount
 * mostly a copy of sit
 * mahkefel
 */
#include <lib.h>
#include <position.h>

inherit LIB_SIT;
inherit LIB_HITCH;

private object Rider  = 0;

object GetRider() {
    return Rider;
}

// mount a thing
mixed eventReceiveMount(object who) {
  mixed thing;

  // try to eventSit. if it fails, we couldn't sit
  // and return the value. Otherwise, sitter is Rider.
  thing = who->eventSit(this_object());
  if (thing != 1) {
    if (!thing) {
      who->eventPrint("You cannot ride that!"); 
    } else {
      who->eventPrint(thing); 
    }
  } else {
    send_messages("mount", "$agent_name $agent_verb " +
     "$target_name.", who, this_object(), environment());
    Rider = who;
  }
  return 1; 
}

// dismounting
mixed eventReleaseDismount(object who) {
  // only rider "dismounts",
  // passengers do not
  if (GetRider() == who) {
    send_messages("dismount",
      "$agent_name $agent_verb $target_name.",
      who, this_object(), environment(who) );
    Rider = 0;
  } else {
    send_messages("jump",
      "$agent_name $agent_verb off $target_name.",
      who, this_object(), environment(who) );
  }
  return 1;
}

// override eventReleaseStand (Standing up) to also dismount
mixed eventReleaseStand(object who) {
  if (eventReleaseDismount(who)) {
    return ::eventReleaseStand(who);
  } else {
    return 0;
  }
}

mixed direct_mount_liv() {
  if (Rider) {
    return Rider->GetKeyName() + " is riding that!";
  }
  return 1;
}

int is_mount() {
  return 1;
}
