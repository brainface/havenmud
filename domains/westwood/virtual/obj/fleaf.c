#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;
inherit LIB_SMELL;
inherit LIB_TOUCH;

static void create() {
   meal::create();
   SetKeyName("fenfir leaf");
   SetShort("a fenfir leaf");
   SetId( ({"leaf","fenfir leaf"}) );
   SetAdjectives( ({ "fenfir" }) );
   SetLong("This is a large leaf from a fenfir tree.  It is green "
     "and very large.");
   SetMass(2);
   SetMealType(MEAL_FOOD);
   SetStrength(35);
   SetMealMessages("The leaf tastes slightly sweet.",
                   "$N chews on a fenfir leaf.");
   SetTouch("The leaf is slightly fuzzy.");
   SetSmell("The leaf smells like fenfir.");
}

mixed direct_smell_obj() {
   return smell::direct_smell_obj();
}
