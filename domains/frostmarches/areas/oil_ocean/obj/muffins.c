#include <lib.h>
#include "../oil.h"
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
  meal::create();
  SetKeyName("muffins");
  SetId( ({ "muffin", "muffins", }) );
  SetAdjectives( ({ "tray", "of" }) );
  SetShort("a small tray of muffins");
  SetMass(1);
  SetLong("This small tray of muffins from the Twitchy Nymph look yummy.");
  SetMealType(MEAL_FOOD);
  SetStrength(15);
  SetPortions(8);
  SetMealMessages(
    "You eat a muffin.  It's quite yummy.",
    "$N eats a muffin.");
}
