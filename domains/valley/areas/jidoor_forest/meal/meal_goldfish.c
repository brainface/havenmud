/* ----------------------------------------------------------------------- */
// Area Title: Jidoor Forest
// Filename: meal_goldfish.c
// Author: Derek Noble
// Angel: dylanthalus@haven
// Creation Date: August 20th, 1997
// Abstract: This is the meal of a goldfish.
// Revision History: August 23rd, 1998 - Pre-Approved by Zaxan Zimtafarous
// Last Update: 
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include <meal_types.h>

inherit LIB_MEAL;

static void create() 
  {
  meal::create();
  SetKeyName("goldfish");
  SetId( ({ "goldfish","fish" }) );
  SetAdjectives( ({ "big" }) );
  SetShort("a big goldfish");
  SetLong("This is a big goldfish caught from a stream in the Jidoor "
          "Forest.  It looks like it would an appetizing meal.");
  SetMass(20);
  SetMealType(MEAL_FOOD);
  SetStrength(30);
  SetMealMessages(
         "Eating a goldfish is different, but it tastes good anyway.", 
         "$N eats a big goldfish."
                 );
  }
