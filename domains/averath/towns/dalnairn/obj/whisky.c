// Dalnairn
// Aerelus

#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create()
{
  meal::create();
  SetKeyName("whisky");
  SetId( ({ "glass", "whisky", "glass of whisky" }) );  
  SetShort("a large glass of whisky");
  SetLong(
    "This large glass is filled with some of the infamous Duergar "
    "whisky, distilled in the city of Dalnairn."
  );
  SetAdjectives( ({ "large", "whisky", "empty" }) );
  
  SetMass(15);
  SetValue(-1);  
  SetMealType(MEAL_DRINK | MEAL_ALCOHOL);
  SetStrength(80);
  SetMealMessages("The whisky warms your throat as you drink it.",
                  "$N drinks a large glass of whisky.");
  SetEmptyName("glass");
  SetEmptyShort("an large empty glass");
  SetEmptyLong("This is large empty glass.");
}
