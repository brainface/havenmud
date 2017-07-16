#include "../ungkh.h"
#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
  meal::create();

  SetKeyName("meat");
  SetShort("a chewy chunk of meat");
  SetId( ({
    "chunk","meat"
    }) );
  SetAdjectives( ({
    "chewy","dirty",
    }) );

  SetLong("The chunk of meat looks like it will feed those "
          "desperate enough fools to eat anything.  It is filled "
          "with maggots and looks rotten.");

  SetMealType(MEAL_FOOD);
  SetStrength(13+random(4));
  SetMealMessages("The chunks are swallowed very painfully.");

}

mixed eventEat(object who) {
  if(!random(1)) who -> addPoison(10);
  return meal::eventEat(who);
}
