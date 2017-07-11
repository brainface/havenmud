// Amelia
// Herb to heal mp
#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
   ::create();
   SetKeyName("oxknee");
   SetShort("a leaf of oxknee");
   SetId( ({ "leaf","oxknee" }) );
   SetAdjectives( ({ "leaf of","oxknee" }) );
   SetLong("The leaf has a pale, new color.");
   SetMass(1);
   SetMealType(MEAL_FOOD);
   SetStrength(1);
   SetMealMessages("The leaf is tender and sweet.",
                   "$N eats a leaf.");
}

mixed eventEat(object who) {
   who->AddMagicPoints(5);
   who->eventPrint("You feel refreshed.");
   return ::eventEat(who);
}

int GetValue() {
   return 25;
}
