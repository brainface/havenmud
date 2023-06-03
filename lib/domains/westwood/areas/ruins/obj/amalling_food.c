#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
  ::create();
  SetKeyName("albino malling");
  SetShort("an albino malling");
  SetStrength(100);
  SetMass(45);
  SetId( ({ "malling", "fish" }) );
  SetAdjectives( ({"albino"}) );
  SetLong("This particular fish looks like a rare creature "
          "that has been altered to become pure white in colour. "
          "It is a very large carrot shaped fish with two "
          "equally large fins on the sides of the body. Two "
          "red eyes protrude from its hardened head and "
          "thick scales have formed around his body cavity. "
          "Its overall size is massive and would prove to "
          "be an excellent meal.");
  SetMealMessages( ({
    "$N eats an albino malling.",
    "You eat an albino malling, it is quite filling and delicious.",
    }) );
  SetMealType(MEAL_FOOD);
  SetValue(10);
}
