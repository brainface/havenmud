//--  Torak  --//
//-- 5/28/99 --//

#include <lib.h>
#include <meal_types.h>

inherit LIB_MEAL;

string COLOR_SHROOM;
string COLOR;
int FOOD_TYPE;

static void create() {

  meal::create();

  switch(random(3)) {

    case 0:
    COLOR_SHROOM = "dark red mushroom";
    COLOR = "red";
    FOOD_TYPE = MEAL_FOOD|MEAL_POISON;
    break;

    case 1:
    COLOR_SHROOM = "bright yellow mushroom";
    COLOR = "yellow";
    FOOD_TYPE = MEAL_FOOD;
    break;

    case 2:
    COLOR_SHROOM = "spotted blue mushroom";
    COLOR = "blue";
    FOOD_TYPE = MEAL_FOOD|MEAL_ALCOHOL;
    break;

    case 3:
    COLOR_SHROOM = "striped orange mushroom";
    COLOR = "orange";
    FOOD_TYPE = MEAL_FOOD|MEAL_CAFFEINE;
    break;
    
    }

  SetKeyName("mushroom");
  SetShort("a " + COLOR_SHROOM);
  SetId( ({ 
    "mushroom",
    }) );
  SetAdjectives( ({ 
    }) );
  SetMealType(FOOD_TYPE);
  SetLong("This small " + COLOR_SHROOM + "was grown in Ungkh.  "
          "Dispite its dirty appearance, it looks good to eat.");
  SetMass(2);
  SetStrength(10+random(10)+random(5));
  SetMealMessages(
    "What an odd taste."
    );
  }
