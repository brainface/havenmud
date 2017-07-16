// Amelia
// Herb to heal poisons
#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
   ::create();
   SetKeyName("neem");
   SetShort("a hunk of neem bark");
   SetId( ({ "hunk","bark","neem" }) );
   SetAdjectives( ({ "bark","neem","hunk of" }) );
   SetLong("Dark and rough, the neem bark is covered in a stick resin.");
   SetMass(1);
   SetMealType(MEAL_FOOD);
   SetStrength(1);
   SetMealMessages("The bark has an acrid taste.",
                   "$N eats a hunk of bark.");
}

mixed eventEat(object who) {
   who->AddPoison(-5);
   who->eventPrint("You feel purified.");
   return ::eventEat(who);
}

int GetValue() {
   return 45;
}
