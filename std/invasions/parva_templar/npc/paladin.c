// Templar invasion of Parva
// Duuk
// Edited: Laoise, 2005

#include <lib.h>
#include "../tip.h"
inherit LIB_INVADER;

int CheckParva();

static void create() {
  ::create();
  SetKeyName("Kylin Paladin");
  SetShort("a Paladin of Kylin");
  SetId( ({ "paladin" }) );
  SetAdjectives( ({ "kylin" }) );
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
  SetSkill("evokation", GetLevel()*3, 1);
  SetLevel(25);
  SetInventory( ([
    TIP_OBJ + "mace" : "wield mace",
    TIP_OBJ + "plate" : "wear armour",
    TIP_OBJ + "sword" : "wield sword",
  ]) );
  SetAction(5, ({
    "!cast wall of force",
    "!yell Secure the town!",
    "!yell Heathen, we have come for you!",
  }) );
  SetCombatAction(5, ({
    "!cast wrath",
    "!cast wall of force",
    "!cast Surrender, Parva!",
  }) );
  SetSpellBook( ([
    "wall of force" : 100,
    "wrath" : 100,
  ]) );
  SetFriends( ({ "templar_inv" }) );
  SetEncounter( (: CheckParva :) );
  SetWanderSpeed(5);
  SetWanderPath( ({
    "enter hall", "go out", "go east", "enter shack",
    "go out", "go south", "enter building", "go out",
    "go north", "go east", "enter store", "go out",
    "enter inn", "go out", "go east", "go north",
    "go south", "go south",
  }) );
}

int CheckParva() { 
  object who = this_player();

  if (!userp(who) && !(who->GetProperty("invader"))) {
    eventForce("yell For Duuk, I will send you to the void!");
    SetAttack(who);
  return 1;
  }
return 0;
}