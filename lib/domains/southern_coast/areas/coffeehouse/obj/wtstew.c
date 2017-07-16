#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create()
{
  meal::create();
  SetKeyName("stew");
  SetId( ({"stew","thick stew","vegetable stew","thick vegetable stew"}) );
  SetShort("thick vegetable stew");
  SetMass(2);
  SetValue(4);
  SetLong("This is a bowl of thick vegetable stew with a beef broth base.");
  SetMealType(MEAL_FOOD);
  SetStrength(26);
  SetMealMessages("You eat the thick vegetable stew.","$N eats some thick vegetable stew.");
}
