/*  A random level dark elf mage */
#include <lib.h>
#include <std.h>
#include "../mage_tower.h"
inherit LIB_SENTIENT;

static void create() {
  ::create();
  SetKeyName("elf mage");
  SetFriends( ({ "dark-elven apprentice" }) );
  SetRace("elf");
  SetUndead(1);
  SetShort("a cursed elven mage");
  SetId( ({ "elf", "mage" }) );
  SetAdjectives( ({ "cursed", "elven" }) );
  
  SetGender("male");
  SetLong("This cursed elven mage seems to have an aura of power "
          "and evil surrounding him which sets him out as someone "
          "to be feared and respected. His magical skills have given "
          "him the sure look of a quick and painful killer.");
  SetClass("evoker");
  SetSkill("melee combat",1,2);
  SetSkill("shock magic",1,2);
  SetSkill("fire magic",1,2);
  SetLevel(random(30) + 70);
  SetReligion("Soirin");
  SetMorality(-1500);
  SetCurrency("imperials", random(50000)+10);
  SetSpellBook( ([
     "energy wall"     : 100,
     "mesmer barrier"  : 100,
     "chain lightning" : 100,
     "fireball"        : 100,
     "disintegrate"    : 100,
     "flamestrike"     : 100,
     ]) );
  SetFirstCommands( ({
  	"cast mesmer barrier",
  	"cast energy wall",
    "cast energy wall",
    }) );
  //call_out( (: eventForce, "cast enhanced aura" :), 0 );
  //call_out( (: eventForce, "cast enhanced buffer" :), 0 );
  SetInventory( ([
    TOWER_OBJ "chest_key" : 1,
    STD_CLOTHING "body/black_robe" : "wear robe",
  ]) );
  SetAction(10, ({
    "!cast mesmer barrier",
    "!smile sadistically",
    "!muah",
    "!chuckle maniacially"
    "!scream loudly",
    "!cast energy wall",
    }) );
  SetCombatAction(50, ({
      "!cast fireball",
      "!cast chain lightning",
      "!cast flamestrike",
      "!cast disintegrate",
      }) );
  }
