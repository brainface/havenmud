#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create()
{
  meal::create();
  SetKeyName("whiskey");
  SetId( ({ "whiskey", "jar" }) );
  SetAdjectives( ({ "whiskey", "whiskey in the" }) );
  SetShort("whiskey in the jar");
  SetMass(15);
  SetValue(0);
  SetLong(
    "This is a small jar, which appears to be carved out of grey "
    "stone. A stopper is jammed in to it narrow neck, holding in "
    "whatever is inside. Carvings along the side of the jar seem "
    "to indicate that it contains whiskey."
  );
  SetMealType(MEAL_DRINK | MEAL_ALCOHOL);
  SetStrength(50);
  SetPortions(5);
  SetMealMessages(
    "You remove the cork from the jar of whiskey and tip "
    "it above your head, taking a deep swallow.",
    "$N pulls the cork from a jar of whiskey and tips it up, "
    "drinking deeply."
  );
  SetEmptyName("jar");
  SetEmptyShort("an empty stone jar");
  SetEmptyLong(
    "This is an empty jar of grey stone. Markings on its side indicate "
    "that at one time it held whiskey."
  );
}
