// by Dahaka
// with assistance from Laoise
// Aug 2004

#include <lib.h>
#include <std.h>
#include "../drazh.h"

inherit LIB_LEADER;
void DoCombatSomething();


static void create() {
  leader::create();
  SetKeyName("ikirit");
  SetTown("Drazh");
  SetReligion("Soirin");
  SetId( ({"ikirit","seer","councilman"}) );
  SetAdjectives( ({"seerlord","seer","lord","grey"}) );
  SetShort("Seerlord Ikirit, Grey Seer of Soirin");
  SetLong(
     "Seerlord Ikirit is a large skaven with light grey fur. He is "
	   "skaven of many words. He is one whom openly preaches about the "
	   "faith of Soirin. For Ikirit's faithful service to Soirin, Melchezidek "
	   "has blessed his head priest with the light grey fur, Ikirit now "
	   "wears."
     );
  SetGender("male");
  SetRace("skaven");
  SetClass("priest");
  SetSkill("poison magic",1,2);
  SetLevel(100);
  SetMorality(-2000);
  SetSpellBook( ([
     "miasmic guardian" : 100,
     "touch of death"   : 100,
     "purify"       	  : 100,
     "stab in the dark" : 100,
     "poison weapon"    : 100,
	 ]) );
  SetUniqueSkills( ([
     "blunt combat"    : 0,
     "knife combat"    : 1,
     "stealth"         : 2,
     ]) );
  SetPlayerTitles( ([
     "newbie"	 : "the Grey Seer Initiate of Soirin",
     "mortal"	 : "the Grey Seer Acolyte of Soirin",
     "hm"		   : "the Grey Seer of Soirin",
     "legend"	 : "the Seer Lord of Soirin",
     "rogue"	 : "the Pillaging Vicar of Soirin",
     "fighter" : "the Iniquitous Warrior of Soirin",
     ]) );
  SetFreeEquip( ([
	   "/std/weapon/knife/stiletto" : 1,
     V_OBJ + "lvest"              : 1,
	   ]) );
  SetAction(8, ({
     "!say Melchezidek's faith is the pillar that supports us",
     "!say My lord's will is the foundation of this town.",
     "!nod solem",
     "!grin",
     "!say My Lord has protected us with darkness!",
     "!say Melchezidek has given us a purpose!",
	   }) );
  SetCombatAction(50, (: DoCombatSomething() :) ); 
  SetInventory( ([
     V_OBJ + "vest"      : "wear vest",
	   V_OBJ + "lpants"    : "wear pants",
	   V_OBJ + "grey_robe" : 
	    "wear robe on torso and left arm and right arm and left leg and right leg",
	   ]) );
  SetFirstCommands( ({
     "cast miasmic guardian",
     "cast miasmic guardian",
     }) );
}




void DoCombatSomething(){
object who = this_object();
object target = GetCurrentEnemy();

	if (!random(10)) {
		int randnum = random(2);
		if (randnum == 0) { eventForce("speak you are foolish young one.");}
		else { eventForce("yell you challenge the Seerlord.");}
	}

  switch(random(8)) {
    case 0:
      eventForce("cast touch of death");
      break;
    case 1:
      eventForce("cast purify");
      break;
    case 3:
      if (sizeof(GetMagicProtection()) < 5) 
        eventForce("cast miasmic guardian");
      break;
    case 4:
      if((who->GetWielded() > 0) && (who->GetWielded() < 2))
        eventForce("cast poison weapon on " + who->GetWielded());
      if(who->GetWielded() > 1)
        eventForce("cast poison weapon on " + 
          (random(2) ? who->GetWielded("left claw") : who->GetWielded("right claw")));
      break; 
    default:
      eventForce("cast stab in the dark");
      break;
}
}

