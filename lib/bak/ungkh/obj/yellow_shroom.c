//--  Torak  --//
//-- 5/28/99 --//

#include <lib.h>
#include <meal_types.h>

inherit LIB_MEAL;

static void create() {

  meal::create();
  SetKeyName("mushroom");
  SetShort("a bright yellow mushroom");
  SetId( ({ 
    "mushroom",
    }) );
  SetAdjectives( ({ 
    "bright", "yellow"
    }) );
  SetMealType(MEAL_FOOD|MEAL_POISON);
  SetLong("This small bright yellow mushroom was grown in Ungkh.  "
          "Dispite its dirty appearance, it looks good to eat.");
  SetMass(2);
  SetStrength(20+random(10)+random(5));
  SetMealMessages(
    "What an odd taste."
    );
  }
