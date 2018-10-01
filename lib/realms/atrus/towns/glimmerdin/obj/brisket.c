 /* 
  * food
  * balishae 1997
  * added to newglim by Duhoc on Jan. 99
  */
#include <lib.h>
#include <meal_types.h>

inherit LIB_MEAL;

static void create() {
    meal::create();
    SetKeyName("beef brisket");
    SetId( ({ "brisket" }) );
    SetAdjectives( ({ "beef", "meaty" }) );
    SetShort("a huge beef brisket");
    SetLong("Several inches think and covering an entire plate, the "
            "brisket looks like it would feed a party of adventurers.");
    SetMass(15);
    SetMealType(MEAL_FOOD);
    SetValue(20);
    SetStrength(75);
    SetMealMessages("The people around you are amazed as you gorge yourself " 
                    "on the beef brisket.",
										    "$N eats an entire beef brisket before your eyes.  What a pig!");
}
