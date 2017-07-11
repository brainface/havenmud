#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
  meal::create();
  SetKeyName("poison antidote");
  SetId( ({"antidote","poison antidote","potion"} ));
  SetAdjectives( ({"yellow","thick","heavy","antidote"}));
  SetShort("a thick yellow potion");
  SetMass(4);
  SetProperty("magic" ,
    "The dark yellow potions appears to be a poison antidote.");
  SetLong("The bottle is corked and filled with a heavy yellow "
    "liquid that appears to be very thick. ");
  SetMealType(MEAL_DRINK|MEAL_POISON);
  SetStrength(-100);
  SetMealMessages("You drink from the bottle.","$N drinks from a "
    "bottle containing a heavy yellow potion.");
  SetEmptyName("potion");
  SetEmptyShort("an empty potion");
  SetEmptyLong("It's an empty bottle.");
}
