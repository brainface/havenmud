#include <lib.h>
#include <meal_types.h>

inherit LIB_MEAL;
void eventDecay();
int life = 300;

static void create() {
    meal::create();
    SetKeyName("roasted rabbit");
    SetId( ({ "rabbit" }) );
   SetAdjectives( ({ "roasted","perfect","perfectly","prepared" }) );
    SetShort("a perfectly prepared roasted rabbit");
    SetLong("A delicately crispy layer of skin forms the outer layer of "
	"perfectly prepared roasted rabbit.  The air hazes near it, "
	"betraying its heat and suggesting that it was recently removed "
	"from the fire.");
    SetMass(20);
    SetMealType(MEAL_FOOD);
    SetStrength(75);
    SetMealMessages("The roasted rabbit virtually melts in your mouth.",
                    "$N devours a roasted rabbit.");
    SetProperty("magic","Created by Eclat druids to provide nourishment, "
	"the roasted rabbit is a gift from the Divine Amelia.");
    set_heart_beat(1);
}

void heart_beat() {
   life--;
   if(!life) { eventDecay(); }
}

void eventDecay() {
    if (environment())
  message("food_action",
     "The roasted rabbit decays into nothingness.",
      environment() );
    eventDestruct();
  }
