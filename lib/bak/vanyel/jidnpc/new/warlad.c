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
#include "../jidoor.h"

inherit LIB_LEADER;

static void create() {
   leader::create();
   SetKeyName("warlad");
   SetShort("Warlad the Thaumaturgist of Destruction");
   SetId( ({ "warlad", "evoker","thaumaturgist",
             "thaumaturgist of destruction" 
        }) );
   SetRace("sprite");
   SetClass("evoker");
   SetGender("male");
   SetTown("Jidoor");
   SetFreeEquip( ([ 
      "/std/weapon/pole/staff" : 1,
   ]) );
   SetPlayerTitles( ([ 
      "newbie" : "the Neophyte of Evokation",
      "mortal" : "the Professional Evoker",
      "hm" : "the Grand Magician",
      "legend" : "the Thaumaturgist of Destruction",
      "avatar" : "the Shatterer of Worlds",
      "rogue" : "the Spellweaver in the Shadows",
      "cavalier" : "the Militant Wizard",
   ]) );
   SetLevel(75);
   SetMorality(30);
   SetLong("This large sprite is very skilled in the ways of magical "
           "effects. He is the resource of Kailie's most skilled "
           "evokers.");
  SetSpellBook( ([ 
/*01*/      "chain lightning" : 100,
/*02*/      "disintegrate" : 100,
/*03*/      "energy wall" : 100,
/*04*/      "enhanced aura" : 100,
/*05*/      "enhanced buffer" : 100,
/*06*/      "enhanced fireball" : 100,
/*07*/      "temperature shield" : 100,
/*08*/
/*09*/
/*10*/
/*11*/
/*12*/
/*13*/
/*14*/
/*15*/
/*16*/
/*17*/
/*18*/      
/*19*/
/*20*/
            ]) );
   SetCombatAction(20, ({ 
      "!cast energy wall",
      "!cast chain lightning",
      "!cast enhanced fireball",
      "!cast disintegrate",
      "!cast chain lightning",
      "!cast disintegrate",
   }) );
   SetInventory( ([ 
      JID_OBJ + "/clothing/evoker_robe" : "wear robe",
      JID_OBJ + "/clothing/sandals" : "wear sandals",
   ]) );
}
