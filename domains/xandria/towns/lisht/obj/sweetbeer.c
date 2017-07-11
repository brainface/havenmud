//Selket@Haven
//2006
#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
  meal::create();
  SetKeyName("sweet beer");
  SetId( ({ "cup", "beer"}) );
  SetShort("a cup of sweet beer");
  SetLong(
    "The beer looks a little scummy, but it smells "
    "pretty tasty.");
  SetMass(20);
  SetMealType(MEAL_DRINK | MEAL_ALCOHOL);
  SetStrength(35);
  SetMealMessages("You drink a sweet, warming cup of beer.",
                    "$N drinks a sweet, warming cup of beer.");
  SetEmptyName("cup");
  SetEmptyShort("an empty beer cup");
  SetEmptyLong("You feel compelled to buy more beer.");
}
