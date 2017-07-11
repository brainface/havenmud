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

  SetKeyName("mystic");
  SetProperty("minaretnoleave", 1);
  SetId( ({ "mystic", "thri-kreen" }) );          
  SetAdjectives( ({ "thri-kreen" }) );
  SetShort("a thri-kreen mystic");      
  SetLong(
    "The thri-kreen mystic is an insectoid creature with an "
    "extra set of arms growing from "+possessive+" torso.  "
    +pronoun+" is the largest thri-kreen and has an ancient, "
    "timeless face.  "
    "The outer layer of "+possessive+" skin is covered "
    "in an exosekelton of hard armour."
  );                                                             
  SetFirstCommands( ({
    "wield gythka in upper right hand and and upper left hand",
    "cast cavern call",
    "cast aetheric rift",
    "cast aetheric rift",
    "cast aetheric rift",
    "cast force of nature",
    "wield chigirikis",
  }) );
  SetAction(15, ({
    "!emote studies something through the telescope.",
    "!say Where is it hiding..?",
    "!emote shakes "+possessive+" head in frustration.",
    }) );
  SetRace("thri-kreen");
  SetReligion("Magildan");
  SetResistance(ACID, "immune");
  SetSize(SIZE_LARGE);
  SetInventory( ([
    MIN_OBJ "/bottle" : 1,
    MIN_OBJ "/gythka" : 1,
    MIN_OBJ "/chigiriki" : 2,
  MIN_OBJ "/blue_exo" : "wear exoskeleton on torso and "
        "upper right arm and right leg and upper left arm and left leg",
    ]) );
  SetClass("mystic");
  SetSkill("ice magic", 1, 1);
  SetSkill("accuracy", 1, 1);
  SetSkill("enchantment", 1, 1);
  SetSkill("dodge", 1, 1);
  SetSkill("combat rage", 1, 1);
  SetLevel(random(15) +336);
  SetCombatAction(15, ({
    "!cast plant strike",
    "!cast meteor swarm",
    "!cast fireburst",
    "!cast frostbite",
  }) );
  SetSpellBook( ([
    "meteor swarm" : 100,
    "force of nature" : 100,
    "cavern call" : 100,
    "aetheric rift" : 100,
    "plant strike" : 100,
    "fireburst" : 100,
    "frostbite" : 100,
  ]) );
}

void init() {
  sentient::init();
}


void heart_beat() {
  ::heart_beat();
  if (sizeof(GetMagicProtectionNames()) < 3) {
    eventForce("cast aetheric rift");
  }
}

varargs int eventDie(object killer) {
  if (killer) killer->AddTitle("the Mystic Murderer");
  return::eventDie(killer); 
  }
