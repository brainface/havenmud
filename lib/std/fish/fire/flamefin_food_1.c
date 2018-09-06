#include <lib.h>
#include <meal_types.h>

inherit LIB_MEAL;

static void create() {
    meal::create();
    SetKeyName("lesser flamefin");
    SetId( ({ "flamefin" }) );
    SetAdjectives( ({ "lesser" }) );
    SetShort("a lesser flamefin");
    SetLong(
      "Technically an elemental, this looks more like a flounder, if that "
      "flounder were self-frying. Its askew eyes stare outward blankly, and "
      "tiny flames and steam occasionally spit from the tip of the fins lining "
      "its broad flat body."
    );
    SetMass(FISH_SIZE_SMALL);
    SetMealType(MEAL_FOOD);
    SetStrength(FISH_FOOD_SMALL);
    SetPortions(1);
    SetProperty("history", "Well known and used by sailors to keep fatigue at "
      "bay, these are most often found off Haventown Bay.");
    SetProperty("magic", "A minor fire elemental, when consumed it restores stamina.");
    SetValue(500);
    SetMealMessages("A fire seems to fill your belly and radiate outward, refreshing you.",
      "$N carefully gulps down a lesser flamefin.");
}

mixed eventEat(object who) {
  who->AddStaminaPoints(25);
  return meal::eventEat(who);
}

