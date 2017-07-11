/* ----------------------------------------------------------------------- */
// Area Title: City of Jidoor
// Filename: fchild.c
// Author: Derek Noble
// Creator: Zaxan Zimtafarous@Haven
// Creation Date: Feb 9th, 1999
// Abstract: Female Citizen of Jidoor
// Revision History:  
/* ----------------------------------------------------------------------- */
#include <lib.h>
#include "../jidoor.h"

inherit LIB_SENTIENT;

int type = random(2);

static void create() {
   sentient::create();
   if (type == 0) { /* JIDOOR NPC TYPE: FEMALE SPRITE CHILD */
   SetKeyName("child");
   SetAdjectives( ({ "sprite","female","young" }) );
   SetId( ({ "child", "sprite", "citizen", "jid_protect" }) );
   SetShort("a young female Sprite child");
   SetLong("This tiny sprite is obviously one of the city's youth. "
           "She has a look of great contentment on her face but she "
           "looks intelligent regardless.  She likely will grow up "
           "to become a fine mage of some sort.");
   SetRace("sprite");
   SetClass("rogue");
   SetLevel(1);
   
   SetTown("Jidoor");
   SetReligion("Magildan","Magildan");
   SetGender("female");
   SetCombatAction(5, ({ 
      "!yell Help!",
      "!yell Get away from me!",
      "!yell Help!",
   }) );
   SetInventory( ([ 
      JID_OBJ + "/clothing/vs_dress" : "wear dress",
      JID_OBJ + "/clothing/vs_sandals" : "wear sandals",
   ]) );
   SetMorality(500);
   SetCurrency("rupies",random(10) + 1);
   SetAction(1, ({ 
      "The female Sprite child skips around the area happily.",
      "The Sprite child smiles at you.",
   }) );
   SetDie("The female Sprite child drops dead.");
   SetWander(15);
  }
  else if(type == 1) { /* JIDOOR NPC TYPE: FEMALE LAMRANI CHILD */
   SetKeyName("child");
   SetAdjectives( ({ "lamrani","female","young" }) );
   SetId( ({ "child", "lamrani","citizen", "jid_protect" }) );
   SetShort("a young female Lamrani child");
   SetLong("This female Lamrani is obviously one of the city's youth. "
           "She stands about four feet tall and her skin is pale white. "
           "She seems solemn and absorbed in thought. She likely will "
           "grow up to become a fine mage of some sort.");
   SetRace("lamrani");
   SetClass("rogue");
   SetLevel(1);
   RemoveLanguage("Dasinri");
   SetLanguage("Sprith", 100, 1);
   SetTown("Jidoor");
   SetReligion("Magildan","Magildan");
   SetGender("female");
   SetCombatAction(5, ({ 
      "!yell Help!",
      "!yell Get away from me!",
   }) );
   SetInventory( ([ 
      JID_OBJ + "/clothing/dress" : "wear dress",
      JID_OBJ + "/clothing/sandals" : "wear sandals",
   ]) );
   SetMorality(300);
   SetCurrency("rupies",random(10) + 1);
   SetAction(1, ({ 
      "The female Lamrani child quietly hovers around the area.",
      "The Lamrani child smiles politely at you.",
   }) );
   SetDie("The female Lamrani child drops dead.");
   SetLimit(4);
   SetWander(15);
   }
}
