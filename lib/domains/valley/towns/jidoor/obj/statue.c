/* ----------------------------------------------------------------------- */
// Area Title: City of Jidoor
// Filename: statue.c
// Author: Derek Noble
// Sage: dylanthalus@haven
// Creation Date: Nov 6th, 1998
// Abstract: Jidoor City Square Statue
// Revision History: 
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include "../jidoor.h"

inherit LIB_ITEM;

static void create() {
   item::create();
   SetKeyName("statue");
   SetId("statue","statue of a sprite");
   SetProperty("history", "You sense the thoughts of the creator was to "
               "create a statue that depicted the sprite race in general. "
               "The purpose of his creation was to demonstrate the "
               "absolute beauty of the sprite race.",);
   SetShort("a statue of a sprite");
   SetAdjectives( ({ "magnificient" }) );
   SetLong("The statue is a magnificient creation of art. It depicts a "
           "male sprite, standing proudly with his arms outstretched "
           "towards the sky. He is dressed in robes and is obviously "
           "a mage of some sort.  The statue itself is made from pure "
           "rupie and sparkles in the light of the town square.");
   SetPreventGet("The statue is far too heavy for any mortal to move.");
}
