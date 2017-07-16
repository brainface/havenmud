#include <lib.h>
#include <meal_types.h>

inherit LIB_MEAL; 

static void create() {
  ::create();
  SetKeyName("beer");
  SetShort("a mug of beer");
  SetId( ({ "beer" }) );
  SetAdjectives( ({"tanish","liquid" }) );
  SetStrength(5);
  SetMealType(MEAL_DRINK|MEAL_ALCOHOL);
  SetLong("This is a tanish liquid that has a "
          "fair amount of alcoholic properties.");
  SetMass(1);
  }
