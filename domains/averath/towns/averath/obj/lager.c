/* A mud of Lager
   Coded by Kilik
*/

#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create(){
  meal::create();    SetKeyName("lager");
  SetId( ({ "mug","lager" }) );
  SetAdjectives( ({ "dark lager" }) );
  SetShort("a mug of dark lager");
  SetStrength(25);
  SetMass(5);
  SetValue(5);
  SetLong("This is a tall mug of dark lager.");
  SetMealType(MEAL_DRINK | MEAL_ALCOHOL);
  SetMealMessages("You chug a mug of lager.",
                  "$N chugs a mug of lager.");
  SetEmptyName("mug");    SetEmptyShort("an empty mug");
  SetEmptyLong("It is an empty mug.");
}
