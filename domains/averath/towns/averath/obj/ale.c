/* A stein of ale
   Coded by Kilik
*/

#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create(){
  meal::create();
  SetKeyName("ale");
  SetId( ({ "stein","ale" }) );
  SetAdjectives( ({ "light ale" }) );
  SetShort("a stein of light ale");
  SetStrength(20);
  SetMass(5);
  SetValue(5);
  SetLong("This is a stout stein of ale.");
  SetMealType(MEAL_DRINK | MEAL_ALCOHOL);
  SetMealMessages("You gulp down a stein of ale.",
                  "$N makes a mess of their shirt "
                  "downing a stein of ale.",);
  SetEmptyName("stein");
  SetEmptyShort("an empty stein");
  SetEmptyLong("It is an empty stein.");
}
