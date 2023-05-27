// Banana Pudding with Beaver butt flavoring
// Look it up. Castoreum.
// www.youtube.com/watch?v=nweK6VRM8a8&ab 
// www.youtube.com/watch?v=ZKrj3UjMi1o&ab
// www.youtube.com/watch?v=rW_7AWhQfK8&ab (LTN/CNN seriousish vid)
// Was a radio show segment that I found quite funny / assess intake
// Also I dont think I ever made food with a 'wrapper' 
// Urien 5/26/2023

#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
  ::create();
  SetKeyName("pudding");
  SetShort("a serving of banana pudding");
  SetStrength(5);
  SetMass(5);
  SetId( ({ "pudding", "serving","plastic" }) );
  SetAdjectives( ({"banana"}) );
  SetLong("An Immortal was craving banana pudding and got none. So "
          "in a sad attempt to schmooze, make amends or "
          "festivities it was created in haste for you! The "
          "ingredients seem to have been all blended together "
          "into a light fluffy creamy ooze inside a convenient "
          "clear plastic container. It almost appears other "
          "worldly in packaging and convenience.");
  SetMealMessages( ({
    "$N eats the entire portion of banana pudding.",
    "You eat the banana pudding. It tastes delicious with a hint "
    "of vanilla. It's 21st century pudding and reminds you it "
    "is made with beaver butt, an ingredient commonly found "
    "in vanilla extract.",
    }) );
  SetMealType(MEAL_FOOD);
  SetValue(10);
  SetEmptyName("container");
  SetEmptyShort("an empty container of banana pudding");
  SetEmptyLong("This plastic container once held the remnants "
    "of some banana pudding. Some transparent slime of what "
    "once along the inside would only provide flavoring, "
    "nothing more for sustenance. A sad state for what once "
    "was.");
}
