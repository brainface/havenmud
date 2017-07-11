#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create()
{
  meal::create();
  SetKeyName("bread");
  SetId( ({"bread","loaf","loaf of bread","old bread","slightly old bread"}) );
  SetShort("a loaf of bread");
  SetMass(15);
  SetValue(4);
  SetLong("This is a medium sized loaf of slightly old bread");
  SetMealType(MEAL_FOOD);
  SetStrength(20);
  SetMealMessages("You eat some bread",
                  "$N eats some bread.");
}
