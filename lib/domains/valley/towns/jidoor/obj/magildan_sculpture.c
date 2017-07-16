/* ----------------------------------------------------------------------- */
// Area Title: City of Jidoor
// Filename: magildan_statue.c
// Author: Derek Noble
// Sage: dylanthalus@haven
// Creation Date: Jan 23rd, 1999
// Abstract: Statue of the Magildan Symbol for Temple of Jidoor
// Revision History: 
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include "../jidoor.h"

inherit LIB_ITEM;

static void create() {
   item::create();
   SetKeyName("sculpture");
   SetId("sculpture","spellbook");
   SetProperty("history", "Sculpted by Nervala herself, this sculpture "
      "of the "
      "symbol of Magildan faith was designed expressly to be used in the "
      "new temple. It was created in the year 109.",);
   SetProperty("magic", "Although your mortal mind can comprehend that the "
      "sculpture is indeed magical, it cannot begin to understand the "
      "sculpture's intended effects.  The magic eminates auras of all the "
      "magical schools but strongest amongst them is the enchantment "
      "aura. The aura is so strong that it filters throughout the "
      "entire temple with ease and even penetrates outdoors.",);
   SetShort("a sculpture of a giant open spellbook");
   SetAdjectives( ({ "sculpture of","open","giant","magnificient",
                     "magildan"}) );
   SetLong("The universal symbol of the magildan faith is an open "
       "spellbook. In this sculpture however, the spellbook also contains "
       "what Magildan's commonly refer to as the Manastar. The "
       "Manastar is basically two squares overlapping each other to "
       "form a star with eight points. The Manastar on the dark purple "
       "marble of the sculpture stands out easily as it was etched into "
       "the stone and filled with liquified rupie which later hardened. "
       "The sculpture is obviously priceless.");
   SetPreventGet("The sculpture is far too heavy for any mortal to move.");
}
