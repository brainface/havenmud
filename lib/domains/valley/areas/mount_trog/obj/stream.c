#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
  meal::create();
  SetKeyName("rivulet");
  SetId( ({ "rivulet", "stream" }) );
  SetAdjectives( ({ "tiny" }) );
  SetShort("a tiny rivulet of water");
  SetMealType(MEAL_DRINK);
  SetInvis(1);
  SetLong(
    "This tiny flow of water seems to head all to the south."
    );
  SetPreventGet("The water runs quickly out of your fingers.");
  SetPortions(-1);
  SetStrength(5);
  SetMealMessages( ({ 
  	"$N sip up some water from the stream.", 
    "$N sips up some water from the stream.", 
    }) );
}
