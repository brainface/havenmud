#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
  ::create();
  SetKeyName("natural herbs");
  SetShort("a sprig of natural herbs");
  SetId( ({ "sprig", "herb", "herbs" }) );
  SetAdjectives( ({ "spring", "of", "natural" }) );
  SetLong(
    "This sprig of natural herbs is a natural way to calm oneself. Though "
    "likely unhealthy it can refocus a state of mind."
  );
  SetSmell("The sprig has a faintly cinnamony smell.");
  SetMealType(MEAL_SMOKE|MEAL_ALCOHOL);
  SetPortions(1);
  SetMass(15);
  SetStrength(40);
  SetMealMessages( ({
    "You puff on the natural herbs.",
    "$N puffs on a sprig of natural herbs."
  }) );
}

mixed eventSmoke(object who) {
  int x = ::eventSmoke(who);
  
  who->AddCaffeine(-10);
  who->AddRecoveryTime(-5);
  return x;
}
