#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
  meal::create();
  SetKeyName("cigar");
  SetId( ({ "cigar", "averan" }) );
  SetAdjectives( ({ "brand"}) );
  SetShort("a dark brown cigar");
  SetMass(2);
  SetLong("This cigar has a dark brown wrapping with black "
          "stripes which swirl on the paper. An opening "
          "displays the deep red cut tobacco inside. This "
          "cigar is commonly known as the Averan in Averath. "
          "The standard in a quality cigar.\n"
          "To use the cigar you must first 'light' it.");
  SetMealType(MEAL_SMOKE);
  SetStrength(8);
  SetPortions(15);
  SetValue(30);
  SetMealMessages(
    "You take a puff on the Averan brand cigar. It has a mild blend.",
    "$N puffs on a fancy dark-brown cigar."
    );
}
