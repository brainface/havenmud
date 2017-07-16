#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
  meal::create();
  SetKeyName("vodka");
  SetShort("a shot of dark vodka");
  SetAdjectives(({ "shot", "of", "dark" }) );
  SetId( ({ "vodka", "shot",  }) );
  SetLong("This small glass has been filled with a very dark vodka.");
  SetMealType(MEAL_DRINK|MEAL_ALCOHOL);
  SetStrength(40);
  SetMealMessages(
     "It goes down like a shotgun blast to the chest.",
     "$N drinks the vodka in one straight shot.");
  SetEmptyName("glass");
  SetEmptyShort("a tiny empty glass");
  SetEmptyLong(
     "This glass is tiny and once held a dark liquid. A strong "
     "smell of vodka lingers from it.");
  SetPortions(1);
}
