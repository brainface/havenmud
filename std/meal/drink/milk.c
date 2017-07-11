// Amelia@Haven

#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
   meal::create();
   SetKeyName("milk");
   SetShort("a cup of milk");
   SetId( ({ "cup of milk","milk","cup" }) );
   SetLong("This tall glass of cool, refreshing milk looks very good.");
   SetMass(5);
   SetMealType(MEAL_DRINK);
   SetStrength(10);
   SetMealMessages("You drink the tall glass of milk.  It's still fresh!",
                   "$N drinks some milk.");
   SetEmptyName("empty cup");
   SetEmptyShort("an empty cup");
   SetEmptyLong("This is an empty cup that looks to have held milk once "
                "in he past.");
}
