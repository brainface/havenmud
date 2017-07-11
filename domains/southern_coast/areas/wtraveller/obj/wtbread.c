#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create()
{
  meal::create();
  SetKeyName("bread");
  SetId( ({"bread","loaf","loaf of bread","warm bread","warm loaf of bread"}) );
  SetShort("a warm loaf of bread");
  SetMass(1);
  SetValue(2);
  SetLong("This bread is fresh from the oven and looks quite filling.");
  SetMealType(MEAL_FOOD);
  SetStrength(22);
  SetMealMessages("You eat the warm loaf of bread. It's quite filling and tasty.","$N eats a warm loaf of bread.");
}
