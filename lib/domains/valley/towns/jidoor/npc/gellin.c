/* ----------------------------------------------------------------------- */
// Area Title: City of Jidoor
// Filename: gellin.c
// Author: Derek Noble
// Creator: dylanthalus@haven
// Creation Date: Sept 19th, 1998
// Abstract: Gellin, Planar Specialist
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include "../jidoor.h"

inherit LIB_LEADER;

static void create() {
   leader::create();
   SetKeyName("gellin");
   SetId( ({ "gellin", "necromancer", "specialist", 
             "specialist of planar magic", "jidoor_npc", }) );
   SetRace("sprite");
   SetClass("necromancer");
  // mahkefel: std necro, allowing join, gives some titles, whatev.
   SetTown("Jidoor");
   SetFreeEquip( ([ 
      "/std/weapon/pole/staff" : 1,
   ]) );
   SetPlayerTitles( ([ 
      "newbie" : "the Neophyte of the Dark Art",
      "mortal" : "the Professional of the Dark Art",
      "hm" : "the Tainted Wizard",
      "legend" : "the Bane of the Living",
      "avatar" : "the Warden of Lost Souls",
      "rogue" : "the Violator of Sacred Ground",
      "cavalier" : "the Fallen Knight",
   ]) );
   SetLevel(75);
   SetMorality(-100);
   SetGender("female");
   SetShort("Gellin, the Specialist of Planar Magic");
   SetLong("Although there are no planar mages on Kailie, Gellin "
           "is perhaps the closest thing to one.  A necromancer "
           "by trade, she has chosen to devote a great deal of time "
           "to become one of the greatest students of planar magic. "
           "She is a small sprite, but her knowledge of planar magic "
           "is beyond greatness.");  
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
