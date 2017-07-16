/* A glass of whiskey
   Coded by Kilik
*/

#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create(){
  meal::create();
  SetKeyName("whiskey");
  SetId( ({ "glass","whiskey" }) );
  SetAdjectives( ({ "heavy whiskey" }) );
  SetShort("a glass of heavy whiskey");
  SetStrength(50);
  SetMass(5);
  SetValue(5);
  SetLong("This is a short glass of whiskey.");
  SetMealType(MEAL_DRINK | MEAL_ALCOHOL);
  SetMealMessages("You shoot a glass of whiskey.",
                  "$N hiccups after a shot of whiskey.",);
  SetEmptyName("glass");
  SetEmptyShort("an empty glass");
  SetEmptyLong("It is an empty glass.");
}
