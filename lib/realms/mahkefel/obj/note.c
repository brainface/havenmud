#include <lib.h>

inherit LIB_ITEM;

int GoalGetter(object who);

static void create() {
  item::create();
  SetKeyName("high note");
  SetShort("a high note");
  SetId(({ "note" }));
  SetAdjectives( ({ "high" }) );
  SetLong(
    "It's... a quarter note. Just sort of floating around up there."
    );
  SetListen("EEEEEEEEEEEEEflat");
  SetPreventGet( (:GoalGetter:) );
}

int GoalGetter( object who ) {
  who->eventPrint("It sort of floats away.");
  return 0;
}

