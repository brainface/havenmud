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
     ({ "go up","go south","go west","go west",
       "enter store","kill poisa" }),
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
   SetShort("a strong pirate");
   SetId( ({ "pirate" }) );
   SetAdjectives( ({ "strong" }) );
   SetLong(
     "The pirate has a buff physique.  He is kind of short for an "
     "elf, but thick with muscle.  He appears to be the sort that "
     "is used to brawling with his bare hands, and he with his "
     "strength, he is probably very good at it."
   );
   SetRace("human");
   SetGender("male");
   SetClass("rogue");
   SetSkill("stealing",1,1);
   SetSkill("stealth",1,1);
   SetLevel(25);
   SetStat("strength",90,1);
   SetMorality(-500);
   SetInventory( ([
     PIP_OBJ + "boots" : "wear boots",
     PIP_OBJ + "shirt" : "wear shirt",
     PIP_OBJ + "pants" : "wear pants",
     PIP_OBJ + "belt" : "wear belt",
   ]) );
   SetCurrency("oros",2200+random(500));
   SetAction(6, ({ 
     "!growl",
     "!mutter",
     "!speak Arrgh!",
     "!speak Arrrr.",
     "!speak Where are the wenches?",
     "!shout Com'ere mates! Let's find dem wenches!",
     "!speak Yo, ho, ho! ",
     "!speak Where do they store the rum?",
     "!speak Idiots!  Fools!  Ye think yer a seafaring lad?",
     "!speak Har har har!",
     "!speak Parva will die!",
     "!speak Pirates rule Parva!",
     "!speak Get me da run or I'll kill ye all!",
     "!speak I need me a wench!",
   }));
   SetCombatAction(10, ({ 
     "!trip",
     "!kick",
     "!growl",
     "!shout Com'ere and kill this landlubber with me!",
     "!speak Har har!  Die!",
     "!speak Death to Parva!",
     "!speak Foolish Parva people!  Ye canna do nothing right!", 
   }) );
   SetFriends( ({ "pirate_inv" }) );
   SetWanderSpeed(5);
   SetWanderPath(wanderpathlist);
}
