/* ----------------------------------------------------------------------- */
// Area Title: Jidoor Forest
// Filename: meal_perch.c
// Author: Derek Noble
// Angel: dylanthalus@haven
// Creation Date: August 20th, 1997
// Abstract: This is the meal of a perch
// Revision History: August 23rd, 1998 - Pre-Approved by Zaxan Zimtafarous
// Last Update: 
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include <meal_types.h>

inherit LIB_MEAL;

static void create() 
  {
  meal::create();
  SetKeyName("perch");
  SetId( ({ "perch","fish" }) );
  SetAdjectives( ({ "small" }) );
  SetShort("a small perch");
  SetLong("This is a small perch caught from a stream in the Jidoor Forest.");
  SetMass(25);
  SetMealType(MEAL_FOOD);
  SetStrength(35);
  SetMealMessages("The perch tastes excellent.", 
                  "$N eats a small perch.");
  }
