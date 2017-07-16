#include <lib.h>
#include <std.h>
#include <daemons.h>
#include "../keryth.h"

inherit LIB_LEADER;

static void create() {
  leader::create();
  SetKeyName("azogar");
  SetShort("Azogar, High Priest of Soirin");
  SetId( ({ "azogar", "priest", "soirin priest", "soirin" }) );
  SetLong("Like a building, Azogar stands here almost completely immovable.  "
          "His rugged countenance conveys power and duty to his faith, while "
          "hinting at a keen intelligence.  Though most Goden prefer to wear "
          "a minimal amount of clothing to be comfortable in the coldness of "
          "Keryth, Azogar chooses to never allow himself that comfort, as he "
          "feels that it can only serve to weaken him.");
  SetRace("goden");
  SetClass("cleric");
  SetLevel(85);
  SetGender("male");
  SetMorality(-250);
  SetTown("Keryth");
  SetUniqueSkills( ([
    "evokation" : 1,
    "enchantment" : 1,
    "knife attack" : 1,
    "stealth" : 2,
    "knife defense" : 2,
    "multi-weapon" : 2,
    "pierce attack" : 2,
    "pierce defense" : 3,
    "fishing" : 3,
    "bargaining" : 3,
    "healing" : 4
  ]) );
  SetSpellBook( ([
    "cloak of darkness" : 100,
    "dark arrow" : 100
  ]) );
  SetCombatAction(20, ({
    "!cast cloak of darkness",
    "!cast dark arrow"
  }) );
  SetTaughtSpheres( ({
    "clerical",
    "clerical enchantment",
    "clerical evokation",
    "clerical healing",
    "religion soirin"
  }) );
  SetInventory( ([
    K_OBJ + "/cleric_staff" : "wield staff"
  ]) );
  SetReligion("Soirin", "Soirin");
  SetPlayerTitles( ([
    "newbie" : "the Northern Shadowy Cleric",
    "mortal" : "the Northern Dark Cleric",
    "hm"     : "the Northern Cleric of Darkness",
    "legend" : "the Northern Priest of Darkness",
    "avatar" : "the High Ruler of Darkness"
  ]) );
  SetFreeEquip( ([
       STD_KNIFE + "freeknife" : 1,
    ]) );
}
