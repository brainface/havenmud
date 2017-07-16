/*  A druid puddle */
#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;
void NukeMe();

static void create() {
  meal::create();
  SetKeyName("puddle");
  SetShort("a puddle of water");
  SetId( ({ "puddle", "water", "puddle of water" }) );
  SetStrength(65);
  SetLong("This is a magically summoned puddle of water.");
  SetMealType(MEAL_DRINK);
  SetPreventGet("You cannot take a puddle!");
  SetMass(450000);
  call_out( "NukeMe", 20);
 }

mixed eventDrink(object who) {
   remove_call_out("NukeMe");
  return meal::eventDrink(who);
  }

void NukeMe() {
  if (environment())
     message("other_spam", "A puddle dries up into the ground.", environment());
  eventDestruct();
  }
