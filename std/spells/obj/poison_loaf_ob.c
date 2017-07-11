#include <lib.h>
#include <meal_types.h>

inherit LIB_MEAL;
void eventDecay();
int life = 500;

static void create() {
    meal::create();
    SetKeyName("mystic loaf");
    SetId( ({ "loaf", "bread" }) );
    SetAdjectives( ({ "mystic", "warm" }) );
    SetShort("a mystic loaf of warm bread");
    SetLong("This delectable looking loaf was created "
            "magically.  It looks absolutely delicious!");
    SetMass(12);
    SetMealType(MEAL_FOOD|MEAL_POISON);
    SetStrength(15);
    SetValue(0);
    SetMealMessages("The loaf fills your tummy.",
                    "$N tears into a mystic loaf.");
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
