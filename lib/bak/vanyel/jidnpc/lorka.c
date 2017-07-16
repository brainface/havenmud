/* ----------------------------------------------------------------------- */
// Area Title: City of Jidoor
// Filename: lorka.c
// Author: Derek Noble
// Creator: Zaxan@Haven, Dylanthalus@Haven
// Creation Date: Unknown
// Abstract: Jidoor's Language Teacher
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include "../jidoor.h"

inherit LIB_SAGE;

static void create() {
   sage::create();
   SetKeyName("lorka");
   SetRace("sprite");
   SetShort("Lorka Landara, the Sage of Jidoor");
   SetMorality(30);
   SetId( ({ "lorka", "landara", "lorka landara","teacher","sage" }) );
   SetLong("Lorka is a fairly small sprite who holds in her head "
           "the knowledge of many languages. She looks ready to "
           "help others learn the languages she knows. She is "
           "dressed in the attire of an enchanter and looks "
           "quite capable of defending herself against aggression.");
   SetGender("female");
   SetClass("enchanter");
   SetLocalCurrency("rupies");
   SetCharge(5000);
   SetSpellBook( ([ 
      "missile" : 100,
      "fireball" : 100,
   ]) );  
   SetTaughtLanguages( ({"Blaodric","Dasinri","Eltherian","Slith",
                         "Sprith","Uruk"})
                     );
   SetLevel(35);
   SetAction(1, ({ 
      "!emote searches through some books.",
      "!smile polite",
      "!speak Are you here to learn some languages?",
      "!speak I'd gladly teach you something about languages "
      "if you're able to pay me for my services.",
   }) );
   SetCombatAction(15, ({ 
      "!cast missile",
      "!cast fireball",
   }) );
   SetInventory( ([ 
      JID_OBJ + "/clothing/enchanter_robe" : "wear robe",
      JID_OBJ + "/clothing/sandals" : "wear sandals",
   ]) );
}
