/* ----------------------------------------------------------------------- */
// Area Title: City of Jidoor
// Filename: mcitizen.c
// Author: Derek Noble
// Creator: Zaxan Zimtafarous@Haven
// Creation Date: February 10th, 1999
// Abstract: Random Male Citizen of Jidoor
// Revision History:  
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include "../jidoor.h"

inherit LIB_SENTIENT;


static void create() {
  sentient::create();
   SetKeyName("citizen");
   SetId( ({ "lamrani","citizen", "jid_protect" }) );
   SetAdjectives( ({ "lamrani","male" }) );
   
   
   SetShort("a male Lamrani citizen of Jidoor");
   SetLong("Tall and slender, this male Lamrani citizen of the "
           "city is dressed in the attire of a mystic. Although "
           "he appears to be friendly, he does look somewhat "
           "preoccupied.");
   
  SetRace("lamrani");
  SetGender("male");
  RemoveLanguage("Dasinri");
  SetLanguage("Sprith", 100, 1);
  SetClass("mystic");
  SetMorality(20);
  SetLevel(3+random(15));
  SetTown("Jidoor");
  SetReligion("Magildan","Magildan");
  SetCurrency("rupies",random(100)+1);
  SetAction(1, ({ 
      "!speak Hello",
      "Citizen smiles at you.",
      "Citizen nods politely at you.",
      "!speak It certainly is a nice day.",
      "!look at mountains",
      "!look at building",
      "!ponder",
   }) );
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
  SetDie("The male citizen falls down dead.");
  SetWander(15);
}
