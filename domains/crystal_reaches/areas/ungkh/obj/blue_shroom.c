//--  Torak  --//
//-- 5/28/99 --//

#include <lib.h>
#include <meal_types.h>

inherit LIB_MEAL;

static void create() {

  meal::create();
  SetKeyName("mushroom");
  SetShort("a striped orange mushroom");
  SetId( ({ 
    "mushroom",
    }) );
  SetAdjectives( ({ 
    "striped", "orange"
    }) );
  SetMealType(MEAL_FOOD|MEAL_CAFFEINE);
  SetLong("This small striped orange mushroom was grown in Ungkh.  "
          "Dispite its dirty appearance, it looks good to eat.");
  SetMass(2);
  SetStrength(20+random(10)+random(5));
  SetMealMessages(
    "What an odd taste."
    );
  }
