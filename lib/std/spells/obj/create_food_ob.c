#include <lib.h>
#include <meal_types.h>

inherit LIB_MEAL;
void eventDecay();
int life = 240;

static void create() {
    meal::create();
    SetKeyName("loaf");
    SetId( ({ "loaf", "bread" }) );
    SetAdjectives( ({ "", "warm" }) );
    SetShort("a loaf of warm bread");
    SetLong("This delectable looking loaf was created "
            "magically.  It looks absolutely delicious!");
    SetMass(12);
    SetMealType(MEAL_FOOD);
    SetStrength(50);
    SetValue(0);
    SetMealMessages("The loaf of bread fills your tummy.",
                    "$N tears into a loaf of bread.");
    set_heart_beat(1);
}

void heart_beat() {
   life--;
   if(!life) { eventDecay(); }
}

void eventDecay() {
    if (environment())
  message("food_action",
     "A mystic loaf decays into nothingness.",
      environment() );
    eventDestruct();
  }
