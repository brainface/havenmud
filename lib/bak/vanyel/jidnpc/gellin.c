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
             "specialist of planar magic" }) );
   SetRace("sprite");
   SetClass("necromancer");
   SetNoJoin(1);
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
  /*01*/      "dimension door" : 100,
  /*02*/      "elemental protection" : 100,
  /*03*/      "lock area" : 100,
  /*04*/      "planar strength" : 100,
  /*05*/      "planar assault" : 100,
  /*06*/      "teleport" : 100,
  /*07*/      "plane warp" : 100,
  /*08*/      "planar shield" : 100,
  /*09*/      "ethereal touch" : 100,
  /*10*/      "earth touch" : 100,
  /*11*/      "lock person" : 100,
  /*12*/      "mesmer barrier" : 100,
  /*13*/      
  /*14*/      
  /*15*/
  /*16*/
  /*17*/
  /*18*/
  /*19*/
  /*20*/
       ]) );
  SetTaughtSpheres( ({"magical planar magic","magical" }) );
   SetInventory( ([ 
      JID_OBJ + "/clothing/necro_robe" : "wear robe",
      JID_OBJ + "/clothing/sandals" : "wear sandals",
      "/std/weapon/pole/staff" : "wield staff",
   ]) );
}
