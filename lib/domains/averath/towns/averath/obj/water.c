/* A glass of water
   Coded by Kilik
*/

#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create(){
  meal::create();
  SetKeyName("water");
  SetId( ({ "glass","water" }) );
  SetAdjectives( ({ "water" }) );
  SetShort("a tall glass of water");
  SetStrength(30);
  SetMass(5);
  SetValue(5);
  SetLong("This is a tall thin glass of water.");
  SetMealType(MEAL_DRINK);
  SetMealMessages("You drink a glass of water.",
                  "$N drinks a glass of water.",);
  SetEmptyName("glass");
  SetEmptyShort("a tall glass");
  SetEmptyLong("It is an empty glass.");
}
