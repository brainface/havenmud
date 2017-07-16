/* ----------------------------------------------------------------------- */
// Area Title: City of Jidoor
// Filename: warlad.c
// Author: Derek Noble
// Creator: dylanthalus@haven
// Creation Date: Sept 19th, 1998
// Abstract: Warlad, Evoker Leader
// Revision History:  Base file created by Zaxan@Haven 
//               Sept 19th, 1998 Player Titles Changed
//               Dec 10th, 1998 Spellbook rearranged
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include <std.h>
#include "../jidoor.h"

inherit LIB_LEADER;

static void create() {
   leader::create();
   SetKeyName("warlad");
   SetShort("Warlad the Thaumaturgist of Destruction");
   SetId( ({ 
   		"warlad", "evoker","thaumaturgist","jidoor_npc",
   		"thaumaturgist of destruction" 
      }) );
   SetRace("sprite");
   SetClass("evoker");
   SetSkill("shock magic",1,2,);
   SetLevel(75);
   SetGender("male");
   SetTown("Jidoor");
   
   SetFreeEquip( ([ 
    STD_POLE "staff" : 1,
    ]) );
   
   SetPlayerTitles( ([ 
      "newbie"   : "the Neophyte of Evokation",
      "mortal"   : "the Professional Evoker",
      "hm"       : "the Grand Magician",
      "legend"   : "the Thaumaturgist of Destruction",
      "avatar"   : "the Shatterer of Worlds",
      //"rogue"    : "the Spellweaver in the Shadows",
      //"cavalier" : "the Militant Wizard",
      ]) );
   
   SetMorality(30);
   SetLong("This large sprite is very skilled in the ways of magical "
           "effects. He is the resource of Kailie's most skilled "
           "evokers.");
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
      JID_OBJ + "/clothing/vs_evoker_robe" : "wear robe",
      JID_OBJ + "/clothing/vs_sandals" : "wear sandals",
   ]) );
}
