#include <lib.h>
#include <meal_types.h>

inherit LIB_MEAL;

static void create() {
  meal::create();
  SetKeyName("ale");
  SetId( ({ "bottle", "ale", "black day", "black day ale" }) );
  SetShort("a bottle of Black Day ale");
  SetLong("This is a bottle of Black Day ale, a specialty of Skel.");
  SetMass(25);
  SetMealType(MEAL_DRINK | MEAL_ALCOHOL);
  SetStrength(35);
  SetMealMessages("The ale rumbles down your throat and warms your stomach.",
		              "$N drinks from a black bottle.");
  SetEmptyName("bottle");
  SetEmptyShort("an empty bottle of Black Day ale");
  SetEmptyLong("This black bottle once contained some strong ale.");
}
