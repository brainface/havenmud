#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;
inherit LIB_SMELL;
inherit LIB_TOUCH;

static void create() {
   meal::create();
   SetKeyName("honeysuckle flower");
   SetShort("a honeysuckle flower");
   SetId( ({"flower","honeysuckle flower"}) );
   SetAdjectives( ({ "honeysuckle" }) );
   SetLong("This is a tiny white honeysuckle flower.");
   SetMass(2);
   SetMealType(MEAL_DRINK);
   SetStrength(18);
   SetMealMessages("The honeysuckle taste sweet.",
                   "$N sucks on the end of a honeysuckle.");
   SetTouch("The flower is smooth.");
   SetSmell("The flower smells sweet.");
}

mixed direct_smell_obj() {
   return smell::direct_smell_obj();
}
