#include <lib.h>
#include <armour_class.h>
#include <armour_types.h>
inherit LIB_ARMOUR;

void WearMe();

static void create() {
  ::create();
  SetKeyName("communicator ring");
  SetArmourType(A_RING);
  SetArmourClass(ARMOUR_CLOTH);
  SetShort("a communicator ring");
  SetLong(
    "This ring allows access to the interstellar radio waves."
    );
  SetWear( (: WearMe :) );
  SetId( ({ "ring", "communicator" }) );
  SetAdjectives( ({ "communicator" }) );
}

void WearMe() {
  this_player()->AddChannel("comm");
  send_messages("wear", "$agent_name $agent_verb a communicator ring.", this_player(), 0, environment(this_player()) );
}

varargs mixed eventUnequip(object who) {
  if (who) who->RemoveChannel("comm");
  return ::eventUnequip(who);
}