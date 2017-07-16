//--  Torak  --//
//-- 5/28/99 --//

#include <lib.h>
#include <meal_types.h>

inherit LIB_MEAL;

static void create() {

  meal::create();
  SetKeyName("mushroom");
  SetShort("a dark red mushroom");
  SetId( ({ 
    "mushroom",
    }) );
  SetAdjectives( ({ 
    "red", "dark"
    }) );
  SetMealType(MEAL_FOOD|MEAL_ALCOHOL);
  SetLong("This small dark red mushroom was grown in Ungkh.  "
          "Dispite its dirty appearance, it looks good to eat.");
  SetMass(2);
  SetStrength(20+random(10)+random(5));
  SetMealMessages(
    "What an odd taste."
    );
  }
