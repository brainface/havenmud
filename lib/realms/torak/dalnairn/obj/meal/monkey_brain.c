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
  SetKeyName("monkey brain");
  SetId( ({ 
    "brain", "skull"
  }) );
  SetAdjectives( ({ 
    "monkey", "brain", "in"  
  }) );
  SetShort("a monkey brain in skull");
  SetLong(
    "This is a seasoned monkey brain served inside its own skull."
  );
  SetMass(8);
  SetMealType(MEAL_FOOD);
  SetStrength(60);
  SetPortions(3);
  SetMealMessages(
    "The monkey brain is delicious!",
    "$N perks up after eating some monkey brains from a skull.");
  SetEmptyName("skull");
  SetEmptyShort("an empty monkey skull");
  SetEmptyLong("It is an empty monkey skull that once held some seasoned brains.");
}
