#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
  meal::create();
  SetKeyName("cigar");
  SetId( ({ "cigar" }) );
  SetAdjectives( ({ "special", "blend", "duchy"}) );
  SetShort("a duchy special blend cigar");
  SetMass(1);
  SetLong("One of the highest quality cigars to date, the "
          "duchy special blended cigar has a coal-black "
          "wrapping with a white stripe surrounding the"
          "closed end. This cigar "
          "is two human index fingers in length.\n"
          "To use the cigar you must first 'light' it.");
  SetMealType(MEAL_SMOKE);
  SetStrength(12);
  SetPortions(20);
  SetValue(25);
  SetMealMessages(
    "You take a puff on duchy special blend. It has a rich, smooth taste.",
    "$N puffs on a coal black cigar, releasing a major cloud."
    );
}
