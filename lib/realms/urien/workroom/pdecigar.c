#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
  ::create();
  SetKeyName("cigar");
  SetId( ({ "cigar", }) );
  SetAdjectives( ({ "daemon" }) );
  SetShort("a daemon cigar");
  SetMass(1);
  SetLong("This is actually a human index finger ablaze.");
  SetMealType(MEAL_SMOKE);
  SetStrength(15);
  SetPortions(20);
  SetMealMessages(
    "You puff on an index finger.",
    "$N puffs on an index finger."
    );
}
