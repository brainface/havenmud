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
   SetId( ({ 
   		"valora", "diviner","augur","augur of thought",
   		"jidoor_npc",
   		}) );
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
     "chain lightning" : 100,
     "disintegrate"    : 100,
     "energy wall"     : 100,
     "mesmer barrier"  : 100,
     "flamestrike"     : 100,
     ]) );
   SetCombatAction(90, ({ 
      "!cast energy wall",
      "!cast chain lightning",
      "!cast flamestrike",
      "!cast disintegrate",
      "!cast mesmer barrier",
      }) );
   SetInventory( ([ 
      JID_OBJ + "/clothing/vs_diviner_robe" : "wear robe",
      JID_OBJ + "/clothing/vs_sandals" : "wear sandals",
   ]) );
  SetNoJoin(1);
}
