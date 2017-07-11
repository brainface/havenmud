#include <lib.h>
#include <meal_types.h>

inherit LIB_MEAL;

static void create() {
    meal::create();
    SetKeyName("boot broth");
    SetId( ({ "broth", "bowl" }) );
    SetAdjectives( ({"bowl", "of", "boot" }) );
    SetShort("a bowl of boot broth");
    SetLong(
      "This \"soup\" looks more like ditch runoff and smells like "
      "dead cat. Something floating in it looks suspiciously "
      "like boot heel."
    );
    SetMass(12);
    SetMealType(MEAL_FOOD);
    SetStrength(50);
    SetValue(0);
    SetMealMessages("It tastes like old people.",
                    "$N forces some vile, muddy liquid down.");
}


