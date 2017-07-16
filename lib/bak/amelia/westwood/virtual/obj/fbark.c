#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;
inherit LIB_SMELL;
inherit LIB_TOUCH;

static void create() {
   meal::create();
   SetKeyName("fenfir bark");
   SetShort("a sliver of fenfir bark");
   SetId( ({"bark","fenfir bark","sliver of bark","sliver of fenfir bark"}) );
   SetAdjectives( ({ "fenfir" }) );
   SetLong("This is a small sliver of fenfir bark.  It is white and "
     "smotted with small streaks of brown.");
   SetMass(2);
   SetMealType(MEAL_FOOD);
   SetStrength(12);
   SetMealMessages("The bark crunches softly as you eat it.",
                   "$N crunches on some fenfir bark.");
   SetTouch("The bark is smooth to touch.");
   SetSmell("The bark smells like fenfir.");
}

mixed direct_smell_obj() {
   return smell::direct_smell_obj();
}
