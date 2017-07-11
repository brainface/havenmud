#include <lib.h>
#include <meal_types.h>
#include "../gwonish.h"
inherit LIB_MEAL;

static void create() {
  ::create();
  SetKeyName("pool");
  SetPortions(-1);
  SetShort("a stagnant pool of water");
  SetId( ({ "pool", "water", }) );
  SetAdjectives( ({ "stagnant", "pool", "of" }) );
  SetLong("This stagnant pool of filthy swamp water is a repulsive "
          "bit of trash that only a lizardman could enjoy drinking. "
          "It appears to be a festering pool of disease.");
  SetMealType(MEAL_DRINK);
  SetStrength(100);
  SetPreventGet("");
  SetMealMessages( 
    "$N slurp loudly from a stagnant pool.",
    "$N slurps loudly from a stagnant pool.");
}

int eventDrink(object who) {
  if (who->GetRace() == "lizardman") return ::eventDrink(who);
  send_messages( ({ "groan", "vomit" }),
    "$agent_name $agent_verb and $agent_verb.",
    who, 0, environment(who));
  if (random(100) > who->GetStatLevel("durability")) {
    new(GWONISH_OBJ "infection")->eventInfect(who);
    }
  return 1;
}