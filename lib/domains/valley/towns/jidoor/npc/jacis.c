                                                                                               /* ----------------------------------------------------------------------- */
// Area Title: City of Jidoor
// Filename: jacis.c
// Author: Derek Noble
// Creator: dylanthalus@haven
// Creation Date: Sept 19th, 1998
// Abstract: Jacis, Planar Trainer
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include "../jidoor.h"

inherit LIB_TRAINER;

static void create() {
   trainer::create();
   SetKeyName("jacis");
   SetShort("Jacis Bevren");
   SetId( ({ 
   		"jacis","bevren","necromancer","jacis bevren","teacher",
   		"jidoor_npc",
   		}) );
   
   SetClass("necromancer");
   SetSkill("conjuting",1,1);
   SetSkill("necromancy",1,1);
   SetSkill("evokation",1,1);
   
   SetMorality(-50);
   SetLevel(20);
   SetGender("male");
   SetRace("sprite");
   SetLong("Jacis Bevren is the most adept person for teaching the skill "
           "of planar magic.  He is always willing to help someone better "
           "their knowledge.");
   SetInventory( ([ 
      JID_OBJ + "/clothing/vs_necro_robe" : "wear robe",
      JID_OBJ + "/clothing/vs_sandals" : "wear sandals",
      "/std/weapon/pole/staff" : "wield staff",
      ]) );
   SetSpellBook( ([
   		"wound"       : 100,
   		"cloud kill"  : 100,
   		"sphere"      : 100,
   	  ]) );
   SetCombatAction(40, ({
   	  "!cast wound",
   	  "!cast cloud kill",
   	  "!cast sphere",
   		}) );
}
