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
             "wizard of enthrallment" }) );
   SetRace("sprite");
   SetClass("enchanter");
   SetGender("male");
   SetTown("Jidoor");
   SetFreeEquip( ([ 
      "/std/weapon/pole/staff" : 1, 
   ]) );
   SetPlayerTitles( ([ 
      "newbie" : "the Neophyte of Enchantment",
      "mortal" : "the Professional Enchanter",
      "hm" : "the Wizard of Enthrallment",
      "legend" : "the Weaver of Dreams",
      "avatar" : "the Bender of Wills",
      "fighter" : "the Wizard of War",
   ]) );
   SetLevel(75);
   SetMorality(30);
   SetLong("Dolad is a local enchanter. He stands here as teacher "
           "of common enchantment spells.");
   SetSpellBook( ([
  /*01*/      "curse" : 100, 
  /*02*/      "ice ball" : 100,
  /*03*/      "create water" : 100,
  /*04*/      "create food" : 100,
  /*05*/      "create magic reserve" : 100,
  /*06*/      "create light globe" : 100,
  /*07*/      "create light globe" : 100,
  /*08*/      "shield area" : 100,
  /*09*/      "haste" : 100,
  /*10*/      "poison cloud" : 100,
  /*11*/      "anti-magic field" : 100,
  /*12*/      "wards of light" : 100,
  /*13*/      "paralysis" : 100,
  /*14*/      "blindness" : 100,
  /*14*/      "create dark globe" : 100,
  /*16*/
  /*17*/
  /*18*/
  /*19*/
  /*20*/
                ]) );
   SetInventory( ([ 
      JID_OBJ + "/clothing/enchanter_robe" : "wear robe",
      JID_OBJ + "/clothing/sandals" : "wear sandals",
      "/std/weapon/pole/staff" : "wield staff",
   ]) );
   SetCombatAction(5, ({
      "!cast paralysis",
      "!cast ice ball",
      "!cast ",
   }) );
}
