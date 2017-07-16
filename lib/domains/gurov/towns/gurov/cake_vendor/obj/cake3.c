//Illura@Haven
//June 2009
#include <lib.h>
#include <meal_types.h>
#include "../cake.h"
inherit LIB_MEAL;
inherit LIB_SMELL;

static void create() {
   meal::create();
   SetKeyName("lunaberry cake");
   SetShort("a heavenly hunk of lunaberry cake");
   SetId( ({ "cake", "hunk", }) );
   SetAdjectives( ({ "heavenly", "lunaberry" }) );
   SetLong("The dark chocolate cake contains hundreds "
           "of tiny non-pereil purple berries. A strange "
           "shadow makes it hard for you to focus on "
           "the cake, but it is probably still delicious.");
   SetMass(1);
   SetMaterial("natural");
   SetMealType(MEAL_FOOD);
   SetStrength(10);
  SetMealMessages("The darker the berry, the sweeter the juice.",
                   "$N finishes off a piece of cake.");
   SetSmell("The lunaberry cake smells piquant and sweet.");
}

mixed direct_smell_obj() {
   return smell::direct_smell_obj();
}
