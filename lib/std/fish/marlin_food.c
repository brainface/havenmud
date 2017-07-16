#include <lib.h>
#include <meal_types.h>

inherit LIB_MEAL;

static void create() {
    meal::create();
    SetKeyName("marlin");
    SetId( ({ "marlin","fish" }) );
    SetAdjectives( ({ "blue" }) );
    SetShort("a blue marlin");
    SetLong("This blue marlin is a beautiful sapphire color with a pure white underbelly. "
            "A long grassy hued stripe runs down its body almost as if it was painted on. "
            "It looks like it would make an excelent meal.");
    SetMass(350);
    SetMealType(MEAL_FOOD);
    SetStrength(80);
  SetValue(700);
    SetMealMessages("It tastes excellent.", "$N eats a blue marlin.");
}
