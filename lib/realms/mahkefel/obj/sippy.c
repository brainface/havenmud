#include <lib.h>
#include <meal_types.h>
void NukeMe();
inherit LIB_MEAL;

static void create() {
  meal::create();
  SetKeyName("coffee");
  SetShort("an unspillable sippy cup of coffee");
  SetId( ({ "coffee", "cup" }) );
  SetAdjectives( ({ "unspillable", "sippy", "cup", "of" }) );
  SetMass(5);
  SetLong("This sippy cup is full of not cool aid but potent "
    "black cowboy coffee. You can practically see the grit floating "
    "around in the coffee, or could, if not for the protective "
    "sippy cup cover. The base flares outward saucerlike, making it "
    "very hard to spill, even if someone is super super clumsy.");
  SetMealType(MEAL_DRINK|MEAL_CAFFEINE);
  SetStrength(35);
  SetMealMessages(
    "You very safely drink a cup of coffee.",
    "$N very safely drinks a cup of coffee."
    );
}

