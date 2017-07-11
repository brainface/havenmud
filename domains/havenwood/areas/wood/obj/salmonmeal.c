//coded by Syra 8/97

#include <lib.h>
#include <meal_types.h>

inherit LIB_MEAL;

static void create() {
    ::create();
    SetKeyName("salmon");
    SetShort("a silver salmon");
    SetStrength(30);
    SetMass(20);
    SetId( ({ "salmon", "fish" }) );
    SetAdjectives( ({ "silver","shimmery","speckled","dotted" }) );
    SetLong("It is has a shimmery silver color speckled "
            "with black dots along its underside.");
    SetMealMessages("It slides easily down your throat.", 
                    "$N eats a silver salmon.");
    SetMealType(MEAL_FOOD);
    SetValue(30);    
}


/* Approved by Amelia on Sun Sep 14 19:51:17 1997. */