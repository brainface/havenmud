// 
// Dalnairn Total Recode
// Torak@Haven 2014-2017
// Restaurant Foods
//

#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
  ::create();
  SetKeyName("brandy");
  SetId( ({ 
    "snifter", "brandy", "bell", "shaped", "glass" 
  }) );
  SetAdjectives( ({ 
    "snifter", "brandy", "of", "bell", "shaped" 
  }) );
  SetShort("a snifter of brandy");
  SetMass(15);
  SetValue(-1);
  SetLong("This snifter is an upturned bell shaped glass. "
          "Brandy fills the lower half of the bell.");
  SetMealType(MEAL_DRINK | MEAL_ALCOHOL);
  SetStrength(50);
  SetMealMessages(
    "You drink the snifter of brandy.",
    "$N drinks a snifter of brandy."
  );
  SetEmptyName("glass");
  SetEmptyShort("an empty snifter glass");
  SetEmptyLong("This is small snifter glass.");
}
