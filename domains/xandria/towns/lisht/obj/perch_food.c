#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
  ::create();
  SetKeyName("itro perch");
  SetShort("an itro perch");
  SetStrength(25);
  SetPortions(3);
  SetMass(20);
  SetId( ({ "perch", "fish" }) );
  SetAdjectives( ({ "itro" }) );
  SetLong(
    "This is a variety of perch native to the Itro River in Xandria."
    "It looks tasty."
    );
  SetMealMessages( ({
    "$N eats some itro perch.",
    "You eat some itro perch.",
    }) );
  SetMealType(MEAL_FOOD);
  SetValue(10);
}
