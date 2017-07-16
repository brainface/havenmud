#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
  meal::create();
  SetKeyName("fountain");
  SetShort("a fountain");
  SetMealType(MEAL_DRINK);
    SetLong("This is the local fountain.  It is a good place for the "
    "citizens of Argoth to relax and get a cool, refreshing drink.");
  SetPreventGet("You cannot take the fountain.");
  SetEmptyItem("/domains/crystal_reaches/areas/argoth/obj/fountain");
  SetStrength(45);
  SetPortions(-1);
  SetMealMessages( ({ "$N drink from a fountain.", 
                  "$N drinks from a fountain.", 
                }) );
 }
