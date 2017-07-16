#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
   meal::create();
   SetKeyName("fillet");
   SetShort("a fillet of king salmon");
   SetId( ({ "fillet","salmon" }) );
   SetAdjectives( ({ "fillet of","king","salmon" }) );
   SetLong("The king salmon fillet sits on a plain plate.  "
           "A brown sauce that almost sparkles is drizzled "
           "across it.");
   SetMass(15);
   SetStrength(100);
   SetMealType(MEAL_FOOD);
   SetMealMessages("$N eat a king salmon fillet.",
                   "$N eats a fillet of king salmon.");
}
