#include <lib.h>
#include <meal_types.h>

inherit LIB_MEAL;

static void create() {
  meal::create();
  SetShort("an ugly cake made of mud and twigs");
  SetId("cake");
  SetAdjectives( ({ "ugly" }) );
  SetKeyName("cake");
  SetLong("This cake was made in the playground somewhere."
          " It is made of mud and twigs. It looks disgusting.");
  SetStrength(80);
  SetMealType(MEAL_FOOD);
  SetMass(10);
  }
