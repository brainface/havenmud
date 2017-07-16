// A Skaven Bandit to invade Parva
// Original Coder: Unknown
// Edited: Laoise, 2005

#include <lib.h>
#include "../bip.h"
inherit LIB_INVADER;

int CheckParva();

static void create() {
  ::create();
  SetKeyName("skaven bandit");
  SetEnemyTown("Parva");    
  SetShort("an evil skaven bandit");
  SetId( ({ "bandit", "bandit_inv" }) );
  SetAdjectives( ({ "skaven", "evil", "looking" }) );
  SetLong(
    "This evil skaven is a member of a roving band of "
    "villians that are the scourge of the area."
  );
  SetRace("skaven");
  SetGender(random(2) ? "male" : "female");
  SetClass("fighter");
  SetLevel(5);
  SetMorality(-300);
  SetInventory( ([
    BIP_OBJ + "sword" : "wield sword",
    BIP_OBJ + "leather" : "wear leather",
  ]) );
  SetAction(5, ({
    "!yell Sack the town!",
    "!yell We have come for your money!",
  }) );
  SetCombatAction(5, ({
    "!slice",
  }) );
  SetEncounter( (: CheckParva :) );
  SetFriends( ({ "bandit_inv" }) );
  SetWanderSpeed(5);
  SetWanderPath( ({
    "enter hall", "go out", "go east", "enter shack",
    "go out", "go south",
    "go north", "go east", "enter store", "go out",
    "enter inn", "go out", "go east", "go north",
    "go south", "go south",
  }) );
}

int CheckParva() { 
  object who = this_player();

  if (!userp(who) && !(who->GetProperty("invader"))) {
    eventForce("yell Over here, a Parvite to be killed!");
    SetAttack(who);
  return 1;
  }
return 0;
}