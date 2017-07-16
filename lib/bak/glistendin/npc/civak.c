#include <lib.h>
#include "../glim.h"

inherit LIB_LEADER;

static void create(){
  leader::create(); 
  SetKeyName("civak");
  SetRace("dwarf");
  SetRestrictRace(1);
  SetClass("fighter");
  SetUniqueSkills( ([
    "slash combat"  : 2,
    "slash combat" : 2,
    "hack combat"   : 1,
    "hack combat"  : 1,
    ]) );
  SetLevel(85);
  SetGender("male");
  SetShort("Civak Axethrower, Thane Commander of the Dwarven Host");
  SetId( ({"civak",  "axethrower", "dwarf", "thane", "commander" }) );
  SetLong("Though lightly armoured, Civak is obviously a fighter of "
          "legendary ability. His beard has turned completely grey, and "
          "his face is wrinkled with great age, leaving his kindly blue "
          "eyes as the only remnent of his past youth. His position as Thane "
          "Commander makes him the person to petition for membership as a "
          "fighter.");
  SetTown("Glistendin");
  SetReligion("Kylin",);
  SetSkill("melee combat", 255, 1);
  AddStatBonus("strength", function() { return 30; } );
  SetMorality(200);
  SetPlayerTitles( ([
    "newbie" : "- a Soldier of the Dwarven Host",
    "mortal" : "- a Warrior of the Dwarven Host",
    "hm"     : "the Great Dwarven Warrior",
    "legend" : "the Dwarven Hero",
    "avatar" : "the Supreme Dwarven Warrior",
    ]) );
  SetFreeEquipment( ([
    G_OBJ + "axe" : 2,
    ]) );
  SetCombatAction(5,({
   "!say You ruffian, begone!",
    }) );
  SetInventory( ([
    G_OBJ + "guard_axe" : "wield first axe",
    G_OBJ + "chainmail"  :  "wear chainmail",
    ]) );
  SetAction(2,({
      "!say Your people need you! Arise and join us!",
      "!say In the end, we shall stand in triumph!",
    }) );
}
