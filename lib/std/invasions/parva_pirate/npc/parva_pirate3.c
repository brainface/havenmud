// Pirate invasion of Parva
// Original coder: Unknown
// Edited: Laoise, 2005
// Edited: Ohtar, 2009

#include <lib.h>
#include "../pip.h"
inherit LIB_INVADER;


static void create() {
   string array wanderpathlist = ({
     ({ "kill fisherman" }),
     ({ "go up","go south","go west","enter inn",
       "kill first drunk" }),
     ({ "go up","go west","kill owner" }),
     ({ "go up","go south","go west","enter store", "kill pons" }),
     ({ "go up","go south","go west","enter store", "kill snop" }),
     ({ "go up","go south","go west","go west", "enter store",
       "kill poisa" }),
     ({ "go up","go south","go west","go west", "go west",
       "enter town hall","kill samson" }),
     ({ "go up","go south","go west","go west", "go west",
       "enter bank","kill banker" }),
     ({ "go up","go south" }),
     ({ "go up","go south","go south" }),
     ({ "go up" }),
     ({ "go up","go south","go west" }),
     ({ "go up","go south","go west","go west" }),
     ({ "go up","go south","go west","go west", "go south" }),
     ({ "go up","go south","go west","go west", "go west" }),
   })[random(15)];

   invader::create();
   SetKeyName("pirate");
   SetEnemyTown("Parva");    
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
   SetRace("human");
   SetGender("male");
   SetClass("evoker");
   SetLevel(20); 
   SetStat("intelligence",60,1);
   SetMorality(-500);
   SetInventory( ([
     PIP_OBJ + "boots" : "wear boots",
     PIP_OBJ + "shirt" : "wear shirt",
     PIP_OBJ + "pants" : "wear pants",
     PIP_OBJ + "belt" : "wear belt",
     PIP_OBJ + "eyepatch" : "wear patch",
     PIP_OBJ + "knife" : "wield first knife in right hand",
     PIP_OBJ + "knife2" : "wield first knife in left hand"
   ]) );
   SetCurrency("oros",1000+random(1000));
   SetAction(5, ({ 
     "!cast aura",
     "!shout Com'on, maties! There's more fun over'ere!",
     "!speak arrr!",
     "!growl",
     "!speak Where are yer women? Send one over'ere!",
     "!say Where's the rum?",
     "!speak Aarrggh!",
     "!speak Shiver me timbers!",
     "!speak I can still beat yer sorry body to bits with my magic!",
     "!speak Let's go get dees pretend seamen! Dees idiotic "
       "fisherman that don't know nothin' about the sea!",
     "!speak Death to Parva!",
     "!speak Curse ye all!",
     "!speak You fake seamen! Get me a wench or I'll kill ya all!",
     "!speak Ha ha ha, Parva will die!" 
   }));
   SetCombatAction(35, ({ 
     "!cast fireball",
     "!cast bolt",
     "!cast chain lightning",
     "!cast aura",
     "!cast missile",
     "!cast acid blast",
     "!cackle",
     "!speak Die, ye landlubber!",
     "!shout Com'ere, mateys! Help me dispose of this scurvy "
       "landlubber!",
     "!speak Har har har! Die!",
     "!snarl",
   }) );
   SetSpellBook( ([
     "fireball" : 100,
     "bolt" : 100,
     "chain lightning" : 100,
     "aura" : 100,
     "acid blast" : 100,
     "missile" : 100,
   ]) );
   SetWanderSpeed(5);
   SetWanderPath(wanderpathlist);
}
