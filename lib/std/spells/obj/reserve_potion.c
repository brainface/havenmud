#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
  meal::create();
  SetKeyName("potion");
  SetId( ({ "magic potion", "potion" }) );
  SetShort("a magic potion");
  SetProperty("magic", "This blue potion seems to hold magical energy.");
  SetMass(20);  /* fixed from weighing 2.5 pounds by Dylanthalus@Haven */
  SetDestroyOnSell(1);
  SetLong("It is a magic potion of blue liquid.");
  SetMealType(MEAL_DRINK);
  SetStrength(0);
  SetValue(0);
  SetMealMessages("You drink some blue liquid and feel a bit different.",
                  "$N drinks some blue liquid.");
}

mixed eventDrink(object who) {
  who->AddMagicPoints(120);
  return meal::eventDrink(who);
}
