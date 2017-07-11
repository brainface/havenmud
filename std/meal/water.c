#include <lib.h>
#include <std.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
   meal::create();
   SetKeyName("water");
   SetShort("a glass of water");
   SetId( ({ "glass","water" }) );
   SetAdjectives( ({ "glass of","water" }) );
   SetLong("The water looks pretty healthy; nothing is floating "
           "in it, though it isn't perfectly clear.");
   SetMass(5);
   SetStrength(15);
   SetMealType(MEAL_DRINK);
   SetMealMessages("$N drink a glass of slightly stale water.",
                   "$N drinks a glass of water.");
  SetEmptyItem(STD_MEAL "glass");
}
