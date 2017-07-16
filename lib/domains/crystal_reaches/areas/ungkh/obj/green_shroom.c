//--  Torak  --//
//-- 5/28/99 --//

#include <lib.h>
#include <meal_types.h>

inherit LIB_MEAL;

static void create() {

  meal::create();
  SetKeyName("mushroom");
  SetShort("a spotted green mushroom");
  SetId( ({ 
    "mushroom",
    }) );
  SetAdjectives( ({ 
    "spotted", "green"
    }) );
  SetMealType(MEAL_FOOD);
  SetLong("This small spotted green mushroom was grown in Ungkh.  "
          "Dispite its dirty appearance, it looks good to eat.");
  SetMass(2);
  SetStrength(20+random(10)+random(5));
  SetMealMessages(
    "What an odd taste."
    );
  }
