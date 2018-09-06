#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
  meal::create();
  SetKeyName("cookie");
  SetId( ({ "cookie" }) );
  SetAdjectives( ({ "chocolate", "chip" }) );
  SetShort("a chocolate chip cookie");
  SetMass(10);
  SetLong("This is a HUUUGE chocolate chip cookie. It looks fresh baked.");
  SetMealType(MEAL_FOOD);
  SetPortions(2);
  SetStrength(50);
  SetMealMessages("You chew noisily on the cookie.  It's warm and chocolatey.",
                  "$N chews noisily on a chocolate chip cookie.");
}


