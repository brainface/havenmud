#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
  ::create();
  SetKeyName("cigar");
  SetId( ({ "cigar", }) );
  SetAdjectives( ({ "moldy" }) );
  SetShort("a moldy cigar");
  SetMass(1);
  SetLong("This is a thick, moldy looking cigar. It has a dark "
          "leaf wrapping which surrounds the previously chopped "
          "tobacco on the inside. It has a pinhole on one end "
          "on which to smoke it from. Some mold is seen on the "
          "wrapper, but still looks consumable.\n"
          "  To smoke this cigar you must first 'light' it.");
  SetMealType(MEAL_SMOKE | MEAL_POISON);
  SetStrength(12);
  SetPortions(8);
  SetMealMessages(
    "You puff on a moldy cigar.",
    "$N puffs on a moldy cigar."
    );
}