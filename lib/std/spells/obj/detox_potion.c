#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
  meal::create();
  SetKeyName("potion of detoxification");
  SetId( ({"potion","potion of detoxification"} ));
  SetAdjectives( ({"blue","thick","heavy","detoxification"}));
  SetShort("a thick blue potion");
  SetMass(4);
  SetProperty("magic" ,
              "The dark blue potions appears to be a potion of detoxification.");
  SetLong("The bottle is corked and filled with a heavy blue "
          "liquid that appears to be very thick. ");
  SetMealType(MEAL_ALCOHOL|MEAL_DRINK);
  SetStrength(-13);
  SetMaterial( ({ "natural" }) );
  SetValue(0);
  SetMealMessages("You drink from the bottle.","$N drinks from a "
                  "bottle containing a heavy blue potion.");
  SetEmptyName("potion");
  SetEmptyShort("an empty potion");
  SetEmptyLong("It's an empty bottle.");
}
