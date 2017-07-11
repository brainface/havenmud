#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
  meal::create();
  SetKeyName("fountain");
  SetShort("the Blood Fountain");
  SetLong(
    "This is the blood fountain of Grymxoria. Here the sacred "
    "and pure water of the Blood River is piped up for all to "
    "drink."
  );
  SetMealType(MEAL_DRINK);
  SetPortions(-1);
  SetStrength(15);
  SetPreventGet("You cannot take the fountain.");
  SetEmptyItem("/domains/grymxoria/obj/fountain");
  SetMealMessages( ({ 
    "The water tastes of minerals.", 
    "$N drinks from a fountain.", 
  }) );
}
