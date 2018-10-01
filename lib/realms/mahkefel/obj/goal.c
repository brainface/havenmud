#include <lib.h>

inherit LIB_ITEM;

int GoalGetter(object who);

static void create() {
  item::create();
  SetKeyName("goal");
  SetShort("a tangible goal");
  SetId(({ "goal" }));
  SetAdjectives( ({ "tangible" }) );
  SetLong(
    "A huge field goal post stands proudly here, waiting for someone to grab "
    "it and run around in drunken revelry."
    );
  SetTouch("Feels like victory.");
  SetSmell("Smells like team spirit.");
  SetPreventGet( (:GoalGetter:) );
}

int GoalGetter( object who ) {
  who->eventPrint("You have acquired a tangible goal!");
  if(creatorp(who)){
    who->SetShort("$N the Goal-Getter");
  } else if (playerp(who)) {
    who->AddTitle("$N the Goal-Getter");
  }
  return 1;
}

