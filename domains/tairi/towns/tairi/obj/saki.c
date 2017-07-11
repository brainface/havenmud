/* A small cup of saki */
#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
  ::create();
  SetKeyName("saki");
  SetShort("a small cup of saki");
  SetId( ({ "cup", "saki" }) );
  SetId( ({ "small" }) );
  SetLong(
     "This is a small cup of warm sake. It is an alcoholic beverage "
     "that is produced from a rice and malt mixture. "
  );
  SetProperty("history",
     "Saki is a drink that has been produced for many ages throughout "
     "the lands of Tairi. It was made from a rice and malt mixture, "
     "added into water that runs fresh into the valley of Tairi. "
     "It is a mild drink compared to other types of alcohol. The "
     "traditional way to enjoy sake is with a plate of sushi. "
     "The drink is generally served warm, but can also be enjoyed "
     "cold, or even frozen, as well. "
  );
  SetStrength(8);
  SetMealType(MEAL_DRINK|MEAL_ALCOHOL);
  SetMass(5);
  SetMealMessages("The subtle taste of a warm mild liquid fills "
                 "your mouth. ",
              "$N sips a cup of saki. ");
  SetPortions(6);
}
