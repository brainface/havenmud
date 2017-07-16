#include <lib.h>
#include <meal_types.h>
#include <domains.h>
inherit LIB_MEAL;

static void create() {
  ::create();
  SetKeyName("oasis");
  SetId( ({ "oasis", }) );
  SetAdjectives( ({  }) );
  SetShort("an oasis");
  SetPortions(-1);
  SetLong(
    "The oasis in the desert seems to be fed from a deep "
    "underground water source.  So deep, in fact, that "
    "one could fish within its waters."
  );
  SetStrength(20);
  SetMealType(MEAL_DRINK);
  SetMealMessages( ({
    "You drink from the oasis.",
    "$N drinks from the oasis.",
  }) );
  SetInvis(1);
  SetPreventGet("");
}

mixed direct_dive_into_obj() {
  if (this_player()->GetProperty("swimmer")) return 1;
  return "But you need to <set swimming to on> for that!";
}

int eventExecuteDive(object who) {
  who->eventMove(YOZRATH_VIRTUAL "river/0,0");
  return 1;
}
