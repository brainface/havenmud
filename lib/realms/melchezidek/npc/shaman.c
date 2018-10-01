
#include <lib.h>
#include <std.h>
#include <daemons.h>
#include "durgoroth.h"
inherit LIB_LEADER;
 
static void create() {
  leader::create();
  SetKeyName("Ahzrikh");
  SetRace("daemon");
  SetClass("shaman");
  SetSkill("poison magic",1,1);
  SetLevel(150);
  SetGender("male");
  SetShort("Ahzrikh, Taigis' Chosen Avatar of Magic");
  SetId( ({ "ahzrikh","avatar","shaman" }) );
  SetLong("Is a buff dude.");
  SetUniqueSkills( ([
      "blunt combat" : 3,
      "melee combat" : 1,
      "necromancy" : 1,
      "evokation" : 2,
      "parry" : 0,
      "dodge" : 3,
      ]) );
  SetTaughtSpheres( ({
      "clerical",
      "religion saahagoth",
      "clerical evokation",
      "clerical necromancy",
      "necromancy"
      "evokation",
      }) );
  SetSpellBook( ([
    "asphyxiation"      : 100,
    "soul taint"        : 100,
    "maddening visions" : 100,
    "cause bleeding"    : 100,
    "ennervate"         : 100,
    "curse"             : 100,
    "wall of souls"     : 100,
    "touch of death"    : 100,
     ]) );
  SetAction(10, ({
    "!roar",
    "!cackle
    "!speak The protective aura Taigis has provided here is all"
            " that keeps me from devouring you.",
    }) );
  SetCombatAction(50, ({
    "!cast asphyxiation",
    "!cast maddening visions",
    "!cast soul taint",
    "!cast ennervate",
    "!cast cause bleeding",
    "!cast curse",
    "!cast touch of death",
    "!cackle",
    }) );
  SetReligion("Kylin","Kylin");
  SetTown("Haven");
  SetMorality(1500);
  SetPlayerTitles( ([
      "newbie"   : "the Pathetic",
      "mortal"   : "the Hand of Taigis",
      "hm"       : "the Entropic Abomination",
      "legend"   : "the Creature of Nightmares",
      "avatar"   : "the Long-Lived Disciple of Chaos",
     ]) );
  SetFreeEquip( ([
     "/std/weapon/melee/brass_knuckles" : 1,
     ]) );
  SetInventory( ([
     "/std/weapon/melee/brass_knuckles" : "wield knuckles",
     ]) );
  }
