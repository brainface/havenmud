#include <lib.h>
#include <meal_types.h>
#include "parva.h"
inherit LIB_MEAL;

static void create() {
   meal::create();
   SetKeyName("beer");
   SetShort("a mug of beer");
   SetId( ({ "mug","beer" }) );
   SetAdjectives( ({ "mug of","beer" }) );
   SetLong("The beer is in a dark brown mug.  It doesn't appear "
           "to be flat or unappetizing to a normal beer drinker.");
   SetMass(15);
   SetStrength(25);
  SetMealType(MEAL_DRINK|MEAL_ALCOHOL);
   SetMealMessages("$N gulp down the mug of beer.",
                   "$N drinks a mug of beer.");
   SetEmptyItem(P_OBJ + "/mug");
}
