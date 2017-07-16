#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
  meal::create();
  SetKeyName("pool");
  SetShort("a shallow pool of thick liquid");
  SetMealType(MEAL_DRINK);
  SetLong(
    "This shallow pool of liquid is thick and coppery. After quick "
    "review, it is a pool of gnomish blood!"
    );
  SetPreventGet("The pool is splattered on the floor.");
  SetPortions(3);
  SetStrength(15);
  SetMealMessages( ({ 
  	"$N sip up some liquid from the pool.", 
    "$N sips up some liquid from the pool.", 
    }) );
  SetSmell("The pool smells coppery, like blood.");
  SetTouch("The liquid is thick and coagulated.");  
}
