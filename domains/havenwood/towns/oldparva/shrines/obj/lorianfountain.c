#include <lib.h>
#include <meal_types.h>
#include "../parva.h"
inherit LIB_MEAL;

static void create() {
   ::create();
   SetKeyName("fountain");
   SetShort("a marble fountain");
   SetId( ({ "fountain" }) );
   SetAdjectives( ({ "marble" }) );
   SetLong("The marble fountain is full of crystal-clear water that burbles out "
           "from a group of unicorns' horns.  The unicorns stand in the center "
           "of the fountain, proud and beautiful in their glory.  The unicorns "
           "seem to sparkle in the light.");
   SetStrength(20);
   SetPreventGet("Yeah right.  You aren't taking this fountain.");
   SetMealType(MEAL_DRINK);
   SetEmptyItem(PS_OBJ + "/lorianfountain");
   SetMealMessages("You bend over and drink from the water trickling from a horn "
                   "near the edge of the fountain.  The water tastes pure and "
                   "refreshing.","$N drinks from the fountain.");
}
