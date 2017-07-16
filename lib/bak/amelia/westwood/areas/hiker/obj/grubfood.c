#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
   meal::create();
   SetKeyName("ugly dead grub");
   SetShort("an ugly dead grub");
   SetId( ({ "grub","thing" }) );
   SetAdjectives( ({ "ugly","dead","fat","squishy","dirty","white" }) );
   SetLong("The grub is fat and squishy and just a little bit dirty too.  "
           "The white thing is wrinkly and could almost be a tasty "
           "snack--if you were half starved.");
   SetMass(2);
   SetMealType(MEAL_FOOD);
   SetStrength(3);
   SetMealMessages("You blanch slightly while swallowing the single "
                   "grub.  You'd have to eat a lot to fill up.",
                   "$N eats a grub.");
}
