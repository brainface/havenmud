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
       "go west","go west","go west","sneak bank",
       "backstab ilian" }),
     ({ "go north","go north","go north","go north",
       "go west","go west","go west","sneak inn", "backstab rupert" }),
     ({ "go north","go west","go west","enter inn", "kill inkeeper", }),
     ({ "go north","go west","go west","go west", "enter inn",
       "kill innkeeper" }),
   })[random(8)];
   invader::create();
  SetEnemyTown("Haven");
   SetKeyName("pirate");
   SetShort("a growling pirate");
   SetId( ({ "pirate", "pirate_inv" }) );
   SetAdjectives( ({ "growling" }) );
   SetLong(
     "The pirate looks mad and angry at the world.  He growls "
     "constantly, muttering under his breath.  His anger "
     "makes him a doubly dangerous opponent, and he looks "
     "highly skilled."
   );
   SetStat("luck",70,1);
   SetStat("coordination",80,1);
   SetStat("agility",80,1);
   SetStat("strength",70,1);
   SetRace("dwarf");
   SetGender("male");
   SetClass("rogue");
   SetLevel(30);
   SetMorality(-500);
   SetEncounter( (: CheckSprite :) );
   SetInventory( ([
     PIH_OBJ + "hat" : "wear hat",
     PIH_OBJ + "boots" : "wear boots",
     PIH_OBJ + "shirt" : "wear shirt",
     PIH_OBJ + "pants" : "wear pants",
     PIH_OBJ + "belt" : "wear belt",
     PIH_OBJ + "knife" : "wield first knife in right hand",
     PIH_OBJ + "knife2" : "wield first knife in left hand",
   ]) );
   SetCurrency("oros",2000+random(750));
   SetAction(7, ({ 
     "!growl",
     "!speak Shiver me timbers!",
     "!speak Where's da rum?",
     "!speak Time to get drunk, mateys!",
     "!speak Where's the gold at, landlubbers?",
     "!speak Gimme yer oros before I have my way with your woman!",
     "!speak Arrgh, so be it, where's your woman?", 
   }));
   SetCombatAction(10, ({ 
     "!disarm",
     "!disorient",
     "!speak Arrggh!",
     "!growl",
     "!mutter",
     "!speak Ha!  No landlubber will ever defeat us'n pirates!",
     "!shout Com'ere, mateys!  Join the fun!",
     "!cackle" ,
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
