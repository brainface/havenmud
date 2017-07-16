//Selket@Haven
//2006
#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
  meal::create();
  SetKeyName("honey cake");
  SetId( ({ "cake" }) );
  SetAdjectives( ({ "honey" }) );
  SetShort("a honey cake");
  SetMass(1);
  SetLong(
    "This is a cake, topped with grain and sweetened with"
    "honey. It looks like it would take the edge off.");
  SetMealType(MEAL_FOOD);
  SetStrength(15);
  SetPortions(4);
  SetMealMessages(
    "You eat a bit of honey cake. It is simple, but good.",
    "$N eats a bit of honey cake.");
}
