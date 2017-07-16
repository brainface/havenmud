/* ----------------------------------------------------------------------- */
// Area Title: City of Jidoor
// Filename: sweeper.c
// Author: Derek Noble
// Creator: dylanthalus@haven
// Creation Date: December 16th, 1998
// Abstract: Street Sweeper.
// Revision History:  Base file created by Zaxan@Haven 
//                    Recoded by Dylanthalus@Haven
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include "../jidoor.h"

inherit LIB_NPC;

static void create() {
   npc::create();
   SetKeyName("Navan");
   SetId( ({ "navan","sweeper" }) );
   SetAdjectives( ({ "street","old","old jidoor street" }) );
   SetShort("Navan, the old Jidoor street sweeper");
   SetLong("Navan is perhaps the oldest sprite you have ever seen. "
           "He doesn't appear fragile or weak, just aged by "
           "experience.  He's standing around here, doing his best "
           "to clean up any garbage littered into the city from "
           "the bazaar.  You do notice one strange thing about him. "
           "He does not seem to be carrying any kind of sweeping "
           "apparatus.");
   SetLevel(20);
   SetMorality(15);
   SetGender("male");
   SetRace("sprite");
   SetTown("Jidoor");
   SetReligion("Magildan","Magildan");
   SetClass("evoker");
   SetCurrency("rupies",random(70));
   SetAction(1, ({ 
      "!emote smiles at you.",
      "!emote smiles at you.",
      "!emote smiles at you.",
      "!emote smiles at you.",
      "!emote smiles at you.",
      "!emote looks frustrated at the garbage collecting on the "
      "avenue.",
      "!emote looks frustrated at the garbage collecting on the "
      "avenue.",
      "!emote looks frustrated at the garbage collecting on the "
      "avenue.",
      "!emote looks frustrated at the garbage collecting on the "
      "avenue.",
      "!speak I love this new bazaar but I sure wish people would "
      "stop littering on our streets.",
      "!speak sometimes I don't know why I bother...",
      "!mutter",
      "!mutter",
      "!mutter",
             }) );
   SetInventory( ([ 
      JID_OBJ + "/clothing/evoker_robe" : "wear robe",
      JID_OBJ + "/clothing/sandals" : "wear sandals",
   ]) );
}
