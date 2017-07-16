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
  SetLong("This is a thick, expensive cigar.");
  SetMealType(MEAL_SMOKE);
  SetStrength(15);
  SetPortions(4);
  SetMealMessages(
    "You puff on a thick cigar.",
    "$N puffs on a thick cigar."
    );
}
