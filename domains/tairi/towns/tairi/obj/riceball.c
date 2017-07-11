/* A small bowl of rice */
#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
  ::create();
  SetKeyName("rice");
  SetShort("a small bowl of rice");
  SetId( ({ "bowl", "rice" }) );
  SetAdjectives( ({ "small" }) );
  SetLong(
     "This is a small bowl that is filled with riceballs. "
     "The riceballs look fresh and delicious. "
  );
  SetStrength(15);
  SetMass(15);
  SetMealType(MEAL_FOOD);
  SetMealMessages(
     "You eat a ball of rice from the bowl. ",
     "$N eats a ball of rice from the bowl."
  );
  SetPortions(4);
}
