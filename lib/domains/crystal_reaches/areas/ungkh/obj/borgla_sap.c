//-- Torak@Haven --//
//Fixed typo

#include <lib.h>
#include <meal_types.h>

inherit LIB_MEAL;

static void create() {
  meal::create();
  SetKeyName("sap");
  SetShort("a mug of borgla sap");
  SetId( ({"mug","sap"}) );
  SetMass(15);
  SetLong("Made from the sap of the great Borgla Tree, this "
          "ale has been known to deliver quite a punch.");
  SetStrength(100);
  SetMealType(MEAL_DRINK|MEAL_ALCOHOL); 
  SetMealMessages(
    "The sap slowly oozes down your throat, enthusiastically "
    "adding life to each area it touches.",
    "$N chugs from the mug, gagging slightly."
    );
  }
