/* ----------------------------------------------------------------------- */
// Area Title: City of Jidoor
// Filename: fcitizen.c
// Author: Derek Noble
// Creator: dylanthalus@haven
// Creation Date: Feb 10th, 1999
// Abstract: Random Female Citizens of Jidoor
// Revision History:  
/* ----------------------------------------------------------------------- */
#include <lib.h>
#include "../jidoor.h"

inherit LIB_SENTIENT;

static void create() {
   sentient::create();
   SetKeyName("citizen");
   SetId( ({ "lamrani","citizen", "jid_protect" }) );
   SetAdjectives( ({ "lamrani","female" }) );
   SetShort("a female Lamrani citizen of Jidoor");
   SetLong("Dressed in the attire of mystic, the female citizen "
           "is wandering about the city attending to her daily "
           "business. She appears to be friendly.");

   SetRace("lamrani");
   SetGender("female");
   RemoveLanguage("Dasinri");
   SetLanguage("Sprith", 100, 1);
   SetMorality(20);
   
   SetClass("mystic");
   SetLevel(3+random(15));
   SetTown("Jidoor");
   SetReligion("Magildan","Magildan");
   
   SetCurrency("rupies", random(50)+50);
   SetAction(1, ({ 
      "!speak Hello",
      "Citizen smiles at you.",
      "!speak lovely day isn't it?",
      "!look at mountains",
      "!look at building",
      "!ponder",   }) );
   SetSpellBook( ([ 
      "terra"   : 100,
      "tangle"  : 100,
      "capsule" : 100,
      "shock"   : 100,
   ]) );
   SetCombatAction(60, ({ 
      "!cast tangle",
      "!cast terra",
      "!cast capsule",
      "!cast shock",
   		}) );
   SetInventory( ([ 
      JID_OBJ + "/clothing/mystic_robe" : "wear robe",
      JID_OBJ + "/clothing/sandals" : "wear sandals",
   		]) );
   SetDie("The female citizen falls down dead.");
   SetFriends( ({ "child","guard", "citizen","navan" }) );
   SetWander(15);
}
