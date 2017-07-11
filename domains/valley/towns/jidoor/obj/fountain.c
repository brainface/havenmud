/* ----------------------------------------------------------------------- */
// Area Title: City of Jidoor
// Filename: fountain.c
// Author: Derek Noble
// Sage: dylanthalus@haven
// Creation Date: Sept 19th, 1998
// Abstract: Jidoor City Fountain
// Revision History: Originaly Created by Zaxan@Haven
//             Nov 6th, 1998 - Made a little more interesting
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include <meal_types.h>
#include "../jidoor.h"

inherit LIB_MEAL;

static void create() {
   meal::create();
   SetKeyName("fountain");
   SetProperty("history", "The fountain that used to sit in this spot was "
                "remove not to long ago and this fountain, attached to "
                "a statue of a sprite was put here in place.  The "
                "fountain itself is many years old, but your divinational "
                "powers are unable to discern the full history of the "
                "creation.",);
   SetProperty("magic", "The fountain is magical, but the type and purpose "
                "of the magic eludes your best attempts to discern it." );
   SetShort("a fountain");
   SetMealType(MEAL_DRINK);
   SetLong("The fountain is jetting streams of water towards the statue "
           "but not directly upon it.  The water looks clean and "
           "refreshing.");
   SetPreventGet("You cannot take the fountain.");
   SetPortions(-1);
   SetStrength(15);
   SetAdjectives( ({ "beautiful" }) );
   SetMealMessages( ({ 
      "$N drink from the fountain.", 
      "$N drinks from the fountain.",
   }) );
}
