#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;
inherit LIB_SMELL;

static void create() {
   meal::create();
   SetKeyName("juice bottle");
   SetShort("a juice bottle");
   SetId( ({ "bottle","juice" }) );
   SetAdjectives( ({ "juice","pint","semi-transparent" }) );
   SetLong("The juice swirls around in its semi-transparent bottle.  "
           "The pint bottle is about three quarters full.");
   SetMass(20);
   SetStrength(20);
   SetMealType(MEAL_DRINK);
   SetMealMessages("The juice tastes fruity.",
                   "$N drinks some juice.");
   switch(random(16)) {
      case 0:
      SetMealType(MEAL_ALCOHOL|MEAL_DRINK);
      SetSmell("Something about the juice smells slightly off, like "
               "a wine.");
      SetMealMessages("The juice has a strange, alcohol-like taste to "
                      "it.","$N looks surprised while consuming some "
                      "juice.");
      break;
      case 1..15:
      SetSmell("The juice smells fruity, kind of like apples.");
      break;
   }
}
mixed direct_smell_obj() {
   return smell::direct_smell_obj();
}
