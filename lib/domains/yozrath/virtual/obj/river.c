#include <lib.h>
#include <meal_types.h>
#include <domains.h>
inherit LIB_MEAL;

static void create() {
  ::create();
  SetKeyName("river");
  SetId( ({ "river", }) );
  SetAdjectives( ({  }) );
  SetShort("a river");
  SetPortions(-1);
  SetLong(
    "The River Bjorn seems to be fed from a deep "
    "underground water source. So deep, in fact, that "
    "one could dive into its waters."
  );
  SetStrength(20);
  SetMealType(MEAL_DRINK);
  SetMealMessages( ({
    "You drink from the river.",
    "$N drinks from the river.",
  }) );
  SetInvis(1);
  SetPreventGet("");
}

mixed direct_dive_into_obj() {
  if (this_player()->GetProperty("swimmer")) return 1;
  return "But you need to <set swimming to on> for that!";
}

int eventExecuteDive(object who) {
  who->eventMove(YOZRATH_VIRTUAL "river/40,100");
  return 1;
}
