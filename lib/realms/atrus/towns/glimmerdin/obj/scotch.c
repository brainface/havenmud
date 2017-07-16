#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create()
{
  meal::create();
  SetKeyName("scotch");
  SetId( ({ "shot","glass","scotch","glass of scotch" }) );
  SetAdjectives( ({ "shot","scotch","small","short","empty" }) );
  SetShort("a short glass of scotch");
  SetMass(1);
  SetValue(3);
  SetLong("This small glass is filled with scotch.");
  SetMealType(MEAL_DRINK | MEAL_ALCOHOL);
  SetStrength(17);
  SetMealMessages("You drink the short glass of scotch.",
                  "$N drinks a shot glass of scotch.");
  SetEmptyName("glass");
  SetEmptyShort("an empty shot glass");
  SetEmptyLong("This is small shot glass.");
}
