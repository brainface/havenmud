#include <lib.h>
#include <meal_types.h>

inherit LIB_MEAL;
int eventDecay();

static void create() {
    meal::create();
    SetKeyName("mystic loaf");
    SetId( ({ "loaf", "bread" }) );
   SetAdjectives( ({ "mystic", "warm" }) );
    SetShort("a mystic loaf of warm bread");
    SetLong("This delectable looking loaf was created "
            "magically.  It looks absolutely delicious!");
    SetMass(12);
    SetMealType(MEAL_FOOD);
    SetStrength(50);
    SetMealMessages("The loaf fills your tummy.",
                    "$N tears into a mystic loaf.");
  call_out( (: eventDecay :), 240 );
}


int eventDecay() {
    if (!environment()) { eventDestruct(); return 0; }
  message("food_action",
     "A mystic loaf decays into nothingness.",
      environment() );
    eventDestruct();
    return 1;
  }
