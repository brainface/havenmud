#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
  ::create();
  SetPortions(-1);
  SetShort("a granite cippus");
  SetKeyName("cippus");
  SetId( ({ "cippus" }) );
  SetAdjectives( ({ "granite" }) );
  SetPreventGet("");
  SetLong(
    "This beautifully carved statue is of the deity of this town, Selket, "
    "and several poisonous beasts - coiling snakes and fierce scorpions. "
    "At the bottom is a wide, shallow basin that collects rain water. It "
    "appears to be blessed by the statue to be fit for both drinking and "
    "the healing of poisonous wounds."
    );
  SetStrength(20);
  SetMealType(MEAL_DRINK);
  SetPoison(-10);
  SetMealMessages( ({
    "You drink cool water from the cippus.",
    "$N drinks cool water from the cippus.",
  }) );
}
