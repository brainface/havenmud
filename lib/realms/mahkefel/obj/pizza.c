#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
  meal::create();
  SetKeyName("pizza");
  SetId( ({ "pizza", "oatmeal" }) );
  SetAdjectives( ({ "oatmeal","delicious","slice","of" }) );
  SetShort("a delicious slice of oatmeal pizza");
  SetMass(20);
  SetLong("This cactusland delicacy is sauced with oatmeal instead "
    "of tomatoes and topped with cranberries and blueberries. Yeah, "
    "that probs goes great with cheese let's run with that. The "
    "crust is also all cinammon bunny make this for me and ship it "
    "to me.");
  SetMealType(MEAL_FOOD);
  SetPortions(4);
  SetStrength(100);
  SetMealMessages(
    "Scromnomnom.",
    "$N makes scromnomnom noises as they noisily devour a pizza.");
}

