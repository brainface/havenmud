// Torak@Haven - 2/27/15 //


#include <lib.h>
#include <meal_types.h>

inherit LIB_MEAL;

 static void create() {
  ::create();
  SetKeyName("milk");
  SetId( ({ "milk", "cup" }) );
  SetShort("a ceramic cup of milk");
  SetLong(
    "This is a cup of raw milk.  The ceramic cup containing "
    "it is solid and painted white with delicate blue flowers. "
  );
  SetMealType(MEAL_DRINK);
  SetStrength(30);
  SetMealMessages(
    "Mmmm.  Raw milk.",
  );
  SetEmptyName("cup");
  SetEmptyShort("an empty ceramic cup");
  SetEmptyLong(
    "The ceramic cup is solid and painted white with delicate "
    "blue flowers. "
  );
}
