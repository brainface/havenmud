
#include <lib.h>
#include "../haven.h"
inherit LIB_SENTIENT;

static void create() {
  ::create();
  SetKeyName("arcturus");
  SetRace("elf");
  SetClass("fighter");
  SetSkill("pierce attack", 200, 1);
  SetSkill("blunt defense", 200, 1);
  SetSkill("hack defense", 200, 1);
  SetSkill("pierce defense", 200, 1);
  SetSkill("slash defense", 200, 1);
  SetSkill("projectile defense", 200, 1);
  SetClass("cleric");
  SetSkill("evokation", 200, 1);
  SetSkill("healing", 200, 1);
  SetLevel(250);
  SetShort("arcturus the Supreme Warrior of Haven Town (elf)");
  SetId( ({ "arcturus", "warrior", "elf", "haven_wander" }) );
  SetWanderSpeed(10);
  SetTown("Haven");
  SetReligion("Kylin");
  SetAdjectives( ({ "supreme", "elf" }) );
  SetLong("Arcturus has made a life of combat.  His abilities "
          "to deflect attacks are legendary.");
  SetInventory( ([
  H_OBJ "guard_armour" : "wear armour",
    H_OBJ "avatarslash" : "wield longsword",
    H_OBJ "avatarpierce" : "wield rapier",
    ]) );
  SetCurrency( ([
    "imperials" : random(15000),
    ]) );
  SetGender("male");
  SetMorality(2000);
  AddFood(25000);
  AddDrink(25000);
  SetSpellBook( ([
    "barrier of faith" : 100,
    "curing touch" : 100,
    "wall of force" : 100,
  ]) );
  SetAction(5,
    ({ "!cast barrier of faith",
       "!cast curing touch",
    "!cast wall of force",
    "!speak I defend this city from harm.",
  }) );
  SetCombatAction(10, ({
    "!cast barrier of faith",
    "!cast curing touch",
    }) );
  if (environment()) call_out( (: eventForce, "cast barrier of faith" :), 0 );
}
