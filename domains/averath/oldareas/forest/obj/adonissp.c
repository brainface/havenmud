// Amelia
// herb to heal sp
#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
   ::create();
   SetKeyName("adonis");
   SetShort("a petal of adonis");
   SetId( ({ "petal","adonis" }) );
   SetAdjectives( ({ "petal of","adonis" }) );
   SetLong("The delicate petal is the color of dried blood.");
   SetMass(1);
   SetMealType(MEAL_FOOD);
   SetStrength(1);
   SetMealMessages("The petal melts in your mouth.",
                   "$N eats a petal.");
}

mixed eventEat(object who) {
   who->AddStaminaPoints(5);
   who->eventPrint("You feel refreshed.");
   return ::eventEat(who);
}

int GetValue() {
   return 25;
}
