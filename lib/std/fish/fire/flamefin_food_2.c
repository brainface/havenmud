#include <lib.h>
#include <meal_types.h>

inherit LIB_MEAL;

static void create() {
    meal::create();
    SetKeyName("greater flamefin");
    SetId( ({ "flamefin" }) );
    SetAdjectives( ({ "greater" }) );
    SetShort("a greater flamefin");
    SetLong(
      "Technically an elemental, this looks more like a flounder, if that "
      "flounder were self-immolating. Its askew eyes stare outward blankly, and "
      "dangerous flames and steam spit and spark from the tip of the fins "
      "lining its broad flat body."
    );
    SetMass(FISH_SIZE_MEDIUM);
    SetMealType(MEAL_FOOD);
    SetStrength(FISH_FOOD_MEDIUM);
    SetPortions(1);
    SetProperty("history", "Well known and used by sailors to keep fatigue at "
      "bay, these are most often found off Haventown Bay. This looks to be a "
      "particularly large specicimen.");
    SetProperty("magic", "A minor fire elemental, when consumed it restores stamina.");
    SetValue(1500);
    SetMealMessages("A fire seems to fill your belly and radiate outward, refreshing you.",
      "$N carefully gulps down a lesser flamefin.");
}

mixed eventEat(object who) {
  who->AddStaminaPoints(250);
  return meal::eventEat(who);
}

