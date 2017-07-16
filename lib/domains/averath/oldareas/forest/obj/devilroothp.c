// Amelia
// Herb to heal hp
#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
   ::create();
   SetKeyName("oxnee");
   SetShort("a piece of devil's club root");
   SetId( ({ "root" }) );
   SetAdjectives( ({ "piece of","devil's","club" }) );
   SetLong("Creamy white in color, this small piece of "
           "devil's club root is very fibrous.");
   SetMass(1);
   SetMealType(MEAL_FOOD);
   SetStrength(1);
   SetMealMessages("You chew slowly on the root, wincing at the bitter taste.",
                   "$N chews on a piece of devil's club root.");
}

mixed eventEat(object who) {
   who->AddHealthPoints(5);
   who->eventPrint("You feel healthier!");
   return ::eventEat(who);
}

int GetValue() {
   return 10;
}
