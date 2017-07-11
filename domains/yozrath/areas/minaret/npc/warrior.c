#include <lib.h>
#include "../minaret.h"
#include <damage_types.h>
#include <size.h>
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

  SetKeyName("warrior");
  SetProperty("minaretnoleave", 1);
  SetId( ({ "warrior", "thri-kreen" }) );
  SetAdjectives( ({ "thri-kreen" }) );
  SetShort("a thri-kreen warrior");
  SetLong(
    "The thri-kreen warrior is an insectoid creature with an "
    "extra set of arms growing from "+possessive+" torso.  "
    +pronoun + " has a vicious look upon its face.  "
    "The outer layer of this insectoid's skin is covered "
    "in an exosekelton of hard armour.  The shear size "
    "of this insectoid makes "+objective+" a formidable foe.  "
  );
  SetRace("thri-kreen");
  SetClass("ninja");
  SetSkill("natural armour", 1, 1);
  SetSkill("brawling", 1, 1);
  SetLevel(230);
  SetResistance(COLD, "weakness");
  SetResistance(ACID, "immune");
  SetFirstCommands( ({
    "wield all",
  }) );
  SetReligion("Magildan");
  SetSize(SIZE_LARGE);
  SetInventory( ([
    MIN_OBJ "/chigiriki" : 2,
    MIN_OBJ "/chatkcha" : 2,
    MIN_OBJ "/red_exo" : "wear exoskeleton on torso and "
        "upper right arm and right leg and upper left arm and left leg",
    ]) );
  SetSpellBook( ([
    "full regeneration" : 100,
    ]) );
  SetCombatAction(15, ({
    "!disorient",
    "!uppercut",
    "!punch",
    "!headbutt",
    "!cast full regeneration",
  }) );
  SetEncounter(125);
}

