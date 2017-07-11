/* ----------------------------------------------------------------------- */
// Area Title: City of Jidoor
// Filename: w_guard.c
// Author: Derek Noble
// Creator: dylanthalus@haven
// Creation Date: Sept 17th, 1998
// Abstract: Patrolling Guard in Jidoor
// Revision History:  Base file created by Zaxan@Haven 
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include "../jidoor.h"

inherit LIB_SENTIENT;

#include "../wanted.h"
int CheckWanted();

static void create() {
   sentient::create();
   SetKeyName("patrol guard");
   SetId( ({ "guard","guard of jidoor", "jid_protect" }) );
   SetAdjectives( ({ "city", "patrolling" }) );
   SetShort("a patrolling guard of Jidoor");
   SetLong("Shifting his eyes around cautiously, this guard wanders the "
           "city of Jidoor ensuring that the peace is maintained.  He looks "
           "quite capable of keeping the peace but seems to be somewhat "
           "friendly as long as the town is in a peaceful state.");
   SetLevel(random(40)+10);
   SetTown("Jidoor");
   SetReligion("Magildan","Magildan");
   SetGender("male");
   SetMorality(25);
   SetRace("sprite");
   SetStat("durability", 55);
   SetClass("fighter");
   SetClass("enchanter");
   SetSpellBook( ([ 
      "chain lightning" : 100,
      "disintegrate" : 80,
      "enhanced fireball" : 100,
      "fireball" : 100,
   ]) );
   SetCurrency("rupies",random(1500)+200);
   SetAction(1, ({ 
      "!emote looks around for signs of trouble.",
      "!emote surveys the area cautiously.",
      "Patrol guard smiles at you.",
      "!look building",
      "!listen",
      "!speak it is indeed a nice day for weather here in Jidoor.",
      "!speak Greetings.",
      "!speak Hello.",
      "!speak Hi there.",
            }) );
   SetCombatAction(50, ({ 
      "!speak Nobody will harm the citizens of our fine city!",
      "!speak Leave our city at once!",
      "!speak You vile fiend!",
      "!yell Guards!",
      "!cast disintegrate",
      "!cast chain lightning",
      "!cast enhanced fireball",
      "!cast fireball",
      "!slice",
      "!slice"
      "!cast disintegrate",
      "!cast chain lightning",
      "!cast enhanced fireball",
      "!cast fireball",
      "!slice",
      "!slice"
   }) );
   SetInventory( ([ 
      JID_OBJ "/sword" : "wield sword",
      JID_OBJ + "/clothing/enchanter_robe" : "wear robe",
      JID_OBJ + "/clothing/sandals" : "wear sandals",
   ]) );
   SetDie("The patrolling guard falls dead.");
   SetFriends( ({ "guard", "citizen", "nervala", "arpal", "auralia", "dolad",
                  "eurdice", "hima", "lorka", "mingad", "opewat", "parcil",
                  "porcil", "purcil", "purlad", "sweeper", "urala", "valora",
                  "waplar", "warlad", "worker", "zurlock", "jacis","malkus",
                  "ryl", "brak", "cainwyn", "dahlia", "juggler","kelsey",
                  "lilah", "raevynn", "robby", "stiltman", "zoe"
             }) );
   SetWander(4);
   SetEncounter( (: CheckWanted : ) );
}

int CheckWanted() {
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
   if(this_player()->GetProperty("invader")) {
     eventForce("yell Invaders!");
     AddEnemy(this_player());
     return 1;
   }
  return 0;
}
