/* ----------------------------------------------------------------------- */
// Area Title: City of Jidoor                                                
// Filename: nylrius.c                                                       
// Author: Derek Noble                                                       
// Creator: Zaxan Zimtafarous@Haven                                          
// Creation Date: April 06, 1999                                             
// Abstract: Jidoor's Ancient Languages Teacher                              
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include "../jidoor.h"

inherit LIB_SAGE;

static void create() {
   sage::create();    
   SetKeyName("Nylrius");
   SetRace("lamrani");   
   RemoveLanguage("Dasinri");
   SetLanguage("Sprith", 100, 1);
   SetTown("Jidoor");            
   SetReligion("Magildan","Magildan");
   SetShort("Nylrius, the Sage of the Ancients");
   SetMorality(-100);                            
   SetId( ({ "nylrius", "teacher","sage","jidoor_npc", }) );
   SetLong("Nylrius is an ancient looking Lamrani, probably "
           "hundreds of years old.  He stands here offering "
           "his knowledge of lost languages to the wealthy " 
           "few who can afford his services.  Although feeble "
           "looking, his very presence is intimidating.  He is "
           "dressed in the traditional black robe of the "
           "necromancer.");
   SetGender("male");
   SetClass("necromancer");
   SetLocalCurrency("rupies");
   SetCharge(3500);
   SetSpellBook( ([
      "wither"                                   : 100,
      "hunger"                                   : 100,
      "veil from beyond" : 100,
   ]) );
   SetTaughtLanguages( ({"Archaic","Naklu","Padashi","Valsor"}));
   SetLevel(50);
   SetAction(1, ({
      "!emote searches through some books.",
      "!speak I charge 35,000 rupies per lesson.  As I said, my services are not cheap.",
      "!speak Are you here to learn some languages?",
      "!speak Only the wealthy can afford my services.",
      "!cast veil from beyond",
   }) );
   SetCombatAction(75, ({
      "!cast hunger",
      "!cast wither",
      "!cast veil from beyond",
   }) );
   SetInventory( ([
      JID_OBJ + "/clothing/necro_robe" : "wear robe",
      JID_OBJ + "/clothing/sandals" : "wear sandals",
   ]) );
}

