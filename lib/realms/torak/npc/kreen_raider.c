// Torak 8/12/2013

#include <lib.h>
#include <domains.h>
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

  SetKeyName("raider");
  SetId( ({ "raider", "kreen", "thri-kreen" }) );
  SetAdjectives( ({ "thri-kreen" }) );
  SetShort("a thri-kreen raider");
  SetLong(
    "The thri-kreen warrior is an insectoid creature with an "
    "extra set of arms growing from "+possessive+" torso.  "
    +pronoun + " has a vicious look upon its face.  "
    "The outer layer of this insectoid's skin is covered "
    "in an exosekelton of hard armour."
  );
  SetRace("thri-kreen");
  SetClass("horror");
  SetSkill("natural armour", 1, 1);
  SetSkill("brawling", 1, 1);
  SetLevel(101);
  SetResistance(COLD, "weakness");
  SetResistance(ACID, "immune");
  SetFirstCommands( ({
    "wield all",
  }) );
  SetReligion("Kuthar");
  SetInventory( ([
    YOZRATH_VIRTUAL "obj/chitin_chigiriki" : 4,
    YOZRATH_VIRTUAL "obj/raider_exo" : "wear exoskeleton on torso and "
        "upper right arm and right leg and upper left arm and left leg",
    ]) );
  SetCombatAction(15, ({
    "!disorient",
    "!uppercut",
    "!punch",
    "!headbutt",
  }) );
}
