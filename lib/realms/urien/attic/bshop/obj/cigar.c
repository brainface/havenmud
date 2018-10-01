#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
  meal::create();
  SetKeyName("cigar");
  SetId( ({ "cigar", }) );
  SetAdjectives( ({ "imported"}) );
  SetShort("an imported cigar");
  SetMass(2);
  SetLong("This cigar is just a human finger in length and "
          "has been wrapped in a dry leaf. This short "
          "cigar has a smooth cut opening through which the chopped "
          "tobacco can be seen. It has a band along the "
          "tip of the cigar which reads \"imported.\" \n"
          "To use the cigar you must first 'light' it.");
  SetMealType(MEAL_SMOKE);
  SetStrength(10);
  SetPortions(6);
  SetValue(4);
  SetMealMessages(
    "You take a puff on the cigar. A medium quality taste remains.",
    "$N puffs on an imported cigar, releasing white smoke."
    );
}
