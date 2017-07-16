#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
   meal::create();
   SetKeyName("rations");
   SetShort("a piece of trail rations");
   SetId( ({ "snack","rations","piece" }) );
   SetAdjectives( ({ "piece of","trail""power" }) );
   SetLong("This lump of brown something with lumps of other bland "
           "colors stuck in it does not look very appealing, but it "
           "is probably very healthy and filling.");
   SetMass(10);
   SetMealType(MEAL_FOOD);
   SetStrength(60);
   SetMealMessages("$N manage to consume the trail rations and get a "
                   "burst of energy from it.","$N eats some trail rations.");
}

int eventEat(object who) {
  who->AddCaffeine(10);
   ::eventEat(who);
}
