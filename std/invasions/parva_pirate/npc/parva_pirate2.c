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
     ({ "go up","go south","go west","enter store",
       "kill pons" }),
     ({ "go up","go south","go west","enter store",
       "kill snop" }),
     ({ "go up","go south","go west","go west",
       "enter store","kill poisa" }),
     ({ "go up","go south","go west","go west",
       "go west","enter town hall","kill samson" }),
     ({ "go up","go south","go west","go west",
       "go west","enter bank","kill banker" }),
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
   SetShort("a growling pirate");
   SetId( ({ "pirate", "pirate_inv" }) );
   SetAdjectives( ({ "growling" }) );
   SetLong(
     "The pirate looks mad and angry at the world.  He growls "
     "constantly, muttering under his breath.  His anger "
     "makes him a doubly dangerous opponent, and he looks "
     "highly skilled."
   );
   SetGender("male");
   SetClass("rogue");
   SetClass("merchant");
   SetLevel(30);
   SetStat("luck",70,1);
   SetStat("coordination",80,1);
   SetStat("agility",80,1);
   SetStat("strength",70,1);
   SetRace("half-elf");
   SetMorality(-500);
   SetInventory( ([
     PIP_OBJ + "hat" : "wear hat",
     PIP_OBJ + "boots" : "wear boots",
     PIP_OBJ + "shirt" : "wear shirt",
     PIP_OBJ + "pants" : "wear pants",
     PIP_OBJ + "belt" : "wear belt",
     PIP_OBJ + "knife" : "wield first knife in right hand",
     PIP_OBJ + "knife2" : "wield first knife in left hand"
   ]) );
   SetCurrency("oros",1000+random(750));
   SetAction(7, ({ 
     "!growl",
     "!speak Shiver me timbers!",
     "!speak Where's da rum?", 
     "!speak Time to get drunk, mateys!",
     "!speak Where's the gold at, landlubbers?",
     "!speak Gimme yer oros before I have my way with your woman!",
     "!speak Arrgh, so be it, where's your woman?",
     "!growl",
     "!speak Gimme a wench or two or three!",
     "!speak find me da rum!",
     "!speak Har har har!",
   }));
   SetCombatAction(10, ({ 
     "!speak Die, ye blasted landlubber!",
     "!speak Arrr!",
     "!speak Arrggh!",
     "!growl",
     "!mutter",
     "!speak Ha! No landlubber will ever defeat us'n pirates!",
     "!shout Com'ere, mateys!  Join the fun!",
     "!cackle",
     "!yell Death to Parva!",
     "!speak Foolish people! You think you can run a ship?",
     "!speak Har har har!" }) );
   SetFriends( ({ "pirate_inv" }) );
   SetWanderSpeed(5);
   SetWanderPath(wanderpathlist);
}
