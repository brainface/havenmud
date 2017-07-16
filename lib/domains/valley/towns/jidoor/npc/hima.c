/* ----------------------------------------------------------------------- */
// Area Title: City of Jidoor
// Filename: hima.c
// Author: Derek Noble
// Creator: dylanthalus@haven
// Creation Date: Sept 19th, 1998
// Abstract: Hima, Necromancy Leader
// Revision History:  Base file created by Zaxan@Haven 
//               Sept 19th, 1998 Player Titles Changed
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include "../jidoor.h"

inherit LIB_LEADER;

static void create() {
   leader::create();
   SetKeyName("Hima");
   SetId( ({ "hima", "bane", "bane of the living","jidoor_npc", }) );
   SetRace("sprite");
   SetClass("necromancer");
   SetTown("Jidoor");
   SetFreeEquip( ([ 
      "/std/weapon/pole/staff" : 1,
   ]) );
   SetPlayerTitles( ([ 
      "newbie" : "the Neophyte of the Dark Art",
      "mortal" : "the Professional of the Dark Art",
      "hm"     : "the Tainted Wizard",
      "legend" : "the Bane of the Living",
      "avatar" : "the Warden of Lost Souls",
      "rogue"  : "the Violator of Sacred Ground",
      "cavalier" : "the Fallen Knight",
   ]) );
   SetLevel(75);
   SetMorality(-100);
   SetGender("female");
   SetShort("Hima the Bane of the Living");
   SetLong("Hima is a master of necromanctic magic. She is one of the "
           "highest ranked necromancers in the world. She is a "
           "great resource for both elite and aspiring necromancers.");
   SetSpellBook( ([ 
       "umbral shield"	: 100,
       "soul tap"       : 100,
       "vampiric touch" : 100,
       "wither"         : 100,
       ]) );
   SetCombatAction(70, ({
   	   "!cast umbral shield",
   	   "!cast soul tap",
   	   "!cast wither",
   	   "!cast vampiric touch",
   	   }) );
   SetInventory( ([ 
      JID_OBJ + "/clothing/vs_necro_robe" : "wear robe",
      JID_OBJ + "/clothing/vs_sandals" : "wear sandals",
      "/std/weapon/pole/staff" : "wield staff",
   ]) );
}
