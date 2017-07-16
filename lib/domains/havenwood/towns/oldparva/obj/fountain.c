// Amelia@Haven

#include <lib.h>
inherit LIB_MEAL;
#include <meal_types.h>
#include "parva.h"
 
static void create() {
   meal::create();
   SetKeyName("fountain");
   SetId( ({ "fountain" }) );
   SetAdjectives( ({ "dusty" }) );
   SetShort("a dusty fountain");
   SetMealType(MEAL_DRINK);
   SetLong("This fountain is plain and rather dusty.  The water "
           "looks just fine..");
   SetPreventGet("The fountain is firmly attached to the ground.");
   SetPortions(-1);
   SetStrength(25);
   SetMealMessages( ({ "You drink from the fountain.",
                   "$N drinks from the fountain." }) );
}
