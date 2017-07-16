/* A standard farming thing */
#include <lib.h>
#include <meal_types.h>

inherit LIB_MEAL;

static void create() {
  ::create();
  SetKeyName("potato");
  SetShort("a potato");
  SetId( ({ "potato" }) );
  SetAdjectives( ({ }) );
  SetMealType(MEAL_FOOD);
  SetStrength(30);
  SetLong("This is a home grown potato.");
  SetMass(15);
}
