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
  SetKeyName("tuna steak");
  SetId( ({ 
    "steak"
  }) );
  SetAdjectives( ({ 
    "seared", "tuna"
  }) );
  SetShort("a seared tuna steak");
  SetLong(
    "This is seared tuna steak. "
    "the outer skin is seared and seasoned while "
    "the inner portion is still raw."
  );
  SetMass(20);
  SetMealType(MEAL_FOOD);
  SetStrength(100);
  SetPortions(5);
  SetMealMessages(
    "The seared tuna is delicious!",
    "$N perks up after eating some seared tuna steak.");
}
