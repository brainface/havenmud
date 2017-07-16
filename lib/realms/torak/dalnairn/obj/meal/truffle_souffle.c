#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
  ::create();
  SetKeyName("truffle souffle");
  SetShort("a black truffle souffle");
  SetId( ({ "souffle" }) );
  SetAdjectives( ({ "truffle", "black" }) );
  SetLong(
    "This is a fluffy black truffle souffle served in a turtle shell."
  );
  SetMass(8);
  SetMealType(MEAL_FOOD);
  SetStrength(45);
  SetPortions(6);
  SetMealMessages("You eat some black truffle souffle.",
                  "$N enjoys a bite of black truffle souffle.");
  SetEmptyName("shell");
  SetEmptyShort("an empty turtle shell");
  SetEmptyLong("It is an empty turtle shell that once held some cooked food.");
}
