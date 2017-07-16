#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
  meal::create();
  SetKeyName("rum");
  SetShort("a bottle of rum");
  SetId( ({ "bottle", "rum" }) );
  SetAdjectives( ({ "rum", "bottle", "of" }) );
  SetMealType(MEAL_DRINK|MEAL_ALCOHOL);
  SetLong("This bottle of rum appears to be mostly consumed and "
          "cannot possibly be healthy.");
  SetStrength(35);
  SetMealMessages( ({ 
    "$N drink from a bottle of rum.", 
    "$N drinks from a bottle of rum.", 
    }) );
}
