#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
  meal::create();
  SetKeyName("nectar");
  SetShort("a mug of nectar");
  SetId( ({ "nectar", "mug" }) );
  SetAdjectives( ({ "mug", "of" }) );
  SetMass(7);
  SetLong("This mug has been filled with a light yellow "
          "nectar. The liquid is thicker than "
          "water, with an almost syrupy quality. "
          "Some petals from a native flower of Baria "
          "have been previously stirred into the liquid, " 
          "creating a rather exotic drink.");
  SetMealType(MEAL_DRINK);
  SetStrength(20);
  SetPortions(2);
  SetValue(15);
  SetMealMessages(
    "You drink the mug of nectar. it has a very light taste.",
    "$N drinks a mug of nectar."
    );
}
