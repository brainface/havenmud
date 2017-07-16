/* ----------------------------------------------------------------------- */
// Area Title: City of Jidoor
// Filename: mingad.c
// Author: Derek Noble
// Creator: dylanthalus@haven
// Creation Date: Unknown
// Abstract: Mingad Mardan, Mayor of Jidoor
// Revision History:  Base file created by Zaxan@Haven 
//        November 6th, 1998 - Added Clothing, Changed Class to Diviner
/* ----------------------------------------------------------------------- */
#include <lib.h>
#include "../jidoor.h"

inherit LIB_MAYOR;

static void create() {
   mayor::create();
   SetKeyName("mingad");
   SetShort("Mingad Mardan, Mayor of Jidoor");
   SetId( ({ "mingad", "mardan", "mingad mardan", "mayor" }) );
   SetLong("Mingad Mardan is the Jidoor mayor. He looks like he spends his "
           "days doing paperwork, dealing with new citizens and collecting "
           "taxes.");
   SetRace("sprite");
   SetMorality(70);
   SetGender("male");
   SetClass("diviner");
   SetInventory( ([ 
      JID_OBJ + "/clothing/vs_diviner_robe" : "wear robe",
      JID_OBJ + "/clothing/vs_sandals" : "wear sandals",
   ]) );
   SetLevel(15);
   SetTown("Jidoor");
   SetLocalCurrency("rupies");
   SetTax(10);
}
