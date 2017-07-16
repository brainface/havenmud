
#include <lib.h>
#include <std.h>
#include <daemons.h>
#include "../durgoroth.h"
inherit LIB_LEADER;
 
static void create() {
  leader::create();
  SetKeyName("Ahzrikh");
  SetRace("daemon");
  SetClass("shaman");
  SetSkill("poison magic",1,1);
  SetLevel(250);
  SetGender("male");
  SetShort("Ahzrikh the Chosen Avatar of Magic");
  SetId( ({ "ahzrikh","avatar","shaman" }) );
  SetLong("A towering eight foot daemon, Ahzrikh bulges"
          " with muscles. His scarlet scales are the"
          " color of human blood - a fact that surely"
          " has been tested and proved on multiple"
          " occasions. His head is topped with two"
          " massive horns that spiral to a point a"
          " foot above his head. Without a doubt,"
          " Azhrikh's physical power alone should"
          " be enough to frighten the strongest of"
          " would be challengers.");
  SetUniqueSkills( ([
      "blunt combat" : 0,
      "blunt combat" : 3,
      "melee combat" : 1,
      "necromancy" : 1,
      "evokation" : 0,
      "evokation" : 2,
      "parry" : 0,
      "dodge" : 3,
      "stealth" : 0,
      "combat rage" : 3,
      ]) );
  SetTaughtSpheres( ({
      "clerical",
      "religion saahagoth",
      "clerical evokation",
      "clerical necromancy",
      "necromancy",
      "evokation",
      }) );
  SetSpellBook( ([
    "avalanche"          : 100,
    "soul taint"         : 100,
    "maddening visions"  : 100,
    "cause bleeding"     : 100,
    "flamestrike"        : 100,
    "curse"              : 100,
    "unholy guardian"    : 100,
    "touch of death"     : 100,
    "temperature shield" : 100,
    "unholy power"       : 100,
    ]) );
  SetAction(10, ({
    "!roar",
    "!cackle",
    "!speak The protective aura Taigis has provided here is all"
            " that keeps me from devouring you.",
    }) );
  SetCombatAction(50, ({
    "!cast maddening visions",
    "!cast soul taint",
    "!cast cause bleeding",
    "!cast curse",
    "!cast touch of death",
    "!cackle",
    "!cast soul tap",
    "!cast flamestrike",
    "!cast avalanche",
    }) );
  SetReligion("Saahagoth","Saahagoth");
  SetTown("Durgoroth");
  SetMorality(-2500);
  SetPlayerTitles( ([
      "newbie"   : "the Pathetic",
      "mortal"   : "the Hand of Taigis",
      "hm"       : "the Entropic Abomination",
      "legend"   : "the Creature of Nightmares",
      "avatar"   : "the Long-Lived Disciple of Chaos",
     ]) );
  SetFreeEquip( ([
     "/std/weapon/melee/brass_knuckles" : 1,
     DURG_OBJ "scale_robe" : 1,
     ]) );
  SetInventory( ([
     "/std/weapon/melee/brass_knuckles" : "wield knuckles",
     DURG_OBJ "scale_robe"              : "wear robe",
     DURG_OBJ "bone_horseshoe"          : "wear 1st shoe on left hoof",
     DURG_OBJ "bone_horseshoe2"         : "wear 1st shoe on right hoof",
     ]) );
  SetCurrency("crystals", 5000);
  SetFirstCommands( ({ 
    "cast unholy power",
    "cast temperature shield",
    "cast temperature shield",
    "cast unholy guardian",
    "cast unholy guardian",
    "cast unholy guardian",
  }) );
}



void heart_beat() {
  ::heart_beat();
  if (sizeof(GetMagicProtectionNames()) < 3) {
    eventForce("unholy guardian");

  }
}
