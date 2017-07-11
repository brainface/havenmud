#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
  meal::create();
  SetKeyName("cigar");
  SetId( ({ "cigar", }) );
  SetAdjectives( ({ "thick" }) );
  SetShort("a thick cigar");
  SetMass(1);
  SetLong("This thick cigar is the length of a human index "
          "finger, but the width of a good sized carrot. The "
          "outside has been carefully wrapped with a bright "
          "leaf which surrounds the inside tobacco exposing "
          "it at one end. The cigar has a ribbon wrapped around "
          "it with a fancy \"L\" sewn in the surface. A pinhole "
          "has been made to get a deeper hit off the product.\n"
          "To use the cigar you must first 'light' it.");
  SetMealType(MEAL_SMOKE);
  SetStrength(15);
  SetPortions(8);
  SetValue(15);
  SetMealMessages(
    "You puff on a thick cigar.",
    "$N puffs on a thick cigar."
    );
}
