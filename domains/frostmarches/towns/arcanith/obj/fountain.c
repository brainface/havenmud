/* Arcanith's fountain - made by Sardonas*/

#include <lib.h>
#include "../ruins.h"
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
  meal::create();
  SetKeyName("fountain");
  SetShort("a glowing fountain");
  SetId( ({ "fountain" }) );
  SetAdjectives( ({ "glowing", "marble", "white" }) );
  SetLong("This fountain is made of a white marble which contains tiny "
          "flecks of gold.  The fountain has been carved to resemble a trio "
          "of dolphins jumping from the center of the fountain.  Cool water "
          "flows from the mouths of the dolphins.  The entire fountain glows "
          "with a pale blue light.");
  SetProperty( "magic", "The very stones of the fountain seem to radiate "
                        "a blue glow.  Small runes which cover the fountain's "
                        "seem to be causing the light.");
  SetRadiantLight(25);
  SetMealType(MEAL_DRINK);
  SetMealMessages( ({ "A warm feeling fills your body after you drink the "
                      "water.",
                      "$N drinks from a fountain." }) );
  SetPreventGet("The fountain is firmly attached to the ground!");
  SetPortions(-1);
  SetStrength(20);
}
