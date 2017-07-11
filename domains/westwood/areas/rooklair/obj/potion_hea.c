#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
  meal::create();
  SetKeyName("healing potion");
  SetId( ({"potion","healing potion"} ));
  SetAdjectives( ({"green","watery","healing"}));
  SetShort("a watery green potion");
  SetMass(4);
  SetProperty("magic" ,
    "The watery potion appears to be a healing potion.");
  SetLong("The bottle is corked and filled with a watery green "
    "liquid that appears to be very thin. ");
  SetMealType(MEAL_DRINK);
  SetStrength(10);
  SetMealMessages("You drink from the bottle.","$N drinks from a "
    "bottle containing a watery green potion.");
  SetEmptyName("potion");
  SetEmptyShort("an empty potion");
  SetEmptyLong("It's an empty bottle.");
}

mixed eventDrink(object who) {
  who->AddHealthPoints(random(150));
  return meal::eventDrink(who);
}
