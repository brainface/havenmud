#include <lib.h>
#include <std.h>
#include <daemons.h>
#include "../parva.h"
inherit LIB_LEADER;

static void create() {
  ::create();
  SetId( ({ "savlyc" }) );
  SetKeyName("savlyc");
  SetShort("Savlyc the Decayed");
  
  SetRace("human");
  SetGender("male");
  SetReligion("Thorian");
  SetClass("priest");
  SetSkill("poison magic",1,1);
  SetLevel(70);
  SetTown("Parva");
  SetMorality(-900);
  SetLong("Savlyc the Decayed is the Thorian leader for the city of Parva, "
          "though he is often viewed as the single source of disease and misfortune "
          "by the locals, he is revered by other Thorians. His cold eyes stare "
          "blankly into space as disease has taken his sight as well as left him "
          "disfigured.");
  SetLimit(1);  
  SetUniqueSkills( ([
    "blunt combat" : 0,
    "knife combat" : 1,
    ]) );
   SetTaughtSpheres( ({
    "clerical",
    "religion thorian",
    "clerical evokation",
    "clerical enchantment",
    "clerical necromancy",
    }) );
   SetPlayerTitles( ([  
     "newbie"   : "the Infected Friar",
     "mortal"   : "the Diseased Cleric",
     "hm" 		  : "the Tainted Bishop",
     "legend"   : "the Plague-Wrought Cardinal",
     "avatar"   : "Pocked $N the Decayed Bringer of Oblivion",
     "fighter"  : "the Plague Ridden Monk of Epidemics",
     "chaplain" : "the Plague Bearer of the Seas",
    ]) );
  SetFreeEquip( ([
    STD_WEAPON "knife/freeknife" : 1,
    ]) );
  SetInventory ( ([
    STD_WEAPON "knife/freeknife" : "wield knife",
  	]) ); 
  SetSpellBook( ([
    "wall of souls" : 100,
    "venomous wind" : 100,
    "gangrene" 			: 100,
    ]) );
  SetAction(5, ({
    "!speak Embrace death and as you do understand His will.",
    "!speak Do not fear the end, it comes for us all.",
    }) );
  SetCombatAction(35, ({
    "!cast venomous wind",
    "!cast gangrene",
    }) );
  SetFirstCommands( ({ 
    "cast wall of souls", 
		"cast wall of souls",
		"cast wall of souls",
    "cast wall of souls",
    "cast wall of souls",
  }) );
}

void heart_beat() {
  ::heart_beat();
  if (sizeof(GetMagicProtectionNames()) < 5) {
    eventForce("cast wall of souls",);
  }
}

