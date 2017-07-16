//
// The Jidoor City Guard
// Created by Zaxan@Haven
//

#include <lib.h>
#include "../jidoor.h"

inherit LIB_NPC;
#include "../wanted.h"

int CheckWanted();

static void create() {
   npc::create();
   SetKeyName("guard");
   SetId( ({ "guard", "jid_protect" }) );
   SetAdjectives( ({ "city" }) );
   SetShort("a city guard");
   SetLong("This guard is very strong for a sprite. His eyes shift "
           "back and forth very carefully, watching the city of "
           "Jidoor.");
   SetLevel(25);
   SetGender("male");
   SetMorality(25);
   SetRace("sprite");
   SetClass("fighter");
   SetClass("enchanter");
   SetSpellBook( ([ 
      "chain lightning" : 100,
      "disintegrate" : 80,
      "enhanced fireball" : 100,
      "aura" : 100,
      "fireball" : 100,
      "buffer" : 100,
   ]) );
   SetCurrency("rupies",random(300)+200);
   SetCombatAction(50, ({ 
      "!speak Nobody will harm the city statue!",
      "!speak how dare you cause this kind of trouble in "
       "the great city of Magic?",
      "!speak You evil fiend!",
      "!cast disintegrate",
      "!cast chain lightning",
      "!cast enhanced fireball",
      "!cast fireball",
      "!cast aura",
      "!cast buffer",
   }) );
   SetInventory( ([ 
      JID_OBJ "/sword" : "wield sword",
      JID_OBJ + "/clothing/enchanter_robe" : "wear robe",
      JID_OBJ + "/clothing/sandals" : "wear sandals",
   ]) );
   SetDie("The guard falls dead.");
   SetFriends( ({ "guard", "citizen","child" }) );
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
