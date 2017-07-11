/* ----------------------------------------------------------------------- */
// Area Title: City of Jidoor
// Filename: eurdice.c
// Author: Derek Noble
// Creator: dylanthalus@haven
// Creation Date: Unknown
// Abstract: Eurdice, Captain of the Guard.
// Revision History:  Base file created by Zaxan@Haven 
//        November 6th, 1998 - Made into a simpler NPC to ensure the wanted
//                               list was not automatic.
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include "../jidoor.h"

inherit LIB_NPC;

#include "../wanted.h"

static void create() {
   npc::create();
   SetKeyName("eurdice");
   SetId( ({ "eurdice", "guard", "captain",
             "captain of the guard","jid_protect"}) );
   SetShort("Eurdice the Captain of the Guard");
   SetLong("This large sprite is captain of the guard, and chief law officer "
           "here in Jidoor. He looks extremely capable of not only "
           "defending himself, but his wards too.");
   SetRace("sprite");
   SetReligion("Magildan","Magildan");
   SetGender("male");
   SetLevel(55);
   SetClass("enchanter");
   SetClass("fighter");
   SetMorality(5);
   SetSpellBook( ([ 
      "chain lightning" : 100,
      "disintegrate" : 80,
      "enhanced fireball" : 100
   ]) );
   SetFriends( ({ "guard", "citizen", "patrol guard", "mingad" }) );
   SetInventory( ([ 
      JID_OBJ + "/sword" : "wield sword",
      JID_OBJ + "/clothing/enchanter_robe" : "wear robe",
      JID_OBJ + "/clothing/sandals" : "wear sandals",
   ]) );
   SetCurrency("rupies",random(1500)+500);
   SetCombatAction(1, ({ 
      "!speak Foolish one, you'll pay with your life for this!",
      "!cast disintegrate",
      "!cast chain lightning",
      "!cast enhanced fireball",
      "!slice",
      "!slice"
   }) );
}

void init() {
   ::init();
   if( (newbiep(this_player())) &&
       (member_array(this_player()->GetKeyName(), Wanted) != -1) ) {
      eventForce("speak I'd get out of the city, "+
                 this_player()->GetName()+". You're in a bit of trouble.");
   }
   if( (!newbiep(this_player())) &&
       (member_array(this_player()->GetKeyName(), Wanted) != -1) ) {
      eventForce("speak Die "+this_player()->GetName()+"! Die!");
      eventForce("follow " + this_player()->GetKeyName());
      eventForce("attack " + this_player()->GetKeyName());
   }
}
