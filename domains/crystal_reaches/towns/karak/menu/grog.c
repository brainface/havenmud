// Karak Rewrite
// Laoise
// 2007

#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
  meal::create();
  SetKeyName("grog");
  SetId( ({ "orcish grog", "grog" }) );
  SetAdjectives( ({ "orcish" }) );
  SetShort("a cup of orcish grog");
  SetLong(
    "This thick, green liquid looks as sickening as any drink that "
    "has ever been conceived. It has unidentifiable chunks floating "
    "in it, and darker shadows suggesting objects in its depths. It "
    "would take firm resolve to be able to down this drink."
  );
  SetMass(20);
  SetMealType(MEAL_DRINK|MEAL_ALCOHOL);
  SetStrength(45);
  SetMealMessages(
    "You slurp up the thick, chunky orcish grog. It tastes "
    "disgusting.",  
    "$N chokes down an entire mug of grog with ghastly "
    "slurping noises."
  );
}
