// Templar invasion of Jidoor
// Duuk

#include <lib.h>
#include "../tij.h"
inherit LIB_INVADER;

int CheckSprite();

static void create() {
  ::create();
  SetKeyName("Kylin Paladin");
  SetId( ({ "paladin", "templar_inv" }) );
  SetAdjectives( ({ "kylin" }) );
  SetShort("a Paladin of Kylin");
  SetLong(
    "This virtuous warrior-priest is a member "
    "of the Kylin Templar force for invasions. "
    "The devout look of peace on the face of the warrior "
    "is of sublime happiness in the cause of Kylin."
  );
  SetRace("elf");
  SetGender(random(2) ? "male" : "female");
  SetClass("cleric");
  SetClass("cavalier");
  SetSkill("enchantment", 1, 1);
  SetSkill("evokation", 1, 1);
  SetLevel(45);
  SetInventory( ([
    TIJ_OBJ + "mace" : "wield mace",
    TIJ_OBJ + "plate" : "wear armour",
    TIJ_OBJ + "sword" : "wield sword",
  ]) );
  SetAction(5, ({
    "!cast wall of force",
    "!yell Secure the town!",
    "!yell JidoorMages, we have come for you!",
    "!yell Search the Library!",
  }) );
  SetCombatAction(5, ({
    "!cast wrath",
    "!cast wall of force",
    "!cast Surrender, Jidoor!",
  }) );
  SetSpellBook( ([
    "wall of force" : 100,
    "wrath" : 100,
  ]) );
  SetEncounter( (: CheckSprite :) );
  SetWanderSpeed(5);
  SetWanderPath( ({
    "go north",
    "go north", "go north", "enter library", "go out",
    "go north", "go north", "enter hall", "go out",
    "go south", "go south", "go south", "go south" 
  }) );
  SetWanderRecurse(1);
  call_out( (: eventForce :), 1, "cast wall of force");
  call_out( (: eventForce :), 1, "cast wall of force");
  call_out( (: eventForce :), 1, "cast wall of force");
 }

int CheckSprite() { 
  object who = this_player();

  if (!userp(who) && !(who->GetProperty("invader"))) {
    eventForce("yell For Duuktsaryth, I will send you to the void!");
    SetAttack(who);
  return 1;
  }
return 0;
}