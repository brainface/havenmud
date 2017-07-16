#include <lib.h>
#include <meal_types.h>

inherit LIB_MEAL;

static void create() {
  meal::create();
  SetKeyName("sun fish");
  SetId( ({"sun fish","fish"}) );
  SetAdjectives(  ({"sun","fish","spiked"}) );
  SetShort("a spiked sun fish");
  SetLong("It is has a slimy yellowish color, speckled "
            "with spikes and harsh scales.");
  SetMass(10);
  SetId( ({ "sun fish","fish", "sunny",}) );
  SetMealType(MEAL_FOOD);
  SetStrength(30);
  SetMealMessages("It slides harshly down your throat.", 
                    "$N eats a spiked sun fish.");

  }
