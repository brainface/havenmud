#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
  meal::create();
  SetKeyName("leaf");
  SetId( ({ "rough leaf", "leaf" }) );
  SetAdjectives( ({ "barian", "Barian"}) );
  SetShort("a rough Barian leaf");
  SetMass(1);
  SetLong("This leaf has been rolled into a thin cylinder "
          "with bits of leaf shreds tucked inside. This "
          "leaf is most common to the jungle of Baria and "
          "it is very cheap to craft this together.\n"
          "To use the rough leaf you must first 'light' it.");
  SetMealType(MEAL_SMOKE);
  SetStrength(1);
  SetPortions(3);
  SetValue(5);
  SetMealMessages(
    "You take a drag off the leaf. It is rough and dry.",
    "$N puffs on the rough Barian leaf."
    );
}
