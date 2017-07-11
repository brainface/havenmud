/* ----------------------------------------------------------------------- */
// Area Title: City of Jidoor
// Filename: dolad.c
// Author: Derek Noble
// Creator: dylanthalus@haven
// Creation Date: Sept 19th, 1998
// Abstract: Dolad, Enchanter Leader
// Revision History:  Base file created by Zaxan@Haven 
//               Sept 19th, 1998 Player Titles Changed
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include "../jidoor.h"

inherit LIB_LEADER;

static void create() {
   leader::create();
   SetKeyName("dolad");
   SetShort("Dolad the Weaver of Dreams");
   SetId( ({ "dolad", "enchanter","weaver","weaver of dreams",
             "wizard of enthrallment","jidoor_npc", }) );
   SetRace("sprite");
   SetClass("enchanter");
   SetSkill("shock magic",1,2);
   SetGender("male");
   SetTown("Jidoor");
   SetFreeEquip( ([ 
      "/std/weapon/pole/staff" : 1, 
   ]) );
   SetPlayerTitles( ([ 
      "newbie" : "the Neophyte of Enchantment",
      "mortal" : "the Professional Enchanter",
      "hm"     : "the Wizard of Enthrallment",
      "legend" : "the Weaver of Dreams",
      "avatar" : "the Bender of Wills",
      "fighter" : "the Wizard of War",
   ]) );
   SetLevel(75);
   SetMorality(30);
   SetLong("Dolad is a local enchanter. He stands here as teacher "
           "of common enchantment spells.");
    SetSpellBook( ([ 
       "mesmer barrier"	: 100,
       "flamestrike"    : 100,
       "chain lighting" : 100,
       "disintegrate"   : 100,
       ]) );
   SetCombatAction(70, ({
   	   "!cast mesmer barrier",
   	   "!cast flamestrike",
   	   "!cast chain lightning",
   	   "!cast disintegrate",
   	   }) );
   SetInventory( ([ 
      JID_OBJ + "/clothing/vs_enchanter_robe" : "wear robe",
      JID_OBJ + "/clothing/vs_sandals" : "wear sandals",
      "/std/weapon/pole/staff" : "wield staff",
      ]) );

}
