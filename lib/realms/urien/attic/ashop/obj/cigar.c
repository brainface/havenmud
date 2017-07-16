#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
  meal::create();
  SetKeyName("cigar");
  SetId( ({ "cigar", }) );
  SetAdjectives( ({ "fine"}) );
  SetShort("a fine cigar");
  SetMass(2);
  SetLong("This cigar is just a human finger in length and "
          "has been wrapped with a dry leaf. This short "
          "cigar has a smoothly cut opening through "
          "which the chopped tobacco can be seen.\n"
          "To use the cigar you must first 'light' it.");
  SetMealType(MEAL_SMOKE);
  SetStrength(3);
  SetPortions(4);
  SetValue(4);
  SetMealMessages(
    "You take a puff off the cigar. A medium quality taste remains.",
    "$N puffs on a fine cigar."
    );
}
