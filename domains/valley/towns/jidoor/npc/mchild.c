/* ----------------------------------------------------------------------- */
// Area Title: City of Jidoor
// Filename: mchild.c
// Author: Derek Noble
// Creator: dylanthalus@haven
// Creation Date: December 16th, 1998
// Abstract: male Citizen of Jidoor
// Revision History:  Base file created by Zaxan@Haven 
/* ----------------------------------------------------------------------- */
#include <lib.h>
#include "../jidoor.h"

inherit LIB_SENTIENT;

int type = random(2);

static void create() {
   sentient::create();
   if (type == 0) { /* JIDOOR NPC TYPE: MALE SPRITE CHILD */
   SetKeyName("child");
   SetAdjectives( ({ "sprite","male","young" }) );
   SetId( ({ "sprite", "child", "citizen", "jid_protect" }) );
   SetShort("a young male Sprite child");
   SetLong("This tiny Sprite is obviously one of the city's youth. "
           "He has a look of great contentment on his face but he "
           "looks intelligent regardless.  He will almost assuredly "
           "grow up to become a fine mage of some sort.");
   SetRace("sprite");
   SetClass("rogue");
   
   SetLevel(1);
   SetTown("Jidoor");
   SetReligion("Magildan","Magildan");
   SetGender("male");
   SetCombatAction(5, ({ 
      "!yell Help!",
      "!yell Get away from me!",
   		}) );
   SetInventory( ([ 
      JID_OBJ + "/clothing/vs_slacks" : "wear slacks",
      JID_OBJ + "/clothing/vs_shirt" : "wear shirt",
      JID_OBJ + "/clothing/vs_sandals" : "wear sandals",
   		]) );
   SetMorality(500);
   SetCurrency("rupies",random(10) + 1);
   SetAction(1, ({ 
      "The male Sprite child skips around the area happily.",
      "Child smiles at you.",
   }) );
   SetDie("The male child drops dead.");
   SetWander(15);
   }
  else if(type == 1) { /* JIDOOR NPC TYPE: MALE LAMRANI CHILD */
   SetKeyName("child");
   SetAdjectives( ({ "lamrani", "male","young" }) );
   SetId( ({ "lamrani", "child", "citizen", "jid_protect" }) );
   SetShort("a young male Lamrani child");
   SetLong("This young Lamrani is obviously one of the city's youth. "
           "He has a look of great curiousity on his face and he "
           "looks very intelligent.  He will almost assuredly "
           "grow up to become a fine mage of some sort.");
   SetRace("lamrani");
   SetClass("rogue");
   RemoveLanguage("Dasinri");
   SetLanguage("Sprith", 100, 1);

   SetLevel(1);
   SetTown("Jidoor");
   SetReligion("Magildan","Magildan");
   SetGender("male");
   SetCombatAction(5, ({ 
      "!yell Help!",
      "!yell Get away from me!",
      "!yell Help!",
   }) );
   SetInventory( ([ 
      JID_OBJ + "/clothing/slacks" : "wear slacks",
      JID_OBJ + "/clothing/shirt" : "wear shirt",
      JID_OBJ + "/clothing/sandals" : "wear sandals",
   ]) );
   SetMorality(500);
   SetCurrency("rupies",random(10) + 1);
   SetAction(1, ({ 
      "The male Lamrani child looks curiously at his surroundings.",
      "Child smiles at you.",
   }) );
   SetDie("The male child drops dead.");
   SetLimit(4);
   SetWander(15);
   }
}
