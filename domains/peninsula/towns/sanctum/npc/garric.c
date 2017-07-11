#include <lib.h>
#include <std.h>
#include <daemons.h>
#include "../rome.h"
inherit LIB_LEADER;

static void create() {
  ::create();
  SetId( ({ "garric" }) );
  SetKeyName("garric");
  SetShort("Garric, Thorian High Priest");
  SetGender("male");
  SetMorality(0);
  SetTown("Sanctum");
  SetRace("human");
  SetReligion("Thorian");
  SetClass("priest");
  SetSkill("poison magic", 1, 1);
  SetLevel(150);
  RemoveLanguage("Enlan");
  SetLanguage("Imperial", 100, 1);
  SetLong("High Priest Garric is the leader of the Thorian religion "
          "in the Empire. His gaze causes fear in the hearts of many, "
          "yet staring at him for a long period of time shows that he "
          "has a great sadness and even greater hope about him.");

  SetLimit(1);  
  SetFriends( ({ 
  	"narrin",
    }) );
  SetUniqueSkills( ([
    "blunt combat" : 0,
    "knife combat" : 1,
    ]) );
   SetTaughtSpheres( ({
    "clerical",
    "religion thorian",
    "clerical evokation",
    "clerical healing",
    "clerical enchantment",
    "clerical necromancy",
    }) );
   SetPlayerTitles( ([  
     "newbie"  : "the Infected Friar",
     "mortal"  : "the Diseased Cleric",
     "hm"      : "the Tainted Bishop",
     "legend"  : "the Plague-Wrought Cardinal",
     "avatar"  : "Pocked $N the Decayed Bringer of Oblivion",
     "bard"    : "the Voice of Oblivion",
     "fighter" : "the Plague Ridden Monk of Epidemics",
     ]) );
  SetFreeEquip( ([
    STD_ARMOUR "shirt/studded_leather" : 1,
    "/std/weapon/knife/freeknife" : 1,
    ]) );
  SetInventory ( ([
    STD_WEAPON "knife/freeknife" : "wield knife",
    ROME_OBJ "toga_evil" : "wear toga",
    ]) ); 
  SetSpellBook( ([
    "wall of souls"    : 100,
    "pious obstructions"   :  100,
    "persistent bane"  :  100,
    "major venomous touch" : 100,
    "gangrene" : 100,
    ]) );
  SetAction(5, ({
    "!speak When one life ends, another begins",
    "!speak Death is not to be feared, but embraced.",
    "!speak When your time comes, you will seek death and you will decay!",
    "!speak If Narrin converts you, I can teach you the ways of death!",
    }) );
  SetCombatAction(80, ({
    "!cast major venomous touch",
    "!cast persistent bane",
    "!cast gangrene",
    }) );
  SetFirstCommands( ({ 
    "cast pious obstructions", 
    "cast pious obstructions", 
    "cast pious obstructions", 
    "cast pious obstructions", 
    "cast pious obstructions", 
 	  }) );
}

void heart_beat() {
  ::heart_beat();
  if (sizeof(GetMagicProtectionNames()) < 5) {
    eventForce("cast pious obstructions");
  }
}
