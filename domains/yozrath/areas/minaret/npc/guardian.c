#include <lib.h>
#include "../minaret.h"
#include <damage_types.h>
#include <size.h>
#include <damage_types.h>
inherit LIB_SENTIENT;

static void create() {
  string pronoun = "He";
  string objective = "him";
  string possessive = "his";
  sentient::create();
  if(random(2)) { SetGender("male"); }
   else  {
   SetGender("female");
   pronoun = "She"; 
   objective = "her";
   possessive = "her";
  }

  SetKeyName("guardian");
  SetProperty("minaretnoleave", 1);
  SetFriends( ({
    "thri-kreen"
  }) );
  SetId( ({ "guardian", "thri-kreen" }) );          
  SetAdjectives( ({ "thri-kreen" }) );
  SetShort("a thri-kreen guardian");      
  SetLong(
    "The thri-kreen guardian is an insectoid creature with an "
    "extra set of arms growing from "+possessive+" torso.  "
    +pronoun +" has a wise and serene look upon "+possessive+" face.  "
    "The outer layer of this insectoid's skin is covered "
    "in an exosekelton of hard armour."
  );                                                             
  SetFirstCommands( ({
    "wield gythka in upper right hand and and upper left hand",
    "cast force of nature",
//    "cast animalistic protection",
//    "cast animalistic protection",
    "wield all",
  }) );
  SetRace("thri-kreen");
  SetReligion("Magildan");
  SetResistance(ACID, "immune");
  SetResistance(COLD, "weakness");
  SetSize(SIZE_LARGE);
  SetInventory( ([
    MIN_OBJ "/gythka" : 1,
    MIN_OBJ "/chatkcha" : 2,
    MIN_OBJ "/green_exo" : "wear exoskeleton on torso and "
      "upper right arm and right leg and upper left arm and left leg",
    ]) );
  SetClass("druid");
  SetSkill("accuracy", 1, 1);
  SetLevel(210);
  SetCombatAction(15, ({
    "!cast plant strike",
  }) );
  SetSpellBook( ([
    "force of nature" : 100,
//    "animalistic protection" : 100,
    "plant strike" : 100,
  ]) );
}

//void init() {
//  sentient::init();
//}


//void heart_beat() {
//  ::heart_beat();
//  if (sizeof(GetMagicProtectionNames()) < 2) {
//    eventForce("cast animalistic protection");
//  }
//}
