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
   SetId( ({ "hima", "bane", "bane of the living" }) );
   SetRace("sprite");
   SetClass("necromancer");
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
   SetShort("Hima the Bane of the Living");
   SetLong("Hima is a master of necromanctic magic. She is one of the "
           "highest ranked necromancers in the world. She is a "
           "great resource for both elite and aspiring necromancers.");
   SetSpellBook( ([ 
  /*01*/      "wards of protection" : 100,
  /*02*/      "hellfire" : 100,
  /*03*/      "reckoning" : 100,
  /*04*/      "mage's bane" : 100,
  /*05*/      "chaos bolt" : 100,
  /*06*/      "spirit call" : 100,
  /*07*/      "dark flame" : 100,
  /*08*/      "chill touch" : 100,
  /*09*/      "splash" : 100,
  /*10*/      "transfusion" : 100,
  /*11*/      "wither" : 100,
  /*12*/      "wound" : 100,
  /*13*/      "asphyxiation" : 100,
  /*14*/
  /*15*/
  /*16*/
  /*17*/
  /*18*/
  /*19*/
  /*20*/
       ]) );
   SetInventory( ([ 
      JID_OBJ + "/clothing/necro_robe" : "wear robe",
      JID_OBJ + "/clothing/sandals" : "wear sandals",
      "/std/weapon/pole/staff" : "wield staff",
   ]) );
}
