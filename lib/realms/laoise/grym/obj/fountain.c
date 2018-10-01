#include <lib.h>
#include <meal_types.h>
#include "../grymxoria.h"
inherit LIB_MEAL;

static void create() {
  meal::create();
  SetKeyName("fountain");
  SetShort("the Grymxoria Fountain");
  SetLong(
    "This is the fountain of Grymxoria. "
    "Here the sacred and pure water of the Blood "
    "River is piped up for all to drink."
  );
  SetMealType(MEAL_DRINK);
  SetPreventGet("You cannot take the fountain.");
  SetEmptyItem(G_OBJ + "fountain");
  SetPortions(-1);
  SetStrength(15);
  SetMealMessages( ({ 
    "The water tastes of minerals.", 
    "$N drinks from a fountain.", 
  }) );
}
