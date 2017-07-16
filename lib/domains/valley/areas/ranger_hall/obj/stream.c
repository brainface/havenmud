/* ----------------------------------------------------------------------- */
// Area Title: Ranger Hall
// Filename: stream.c
// Author: Derek Noble
// Immortal: Zaxan Zimtafarous@haven
// Creation Date: 
// Abstract: A stream running through the ranger's guildhall.
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include <meal_types.h>
#include "../ranger_hall.h"

inherit LIB_MEAL;

static void create() {
   meal::create();
   SetKeyName("stream");
   SetShort("a stream");
   SetMealType(MEAL_DRINK);
   SetLong("The stream enters the trove along the western "
           "from a hole in the northern western corner and "
           "trickles quietly until it disappears through "
           "another hole in the south western corner. The "
           "stream looks like an excellent place to "
           "quench your thirst.");
   SetAdjectives( ({ "small","underground" }) );         
   SetPreventGet("Take a stream?");
   SetEmptyItem(RH_OBJ "stream");
   SetStrength(15);
   SetMealMessages( ({ 
      "$N drink from the stream.", 
      "$N drinks from the stream.",
   }) );
}
