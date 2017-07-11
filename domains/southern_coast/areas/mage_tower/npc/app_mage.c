#include <lib.h>
#include <std.h>
#include "../mage_tower.h"
inherit LIB_NPC;

static void create() {
  ::create();
  SetKeyName("dark-elven apprentice");
  SetFriends( ({ "elf mage", "dark-elven apprentice" }) );
  SetRace("elf");
  SetUndead(1);
  SetMorality(-750);
  SetReligion("Soirin");
  SetGender("male");
  SetClass("evoker");
  SetSkill("melee combat",1,2);
  SetSkill("fire magic",1,2);
  SetSkill("shock magic",1,2);
  SetLevel(random(15) + 30);
  SetShort("a cursed elven apprentice mage");
  SetId( ({ "mage", "elf", "apprentice" }) );
  SetAdjectives( ({ "cursed", "elven", "elf", "apprentice" }) );
  SetLong("This cursed elf seems to know his magic.  The power "
          "radiating off of him suggests that he, though an "
          "apprentice of this tower, can more than handle himself.");
  SetLanguage("Dasinri", 100);
  SetSpellBook( ([
    "energy field"    : 100,
    "bolt"            : 100,
    "sphere"          : 100,
    "fireball"        : 100,
    "chain lightning" : 100,
    ]) );
  SetAction(15, ({
    "!cackle mani",
    "!cast sphere",
    "!cast energy field",
    "!yell The Master comes!",
    "!emote rolls his eyes back in his head moaning about the Master.",
    "!speak in dasinri The Master remembers us.  We banished him to the Lower Planes and he is angry!",
    }) );
  SetCombatAction(50, ({
    "!cast bolt",
    "!cast sphere",
    "!cast energy field",
    "!cast fireball",
    "!cast chain lightning",
    }) );
  SetInventory( ([
    STD_CLOTHING "body/black_robe" : "wear robe",
    ]) );
  SetCurrency("imperials", random(10000) );
  //call_out( (: eventForce, "cast enhanced buffer" :), 0 );
  //call_out( (: eventForce, "cast enhanced aura" :), 0 );
  SetFirstCommands( ({
  	"cast energy field",
  	"cast energy field",
  	"cast sphere",
  	"cast sphere",
  	"cast sphere",
  	}) );
  	
}

