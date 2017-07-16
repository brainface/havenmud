#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
  meal::create();
  SetKeyName("poison");
  SetId( ({"poison","potion","vial","poison vial"}) );
  SetAdjectives( ({"poison","vial"}) );
  SetShort("a small vial of blue liquid");
  SetMass(5);
  SetProperty("magic" ,
    "This strange blue liquid appears to be a poison.");
  SetLong("The vial has a small rubber stopper pressed tight into it, "
    "keeping a blue liquid sealed inside.");
  SetMealType(MEAL_DRINK|MEAL_POISON);
  SetStrength(500);
  SetMealMessages("You drink from the vial.","$N drinks from a "
    "vial containing a blue liquid.");
  SetEmptyName("vial");
  SetEmptyShort("an empty vial");
  SetEmptyLong("It's an empty vial.");
}
