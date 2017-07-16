//
//  Summary: Drink for baria
//  Created by Rhakz - Angel Cazares
//  For Baria
//  Date: 10/14/98
//
#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
  meal::create();
  SetKeyName("cocktail");
  SetShort("a coconut full of barian cocktail");
  SetId( ({"cocktail","barian cocktail","drink"}) );
  SetMass(15);
  SetLong("The barian cocktail is a mix of coconut and pineapple "
          "juice along with a homemade liquor. It is served on "
          "a coconut.");
  SetStrength(15);
  SetMealType(MEAL_DRINK|MEAL_ALCOHOL);
  SetMealMessages(
                  "The cocktail is delicious and refreshing!",
                  "$N drinks a barian cocktail."
                 );
  SetEmptyItem("/domains/baria/towns/baria/obj/coconut");
}
