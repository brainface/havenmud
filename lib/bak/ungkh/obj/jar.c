/* EnjilCode */


#include "../ungkh.h"
#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
  meal::create();

  SetKeyName("drink");
  SetShort("a jar of liquid");
  SetId( ({
    "jar"
    }) );
  SetAdjectives( ({
    "dirty",
    }) );

  SetMealType(MEAL_DRINK);
  SetStrength(13+random(4));
  SetMealMessages("The slimy liquid slides down your throat.");

}

mixed eventEat(object who) {
  if(!random(100)) who -> addPoison(10);
  return meal::eventEat(who);
}
