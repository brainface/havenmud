/* ----------------------------------------------------------------------- */
// Area Title: City of Jidoor
// Filename: valora.c
// Author: Derek Noble
// Creator: dylanthalus@haven
// Creation Date: Sept 19th, 1998
// Abstract: Valora, Diviner Leader
// Revision History:  Base file created by Zaxan@Haven 
//               Sept 19th, 1998 Player Titles Changed
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include "../jidoor.h"

inherit LIB_LEADER;

static void create() {
   leader::create();
   SetKeyName("valora");
   SetShort("Valora the Augur of Thought");
   SetId( ({ "valora", "diviner","augur","augur of thought" }) );
   SetRace("sprite");
   SetClass("evoker");
   SetGender("female");
   SetTown("Jidoor");
   SetFreeEquip( ([ 
      "/std/weapon/blunt/mace" : 1,
   ]) );
   SetPlayerTitles( ([ 
      "newbie" : "the Neophyte Diviner",
      "mortal" : "the Professional Diviner",
      "hm" : "the Seer of Portents", 
      "legend" : "the Augur of Thought",
      "avatar" : "the Omniscient Prophet",
      "rogue" : "the Predator of Dreams",
      "merchant" : "the Dream Merchant",
   ]) );
   SetLevel(75);
   SetMorality(30);
   SetLong("Valora is one of the most powerful diviners in all of "
           "the world. She has dedicated her life to teaching others "
           "in the arts of divination.");
   SetSpellBook( ([ 
/*01*/      "detect invisibility" : 100,
/*02*/      "discern morality" : 100,
/*03*/      "discern religion": 100,
/*04*/      "detect evil" : 100,
/*05*/      "detect good" : 100,
/*06*/      "discern location" : 100,
/*07*/      "discern killer" : 100,
/*08*/      "research history" : 100,
/*09*/      "telepathy" : 100,
/*10*/      "detect magic" : 100,
/*11*/      "discern magic" : 100,
/*12*/      "discern profession" : 100,
/*13*/      "discern homeland" : 100,
/*14*/      "alarm" : 100,
/*15*/      "enhanced alarm" : 100,
/*16*/      
/*17*/      
/*18*/      
/*19*/
/*20*/
   ]) );
  SetTaughtSpheres( ({"magical divination","magical" }) );
   SetInventory( ([ 
      JID_OBJ + "/clothing/diviner_robe" : "wear robe",
      JID_OBJ + "/clothing/sandals" : "wear sandals",
   ]) );
  SetNoJoin(1);
}
