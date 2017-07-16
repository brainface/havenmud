
// Pirate invasion of Parva
// Original Coder: Unknown
// Edited: Laoise, 2005

#include <lib.h>
#include "../pip.h"
inherit LIB_INVADER;

string GetRandomName();

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
   string ldrName = GetRandomName();
   
   invader::create();
   SetKeyName(ldrName);
   SetEnemyTown("Parva");    
   SetShort("a pirate captain");
   SetId( ({ "pirate", "captain", "pirate_inv" }) );
   SetAdjectives( ({ "pirate" }) );
   SetLong(
     "The pirate captain has an ugly grin covering his "
     "face.  He got his position as captain by being "
     "the best fighter and the most cunning of all his "
     "crew.  Evilness exudes from him."
   );
   SetRace("human");
   SetGender("male");
   SetClass("rogue");
   SetClass("merchant");
   SetSkill("slash attack",1,1);
   SetSkill("knife attack",1,1);
   SetSkill("slash defense",1,1);
   SetSkill("knife defense",1,1);
   SetLevel(45);
   SetStat("coordination",60,1);
   SetStat("agilty",60,1);
   SetStat("durability",60,1);
   SetStat("intelligence",60,1);
   SetStat("luck",60,1);
   SetStat("speed",60,1);
   SetStat("strength",60,1);
   SetStat("wisdom",60,1);
   SetMorality(-900);
   SetInventory( ([
     PIP_OBJ + "boots2" : "wear boots",
     PIP_OBJ + "shirt2" : "wear shirt",
     PIP_OBJ + "pants2" : "wear pants",
     PIP_OBJ + "belt2" : "wear belt",
     PIP_OBJ + "knife3" : "wield knife",
     PIP_OBJ + "sword" : "wield sword",
   ]) );
   SetAction(10, ({ 
     "!speak Have at ye, landlubbers!",
     "!emote belches disgustingly.",
     "!speak Let's loot this village pirates!",
     "!speak Arrr.",
     "!speak I need myself a wench!",
     "!speak argh.",
     "!speak Let's loot Parva!",
     "!speak Kill Parva, men!",
     "!speak Bring me a wench, men!",
     "!yell Death to Parva!",
     "!speak Where's me wench, pirates?",
     "!speak Where's me rum, pirates?",
     "!speak Bring me da rum!" }));
   SetCombatAction(10, ({ 
     "!slice",
     "!speak  Arrrgh, "
     "prepare to die!",
     "speak  Arr!",
     "!shout Com'ere, mateys!  Help yer cap'n!",
     "!cackle",
     "!growl",
     "!yell Death to Parva!",
     "!speak How dare ye attack me!",
     "!speak Death to all who oppose me!" }) );
   SetFriends( ({ "pirate_inv" }) );
   SetWanderSpeed(5);
   SetWanderPath(wanderpathlist);
}

string GetRandomName() {
   string *theNames = ({ 
     "Blythe","Blood","Two Teeth","Greybeard",
     "Killingsworth","Blackmane","Redbeard",
     "Ming","One-eye","Stuart", "Bone","Phillip Black",
     "Eduard", "Mac Donnigal","Theodore Hate","Kaen",
     "Morgan","Phineas the Frog","Acteon",
     "Mondriak","Su the Terrible","Morrigan",
     "Muurias","Edward the Duevil" 
   });
   return ("Captain " + theNames[random(sizeof(theNames))]);
}
