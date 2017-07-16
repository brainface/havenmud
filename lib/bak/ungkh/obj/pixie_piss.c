//
//  Summary: Pixie Piss. Ogre beer.
//  Created by Malak@Haven, Chris Hays
//  Date: 5/27/99
//
#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
  meal::create();
  SetKeyName("cocktail");
  SetShort("a large jug");
  SetId( ({"jug","pixie piss","piss"}) );
  SetMass(15);
  SetLong("The large, crudely made jug is full of a highly acidic "
          "drink.  Fumes rise from the opening, the fluid inside a "
          "sickening shade of yellow."
         );
  SetStrength(158);
  SetMealType(MEAL_DRINK|MEAL_ALCOHOL); 
  SetMealMessages(
                  "The Pixie Piss feels like liquid fire as it pours down your throat.",
                  "$N chugs from the bottle of Pixie Piss, gagging slightly."
                 );
}
