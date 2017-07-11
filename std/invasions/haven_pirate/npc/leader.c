// Pirate Invasion of Haven
// Original coder: Unknown
// Edited: Laoise, 2005

#include <lib.h>
#include "../pih.h"
inherit LIB_INVADER;

string GetRandomName();
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
   })[random(6)];

   string ldrName = GetRandomName();
   
   invader::create();
   SetKeyName(ldrName);
   SetShort(ldrName);
  SetEnemyTown("Haven");   
   SetId( ({ "pirate", "captain", "pirate_inv" }) );
   SetAdjectives( ({ "pirate" }) );
   SetLong(
     "The pirate captain has an ugly grin covering his "
     "face. He got his position as captain by being "
     "the best fighter and the most cunning of all his "
     "crew. Evilness exudes from him."
   );
   SetRace("human");
   SetGender("male");
   SetClass("rogue");
   SetSkill("slash attack",1,1);
   SetSkill("knife attack",1,1);
   SetSkill("slash defense",1,1);
   SetSkill("knife defense",1,1);
   SetLevel(50);
   SetLanguage("enlan",100,1);
   SetMorality(-900);
   SetInventory( ([
     PIH_OBJ + "boots2" : "wear boots",
     PIH_OBJ + "shirt2" : "wear shirt",
     PIH_OBJ + "pants2" : "wear pants",
     PIH_OBJ + "belt2" : "wear belt",
     PIH_OBJ + "knife3" : "wield knife",
     PIH_OBJ + "sword" : "wield sword",
/*
     PIH_OBJ + "tiara" : 1,
*/
   ]) );
   SetAction(10, ({ 
     "!speak in drakem Have at ye, landlubbers!",
     "!emote belches disgustingly.",
     "!speak in drakem Let's loot this village, mates!",
     "!speak in drakem Arrr.",
     "!speak in drakem I need myself a wench!",
     "!speak in drakem argh.", 
   }));
   SetCombatAction(10, ({ 
     "!disarm",
     "!yell Arrrgh!",
     "!disorient",
     "!shout Com'ere, mateys!  Help yer cap'n!",
     "!cackle",
   }) );
   SetFriends( ({ "pirate_inv" }) );
   SetWanderSpeed(5);
   SetWanderPath(wanderpathlist);
   SetEncounter( (: CheckSprite :) );
}

string GetRandomName() {
   string *theNames = ({ 
     "Blythe","Blood","Two Teeth","Greybeard",
     "Killingsworth","Blackmane","Redbeard",
     "Ming","One-eye","Stuart",
     "Bone","Phillip Black","Bob",
     "Mac Donnigal","Theodore Hate","Kaen",
     "Morgan","Phineas the Frog","Acteon",
     "Mondriak","Su the Terrible","Morrigan",
     "Muurias","Edward the Duevil"
   });
   return ("Captain " + theNames[random(sizeof(theNames))]);
}

int CheckSprite() {
  object who = this_player();
  if (!userp(who) && !(who->GetProperty("invader")) ) {
    eventForce("attack " + who->GetKeyName());
  return 1;
  }
return 0;
}
