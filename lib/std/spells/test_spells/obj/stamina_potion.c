// adds stamina to drinker
#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
  meal::create();
  SetKeyName("potion");
  SetId( ({ "stamina potion", "potion" }) );
  SetShort("a dark yellow potion");
  SetAdjectives( ({"yellow","dark","stamina"}) );
  SetProperty("magic", "This potion seems to relieve fatigue.");
  SetMass(20);  /* fixed from weighing 2.5 pounds by Dylanthalus@Haven */
  SetDestroyOnSell(1);
  SetLong("It is a magic potion of some dark yellow liquid.");
  SetMealType(MEAL_DRINK);
  SetStrength(20);
  SetValue(0);
  SetMealMessages("You drink some of the potion and feel a bit different.",
                  "$N drinks a potion.");
}

mixed eventDrink(object who) {
  who->AddStaminaPoints(120);
  return meal::eventDrink(who);
}


