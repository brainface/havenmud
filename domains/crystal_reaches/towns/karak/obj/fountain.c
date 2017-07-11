// Karak Rewrite
// Fountain infection stolen from Duuk's Gwonish
// Laoise
// 2007

#include <lib.h>
#include <meal_types.h>
#include "../karak.h"
inherit LIB_MEAL;

static void create() {
  meal::create();
  SetKeyName("fountain");
  SetShort("the Karak fountain");
  SetLong(
    "This is a very plain fountain, designed of simple wooden slats banded "
    "with metal, which form a large barrel shape. Fresh water enters the "
    "fountain from a wooden spout, pumped from local sources known to the "
    "orcs. Local rumor has it that there is something special about this "
    "water which makes it risky for those with no orc blood to drink."
  );
  SetPreventGet("You cannot take the fountain.");
  SetEmptyItem(KARAK_OBJ + "fountain");
  SetMealType(MEAL_DRINK);
  SetStrength(45);
  SetPortions(-1);
  SetMealMessages( ({ 
  	"You slurp noisily from the Karak fountain.", 
    "$N slurps noisily from the Karak fountain.", 
  }) );
}


int eventDrink(object who) {
  if (who->GetRace() == "orc" || "half-orc") return ::eventDrink(who);
  send_messages( ({ "groan", "vomit" }),
    "$agent_name $agent_verb and $agent_verb.",
    who, 0, environment(who));
  if (random(100) > who->GetStatLevel("durability")) {
    new(KARAK_OBJ "infection")->eventInfect(who);
  }
  return 1;
}
