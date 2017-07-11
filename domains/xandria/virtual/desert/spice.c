#include <lib.h>
#include <vendor_types.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
  ::create();
    SetKeyName("sandworm spice");
  SetShort("a handful of sand worm spice");
  SetId( ({ "spice" }) );
  SetAdjectives( ({ "handful", "of", "sand", "worm", }) );
  SetMealType(MEAL_FOOD|MEAL_CAFFEINE);
  SetMass(50);
  SetPortions(1);
  SetStrength(80);
  SetValue(5000);
  SetMealMessages( ({
    "You ingest a small quantity of spice.",
    "$N ingests a small quantity of spice.",
  }) );
  SetLong(
    "This spice was removed from the gut of a Xandrian giant sand worm. Its ability "
    "to extend life and speed the body's natural processes are legendary. The spice "
    "is a blue-green color, very sandy, and has a slight odor."
    );
  SetSmell("The spice smells somewhat like cinammon.");
}
