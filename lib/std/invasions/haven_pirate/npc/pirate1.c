// Pirate Invasion of Haven
// Original coder: Unknown
// Edited: Laoise, 2005

#include <lib.h>
#include "../pih.h"
inherit LIB_INVADER;

int CheckSprite();

static void create() {
   string array wanderpathlist = ({
     ({ "go north","go west","go west","enter smithy",
       "kill naythen" }),
     ({ "go north","go west","go west","go west",
       "enter store","kill taylor" }),
     ({ "go north","go west","go west","go west",
       "go west","enter armoury","kill fidget" }),
     ({ "enter tavern","kill yrslim","kill brook" }),
     ({ "go north","go north","go north","go north",
       "go west","go west","go west","enter bank", "kill ilian" }),
     ({ "go north","go north","go north","go north",
       "go west","go west","go west","enter inn", "kill rupert" }),
     ({ "go north","go west","go west","enter inn", "kill innkeeper" }),
     ({ "go north","go west","go west","go west",
       "enter inn","kill innkeeper" }),
   })[random(8)];

   invader::create();
   SetKeyName("pirate");
   SetEnemyTown("Haven");
   SetShort("a strong pirate");
   SetId( ({ "pirate", "pirate_inv" }) );
   SetAdjectives( ({ "strong" }) );
   SetLong(
     "The pirate has a buff physique.  He is kind of short for an "
     "elf, but thick with muscle.  He appears to be the sort that "
     "is used to brawling with his bare hands, and he with his "
     "strength, he is probably very good at it."
   );
   SetStat("strength",90,1);
   SetRace("elf");
   SetGender("male");
   SetClass("fighter");
   SetSkill("stealing",1,1);
   SetSkill("stealth",1,1);
   SetLevel(25);
   SetMorality(-500);
   SetEncounter( (: CheckSprite :) );
   SetInventory( ([
     PIH_OBJ + "boots" : "wear boots",
     PIH_OBJ + "shirt" : "wear shirt",
     PIH_OBJ + "pants" : "wear pants",
     PIH_OBJ + "belt" : "wear belt",
   ]) );
   SetCurrency("oros",1500+random(500));
   SetAction(6, ({ 
     "!growl",
     "!mutter",
     "!speak Arrgh!",
     "!speak Arrrr.",
     "!speak Where are the wenches?",
     "!shout Com'ere mates! Let's find dem wenches!",
     "!speak Yo, ho, ho! "
     "!speak Where do they store the rum?" 
   }));
   SetCombatAction(10, ({ 
     "!disarm",
     "!roar",
     "!growl",
     "!shout Com'ere and kill this landlubber with me!",
     "!speak Har har!  Die!" 
   }) );
   SetFriends( ({ "pirate_inv" }) );
   SetWanderSpeed(5);
   SetWanderPath(wanderpathlist);
}

int CheckSprite() {
  object who = this_player();
  if (!userp(who) && !(who->GetProperty("invader")) ) {
    eventForce("attack " + who->GetKeyName());
  return 1;
  }
return 0;
}
