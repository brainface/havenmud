// removes random(luck/2) bleeding in imbiber
// mahkefel '10
#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
  meal::create();
  SetKeyName("potion");
  SetId( ({ "coagulation potion", "potion" }) );
  SetShort("a crimson potion");
  SetAdjectives( ({"crimson","coagulation","viscous"}) );
  SetProperty("magic", "This potion seems to slow bleeding.");
  SetMass(20);  /* fixed from weighing 2.5 pounds by Dylanthalus@Haven */
  SetDestroyOnSell(1);
  SetLong("It is a magic potion of some viscous red liquid.");
  SetMealType(MEAL_DRINK);
   SetStrength(20); // a little drink to prevent mutli-potion lameness.
  SetValue(0);
  SetMealMessages("You drink some of the crimson potion and feel a bit different.",
                  "$N drinks a crimson potion.");
}

mixed eventDrink(object who) {
  who->AddBleeding(-random(who->GetStatLevel("luck")/2) - 1);
  return meal::eventDrink(who);
}
