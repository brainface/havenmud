// Pirate Invasion of Haven
// Original coder: Unknown
// Edited: Laoise, 2005

#include <lib.h>
#include "../pih.h"
inherit LIB_INVADER;
int CheckSprite();


static void create() {
   string array wanderpathlist = ({
     ({ "go north","go west","go west","sneak smithy",
       "backstab naythen" }),
     ({ "go north","go west","go west","go west",
       "sneak store","backstab taylor" }),
     ({ "go north","go west","go west","go west",
       "go west","sneak armoury","backstab fidget" }),
     ({ "sneak tavern","backstab yrslim","kill brook" }),
     ({ "go north","go north","go north","go north",
       "go west","go west","go west","sneak bank", "backstab ilian" }),
     ({ "go north","go north","go north","go north",
       "go west","go west","go west","sneak inn", "backstab rupert" }),
     ({ "go north","go west","go west","enter inn", "kill inkeeper", }),
     ({ "go north","go west","go west","go west", "enter inn",
       "kill innkeeper" }),
   })[random(8)];

   invader::create();
   SetKeyName("pirate");
     SetEnemyTown("Haven");
   SetShort("an ugly pirate");
   SetId( ({ "pirate", "pirate_inv" }) );
   SetAdjectives( ({ "ugly" }) );
   SetLong(
     "The pirate is ugly.  His face is marked with scars and "
     "one of his eyes is missing.  He is an orc.  His leg is "
     "a block of wood.  He has been in many fights in his youth, but "
     "he turned from the ways of brawling after he lost "
     "his leg.  Now, he studies the arts of magic, and the "
     "confident aura around him seems to suggest that he "
     "has reached some level of competence."
   );
   SetStat("intelligence",60,1);
   SetRace("orc");
   SetGender("male");
   SetClass("evoker");
   SetLevel(20); // 60
   SetMorality(-500);
   SetInventory( ([
     PIH_OBJ + "boots" : "wear boots",
     PIH_OBJ + "shirt" : "wear shirt",
     PIH_OBJ + "pants" : "wear pants",
     PIH_OBJ + "belt" : "wear belt",
     PIH_OBJ + "eyepatch" : "wear patch",
     PIH_OBJ + "knife" : "wield first knife in right hand",
     PIH_OBJ + "knife2" : "wield first knife in left hand"
   ]) );
   SetCurrency("oros",2500+random(1000));
   SetAction(5, ({ 
     "!cast aura",
     "!shout Com'on, maties!  There's more fun over'ere!",
     "!speak arrr!",
     "!growl",
     "!speak Where are yer women?  Send one over'ere!",
     "!say Where's the rum?",
     "!speak AArrggh!",
     "!speak Shiver me timbers!",
     "!speak I can still beat yer sorry body to bits with my magic!" 
   }));
   SetCombatAction(40, ({ 
     "!cast fireball",
     "!cast bolt",
     "!cast chain lightning",
     "!cast aura",
     "!cast missile",
     "!cast acid blast",
     "!cackle",
     "!speak Die, ye landlubber!",
     "!shout Com'ere, mateys!  Help me dispose of this scurvy landlubber!"
   }) );
   SetSpellBook( ([
     "fireball" : 100,
     "bolt" : 100,
     "chain lightning" : 100,
     "aura" : 100,
     "acid blast" : 100,
     "missile" : 100,
   ]) );
   SetFriends( ({ "pirate_inv" }) );
   SetWanderSpeed(5);
   SetWanderPath(wanderpathlist);
   SetEncounter( (: CheckSprite :) );
}

int CheckSprite() {
  object who = this_player();
  if (!userp(who) && !(who->GetProperty("invader")) ) {
    eventForce("attack " + who->GetKeyName());
  return 1;
  }
return 0;
}

